#include <signal.h>
#include <sys/types.h>

int main(void)
{
    pid_t pid;
    int signal_num;

    kill(pid, signal_num);

    return 0;
}