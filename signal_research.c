/**
 * @file signal_research.c
 *
 * Author: Hunter Carroll
 * Course: CPE 2600
 * Section: 012
 * Assignment: Lab 10
 *
 * Brief Summary
 * Demonstrates the use of the kill() function
*/
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
    pid_t pid;
    int signal_num;

    pid = getpid();
    signal_num = SIGKILL;

    printf("Current process PID: %d\n", pid);
    printf("Sending signal to process %d\n", pid);
    
    kill(pid, signal_num);

    return 0;
}