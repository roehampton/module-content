# Software Development 2 Lab 08 -- Memory Management: Using the Stack and Heap

\chapter{Memory Management - Using the Stack and Heap}

In this unit we are going to expand on our work with understanding pointers by beginning to work with memory.  When working with a low-level systems language such as C/C++, working with memory is an important consideration.  So far, our journey through C and C++ has been as follows:
\begin{enumerate}
\item Introduction to programming in C, learning how our code is compiled and linked.
\item Learning how our data is represented in the computer's memory.
\item Learning how our C code is converted into Assembly language (and therefore machine understandable instructions).
\item Learning how our code files are processed and joined together to build compilation units.
\item Learning how we can pass values into functions in C++ using references and pointers.
\end{enumerate}

In this unit we are going to investigate how we allocate memory, the difference between the stack and the heap, as well as looking a bit deeper into scope.  We will also look at the new C++ features called \emph{smart pointers}.  For those of you who are a little more adventurous we will also look at basic value casting in C++.

\section{Scope of Values}

We have already looked into scope in a basic manner.  In this part we will look at scope in a bit more detail.  In particular, we will build inner scopes in our functions to give you an idea of how scope works in a bit more detail.

\begin{framed}
\textbf{What is Scope?}

Scope is about which values are currently valid in a particular piece of code.  In general, you should understand scope from the basic idea of having a variable available only after you have declared it.  For example:

\begin{lstlisting}
x = x + 1; // Don't know what x is here
int x = 0; // x only declared now
\end{lstlisting}

As \texttt{x} is declared after we use it we will get a compiler error - \texttt{x} is undeclared (not in scope).

Scope becomes more complex when we work with functions and classes.  When we call a function, we pass any variables we want to the function's scope.  In the previous unit we looked at how this could mean passing by value or passing by reference.  If we don't pass in the variable, then the value is not in scope.

Scope actually works in C / C++ from the point of view of values declared within braces.  For example, consider the following:

\begin{lstlisting}
void func()
{
    // Main scope of the function
    {
        // Scope A - can see main scope
        {
            // Scope B - can see scope A and main scope
        }
        
        {
            // Scope C - can see scope A and main scope.  Scope B no longer valid
        }
    }
}
\end{lstlisting}

We can only see values in our outer scope - not our inner scope.  This means whenever you use a curly brace (such as in a \texttt{while} loop or \texttt{if} statement) you create a new inner scope.  Any values declared in these scopes are destroyed (removed from the stack) when the scope is exited.

In C and C++ we have the ability to create values that are in the \emph{global} scope.  This can be useful, but is often frowned upon.  Passing values around the application as parameters is considered best practice.

Scope can be a tricky concept for new programmers.  Spend your time understanding which values are valid at particular points of your application.  Our next two example applications explore scope in more detail.
\end{framed}

\subsection{Which \texttt{x} is in Scope?}

Our first application investigating scope will look at how we can declare new values in inner scope with the same variable name, but still retain the values in the outer scope.  In a way, you can consider the inner scopes as the scope of a function (without parameter passing).  Below is our example application.  Notice how we keep redeclaring \texttt{x} in each inner scope, then unwind to get back to the original value.

\begin{lstlisting}[caption=Multiple \texttt{x} Values in Different Scopes]
#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
    // Outermost declaration
    int x = 10;
    cout << "Outermost x = " << x << endl;
    {
        // Now in new scope
        int x = 20;
        cout << "\tInner x = " << x << endl;
        {
            // Now even further in scope
            int x = 30;
            cout << "\t\tInner inner x = " << x << endl;
            {
                // Let's stop here
                int x = 40;
                cout << "\t\t\tInnermost x = " << x << endl;
                // Now unwind scope
            }
            cout << "\t\tInner inner x = " << x << endl;
        }
        cout << "\tInner x = " << x << endl;
    }
    cout << "Outermost x = " << x << endl;

    return 0;
}
\end{lstlisting}

Each time we enter a new scope we redeclare our \texttt{x} variable.  \emph{We are not redefining the value stored in \texttt{x} - we are creating a new variable}.  This is an important concept to understand.  As these are new variables, we are not changing the value of the previous scope.  It still exists.  Therefore, this application will print out values of each scope, then return back to the first scope.  The output from this application is below:

\begin{lstlisting}[style=DOS, caption=Output from Scope Test Application]
Outermost x = 10
        Inner x = 20
                Inner inner x = 30
                        Innermost x = 40
                Inner inner x = 30
        Inner x = 20
Outermost x = 10
\end{lstlisting}

\subsection{Values out of Scope}

So what happens when a value is out of scope?  Well we end up in a situation where we have \emph{undeclared identifiers}.  This leads to a compiler error.  Effectively the value hasn't been declared from the point of view of the compiler and therefore cannot be used.  The following application illustrates this:

\begin{lstlisting}[caption=Trying to Access Out of Scope Values]
#include <iostream>

int main(int argc, char **argv)
{
    // Declare an int here
    int i = 10;
    {
        // Declare another int here - can access i
        int j = i * 2;
        {
            // Declare another int here - can access i and j
            int k = i + j;
        }
        // Compile error here - k not in scope
        j = j + k;
    }
    // Compile error here - j not in scope
    i = i + j;

    return 0;
}
\end{lstlisting}

We have two problems in this code.  On line 15 we are attempting to access variable \texttt{k}, but this was declared in a scope that we have now exited (it existed in lines 10 to 14).  Therefore the compiler will give an error.  A similar problem exists on line 18. \texttt{j} was only in scope lines 7 to 16.  At line 18 it no longer exists (it has been removed from the stack) and therefore our compiler again throws an error.  Compiling this application provides the output below:

\begin{lstlisting}[style=DOS, caption=Compiler Output from Out of Scope Variable Application]
D:\programming-fundamentals\code\unit-06>cl scope2.cpp
Microsoft (R) C/C++ Optimizing Compiler Version 18.00.30501 for x86
Copyright (C) Microsoft Corporation.  All rights reserved.

scope2.cpp
C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\INCLUDE\xlocale(337) : wa
rning C4530: C++ exception handler used, but unwind semantics are not enabled. S
pecify /EHsc
scope2.cpp(15) : error C2065: 'k' : undeclared identifier
scope2.cpp(18) : error C2065: 'j' : undeclared identifier
\end{lstlisting}

Those errors from the compiler are important to spot.  The fact that values are not in scope is given and the particular line the problem exists in provided.  Being able to spot problems with out-of-scope variables is another stumbling block for new programmers.

\subsection{Losing Values on the Stack}

So now we know the pitfalls of working with scope we can relate back to what we have been working to up until this point.  In the last unit we discussed passing values as values, references and pointers.  In this unit we are interested in memory management.  Our problem really comes into effect when we allocate a block of data on the stack and then try and return it.  Remember that when we return from a function we lose the stack created for the function.

The problem becomes apparent when working with arrays.  As we have seen in C and C++ we can declare an array on the stack in our code if we know the size of our array at compile time.

\texttt{int array[10];}

If we do this in a function the data declared on the stack is lost when we exit its scope.  Therefore, if we return a such an array, the pointer is no longer pointing to valid memory.  This will happen also if we try to return a pointer to a value declared in a function.  We are effectively pointing to a location on the stack that has been deemed no longer allocated.

We get around this by allocating memory outside the stack - in the global memory space or heap.  Before discussing the heap in any detail let us look at an example application that shows what happens when we return values from a function using a pointer.  We also illustrate what happens when we try to set values in a memory location we are not allowed to.

\begin{lstlisting}[caption=Trying to Access Out of Scope Variables on the Stack]
#include <iostream>

using namespace std;

int* create_array()
{
    // This memory is created on the stack
    int data[20];
    for (int i = 0; i < 20; ++i)
        data[i] = i;
    return data;
    // Stack emptied - memory gone
}

int* create_array_new()
{
    // Memory created on the heap
    int *data = new int[20];
    for (int i = 0; i < 20; ++i)
        data[i] = i;
    return data;
    // Memory on the heap still relevant
}

void create_array(int *data)
{
    for (int i = 0; i < 20; ++i)
        data[i] = i;
}

int main(int argc, char **argv)
{
    int *data = create_array();
    // Print out all elements
    cout << "Array 1" << endl;
    for (int i = 0; i < 20; ++i)
        cout << data[i] << endl;

    data = create_array_new();
    // Print out all elements
    cout << endl << "Array 2" << endl;
    for (int i = 0; i < 20; ++i)
        cout << data[i] << endl;
    // Free the memory
    delete[] data;
    // Set to nullptr
    data = nullptr;
    
    // Create array from pointer
    // This will cause a memory allocation error
    create_array(data);
    
    // Allocate memory
    data = new int[20];
    // Create array from pointer
    create_array(data);
    // Print out all elements
    cout << endl << "Array 3" << endl;
    for (int i = 0; i < 20; ++i)
        cout << data[i] << endl;
    // Free the memory
    delete[] data;
    // Set to nullptr
    data = nullptr;
    
    return 0;
}
\end{lstlisting}

If you try and run this application you will get a runtime error (the application will hang) because of the attempt to allocate to \texttt{nullptr} (which represents memory location 0).  We will come back to \texttt{nullptr} later.  If you fix the code and run the application you will get the following output for Array 1.

\begin{lstlisting}[style=DOS, caption=Array 1 from Function Return]
Array 1
16741608
16590431
16747288
16747376
10157064
16747376
10157056
16590789
10157064
10157076
16604322
16747376
-255
16747376
10157084
16587195
10157100
16591518
16747376
16747376
\end{lstlisting}

Notice that these are not the values you are expecting.  The array has been cleared and now we have random values in the memory.

\section{Allocating Data in Global Memory (the Heap)}

So we now know the limitation of working with the stack when trying to return values from functions.  Overcoming this involves us working with global memory.  Global memory (the heap) allows us allocate memory that is not freed until such time as we wish to free it.  This is advantageous for a number of reasons, but also leads us to some of the biggest problems for new \emph{and experienced} software developers.  There is a reason why Java hides this with a garbage collector.  However, understanding memory allocation can be very important to comprehend when your values are valid and when they are cleared up.

In a way, you can consider the stack as working memory - it is very ordered, is cleaned up when finished with, and is also quite limited (more on this later).  The heap is a large blob of memory that we can allocate to and keep values on for long term storage.  Figure~\ref{fig:stack-heap} tries to illustrate this idea.

\begin{figure}[htb]
\centering
\includegraphics[width=\textwidth]{stack-heap}
\caption{Stack and Heap}
\label{fig:stack-heap}
\end{figure}

The question now is how do we allocate memory on the heap?  Well we have already seen this in a few places through the previous few units.  Now let us look at this in more detail, starting with how we do this in C for raw blocks of memory.

\subsection{The \texttt{malloc} Function}

We have already seen the \texttt{malloc} function when we worked with file I/O.  \texttt{malloc} stands for Memory ALLOCation.  It is used to allocate a block of memory of a given size on the heap.  It takes the following form:

\vspace{12pt}

\texttt{void *\emph{variable} = malloc(\emph{size});}

\vspace{12pt}

Notice first that \texttt{malloc} returns a pointer to \texttt{void}.  This means that the type of memory isn't defined.  \texttt{malloc} simply returns a pointer to a block of memory.  This means that you have to cast it to the relevant type (e.g. \texttt{int*}).

The only parameter that \texttt{malloc} takes is the number of bytes that need to be allocated.  This is the \texttt{size} parameter.  Remember that this is the number of \emph{bytes} being allocated.  Typically we use \texttt{sizeof} and the number of values we want to determine the number of bytes that we need.  For example, to allocate 100 \texttt{int} values on the heap we would use:

\vspace{12pt}

\texttt{int *data = (int*)malloc(sizeof(int) * 100);}

\vspace{12pt}

This is all we need to know about allocating memory in C.  We will look into C++ allocation shortly.  However, first we need to look at how we deallocate memory.

\subsection{The \texttt{free} Function}

In C and C++ we are usually responsible for allocating memory and ensuring that it is cleaned up afterwards.  This involves us using the \texttt{free} function.

\vspace{12pt}

\texttt{free(\emph{value});}

\vspace{12pt}

\texttt{free} takes the pointer created by a call to \texttt{malloc}.  It doesn't need to know the size of the data as this is kept track of.  Essentially your calls should look something like this:

\begin{lstlisting}
int *data = (int*)malloc(sizeof(int) * 100);
// Do some work with data.  Once finished call free
free(data);
\end{lstlisting}

\begin{framed}
\textbf{Why do we need to \texttt{free}?}

One of the biggest disadvantages levelled at C and C++ is the fact that you have to be responsible for tracking memory that has been allocated on the heap.  Once you have finished with it, you call \texttt{free} to deallocate.  If you don't free used memory, then your application slowly increases its memory usage until it runs out.

A bigger problem occurs when lose a pointer to allocated memory by it going out of scope.  This is a \emph{memory leak}.  Without the pointer, you cannot free the memory.  Do this enough times, and the above problem occurs, but this time we have no way to rectify the issue.  This is one of the issues new C/C++ programmers commonly face as well.
\end{framed}

\subsection{Using \texttt{calloc} to Clear Memory While Allocating}

\texttt{malloc} is not the only method in C to allocate memory.  The other method is using \texttt{calloc}.  This function works by not only allocating memory but also zeroing the memory allocated (all locations have 0 stored).  This takes a bit longer than \texttt{malloc} but does ensure no previous values are stored in memory.

The call to \texttt{calloc} is a little different than \texttt{malloc}:

\vspace{12pt}
\texttt{void *data = calloc(\emph{number of values}, \emph{size of values});}
\vspace{12pt}

Notice that the \texttt{size} parameter from \texttt{malloc} has been split into two values - the number of values you require and the size of those values.  Essentially it is the same calculation as before, just split across two values.

As with \texttt{malloc} any call to \texttt{calloc} has to have its memory deallocated using \texttt{free}.

\subsection{Example}

With the necessary calls for working with memory in C discussed we can now build an example application.  The following uses three methods for creating and returning an array of data.
\begin{enumerate}
\item On the stack (bad)
\item Using \texttt{malloc}
\item Using \texttt{calloc}
\end{enumerate}

The example application is below.

\begin{lstlisting}[caption=Allocating and Freeing Memory on the Heap]
#include <cstdlib>
#include <cstdio>

int* foo()
{
    // This memory is created on the stack
    int data[20];
    for (int i = 0; i < 20; ++i)
        data[i] = i;
    return data;
    // Stack emptied - memory gone
}

int* foo2()
{
    // Memory created on the heap
    int *data = (int*)malloc(sizeof(int) * 20);
    for (int i = 0; i < 20; ++i)
        data[i] = i;
    return data;
    // Memory on the heap still relevant
}

int* foo3()
{
    // Memory allocated on the heap using calloc
    // Memory set to 0.  Use elements and element size as seperate parameters
    int *data = (int*)calloc(20, sizeof(int));
    return data;
    // Memory on the heap still relevant
}

int main(int argc, char **argv)
{
    // Call foo - stack is corrupted
    int *data = foo();
    // Check values
    printf("Array 1\n");
    for (int i = 0; i < 20; ++i)
        printf("%d\n", data[i]);

    // Call foo2 - data on heap so not lost
    data = foo2();
    printf("Array 2\n");
    for (int i = 0; i < 20; ++i)
        printf("%d\n", data[i]);
    // Free memory
    free(data);
    
    // Call foo3 - data on heap so not lost
    data = foo3();
    printf("Array 3\n");
    for (int i = 0; i < 20; ++i)
        printf("%d\n", data[i]);
    // Free memory
    free(data);
    
    return 0;
}
\end{lstlisting}

The output generated from this application is as follows:

\begin{lstlisting}[style=DOS, caption=Output from Allocating Memory on the Heap Application]
Array 1
8994208
8920684
17
10090664
8917873
1
8987032
8917853
1181712074
0
0
0
2
10090620
10090624
10090752
8924336
1182763074
-2
8917853
Array 2
0
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
Array 3
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
0
\end{lstlisting}

As we can see, Array 1 has corrupted values.  Array 2, which is allocated on the heap, is correct.  Finally, for \texttt{calloc} we can see that the numbers are zeroed in Array 3.

\section{Limits of the Stack}

So far we have seen that using the heap can overcome values being out of scope.  However, we already found out in the last unit that we can overcome this by passing in pointers and references.  We could \emph{possibly} get around many of our problems in this way, but actually there is a particular issue that we have to deal with - \emph{the limit of the stack}.

Your applications only have a limited amount of stack space.  On Windows the default is 1 megabyte.  This isn't that much really.  This means that when you are working with any application that needs more that 1 megabyte of stack space you need to use the heap.  In any reasonably sized application this will be the case.

To test the limits of the stack, try the following application:

\begin{lstlisting}[caption=Allocating Beyond the Limit of the Stack]
#include <cstdlib>
#include <cstdio>

// Size of data to allocate
const unsigned int SIZE = 1048576;

int main(int argc, char **argv)
{
    // Try and create data on the stack
    // This is 1MB - common stack size.
    // Other values take us over the stack size
    char data[SIZE];
    for (int i = 0; i < SIZE; ++i)
        printf("%d\n", data[i]);

    return 0;
}
\end{lstlisting}

When you compile and run this application you will get a runtime error (the application will crash).  This is because we have attempted to allocate an array of 1 megabyte on the stack.  The other values in scope will take us over 1 megabyte, hence the runtime error.

\subsection{\textbf{For the Brave} - Setting the Stack Size with the Linker}

As mentioned, 1 megabyte is the default stack size for Windows applications.  You can however change the stack size for your application using the linker.  Below is how we achieve this.

\begin{lstlisting}[style=DOS, caption=Setting the Stack Size with the Linker]
cl /c <filename.cpp>
link /STACK:<bytes> <filename.obj>
\end{lstlisting}

See if you can get the above application to work by increasing the stack size to 1 megabyte.  Also, try and find out if there is a limit to the stack size that you can define.

\section{Allocating Large Memory Blocks on the Heap}

So the heap is the go to area of memory to work with shared memory and large data blocks.  However, there is a limit to how memory you can allocate on the heap.  The following test application lets us create a large 1 gigabyte area of memory.  This is fine, but work on the exercise to see how far you can push the limits of the application.

\begin{lstlisting}[caption=Allocating 4GB of Memory with \texttt{malloc}]
#include <cstdlib>
#include <cstdio>

// 1 megabyte in bytes
const unsigned int MB = 1024 * 1024;
// 1 gigabyte in bytes
const unsigned int GB = 1024 * MB;

int main(int argc, char **argv)
{
	// Allocate 1 GB of data
	char *data = (char*)malloc(GB);
	
	// Need to "use" the data before actual allocation occurs
	for (int i = 0; i < 100; ++i)
		printf("%d\n", data[i]);
	
	// Free the memory
	free(data);
	
	return 0;
}
\end{lstlisting}

We use \texttt{malloc} here to allocate 1 gigabyte of data.  Many operating systems and compilers will optimise your application so that memory isn't actually allocated until we use it.  Therefore, we print out 100 values from our memory block to force the memory to be allocated.  Running this application will cause no issues, but you should move onto the exercise to test some limits.

\subsection{Exercise}

Try and find the limit of the amount of memory you can allocate on both 32-bit applications.  There is a limit to the size a single variable can have (2 gigabytes), so create 1 gigabyte variables until you hit a problem.  You should also allocate a 2 gigabyte variable just to see that this is an issue.  \emph{Do not try this with a 64-bit application!}.  The limit on 64-bit will be larger than your memory and hard drive will likely be able to handle.  The operating system will allocate memory into your hard drive swap space if there is not enough main memory to cope.

\section{Using Pointers to Pointers to Allocate Memory to Parameters}

So we have now worked on the boundaries of using memory allocation.  There are still another problem that new C and C++ programmers experience - allocating memory to parameters passed into a function.  Remember in the last lesson that we used pointers and references to pass in values to functions that we could then change.  Well a pointer itself is just a value, so what if we want to change the pointer (i.e. the memory location pointed to) in a function.  This is where we need pointers to pointers.

\begin{framed}
\textbf{What are \emph{Pointers-to-Pointers}?}

A pointer to a pointer is exactly that.  We have a memory location that itself contains a memory location telling us where the data is actually located.  We have two levels of indirection.  At the moment, we need these ideas to allow us to allocate memory in a function to a passed in parameter.  We will look at pointers-to-pointers further when we discuss data structures towards the end of the module.  We have already used pointers-to-pointers when we worked with the command line (remember the \texttt{char **argv} value).

We can have many levels of indirection.  It is possible to have a pointer-to-pointer-to-pointer - a 3-dimensional array will have this, or a 2-dimensional array passed in as a parameter.  The point is we have memory locations that contain memory locations.  We can then work with these to various levels.  Although common in C, they are less common in C++ where we can use object-orientation to overcome the issues.
\end{framed}

The following example application illustrates the problem when using \texttt{malloc} in a function. Of particular note is the memory leaks we create.

\begin{lstlisting}[caption=Using Pointers to Pointers]
#include <cstdlib>
#include <cstdio>

void foo(int *value)
{
    // Allocate the value.  This changes the memory pointed to
    value = (int*)malloc(sizeof(int));
    *value = 5;
    // Print address and value
    printf("In first foo, address - %d, value - %d\n", value, *value);
    // When we return, we lose the memory address
    // We have a leak!!!
}

void foo(int **value)
{
    // Allocate the value.  This changes the memory pointed to
    *value = (int*)malloc(sizeof(int));
    **value = 5;
    // Print address and value - have to dereference twice
    printf("In second foo, address - %d, value - %d\n", *value, **value);
    // When we return, we retain the pointed to memory address
}

int main(int argc, char **argv)
{
    // Declare value.  Use calloc to set as 0
    int *value = (int*)calloc(1, sizeof(int));
    // Print address and value
    printf("Initially, address - %d, value - %d\n", value, *value);
    // Call foo
    foo(value);
    // Print address and value
    printf("After first foo, address - %d, value - %d\n", value, *value);
    // Call foo with pointer to pointer
    foo(&value);
    // Print address and value
    printf("After second foo, address - %d, value - %d\n", value, *value);
    // Free memory
    free(value);

    return 0;
}
\end{lstlisting}

\begin{framed}
\textbf{Memory Leak Problems}

Once we ``lose'' a memory address (the pointer) we cannot free the memory involved.  However, the Operating System will still have the memory marked as allocated until your application exits.  We have seen a few ways now that we can create memory leaks and memory allocation problems and for the novice programmer remembering these can take time.

In current software development using the types of systems we do losing a few bytes of memory in an applications lifetime can be seen as not a bad thing.  A few years ago when memory was far more limited it was a bigger issue.  On limited systems (such as embedded systems) losing a few bytes of memory can be an issue.

In an application that has some form of control loop (such as game that loops 60+ times a second) losing a few bytes every iteration is a major issue as that memory won't come back until the application exits.  This can escalate quickly to your application existing with a memory problem or just slowing down considerably.
\end{framed}

\begin{framed}
\textbf{Dereferencing Multiple Times}

In the above application we also use \texttt{**} to dereference our pointer-to-pointer value.  This is also worth remembering as a new programmer - \emph{for every level of indirection you create you have to perform a dereference to get to the actual value}.  When we work with multiple dimensional arrays later in the module we will come back to this idea in more depth.
\end{framed}

Running this application will provide you with output similar to the following (the memory addresses will be different):

\begin{lstlisting}[style=DOS, caption=Output from Pointer to Pointer Application]
Initially, address - 16833728, value - 0
In first foo, address - 16833744, value - 5
After first foo, address - 16833728, value - 0
In second foo, address - 16833760, value - 5
After second foo, address - 16833760, value - 5
\end{lstlisting}

Notice the problem that occurs in the first call to \texttt{foo}.  We can see that we have allocated a new block of memory (location 16833744 above) and set the value to 5.  However, outside the call this is not reflected - the memory location and value is the same as before the call.  Only in the second \texttt{foo} do we solve the problem.

\section{Using \texttt{new} in C++ to Allocate Memory}

Allocating memory in C using \texttt{malloc} and \texttt{calloc} can be useful when working in C, but C++ provides a different mechanism - the \texttt{new} operator.  \texttt{new} will also allocate memory on the heap but does so in a manner that is easier to read.  In fact, you have used this method in Java already.

C++ memory location using \texttt{new} operates on the surface as C memory allocation using \texttt{malloc} and \texttt{calloc} does.  Memory is still allocated in a block and we still need to free (or delete in C++ terms) the memory after we are finished with it.  In the next section we will look at automatic memory management in C++ to make our life even easier.

\subsection{Using \texttt{new} to Allocate Memory}

\texttt{new} is not a function in C++ as \texttt{malloc} - it is an operator.  Using \texttt{new} in C++ takes the following form for allocating a single value:

\vspace{12pt}
\texttt{\emph{type} *name = new \emph{type}(\emph{paramaters});}
\vspace{12pt}

Notice that we don't have to tell \texttt{new} the size of the value - it can work this out itself.  We can also pass parameters (or the value) to the call to \texttt{new}.  It is effectively the same call you would make in Java and C\#.  As an example, to allocate a new \texttt{int} with the value 5 we would use:

\vspace{12pt}
\texttt{int *value = new int(5);}
\vspace{12pt}

\begin{framed}
\textbf{\texttt{new} as an operator}

As mentioned \texttt{new} is not a function in C++ but an operator (like +, *, etc.).  As such, a class can actually override the standard behaviour of \texttt{new} and undertake something different.  This is not done too often, but can be used in particular circumstances when finer grained control of memory is required.

We will look at operator overloading (but not overloading \texttt{new} in the second half of the module.
\end{framed}

\subsection{Using \texttt{delete} to Free Memory}

As \texttt{malloc} is paired with \texttt{free} in C, \texttt{new} is paired with \texttt{delete}.  \texttt{delete} is also an operator and as such the call is very simple.

\vspace{12pt}
\texttt{delete name;}
\vspace{12pt}

We just use the variable name that we allocated to and work accordingly.  For example, to delete the variable we allocated using \texttt{new} above we use the following:

\vspace{12pt}
\texttt{delete value;}
\vspace{12pt}

\begin{framed}
\textbf{\texttt{delete} as an operator}

As with \texttt{new}, \texttt{delete} is also an operator that can be overridden by the programmer for different classes.  If you ever need to override \texttt{new} then you should also override \texttt{delete}.  Again, we will come to operator overloading (but not of \texttt{delete}) later in the module.
\end{framed}

\subsection{Using \texttt{new} to Allocate Arrays}

So we have seen how to use \texttt{new} to allocate a single value.  What about arrays of values?  Well in C++ we can do this in a similar manner to the one you have experienced in Java:

\vspace{12pt}
\texttt{\emph{type} *name = new \emph{type}[\emph{size}];}
\vspace{12pt}

Again, we don't need to pass the size of the individual type - C++ can work this out for us.  It just needs to know how many items you wish to allocate.  As an example, to allocate 100 \texttt{float} values we would do the following:

\vspace{12pt}
\texttt{float *values = new float[100];}
\vspace{12pt}

\begin{framed}
\textbf{Arrays in C and C++ Revisited}

Notice that we are still just working with a pointer (single \texttt{*}) when using \texttt{new} when working with an array or a single value.  Remember from our discussion before that an array is just a memory location where we state that a certain type of data is.  In C++ we don't even know how many values there are in that memory location - we have to keep track of this ourselves.

When working with arrays in C and C++ it is worth remembering that we can access individual values as an offset from this base address.  For example, if we have 10 values of type \texttt{int} (assuming \texttt{int} is 4 bytes) then the offset of each value of the array from the starting address is:

\begin{center}
\begin{tabular}{|l|c|c|c|c|c|c|c|c|c|c|}
\hline
index & 0 & 1 & 2 & 3 & 4 & 5 & 6 & 7 & 8 & 9 \\
\hline
offset & 0 & 4 & 8 & 12 & 16 & 20 & 24 & 28 & 32 & 36 \\
\hline
\end{tabular}
\end{center}

When we used \texttt{malloc} we did not really specify that we might be only allocating a single value in memory - but it is possible.  In C++ the distinction is more obvious because of the different syntax used.
\end{framed}

\subsection{Freeing Arrays with \texttt{delete[]}}

In C++ we have to specify that we are deleting an array when calling \texttt{delete}.  The call is as follows:

\vspace{12pt}
\texttt{delete[] name;}
\vspace{12pt}

Otherwise the idea is the same.  For example, to delete our 100 \texttt{float} values used above we undertake the following:

\vspace{12pt}
\texttt{delete[] values;}
\vspace{12pt}

\subsection{Test Application}

Let us now build a test application for using \texttt{new} and \texttt{delete}.  This is shown below.  It follows the same pattern we used for \texttt{malloc}.

\begin{lstlisting}[caption=Using \texttt{new} and \texttt{delete}]
#include <iostream>

using namespace std;

int* foo()
{
    // Create memory on the heap
    int *data = new int(5);
    // Return data
    return data;
}

int* foo2(unsigned int size)
{
    // Create an array on the heap
    int *data = new int[size];
    // Return data
    return data;
}

int main(int argc, char **argv)
{
    // Call foo
    int *data = foo();
    // Output address and value
    cout << "Address = " << data << ", value = " << *data << endl;
    // Delete the memory
    delete data;

    // Call foo2
    int *data2 = foo2(20);
    // Output addresses and value
    for (int i = 0; i < 20; ++i)
        cout << "Array address = " << &data[i] << ", value = " << data[i] << endl;
    // Delete the memory
    delete[] data2;
    
    return 0;
}
\end{lstlisting}

Notice on line 34 we are also printing the \emph{address of} the array elements.  This is to illustrate that the array elements are continuous in memory.  An output for this application (depending on the memory addresses used) is shown below:

\begin{lstlisting}[style=DOS, caption=Output from C++ Memory Allocation Application]
Address = 0084A928, value = 5
Array address = 0084A928, value = 8694344
Array address = 0084A92C, value = 8650944
Array address = 0084A930, value = 232176122
Array address = 0084A934, value = 134221306
Array address = 0084A938, value = 14541700
Array address = 0084A93C, value = 1
Array address = 0084A940, value = 81181171
Array address = 0084A944, value = 134221306
Array address = 0084A948, value = 8695168
Array address = 0084A94C, value = 8694408
Array address = 0084A950, value = 0
Array address = 0084A954, value = 0
Array address = 0084A958, value = 8694044
Array address = 0084A95C, value = 0
Array address = 0084A960, value = 8694040
Array address = 0084A964, value = 0
Array address = 0084A968, value = 0
Array address = 0084A96C, value = 14579872
Array address = 0084A970, value = 0
Array address = 0084A974, value = 0
\end{lstlisting}

Notice the memory addresses for arrays.  Our array has memory address 0084A928 (in hexadecimal).  This is also the address of the first element (element 0).  Every other element has this base address plus four times its own index.  So element index 7 has the base memory address plus 28 (so memory location 0084A944 in hex).  Understanding this relationship between memory addresses and items in an array is also an important concept when dealing with low level memory concerns.

\section{Best Practice When Working with Allocated Memory}

We have actually been very bad in our current use of memory.  When deleting or freeing memory we should always set our memory to \texttt{null} afterwards.  In raw memory terms this means setting the pointer to 0 (equivalent to not allocated).  In C we should do the following:

\begin{lstlisting}
void *mem = malloc(1024);
// Do something with the memory
free(mem);
// Set pointer to null (0)
mem = 0;
\end{lstlisting}

In C++ we would do something like this:

\begin{lstlisting}
int *x = new int(5);
// Do something with x
delete x;
x = 0;
\end{lstlisting}

In modern C++ (C++11 onwards) we can use the \texttt{nullptr} value (which also equals 0):

\begin{lstlisting}
int *x = new int(5);
// Do something with x
delete x;
x = nullptr;
\end{lstlisting}

\emph{From this point onwards you should always free your memory and then set it to \texttt{null}}.  In particular, when working with C++ you should use \texttt{nullptr} as this is the standard.  Remember this as it can solve a number of issues.  We will also return to \texttt{nullptr} in the next few sections.

\section{\texttt{shared\_ptr} and Automatic Memory Management}

Working with memory has been a major issue for new (and even experienced) C and C++ programmers.  Thankfully the C++11 standard introduced new data types that overcome many of the issues encountered when working with memory - \emph{smart pointers}.  There are two types of smart pointers - \texttt{shared\_ptr} (pronounced \emph{shared puter}) and \texttt{unique\_ptr} (\emph{unique puter}).  We will look at \texttt{shared\_ptr} first.

\begin{framed}
\textbf{Garbage Collection}

In languages and runtimes such as Java, C\#, Python and JavaScript our memory management is handled for us.  This is done using a technique called \texttt{garbage collection}.  Garbage collection means that the runtime takes care of determining when memory is being used and when it can be freed.  This makes the life of a programmer \emph{much easier}.  However, it has an impact on performance - the tracking of valid and invalid memory and the freeing of it takes processor time.

From the advent of Java many people have considered garbage collection the best method for most applications.  However, the introduction of smart pointers have driven a vocal argument about garbage collection being a problem.  At the end of the day, unless you are writing high performance, well optimised code, there is really no argument against garbage collection - you should always use a language that is best fit for the purpose (no language is good in all conditions).  However, understanding when your values are valid and not in memory is an important skill.
\end{framed}

\begin{framed}
\textbf{Working with \texttt{shared\_ptr}}

\texttt{shared\_ptr} tries to work as much like a standard pointer as possible.  This means that much of our previous examination of pointers in C++ carries on to \texttt{shared\_ptr}.  Many of the differences come from declaration and creating the \texttt{shared\_ptr}.

To declare a \texttt{shared\_ptr} we use the following:

\vspace{12pt}
\texttt{shared\_ptr<\emph{type}> name;}
\vspace{12pt}

The \texttt{type} parameter tells us what is pointed to.  So for example to create a \texttt{shared\_ptr} of type \texttt{int} we do the following:

\vspace{12pt}
\texttt{shared\_ptr<int> value;}
\vspace{12pt}

To actually create a \texttt{shared\_ptr} (remember that declaring a pointer doesn't mean allocating memory) we need to pass a pointer as a parameter:

\vspace{12pt}
\texttt{shared\_ptr<\emph{type}> name = shared\_ptr<\emph{type}>(new \emph{type}(\emph{params...}));}
\vspace{12pt}

So to create a \texttt{shared\_ptr} of type \texttt{int} we would use the following:

\vspace{12pt}
\texttt{shared\_ptr<int> value = shared\_ptr<int>(new int(5));}
\vspace{12pt}

Another method of creating a \texttt{shared\_ptr} is using the \texttt{make\_shared} function.  This function works out the correct method to create the object by the parameters passed to it.  So for an \texttt{int} we can use the following:

\vspace{12pt}
\texttt{shared\_ptr<int> value = make\_shared(5);}
\vspace{12pt}

The \texttt{make\_shared} function is the better method for creating \texttt{shared\_ptr} values in general as it involves no copying of data.

The \texttt{shared\_ptr} value behaves much like a standard pointer otherwise.  When the dereference operator (\texttt{*}) is used we can access the value.  There are other operations on \texttt{shared\_ptr} but the only one we will look at just now is getting the usage count.  This is done using the \texttt{use\_count} method on the \texttt{shared\_ptr}.  This tells us how many references there are to the pointer.  When the \texttt{shared\_ptr} is passed as a parameter (enters a new scope) the use count is incremented.  Exiting a scope or setting one of the \texttt{shared\_ptr} to \texttt{nullptr} decrements the count.  When the count equals 0 the memory is deleted.
\end{framed}

Let us build an example application using \texttt{shared\_ptr}.  This is shown below:

\begin{lstlisting}[caption=Using \texttt{shared\_ptr}]
#include <iostream>
#include <memory>

using namespace std;

void foo(shared_ptr<int> value)
{
    // Print out number of accessors to the shared object - should be 2
    cout << "In foo, count on shared_ptr = " << value.use_count() << endl;
    // shared_ptr behaves like a pointer - we can assign to it by dereferencing
    *value = 5;
}

int main(int argc, char **argv)
{
    // We can create a shared_ptr by wrapping it around an allocated object
    shared_ptr<int> value = shared_ptr<int>(new int(10));
    cout << "Initial address = " << value << ", value = " << *value << endl;
    // We can also create a shared_ptr by using the make_shared function
    value = make_shared<int>(70);
    cout << "After make shared, address = " << value << ", value = " << *value << endl;
    // Print out number of accessors to the shared object
    cout << "Before foo, count on shared_ptr = " << value.use_count() << endl;
    // Let's call foo
    foo(value);
    cout << "After foo, address = " << value << ", value = " << *value << endl;
    // Print out number of accessors to the shared object
    cout << "After foo, count on shared_ptr = " << value.use_count() << endl;
    // Let's set value to nullptr - this will clear the memory 
    value = nullptr;
    // Print out number of accessors to the shared object.  Should be 0
    cout << "After nullptr, count on shared_ptr = " << value.use_count() << endl;

    return 0;
}
\end{lstlisting}

\begin{framed}
\textbf{What is \texttt{nullptr}?}

We already mentioned that \texttt{nullptr} can be used to set a pointer to null.  However, it does more than this.  \texttt{nullptr} was introduced with smart pointers.  It allows us to set a smart pointer to null.  \texttt{nullptr} can be used as a \texttt{shared\_ptr} value which 0 does not.  However, \texttt{nullptr} can be used as 0.  Therefore, \texttt{nullptr} should be used wherever possible.
\end{framed}

\begin{framed}
\textbf{Referencing Counting of Pointers}

The idea of referencing counting of pointers has been around for a long time.  Almost every company that used C++ extensively created their own version of a reference counting data type.  C++11 introduced this as a language feature of C++ rather than a user defined type.  This has changed how C++ should be approached as a programming language.  In general, smart pointers are the method you should use from now on.
\end{framed}

\begin{framed}
\textbf{Using \texttt{make\_shared}}

\texttt{make\_shared} is a useful C++ function which uses some C++ magic to work - magic we won't look at in this module.  If you are interested then looking at \emph{variadic templates} and \emph{metatemplate programming} is a worthwhile area of research (after the module though).

\texttt{make\_shared} works by calling the necessary \emph{constructor} (more on this when we discuss object-orientation).  It works this out by the parameters passed as the compiler working out the correct method to call.  If no constructor exists with those parameters we get a compiler error.
\end{framed}

The following is an example output from the application:

\begin{lstlisting}[style=DOS, caption=Output from \texttt{shared\_ptr} Application]
Initial address = 00D3A948, value = 10
After make shared, address = 00D3AA7C, value = 70
Before foo, count on shared_ptr = 1
In foo, count on shared_ptr = 2
After foo, address = 00D3AA7C, value = 5
After foo, count on shared_ptr = 1
After nullptr, count on shared_ptr = 0
\end{lstlisting}

The use count value illustrates how reference counting works.  This is the important aspect of \texttt{shared\_ptr}.  We can pass the value around happily and when we no longer need it the memory is cleared up.  Our other smart pointer - \texttt{unique\_ptr} - is not for sharing.  It is only valid in one scope.

\section{Examining \texttt{shared\_ptr}}

As with a normal pointer we cannot just pass in \texttt{shared\_ptr} values as parameters and change the pointer.  When passing a \texttt{shared\_ptr} value into a function a copy of the \texttt{shared\_ptr} is made (but not a copy of the pointed to data).  This means that changing the address (for example using \texttt{make\_shared}) changes the pointer.  This is the same problem we had to overcome using pointers-to-pointers.

To overcome this we can use a reference to our \texttt{shared\_ptr}.  The following application illustrates this:

\begin{lstlisting}[caption=Examining the \texttt{shared\_ptr} Value]
#include <iostream>
#include <memory>

using namespace std;

void foo(shared_ptr<int> value)
{
    // Output number of accessors to value - should be 2
    cout << "In foo, accessors to value = " << value.use_count() << endl;
    // Call make_shared again - we lose this copy
    value = make_shared<int>(25);
    // Output number of accessors to value - should be 1
    cout << "In foo, after make_shared, accessors to value = " << value.use_count() << endl;
    // No memory leaks! shared_ptr will clean itself up
}

// Note we now have a reference to the shared_ptr
void foo2(shared_ptr<int> &value)
{
    // Output number of accessors to value - should be 1
    cout << "In foo2, accessors to value = " << value.use_count() << endl;
    // Call make_shared again - we retain this copy
    value = make_shared<int>(100);
    // Output number of accessors to value - should still be 2
    cout << "In foo2, after make_shared, accessors to value = " << value.use_count() << endl;
}

int main(int argc, char **argv)
{
    // Create a new shared_ptr
    shared_ptr<int> value = make_shared<int>(5);
    // Print data
    cout << "Address = " << value << ", value = " << *value << ", usage = " << value.use_count() << endl;
    // Call foo
    foo(value);
    // Print data
    cout << "Address = " << value << ", value = " << *value << ", usage = " << value.use_count() << endl;
    // Call foo2
    foo2(value);
    // Print data
    cout << "Address = " << value << ", value = " << *value << ", usage = " << value.use_count() << endl;

    return 0;
}
\end{lstlisting}

Below is an example output.  Notice that the printing of the value on line 13 illustrates that the use count is changed to 1 after the call to \texttt{make\_shared}.  This is the problem that \texttt{foo2} overcomes by passing the \texttt{shared\_ptr} as a reference.

\begin{lstlisting}[style=DOS, caption=Output from Examing the \texttt{shared\_ptr} Value]
Address = 00A9A964, value = 5, usage = 1
In foo, accessors to value = 2
In foo, after make_shared, accessors to value = 1
Address = 00A9A964, value = 5, usage = 1
In foo2, accessors to value = 1
In foo2, after make_shared, accessors to value = 1
Address = 00A9AACC, value = 100, usage = 1
\end{lstlisting}

\section{Using \texttt{shared\_ptr} for Arrays}

\texttt{shared\_ptr} works well for standard values allocated in the heap.  For arrays it is a little different.  This is because of the different allocation and deletion methods that arrays use.  As such, when working with arrays and \texttt{shared\_ptr} we have to declare them a little differently.

Firstly, the \texttt{make\_shared} function cannot be used for arrays - there is no object constructor for arrays.  Therefore we always have to use the standard \texttt{shared\_ptr} constructor:

\vspace{12pt}
\texttt{shared\_ptr<\emph{type}> name = shared\_ptr<\emph{type}>(new \emph{type}[\emph{size}]);}
\vspace{12pt}

So to create an array of size 10 we would use the following:

\vspace{12pt}
\texttt{shared\_ptr<int> value = shared\_ptr<int>(new int[10]);}
\vspace{12pt}

This is only one part of the problem.  \texttt{shared\_ptr} does not know that our value is an array and therefore won't delete the memory properly.  Thus we need to tell \texttt{shared\_ptr} how to delete the memory.  We do this by passing a deletion method.  C++ comes with some default ones that we can use for arrays:

\vspace{12pt}
{
\footnotesize
\texttt{shared\_ptr<\emph{type}> name = shared\_ptr<\emph{type}>(new \emph{type}[\emph{size}], default\_delete<\emph{type}[]>());}
}
\vspace{12pt}

So for our \texttt{int} array we can use the following:

\vspace{12pt}
{
\footnotesize
\texttt{shared\_ptr<int> name = shared\_ptr<int>(new int[10], default\_delete<int[]>());}
}
\vspace{12pt}

Below is an example application to show how we do this:

\begin{lstlisting}[caption=Using \texttt{shared\_ptr} for Arrays]
#include <iostream>
#include <memory>

using namespace std;

const int SIZE = 65536;

void build_array(shared_ptr<int> data)
{
    for (int i = 0; i < SIZE; ++i)
        // Have to dereference the pointer, then access the values
        data.get()[i] = i;
}

void print_array(shared_ptr<int> data)
{
    for (int i = 0; i < SIZE; ++i)
        // Have to dereference the pointer, then access the values
        cout << data.get()[i] << endl;
}

int main(int argc, char **argv)
{
    // We have to tell shared_ptr how to delete the data
    // When creating use the default_delete function
    shared_ptr<int> data = shared_ptr<int>(new int[SIZE], default_delete<int[]>());
    // Build the array
    build_array(data);
    // Print the array
    print_array(data);
    // Set data to nullptr - will cause data to be deleted
    data = nullptr;

    return 0;
}
\end{lstlisting}

On line 12 we use the \texttt{get} method on the \texttt{shared\_ptr}.  This allows us to get the raw pointer controlled by the \texttt{shared\_ptr}.  We need to do this to access the individual elements of the array.  We cannot do this via the \texttt{shared\_ptr} - it is not an array.  Therefore we have to get the raw pointer and work with it in the way we want.

\section{\texttt{unique\_ptr}}

\texttt{shared\_ptr} is a good replacement for almost every situation where we would use a pointer.  However, it comes with an overhead for the management of the reference counting.  It is also the case that sometimes we don't need to share the pointer - there is only ever one owner.  This is true for when we have to allocate large temporary blocks of memory inside functions.  The \texttt{unique\_ptr} is a solution to this.

\begin{framed}
\textbf{Why we need \texttt{unique\_ptr}}

\texttt{unique\_ptr} works by monitoring which scope currently owns the pointer.  The pointer can only be owned by one function.  When you pass the \texttt{unique\_ptr} to another function the ownership is passed to this function and the caller loses ownership.

This idea can be quite tricky for new programmers to understand.  C++11 introduced the idea of \emph{move semantics}.  Move semantics are an area we won't cover in this module any further, but you should look into these further if you are to become a C++ programmer.  Move semantics mean that we \emph{move} data from one function to another.  No copying takes place, but also no reference passing occurs.  This is the middle ground between pass-by-value and pass-by-reference.

We need \texttt{unique\_ptr} for situations where we don't need reference counting.  In general you probably should stick with \texttt{shared\_ptr} unless you are sure you don't need pointer sharing.  This takes experience and thought to determine.
\end{framed}

\begin{framed}
\textbf{Difference between \texttt{unique\_ptr} and \texttt{shared\_ptr}}

The difference between \texttt{shared\_ptr} and \texttt{unique\_ptr} is the reference counting.  \texttt{unique\_ptr} has none - it uses move semantics to ensure that only one owner of the pointer exists.  When that owner goes out of scope the memory is cleared up.

\texttt{shared\_ptr} adds to the use count every time a copy (pass-by-value) of the pointer is made.  The use count is decremented every time one of these copies goes out of scope.  When the use count equals 0 the memory is cleared up.

Using \texttt{shared\_ptr} and \texttt{unique\_ptr} is now the common practice in C++.  Working with raw memory should only occur when working at a low level such as using hardware.  This makes working with C++ easier for new programmers - once they understand using smart pointers.
\end{framed}

An example application of using \texttt{unique\_ptr} is below.  Note the problems encountered when passing the data to a function without using a reference.  Also, there is currently no \texttt{make\_unique} function as there is \texttt{make\_shared} supported by the Microsoft compiler - although the C++14 standard does introduce this.

\begin{lstlisting}[caption=Using \texttt{unique\_ptr}]
#include <iostream>
#include <memory>

using namespace std;

void foo(unique_ptr<int> value)
{
    // Let's set the value to 500.  Can treat just as a pointer
    *value = 500;
    // We don't return unique_ptr.  We have lost *ALL* the data
}

unique_ptr<int> foo2(unique_ptr<int> value)
{
    // This time we will move the answer back
    *value = 500;
    return value;
}

void foo3(unique_ptr<int> &value)
{
    // Using a reference solves the problem
    *value = 1000;
}

int main(int argc, char **argv)
{
    // Create a unique_ptr value
    unique_ptr<int> value(new int(50));
    // Print data
    cout << "Address = " << value.get() << ", value = " << *value << endl;
    // Call foo.  We have to "move" the pointer into foo
    foo(move(value));
    // Print data.  Cannot print value.  No longer valid
    cout << "After foo, address = " << value.get() << endl;

    // Recreate the value
    value = unique_ptr<int>(new int(50));
    // Print data
    cout << "Address = " << value.get() << ", value = " << *value << endl;
    // Call foo2.  We have to "move" the pointer into foo
    value = foo2(move(value));
    // Print data
    cout << "After foo2, address = " << value.get() << ", value = " << *value << endl;
    
    // Call foo3.  Use a reference to avoid a move
    foo3(value);
    // Print data
    cout << "After foo3, address = " << value.get() << ", value = " << *value << endl;
    
    return 0;
}
\end{lstlisting}

On line 20 we overcome the move of a \texttt{unique\_ptr} by using pass-by-reference.  Passing smart pointers by reference overcomes many issues that we had to use pointers-to-pointers.  An example output from this application is below:

\begin{lstlisting}[style=DOS, caption=Output from \texttt{unique\_ptr} Application]
Address = 0107A948, value = 50
After foo, address = 00000000
Address = 0107A948, value = 50
After foo2, address = 0107A948, value = 500
After foo3, address = 0107A948, value = 1000
\end{lstlisting}

\section{\texttt{unique\_ptr} for Arrays}

Unlike \texttt{shared\_ptr}, \texttt{unique\_ptr} can happily work with arrays.  As \texttt{unique\_ptr} is meant for situations where we need blocks of temporary memory this makes sense.  Below is an example application showing how we use arrays with \texttt{unique\_ptr}.

\begin{lstlisting}[caption=Using \texttt{unique\_ptr} for Arrays]
#include <iostream>
#include <memory>

using namespace std;

const int SIZE = 65536;

void build_array(unique_ptr<int[]> &data)
{
    for (int i = 0; i < SIZE; ++i)
        // Have to dereference the pointer, then access the values
        data.get()[i] = i;
}

void print_array(unique_ptr<int[]> &data)
{
    for (int i = 0; i < SIZE; ++i)
        // Have to dereference the pointer, then access the values
        cout << data.get()[i] << endl;
}

int main(int argc, char **argv)
{
    // unique_ptr can have arrays
    unique_ptr<int[]> data(new int[SIZE]);
    // Build the array - using pass by reference on the unique_ptr
    build_array(data);
    // Print the array
    print_array(data);
    // Set data to nullptr - will delete the array
    data = nullptr;

    return 0;
}
\end{lstlisting}

Notice that we still have to declare the array using \texttt{new} and pass this to the \texttt{unique\_ptr}.  Otherwise we don't have to do anything else special to work with arrays and \texttt{unique\_ptr}.

\section{The \texttt{auto} Keyword}

We are now getting to a point where we are getting quite complicated type names.  For \texttt{shared\_ptr}, \texttt{unique\_ptr} and \texttt{vector} we can end up writing quite long type names.  For example, we could easily have a type of the following:

\vspace{12pt}
\texttt{vector<shared\_ptr<vector<int>> data;}
\vspace{12pt}

This is a \texttt{vector} containing a collection of \texttt{shared\_ptr} to \texttt{vector} of \texttt{int} - or a multidimensional array like structure using \texttt{vector}.  This is actually not an uncommon thing to do in large applications.

Writing out this type name can be tiresome.  Thankfully C++11 introduced the new \texttt{auto} keyword.  This allows the compiler to determine the type for us.  An example application is below.

\begin{lstlisting}[caption=Using \texttt{auto} to Simplify Code]
#include <iostream>
#include <memory>

using namespace std;

int main(int argc, char **argv)
{
    // Use the auto keyword - compiler determines the type
    auto data = make_shared<int>(5);
    // ... data is a shared_ptr<int>.  Compiler fills in the type
    return 0;
}
\end{lstlisting}

\begin{framed}
\textbf{Using the \texttt{auto} keyword}

The \texttt{auto} keyword for a data type only works when the compiler can work out the type.  For example we cannot simply write the following:

\vspace{12pt}
\texttt{auto x;}
\vspace{12pt}

The compiler has no way of determining the type - \texttt{x} could be anything.  Changing this to the following:

\vspace{12pt}
\texttt{auto x = 5;}
\vspace{12pt}

Means that \texttt{x} is determined to be of type \texttt{int}.

The \texttt{auto} keyword comes in very handy as you get further into C++ programming.  In C++14 it can also be used for parameters which is pretty powerful.  At the moment though you should only use it for variable declarations.

The \texttt{auto} keyword should not be confused with dynamic typing seen in languages such as JavaScript and Python.  The compiler is determining the type of your variable and this type cannot be changed.  For example, it is not OK to write the following:

\begin{lstlisting}
// Type is shared_ptr<int>
auto x = make_shared<int>(5);
// Now just try and set x to 5 (so just an int)
x = 5;
// This will cause a compiler error
\end{lstlisting}

\texttt{auto} does not enable dynamic typing in C++ - due to it's low level nature this is not possible.  Don't think of \texttt{auto} as any type.  It is just a method to let the compiler fill in the type for us.
\end{framed}

\section{\textbf{For the Brave} - Casting in C++ Using \texttt{static\_cast}}

For the last part of this unit we will look at some of the C++ casting methods.  We already looked at casting from a C point of view, and this still exists in C++.  However, this type of casting is frowned upon in C++ and other techniques should be used instead.

Remember our discussion on C casting.  From that point of view we were simply stating that an area of memory should be treated as a different type.  This has no checking involved which can lead to a number of problems.  C++ uses the \texttt{static\_cast} function to allow us cast between types in C++ safely.  It takes the following form:

\vspace{12pt}
\texttt{\emph{type} name = static\_cast<\emph{type}>(value);}
\vspace{12pt}

So to cast a \texttt{float} to an \texttt{int} we would do the following:

\begin{lstlisting}
float x = 12.5f;
int y = static_cast<int>(x);
\end{lstlisting}

Let us look at an example application where we try and cast a \texttt{string} to a \texttt{float}.  This code is shown below:

\begin{lstlisting}[caption=Using \texttt{static\_cast}]
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
	// Declare an int
	int x = 10;
	// Cast to a float
	// Let compiler work out the type
	auto y = static_cast<float>(x);
	// Declare a string
	string str = "Hello world!";
	// Cast str to a float
	// Will cause a compiler error
	auto z = static_cast<float>(str);
	
	return 0;
}
\end{lstlisting}

Compiling this application will provide a compiler error as shown below.  Notice that the line (17) is given that is the problem and the issue (no conversion operator available).

\begin{lstlisting}[style=DOS, caption=Compiler Output from Casting Error]
cl static_cast.cpp
Microsoft (R) C/C++ Optimizing Compiler Version 18.00.30501 for x86
Copyright (C) Microsoft Corporation.  All rights reserved.

static_cast.cpp
C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\INCLUDE\xlocale(337) : wa
rning C4530: C++ exception handler used, but unwind semantics are not enabled. S
pecify /EHsc
static_cast.cpp(17) : error C2440: 'static_cast' : cannot convert from 'std::str
ing' to 'float'
        No user-defined-conversion operator available that can perform this conv
ersion, or the operator cannot be called
\end{lstlisting}

\section{\textbf{For the Brave} - Casting with \texttt{const\_cast}}

Another casting function C++ provides is \texttt{const\_cast}.  \texttt{const\_cast} allows us to convert a \texttt{const} value to a non-\texttt{const} value.  This can overcome a situation where we need to modify a \texttt{const} value.

Let us look at an example application where we cast away the \texttt{const} of the internal \texttt{char} array in a \texttt{string}.  This allows us to modify the individual characters in the \texttt{string}.  This example application is below.

\begin{lstlisting}[caption=Using \texttt{const\_cast}]
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
	// Create a string
	string str = "Hello World!";
	cout << "String = " << str << endl;
	// Get the raw C string
	const char *const_raw = str.c_str();
	// Can't change any values in raw - const
	// This won't compile
	// const_raw[4] = 'p';
	// Now let's live dangerously - use const cast
	char *raw = const_cast<char*>(const_raw);
	// Change the value of raw now
	raw[4] = 'p';
	// Print out the string
	cout << "String = " << str << endl;
	
	return 0;
}
\end{lstlisting}

In this application we are changing the 5th character of ``Hello World!'' (remember that the 1st character is index 0) to  ``p'' giving us ``Hellp World!''.  The output is shown below.

\begin{lstlisting}[style=DOS, caption=Output from Manipulating \texttt{const} Values with \texttt{const\_cast}]
String = Hello World!
String = Hellp World!
\end{lstlisting}

\begin{framed}
\textbf{WARNING - avoid \texttt{const\_cast}}

So we can remove the \texttt{const} of a value - surely that can be useful.  Well yes, but if you have written an application that requires you to do this you should probably rethink what you have done.  Values are normally declared \texttt{const} for a reason and removing this normally circumvents this requirement.  Rethink your application if you find that you require \texttt{const\_cast}.
\end{framed}

\section{\textbf{For the Brave} - Using \texttt{typeid}}

Although we are generally just dealing with raw memory blocks in C++ and just stating what we want to treat the memory as, it is possible to get type information in C++.  It isn't that common as it does have an overhead, but we can use the \texttt{typeid} function to get a value's type.  This type is itself a type with some values and operations associated with it.

Below is a test application using \texttt{typeid}.  This is all we will do with types in C++ apart from working with object-orientation concepts.  However, you should consider typing a fundamental part of programming.

\begin{lstlisting}[caption=Using \texttt{typeid}]
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv)
{
	// Create a string
	string str1 = "Hello";
	string str2 = "World";
	
	// Check if the types are equal
	if (typeid(str1) == typeid(str2))
		cout << "Types are equal" << endl;
	else
		cout << "Types are not equal" << endl;
		
	// Create a float
	float x = 52.0f;
	
	// Print out details
	cout << "x is a " << typeid(x).name() << " with value " << x << endl;
	
	return 0;
}
\end{lstlisting}

We are testing if two values of type \texttt{string} have the same type (they do), and then getting the name of the \texttt{float} type.  The output from this application is shown below:

\begin{lstlisting}[style=DOS, caption=Output from \texttt{typeid} Application]
Types are equal
x is a float with value 52
\end{lstlisting}

\section{Case Study - Building Trees}

This exercise is quite long and in a number of stages.  \emph{It is strongly advised that you undertake this exercise as it will really help in your understanding of these concepts}.  The basic parts covered are useful for understanding, and the extra exercises will really push the capabilities of the stronger students in the class.

\subsection{Trees}

Not the type you find in a park but a data structure used to efficiently store and access data.  You will come across trees in a number of places in computing, such as data structures, network architectures, etc.  We will introduce a basic type of tree - the binary tree - and how we can use that to store ordered data.

An example of a binary tree is given in Figure~\ref{fig:btree1}.  Let us define a few terms we will use.

\begin{figure}[htb]
	\centering
	\begin{tikzpicture}[->,>=stealth',shorten >=1pt,auto,node distance=2cm,thick,main node/.style={circle,fill=white!20,draw,font=\sffamily\Large\bfseries}]
	\node[main node] (5) {5};
	\node[main node] (2) [below left of=5] {2};
	\node[main node] (1) [below left of=2] {1};
	\node[main node] (4) [below right of=2] {4};
	\node[main node] (3) [below left of=4] {3};
	\node[main node] (6) [below right of=5] {6};
	\node[main node] (8) [below right of=6] {8};
	\node[main node] (7) [below left of=8] {7};
	\node[main node] (9) [below right of=8] {9};
	
	\path[every node/.style={font=\sffamily\small}]
	(5) edge node [left] {} (2)
	    edge node [right] {} (6)
	(2) edge node [left] {} (1)
	    edge node [right] {} (4)
	(4) edge node [left] {} (3)
	(6) edge node [right] {} (8)
	(8) edge node [left] {} (7)
	    edge node [right] {} (9)
	;
	\end{tikzpicture}
	\caption{Binary Tree Example}
	\label{fig:btree1}
\end{figure}

\begin{description}
	\item[node] - a node is an item in the tree (one of the circles with a number in).  A tree is just a collection of nodes connected together in a particular manner.
    \item[root node] - the top node of the tree being examined.
	\item[branch] - a branch connects a node to other nodes.  In a binary tree each node has two branches - \emph{the left branch} and \emph{the right branch}.
\end{description}

A binary tree stores data in manner such that the value store on the left branch of a node is always less than the value store in the node, and the branch on the right contains values that are larger than the value in the node.  This allows us to efficiently store data in order and retrieve it.

This also brings up an idea that you also need to grasp - \emph{a branch of a tree is itself a tree}.  Think about it.  If we take a branch, then we are effectively considering the root node as the top node of that branch.  This allows us to think of the tree as a collection of sub-trees, which comes in handy when we start dealing with our algorithms.

\subsubsection{Exercise}

Check the tree in Figure~\ref{fig:btree1} now.  Look at each node and then look at the node on its left branch and then its right branch.  Is the tree correct?  Discuss with someone else in the class and then one of the teaching team to determine its correctness.

\subsection{Building a Binary Tree}

Next let us examine how we created the tree in Figure~\ref{fig:btree1}.  We will look at the left hand side first.  At the start, the tree is obviously empty.  The first value added to the tree is 5.  This gives us the tree shown in Figure~\ref{fig:btree2}.

\begin{figure}[htb]
	\centering
	\begin{tikzpicture}[->,>=stealth',shorten >=1pt,auto,node distance=2cm,thick,main node/.style={circle,fill=white!20,draw,font=\sffamily\Large\bfseries}]
	\node[main node] (5) {5};
	\end{tikzpicture}
	\caption{Binary Tree Start}
	\label{fig:btree2}
\end{figure}

Now let us insert the values 2, 4, 1, and 3 into the tree.  The sequence of steps involved in doing this is shown in Figure~\ref{fig:btree3}.

\begin{figure}[htb]
	\centering
	\begin{subfigure}[t]{0.2\textwidth}
		\begin{tikzpicture}[->,>=stealth',shorten >=1pt,auto,node distance=1.5cm,thick,main node/.style={circle,fill=white!20,draw,font=\sffamily\small\bfseries}]
		\node[main node] (5) {5};
		\node[main node] (2) [below left of=5] {2};
		
		\path[every node/.style={font=\sffamily\small}]
		(5) edge node [left] {} (2)
		;
		\end{tikzpicture}
	\end{subfigure}
	\begin{subfigure}[t]{0.2\textwidth}
		\begin{tikzpicture}[->,>=stealth',shorten >=1pt,auto,node distance=1.5cm,thick,main node/.style={circle,fill=white!20,draw,font=\sffamily\small\bfseries}]
		\node[main node] (5) {5};
		\node[main node] (2) [below left of=5] {2};
		\node[main node] (4) [below right of=2] {4};
		
		\path[every node/.style={font=\sffamily\small}]
		(5) edge node [left] {} (2)
		(2) edge node [right] {} (4)
		;
		\end{tikzpicture}
	\end{subfigure}
	\begin{subfigure}[t]{0.2\textwidth}
		\begin{tikzpicture}[->,>=stealth',shorten >=1pt,auto,node distance=1.5cm,thick,main node/.style={circle,fill=white!20,draw,font=\sffamily\small\bfseries}]
		\node[main node] (5) {5};
		\node[main node] (2) [below left of=5] {2};
		\node[main node] (4) [below right of=2] {4};
		\node[main node] (1) [below left of=2] {1};
		
		\path[every node/.style={font=\sffamily\small}]
		(5) edge node [left] {} (2)
		(2) edge node [left] {} (1)
		    edge node [right] {} (4)
		;
		\end{tikzpicture}
	\end{subfigure}
	\begin{subfigure}[t]{0.2\textwidth}
		\begin{tikzpicture}[->,>=stealth',shorten >=1pt,auto,node distance=1.5cm,thick,main node/.style={circle,fill=white!20,draw,font=\sffamily\small\bfseries}]
		\node[main node] (5) {5};
		\node[main node] (2) [below left of=5] {2};
		\node[main node] (4) [below right of=2] {4};
		\node[main node] (1) [below left of=2] {1};
		\node[main node] (3) [below left of=4] {3};
		
		\path[every node/.style={font=\sffamily\small}]
		(5) edge node [left] {} (2)
		(2) edge node [left] {} (1)
		    edge node [right] {} (4)
		(4) edge node [left] {} (3)
		;
		\end{tikzpicture}
	\end{subfigure}
	\caption{Building the Left Branch}
	\label{fig:btree3}
\end{figure}

Notice the stages of the tree building.  When we add a new value we check if it against each node to see if it should go left or right until we find an empty place to add it.  We will come back to this algorithm shortly.

\subsubsection{Exercise}

Go through the stages of adding the values 6, 8, 9 and 7.  Do you get the same tree as shown in Figure~\ref{fig:btree1}?

\subsection{Getting Started with Binary Trees}

We know enough now to build a binary tree data structure and also some algorithms to enable testing of the binary tree.  First of all, let us consider what a binary tree is in a programming context.  Well a binary tree is just a collection of nodes which have branches to connect them.  These branches connect to other nodes.  Therefore we can consider a node as a data value (the value stored in the node) and pointers to left and right branches.  Figure~\ref{fig:tree-pointers} illustrates the general idea.

\begin{figure}[htb]
    \centering
    \includegraphics{tree-pointers}
    \caption{Data Structure of a Binary Tree}
    \label{fig:tree-pointers}
\end{figure}

Therefore we can define a binary tree as just a node, with pointers to two other nodes.  In code we will define it as follows:

\begin{lstlisting}[caption=Binary Tree Node]
struct node
{
    // Data stored in this node of the tree
    int data;
    // The left branch of the tree
    node *left;
    // The right branch of the tree
    node *right;
};
\end{lstlisting}

Our application is going to perform three different techniques at present:
\begin{enumerate}
    \item Insert a value into the tree
    \item Print the tree \emph{in order}
    \item Free the resources in the tree
\end{enumerate}

This requires us to utilise \emph{recursion} in our code.  We need to treat each branch as a tree, and we just drill down these trees until we get to the bottom.

\begin{framed}
    \textbf{What is Recursion?}
    
    Recursion is one of those ideas in programming that can throw the beginner until they change their way of thinking to accommodate.  Recursion is where we call a function from within itself to allow certain types of computation to occur.  Recursion is very common in algorithmic design, and in particular in functional programming (for those of you doing Mathematics for Software Engineering).
    
    The basic concept is as follows.  Let us look at the Fibonacci number sequence.  It is defined as follows:
    
    \[
    \text{1, 1, 2, 3, 5, 8, 13, 21, 34,} \dots
    \]
    
    Notice that starting from 2, each number is the sum of the two previous ($2=1+1, 3=2+1, 5=3+2$, etc.).  We can generalise this to the following equation:
    
    \[
    F_n = F_{n-1} + F_{n-2}
    \]
    
    With starting values $F_1 = 1$ and $F_2 = 1$.
    
    If we were to write this out as code we would need to use the Fibonacci sequence function to define the Fibonacci sequence.  The pseudocode for this would look as follows:
    
    \begin{algorithmic}
        \Function{fibonacci}{$n$}
        \If{$n = 1$}
        \State \Return $1$
        \ElsIf{$n = 2$}
        \State \Return $1$
        \Else
        \State \Return \Call{fibonacci}{$n - 1$} + \Call{fibonacci}{$n - 2$}
        \EndIf
        \EndFunction
    \end{algorithmic}
    
    As an exercise, use the above functional definition to determine the 10th Fibonacci number.
\end{framed}

Our starting code for the exercises is below.  You should be able to compile and run this code as is at the moment, although it won't do anything.

\begin{lstlisting}[caption=Binary Tree Application Starting Code]
#include <iostream>

using namespace std;

// The node of a tree
struct node
{
    // Data stored in this node of the tree
    int data;
    // The left branch of the tree
    node *left;
    // The right branch of the tree
    node *right;
};

// Inserts a value into the tree - notice **
void insert(node **tree, int value)
{
    // TODO
}

// Deletes the tree - freeing memory
void delete_tree(node *tree)
{
    // TODO
}

// Prints the tree in order
void inorder(node *tree)
{
    // TODO
}

int main(int argc, char **argv)
{
    // Declare the tree - nullptr to a node
    node *tree = nullptr;
    
    // Loop until -1 entered
    while (true)
    {
        int num;
        cout << "Enter number (-1 to exit): ";
        cin >> num;
        
        if (num == -1)
            break;
        insert(&tree, num);
    }
    
    // Print the tree
    inorder(tree);
    cout << endl;
    
    // Delete the tree
    delete_tree(tree);
    
    return 0;
}
\end{lstlisting}

Notice on line 37 we just declare our tree as a pointer to a \texttt{node} which we initially set as \texttt{nullptr}.  This just means that our initial tree is empty.  The rest of the code is to prompt the user for a number to add to the tree and insert it.  If the number entered is -1 we exit the loop, print the tree, then delete it.

Also note that our \texttt{insert} operation takes a pointer-to-pointer.  This is because we will be allocating new \texttt{node} values here.

\subsection{Inserting a Value into a Empty Tree}

Let us start with the simplest idea - inserting a value into an empty tree.  For this first part you are provided with the code:

\begin{lstlisting}[caption=Inserting into an Empty Tree]
// Inserts a value into the tree - notice **
void insert(node **tree, int value)
{
    // Check if nullptr.  If so set new node
    if (*tree == nullptr)
    {
        // Create new node
        *tree = new node;
        // Set new value
        (*tree)->data = value;
        // Set branches to nullptr
        (*tree)->left = nullptr;
        (*tree)->right = nullptr;
    }
}
\end{lstlisting}

Lines 10, 12 and 13 need a little explaining.  As we have a pointer-to-pointer situation, we need to dereference the pointer to access the value.  We could do this twice (\texttt{**tree.data = value}), but we can also use the \emph{pointed to} operator \texttt{->}.  This operator can replace a single dereference and dot.  Therefore the code \texttt{(*tree)->data} is equivalent to \texttt{(**tree).value}.  Good practice in C and C++ normally means we use the pointed to operator when we can.  

\subsubsection{Exercise}

You should be able to run the application now and add a single item to the tree.  Try this now.  At the moment you cannot really see if it worked, but you are checking that the application compiles and runs correctly.

\subsection{Challenge 1 - Printing In Order}

The \texttt{inorder} function allows the printing of the tree data in numerical order.  This will allow use to test our application.  The pseudocode for this operation is given below.  Note the use of recursion.

\begin{algorithmic}
    \Procedure{inorder}{$tree$}
    \If{$tree \neq nullptr$}
    \State \Call{inorder}{\emph{left branch}}
    \State \Call{print}{\emph{value}}
    \State \Call{inorder}{\emph{right branch}}
    \EndIf
    \EndProcedure
\end{algorithmic}

Your challenge here is to implement this algorithm and then use it to test the insertion we build above.

\subsection{Challenge 2 - Inserting into a Non-Empty Tree}

Now let us expand the \texttt{insert} operation to deal with non-empty trees.  The complete algorithm for \texttt{insert} is given below.  Note the use of recursion.

\begin{algorithmic}
    \Procedure{insert}{$tree$, $value$}
    \If{$tree = nullptr$}
    \State \emph{Create new tree}
    \State $data \gets value$
    \State \emph{Set left and right branches to nullptr}
    \Else
    \If{$value < data$}
    \Comment{is less than this node - go left}
    \State \Call{insert}{\emph{left branch}, $value$}
    \ElsIf{$value > data$}
    \Comment{is greater than this node - go right}
    \State \Call{insert}{\emph{right branch}, $value$}
    \Else
    \Comment{is equal to this node - ignore}
    \State \Return
    \EndIf
    \EndIf
    \EndProcedure
\end{algorithmic}

When this is working and you test your application you will be able to enter as many numbers as you like.  When \texttt{inorder} is called the numbers entered are printed in numerical order.

\subsection{Challenge 3 - Freeing Resources}

OK, we have been avoiding freeing up our memory and this is bad.  Let us rectify this by completing the \texttt{delete\_tree} operation.  The pseudocode for this is below.  Again, notice the recursion.

\begin{algorithmic}
    \Procedure{delete\_tree}{$tree$}
    \If{$tree = nullptr$}
    \State \Return
    \EndIf
    \State \Call{delete\_tree}{\emph{left branch}}
    \State \emph{Delete left branch}
    \State \Call{delete\_tree}{\emph{right branch}}
    \State \emph{Delete right branch}
    \EndProcedure
\end{algorithmic}

Again test your application to ensure that you haven't broken anything.

\subsection{Exercises}

The following exercises build on the tree application developed.  Some of these are tricky and will take time to complete.

\begin{enumerate}
    \item There are two other types of order you can print the tree in - \emph{pre-order} and \emph{post-order}.  Pre-order prints the nodes as \emph{current node, left branch, right branch} and post-order prints the nodes as \emph{left branch, right branch, current node}.  Implement these two algorithms and test the application, comparing how the different orders work.
    \item Implement a search function that returns true or false based on whether a value is in the tree.
    \item Modify the tree node to use a \texttt{shared\_ptr} rather than a raw pointer.  What change is needed to the main application?
    \item \textbf{For the Brave} - can you implement a copy operation to copy one tree to another?  There are a number of ways this could be achieved, so try and work one out.  In particular, pre-order and post-order should output the same order for the copied tree.
    \item \textbf{For the Brave} - this one is tricky.  Write an operation that allows the removal of a value from the tree.  This will require you to reconfigure the tree by moving branches between nodes.  There are four cases you need to deal with in your algorithm:
    \begin{enumerate}
        \item No node in the tree contains the data to be removed
        \item The node containing the data has no branches
        \item The node containing the data has one branch
        \item The node containing the data has two branches
    \end{enumerate}
\end{enumerate}