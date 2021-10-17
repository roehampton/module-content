#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void* sleeper(void *arg)
{
    // Cast the argument to the right type
    int duration = (int)arg;
    // Get the current thread
    // *** COMPLETE ME ***
    // Wake up every duration
    for (int i = 0; i < 10; ++i)
    {
        printf("%lu awake!\n", tid);
        printf("%lu going to sleep\n", tid);
        // Sleep for duration seconds
        // *** COMPLETE ME ***
    }
    // Exit the thread
    // *** COMPLETE ME ***
}

int main(int argc, char **argv)
{
    pthread_t t1;
    pthread_t t2;
    // Create thread 1 - sleeps 2 seconds
    // *** COMPLETE ME ***
    // Create thread 2 - sleeps 3 seconds
    // *** COMPLETE ME ***
    // Join the threads
    void *status;
    // Join thread 1
    // *** COMPLETE ME ***
    // Join thread 2
    // *** COMPLETE ME ***
    return 0;
}