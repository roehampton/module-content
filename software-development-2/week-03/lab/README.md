# Data Sizes and Data Representation

C is often referred to as a systems language as it provides a close approximation to how the computer works. As such, when we declare data in C it has a direct representation in memory. This has advantages when working with memory, but does mean we need to be more cautious in comparison to languages such as Java and C\# (which are often referred to as *managed languages*).

When it comes to working with data in C, we have to understand how data is represented and how to find out the sizes of our data types. Memory size is also an important consideration when worrying about system performance and limitations.

## Getting the Size of Data Using `sizeof`

How big is a value? Well, that does actually depend on the system you are working in and the compiler you are using. In C and C++ we can use the `sizeof` function to get the size of a data type in bytes.

> **The `sizeof` Function**
>
> `sizeof` is a very useful function we will use when we work with memory allocation later in the module. It requires either a type or a value and will return the number of bytes used to represent the type or value.
>
> `sizeof` returns a value of type `size_t`.  Although this type is compiler specific, it is normally of type `unsigned int`.  We will typically just treat it as `int`.

Let us now test the size of the standard `int` type. The following application will print this value out for us.

```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    printf("The size of int is %d bytes\n", sizeof(int));
    return 0;
}
```

Running this application will provide an output similar to the following.

```shell
The size of int is 4 bytes
```

**Depending on the system you are working in you might get a different result**. However, it is pretty standard now that an `int` value is 4 bytes. We will look at what this actually means for maximum and minimum values shortly.

## `unsigned` Data Types

> **`signed` versus `unsigned` Value Representation**
>
> We aren't going to cover this in any great detail -- you covered the concepts of *two's* complement and signed bits in Computer Systems.  Let us consider a simple 8-bit value.  In a signed value, the first bit is the signed bit.  If the first bit is 0, the value is positive:
> `00000000`
>
> If the first bit is 1, the value is negative:
>
> `10000000`
>
> The other 7 bits represent the value of the 8-bit number.  This means that we have two values for `0` -- positive zero and negative zero -- as illustrated in our two examples.

The following application will give you an idea of what happens when we work with `unsigned` values.

```c
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int a = -500;
    unsigned int b = -500;
    unsigned int c = (unsigned int)a;
    float f = -500;

    printf("a signed: %d, a unsigned: %u\n", a, a);
    printf("b signed: %d, b unsigned: %u\n", b, b);
    printf("c signed: %d, c unsigned: %u\n", c, c);
    printf("f signed: %d, f unsigned: %u\n", f, f);
    printf("a == b: %d\n", a == b);
    printf("a == c: %d\n", a == c);
    printf("a == f: %d\n", a == f);
    
    return 0;

}
```

> **Printing `unsigned` Values**
>
> To print a value as `unsigned` with `printf` we use the `%u` placeholder.  This can be combined with other data types to print them as `unsigned`.  We will look at this again shortly.

On line 7 and 8 we declare our `unsigned` values -- on line 7 the value is even set as negative.  Our `printf` statement tries to print all the values as `signed` and `unsigned`.  We also print out if the values are equal.  Running this application provides the following output:

```shell
a signed: -500, a unsigned: 4294966796
b signed: -500, b unsigned: 4294966796
c signed: -500, c unsigned: 4294966796
f signed: 0, f unsigned: 3229564928
a == b: 1
a == c: 1
a == f: 1
```

**Remember that C represents false as 0 and true as any other value -- in this case 1**.

Notice that `printf` treats all the `int` values as if they were the same value.  This is because they have the same bit representation. C has undertaken a rather crude conversion between `signed` and `unsigned` values. The only difference is when we print the `float` value.  `float` values have a different bit representation and therefore when we attempt to print it as a `signed` or `unsigned int` then we get a different result.

Looking at the equality tests though shows us that C does do more work here.  \texttt{a} is shown to be equal to \texttt{f}, although the bit representations are different.  This is because C will attempt to convert the values to the same type.  There are rules that govern this conversion.  You will learn them through practice.

\section{Minimum and Maximum Values of Data Types}

Given that we can work out the size of a data type in bytes using \texttt{sizeof} and know the difference between \texttt{signed} and \texttt{unsigned} values and the overhead of having \texttt{signed} values, we are able to work out the maximum and minimum values of each type.  We could do this by hand, but we would have to do it for every system we compiled our programs for.  This isn't very efficient either.  Thankfully we have the \texttt{limits.h} header file which provides us.

\begin{framed}
\texttt{limits.h}

The \texttt{limits.h} header file contains a collection of different values that define the minimum and maximum values of the standard types.  We will be looking at these shortly.  If you need to know the maximum or minimum of the standard values then include the \texttt{limits.h} header.
\end{framed}

Let us do a quick test of finding out the limits.  Run the following application:

\begin{lstlisting}[caption=Getting Minimum and Maximum Values]
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char **argv)
{
    printf("unsigned int is %d bytes, min value %u, max value %u\n", sizeof(unsigned int), 0, UINT_MAX);
    printf("int is %d bytes, min value %d, max value %d\n", sizeof(int), INT_MIN, INT_MAX);

    return 0;
}
\end{lstlisting}

Notice that for \texttt{unsigned int} we use 0 as the minimum - there is no other minimum defined.  The other values (\texttt{UINT\_MAX}, \texttt{INT\_MIN} and \texttt{INT\_MAX}) are all defined in the \texttt{limits.h} header file.  Running this application will give the following result (based on your system).

\begin{lstlisting}[style=DOS, caption=Output from Min-Max Application]
unsigned int is 4 bytes, min value 0, max value 4294967295
int is 4 bytes, min value -2147483648, max value 2147483647

\end{lstlisting}

So we now know how to get the size of a value and also how to get the minimum and maximum values.  Let us combine these ideas into a single application.

\section{Different Datatypes}

The following application will print the sizes, minimum, and maximum values of the standard C types.  We will use \texttt{float.h} to get the minimum and maximum values of the floating point number types as well.  The application is below.  It also includes pointer values.

\begin{lstlisting}[caption=Displaying Information from Different Datatypes]
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <float.h>

int main(int argc, char **argv)
{
    printf("unsigned char is %d bytes, min value %u, max value %u\n", sizeof(unsigned char), 0, UCHAR_MAX);
    printf("signed char is %d bytes, min value %d, max value %d\n", sizeof(signed char), SCHAR_MIN, SCHAR_MAX);
    printf("char is %d bytes, min value %d, max value %d\n", sizeof(char), CHAR_MIN, CHAR_MAX);
    printf("unsigned short is %d bytes, min value %u, max value %d\n", sizeof(unsigned short), 0, USHRT_MAX);
    printf("short is %d bytes, min value %d, max value %d\n", sizeof(short), SHRT_MIN, SHRT_MAX);
    printf("unsigned int is %d bytes, min value %u, max value %u\n", sizeof(unsigned int), 0, UINT_MAX);
    printf("int is %d bytes, min value %d, max value %d\n", sizeof(int), INT_MIN, INT_MAX);
    printf("unsigned long is %d bytes, min value %lu, max value %lu\n", sizeof(unsigned long), 0, ULONG_MAX);
    printf("long is %d bytes, min value %ld, max value %ld\n", sizeof(long), LONG_MIN, LONG_MAX);
    printf("unsigned long long is %d bytes, min value %llu, max value %llu\n", sizeof(unsigned long long), 0ULL, ULLONG_MAX);
    printf("long long is %d bytes, min value %lld, max value %lld\n", sizeof(long long), LLONG_MIN, LLONG_MAX);
    printf("float is %d bytes, min value %e, max value %e\n", sizeof(float), FLT_MIN, FLT_MAX);
    printf("double is %d bytes, min value %e, max value %e\n", sizeof(double), DBL_MIN, DBL_MAX);
    printf("long double is %d bytes, min value %e, max value %e\n", sizeof(long double), LDBL_MIN, LDBL_MAX);

    // Pointer sizes
    printf("char* is %d bytes\n", sizeof(char*));
    printf("short* is %d bytes\n", sizeof(short*));
    printf("int* is %d bytes\n", sizeof(int*));
    
    return 0;
}
\end{lstlisting}

\begin{framed}
\textbf{More \texttt{printf} Placeholders}

We have introduced two new placeholders for \texttt{printf} this time.  These are as follows:
\begin{description}
\item[\texttt{\%l}] - placed before another placeholder means that we expect a \texttt{long} version of the value (\texttt{signed} or \texttt{unsigned}).  Can be used with another long placeholder for \texttt{long long} values.
\item[\texttt{\%e}] - prints out the value in scientific notation format
\end{description}
\end{framed}

\begin{framed}
\textbf{Why no \texttt{unsigned} Floating Points?}

We have used the floating point values in this application, but we haven't defined any \texttt{unsigned} floating point values.  This is because they don't exist.  This is because the CPU does not support \texttt{unsigned} floating point values, therefore neither does C.  All floating point values are \texttt{signed}.
\end{framed}

Running this application provides the following output:

\begin{lstlisting}[style=DOS, caption=Output from Data Types Application]
unsigned char is 1 bytes, min value 0, max value 255
signed char is 1 bytes, min value -128, max value 127
char is 1 bytes, min value -128, max value 127
unsigned short is 2 bytes, min value 0, max value 65535
short is 2 bytes, min value -32768, max value 32767
unsigned int is 4 bytes, min value 0, max value 4294967295
int is 4 bytes, min value -2147483648, max value 2147483647
unsigned long is 4 bytes, min value 0, max value 4294967295
long is 4 bytes, min value -2147483648, max value 2147483647
unsigned long long is 8 bytes, min value 0, max value 18446744073709551615
long long is 8 bytes, min value -9223372036854775808, max value 9223372036854775807
float is 4 bytes, min value 1.175494e-038, max value 3.402823e+038
double is 8 bytes, min value 2.225074e-308, max value 1.797693e+308
long double is 8 bytes, min value 2.225074e-308, max value 1.797693e+308
char* is 4 bytes
short* is 4 bytes
int* is 4 bytes
\end{lstlisting}

\begin{framed}
\textbf{Pointers and Pointer Sizes}

The pointer values are all 4 bytes in size.  This is because we have been building 32-bit applications.  A 32-bit application uses 32-bit (\emph{4 byte}) values to represent memory locations, and a pointer is just a memory location.  If you calculate the maximum number of addressable memory locations using the standard calculation ($2^{32}$) you end up with 4294967296 bytes - or 4 GB.  You might recognise this as the maximum amount of memory that a 32-bit operating system supports.  It is also the maximum amount of memory that a 32-bit application can allocate.
\end{framed}

Table~\ref{tab:datatypes} provides an overview of the integer data types and their sizes based on our result of running this program using the Microsoft compiler on Windows.  Note that these data sizes are not consistent across other operating systems and compilers.  You should always check your data sizes in the environment you are working in.

\begin{table}[htb]
\centering
\begin{tabularx}{\textwidth}{|l|X|X|X|}
\hline
\textbf{Type} & \textbf{Size (bytes)} & \textbf{Minimum Value} & \textbf{Maximum Value} \\
\hline
\texttt{unsigned char} & 1 & 0 & $2^8 - 1$ \\
\hline
\texttt{signed char} & 1 & $-2^7 -1$ & $2^7 - 1$ \\
\hline
\texttt{unsigned short} & 2 & 0 & $2^{16} - 1$ \\
\hline
\texttt{signed short} & 2 & $-2^{15} - 1$ & $2^{15} - 1$ \\
\hline
\texttt{unsigned int} & 4 & 0 & $2^{32} - 1$ \\
\hline
\texttt{signed int} & 4 & $-2^{31} - 1$ & $2^{31} - 1$ \\
\hline
\texttt{unsigned long} & 4 & 0 & $2^{32} - 1$ \\
\hline
\texttt{signed long} & 4 & $-2^{31} - 1$ & $2^{31} - 1$ \\
\hline
\texttt{unsigned long long} & 8 & 0 & $2^{64} - 1$ \\
\hline
\texttt{singed long long} & 8 & $-2^{63} - 1$ & $2^{63} - 1$ \\
\hline
\end{tabularx}
\caption{Data Sizes, and Minimum and Maximum Values of Integer Types}
\label{tab:datatypes}
\end{table}

\section{Compiling for 64-Bit}

Let us rebuild this application in 64-bit to see what the difference is.  To do this, you have to run a different command prompt.  You will find it under \emph{Visual Studio 2013}, \emph{Visual Studio Tools}.  The command prompt you want is \emph{VS2013 x64 Native Tools Command Prompt}.  From here, it is just the same process as before.  Use \texttt{cl} to compile the applications.  If you run the previous application compiled using the 64-bit compiler you will get the following output:

\begin{lstlisting}[style=DOS, caption=Output from Data Types Application Compiled for 64-bit]
unsigned char is 1 bytes, min value 0, max value 255
signed char is 1 bytes, min value -128, max value 127
char is 1 bytes, min value -128, max value 127
unsigned short is 2 bytes, min value 0, max value 65535
short is 2 bytes, min value -32768, max value 32767
unsigned int is 4 bytes, min value 0, max value 4294967295
int is 4 bytes, min value -2147483648, max value 2147483647
unsigned long is 4 bytes, min value 0, max value 4294967295
long is 4 bytes, min value -2147483648, max value 2147483647
unsigned long long is 8 bytes, min value 0, max value 18446744073709551615
long long is 8 bytes, min value -9223372036854775808, max value 9223372036854775807
float is 4 bytes, min value 1.175494e-038, max value 3.402823e+038
double is 8 bytes, min value 2.225074e-308, max value 1.797693e+308
long double is 8 bytes, min value 2.225074e-308, max value 1.797693e+308
char* is 8 bytes
short* is 8 bytes
int* is 8 bytes
\end{lstlisting}

This time the only difference is the number of bytes allocated to a pointer.  It is now \emph{8 bytes}.  This makes sense - we are using 64-bit code now.  You can work out how much addressable memory this means you have now.

\section{Strings}

We previously discussed how C manages strings of characters in Section~\ref{sec:c-strings}.  Now let us look at how the different methods of creating a string affect the data sizes allocated.  Remember we had a few different methods of declaring a string.  We will look at two separate techniques:

\begin{enumerate}
\item Declaring a pointer to a \texttt{char} - a \texttt{char*}
\item Declaring a fixed size array of \texttt{char} - a \texttt{char[]}
\end{enumerate}

C treats these two approaches in different ways.  Let us write a test application to see what happens:

\begin{lstlisting}[caption=Data Sizes and Strings]
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    // Declare some strings
    char *hello = "Hello World!";
    char goodbye[15] = "Goodbye World!";
    
    // Print the messages
    printf("Hello message: %s\n", hello);
    printf("Goodbye message: %s\n", goodbye);
    
    // Get their size
    printf("Size of hello message: %d bytes\n", sizeof(hello));
    printf("Size of goodbye message: %d bytes\n", sizeof(goodbye));
    
    // Get the size of the data pointed to by the string
    printf("Size of data in hello message: %d bytes\n", sizeof(*hello));
    printf("Size of data in goodbye message: %d bytes\n", sizeof(*goodbye));
    
    // Get the length of the string
    printf("Length of hello message: %d bytes\n", strlen(hello));
    printf("Length of goodbye message: %d bytes\n", strlen(goodbye));
    
    return 0;
}
\end{lstlisting}

\begin{framed}
\textbf{Dereferencing a Pointer}

On lines 20 and 21 we have used the following pieces of code:
\begin{itemize}
\item \texttt{*hello}
\item \texttt{*goodbye}
\end{itemize}

When we use the star (\texttt{*}) in front of a pointer variable, we are asking to \emph{dereference} the pointer.  This means that we want to access the \emph{data} stored in the pointed to memory location rather than just the pointer.  We will be covering pointers later in the module, so you don't have to worry about this idea at the moment.
\end{framed}

Running this application will give you the following output:

\begin{lstlisting}[style=DOS, caption=Output from String Sizes Application]
Hello message: Hello World!
Goodbye message: Goodbye World!
Size of hello message: 4 bytes
Size of goodbye message: 15 bytes
Size of data in hello message: 1 bytes
Size of data in goodbye message: 1 bytes
Length of hello message: 12 bytes
Length of goodbye message: 14 bytes
\end{lstlisting}

Let us look at the 6 sizes output:
\begin{enumerate}
\item Hello message is 4 bytes as it is a pointer to a string of character data.  Remember that a pointer is 4 bytes in size on a 32-bit machine (if you compile this in 64-bit the answer will be 8 bytes).
\item Goodbye message is 15 bytes long.  This is because we have created a fixed size array, which C knows the size of.
\item Size of data in hello is 1 byte.  We have dereferenced the pointer to access the data which is of type \texttt{char}.  Remember that a \texttt{char} is 1 byte in size.
\item Size of data in goodbye is the same as hello.
\item Length of hello is 12 bytes.  The message is 12 \texttt{char} long.
\item Length of goodbye is 14 bytes.  The message is 14 \texttt{char} long
\end{enumerate}

So the same general rules apply to sizing strings as they do to sizing other data types.  The new interesting value is the array size.  \emph{This only works for fixed size arrays}.  We will look at arrays in far more detail as we go through the module, and understand the limitations C and C++ has when working with array data.

\section{Casting Between Types}
\label{sec:casting}

So we have looked at data sizes and we understand how numbers are represented on the machine (to a basic level - \emph{Computer Systems} teaches you more).  So what about converting a number between different types and representations?  Well to do this we use a technique called \emph{casting}.  Casting becomes quite a big concept when we work in object-orientation and we will cover some of these ideas later in the module.  However, let us look at how we cast numbers.

\begin{framed}
\textbf{Casting}

Casting is the operation of converting one type of value to another.  It actually happens all the time when you are programming.  A lot of the time you just don't see it.  We will discuss automatic casting shortly.

To perform a cast we use the following syntax:

\texttt{\emph{type} casted\_value = (\emph{type})original\_value;}

The C compiler will take care of the necessary operations to convert from one type to another if necessary, although sometimes no specific operation occurs.  As an example, if we wanted to convert form a \texttt{int} to a \texttt{float} we would do the following:

\begin{lstlisting}
int x = 10;
float y = (float)x;
// y is now 10.0f
\end{lstlisting}

However, if we performed the same operation trying to convert \texttt{x} to a \texttt{char*} you won't be converting an \texttt{int} to a string:

\begin{lstlisting}
int x = 10;
char *y = (char*)x;
// y now points to memory location 10!!!
\end{lstlisting}

In this instance, an \texttt{int} is converted to a memory location.  Your pointer is now pointing at memory location 10.  This is a piece of memory you cannot manipulate (it will be controlled by the operating system).  If you try and print the data at this memory location your application will crash.
\end{framed}

Casting is a useful operation when working with different number types.  However, it does have its limitations as our test application will explore.  In particular you need to think about what happens when you take a large number (say a \texttt{long long}) and convert it to a shorter number (say a \texttt{short}).  What happens to the data that is lost?  What does the number become?  Our test application will examine this.

\begin{lstlisting}[caption=Casting Between Types]
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char **argv)
{
    // Let's start with a unsigned char
    unsigned char c = UCHAR_MAX;
    printf("Value is %d\n", c);
    // Cast to signed char
    printf("As signed char %d\n", (char)c);
    // Cast to a short
    printf("As short %d\n", (short)c);
    // Cast to a int
    printf("As int %d\n", (int)c);
    // Cast to a long
    printf("As long %ld\n", (long)c);
    // Cast to long long
    printf("As long long %lld\n", (long long)c);
    
    // Now try a long long
    long long l = LLONG_MAX;
    printf("Value is %lld\n", l);
    // Cast to long
    printf("As long %lld\n", (long)l);
    // Cast to int
    printf("As int %lld\n", (int)l);
    // Cast to short
    printf("As short %lld\n", (short)l);
    // Cast to char
    printf("As char %lld\n", (char)l);
    
    // Now with a float
    float f = 555.5555f;
    printf("Value is %f\n", f);
    // Cast to char
    printf("As char %d\n", (char)f);
    // Cast to short
    printf("As short %d\n", (short)f);
    // Cast to int
    printf("As int %d\n", (int)f);
    
    return 0;
}
\end{lstlisting}

Running this application will give you the following output:

\begin{lstlisting}[style=DOS, caption=Output from Casting Application]
Value is 255
As signed char -1
As short 255
As int 255
As long 255
As long long 255
Value is 9223372036854775807
As long -1
As int -1
As short -1
As char -1
Value is 555.555481
As char 43
As short 555
As int 555
\end{lstlisting}

For our \texttt{unsigned char} value, we first convert it to a \texttt{signed char}.  This makes it -1!  What has happened here?  Well, a \texttt{signed char} has a maximum value of 127 with a signed bit.  This is represented by the following binary string:

0111 1111

For a \texttt{unsigned char} the value 255 is represented by the following binary string:

1111 1111

When converting this second binary string to a \texttt{signed char}, using standard negative number conversion (remember your \emph{Computer Systems} work) this gives as -1.  Every other data value is large enough to take the binary digits.  Table~\ref{tab:conversion} illustrates how the number is represented in binary for each of the different data types.  It also shows how C converts the numbers (very trivially for \texttt{int} types). 

\begin{table}[htb]
\centering
\begin{tabularx}{\textwidth}{|l|X|X|}
\hline
\textbf{Type} & \textbf{Binary String} & \textbf{Value} \\
\hline
\texttt{unsigned char} & 1111 1111 & $255$ \\
\hline
\texttt{signed char} & 1111 1111 & $-127$ \\
\hline
\texttt{short} & 0000 0000 1111 1111 & $255$ \\
\hline
\texttt{int} & 0000 0000 0000 0000 0000 0000 1111 1111 & $255$ \\
\hline
\texttt{long} & 0000 0000 0000 0000 0000 0000 1111 1111 & $255$ \\
\hline
\texttt{long long} & 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 1111 1111 & $255$ \\
\hline
\end{tabularx}
\caption{Converting \texttt{unsigned char} 255 to Other Types}
\label{tab:conversion}
\end{table}

When we go in reverse we are converting the \texttt{long long} value 9223372036854775807 (all binary digits 1).  In this instance we just remove binary digits until we reach the desired size.  As we are dealing with signed values this equates to -1 in each instance.

\begin{table}[htb]
\centering
\begin{tabularx}{\textwidth}{|l|X|X|}
\hline
\textbf{Type} & \textbf{Binary String} & \textbf{Value} \\
\hline
\texttt{long long} & 0111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 & $9223372036854775807$ \\
\hline
\texttt{long} & 1111 1111 1111 1111 1111 1111 1111 1111 & $-1$ \\
\hline
\texttt{int} & 1111 1111 1111 1111 1111 1111 1111 1111 & $-1$ \\
\hline
\texttt{short} & 1111 1111 1111 1111 & $-1$ \\
\hline
\texttt{char} & 1111 1111 & $-1$ \\
\hline
\end{tabularx}
\caption{Converting \texttt{long long} 9223372036854775807 to Other Types}
\label{tab:conversion2}
\end{table}

For the \texttt{float} conversions more work is done since a \texttt{float} is not represented in this way in binary.  Floating point conversion is therefore more likely to convert to a close approximation of the value required, although note that numbers are not rounded up but down.  The conversion to \texttt{char} follows standard binary conversion which is why the value is 43.  This is because C number conversion with floating point values follow certain rules:
\begin{itemize}
\item Find the smallest data type that the values will convert into with enough bits to get the entire value
\item Convert value to common data type
\item Convert to target data type
\end{itemize}

So, for example, the conversion from \texttt{float} to \texttt{char} is as follows:
\[
float \Rightarrow int \Rightarrow char
\]

Or in binary:
\[
\text{binary float} \Rightarrow \text{0000 0000 0000 0000 0000 0010 0010 1011} \Rightarrow \text{0010 1011}
\]

Value conversion is an important idea to grasp, and in particular when we move onto object-oriented programming with C++.  C does support more complex data types as well using the \texttt{struct} keyword.  Let us look at that next.

\section{Defining \texttt{struct}s}

Having simple data types only provides us with so much capability.  In the real world we want to construct more complex data types to support our applications.  We do this using the \texttt{struct} keyword.  A \texttt{struct} is just a collection of values that we consider as a single value.

\subsection{A \texttt{struct} in Memory}

Let us consider a simple example that we will use in our test application.  This \texttt{struct} will contain student details, and we define it as follows:

\begin{lstlisting}
struct student
{
    unsigned int matric;
    char *name;
    char *address;
};
\end{lstlisting}

The student data type contains three values:
\begin{itemize}
\item A \texttt{unsigned int} used to represent the matriculation number of the student
\item A \texttt{char*} (string) used to represent the student's name
\item A \texttt{char*} (string) used to represent the student's address
\end{itemize}

We treat an variable of type \texttt{student} more or less as a normal data type, with some exceptions that we will cover shortly.  First let us consider how a value of type \texttt{student} is stored in memory. Figure~\ref{fig:student-mem} illustrates how the bytes are laid out to store the \texttt{student struct}.

\begin{figure}[htb]
\small
\centering
\begin{tabular}{|c|c|}
\hline
\textbf{Byte} & \textbf{Data} \\
\hline
0 & matric \\
\hline
1 & matric \\
\hline
2 & matric \\
\hline
3 & matric \\
\hline
4 & name \\
\hline
5 & name \\
\hline
6 & name \\
\hline
7 & name \\
\hline
8 & address \\
\hline
9 & address \\
\hline
10 & address \\
\hline
11 & address \\
\hline
\end{tabular}
\caption{\texttt{student struct} Represented in Memory}
\label{fig:student-mem}
\end{figure}

As can be seen, our data takes 12 bytes of storage, and is stored in the sequence of its declared member values.  There is no additional overhead in C or C++ for storing data in a \texttt{struct}.  We are just stating that a variable is of that type, and therefore the number of required bytes are stored.

\subsection{Accessing \texttt{struct} Members}

To access a value in a \texttt{struct} we use the dot notation (\texttt{.}) to allow us to access members of the \texttt{struct}.  This is the same notation you are likely to remember from using Java.  This is a simple method to allow us to use a variable name and the name of the member to access its value:

\texttt{variable.member\_name}

We can get and set the member using this technique.  We will explore these concepts far more later in the module.

\subsection{Declaring a \texttt{struct} Variable}

In C (not C++ as we will discover later in the module), we declare a variable of a \texttt{struct} type as follows:

\texttt{struct <type> <name>;}

It is much the same as a standard variable declaration, except that we have to place the keyword \texttt{struct} in front of the type.  Otherwise, we have declared the variable as normal, and can access the values accordingly.

\subsection{Passing \texttt{struct} Values as Parameters}

As when declaring a \texttt{struct} variable we must also use the keyword \texttt{struct} when passing as a parameter.  Again this is only in C.  Basically a parameter pass is the same as declaring a variable for the function.  It is just that we are providing that variable when we call the function.

\subsection{\texttt{struct} Test Application}

Our test application for working with \texttt{struct} data types is below.  We are using our \texttt{student} data type, setting the values, and then printing the data type.

\begin{lstlisting}[caption=A First \texttt{struct} Example]
#include <stdio.h>
#include <stdlib.h>

// A data structure containing student information
struct student
{
    unsigned int matric;
    char *name;
    char *address;
};

// Prints student information
void print_student(struct student s)
{
    printf("matric no: %u\n", s.matric);
    printf("name: %s\n", s.name);
    printf("address: %s\n", s.address);
}

int main(int argc, char **argv)
{
    // Output size of the struct
    printf("Size of student struct is %d bytes\n", sizeof(struct student));
    // Create a student data structure
    struct student s;
    s.matric = 42001290;
    s.name = "Kevin Chalmers";
    s.address = "School of Computing";
    // Print student data
    print_student(s);
    
    return 0;
}
\end{lstlisting}

On line 23 we print the size of the \texttt{student struct}.  Based on what we know about the value we should be able to work this out:
\begin{itemize}
\item the \texttt{matric} value is an \texttt{unsigned int} which is 4 bytes in size
\item the \texttt{name} value is a \texttt{char*} which is 4 bytes in size
\item the \texttt{address} value is a \texttt{char*} which is 4 bytes in size
\end{itemize}

Thus our \texttt{student} value should be 12 bytes in size.  Running this application (below) shows that this is the case.

\begin{lstlisting}[style=DOS, caption=Output from \texttt{struct} Application]
Size of student struct is 12 bytes
matric no: 42001290
name: Kevin Chalmers
address: School of Computing
\end{lstlisting}

Building complex data types that represent our real world data is very important.  We will investigate this further when we look at object-orientation later in the module.  However, we will use \texttt{struct} data occasionally from this point onwards.

\section{\texttt{enum} Values and \texttt{case} Statements}

Another data type we can declare is an \texttt{enum}.  An \texttt{enum} allows us to declare a collection of options that a value could take.  This is very useful for having easily read (to the programmer) code for ideas such as menu entries and system states.  An \texttt{enum} can replace a numerical value for this case.

An example \texttt{enum} declaration is given below:

\begin{lstlisting}
enum CHOICE
{
	EXIT = 0,
	HELLO = 1,
	GOODBYE = 2
};
\end{lstlisting}

Notice that we can also attach numerical values to our \texttt{enum} (although this is not required).  To declare a variable of this type we just do the following:

\begin{lstlisting}
CHOICE ch;
\end{lstlisting}

We can then set the value of this variable as follows:

\begin{lstlisting}
ch = HELLO;
\end{lstlisting}

\texttt{enum} values are about making your code easier to understand.  They are especially useful when working with \texttt{case} statements.  Underneath, an \texttt{enum} is just an \texttt{int} value.  We are simply adding some \emph{syntactic sugar} to our code to make it easier for others to understand.  A simple test application using \texttt{enum} and \texttt{case} is given below:

\begin{lstlisting}[caption=Declaring and Using \texttt{enum} Values]
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Defines the menu choices
enum CHOICE
{
	EXIT = 0,
	HELLO = 1,
	GOODBYE = 2
};

int main(int argc, char **argv)
{
    int flag = 1;
    while (flag)
    {
        // Print menu
        printf("1 - say hello\n");
        printf("2 - say goodbye\n");
        printf("0 - exit\n");
        printf("Enter choice - ");
        // Read input
        char buffer[10];
        fgets(buffer, 10, stdin);
        // Convert to CHOICE
        enum CHOICE ch = atoi(buffer);

        // Work on input
        switch (ch)
        {
            case HELLO:
                printf("Hello World!\n");
                break;
            case GOODBYE:
                printf("Goodbye World!\n");
                break;
            case EXIT:
                printf("Exiting...\n");
                flag = 0;
                break;
            default:
                printf("*** INVALID INPUT ***\n");
                break;
        }
    }
    
    return 0;
}
\end{lstlisting}

Running this application can give you an output as follows:

\begin{lstlisting}[style=DOS, caption=Output from Menu Application]
1 - say hello
2 - say goodbye
0 - exit
Enter choice - 1
Hello World!
1 - say hello
2 - say goodbye
0 - exit
Enter choice - 2
Goodbye World!
1 - say hello
2 - say goodbye
0 - exit
Enter choice - 3
*** INVALID INPUT ***
1 - say hello
2 - say goodbye
0 - exit
Enter choice - 0
Exiting...
\end{lstlisting}

As you can see, \texttt{enum} values are very useful for working with menu like applications.  You should consider using them whenever possible to make your code easier to read.

\section{\texttt{const}}

We now know how to declare values in C.  \texttt{struct} and \texttt{enum} is all C really provides in this regard.  Let us now move onto examining other type modifiers.  The first one we will look at is \texttt{const}.  A \texttt{const} value is one that cannot be changed - it has a \emph{constant} value.

To declare a \texttt{const} value we just put the \texttt{const} keyword before the variable type:

\texttt{const <type> <name>;}

This can be used for variable declaration and for passing parameters into functions.  Below is an example program that tries to modify a \texttt{const} value.

\begin{lstlisting}[caption=Working with Constants]
#include <stdio.h>
#include <stdlib.h>

// Constant global value
const int x = 500;

void func(const int i)
{
    // Print the constant
    printf("i = %d\n", i);
    // Change value of i - compiler error
    i = 50;
}

int main(int argc, char **argv)
{
    // Print the constant
    printf("x = %d\n", x);
    // Call func with 50
    func(50);
    // Change value of x - compiler error
    x = 200;

    return 0;
}
\end{lstlisting}

Trying to compile this application will give a compiler error as shown below:

\begin{lstlisting}[style=DOS, caption=Compiler Error from Trying to Modify \texttt{const} Values]
Microsoft (R) C/C++ Optimizing Compiler Version 18.00.30501 for x86
Copyright (C) Microsoft Corporation.  All rights reserved.

constants.c
constants.c(12) : error C2166: l-value specifies const object
constants.c(22) : error C2166: l-value specifies const object
\end{lstlisting}

If you look at the code file you will see that it is lines 12 and 22 (as noted in the compiler error) that are at fault.  We are trying to modify a \texttt{const} value.  The error essentially states that the left hand side of the expression (the \emph{l-value}) is \texttt{const}.

\section{\texttt{static} Values}

Another type modifier that we can apply to our variables in C is \texttt{static}.  A \texttt{static} value is one that exists throughout the execution of the application.  This is especially useful for functions, where we declare variables for use in the function which only normally exist while that function is being used.  \texttt{static} allows a variable to retain its value after the function has ended.  A \texttt{static} value is one that has runtime context rather than just the standard context.  We will look at context and variable lifespan later in the module.

For just now, try the following example application.  It illustrates the basic idea of using a \texttt{static} value.

\begin{lstlisting}[caption=Using \texttt{static} Variables, label=lst:static]
#include <stdlib.h>
#include <stdio.h>

void func()
{
    // Define static value
    static int x = 0;

    // Print value of x
    printf("x = %d\n", x);
    // Increment x
    x = x + 1;
}

int main(int argc, char **argv)
{
    // Call func 100 times
    for (int i = 0; i < 100; ++i)
        func();

    return 0;
}
\end{lstlisting}

Running this application provides the following output (suitably truncated):

\begin{lstlisting}[style=DOS, caption=Output from \texttt{static} Application]
x = 0
x = 1
x = 2
x = 3

....

x = 97
x = 98
x = 99
\end{lstlisting}

Using \texttt{static} variables like this is not that common, but it can be useful occasionally.  Object-orientation overcomes this requirement as we will find later.

\section{Make Files}

We will end this unit by looking at make files.  A make file is a handy method of building applications by containing all the necessary instructions in a single file, rather than typing them in the command line each time.

To use a make file with Microsoft tools you have to create a file called \texttt{makefile} (note no file extension).  This file contains the necessary instructions.  We use a tool called \texttt{nmake} to perform the build operation for us.  \texttt{nmake} looks at the \texttt{makefile} and determines which particular build we want to perform.  We call \texttt{nmake} as follows:

\begin{lstlisting}[style=DOS, caption=Running the \texttt{nmake} Command]
nmake <what?>
\end{lstlisting}

Just now, you should create a \texttt{makefile} file.  Let us look at what we need to add to undertake a build.

\subsection{Simple Make File}

Below is a simple \texttt{makefile} command to build our initial \texttt{hello.c} file:

\begin{lstlisting}[style=makefile, caption=Simple makefile Example]
hello:
	cl hello.c
\end{lstlisting}

The first line is our build we can undertake.  We put a colon after the build name.  After this we list the operations we want to undertake.  In this instance we call \texttt{cl} on \texttt{hello.c}.  Simple.  Modify your \texttt{makefile} to contain these instructions and save.

We can now call \texttt{nmake} stating we want to undertake the \texttt{hello} build.  We do this as follows, with the output given also.

\begin{lstlisting}[style=DOS, caption=Building \texttt{hello.c} Using \texttt{nmake}]
nmake hello

Microsoft (R) Program Maintenance Utility Version 12.00.21005.1
Copyright (C) Microsoft Corporation.  All rights reserved.

        cl hello.c
Microsoft (R) C/C++ Optimizing Compiler Version 18.00.30501 for x86
Copyright (C) Microsoft Corporation.  All rights reserved.

hello.c
Microsoft (R) Incremental Linker Version 12.00.30501.0
Copyright (C) Microsoft Corporation.  All rights reserved.

/out:hello.exe
hello.obj
\end{lstlisting}

And it is as simple as that.  You might be asking yourself \emph{what is the point in that?}.  Well, we can perform more than one instruction as part of the build, and it also allows us to store our build configurations in a file so we don't have to remember how to perform the build.  This will become important as we build more complex applications.  \emph{You should start writing make files from now on.}  In fact, you are required to use them for your assessment.

\subsection{Building All}

Another handy part of make files is that we can combine multiple build operations into a single build operation.  This is quite common to allow us to split a build into separate parts and combine them together into a single overall build operation.  We can also use it to build all the applications we have developed in one operation.

Below is an example of a \texttt{makefile} that builds all the applications by combining a collection of other builds.  You should add all the necessary build configurations to your \texttt{makefile} and an \texttt{all} configuration also.

\begin{lstlisting}[style=makefile, caption=makefile Code for All]
all: sizeof unsigned minmax datatypes

sizeof:
	cl sizeof.c
	
unsigned:
	cl unsigned.c
	
minmax:
	cl minmax.c
	
datatypes:
	cl datatypes.c
\end{lstlisting}

To build all we simply call \texttt{nmake} with the \texttt{all} configuration as shown below.

\begin{lstlisting}[style=DOS, caption=Building All Applications with \texttt{nmake}]
nmake all
\end{lstlisting}

\subsection{Cleaning Up}

A final useful build configuration to have in all your make files is a clean.  A \texttt{clean} configuration deletes all the files generated during your builds.  This can help you tidy up any temporary files you don't need to store.  A \texttt{clean} configuration is shown below:

\begin{lstlisting}[style=makefile, caption=makefile Code for Cleaning]
clean:
	del *.obj
	del *.exe
	del *.asm
\end{lstlisting}

Make files are an important idea to understand, and you should get in the habit of creating and updating make files as you develop your applications.  It will make life easier for you in the long run and it will allow you to understand the build process in more detail.

\section{Exercises}

\begin{enumerate}
\item Create the necessary make file(s) for all the applications you have developed thus far.  Test it out to ensure that your builds work correctly, and that you have captured all the necessary configurations, including cleaning.
\item Write an application that adds 1 to the maximum value of the standard data types and subtracts 1 from the minimum.  Your application should print out the values that you have after performing these operations.
\item Write an application that has a menu system using an \texttt{enum} and \texttt{case} statement which provides the ability to enter a student's details, print the student's details, or exit the system.  Your application should only have one student variable in existence.  It should just overwrite the existing details when a new student is entered.
\item Develop another menu based application which asks the user if they want to print out a triangle, a Christmas tree, or their name surrounded by stars.  It should prompt the user for the size of the triangle / tree or their name based on the choice selected.  You should use functions to simplify your application.
\end{enumerate}