#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <sys/types.h>

int cnt_1 = 0;
int cnt_2 = 0;


void handle_signal(int sig) {
	if(sig == 2){
		cnt_1 = cnt_1+1;
  
	}
	else if(sig == 3){
		cnt_2 += 1;
	}
	    printf("Received signal %d\n", sig);

}

int main() {
    // Install signal handlers for SIGINT and SIGQUIT

    signal(SIGINT, handle_signal);
    signal(SIGQUIT, handle_signal);

    printf("Disabling SIGINT and SIGQUIT signals for 10 seconds...\n");

    // Disable SIGINT and SIGQUIT signals
    sigset_t set;
    sigemptyset(&set);
    sigaddset(&set, SIGINT);
    sigaddset(&set, SIGQUIT);
    sigprocmask(SIG_BLOCK, &set, NULL);

    // Wait for 10 seconds
    sleep(10);

    printf("Enabling SIGINT and SIGQUIT signals...\n");

    // Enable SIGINT and SIGQUIT signals
    sigprocmask(SIG_UNBLOCK, &set, NULL);
	/*    
	printf("Number of times Ctrl+c comes %d\n",cnt_1);
	printf("Number of time Ctrl+' \' comes %d\n",cnt_2);
    	*/
	printf("Done.\n");
    return 0;
}
 
