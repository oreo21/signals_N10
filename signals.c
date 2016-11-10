#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void sighandler(int signum){
  if (signum == 2){
    printf("received signal 2 (SIGINT), exiting...\n");
    exit(0);
  }
  if (signum == 10)
    printf("received signal 10 (SIGUSR1), reporting Parent PID: %d\n", getppid());
}

int main(){
  signal(SIGINT, sighandler);
  signal(SIGUSR1, sighandler);
  while (1){
    printf("PID: %d\n", getpid());
    sleep(1);
  }
  return 0;
}
