#include <sys/mman.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

#include <cerrno>
#include <iostream>
#include <string>

#include "sharedmem.pb.h"

int main(int argc, char *argv[]) {
  int sock;
  struct sockaddr_un server;
  char message[200], reply[200];

  // Create socket
  sock = socket(AF_UNIX, SOCK_STREAM, 0);
  if (sock == -1) {
    std::cout << "Could not create socket." << std::endl;
  }
  std::cout << "Socket created." << std::endl;

  // Populate server address
  memset(&server, 0, sizeof(struct sockaddr_un));
  server.sun_family = AF_UNIX;
  strcpy(server.sun_path, "#MyServer");
  server.sun_path[0] = 0;

  // Connect to the server
  if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
    std::cerr << "Connect failed." << std::endl;
    return -1;
  }
  std::cout << "Connected" << std::endl;

  // Construct the protobuf
  shmmsg::Client client;
  std::string mesg{"Hi"};
  client.set_msg(mesg);
  client.set_client(shmmsg::Client::WRITER);
  if (!client.SerializeToArray(message + 1, sizeof(message) - 1)) {
    std::cerr << "Failed to write client message." << std::endl;
    return -1;
  }
  // Determine size of message and put at message[0] for the server to read
  // first
  int bytes_used = client.ByteSizeLong();
  message[0] = bytes_used;

  // Send the message
  if (send(sock, message, bytes_used + 1, 0) < 0) {
    std::cerr << "send failed" << std::endl;
    return -1;
  }

  // Receive reply
  int fd[1];

  char len;
  ssize_t n = recv(sock, &len, 1, 0);
  if (n < 0) {
    std::cerr << "recv failed." << std::endl;
    return -1;
  }
  n = recv(sock, reply, len, 0);
  if (n < 0) {
    std::cerr << "recv failed." << std::endl;
    return -1;
  }

  // Process the protobuf message from the server first
  shmmsg::Server server_msg;
  if (!server_msg.ParseFromArray(reply, len)) {
    std::cerr << "Failed to parse server message." << std::endl;
    return -1;
  }

  if (server_msg.response() == shmmsg::Server::SUCCESS)
    std::cout << "SUCCESS!" << std::endl;
  else if (server_msg.response() == shmmsg::Server::ERROR) {
    std::cout << "An ERROR has occurred on the server side." << std::endl;
    return -1;
  }

  // If SUCCESS extract the file descriptor from the SCM_RIGHTS message
  char c[1]{'0'};
  struct iovec iov = {.iov_base = &c, .iov_len = 0};

  union {
    char buf[CMSG_SPACE(sizeof(fd))];
    struct cmsghdr allign;
  } u;

  struct msghdr msg = {.msg_iov = &iov,
                       .msg_iovlen = 1,
                       .msg_control = u.buf,
                       .msg_controllen = sizeof(u.buf)};

  struct cmsghdr *cmsg = CMSG_FIRSTHDR(&msg);
  *cmsg = (struct cmsghdr){.cmsg_len = 0, .cmsg_level = 0, .cmsg_type = 0};
  int x = recvmsg(sock, &msg, 0);
  if (x == -1) {
    std::cerr << "recvmsg failed " << strerror(errno) << std::endl;
  }
  if (cmsg->cmsg_len != CMSG_LEN(sizeof(fd))) {
    std::cerr << "cmsg_len incorrect." << std::endl;
  }
  if (cmsg->cmsg_level != SOL_SOCKET) {
    std::cerr << "cmsg_level incorrect." << std::endl;
  }
  if (cmsg->cmsg_type != SCM_RIGHTS) {
    std::cerr << "Invalid SCM message." << std::endl;
  }
  memcpy(fd, CMSG_DATA(cmsg), sizeof(fd));

  // Maps the object into the caller's address space
  int bytes = 1024 * 1024 * 1024;
  char *ptr = (char *)mmap(NULL, bytes, PROT_WRITE, MAP_SHARED, fd[0], 0);
  if (ptr == MAP_FAILED) {
    std::cout << "Mapping failed." << std::endl;
    return -1;
  }
  std::cout << "Received fd from server" << std::endl << std::endl;

  // Write to the shared memory
  std::cout << "Enter a string to be placed into shared memory: ";
  std::string entry;
  getline(std::cin, entry);

  // The actual data
  strcat(ptr, "\n");
  strcat(ptr, entry.c_str());
}
