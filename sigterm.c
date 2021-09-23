#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

volatile sig_atomic_t done = 0;
void* pc = NULL;

// Overwriting the action of SIGTERM using a handler
void term(int signum) { done = 1; }

// Overwriting the action of SIGTERM using an action
void term_a(int signum, siginfo_t* si, void* v) {
  done = 1;
  pc = si->si_addr;
}

int main(void) {
  struct sigaction action;
  memset(&action, 0, sizeof(struct sigaction));
  // action.sa_handler = term;
  action.sa_flags = SA_SIGINFO;
  action.sa_sigaction = term_a;
  sigaction(SIGTERM, &action, NULL);

  // Wait for the SIGTERM
  while (!done) {
  }

  // Get current time upon SIGTERM
  time_t rawtime;
  struct tm* timeinfo;
  time(&rawtime);
  timeinfo = localtime(&rawtime);
  printf("\nTime and date when SIGTERM received: %s\n", asctime(timeinfo));
  printf("Current PC: %p\n", pc);
  return 0;
}
