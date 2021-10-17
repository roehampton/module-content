#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

// Thread function
void* do_work()
{
    printf("I'm a thread!\n");
    // Exit the thread
    // *** COMPLETE ME ***
}

int main(int argc, char **argv)
{
    pthread_t thread;
    // Create a thread using the do_work function
    // *** COMPLETE ME ***
    printf("I'm the main program!\n");
    void *status;
    // Join the thread
    // *** COMPLETE ME ***
    return 0;
}