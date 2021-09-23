#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
  if (argc < 3) {
    printf("Please supply an environment variable name and value.\n");
    return 1;
  }

  if (setenv(argv[1], argv[2], 0) != 0) perror("setenv");
  return 0;
}
