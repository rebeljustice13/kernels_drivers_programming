#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void handler(int sig) {
    printf("Received signal %d\n", sig);
}

int main() {
    int choice;
    struct sigaction new, old;
    new.sa_handler = handler;
    sigemptyset(&new.sa_mask);
    new.sa_flags = 0;

    printf("Choose an option:\n");
    printf("1. Set new signal handler\n");
    printf("2. Get current signal handler\n");
    printf("3. Leave signal handling behavior unchanged\n");
    scanf("%d", &choice);
	 
    switch (choice) {
        case 1:
            if (sigaction(SIGINT, &new, &old) == -1) {
                perror("sigaction");
                exit(EXIT_FAILURE);
            }
            printf("New signal handler set.\n");
            break;
        case 2:
            if (sigaction(SIGINT, NULL, &old) == -1) {
                perror("sigaction");
                exit(EXIT_FAILURE);
            }
            if (old.sa_handler == SIG_DFL) {
                printf("Current signal handler is the default behavior.\n");
            } else if (old.sa_handler == SIG_IGN) {
                printf("Current signal handler is to ignore the signal.\n");
            } else {
                printf("Current signal handler is a user-defined function.\n");
            }
            break;
        case 3:
            printf("Signal handling behavior left unchanged.\n");
            break;
        default:
            printf("Invalid choice.\n");
            exit(EXIT_FAILURE);
    }
    
	
	
    printf("Waiting for signal...\n");
    pause();
    

    return 0;
}

