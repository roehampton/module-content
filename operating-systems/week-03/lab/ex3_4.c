#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

// Called when the parent exits
void parent_exit()
{
    // Print Exiting parent
    // *** COMPLETE ME ***
}

// Called when the child exits
void child_exit()
{
    // Print Exiting child
    // *** COMPLETE ME ***
}

int main(int argc, char **argv)
{
    // Create new process
    // *** COMPLETE ME ***
    if (pid > 0)
    {
        // Set the appropriate exit function
        // *** COMPLETE ME ***
        // Exit the function in success
        // *** COMPLETE ME ***
    }
    else if (!pid)
    {
        // Set the appropriate exit function
        // *** COMPLETE ME ***
        // Exit the function in success
        // *** COMPLETE ME ***
    }
    else if (pid == -1)
    {
        perror("fork");
    }
    return 0;
}