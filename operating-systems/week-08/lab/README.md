# Operating Systems Lab 08 -- Kernel Module Programming 3: Character Device Drivers

<script src="https://cdn.jsdelivr.net/npm/code-line"></script>
<script>CodeLine.initOnPageLoad({toggleBtn: {show: false}, copyBtn: {show: false}})</script>
<script src="/module-content/script/links.js"></script>

<link rel="stylesheet" href="/module-content/css/block.css">

In this lab we will build a simple device driver with a kernel module. A device driver is something that allows the operating system (and potentially the user) to communicate with hardware. We will develop a character device driver -- one that allows sending blocks of character data into and out of kernel space.

## Creating a Character Device

Creating a character device driver in a kernel module is quite simple. There are some helper functions and data structures provided by the Linux kernel headers package. These are in the following header file:

```c
#include <linux/miscdevice.h>
```

To represent a character device driver we use the data type `miscdevice`:

```c
static struct miscdevice my_dev;
```

Then during the initialisation of the kernel module we set some values of the `miscdevice` object. To start with we will set three:

```c
my_dev.minor = MISC_DYNAMIC_MINOR;
my_dev.name = "my_device";
my_dev.fops = NULL;
```

These are:

- `minor` -- relates to the identifier that will be allocated to the device. We use `MISC_DYNAMIC_MINOR` to tell the operating system to allocate us an appropriate identifier.
- `name` -- is the name of the device. This will appear in the `/dev` folder of Linux -- the location of all devices installed in the machine.
- `fops` -- we will come to in the next part of the lab. At the moment, we set this to `NULL` as we aren't using it.

After we have set the necessary values we use the `misc_register` to register and load the device into the operating system:

```c
result = misc_register(&my_dev);
```

Two points of note:

- `misc_register` will return a result code that we need to check to see if the call was successful. We store this in the `result` variable.
- `misc_register` takes one parameter -- a pointer to the `miscdevice` data structure we set up.

When we unload the module, we also have to unload the device. We do this using the `misc_deregister` function, passing a pointer to the `miscdevice` data structure.

```c
misc_deregister(&my_dev);
```

### Your Task

Let us build our first device driver:

1. **Download the [`Makefile`](Makefile){:target="_blank"}. Ensure this is saved in a file called `Makefile` in the same folder as your code.**
2. **Download the code [`ex8_1.c`](ex8_1.c){:target="_blank"}**.
3. **Complete the program by replacing the lines `// *** COMPLETE ME ***` as appropriate.**
4. **Build the kernel module using `make` on the terminal.**
5. **Install the kernel module using `sudo insmod ex8_1.ko`.**
6. **List the contents of the `/dev` folder using `ls /dev` and check that `my_device` is there.**
7. **Uninstall the kernel module using `sudo rmmod ex8_1`**.
8. **Get the kernel log messages using `dmesg`**.

The last two lines of the kernel log will be similar to the following:

```shell
[62565.716427] Device 61 created
[62573.870009] Device removed
```

The times and device ID may be different.

## Opening and Closing a Device

So far, we've not really done anything but create a device. The whole point of a device driver is to allow us to communicate with hardware. We won't actually communicate with hardware directly, but we will build up as close as possible.

The `fops` value of `miscdevice` is short for `file_operations`. These are the functions that are called when the device is interacted with. There are many file operation functions we can define, but we will only look at a few. First, we will look at how we `open` and `close` a device -- which are what happens when you call `open` and `close` as if the device was a file.

The `open` and `close` functions have the following signature:

```c
static int device_open(struct inode*, struct file*);
static int device_release(struct inode*, struct file*);
```

We aren't going to use any of these parameters in our code so we won't explain them further. The important part of our program is pointing to these functions. We do this in a `file_operations` structure as follows:

```c
struct file_operations fops =
{
    .owner = THIS_MODULE,
    .open = device_open,
    .release = device_release
};
```

We set the `.owner` of the device driver to this kernel module, then we point to `device_open` and `device_release` accordingly.

With this structure in place, we can set `fops` of our `miscdevice` structure by pointing to our `fops` value:

```c
my_dev.fops = &fops;
```

One last thing we will do is set the permissions of the device by setting the `mode` value to `SI_ALLUGO`.

```c
my_dev.mode = S_IALLUGO;
```

By default, a device is only usable by a super user and the kernel. However, for our task we want to be able to interact with it in user space. Therefore, we set the permission to `S_IALLGO` -- **ALL** permissions (read, write, execute) for **Group** and **Other**.

### Your Task

1. **Download the code [`ex8_2.c`](ex8_2.c){:target="_blank"}**.
2. **Complete the program by replacing the lines `// *** COMPLETE ME ***` as appropriate.**
3. **Update `Makefile` so the first line is `obj-m += ex8_2.o`.**
4. **Build the kernel module using `make` on the terminal.**
5. **Install the kernel module using `sudo insmod ex8_2.ko`.**
6. **Send a message to the device using `echo 1 > /dev/my_device`. You will get an error message `bash: echo: write error: Invalid argument` that you can ignore.**
7. **Uninstall the kernel module using `sudo rmmod ex8_2`**.
8. **Get the kernel log messages using `dmesg`**.

The last four lines of the kernel log should be similar to the following:

```shell
[63320.666660] Device 61 created
[63328.894466] Device open function called
[63328.895667] Device release function called
[63371.314626] Device removed
```

## Reading and Writing Behaviour

Now let us extend the device driver to respond to reading and writing operations. We do this by defining `read` and `write` operations -- again the same idea as if we were reading or writing from a file.

```c
static ssize_t device_read(struct file*, char __user*, size_t, loff_t*);
static ssize_t device_write(struct file*, const char*, size_t, loff_t*);
```

We'll only be using one of these parameters in `device_read` and two in `device_write`:

- `device_read`
  - The parameter of type `char __user*` is a pointer to a block of character data that we will send to user space -- hence the `__user` part of the type.
- `device_write`
  - The parameter of type `const char*` is the data being sent to the character device.
  - The parameter of type `size_t` is the size of the data being sent.

Both functions return a `ssize_t` type which tells the operating system how many bytes have been read or written. It is important that these are correct as otherwise it can hang the `read` and `write` calls.

To add these functions to our device driver, we simply have to point to them in our `file_operations` data structure.

```c
struct file_operations fops =
{
    .owner = THIS_MODULE,
    .open = device_open,
    .release = device_release,
    .read = device_read,
    .write = device_write
};
```

### Your Task

1. **Download the code [`ex8_3.c`](ex8_3.c){:target="_blank"}**.
2. **Complete the program by replacing the lines `// *** COMPLETE ME ***` as appropriate.**
3. **Update `Makefile` so the first line is `obj-m += ex8_3.o`.**
4. **Build the kernel module using `make` on the terminal.**
5. **Install the kernel module using `sudo insmod ex8_3.ko`.**
6. **Send a message to the device using `echo 1 > /dev/my_device`. **
7. **Read from the device using `head -n 1 /dev/my_device` (get the first line from the head of the device).**
8. **Uninstall the kernel module using `sudo rmmod ex8_3`**.
9. **Get the kernel log messages using `dmesg`**.

The last few lines of the kernel log should be similar to the following:

```shell
[64290.827664] Device 61 created
[64298.140487] Device open function called
[64298.140564] Device write function called
[64298.140593] Device release function called
[64305.995920] Device open function called
[64305.995952] Device read function called
[64305.995976] Device release function called
[64321.053709] Device removed
```

Notice that we are indeed calling the `device_write` and `device_read` functions. Let us try and actually do something with them.

## Implementing Read Behaviour

How do send data back up to the user space? The Linux kernel provides a simple method of copying from kernel memory to user memory -- `copy_to_user`:

```c
result = copy_to_user(buf, kernel_buffer, msg_len);
```

`copy_to_user` takes three parameters:

- Where to copy the data to -- `buf` as defined in our function signature.
- Where to copy the data from -- `kernel_buffer` in our example above.
- The amount of data to copy -- `msg_len` in the example above.

`copy_to_user` returns a value indicating the success or failure of the call.

### Your Task

1. **Download the code [`ex8_4.c`](ex8_4.c){:target="_blank"}**.
2. **Complete the program by replacing the lines `// *** COMPLETE ME ***` as appropriate.**
3. **Update `Makefile` so the first line is `obj-m += ex8_4.o`.**
4. **Build the kernel module using `make` on the terminal.**
5. **Install the kernel module using `sudo insmod ex8_4.ko`.**
6. **Read from the device using `head -n 1 /dev/my_device` (get the first line from the head of the device). This should display `Hello, World!`**
7. **Uninstall the kernel module using `sudo rmmod ex8_4`**.
8. **Get the kernel log messages using `dmesg`**.

The kernel log messages should be similar to:

```shell
[65509.050574] Device 61 created
[65522.589223] Device open function called
[65522.589250] Device read function completed
[65522.589337] Device release function called
[65541.824069] Device removed
```

## Implementing Write Behaviour

Much like sending data to user memory, we can copy data from user memory using `copy_to_user`:

```c
result = copy_from_user(kernel_buffer, buf, msg_len);
```

This is the same idea as sending to user memory.

1. **Download the code [`ex8_5.c`](ex8_5.c){:target="_blank"}**.
2. **Complete the program by replacing the lines `// *** COMPLETE ME ***` as appropriate.**
3. **Update `Makefile` so the first line is `obj-m += ex8_5.o`.**
4. **Build the kernel module using `make` on the terminal.**
5. **Install the kernel module using `sudo insmod ex8_5.ko`.**
6. **Send a message to the device using `echo "hello" > /dev/my_device`.**
7. **Uninstall the kernel module using `sudo rmmod ex8_4`**.
8. **Get the kernel log messages using `dmesg`**.

Your kernel log should be similar to the following:

```shell
[66818.525442] Device 61 created
[66827.668676] Device open function called
[66827.668759] Device received hello
[66827.668792] Device release function called
[66835.242857] Device removed
```

## Over to You -- Experimenting with Character Device Drivers

As with everything we have done so far with kernel modules, we have only scratched the surface. It is up to you to explore further what you can do with a character device driver. Again, you have your previous experience of C to fall back on here and help you develop interesting applications.
