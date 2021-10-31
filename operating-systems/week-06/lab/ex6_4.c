#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/moduleparam.h>

static int int_param = 0;
// Declare int_param as a module parameter of type int
// *** COMPLETE ME ***
// Set int_param description to "An integer"
// *** COMPLETE ME ***
static char *string_param = "Empty";
// Declare string_param as a module parameter of type charp
// *** COMPLETE ME ***
// Set string_param description to "A string"
// *** COMPLETE ME ***

static int __init init_mod(void)
{
    printk(KERN_INFO "Hello, world!\n");
    // Print "int_param=<int_param>"
    // *** COMPLETE ME ***
    // Print "string_param=<string_param>"
    // *** COMPLETE ME ***
    return 0;
}

static void __exit exit_mod(void)
{
    printk(KERN_INFO "Goodbye, world!\n");
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