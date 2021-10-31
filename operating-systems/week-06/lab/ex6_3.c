#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

static int __init hello_init(void)
{
    // Print "Hello, world!" as KERN_INFO
    // *** COMPLETE ME ***
    return 0;
}

static void __exit hello_exit(void)
{
    // Print "Goodbye, world!" as KERN_INFO
    // *** COMPLETE ME ***
}

// Set hello_init as module initialisation
// *** COMPLETE ME ***
// Set hello_exit as module exit
// *** COMPLETE ME ***
// Set module license to GPL
// *** COMPLETE ME ***
// Set module author to your name and email
// *** COMPLETE ME ***
// Set module description to "A simple module"
// *** COMPLETE ME ***