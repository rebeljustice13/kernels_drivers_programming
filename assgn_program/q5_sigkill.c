#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>




int main() {
    pid_t pid;
    int status;
    
    printf("The process of currently running process is %d\n",getpid());
    printf("sleep for 5 sec\n");
    sleep(5);
    printf("Terminating the current running process \n");
    kill(getpid(),SIGKILL);

    
    return 0;
}

