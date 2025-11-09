/**
 * File: recv_signal.c
 * Modified by: Hunter Carroll
 * 
 * Brief summary of program:
 * Uses sigaction to register a handler for the SIGUSR1 signal.
 * After registering, wait in infinite loop.
 * in signal_handler, retrieve sival_int and print then return.
 */
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void handle_signal(int signum, siginfo_t *info, void *context) {
    
    printf("sival_int: %d\n", info->si_value.sival_int);
    return;
}

int main(int argc, char* argv[]) {
    struct sigaction sa;
    memset(&sa, 0, sizeof(sa));
    sa.sa_flags = SA_SIGINFO;
    sa.sa_sigaction = handle_signal;
    sigemptyset(&sa.sa_mask);
    sigaction(SIGUSR1, &sa, NULL);
    
    // Print PID for user
    printf("PID: %d\n", getpid());
    fflush(stdout);

    // infinite loop
    while(1) {
        sleep(1);
    }

    return 0;
}