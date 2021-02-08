# Software Development 2 Lab 05 -- Programming Style and Documentation

We have now covered how data is represented on the machine when working with C.  Let us now look a bit more into how code is generated and how we break our code up into separate files.  We are going to move onto developing larger and larger applications from now on as we will be able split our code up accordingly.  First, we need to look into what is known as the *pre-processor*.

## The Pre-Processor

The pre-processor is a part of the code generation step that occurs when working with C based languages.  The pre-processor runs before the main compilation as it changes the file that needs to be compiled.  It can do this in a number of ways, some of which are compiler dependant.  The pre-processor commands we will look at are fairly standard, so will work on any compiler (more or less).

We can now re-imagine our compilation step as follows:

*pre-processor* **&rarr;** *compiler* **&rarr;** *linker*

This means we can consider the code generation going through the following stages:

*Original C* **&rarr;** *Pre-processed C* **&rarr;** *Assembly* **&rarr;** *Object Code* **&rarr;** *Executable*

Pre-processor lines are denoted with the hash sign (`#`).  You should notice that we have already been using pre-processor commands - our `#include` statements are such commands.  We will look at what these do shortly.  First, we will look at what happens when we define values and perform conditional compilation.

### Some Pre-Processor Commands

Before looking at our first application using pre-processor commands let us look into some pre-processor commands.  These statements allow us to control some of the compilation of our program in particular ways.  It is in fact very common to see pre-processor commands in C and C++ code.

The first pre-processor command we will look at is `#define`.  This command allows us to define values which we can then use in our code.  The pre-processor will replace any use of the defined name with the given value. 

```c
#define TEST
#define NUMBER 1234
#define NAME "Kevin"
```

On line 1 we define `TEST`.  There is no value associated with this definition.  If we were to use it in code it would be replaced with nothing.  Line 2 defines `NUMBER` and assigns it the value 1234.  Any time the pre-processor encounters `NUMBER` it will replace it with 1234.  Finally, line 3 defines `NAME` and assigns it the value `"Kevin"`.

Let us look at how this affects the code we write. Here is an example application using `#define` before the pre-processor is run across it.

```c
// Pre-processor will replace NAME with "Kevin"
char *student_name = NAME;
// Pre-processor will replace NUMBER with 1234
unsigned int student_matric = NUMBER;
```

During compilation, the pre-processor is the first stage to run.  It looks at the `#define` statements and uses them to modify the code to be compiled.  This generates the actual code that the compiler compiles.

```c
// Actual line compiled
char *student_name = "Kevin";
// Actual line compiled
unsigned int student_matric = 1234;
```

It is just a straight swap.  There is no checking of code to see if it is correct by the pre-processor.  It simply modifies any place it finds a defined value and replaces it accordingly.  The compiler is where the check is made to ensure that the code is correct.

Another use of defined values is in performing conditional checks and compiling different code accordingly.  This is a very powerful feature of the pre-processor, allowing you to write code that, for example, can target different platforms.

```c
#ifdef TEST
printf("Test defined\n");
#else
printf("Test not defined\n");
#endif
```

In this example different code is produced by the pre-processor based on whether or not `TEST` is defined.  This means different code is compiled based on the defined values.  The following table illustrates the different code compiled based on whether or not `TEST` is defined.

| **Defined Value**  | **Code Compiled**               |
| ------------------ | ------------------------------- |
| `TEST` defined     | `printf("Test defined\n");`     |
| `TEST` not defined | `printf("Test not defined\n");` |

There are a number of different pre-processor commands.  We will use a couple of these in the module.  The following table describes the most common pre-processor statements.

| **Pre-processor Command** | **Description**                                              |
| ------------------------- | ------------------------------------------------------------ |
| `#include`                | Includes (adds) code from a header file to the code file as part of the code to be compiled. |
| `#define`                 | Defines a values which is then replaced in the code file when found, or used for conditional compilation. |
| `#undef`                  | Undefines a value. Removes a previous `#define`.             |
| `#if`                     | Used to check a value of a defined pre-processor value.      |
| `#ifdef`                  | Used to check if a value has been defined.                   |
| `#ifndef`                 | Used to check if a value has not been defined.               |
| `#else`                   | Used with `#if`, `#ifdef` and `#ifndef`.                     |
| `#elif`                   | An *else-if* statement.                                      |
| `#endif`                  | Ends a pre-processor if block.                               |
| `#pragma`                 | Tells the compiler that the rest of the line contains instructions.  These are generally compiler specific, but we will look at one that is fairly cross compiler |

## Creating a Header File

The real reason we have been looking at the pre-processor is so that we can start understanding what a header file is.  You've been using header files since our very first application (for example `stdio.h`), but our description has been a little vague.  A header file is essentially a collection of previously written code (normally just declarations -- more on this later) that we want to include in our own code.  It can contain any standard C statement or declaration -- it essentially allows us to separate our code into different.

Let us start by declaring a new header file.  **Create a new file called `hello.h`:**

```c
#pragma once
// This file needs to know what printf is
#include <stdio.h>

void hello_world()
{
	printf("Hello world!\n");
} 
```

> **What is `#pragma once`?**
>
> We already mention the `#pragma` command is an instruction to the compiler and/or linker.  The `#pragma once` statement is used to tell the compiler to only include the header file once.  This is actually quite important.  If a header is included more than once, then the functions and other declarations in the header are also added twice.  This leads to a compilation error.
>
> `#pragma once` is a technique to ensure a header is only included once.  Another technique is to use *header guards*.  A header guard used conditional compilation to ensure that the header is only included once.  An example is shown below:
>
> ```c
> #ifndef HELLO_HEADER_GUARD
> #define HELLO_HEADER_GUARD
> 
> // Code defined here...
> 
> #endif
> ```
>
> When the header is first included, the `#define` is encountered, meaning the `#ifndef` can only be true once.  This technique does require more code (and thinking of different header guard defines for each header file), but is technically more platform independent and portable.  This is because `#pragma once` is not an official part of the C standard.  However, pretty much every compiler supports it.

Now that we have created our header file we can create our main application file.  **Enter the code below in a new C (a `.c`) file called `hello.c`.**

```c
// Include the hello header.  Note the use of quotes this time
#include "hello.h"

int main(int argc, char **argv)
{
	hello_world();
  return 0;
}
```

As you can see, our main application just calls the `hello\_world` function defined in our header file.  Essentially our application is the same as our original *Hello World* application.

Compile the program as normal.  The header file is automatically included (as it was when we included other header files).  The pre-processor generates a single code file for the compiler which takes the following form:

```c
#include <stdio.h>

void hello_world()
{
	printf("Hello world!\n");
} 

int main(int argc, char **argv)
{
	hello_world();
  return 0;
}
```

> **What about `stdio.h`?**
>
> The code listing above isn't truly what the pre-processor generates.  The `stdio.h` file is also added at the top.  However in the Microsoft C library this file is over 700 lines of code long.  Hence we haven't included it here.

> **Declaration Order**
>
> Declaration order is an important concept in most languages, but especially in C and C++.  In languages such as Python, Java and C\#, methods and functions and be declared in separate files and the compiler will work it all out for you.  In C and C++ you have to ensure that something is declared before you use it.  This means that sometimes you have to specify that a function or `struct` exists before you explicitly define what it is.  In this module we won't encounter this requirement specifically, but you should be aware of this requirement if you carry on through C and C++ programming.

If you run this program you will get the same output at the standard *Hello World* application.

\subsection{Example - Student Details}

Let us now build an example that uses separate code files.  For this we will revisit our student example.  First, let us define our \texttt{student.h} header file:

\begin{lstlisting}[caption=\texttt{student.h} Header File]
#pragma once

// A structure representing a student
struct student
{
    unsigned int matric;
    char *name;
    char *address;
};

// Declaration of print student method - not implementation
void print_student(struct student s);
\end{lstlisting}

Note the use of \texttt{\#pragma once} again.  Otherwise we have two declarations.  The first is a \texttt{student struct}.  This is the same \texttt{struct} that we defined before.  The second is the \texttt{print\_student} function.  Here we are just declaring the function.  We have provided no implementation detail.  This is in the \texttt{student.c} code file:

\begin{lstlisting}[caption=\texttt{student.c} Code File]
#include "student.h"
#include <stdio.h>

void print_student(struct student s)
{
	printf("Matric: %d\n", s.matric);
	printf("Name: %s\n", s.name);
	printf("Address: %s\n", s.address);
}
\end{lstlisting}

Our implementation file just contains the details of how we implement \texttt{print\_student}.  It includes the \texttt{student.h} and \texttt{stdio.h} header files.  Otherwise we are just implementing the same code as before.

Finally our main application file is as follows:

\begin{lstlisting}[caption=Main Student Application]
#include "student.h"

int main(int argc, char **argv)
{
	struct student s;
	s.matric = 123456;
	s.name = "Kevin Chalmers";
	s.address = "Edinburgh Napier University";
	print_student(s);
	
	return 0;
}
\end{lstlisting}

This is just the same \texttt{main} as we developed before.  Notice that we have only included the \texttt{student.h} header file.

To understand what is happening now when we build the application examine Figure~\ref{fig:student-file-structure}.  At the top of the figure is our \texttt{student.h} file acting as a bridge between our \texttt{main.c} and \texttt{student.c} files.  Underneath this is the how the two generated \texttt{obj} files are linked together to form the main application.

\begin{figure}[htb]
\centering
\includegraphics{student-file-structure}
\caption{Structure of Student Application - both File Inclusion and Object Files}
\label{fig:student-file-structure}
\end{figure}

\subsection{Exercises}

\begin{enumerate}
\item Compile and build the new version of the student application.  You know how to do multiple file compilation, so you should be able to undertake this.
\item Determine what the two code files would look like after the pre-processor pass. This gives you an idea of how the implementation details are separate with the header file acting as a bridge. 
\item Make files?  Yes we are still going on about these.
\end{enumerate}

\section{A Simple Array Library}

OK, now let us develop a nice little reusable library.  Our library will allow us to work with an array of data.  It will provide the following features:
\begin{enumerate}
\item searching an array for a value
\item sorting the array
\item generating random data into the array
\end{enumerate}

We will split these three different functions into three separate code files.  Let us look at the these in turn.

The code for the header is below.

You now know how to create and use a library.  Let us reuse that library as we explore working with file input-output in C.

\section{Reading Files}

This may be a new concept to some of you - how we go about reading and writing files.  The principles are actually similar to working with reading and writing from the command line.  We are just going to perform the actions with a file.

File I/O is another fundamental part of computing.  It forms two thirds of a high level view of an application:
\[
\text{input} \Rightarrow \text{process} \Rightarrow \text{output}
\]

We will look at both input and output over the next two sections.  Let us first look at how we open a file.

\subsection{Opening a File}

To open a file in C we use the \texttt{fopen} function.  This will return a \texttt{FILE*} (pointer to a FILE).  The call requires a filename and a mode.  The filename has to be a correct filename in the system relative to the place where the executable is run (for our purposes the same folder).  \texttt{fopen} is illustrated below.

\begin{lstlisting}[caption=Opening a File]
FILE *file = fopen("filename", "mode");
\end{lstlisting}

The \texttt{mode} value is a string telling C how to open the file.  There are a few different methods of opening a file.  Table~\ref{tab:file-mode} describes the different methods.

\begin{table}[htb]
\centering
\begin{tabularx}{\textwidth}{|l|X|}
\hline
\textbf{Mode} & \textbf{Description} \\
\hline
r & opens the file for reading \\
\hline
w & opens the file for writing.  Existing files of the name have their contents discarded \\
\hline
a & opens the file for appending (writing at the end).  Will not discard existing file contents.  File seeking operations are ignored. \\
\hline
r+ & opens a file for reading and updating \\
\hline
w+ & opens a file for reading and updating.  Discards and existing contents in the file \\
\hline
a+ & opens a file for reading and updating at the end.  Will not discard contents.  File seeking operations are ignored. \\
\hline
b & opens the file as binary rather than text \\
\hline
\end{tabularx}
\caption{File Opening Modes in C}
\label{tab:file-mode}
\end{table}

\subsection{Opening a File for Binary Reading}

We are going to read a file in binary.  These means we have to combine the read mode (\texttt{r}) and the binary mode (\texttt{b}).  We do this as follows:

\begin{lstlisting}[caption=Opening a File for Binary Reading]
FILE *file = fopen("filename", "rb");
\end{lstlisting}

\subsection{Reading a Binary File}

Let us now write a test application to open a binary file, read it in, and then sort it.  To do this we will also write a function that will read in a file and return the amount of data read.  The form of the data file will be such that the first 4 bytes will tell us the number of values stored in the data file.  This means that we don't know how many values are stored, so we will have to introduce some strategies for allocating enough space to store our values.  The code for our test application is below.  We will explain the new parts presently.

\begin{lstlisting}[caption=Reading a Binary File]
#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

// Reads in a block of data as an int array
int readfile(int **data)
{
    // Open file for reading
    FILE *file;
    file = fopen("numbers.dat", "rb");
    // First value is number of integers
    int size;
    fread(&size, sizeof(int), 1, file);
    // Allocate memory for that number of values
    *data = (int*)malloc(sizeof(int) * size);
    // Read in rest of data
    fread(*data, sizeof(int), size, file);
    // Return size
    return size;
}

int main(int argc, char **argv)
{
    // Declare data
    int *data;
    // Read in file
    int size = readfile(&data);
    // Sort
    sort(size, data);
    // Print first 20 results
    for (int i = 0; i < 20; ++i)
        printf("%d\n", data[i]);

    // Free the allocated memory - otherwise a memory leak! (very bad)
    free(data);
    
    return 0;
}
\end{lstlisting}

\begin{framed}
\textbf{Allocating Memory}

We used two new functions in this example - \texttt{malloc} and \texttt{free}.  \texttt{malloc} (Memory ALLOCation) creates a block of memory for us to use.  This is required as we don't know the number of values we require to store the file contents.  We therefore use \texttt{malloc} to create the memory block.  \texttt{malloc} requires just one value - the amount of data (in bytes) we need to allocate.  Notice that we used the size of an \texttt{int} times the number of values we are going to read.

\texttt{malloc} returns a pointer to the memory location it has allocated memory at.  This pointer is of type \texttt{void} (so we have a \texttt{void*}).  This means that the type of memory is undefined (it is just a block).  We cast it to a pointer to \texttt{int} (a \texttt{int*}) to set the \texttt{data} value.

The other function we have used is \texttt{free}.  This releases any allocated memory once we have finished with it.  \emph{This is very important!}.  Let me repeat that - \emph{THIS IS VERY IMPORTANT!}.  If you do not free your allocated memory it cannot be used, leading to memory leaks.  Over time, this could lead to your application running out of memory.  Ensuring you free your allocated memory is an important consideration in C and C++ (there is no garbage collector like in Java and C\#).  We will spend an entire unit exploring this concept.
\end{framed}

\begin{framed}
\textbf{Why \texttt{**data}?  What does that mean?}

Look at what the code is saying (remembering that \texttt{*} means \emph{pointer-to}).  We are effectively saying that we have a \emph{pointer-to} a \emph{pointer-to} \texttt{int}.  In other words, the \texttt{data} value points to a memory location that contains a memory location.

Why do we need this?  Well, the call to \texttt{malloc} will create a new memory location.  If we just used a memory location for \texttt{data} (a pointer-to \texttt{int}) we would overwrite the memory location in \texttt{data} within the function \texttt{readfile} but not in the \texttt{main} function.  We would affectively lose the memory location (and create a memory leak).

At the moment this will seem confusing, but we will spend time exploring this over a couple of units in the module.  At the moment, understand that we have passed data as a \emph{pointer-to a pointer-to} \texttt{int}.
\end{framed}

\begin{framed}
\texttt{fread} and \texttt{fclose}

How many boxes do we need after this code?  We have two other functions for working with files.  The first is \texttt{fread}.  This reads in data from a file.  It takes the following parameters:
\begin{enumerate}
\item the location to read the file into
\item the size of the data type being read in
\item the number of values of the data type to read in
\item the file to read in from
\end{enumerate}

Points 2 and 3 above provide us with the amount of data to read in (the size of the type times the number of values).

The second new function we used was \texttt{fclose}.  This closes the file.  \emph{You should always close your files after you have finished with them!}.  If you don't close the file you can cause system conflicts.  If you are writing to a file, you may lose the information sent to the file when the application exits.  The application \emph{will not} automatically push the contents to the hard drive, even on exit.  Therefore data can be lost.
\end{framed}

\subsection{Exercise}

You should be able to compile and link this file.  You will need the \texttt{array.lib} library we generated in the previous section.  The application will give a similar output to the last one.  However, we are now sorting \emph{a lot} of data, and the application will take time to complete.

\section{Writing Files}

Let us extend the previous version of the application now to also save the sorted data in a text file.  The following code will accomplish this for you.  You should hopefully understand what is meant by a text file by now.

\begin{lstlisting}[caption=Reading and Sorting a Binary File and Outputting as Text]
#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

// Reads in a block of data as an int array
int readfile(int **data)
{
    // Open file for reading
    FILE *file;
    file = fopen("numbers.dat", "rb");
    // First value is number of integers
    int size;
    fread(&size, sizeof(int), 1, file);
    // Allocate memory for that number of values
    *data = (int*)malloc(sizeof(int) * size);
    // Read in rest of data
    fread(*data, sizeof(int), size, file);
    // Close file
    fclose(file);
    // Return size
    return size;
}

// Writes strings to the file
void writefile(int size, int *data)
{
    // Create file
    FILE *file;
    file = fopen("sorted.txt", "w");
    // Loop through each value, writing to the file
    for (int i = 0; i < size; ++i)
        fprintf(file, "%d\n", data[i]);
    // Close the file
    fclose(file);
}

int main(int argc, char **argv)
{
    // Read in data
    int *data;
    int size = readfile(&data);
    // Sort
    sort(size, data);
    // Write the data
    writefile(size, data);
    // Free the allocated memory - otherwise a memory leak! (very bad)
    free(data);

    return 0;
}
\end{lstlisting}

\begin{framed}
\texttt{fprintf}

We used \texttt{fprintf} as a command here.  This works exactly as \texttt{printf} except that is requires a \texttt{FILE*} to print to.  Here we have used the opened file, but we could also use \texttt{stdout} (the command line).
\end{framed}

\section{Exercises}

We've covered a lot of ideas in this unit and you should go through it again to ensure you are comfortable of, and understand the, concepts discussed.  File reading we will return to in C++ (where our life gets a little easier).  So there are only a couple of exercises here.

\begin{enumerate}
\item Write an application that prompts the user for a name and writes it to a file as text.  Each name should be on a new line.  The application should continue asking for names until END is entered.
\item Write an application that reads in your sorted text file and prints out the values.  You should use \texttt{fgets} to read in the lines from the text file.
\end{enumerate}

## Command Line Parameters