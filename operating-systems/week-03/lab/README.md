# Operating Systems Lab 03 -- Working with Processes

<script src="https://cdn.jsdelivr.net/npm/code-line"></script>
<script>CodeLine.initOnPageLoad({toggleBtn: {show: false}, copyBtn: {show: false}})</script>
<script src="/module-content/script/links.js"></script>

<link rel="stylesheet" href="/module-content/css/block.css">

In this lab we will work with the Linux system interface to manipulate processes. The aim is to give you a sense of how a process is created, how we exit processes, and how we wait for other processes. We are still working with the Linux desktop in this lab.

## Getting a Process ID

The first key concept we will work with is how we identify processes. We need to identify processes so we can interact with them later.

Each process is given an ID, which is essentially a number. In Linux, there is a `pid_t` type that represents a **P**rocess **ID** (`pid`). To get the ID of the current process, we use the `getpid()` function from the `unistd.h` header file (`unistd.h` contains wrappers around the system call interface).

So, for example, to get the PID of the current process and store it in a variable `pid` we would use the following code:

```c
pid_t pid = getpid();
```

We can also get the PID of our parent process's ID we use `get-ppid()`, for example:

```c
pid_t parent = getppid();
```

### Exercise

1. **Download the code [`ex3_1.c`](ex3_1.c){:target="_blank"}**.
2. **Complete the program by replacing the lines `// *** COMPLETE ME ***` as appropriate.**
3. **Build the application using `gcc ex3_1.c -o ex3_1` on the terminal.**
4. **Run the application  using `./ex3_1` on the terminal.**

Your output should be something like follows (note the numbers will be different):

```shell
My pid=27181
Parent pid=259
```

## Creating a Process Using `fork`

We've seen how to get a process ID. Now let us create a new process. There are different methods of doing this based on what you are trying to do. `exec` allows you to run another program for example. We will create new processes from within our program.

`fork()` will create a new process in your program and start it running. `fork` will return the `pid_t` of the started process. So for example:

```c
pid_t pid = fork();
```

But what happens when you `fork` a new process? That process starts executing from that point in your program -- you effectively have two versions of your program running at that point. However, there is one difference -- the data created in the parent process is not copied to the child process. An easy way to see this is to examine the value of `pid` as follows:

```c
if (pid > 0)
{
  // This will be the parent - it knows the pid of the created child
}
else if (!pid) // i.e., pid == 0
{
  // This will be the child - it doesn't know pid as it didn't create the process
}
```

In the parent (creating) process, `pid` will have a value -- the process ID of the child process. In the child (created) process, `pid` will not have a value -- it will be zero.

### Exercise

1. **Download the code [`ex3_2.c`](ex3_2.c){:target="_blank"}**.
2. **Complete the program by replacing the lines `// *** COMPLETE ME ***` as appropriate.**
3. **Build the application using `gcc ex3_2.c -o ex3_2` on the terminal.**
4. **Run the application  using `./ex3_2` on the terminal.**

Your output will be something like the following:

```shell
I'm the child
I'm the parent of pid=27400
```

## Printing from Multiple Processes

Let us actually do something with our forked process. Let us print out some values and see what happens.

### Exercise

1. **Download the code [`ex3_3.c`](ex3_3.c){:target="_blank"}**.
2. **Complete the program by replacing the lines `// *** COMPLETE ME ***` as appropriate.**
3. **Build the application using `gcc ex3_3.c -o ex3_3` on the terminal.**
4. **Run the application  using `./ex3_3` on the terminal.**

The output should be as follows:

```shell
Parent 0
Parent 1
Parent 2
Parent 3
Parent 4
Parent 5
Parent 6
Parent 7
Parent 8
Parent 9
Parent 10
=====>Child 0
=====>Child 1
=====>Child 2
=====>Child 3
=====>Child 4
=====>Child 5
=====>Child 6
=====>Child 7
=====>Child 8
=====>Child 9
=====>Child 10
```

## Process Exit

We now know how to create a process. Let us look at exiting a process. You might have already done this in other modules. We use the `exit` function:

```c
exit(STATUS);
```

`STATUS` is a value that tells the operating system how the program exited. The two common ones are:

- `EXIT_SUCCESS` -- the process exited successfully.
- `EXIT_FAILURE` -- the process exited in a failed state.

So, for example, to exit a process in a successful state we use:

```c
exit(EXIT_SUCCESS);
```

We can also run specific code when a process exits using the `atexit` function. It takes the following form:

```c
atexit(function);
```

`function` is just the name of the function you want to run on exit. For example, to run the `parent_exit` function we use:

```c
atexit(parent_exit);
```

**NOTE** -- the function must have the type `void name()`. That is, the function returns nothing and it takes no parameters.

### Exercise

1. **Download the code [`ex3_4.c`](ex3_4.c){:target="_blank"}**.
2. **Complete the program by replacing the lines `// *** COMPLETE ME ***` as appropriate.**
3. **Build the application using `gcc ex3_4.c -o ex3_4` on the terminal.**
4. **Run the application  using `./ex3_4` on the terminal.**

The output for the program should be something as follows:

```shell
Exiting parent
Exiting child
```

## Waiting for Processes

When we have child processes, we can wait for one of them to finish using the `wait` function. This returns the process ID of the child process that finished, and will also fill in a `status` value telling you the status of the exiting process. For example, we can use the following:

```c
pid_t pid = wait(&status);
```

### Exercise

1. **Download the code [`ex3_5.c`](ex3_5.c){:target="_blank"}**.
2. **Complete the program by replacing the lines `// *** COMPLETE ME ***` as appropriate.**
3. **Build the application using `gcc ex3_5.c -o ex3_5` on the terminal.**
4. **Run the application  using `./ex3_5` on the terminal.**

Your output should be **exactly** as follows:

```shell
Parent running....
Parent waiting....
Child running....
Child exiting....
Child exited....
Parent exiting....
```

## Waiting for Specific Processes

We can also wait for a specific process to finish using the `waitpid` function. It requires the `pid` of the process we want to wait to finish and some option flags which we will ignore by setting to `0`. Below is an example:

```c
waitpid(pid, &status, 0);
```

### Exercise

1. **Download the code [`ex3_6.c`](ex3_6.c){:target="_blank"}**.
2. **Complete the program by replacing the lines `// *** COMPLETE ME ***` as appropriate.**
3. **Build the application using `gcc ex3_6.c -o ex3_6` on the terminal.**
4. **Run the application  using `./ex3_6` on the terminal.**

Your output should be as follows (the order may be slightly different in places):

```shell
Parent running....
Waiting for child B....
Child A running....
Child A exiting....
Child B running....
Child B exiting....
Child B exited....
Waiting for child A....
Child A exited....
Parent exiting....
Child A running....
Child A exiting....
```

## Over to You -- Experimenting with Processes

You are now in a position to write programs that use multiple processes. Experiment with this feature and see how programs behave. And remember, you also have the `exec` and related functions to try.
