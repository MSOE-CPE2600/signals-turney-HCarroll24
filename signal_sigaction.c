/**
 * File: signal_sigaction.c
 * Modified by: Hunter Carroll
 * 
 * Brief summary of program:
 * Uses sigaction to register a handler for the SIGUSR1 signal.
 * Prints process ID of sender when SIGUSR1 is received.
 * Exits when SIGUSR1 is received 7 times.
 */
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void handle_signal(int signum) {
    // print message when signal is received
    printf("SIGUSR1 received\n");
    printf("Process ID: %d\n", getpid());
    fflush(stdout);
    sleep(1);
    return;
}

int main(int argc, char* argv[]) {
    // register signal handler
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_handler = handle_signal;
    sa.sa_flags = SA_RESTART;
    sigaction(SIGUSR1, &sa, NULL);

    // initialize count
    int count = 0;

    // infinite loop to sleep
    while(1) {
        sleep(1);
        printf("Sleeping\n");
        count++;
        // raise signal if count between 5 and 7
        if(count > 5 && count < 7) {
            raise(SIGUSR1);

            // print messag ehwen signal received
        } else if (count > 7) { // exit if count is greater than 7
            exit(0);
        }
    }

    // return to exit
    return 0;
}

