#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <string.h>

int main(int argc, char* argv[]) {
  if (argc < 2) {
    printf("Please supply a pid. Try again");
    return 1;
  }

  FILE *fp;
  char buffer[200];

  char filename[] = "/proc/";
  strcat(filename, argv[1]);
  strcat(filename, "/comm");

  fp = fopen(filename, "r");

  long int buffsize = 200;
  long int offset = 0;
  while (!feof(fp)) {
    size_t n = fread(buffer, 1, buffsize, fp);
    fwrite(buffer, 1, n, stdout);
  }
  fclose(fp);

  return 0;
}
