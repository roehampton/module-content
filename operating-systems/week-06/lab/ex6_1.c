#include <linux/module.h>
#include <linux/kernel.h>

int init_module()
{
    // Print Hello, World! as KERN_INFO message
    // *** COMPLETE ME ***
    return 0;
}

void cleanup_module()
{
    // Print Goodbye, World! as KERN_INFO message
    // *** COMPLETE ME ***
}

MODULE_LICENSE("GPL");
