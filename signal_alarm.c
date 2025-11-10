/**
 * @file signal_alarm.c
 * Modified by: Hunter Carroll
 * 
 * Brief summary of program:
 * Schedule an alarm for 5 seconds and print a message when
 * alarm is received.
 */
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

/**
 * @brief Signal handler for SIGALRM
*/
void handle_signal()
{
    // print message whne signal is received
    printf("Alarm signal received\n");
    exit(0);
}

int main(int argc, char* argv[])
{
    // set alarm time to 5 seconds
    unsigned int alarm_time = 5;

    // set alarm
    alarm(alarm_time);

    // register signal handler
    signal(SIGALRM, handle_signal);

    // infinite loop to sleep
    while(1) {
        printf("Sleeping\n");
        sleep(1);
    }

    // return to exit
    return 0;
}
