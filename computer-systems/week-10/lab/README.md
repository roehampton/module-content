# Computer Systems Lab 10 -- Introduction to OpenMP

<script>
MathJax = {
  tex: {
    inlineMath: [['$', '$'], ['\\(', '\\)']]
  },
  svg: {
    fontCache: 'global'
  }
};
</script>
<script type="text/javascript" id="MathJax-script" async
  src="https://cdn.jsdelivr.net/npm/mathjax@3/es5/tex-svg.js">
</script>

The aim of this lesson is to explore thread programming using OpenMP.

OpenMP is an Application Programming Interface (API) for C. It was jointly defined by a group of major computer hardware and software vendors. It is a standard shared memory programming interface.

OpenMP uses some compiler directives, runtime library routines, and environment variables to allow simple parallelisation of C programs. It includes parallel loops, parallel sections and parallel regions. It also consists of synchronisation primitives such as critical regions and barriers.

OpenMP is implemented as an extension to compilers, so your existing C compiler will likely support it. Little has to be done to a C program to turn it into a parallel version. It is simple to use by supporting incremental parallelism.

OpenMP supports standardisation in terms of shared memory architectures and platforms. It supports significant parallelism implementation with 3 or 4 directives. It promotes the capability to implement both fine-grain and coarse-grain parallelism. Because it works with standard C code, it provides scalable and portable model for memory sharing in parallel applications.

We will use the Linux/GNU C compiler `gcc`, although this code will also work on MacOS and Windows via an appropriate C compiler.

## First Program

Type the following program and save as `sample1.c`.

```c
#include <stdio.h>
#include <omp.h> // OpenMP header file

// Main program
int main(int argc, char **argv)
{
  // Print the current thread number.
  printf("Hello from thread %d\n", omp_get_thread_num());
  return 0;
}
```

`amp_get_thread_num()` gets the ID of the current thread being executed.

We compile this program using the following command in Linux:

```shell
gcc -fopenmp sample1.c
```

On Linux, this will produce the file `a.out`. We can run this file by using:

```shell
./a.out
```

And the output should be as follows:

```shell
Hello from thread 0
```

## Second Program

At the moment, the program only has one thread of execution -- the main thread. Create a new program called `sample2.c` and use the following code:

```c
#include <stdio.h>
#include <omp.h> // OpenMP header file

// Main program
int main(int argc, char **argv)
{
  // Run following code section across all cores
  #pragma omp parallel
  {
    // Print the current thread number.
    printf("Hello from thread %d\n", omp_get_thread_num());
  }
  return 0;
}
```

Compiling and executing this version of the program produces something similar to the following depending on the number of cores your system has:

```shell
Hello from thread 0
Hello from thread 3
Hello from thread 2
Hello from thread 6
Hello from thread 5
Hello from thread 4
Hello from thread 7
Hello from thread 1
```

Notice that the prints are not in order. We are not controlling the order of execution here. As only one thread can print to the screen at the time, the output is based on which thread prints first.

### Third Program

As each thread has an ID, we can make different threads behave in different ways. Try the following program, `sample3.c`.

```c
#include <stdio.h>
#include <omp.h>

// Main program
int main(int argc, char **argv)
{
    // Run the following code section across all cores.
    #pragma omp parallel
    {
        // Get thread id
        int tid = omp_get_thread_num();
        // If thread 0 say main thread
        if (tid == 0)
        {
            printf("I am the main thread - 0\n");
        }
        // If even numbered thread, say so
        // Even number means tid % 2 = 0
        else if (tid % 2 == 0)
        {
            printf("I am thread %d - an even thread.\n", tid);
        }
        // Else its an odd numbered thread
        else
        {
            printf("I am thread %d - an odd thread.\n", tid);
        }
    }
    return 0;
}
```

Compiling and running this program provides the following output depending on your system:

```shell
I am the main thread - 0
I am thread 3 - an odd thread.
I am thread 7 - an odd thread.
I am thread 6 - an even thread.
I am thread 5 - an odd thread.
I am thread 1 - an odd thread.
I am thread 4 - an even thread.
I am thread 2 - an even thread.
```

## Fourth Program

So far, everything we have done is a toy example to illustrate that we can execute parallel code easily on our systems. Let us now examine a specific problem, run it sequentially, and then run it in parallel.

We are going to run a Monte Carlo simulation. This just means we are going to generate a lot of random numbers and use these to solve a particular problem. The problem we are going to solve with these random numbers is estimating the value of $\pi$. The following image illustrates how this works. 

![Monte Carlo π](pi_30k.gif)

For those of you who want to know how this works, the following section explains.

### Theory - Estimating $\pi$

Suppose that the radius of the circle is 1. If we pick a random point within the square which encloses the circle (sides of length 2), we can determine whether the point is in the circle by calculating the distance of the point from centre of the square. If this is 1 or less, the point is within the circle. If it is greater than 1, then it is in the square but not the circle. The ratio of total random points to ones in the circle allows us to approximate π. This is because:
$$
\begin{align}
\text{Area of circle} &= \pi r^2 \\
\text{Area of square} &= 4r^2 \\
\text{Ratio} &= \frac{\pi r^2}{4r^2} = \frac{\pi}{4}
\end{align}
$$
We can create an algorithm to approximate $\pi$ as:
$$
\begin{align}
\text{attempts} &= n\\
\text{in circle} &= m\\
\text{ratio} &= \frac{m}{n}\\
\frac{\pi}{4} &\approx \frac{m}{n} \\
\pi &\approx \frac{4m}{n}
\end{align}
$$
Generating random points therefore allows an approximation of π. Points range from `[(0.0, 0.0), (1.0, 1.0)]`, and calculating the distance from  `(0, 0)` determines if the point is in the circle.

### Sequential Monte Carlo $\pi$

Our program will work as follows:

1. Start timer.
2. Loop for attempts times.
   - Generate x and y coordinate.
   - Calculate distance from (0, 0) using Pythagorus' theorem.
   - If distance <= 1.0 increment in circle count.
3. Calculate pi as 4 times in circle divided by attempts.
4. Stop timer.
5. Print result.

The program is below. Save as `pi_seq.c`.

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <omp.h>

// Main program
int main(int argc, char **argv)
{
    // Seed the random number generator
    // Ensures each run will have different random numbers.
    // Use current time as the seed.
    srand((unsigned int)time(NULL));

    // Number of attempts must be power of 2.
    // 2^24 = 16777216
    int attempts = (int)pow(2, 24);

    // Used to measure time elapsed
    struct timespec start, end;
 
    // Get current time as start time.
    clock_gettime(CLOCK_REALTIME, &start);

    // Keep track of number of points in circle
    int in_circle = 0;
    // Iterate
    for (int i = 0; i < attempts; ++i)
    {
        // Generate random point
        // Note - C only produces random ints. We need to convert into a float between 0.0 and 1.0
        // value / maximum possible value does this.
        float x = (float)rand()/(float)(RAND_MAX);
        float y = (float)rand()/(float)(RAND_MAX);
        // Calculate distance of point from centre - use Pythagarous
        float distance = sqrt((x * x) + (y * y));
        // Check if in circle
        if (distance <= 1.0)
            in_circle += 1;
    }
    
    // Calculate pi
    float pi = (4.0 * in_circle) / (float)attempts;

    // Get current time as end time.
    clock_gettime(CLOCK_REALTIME, &end);

    // Calculate time elapsed in seconds
    // Time provided is in seconds (tv_sec) and nanoseconds (tv_nsec).
    // Convert nanosecond part into seconds
    float time_spent = (end.tv_sec - start.tv_sec) +
                       (end.tv_nsec - start.tv_nsec) / 1000000000.0;

    // Print result
    printf("Estimate of pi is %f in %f seconds\n", pi, time_spent);

    return 0;
}
```

The comments should help you understand the new C parts we have used. Fundamentally, we have just used random number generation and timers.

If you compiler and execute this program, you should receive an input similar to the following:

```shell
Estimate of pi is 3.140906 in 0.457599 seconds
```

## Fifth Program -- Converting to Parallel

To convert this program to a parallel one using OpenMP is actually quite easy. We will use a new OpenMP directive -- *a parallel for* -- to convert the `for` loop into one that is executed across all the cores. Call this file `pi_par.c`.

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <omp.h>

// Main program
int main(int argc, char **argv)
{
    // Seed the random number generator
    // Ensures each run will have different random numbers.
    // Use current time as the seed.
    srand((unsigned int)time(NULL));

    // Number of attempts must be power of 2.
    // 2^24 = 16777216
    int attempts = (int)pow(2, 24);

    // Number of threads to execute
    int threads = 8;

    // Used to measure time elapsed
    struct timespec start, end;
 
    // Get current time as start time.
    clock_gettime(CLOCK_REALTIME, &start);

    // Keep track of number of points in circle
    int in_circle = 0;
    // Iterate
    #pragma omp parallel for num_threads(threads) reduction(+:in_circle)
    for (int i = 0; i < attempts; ++i)
    {
        // Generate random point
        // Note - C only produces random ints. We need to convert into a float between 0.0 and 1.0
        // value / maximum possible value does this.
        float x = (float)rand()/(float)(RAND_MAX);
        float y = (float)rand()/(float)(RAND_MAX);
        // Calculate distance of point from centre - use Pythagarous
        float distance = sqrt((x * x) + (y * y));
        // Check if in circle
        if (distance <= 1.0)
            in_circle += 1;
    }
    
    // Calculate pi
    float pi = (4.0 * in_circle) / (float)attempts;

    // Get current time as end time.
    clock_gettime(CLOCK_REALTIME, &end);

    // Calculate time elapsed in seconds
    // Time provided is in seconds (tv_sec) and nanoseconds (tv_nsec).
    // Convert nanosecond part into seconds
    float time_spent = (end.tv_sec - start.tv_sec) +
                       (end.tv_nsec - start.tv_nsec) / 1000000000.0;

    // Print result
    printf("Estimate of pi is %f in %f seconds using %d threads\n", pi, time_spent, threads);

    return 0;
}
```

There are only two lines added, and one line changed. On line 20 we declare the number of threads we are going to use (in this instance 2). Then, on line 31 we tag that the `for` loop should be run in parallel using the following OpenMP directive:

```
#pragma omp parallel for num_threads(threads) reduction(+:in_circle)
```

The `omp parallel for` part indicates that we want to convert the `for` loop into a parallel for loop executed across the cores. `num_threads` tells OpenMP how many threads to create (in this case two). `reduction(+:in_circle)` tells OpenMP that all the threads will be adding to the `in_circle` variable so some protection must be added.

We have also updated our `printf` statement on line 59 to tell us the number of threads used.

Compiling and running this program will provide output similar to the following:

```shell
Estimate of pi is 3.141217 in 0.517353 seconds using 2 threads
```

**NOTE** - there is a very good chance that running this application with two threads will be slower than running it on one thread. This is because of the overhead in trying to coordinate safe changes to `in_circle`. If your computer supports it, trying four threads will provide you with a faster time.

## Exercise

With the Monte Carlo $\pi$ benchmark, gather results for different attempts values and threads used. For example:

| **Attempts** | **Sequential**   | **Two Threads**  | **Four Threads** | **Eight Threads** | **Sixteen Threads** |
| ------------ | ---------------- | ---------------- | ---------------- | ----------------- | ------------------- |
| 2^24         | 0.457599 seconds | 0.517353 seconds | 0.269999 seconds | 0.233344 seconds  | 0.230857 seconds    |
| 2^25         | ...              | ...              | ...              | ...               | ...                 |
| ...          |                  |                  |                  |                   |                     |
| 2^30         | ...              | ...              | ...              | ...               | ...                 |

Then calculate the speedups achieved. **REMEMBER** -- speedup is based on the number of physical processors you have on your computer. You need to find this number. Modern Intel processors and similar use systems called Hyper Threading which gives the impression you double the cores you have. For example, the results shown in this lab come from a four-core processor, but it reports it has eight virtual cores. The $p$ value in speedup would be four in this scenario.

Once you have these values, chart them using a bar chart in Excel or similar. **NOTE** - a line chart is not a suitable chart for this type of data. A Line chart indicates that there are values between the readings. You cannot, for example, have a time for 8.5 threads. A line chart gives this impression.