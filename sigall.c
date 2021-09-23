#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void sig_handler(int signum) {
  // strsignal converts an integer to the appropriate signal name
  printf("\n%s caught!\n", strsignal(signum));
}

int main() {
  struct sigaction action;
  memset(&action, 0, sizeof(struct sigaction));
  action.sa_handler = sig_handler;
  int signals[] = {1,  2,  3,  4,  5,  6,  7,  8,  10, 11,
                   12, 13, 14, 15, 17, 18, 20, 21, 22, 31};
  int size = sizeof(signals) / sizeof(signals[0]);
  for (int i = 0; i < size; i++) {
    sigaction(signals[i], &action, NULL);
  }
  while (1) {
    sleep(10);
  }
  return 0;
}
