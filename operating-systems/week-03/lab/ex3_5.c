#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    // Create new process child
    // *** COMPLETE ME ***
    if (child > 0)
    {
        int status;
        printf("Parent running....\n");
        printf("Parent waiting....\n");
        // Wait for the child
        // *** COMPLETE ME ***
        printf("Child exited....\n");
        printf("Parent exiting....\n");
        exit(EXIT_SUCCESS);
    }
    else if (!child)
    {
        printf("Child running....\n");
        printf("Child exiting....\n");
        exit(EXIT_SUCCESS);
    }
    else if (child == -1)
    {
        perror("fork");
    }
    return 0;
}