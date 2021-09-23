#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
  if (argc < 2) {
    printf("Please enter a directory argument.\n");
    return 1;
  }

  // Open the directory, error if unable to do so
  DIR* dir;
  dir = opendir(argv[1]);
  if (dir == NULL)    {
    perror("Unable to read directory");
    return 1;
  }

  // Read into the dirent structure and gather the name of each entry
  struct dirent *entry;
  while ((entry = readdir(dir)) != NULL) {
    printf("%s\n", entry->d_name);
  }

  // Close the directory
  closedir(dir);

  return 0;
}
