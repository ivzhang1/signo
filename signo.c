#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

static void sighandler(int signo){
  if(signo == SIGINT){
    int file_id = open("error.txt", O_WRONLY | O_CREAT | O_APPEND, 0644);

    char str[] =  "Exit due to SIGINT\n";
    int write_size = write(file_id, str, sizeof(str));
    close(file_id);
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

  return 0;
  
}
