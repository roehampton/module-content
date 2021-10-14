#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>

// Thread function
void* do_work(void *arg)
{
    printf("I'm a thread!\n");
    // Exit the thread
    pthread_exit(NULL);
}

int main(int argc, char **argv)
{
    pthread_t thread;
    // Create a thread
    pthread_create(&thread, NULL, do_work, NULL);
    printf("I'm the main program!\n");
    void *status;
    // Join the thread
    pthread_join(thread, &status);
    return 0;
}