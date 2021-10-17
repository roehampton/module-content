# Operating Systems Lab 04 -- Threads

<script src="https://cdn.jsdelivr.net/npm/code-line"></script>
<script>CodeLine.initOnPageLoad({toggleBtn: {show: false}, copyBtn: {show: false}})</script>
<script src="/module-content/script/links.js"></script>

<link rel="stylesheet" href="/module-content/css/block.css">

In this lab, we will somewhat repeat the work of the last lab but this time we will work with threads.

## What are Threads?

Remember, threads are runnable parts of a process -- a part of your program that can runs independently. A thread looks much like a process, but can share resources that below to the process. We also have additional ways of controlling threads, such as using mutex to control when threads can access certain parts of code.

### POSIX Threads

In this lab we will use the **POSIX Threads** (`pthread`) library. POSIX threads are the standard threading library used in Linux. However, remember that thread libraries used by programmers exist in **user space**. Therefore, the POSIX thread library is not provided with the operating system. A POSIX thread maps to a Linux task -- or a process. This may sound confusing -- and it is a little -- but Linux uses a grouping concept to manage the idea. That is, POSIX threads are grouped within the same Process ID. Linux will still manage the scheduling, but resources are now shared between threads.

## Creating POSIX Threads

A POSIX thread has the type `pthread_t` and we declare one as follows:

```c
pthread_t thread;
```

`pthread_t` is actually just a number -- it represents the thread ID. We will use this in the next example. But as `pthread_t` is just a number we haven't really created a thread yet. To do so, we use the `pthread_create` function:

```c
pthread_create(&thread, NULL, function, args);
```

`pthread_create` takes four parameters:

- A pointer to a `pthread_t` -- note the use of `&` to denote we are getting the pointer to the value.
- A pointer to some thread attributes -- we will use this in the next lab so for now we set to `NULL`.
- The function we want the thread to run -- this must have the signature `void* name(void *args)`.
- A pointer to some arguments -- we will use this later, so for now we set it to `NULL`.

As an example, if we wanted to run the function `do_work` in a thread, we would write the following lines of code:

```c
void* do_work()
{
  // Code to run in the thread
}

int main(int argc, char **argv)
{
  pthread_t thread;
  pthread_create(&thread, NULL, do_work, NULL);
  // ...
}
```

### Exiting a Thread

Once a thread has finished running, it is good practice to correctly exit the thread. This ensures that any used resources are freed up and we can get any exit data from the thread. To exit a thread we use the `pthread_exit` function:

```c
pthread_exit(NULL);
```

It takes one parameter which is a pointer to any data we want the creating process to receive. We won't be using this so we will set the parameter to `NULL`.

### Joining a Thread

Once we have created a thread, we **must** wait for it to complete before the creating process exits. We do this using the `pthread_join` function:

```c
void *status;
pthread_join(thread, &status);
```

`pthread_join` takes two parameters:

- The `pthread_t` that we want to join (wait to complete).
- A pointer to data returned by the thread on exit.

This final parameter matches up to the data from `pthread_exit`. We won'y be using this data so we ignore it.

### Exercise

1. **Download the code [`ex4_1.c`](ex4_1.c){:target="_blank"}**.
2. **Complete the program by replacing the lines `// *** COMPLETE ME ***` as appropriate.**
3. **Build the application using `gcc ex4_1.c -o ex4_1 -pthread` on the terminal.**
4. **Run the application  using `./ex4_1` on the terminal.**

The output you should get is as follows:

```shell
I'm the main program!
I'm a thread!
```

## Thread ID

As stated, `pthread_t` is actually a number -- an `unsigned long`. This is the thread ID for a POSIX thread. We can obviously print this easily enough. But how do we get the current thread's ID?

### Getting the Current Thread

The `pthread` library provides a function to get the currently executing thread -- `pthread_self()`. It is used as follows:

```c
pthread_t thread = pthread_self();
```

To print a `pthread_t` we use `printf` as follows:

```c
printf("%lu", thread);
```

### Exercise

1. **Download the code [`ex4_2.c`](ex4_2.c){:target="_blank"}**.
2. **Complete the program by replacing the lines `// *** COMPLETE ME ***` as appropriate.**
3. **Build the application using `gcc ex4_2.c -o ex4_2 -pthread` on the terminal.**
4. **Run the application  using `./ex4_2` on the terminal.**

Your output will be similar to the following (**note** -- the numbers will be different).

```shell
My ID is 139690740815616
My ID is 139690732422912
My ID is 139690715637504
My ID is 139690707244800
......
I'm the main program!
......
My ID is 139690690459392
My ID is 139690682066688
My ID is 139690665281280
My ID is 139690673673984
```

## Sleeping

We can put a thread to sleep using the `sleep()` function:

```c
sleep(seconds);
```

`sleep` takes one parameter -- the amount of time to sleep in seconds. We will use this to show two threads interleaving as they run. To do this, we will need to pass the time we want to sleep to our threads. *So how do we pass arguments to our thread?*

### Passing Arguments to a Thread

Remember the signature for a thread function is as follows:

```c
void* name(void *args)
```

`args` is a way we can provide arguments to our function. All we have to do is **cast** the arguments to the correct type. For example, if we know `args` is an `int` then we do the following:

```c
void do_work(void *args)
{
  int num = (int)args;
  // ...
}
```

How do we pass this value to the thread? We do this during `pthread_create`. Remember it takes the following form:

```c
pthread_create(&thread, NULL, function, args);
```

`args` has the type `void*` so we must cast our value accordingly as well. For example, to pass the value `2` to our `do_work` function above we would do the following:

```c
void do_work(void *args)
{
  int num = (int)args;
  // ...
}

int main(int argc, char **argv)
{
  pthread_t thread;
  pthread_create(&thread, NULL, do_work, (void*)2);
  // ...
}
```

**NOTE** -- the data we send to the thread must be cartable to a pointer. Remember that a pointer is just an address in memory -- a number. An `int` is therefore a viable type. If you want to provide more complex data types, you'd have to provide the address (using the `&` operator) to the data.

### Exercise

1. **Download the code [`ex4_3.c`](ex4_3.c){:target="_blank"}**.
2. **Complete the program by replacing the lines `// *** COMPLETE ME ***` as appropriate.**
3. **Build the application using `gcc ex4_3.c -o ex4_3 -pthread` on the terminal.**
4. **Run the application  using `./ex4_3` on the terminal.**

Your output will be similar to the following (**note** -- the numbers will be different).

```shell
...
140032845539072 awake!
140032845539072 going to sleep
140032837146368 awake!
140032837146368 going to sleep
140032837146368 awake!
140032837146368 going to sleep
140032837146368 awake!
140032837146368 going to sleep
```

## Creating a Mutual Exclusion Lock (Mutex)

Let us end this lab by using a mutual exclusion lock (**mutex**) to control access to a particular piece of code. This is the most basic method of protecting against **race conditions**, but will serve us well enough as an example.

### Creating a Mutex

The POSIX thread library provides various mechanisms to protect against race conditions. The `pthread_mutex_t` represents a mutex. It is created as follows:

```c
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
```

**NOTE** -- our threads need shared access to this object. There are various methods to do this. We will be lazy and just declare the `pthread_mutex_t` as a global object. *This is very bad practice!*

### Locking a Mutex

To lock a mutex, we use the `pthread_mutex_lock` function, providing a pointer to the mutex in question:

```c
pthread_mutex_lock(&mutex);
```

### Unlocking a Mutex

Unlocking a mutex requires the `pthread_mutex_unlock` function, which also requires a pointer to the mutex in question:

```c
pthread_mutex_unlock(&mutex);
```

### Destroying a Mutex

Finally, to destroy the mutex we use the `pthread_mutex_destroy` method, again with a pointer to the mutex:

```
pthread_mutex_destroy(&mutex);
```

### Exercise

In this exercise we will use a mutex to control access by two threads to a `critical_section` function. Each thread will wait randomly for up to four-seconds when it requires the lock. This is to simulate waiting for a resource to become available. **Pay attention to the output to understand the interleaving.**

1. **Download the code [`ex4_4.c`](ex4_4.c){:target="_blank"}**.
2. **Complete the program by replacing the lines `// *** COMPLETE ME ***` as appropriate.**
3. **Build the application using `gcc ex4_4.c -o ex4_4 -pthread` on the terminal.**
4. **Run the application  using `./ex4_4` on the terminal.**

Your output will be similar to the following (**note** -- the numbers will be different).

```shell
140489895528192 entering mutex
140489895528192 in the mutex
140489895528192 waiting 3 seconds
140489903920896 entering mutex
...
140489895528192 waiting 2 seconds
140489895528192 exiting mutex
140489903920896 in the mutex
140489903920896 waiting 1 seconds
140489903920896 exiting mutex
```

## Over to You

Now it is time to explore working with threads. Things you should try:

1. **Create 10 threads and have each one print out its process ID as we did in the last lab. What do you notice?**
2. **Explore the two other `pthread` locking mechanisms:**
   - `pthread_cond_t` -- a condition variable.
   - `pthread_rwlock_t` -- a reader-writer lock.