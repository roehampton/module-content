#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

// Create mutex
// *** COMPLETE ME ***

void critical_section()
{
    // Get thread ID
    // *** COMPLETE ME ***
    // Print status
    printf("%lu entering mutex\n", tid);
    // Lock the mutex
    // *** COMPLETE ME ***
    // Print status
    printf("%lu in the mutex\n", tid);
    // Wait up to 4 seconds
    int wait = rand() % 5;
    printf("%lu waiting %d seconds\n", tid, wait);
    // Sleep wait seconds
    // *** COMPLETE ME ***
    // Print status
    printf("%lu exiting mutex\n", tid);
    // Unlock the mutex
    // *** COMPLETE ME ***
}

void* worker()
{
    // Enter critical section 10 times
    for (int i = 0; i < 10; ++i)
    {
        critical_section();
    }
    // Exit the thread
    // *** COMPLETE ME ***
}

int main(int argc, char **argv)
{
    pthread_t t1;
    pthread_t t2;
    // Create the threads
    // *** COMPLETE ME ***
    // *** COMPLETE ME ***
    // Join the threads
    void *status;
    // *** COMPLETE ME ***
    // *** COMPLETE ME ***
    // Destroy the mutex
    // *** COMPLETE ME ***
    return 0;
}