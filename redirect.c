#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main() {
  int fd = open("redirection.txt", O_WRONLY);
  if (fd == -1) {
    perror("Error opening file.");
    return 1;
  }

  // Give the oldfd as stdout and the newfd as the file
  dup2(fd, 1);

  printf("hello world\n");

  return 0;
}
