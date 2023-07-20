#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

void handle_signal(int sig) {
    printf("Received signal %d\n", sig);
}

int main() {
    pid_t pid;
    
    // Signal to handle "Ctrl + c"
    signal(SIGINT, handle_signal);
    
    // Fork a child process
    pid = fork();
    
    if (pid == -1) {
        perror("fork");
        exit(1);
    } else if (pid == 0) {
        // Child process
        while (1) {
            printf("Child process running...\n");
            sleep(1);
        }
    } else {
        // Parent process
        sleep(3);
        printf("Pausing child process...\n");
        kill(pid, SIGSTOP);
        sleep(3);
        printf("Resuming child process...\n");
        kill(pid, SIGCONT);
        sleep(3);
        printf("Terminating child process...\n");
        kill(pid, SIGTERM);
    }
    
    return 0;
}

