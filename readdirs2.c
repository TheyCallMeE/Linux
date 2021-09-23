#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/syscall.h>

// From linux source for getdents
#define BUF_SIZE 1024

// Have to define linux_dirent due to using syscall
struct linux_dirent {
  unsigned long d_ino;
  off_t d_off;
  unsigned short d_reclen;
  char d_name[];
};

int main(int argc, char* argv[]) {
  char buf[BUF_SIZE];
  struct linux_dirent *d;

  if (argc < 2) {
    printf("Please supply a directory to read. Try again.");
    return 1;
  }

  int fd = open(argv[1], O_RDONLY | O_DIRECTORY);
  if (fd == -1) {
    perror("Error opening directory.");
    return 1;
  }

  for (;;) {
    long nread = syscall(SYS_getdents, fd, buf, BUF_SIZE);
    if (nread == -1) {
      perror("Error reading contents.");
      return 1;
    }
    if (nread == 0) break;

    for (long bpos = 0; bpos < nread; ) {
      d = (struct linux_dirent *) (buf + bpos);
      printf("%s\n", d->d_name);
      bpos += d->d_reclen;
    }
  }

  return 0;
}
