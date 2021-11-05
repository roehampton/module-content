# Operating Systems Lab 07 -- Linux Kernel Module Programming 2: Using Kernel Threads

<script src="https://cdn.jsdelivr.net/npm/code-line"></script>
<script>CodeLine.initOnPageLoad({toggleBtn: {show: false}, copyBtn: {show: false}})</script>
<script src="/module-content/script/links.js"></script>

<link rel="stylesheet" href="/module-content/css/block.css">

In this lab, we will return to working with threads. However, we are now working in kernel mode and we need to use kernel threads rather than user threads (e.g., `pthread`). If we want to run our kernel module as a background service, we need to launch a thread to execute the program.

## What are Kernel Threads?

Linux kernel threads -- `kthread` -- are similar to threads created by user libraries, except they execute in kernel space and are managed by the operating system. Otherwise, a `kthread` is the same as a normal thread -- it is an indpenedently running part of our kernel module.

## Creating a Kernel Thread

To use kernel threads in Linux, we must include the `kthread` header file:

```c
#include <linux/kthread.h>
```

A `kthread` is represented by a `task_struct` type:

```c
struct task_struct *thread;
```

`task_struct` contains more information than just a number. It also contains scheduling information, data attached to the thread, priority, and other useful data. We won't be using any of this data in this lab, but you might want to explore this further if you are interested.

To create and run a `kthread` we use the `kthread_run` function:

```c
thread = kthread_run(thread_function, NULL, "module thread");
```

`kthread_run` returns a pointer to the created `kthread`. This is managed by the operating system, hence you get a pointer to the information in memory. Three parameters are provided:

- The function that the thread will run.
- A pointer to any argument data sent to the thread.
- The friendly name that allows users to view thread information. We won't worry too much about this.

A `kthread` fuction is a similar concept to a `pthread` function, although the signature is different:

```c
int thread_function(void *args)
{
  // ...
}
```

A `kthread` function must return an `int`, and takes a `void*` as an argument.

With your previous knowledge of `pthread` you should now be able to complete your first exercise using a `kthread`.

### Your Task

Let us now build our first `kthread` kernel module:

1. **Download the [`Makefile`](Makefile){:target="_blank"}. Ensure this is saved in a file called `Makefile` in the same folder as your code.**
2. **Download the code [`ex7_1.c`](ex7_1.c){:target="_blank"}**.
3. **Complete the program by replacing the lines `// *** COMPLETE ME ***` as appropriate.**
4. **Build the kernel module using `make` on the terminal.**
5. **Install the kernel module using `sudo insmod ex7_1.ko`.**
6. **Uninstall the kernel module using `sudo rmmod ex7_1`**.
7. **Get the kernel log messages using `dmesg`**.

The kernel log should look similar to the following (the timestamps on the left will be different):

```shell
[74297.615118] I'm a module!
[74297.618605] Thread created
[74297.618611] I'm a thread!
[74304.315445] Exiting...
```

## Stopping a Kernel Thread

When our kernel module unloads, we will have to stop the `kthread`. This isn't something we can simply do -- we must write code that deals with a stop signal.

To stop a `kthread` we use the `kthread_stop` function:

```c
kthread_stop(thread);
```

This takes one parameter -- a pointer to the `task_struct` representing the `kthread` we want to stop.

Our executing thread has to check to see if it should stop. This is done using the `kthread_should_stop` function, which will return `true` when `kthread_stop` has been called on the `kthread`. A typical way we would support this is to use a `while` loop as follows:

```c
while (!kthread_should_stop())
{
  // ...
}
```

In our exercise we will also cause our thread to sleep. As we are in kernel mode, there is no `sleep` function. Thankfully, the kernel API has a `msleep` function which causes a thread to sleep for a given number of milliseconds.

```c
msleep(1000);
```

### Your Task

1. **Download the code [`ex7_2.c`](ex7_2.c){:target="_blank"}**.
2. **Complete the program by replacing the lines `// *** COMPLETE ME ***` as appropriate.**
3. **Update `Makefile` so the first line is `obj-m += ex7_2.o`.**
4. **Build the kernel module using `make` on the terminal.**
5. **Install the kernel module using `sudo insmod ex7_2.ko`.**
6. **Uninstall the kernel module using `sudo rmmod ex7_2`**.
7. **Get the kernel log messages using `dmesg`**.

Your log should be similar to the following depending on when you removed it.

```shell
[79667.253248] Thread started
[79667.253259] In thread function 1
[79668.301743] In thread function 2
[79669.325727] In thread function 3
[79670.349691] In thread function 4
[79671.373766] In thread function 5
[79672.397664] In thread function 6
[79673.405784] Thread exiting
[79673.408357] Exiting!
```

## Using Kernel Mutual Exclusion Locks

As with `pthread` there are kernel level mutexes we can use to control access to resources. These have type `mutex`:

```c
struct mutex mut;
```

To initialise a `mutex` we use the `mutex_init` function:

```c
mutex_init(&mut);
```

It takes one parameter -- a pointer to the `mutex` to be initialised.

We can also lock a `mutex` using `mutex_lock`:

```c
mutex_lock(&mut);
```

And unlock a `mutex` we have locked using `mutex_unlock`:

```c
mutex_unlock(&mut);
```

Otherwise, a `mutex` in kernel mode operates the same as one from the `pthread` library.

### Your Task

1. **Download the code [`ex7_3.c`](ex7_3.c){:target="_blank"}**.
2. **Complete the program by replacing the lines `// *** COMPLETE ME ***` as appropriate.**
3. **Update `Makefile` so the first line is `obj-m += ex7_3.o`.**
4. **Build the kernel module using `make` on the terminal.**
5. **Install the kernel module using `sudo insmod ex7_3.ko`.**
6. **Uninstall the kernel module using `sudo rmmod ex7_3`**.
7. **Get the kernel log messages using `dmesg`**.

Your log should be similar to the following depending on when you removed it.

```shell
[80342.522526] Thread 1 in the critical section
[80342.522578] Threads started
[80342.527671] Thread 1 waiting 1 seconds
[80343.533708] Thread 1 exiting critical section
[80343.539072] Thread 1 in the critical section
...
[80354.797730] Thread 2 exiting critical section
[80354.803138] Thread 1 in the critical section
[80354.807100] Thread 1 waiting 1 seconds
[80355.821763] Thread 1 exiting critical section
[80355.826960] Thread 2 in the critical section
[80355.832124] Thread 2 waiting 2 seconds
[80357.869702] Thread 2 exiting critical section
[80357.874263] Exiting!
```

## Setting Kernel Thread CPU

To end, we will demonstrate that it is also possible to set which CPU/core a `kthread` runs on. This is done using the `kthread_bind` function:

```c
kthread_bind(thread, 0);
```

`kthread_bind` takes two parameters:

- A pointer to a `task_struct` representing the `kthread` we want to bind to a CPU.
- The index of the CPU we want to bind the `kthread` to.

However, we cannot simply set the CPU for a running `kthread`! We must do it before we run it. How do we do that? First, we create the thread, then set the CPU, and the finally start the thread. To create a thread we use:

```c
thread = kthread_create(thread_function, NULL, "thread");
```

This is the same as the call to `kthread_run` except it does not start the `kthread`. To start the `kthread` we use `wake_up_process`:

```c
wake_up_process(thread);
```

`wake_up_process` takes a pointer to the `task_struct` representing the `kthread`.

### Your Task

1. **Download the code [`ex7_4.c`](ex7_4.c){:target="_blank"}**.
2. **Complete the program by replacing the lines `// *** COMPLETE ME ***` as appropriate.**
3. **Update `Makefile` so the first line is `obj-m += ex7_4.o`.**
4. **Build the kernel module using `make` on the terminal.**
5. **Install the kernel module using `sudo insmod ex7_4.ko`.**
6. **Uninstall the kernel module using `sudo rmmod ex7_4`**.
7. **Get the kernel log messages using `dmesg`**.

Your log should be similar to the following depending on when you removed it.

```shell
[81074.767463] Thread started
[81074.767483] In thread function 1
[81075.789717] In thread function 2
[81076.817734] In thread function 3
[81077.837704] In thread function 4
[81078.865632] Thread exiting
[81078.867952] Exiting!
```

## Over to You -- Experimenting with Kernel Threads

Again, we've only touched the basics of using kernel threads and you should experiment by building larger kernel modules. [This link]([Driver Basics — The Linux Kernel documentation](https://www.kernel.org/doc/html/latest/driver-api/basics.html#)) will provide more information on the the various APIs available to you for kernel module development. We will explore some of these further next week.