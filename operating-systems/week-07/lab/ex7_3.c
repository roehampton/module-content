#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/kthread.h>
#include <linux/delay.h>
#include <linux/mutex.h>

// We have two threads and a mutex
static struct task_struct *thr1;
static struct task_struct *thr2;
static struct mutex mut;

int thread_function(void *args)
{
    int id = (int)args;
    // Loop until should stop
    // *** COMPLETE ME ***
    {
        // Lock the mutex
        // *** COMPLETE ME ***
        printk(KERN_INFO "Thread %d in the critical section\n", id);
        printk(KERN_INFO "Thread %d waiting %d seconds\n", id, id);
        // Sleep for 1000 * id milliseconds
        // *** COMPLETE ME ***
        printk(KERN_INFO "Thread %d exiting critical section\n", id);
        // Unlock the mutex
        // *** COMPLETE ME ***
    }
    return 0;
}

static int __init init_mod(void)
{
    // Initialise the mutex
    // *** COMPLETE ME ***
    // Create thr1 -- pass 1 as an argument (cast to void*)
    // *** COMPLETE ME ***
    // Create thr2 -- pass 2 as an argument (cast to void*)
    // *** COMPLETE ME ***
    if (thr1 && thr2)
    {
        printk(KERN_INFO "Threads started\n");
    }
    else 
    {
        printk(KERN_INFO "Cannot create threads\n");
        return 1;
    }
    return 0;
}

static void __exit exit_mod(void)
{
    // Stop thr1
    // *** COMPLETE ME ***
    // Stop thr2
    // *** COMPLETE ME ***
    printk(KERN_INFO "Exiting!\n");
}

// Set module initialisation function
// *** COMPLETE ME ***
// Set module exit function
// *** COMPLETE ME ***

// Set module license to GPL
// *** COMPLETE ME ***
// Set module author
// *** COMPLETE ME ***
// Set module description
// *** COMPLETE ME ***