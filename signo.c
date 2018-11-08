#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void sighandler(int signo){
  if(signo == SIGINT){
    printf("\nExiting the Program\n");
    exit(0);
  }else if(signo == SIGUSR1){
    printf("Parent PID: %d\n", getppid());
  }
}

int main(){
  signal(SIGINT, sighandler);
  signal(SIGUSR1, sighandler);
  while(1){
    printf("PID: %d\n", getpid());
    sleep(1);
  }
}
