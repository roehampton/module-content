#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    pid_t childA = fork();
    pid_t childB = fork();
    if (childA > 0 && childB > 0)
    {
        int status;
        printf("Parent running....\n");
        printf("Waiting for child B....\n");
        // Wait for B to finish first
        waitpid(childB, &status, 0);
        printf("Child B exited....\n");
        printf("Waiting for child A....\n");
        // Wait for A to finish
        waitpid(childA, &status, 0);
        printf("Child A exited....\n");
        printf("Parent exiting....\n");
        exit(EXIT_SUCCESS);
    }
    else if (!childA)
    {
        printf("Child A running....\n");
        printf("Child A exiting....\n");
        exit(EXIT_SUCCESS);
    }
    else if (!childB)
    {
        printf("Child B running....\n");
        printf("Child B exiting....\n");
        exit(EXIT_SUCCESS);
    }
    else if (childA == -1 || childB == -1)
    {
        perror("fork");
    }
    return 0;
}