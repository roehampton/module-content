#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    // Create a process
    // *** COMPLETE ME ***
    // Continue based on which process is running.
    if (pid > 0)
    {
        printf("I'm the parent of pid=%d\n", pid);
    }
    else if (!pid)
    {
        printf("I'm the child\n");
    }
    else if (pid == -1)
    {
        perror("fork");
    }
    return 0;
}