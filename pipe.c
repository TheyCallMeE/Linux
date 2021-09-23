#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Write to the pipe
void writepipe(int pfd[]) {
  char *sent = "hello world";
  write(pfd[1], sent, strlen(sent));  
}

// Read from the pipe
void readpipe(int pfd[]) {
  char buf[1024];
  int n;
  if ((n = read(pfd[0], buf, sizeof(buf))) >= 0) {
    buf[n] = 0;
    printf("%s\n", buf);
  } else {
    perror("read");
  }
}

int main() {
  int fd[2];

  if (pipe(fd) < 0) exit(1);

  writepipe(fd);
  readpipe(fd);

  close(fd[0]);
  close(fd[1]);

  return 0;
}
