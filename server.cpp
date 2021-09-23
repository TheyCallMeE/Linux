#include <fcntl.h>
#include <poll.h>
#include <sys/mman.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/un.h>
#include <unistd.h>

#include <cerrno>
#include <iostream>
#include <string>

#include "sharedmem.pb.h"

int send_fd(int unix_sock, int fd) {
  char c[1]{'5'};
  struct iovec iov = {.iov_base = &c, .iov_len = 2};

  union {
    char buf[CMSG_SPACE(sizeof(fd))];
    struct cmsghdr allign;
  } u;

  struct msghdr msg = {.msg_iov = &iov,
                       .msg_iovlen = 1,
                       .msg_control = u.buf,
                       .msg_controllen = sizeof(u.buf)};

  struct cmsghdr *cmsg = CMSG_FIRSTHDR(&msg);
  *cmsg = (struct cmsghdr){.cmsg_len = CMSG_LEN(sizeof(fd)),
                           .cmsg_level = SOL_SOCKET,
                           .cmsg_type = SCM_RIGHTS};

  memcpy(CMSG_DATA(cmsg), &fd, sizeof(fd));

  return sendmsg(unix_sock, &msg, 0);
}

int main(int argc, char *argv[]) {
  int socket_desc, client_sock, conn, read_size;
  struct sockaddr_un server, client;
  char client_message[200];

  // Create the socket
  socket_desc = socket(AF_UNIX, SOCK_STREAM, 0);
  if (socket_desc == -1) {
    std::cout << "Could not create socket." << std::endl;
  }
  std::cout << "Socket created." << std::endl;

  // Prepare sockaddr_in structure
  memset(&server, 0, sizeof(struct sockaddr_un));
  server.sun_family = AF_UNIX;
  // Abstract namespace
  strcpy(server.sun_path, "#MyServer");
  server.sun_path[0] = 0;

  // Bind
  if (bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
    // Bind failed
    std::cerr << "Bind failed." << std::endl;
    return -1;
  }
  std::cout << "Bind done." << std::endl;

  // Listening
  listen(socket_desc, 2);

  // Allocate 1 GB of shared memory
  const char *shmpath = "/dev/shm/sharedmem";
  int bytes = 1024 * 1024 * 1024;
  int fd = open(shmpath, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR);
  if (fd == -1) {
    std::cerr << "open: ";
    std::cout << std::strerror(errno) << std::endl;
  }
  if (ftruncate(fd, bytes) == -1) {
    std::cerr << "ftruncate: ";
    std::cout << std::strerror(errno) << std::endl;
  }

  // Unlink the shared memory object
  unlink(shmpath);

  // Create an array of pollfds for incoming connections
  struct pollfd polls[10];
  int numfds{0};
  memset(polls, '\0', sizeof(polls));
  polls[0].fd = socket_desc;
  polls[0].events = POLLIN;
  numfds++;

  // Server stays open, accepting connections and closing them upon sending a
  // response
  while (true) {
    // Accept an incoming connection and allocate the memory in /dev/shm
    std::cout << "Waiting for incoming connection..." << std::endl;

    poll(polls, numfds, -1);
    for (int i = 0; i < numfds; i++) {
      if (polls[i].fd == -1) continue;
      if (polls[i].revents & POLLIN) {
        if (polls[i].fd == socket_desc) {
          conn = sizeof(struct sockaddr_un);
          client_sock = accept(socket_desc, (struct sockaddr *)&client,
                               (socklen_t *)&conn);
          if (client_sock < 0) {
            std::cerr << "Accept failed." << std::endl;
            return -1;
          }
          std::cout << "Connection accepted." << std::endl;
          // Now add the poll response from the client to the pollfds array
          bool new_connection = true;
          for (int j = 0; j < numfds; j++) {
            if (polls[j].fd == -1) {
              polls[j].fd = client_sock;
              polls[j].events = POLLIN;
              new_connection = false;
            }
          }
          if (new_connection) {
            polls[numfds].fd = client_sock;
            polls[numfds].events = POLLIN;
            numfds++;
          }

        } else {
          // Read client messages
          if (read_size = recv(client_sock, client_message, 200, 0) > 0) {
            // Read the protobuf message
            shmmsg::Client client_msg;
            int bytes_to_read = client_message[0];
            if (!client_msg.ParseFromArray(client_message + 1, bytes_to_read)) {
              std::cerr << "Failed to parse client message." << std::endl;
              abort();
            }

            if (client_msg.client() == shmmsg::Client::WRITER)
              std::cout << "Writer requests fd." << std::endl;
            else if (client_msg.client() == shmmsg::Client::READER)
              std::cout << "Reader requests fd." << std::endl;

            // Send a protobuf message to the client
            shmmsg::Server serv;
            serv.set_response(shmmsg::Server::SUCCESS);
            if (!serv.SerializeToArray(client_message + 1,
                                       sizeof(client_message) - 1)) {
              std::cerr << "Failed to write client message." << std::endl;
              return -1;
            }
            // Determine size of message being sent and set client_message[0] to
            // it
            int bytes_used = client_msg.ByteSizeLong();
            client_message[0] = bytes_used;

            int remaining = bytes_used + 1;
            int offset = 0;
            while (remaining > 0) {
              ssize_t a = write(client_sock, client_message + offset, remaining);
              if (a < 0) {
                perror("write");
              }
              remaining -= a;
              offset += a;
            }

            // Send the fd
            int sent = send_fd(client_sock, fd);
            if (sent == -1) {
              perror("send_fd");
            }
            std::cout << "fd sent to client." << std::endl << std::endl;

          } else if (read_size == 0) {
            std::cout << "Client disconnected." << std::endl;
            // Close the connection
            if (close(client_sock) == -1) {
              std::cerr << "close" << std::endl;
              return -1;
            }
            // Remove the client
            polls[i].fd = -1;
            polls[i].events = 0;
          } else {
            std::cerr << "read error: " << strerror(errno) << std::endl;
          }
        }
      }
    }
  }
  return 0;
}
