#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main(void)
{
    pid_t pid;
    int signal_num;

    pid = getpid();
    signal_num = SIGUSR1;

    printf("Current process PID: %d\n", pid);
    printf("Sending signal %d to process %d\n", signal_num, pid);
    
    kill(pid, signal_num);

    return 0;
}