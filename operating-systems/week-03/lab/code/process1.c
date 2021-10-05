#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    // Get the process ID
    pid_t pid = getpid();
    // Get the parent process ID
    pid_t parent = getppid();
    // Print the process ID
    printf("My pid=%d\n", pid);
    // Print the parent process ID
    printf("Parent pid=%d\n", parent);
    
    return 0;
}