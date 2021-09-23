#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/stat.h>

void Hexdump(void* addr, int length) {
  unsigned char* caddr = addr;
  char ascii[17];
  ascii[16] = '\0';
  for (int i = 0; i < length; i++) {
    // Prints addresses in increments of 16 bytes per line
    if (i % 16 == 0) {
      printf("%p\t", addr + i);
    }

    // Print the hex and use the value for ascii conversion
    printf("%02x ", caddr[i]);
    if (caddr[i] >= ' ' && caddr[i] <= '~') {
      ascii[i % 16] = caddr[i];
    } else {
      ascii[i % 16] = '.';
    }

    // If it is the 8th byte add an extra space
    if ((i + 1) % 8 == 0) {
      printf(" ");
    }

    // If we have printed 16 bytes of hex print the ascii
    if ((i + 1) % 16 == 0) {
      printf("|%s|\n", ascii);
    }

    // But we also need to print the ascii when we have reached the end of length
    //  and it is not a multiple of 16, fill the remaining hex with spaces
    if (i + 1 == length) {
      int spaces = 0;
      ascii[(i + 1) % 16] = '\0';
      if ((i + 1) % 16 < 8) {
        spaces = 1;
      }
      int printed = ((i + 1) % 16) * 3;
      spaces = spaces + (49 - printed);
      for (int j = 0; j < spaces; j++) {
        printf(" ");
      }
      printf("|%s|\n", ascii);
    }
  }
}

int main(int argc, char* argv[]) {
  if (argc < 2) {
    printf("Please enter a file to open.\n");
    return 1;
  }
  
  int fd = open(argv[1], O_RDONLY);
  if (fd == -1) {
    perror("open");
    return 1;
  }
  struct stat sb;
  if (fstat(fd, &sb) == -1) {
    perror("fstat");
    return 1;
  }
  int len = sb.st_size;

  void *addr = mmap(NULL, len, PROT_READ, MAP_PRIVATE, fd, 0);
  if (addr == MAP_FAILED) {
    perror("mmap");
    return 1;
  }

  Hexdump(addr, len);

  close(fd);

  return 0;
}
