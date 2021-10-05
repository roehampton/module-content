#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    pid_t pid = fork();
    if (pid > 0)
    {
        // Print numbers 0 to 10
        for (int i = 0; i <= 10; ++i)
        {
            printf("Parent %d\n", i);
        }
    }
    else if (!pid)
    {
        // Print numbers 0 to 10
        for (int i = 0; i <= 10; ++i)
        {
            printf("=====>Child %d\n", i);
        }
    }
    else if (pid == -1)
    {
        perror("fork");
    }
    return 0;
}