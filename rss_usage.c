#include <sys/mman.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main() {
  int bytes = 1 * 1024 * 1024 * 1024;

  char *ptr = mmap("/dev/shm", bytes, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, 0, 0);

  if (ptr == MAP_FAILED) {
    printf("Mapping failed.\n");
    return 1;
  }
  
  for (int i = 0; i < bytes; i += 4096) {
    printf("Writing to address: %p\n", ptr + i);
    memset(ptr + i, 255, 4096);
    sleep(1);
  }

  return 0;
}
