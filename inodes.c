#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
  if (argc < 2) {
    printf("Please supply a file argument.\n");
    return 1;
  }

  struct stat filestat;
  int status;
  if ((status = stat(argv[1], &filestat)) != 0) {
    perror("Error opening file.");
    return 1;
  }

  printf("%s  inode number: %lu\n", argv[1], filestat.st_ino);
  return 0;
}
