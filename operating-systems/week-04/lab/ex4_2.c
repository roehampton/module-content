#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

// Print thread ID
void* print_id()
{
    // Get the thread ID
    // *** COMPLETE ME ***
    // Print the thread ID
    printf("My ID is %lu\n", tid);
    // Exit the thread
    // *** COMPLETE ME ***
}

int main(int argc, char **argv)
{
    // Array of 100 threads
    pthread_t threads[100];

    // Launch 100 threads
    for (int i = 0; i < 100; ++i)
    {
        // Create thread i in the array using print_id
        // *** COMPLETE ME ***
    }
    // Print a message
    printf("I'm the main program!\n");
    // Join 100 threads
    void *status;
    for (int i = 0; i < 100; ++i)
    {
        // Join thread i in the array
        // *** COMPLETE ME ***
    }
    return 0;
}