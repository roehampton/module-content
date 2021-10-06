# Operating Systems Lab 03 -- Working with Processes



## Getting a Process ID



```c
pid_t pid = getpid();
```



```c
pid_t parent = getppid();
```



### Exercise





## Creating a Process Using `fork`



```c
pid_t pid = fork();
```



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



### Exercise



## Printing from Multiple Processes



### Exercise



## Process Exit



```c
exit(STATUS);
```



```c
exit(EXIT_SUCCESS);
```



```c
atexit(function);
```



```c
atexit(parent_exit);
```

### Exercise



## Waiting for Processes



```c
pid_t pid = wait(&status);
```



### Exercise

## Waiting for Specific Processes



```c
waitpid(pid, &status, 0);
```

### Exercise



## Further Work

