# Operating Systems Lab 09 -- Kernel Module Programming 4: Input/Output Control

<script src="https://cdn.jsdelivr.net/npm/code-line"></script>
<script>CodeLine.initOnPageLoad({toggleBtn: {show: false}, copyBtn: {show: false}})</script>
<script src="/module-content/script/links.js"></script>

<link rel="stylesheet" href="/module-content/css/block.css">

In this final exploration of kernel module programming, we will examine input/output control (`ioctl`). `ioctl` allows us to specify messages to send to a driver to allow input/output operations beyond what is possible with system calls.

## Device Input/Output Control

To define `ioctl` within our existing device drivers we need the `ioctl.h` header file.

```c
#include <linux/ioctl.h>
```

As with our other device driver functions, we use a special function to capture the message calls:

```c
static long device_ioctl(struct file*, unsigned int cmd, unsigned long arg);
```

We are interested in two of these parameters:

- `cmd` -- the command being sent to the driver.
- `arg` -- the argument passed to the call. Although this is type `unsigned long` it can effectively be thought of as a pointer if necessary.

To state our device driver has an `ioctl` function we set `.unlocked_ioctl` in the `file_operations` structure:

```c
struct file_operations fops =
{
    .owner = THIS_MODULE,
    .open = device_open,
    .release = device_release,
    .unlocked_ioctl = device_ioctl
};
```

And that is it from the device driver side of things. However, we now need to write a userland programme that can talk to the `ioctl` function.

### Userland Program for Device Driver Interaction

To use hardware `ioctl` through a driver, a program needs to interact via a library provided via the hardware manufacturer. A simple model is:

```
User application --> Library --> Device driver
```

We won't create a library (you should already know how) but just a simple userland application. First, we have to include the following headers to allow us to talk to the device driver through its `ioctl` interface:

```c
#include <fcntl.h>
#include <sys/ioctl.h>
```

Next, we have to open the device using the `open` function:

```c
fd = open("/dev/my_device", O_RDWR);
```

`open` takes the following parameters:

- The **device** name to be opened. In our case, this will be `/dev/my_device`.
- The **access mode**. We will use `O_RDWR` which means we can *read* and *write* to the device.

`open` returns an `int` representing ID to talk to the device. To actually send a message to the driver we use the `ioctl` function:

```c
ioctl(fd, MY_CALL);
```

We need at least two parameters for `ioctl`:

- The ID of the device we want to talk to.
- The message we are sending. We will explain `MY_CALL` in the next part of the lesson.

Finally, we must call `close` on the ID to close our connection with the device.

```c
close(fd);
```

### Your Task

Let us write our first `ioctl` driver and program.

1. **Download the [`Makefile`](Makefile){:target="_blank"}. Ensure this is saved in a file called `Makefile` in the same folder as your code.**
2. **Download the code [`user_program.c`](user_program.c){:target="_blank"}. This is the user program.**
3. **Complete the user program by replacing the lines `// *** COMPLETE ME ***` as appropriate.**
4. **Build the user program by using `gcc user_program.c -o user_program`**
5. **Download the code [`ex9_1.c`](ex9_1.c){:target="_blank"}**.
6. **Complete the program by replacing the lines `// *** COMPLETE ME ***` as appropriate.**
7. **Build the kernel module using `make` on the terminal.**
8. **Install the kernel module using `sudo insmod ex9_1.ko`.**
9. **Run the user program by using the command `./user_program`**.
10. **Uninstall the kernel module using `sudo rmmod ex9_1`**.
11. **Get the kernel log messages using `dmesg`**.

The end of the kernel log should be similar to the following:

```shell
[270338.702556] Device 61 created
[270343.064325] Device open function called
[270343.064360] Device IOCTL invoked
[270343.064383] Device release function called
[270350.912856] Device removed
```

## Input/Output Control Function

In the last exercise, we sent a `MY_CALL` message to the device, but what was `MY_CALL`. It was actually defined in the `user_program.c` file as:

```c
#define MY_CALL _IO('X', 0)
```

If you don't remember the structure of a `#define` statement:

- `#define` is a message to the preprocessor to that creates a label that will be replaced during compilation.
- `MY_CALL` is the label we are creating.
- `_IO('X', 0)` is the message type we are creating. It currently has three parts:
  - `_IO` means it is a simple IO message with no parameters. Other message types can have parameters, such as `_IOR` (read) and `_IOW` (write).
  - `X` is an ID we are giving to the device. Really, we should be using the correct device ID but to get that in the user program takes more work, so we will just use `X`.
  - `0` is the ID of the message we are sending to the device. These must be unique.

We then write a `switch` statement in our `device_ioctl` function dealing with `MY_CALL`:

```c
switch (cmd)
{
    case MY_CALL:
        printk(KERN_INFO "Received MY_CALL\n", arg);
        break;
}
```

### Your Task

1. **Download the code [`ex9_2.c`](ex9_2.c){:target="_blank"}**.
2. **Complete the program by replacing the lines `// *** COMPLETE ME ***` as appropriate.**
3. **Update `Makefile` so the first line is `obj-m += ex9_2.o`.**
4. **Build the kernel module using `make` on the terminal.**
5. **Install the kernel module using `sudo insmod ex9_2.ko`.**
6. **Run the user program by using the command `./user_program`**.
7. **Uninstall the kernel module using `sudo rmmod ex9_2`**.
8. **Get the kernel log messages using `dmesg`**.

The output from the kernel log is:

```shell
[329270.447178] Device 61 created
[329274.958075] Device open function called
[329274.958108] Received MY_CALL
[329274.958129] Device release function called
[329284.440595] Device removed
```

## Sending Data From a User Program

Let us now define another call -- one that will send an argument to the device. We must define this is **both the driver program and user program.**

```c
#define MY_WRITE _IOW('X', 1, unsigned long)
```

Note that the `#define` looks very similar to the previous one, but we now have an argument of type `unsigned long`. Our driver then needs to be able to respond to this message in the `switch` statement:

```c
switch (cmd)
{
    case MY_CALL:
        printk(KERN_INFO "Received MY_CALL\n");
        break;
    case MY_WRITE:
        printk(KERN_INFO "MY_WRITE received %lu\n", arg);
        break;
}
```

We can use the passed `arg` value now. In our user program we just call `ioctl` with the new message type and an argument.

```c
ioctl(fd, MY_WRITE, 54u);
```

### Your Task

1. **Download the code [`ex9_3.c`](ex9_3.c){:target="_blank"}**.
2. **Complete the program by replacing the lines `// *** COMPLETE ME ***` as appropriate.**
3. **Update `Makefile` so the first line is `obj-m += ex9_3.o`.**
4. **Build the kernel module using `make` on the terminal.**
5. **Install the kernel module using `sudo insmod ex9_3.ko`.**
6. **Update `user_program.c` to define `MY_WRITE` and to send the appropriate `ioctl` message.**
7. **Compile the user program using `gcc user_program.c -o user_program`.**
8. **Run the user program by using the command `./user_program`**.
9. **Uninstall the kernel module using `sudo rmmod ex9_3`**.
10. **Get the kernel log messages using `dmesg`**.

Your kernel log should end with the following:

```shell
[330933.537214] Device 61 created
[330957.150655] Device open function called
[330957.150810] Received MY_CALL
[330957.150828] MY_WRITE received 54
[330957.150904] Device release function called
[330963.082808] Device removed
```

## Writing Data to a User Program

Finally, we can also send data back to the user program. Let us copy a block of character data (a string) back to the user program:

```c
#define MY_READ _IOR('X', 2, char*)
```

Then we need to update our `switch` in the device driver:

```c
switch (cmd)
{
    case MY_CALL:
        printk(KERN_INFO "Received MY_CALL\n");
        break;
    case MY_WRITE:
        printk(KERN_INFO "MY_WRITE received %lu\n", arg);
        break;
    case MY_READ:
        printk(KERN_INFO "MY_READ called\n");
        copy_to_user((char*)arg, msg, len);
        break;
}
```

And finally send the `MY_READ` message to the device.

```c
ioctl(fd, MY_READ, str);
```

### Your Task

1. **Download the code [`ex9_4.c`](ex9_4.c){:target="_blank"}**.
2. **Complete the program by replacing the lines `// *** COMPLETE ME ***` as appropriate.**
3. **Update `Makefile` so the first line is `obj-m += ex9_4.o`.**
4. **Build the kernel module using `make` on the terminal.**
5. **Install the kernel module using `sudo insmod ex9_4.ko`.**
6. **Update `user_program.c` to define `MY_WRITE`, send the appropriate `ioctl` message, and then print the received message.**
7. **Compile the user program using `gcc user_program.c -o user_program`.**
8. **Run the user program by using the command `./user_program`. Your user program should output `Received Hello, world! from driver`**.
9. **Uninstall the kernel module using `sudo rmmod ex9_4`**.
10. **Get the kernel log messages using `dmesg`**.

Your kernel log should end with the following:

```shell
[331297.350996] Device 61 created
[331311.151070] Device open function called
[331311.151107] Received MY_CALL
[331311.151125] MY_WRITE received 54
[331311.151137] MY_READ received
[331311.151621] Device release function called
[331367.831960] Device removed
```

## Over to You -- Exploring Input/Output Control

We have ended our exploration of kernel programming and you now have the tools to write significant kernel modules on Linux. We haven't explored how to talk directly to hardware, but you can research this and see how you can send messages from your driver to hardware. **WARNING** -- this will require some real low level manipulation of hardware, much the same as you did when reading from a specific disk sector.
