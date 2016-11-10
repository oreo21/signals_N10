#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>

void sighandler(int signum){
  if (signum == 2){
    char text[] = "received signal 2 (SIGINT), signals.c terminated\n";
    printf("received signal 2 (SIGINT), writing out to info.txt...\n");
    int filedesc = open("info.txt", O_CREAT|O_RDWR|O_APPEND, 0666);
    write(filedesc, text, sizeof(text));
    close(filedesc);
    exit(0);
  }
  if (signum == 10)
    printf("received signal 10 (SIGUSR1), reporting parent PID: %d\n", getppid());
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
