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
    printf("Alarm signal received\n");
    exit(0);
}

int main(int argc, char* argv[])
{
    unsigned int alarm_time = 5;

    alarm(alarm_time);

    signal(SIGALRM, handle_signal);

    while(1) {
        printf("Sleeping\n");
        sleep(1);
    }

    return 0;
}
