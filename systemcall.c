#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
  int status;
  char str[50] = "/bin/bash -c ";
  strcat(str, argv[1]);
  for (int i = 2; i < argc; i++) {
    strcat(str, " ");
    strcat(str, argv[i]);
  }
  printf("%s\n\n", str);
  system(str);
  return 0;
}
