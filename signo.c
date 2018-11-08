#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

static void sighandler(int signo){
  if(signo == SIGINT){
    char * file = "text_file.txt";
    int file_id = open(file, O_APPEND); //READ AND WRITE

 int write_size = write(file_id, "Exit due to SIGINT\n", 64);
    
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
