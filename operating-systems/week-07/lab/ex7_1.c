#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/kthread.h>

// Our thread
static struct task_struct *thread;

// Our thread function
int thread_function(void *args)
{
    printk(KERN_INFO "I'm a thread!\n");
    return 0;
}

static int __init init_mod(void)
{
    printk(KERN_INFO "I'm a module!\n");
    // Create thread
    // *** COMPLETE ME ***
    if (thread)
    {
        printk(KERN_INFO "Thread created\n");
    }
    else 
    {
        printk(KERN_INFO "Thread creation failed\n");
        return 1;
    }
    return 0;
}

static void __exit exit_mod(void)
{
    printk(KERN_INFO "Exiting...\n");
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