#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <math.h>

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
    // Run NUM_THREADS
    pthread_t threads[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; ++i)
    {
        // Create thread i
        // *** COMPLETE ME ***
    }
    void *status;
    for (int i = 0; i < NUM_THREADS; ++i)
    {
        // Join thread i
        // *** COMPLETE ME ***
    }
    return 0;
}