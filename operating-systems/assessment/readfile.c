#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/fs.h>
#include <linux/slab.h>

char* read_file(const char *filepath, loff_t *size)
{
    // Buffer we will read into
    char *buffer;
    // File
    struct file *file = NULL;
    int err = 0;
    // Open the file in read only
    file = filp_open(filepath, O_RDONLY, S_IRWXU | S_IRWXG | S_IRWXO);
    // Check that the file exists
    if (IS_ERR(file)) 
    {
        err = PTR_ERR(file);
        printk(KERN_ERR "Error opening file");
        return NULL;
    }
    // Get size of the file
    *size = vfs_llseek(file, 0, SEEK_END);
    // Rewind to start of file again
    vfs_llseek(file, 0, SEEK_SET);
    // Allocate space to read file into
    buffer = kmalloc(*size, GFP_KERNEL);
    // Read file into buffer
    kernel_read(file, buffer, *size, size);
    // Close file
    filp_close(file, NULL);
    // Return buffer
    // size also been set
    return buffer;
}

static int __init init_function(void)
{
    loff_t size;
    char *buf = read_file("/var/log/auth.log", &size);
    printk(KERN_INFO "%s", buf);
    printk(KERN_INFO "%lld", size);
    kfree(buf);
    return 0;
}

static void __exit exit_function(void)
{
    
}

module_init(init_function);
module_exit(exit_function);
MODULE_LICENSE("GPL");
MODULE_AUTHOR("Kevin Chalmers <kevin.chalmers@roehampton.ac.uk>");
MODULE_DESCRIPTION("Device driver");