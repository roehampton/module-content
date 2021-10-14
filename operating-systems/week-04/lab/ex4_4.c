#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

// Global mutex
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

void critical_section()
{
    // Get thread
    pthread_t tid = pthread_self();
    // Print status
    printf("%lu entering mutex\n", tid);
    // Lock the mutex
    pthread_mutex_lock(&mutex);
    // Print status
    printf("%lu in the mutex\n", tid);
    // Wait
    int wait = rand() % 5;
    printf("%lu waiting %d seconds\n", tid, wait);
    sleep(wait);
    // Print status
    printf("%lu exiting mutex\n", tid);
    // Unlock the mutex
    pthread_mutex_unlock(&mutex);
}

void* worker(void *args)
{
    // Enter critical section 10 times
    for (int i = 0; i < 10; ++i)
    {
        critical_section();
    }
    pthread_exit(NULL);
}

int main(int argc, char **argv)
{
    pthread_t t1;
    pthread_t t2;
    // Create the threads
    pthread_create(&t1, NULL, worker, NULL);
    pthread_create(&t2, NULL, worker, NULL);
    // Join the threads
    void *status;
    pthread_join(t1, &status);
    pthread_join(t2, &status);
    // Destroy the mutex
    pthread_mutex_destroy(&mutex);
    return 0;
}