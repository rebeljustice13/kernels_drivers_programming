#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_signal(int sig) {

	if(sig == SIGALRM){
    printf("Received SIGALRM  signal \n");
	}
	else if(sig == SIGINT)
	{
		printf("Received SIGINT signal \n");
	}
}

int main() {
    // Install signal handler for SIGALRM
    signal(SIGALRM, handle_signal);

    signal(SIGINT, handle_signal);

    // Schedule first alarm after 1 second
    printf("Setting alarm 1 for 1 second...\n");
    alarm(1);
    sleep(2);

    // Schedule second alarm after 2 seconds
    printf("Setting alarm 2 for 2 seconds...\n");
    alarm(2);
    sleep(3);

    // Schedule third alarm after 3 seconds
    printf("Setting alarm 3 for 3 seconds...\n");
    alarm(3);
    sleep(4);

    // Schedule fourth alarm after 4 seconds
    printf("Setting alarm 4 for 4 seconds...\n");
    alarm(4);
    sleep(5);

    /*
    printf("Waiting for signal   \n");
    pause();
    */

    printf("Done.\n");
    return 0;
}

