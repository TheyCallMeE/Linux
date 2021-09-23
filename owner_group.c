#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>

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

  // The user id
  uid_t uid = filestat.st_uid;

  struct passwd *pwd = getpwuid(uid);
  if (pwd == NULL) {
    perror("Error finding user using given uid.");
    return 1;
  }

  printf("Owner: %s\n", pwd->pw_name);

  // The group id
  gid_t gid = filestat.st_gid;

  struct group *grp = getgrgid(gid);
  if (grp == NULL) {
    perror("Error finding group using given gid.");
    return 1;
  } 

  printf("Group: %s\n", grp->gr_name);

  return 0;
}
