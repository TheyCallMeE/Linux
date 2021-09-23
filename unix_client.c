#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

// A simple client to connect to the server in the UNIX domain

int main(int argc, char* argv[]) {
  if (argc < 2) {
    printf("Not enough arguments! Please specify a file name.\n");
    return 1;
  }
  int sock;
  struct sockaddr_un server;
  char message[200], reply[200];

  // Create socket
  sock = socket(AF_UNIX, SOCK_STREAM, 0);
  if (sock == -1) {
    printf("Could not create socket\n.");
  }
  printf("Socket created.\n");

  // Populate server address
  memset(&server, 0, sizeof(struct sockaddr_un));
  server.sun_family = AF_UNIX;
  strcpy(server.sun_path, "#MyServer");
  server.sun_path[0] = 0;

  // Connect to server
  if (connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0) {
    perror("connect failed. Error");
    return 1;
  }
  printf("Connected\n");

  // Keep communication channel open
  snprintf(message, sizeof(message), "GET %s HTTP/1.0\r\n", argv[1]);

  bool header_processed = false;
  int bytes_to_read = 0;

  // Send the data
  if (send(sock, message, strlen(message), 0) < 0) {
    printf("send failed. Error.");
    return 1;
  }

  // Receive the reply
  for (;;) {
    int offset = 0;
    ssize_t n = recv(sock, reply, sizeof(reply), 0);
    if (n < 0) {
      printf("recv failed. Error");
      break;
    } else if (n == 0)
      break;
    // Gather the number of bytes to be read from the server
    if (!header_processed) {
      // Skip the HTTP response
      char* bytes = strtok(reply, "\r\n");
      offset += (strlen(bytes) + strlen("\r\n"));
      bytes = strtok(NULL, "\r\n");
      offset += (strlen(bytes) + strlen("\r\n\r\n"));
      char* num = strtok(bytes, ": ");
      num = strtok(NULL, ": ");
      bytes_to_read = atoi(num);
      header_processed = true;
    }
    fwrite(reply + offset, 1, n - offset, stdout);
    bytes_to_read -= n - offset;
    if (bytes_to_read <= 0) break;
  }

  close(sock);
  return 0;
}
