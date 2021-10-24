#define _GNU_SOURCE
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <math.h>
#include <sched.h>
#include <unistd.h>

// The number of threads to launch
const int NUM_THREADS = 10;

// This function finds all the primes under 1000000
void find_primes(int tid)
{
    int max = 1000000;
    int count = 0;
    // Loop through all numbers up to 1000000
    for (int i = 2; i <= max; ++i)
    {
        // Flag to show if prime
        int prime = 1;
        // Loop through all numbers less than sqrt(i)
        for (int j = 2; j <= (int)sqrt(i); ++j)
        {
            // Test if prime
            if (i % j == 0)
            {
                prime = 0;
                break;
            }
        }
        // If prime, increment counter
        if (prime)
        {
            ++count;
        }
    }
    // Print out how many primes found
    printf("Thread %d found %d primes\n", tid, count);
}

// The function run by a thread
void* do_work(void *args)
{
    int id = (int)args;
    printf("%d working\n", id);
    find_primes(id);
    return 0;
}

int main(int argc, char **argv)
{
    // Get the current process
    pid_t pid = getpid();
    // Create sched_param
    struct sched_param param;
    // Set priority to maximum (20)
    param.sched_priority = 20;
    // Set scheduler to FIFO queue
    // *** COMPLETE ME ***
    // Run NUM_THREADS
    pthread_t threads[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; ++i)
    {
        // Create the thread
        // *** COMPLETE ME ***
        cpu_set_t cpuset;
        // Zero the data
        // *** COMPLETE ME ***
        // Set CPU i % 4
        // That is, we only use cores 0 - 3.
        // *** COMPLETE ME ***
        // Set affinity for the thread
        // *** COMPLETE ME ***
    }
    void *status;
    for (int i = 0; i < NUM_THREADS; ++i)
    {
        // Join the thread
        // *** COMPLETE ME ***
    }
    return 0;
}