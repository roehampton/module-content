#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/kthread.h>
#include <linux/delay.h>

static struct task_struct *thread;

int thread_function(void *args)
{
    int i = 0;
    // Loop until thread should stop
    // *** COMPLETE ME ***
    {
        printk(KERN_INFO "In thread function %d\n", ++i);
        // Sleep for 1000 milliseconds
        // *** COMPLETE ME ***
    }
    printk(KERN_INFO "Thread exiting\n");
    return 0;
}

static int __init init_mod(void)
{
    // Create thread using kthread_create
    // *** COMPLETE ME ***
    // Bind thread to CPU 0
    // *** COMPLETE ME ***
    // Wake up the thread
    // *** COMPLETE ME ***
    if (thread)
    {
        printk(KERN_INFO "Thread started\n");
    }
    else 
    {
        printk(KERN_INFO "Cannot create thread\n");
        return 1;
    }
    return 0;
}

static void __exit exit_mod(void)
{
    // Stop the thread
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