#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void sighandler(int signum){
  if (signum == 2){
    printf("\nreceived signal %d, exiting...\n", signum);
    exit(0);
  }
  
  if (signum == 10){
    printf("\nParent PID: %d\n", getppid());
    kill(getpid(), SIGCONT);
  }
  
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
