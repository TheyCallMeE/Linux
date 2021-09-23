#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
  int status;
  char* args[4];

  args[0] = "/bin/bash";
  args[1] = "-c";
  args[2] = "ls -l";
  args[3] = NULL;

  // child executes the path and args
  if (fork() == 0) execv(args[0], args);
  // parent waits for child
  else wait(&status);

  return 0;
}
