/**
 * File: send_signal.c
 * Modified by: Hunter Carroll
 * 
 * Brief summary of program:
 * Sends SIGUSR1 along with random integer to process with sigqueue.
 * Print number before sending SIGUSR1
 */
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



int main(int argc, char* argv[]) {
    // Check for command line arguments
    if(argc != 2) {
        printf("Usage incorrect\n");
        return 1;
    }

    // Convert command line argument to integer
    int num = atoi(argv[1]);

    // seed random number generator and generate
    srand(time(NULL));

    // generate random integer between 1 and 1000
    int random_num = rand() % 1000 + 1;

    // Print number before sending
    printf("Sending SIGUSR1 with sival_int: %d\n", random_num);
    fflush(stdout);

    // send SIGUSR1 with sival_int to process with pid num
    union sigval sig_value;
    sig_value.sival_int = random_num;

    // Send sigusr1 with sigqueue
    sigqueue(num, SIGUSR1, sig_value);

    return 0;
}