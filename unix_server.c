#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <sys/un.h>
#include <unistd.h>

// For a simple server harnessing sockets in the UNIX domain

int main(int argc, char *argv[]) {
  int socket_desc, client_sock, conn, read_size;
  struct sockaddr_un server, client;
  char client_message[200];

  // Create the socket
  socket_desc = socket(AF_UNIX, SOCK_STREAM, 0);
  if (socket_desc == -1) {
    printf("Could not create socket");
  }
  printf("Socket created.\n");

  // Prepare sockaddr_in structure
  memset(&server, 0, sizeof(struct sockaddr_un));
  server.sun_family = AF_UNIX;
  strcpy(server.sun_path, "#MyServer");
  server.sun_path[0] = 0;

  // Bind
  if (bind(socket_desc, (struct sockaddr *)&server, sizeof(server)) < 0) {
    // Bind failed
    perror("Bind failed. Error");
    return 1;
  }
  printf("Bind done.\n");

  // Listening, second argument is max length of queue of pending connections
  listen(socket_desc, 2);

  // Accept an incoming connection
  printf("Waiting for incoming connection...\n");
  conn = sizeof(struct sockaddr_un);
  client_sock =
      accept(socket_desc, (struct sockaddr *)&client, (socklen_t *)&conn);
  if (client_sock < 0) {
    perror("accept failed. Error");
    return 1;
  }
  printf("Connection accepted.\n");

  // Receive a message from client
  while ((read_size = recv(client_sock, client_message, 200, 0)) > 0) {
    // The HTTP request has the file after the first space, skip the first token
    char *filename = strtok(client_message, " ");
    filename = strtok(NULL, " ");
    FILE *fptr;

    // For gathering the amount of bytes in the file
    struct stat filestat;
    int status;
    if ((status = stat(filename, &filestat)) != 0) {
      snprintf(client_message, sizeof(client_message),
               "HTTP/1.0 404 Not Found\r\n\r\nFile cannot be opened.\r\n");
      write(client_sock, client_message, strlen(client_message) + 1);
    }

    // Open the file and read the content
    if ((fptr = fopen(filename, "r")) == NULL) {
      snprintf(client_message, sizeof(client_message),
               "HTTP/1.0 404 Not Found\r\n\r\nFile cannot be opened.\r\n");
      write(client_sock, client_message, strlen(client_message) + 1);
    } else {
      char buffer[200];
      // Format the HTTP response
      snprintf(client_message, sizeof(client_message),
               "HTTP/1.0 200 OK\r\nContent-Length: %ld\r\n\r\n",
               filestat.st_size);
      write(client_sock, client_message, strlen(client_message) + 1);
      while (!feof(fptr)) {
        size_t n = fread(buffer, 1, sizeof(buffer), fptr);
        // Send the contents back
        snprintf(client_message, n + 1, "%s", buffer);
        size_t a = write(client_sock, client_message, n);
        size_t diff = n - a;
        while (diff > 0) {
          a = write(client_sock, client_message + a, diff);
          diff -= a;
        }
      }
      fclose(fptr);
    }
  }

  if (read_size == 0) {
    printf("Client disconnected.\n");
    fflush(stdout);
  } else if (read_size == -1) {
    perror("recv failed. Error");
    return 1;
  }

  if (close(client_sock) == -1) {
    perror("close");
    return 1;
  }

  return 0;
}
