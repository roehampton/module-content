#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

void parent_exit()
{
    printf("Exiting parent\n");
}

void child_exit()
{
    printf("Exiting child\n");
}

int main(int argc, char **argv)
{
    pid_t pid = fork();
    if (pid > 0)
    {
        atexit(parent_exit);
        exit(EXIT_SUCCESS);
    }
    else if (!pid)
    {
        atexit(child_exit);
        exit(EXIT_SUCCESS);
    }
    else if (pid == -1)
    {
        perror("fork");
    }
    return 0;
}