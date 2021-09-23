#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
  if (argc < 2) {
    printf("please supply an env variable to find\n");
    return 1;
  }

  char* res = getenv(argv[1]);
  if (res) printf("%s\n", res);
  else printf("No such environment variable.\n");
  return 0;
}
