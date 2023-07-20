#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include<unistd.h>

int main() {
    pid_t pid;
    int sig;
    
   

    printf("pid of this process is %d\n",getpid());
    printf("Please enter the pid\n");
    scanf("%d",&pid);
    printf("Please enter the signal\n");
    scanf("%d",&sig);
    
    
    if (kill(pid, sig) == -1) {
        perror("kill");
        exit(1);
    }
    
    printf("Signal %d sent to process %d\n", sig, pid);
    
    return 0;
}

