#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/miscdevice.h>

static struct miscdevice my_dev;

static int device_open(struct inode*, struct file*);
static int device_release(struct inode*, struct file*);

struct file_operations fops =
{
    // Set owner of the module
    // *** COMPLETE ME ***
    // Point to open function
    // *** COMPLETE ME ***
    // Point to release function
    // *** COMPLETE ME ***
};

static int __init init_function(void)
{
    int result;
    // Set minor of device to MISC_DYNAMIC_MINOR
    // *** COMPLETE ME ***
    // Give the device the name my_device
    // *** COMPLETE ME ***
    // Set fops of device to fops
    // *** COMPLETE ME ***
    // Set mode to allow all permissions
    // *** COMPLETE ME ***
    // Register the device getting the result
    // *** COMPLETE ME ***
    if (result) {
        printk(KERN_ERR "Creating device failed\n");
        return 0;
    }
    printk(KERN_INFO "Device %d created\n", my_dev.minor);
    return 0;
}

static void __exit exit_function(void)
{
    // Deregister device
    // *** COMPLETE ME ***
    printk(KERN_INFO "Device removed\n");
}

static int device_open(struct inode *inode, struct file *file)
{
    printk(KERN_INFO "Device open function called\n");
    return 0;
}

static int device_release(struct inode *inode, struct file *file)
{
    printk(KERN_INFO "Device release function called\n");
    return 0;
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