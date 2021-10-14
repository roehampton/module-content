#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

// Print thread ID
void* print_id(void *arg)
{
    // Get the thread ID
    pthread_t tid = pthread_self();
    // Print the thread ID
    printf("My ID is %lu\n", tid);
    // Exit the thread
    pthread_exit(NULL);
}

int main(int argc, char **argv)
{
    // Array of 100 threads
    pthread_t threads[100];

    // Launch 100 threads
    for (int i = 0; i < 100; ++i)
    {
        pthread_create(&threads[i], NULL, print_id, NULL);
    }
    // Print a message
    printf("I'm the main program!\n");
    // Join 100 threads
    void *status;
    for (int i = 0; i < 100; ++i)
    {
        pthread_join(threads[i], &status);
    }
    return 0;
}