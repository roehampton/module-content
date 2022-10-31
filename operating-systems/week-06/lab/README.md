# Operating Systems Lab 06 -- Kernel Module Programming 1

<script src="https://cdn.jsdelivr.net/npm/code-line"></script>
<script>CodeLine.initOnPageLoad({toggleBtn: {show: false}, copyBtn: {show: false}})</script>
<script src="/module-content/script/links.js"></script>

<link rel="stylesheet" href="/module-content/css/block.css">

Over the next few labs, we will be building **Linux kernel modules**. What is a kernel module? It is code we load into the kernel to extend its functionality. An example of a kernel module is a *device driver* -- the software that allows the kernel to talk to an unknown piece of hardware. A kernel module runs within the kernel, and is therefore running in *kernel-mode* not *user-mode*. This gives a kernel module greater permissions to execute within your computer.

## Creating a Linux Kernel Module

Kernel modules are written in C. This means that your previous experience with C goes a long way to help you program Linux kernel modules. However, your system isn't currently set up for building kernel modules as we need to install the Linux headers for our current kernel version.

### Installing Linux Kernel Headers

**Run the following from the command line in your Linux machine. You will be asked for your password.**

```shell
sudo apt install linux-headers-$(uname -r)
```

**If you need to know what is happening:**

- `sudo` asks to run something as a superuser.
- `apt` is Ubuntu's package manager used for installing, updating, and removing software.
- `install` is telling `apt` we want to install software which we give as a name next.
- `$(uname -r)` gets the current Linux kernel version and replaces this text. Run `uname -r` (and even just `uname`) yourself to test the output.

### Basic Kernel Module Code

Our first kernel module will be a basic hello world program. First, to create a kernel module we require the following two headers:

```c
#include <linux/module.h>
#include <linux/kernel.h>
```

These define the data and functions for module programming and interacting with the kernel.

A basic kernel module has two functions -- `init_module` and `cleanup_module`. These are called when the module is initially loaded into the kernel (`init_module`) and unloaded from the kernel (`cleanup_module`). `init_module` takes the following form:

```c
int init_module() 
{
  // ...
}
```

And `cleanup_module` is as follows:

```c
void cleanup_module()
{
  // ...
}
```

### Printing Messages to the Kernel Log

A kernel module is not a normal user application. It doesn't have a `main` method, and it doesn't run within a user interface to print messages to the screen. A kernel module runs within the kernel, executing code on demand. So how can we display output from our kernel module? We use the `printk` function:

```c
printk(...);
```

`printk` operates as `printf`, although we can also define what type of kernel message we are printing. For example, to print `Hello, world!` as an information message we would use the following `printk` call:

```c
printk(KERN_INFO "Hello, world!\n");
```

`printk` can output the following message types:

- `KERN_EMERG`
- `KERN_ALERT`
- `KERN_ERR`
- `KERN_WARNING`
- `KERN_NOTICE`
- `KERN_INFO`
- `KERN_DEBUG`
- `KERN_DEFAULT`
- `KERN_CONT`

The kernel keeps a log of all messages, and we can print them all using the following command in the terminal:

```shell
dmesg
```

An example output would be:

```shell
....
[ 8309.971459] ex6_1: module license 'unspecified' taints kernel.
[ 8309.971462] Disabling lock debugging due to kernel taint
[ 8309.971680] Hello, world!
[ 8317.830395] Goodbye, world!
```

### Building Kernel Modules

Building a kernel module isn't as simple as calling `gcc`. We have to use a specific builder program provided with the Linux kernel build tools. The way to do this is to create a `Makefile`. A basic version is below:

```makefile
obj-m += ex6_1.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
```

To highlight what this does:

- We add `ex6_1.o` to the module build queue. As `ex6_1.o` is an object file built from `ex6_1.c`, this will also use `gcc` to compile our C program.
- We use the module `build` command to build all the modules. This is the line after `all`.
- We can also use a `make clean` command to clean up our files.

To build our kernel module, we call `make` in the folder with the `Makefile` and code file(s) in it:

```shell
make
```

Calling this command will create a number of new files. The most important one is the one with the file extension `.ko` (for example `ex6_1.ko`). This is our kernel module.

### Installing and Removing a Kernel Module

Once we have a built kernel module (a `.ko` file), we can install it using the `insmod` terminal command:

```shell
sudo insmod ex6_1.ko
```

We must run this using `sudo` as we require superuser privileges to load a kernel module. The only other information we need to provide is the name of the kernel module file we want to load.

We can check that a module is loaded using the following command in the terminal:

```shell
lsmod
```

Our loaded module should appear at the top of the displayed list:

```shell
Module                  Size  Used by
ex6_1                  16384  0
nls_iso8859_1          16384  1
xt_conntrack           16384  2
nf_conntrack          147456  1 xt_conntrack
....
```

To remove a module we use the `rmmod` command in the terminal:

```shell
sudo rmmod ex6_1
```

Again, we require superuser privileges to uninstall a module.

### Your Task

Let us now build our first kernel module:

1. **Download the [`Makefile`](Makefile){:target="_blank"}. Ensure this is saved in a file called `Makefile` in the same folder as your code.**
2. **Download the code [`ex6_1.c`](ex6_1.c){:target="_blank"}**.
3. **Complete the program by replacing the lines `// *** COMPLETE ME ***` as appropriate.**
4. **Build the kernel module using `make` on the terminal.**
5. **Install the kernel module using `sudo insmod ex6_1.ko`.**
6. **Uninstall the kernel module using `sudo rmmod ex6_1`**.
7. **Get the kernel log messages using `sudo dmesg`**.

The kernel log should look similar to the following (the timestamps on the left will be different):

```shell
....
[ 8309.971459] ex6_1: module license 'unspecified' taints kernel.
[ 8309.971462] Disabling lock debugging due to kernel taint
[ 8309.971680] Hello, world!
[ 8317.830395] Goodbye, world!
```

## Flexible Kernel Module Development

Early kernel module development required you to use the `init_module` and `cleanup_module` functions. This is not very flexible, and doesn't allow you to have different initialisation and cleanup for different build conditions. Today, we instead define which functions act as our initialisation and cleanup using `module_init` and `module_exit`. These are defined in the following header: 

```c
#include <linux/init.h>
```

Our initialisation function has to follow a prototype -- it must return an `int` and have `void` parameters. We also flag the function as an initialisation one using `__init`. Below is an example:

```c
static int __init init_function(void)
{
  // ...
}
```

Then it is a simple task of using `module_init` with this module name to use this as our kernel module initialisation function:

```c
module_init(init_function);
```

Our exit functions also follow a prototype -- they must return `void` and have `void` parameters. We also must signal this as an exit function using `__exit`. An example is below:

```c
static void __exit exit_function(void)
{
  // ...
}
```

We then use `module_exit` to declare this function as the one to call when the module is unloaded:

```c
module_exit(exit_function);
```

### Your Task

1. **Download the code [`ex6_2.c`](ex6_2.c){:target="_blank"}**.
2. **Complete the program by replacing the lines `// *** COMPLETE ME ***` as appropriate.**
3. **Update `Makefile` so the first line is `obj-m += ex6_2.o`.**
4. **Build the kernel module using `make` on the terminal.**
5. **Install the kernel module using `sudo insmod ex6_2.ko`.**
6. **Uninstall the kernel module using `sudo rmmod ex6_2`**.
7. **Get the kernel log messages using `sudo dmesg`**.

The end of the kernel log should be as follows:

```shell
[39237.060489] Hello, world!
[39237.060491] Data is 10
[39241.415192] Goodbye, world!
```

## Module Licence and Authors

A kernel module should provide information about the license, author, and description. This allows users to know what they are installing. The license value is especially important in Linux due to the open source ethos. To set a license we use `MODULE_LICENSE`. For example, to set the license as GPL (GNU Public License), we use:

```c
MODULE_LICENSE("GPL");
```

To set the author we use `MODULE_AUTHOR`:

```c
MODULE_AUTHOR("Name <email>")
```

And to set the description we use `MODULE_DESCRIPTION`:

```c
MODULE_DESCRIPTION("Description");
```

Once we build the module, we can use the `modinfo` terminal command to get this information. For example:

```shell
modinfo ex6_3.ko
```

### Your Task

1. **Download the code [`ex6_3.c`](ex6_3.c){:target="_blank"}**.
2. **Complete the program by replacing the lines `// *** COMPLETE ME ***` as appropriate.**
3. **Update `Makefile` so the first line is `obj-m += ex6_3.o`.**
4. **Build the kernel module using `make` on the terminal.**
5. **Check the module information using `modinfo ex6_3.ko`.**

Your output should be similar to the following:

```shell
filename:       /home/student/OS/week-06/ex6_3.ko
description:    A simple module
author:         Kevin Chalmers <kevin.chalmers@roehampton.ac.uk>
license:        GPL
srcversion:     23C956A926D0DAA93796B5A
depends:        
retpoline:      Y
name:           ex6_3
vermagic:       5.8.0-1043-azure SMP mod_unload modversions 
```

## Module Parameters

So far, we've been relying on all our data existing in the module on building. Let us now add parameters to our kernel module which we can set when we install the module.

To have module parameters, we need to include the following header:

```c
#include <linux/moduleparam.h>
```

This allows us to declare module variables as a parameter. To do this, we use the `module_param` function:

```c
module_param(parameter, type, permissions);
```

It takes three values:

- The variable we are making a module parameter.
- The type (i.e., an `int`, or `charp` for a character pointer/string).
- Parameter permissions -- we'll ignore this for now and set it to `0`.

To declare the parameter in the module information, we use `MODULE_PARM_DESC`:

```c
MODULE_PARM_DESC(parameter, "Description");
```

For example, let us say we have a string (`char*`) variable called `str` we want to make a module parameter. To do this, our code in the kernel module would be as follows:

```c
char *str = "Empty";
module_param(str, charp, 0);
MODULE_PARM_DESC(str, "A string parameter");
```

Once we  build the module, we can set the parameters when we install it:

```shell
sudo insmod ex6_4.ko str="Hello"
```

### Your Task

1. **Download the code [`ex6_4.c`](ex6_4.c){:target="_blank"}**.
2. **Complete the program by replacing the lines `// *** COMPLETE ME ***` as appropriate.**
3. **Update `Makefile` so the first line is `obj-m += ex6_4.o`.**
4. **Build the kernel module using `make` on the terminal.**
5. **Install the kernel module using `sudo insmod ex6_4.ko int_param=10 string_param="Woohoo"`.**
6. **Uninstall the kernel module using `sudo rmmod ex6_4`**.
7. **Get the kernel log messages using `sudo dmesg`**.

The output from `dmesg` will be as follows:

```shell
[98063.398077] Hello, world!
[98063.398078] int_param=10
[98063.398079] string_param=Woohoo
[98071.619176] Goodbye, world!
```

If you use `modinfo ex6_4.ko` you will get an output similar to the following:

```shell
filename:       /home/student/OS/week-06/ex6_4.ko
description:    A simple module
author:         Kevin Chalmers <kevin.chalmers@roehampton.ac.uk>
license:        GPL
srcversion:     6B3693287C0A5C00F619C01
depends:        
retpoline:      Y
name:           ex6_4
vermagic:       5.8.0-1043-azure SMP mod_unload modversions 
parm:           int_param:An integer (int)
parm:           string_param:A string (charp)
```

## Over to You -- Building Kernel Modules

Now try extending your kernel modules to do different tasks. At the moment, all you can do is run code when the module loads and unloads, but in theory you can do anything that doesn't require user interaction.
