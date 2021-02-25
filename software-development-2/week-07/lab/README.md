# Software Development 2 Lab 07 -- Introduction to C++ and Calling Conventions

In this unit we are going to look at how we work with functions / operations in more detail. We are interested in how our variables are transferred and used by our functions / operations.  This involves our first major investigation into what a pointer is and what a reference is.  The former concept becomes very important when we look at memory management in the next unit.  To use the latter concept, we need to change the language we are using to C++.  This is the language we will use from now on.

## The C++ Programming Language

C++ was first developed in the late 1970s / early 1980s.  It is considered a successor or the next step (hence the ++) to C.  As such, everything you have done up until this moment in C works in C++.  C++ just adds some new constructs to make our life *a lot* easier.  One of the major differences between C and C++ is that C++ has *object-orientation* (like Python, Java and C\#).  We won't look at object-orientation in C++ until a few units, but we already introduced some of the basic ideas with C `struct`s.

As with everything, describing a programme language doesn't tell you as much as actually using the language.  With that in mind let us move onto a simple *Hello World* example.  *From this point onwards you should consider that every piece of code we provide as an example is C++*.

### Hello World in C++

Our *Hello World* example is given below.  The extension of a C++ file is `.cpp`.  On Windows, `cl` is both a C and C++ compiler. **On Linux and MacOS you will have to use `g++` and `clang++` respectively.** **Save the following code as `hello.cpp` and run it**.

```cpp
#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char **argv)
{
    cout << "Hello, world!" << endl;
    return 0;
}
```

OK, we have a couple of new ideas here.  First, the include file.  Here we are including the file `iostream` (note no `.h`).  This is part of the standard C++ library and provides some basic input-output mechanisms (such as command line input-output).  The header name is an abbreviation of *input-output streams*.

On line 3 and line 4 we state which parts of `iostream` we are using -- `std::cout` and `std::endl` both in the `std` namespace (library). On line 8 we have our *print* statement -- and this will look very strange to new C++ programmers.  First of all, let us describe the two objects being used:

- `cout` -- this is the command line (we stated we were using this with `using std::cout`. `cout` can be interpreted as *Console OUTput*.
- `endl` -- this is a new line character supported by the operating system. `endl` can be interpreted as *END Line*.

Now the new operators.  We are using the operator `<<` which is known as the *stream output* operator.  You can read the entire command as *to the console stream `"Hello, world!"` then an end line*.  There is an equivalent *stream input* operator (`>>`) which you should look at in an exercise soon.

## Working with `string` in C++

We spent a fair bit of time working with character strings in C.  In particular, we looked at how strings are represented in C, how this can cause issues, and how we operate on strings.  In C++ we have a `string` type which makes our life *a lot* easier.  Underneath this `string` type there is still a `char*` -- we just don't need to interact with it directly.  The `string` type is provided in the `string` header in C++ (note again no `.h`).

As an example application, let us rebuild our command line example in C++.  The code is below:

```cpp
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main(int argc, char **argv)
{
    string command = "";
    // Loop round command lines, appending to the string
    for (int i = 0; i < argc; ++i)
        command += string(argv[i]) + string(" ");
    // Print the command line
    cout << command << endl;
    // Print out the length of the string
    cout << "Command line is " << command.size() << " characters long" << endl;
    return 0;
}
```

Here we are using the `string` object.  As with `cout`, `string` is part of the *Standard Library* namespace (hence the `std::` part).

Let us look at some of these lines in more detail:

- Line 2 -- here we have included the \texttt{string} header file
- Line 10 -- we declare an initial `string` with no text.  Notice we can initialise a C++ `string` as we did with strings in C using `""`.  Consider this a string initializer for C based languages.
- Line 13 -- here we join the `string` objects together.  Notice that we can just use the `+` operator to do this.  The `+` operator concatenates `string` objects together.  Line 13 effectively says *Add to command (the `+=` part) the next command line argument and a space.*
- Line 15 -- here we print the command line string using `cout`.  Note that `cout` will happily stream a `string` object for us.
- Line 15 -- here we print the length of the `string` object.  Note that we can get that by calling the `size` method on the `string` object.  The `string` maintains its length for us so we can call the `size` method to access the value.
- Line 15 -- also note here that we are streaming multiple values to `cout`.  This allows us to create more complicated outputs if we need to.

### Exercise

Write the equivalent C++ application for reading in a name and saying hello to the person.  You will need to use the stream input operator and a `string` object.  The other object you need is `cin` (*Console INput*).  To give you some guidance in how to structure the statement use the following:

*From console input read into name* (where *name* is the `string` you are reading into).

## Accessing Raw String from C++ `string`

We can rewrite the above application by accessing the raw C string and then calling `printf` (therefore mixing C and C++).  This code is shown below:

```cpp
#include <cstdio>
#include <string>

using std::string;

// A function that will print a C string
void print(const char *str)
{
  printf("%s\n", str);
}

int main(int argc, char **argv)
{
  // Declare an empty string
  string command = "";
  // Loop round command lines, appending to the string
  for (int i = 0; i < argc; ++i)
  {
    command += string(argv[i]) + string(" ");
  }
  // Get the C string (raw string) from the C++ string
  const char *str = command.c_str();
  // Call print
  print(str);

  return 0;
}
```

We are combining a few different ideas here.  Let us look at these in turn:

- Line 1 -- here we are including the `cstdio` header (again no `.h`).  This header provides C++ with access to the functionality provided in the C `stdio.h` header.
- Line 7 -- we have declared a function that will print the value.  Notice the use of `const` here.  We are stating that the value in the `char*` will not change.  We will be looking at `const` in more detail later in the unit.
- Line 9 -- we are calling the standard `printf` function from C in our C++ code.  As stated previously this is perfectly acceptable.
- Line 22 -- this is where we are accessing the raw C string from our C++ `string` object.  This is done using the `c_str` method on `string`.  Note the return type -- it is a `const char*`.  This is because you should not be modifying this value outside of the `string` object -- hence it is a `const`.  The value you have (the pointer to a location in memory) points to the exact same location as the `string` object is storing its `char*`.

In general we don't have to write code that accesses the raw C string of a C++ `string`.  However, you might find that sometimes you are working with a predominantly C based library or framework (for example OpenGL, OpenCL, CUDA, etc.) and you want to have the simplicity of C++ `string` objects but have to give the relevant function calls `char*`.  The access to `c_str` provides this.

The output from this application should be the same as the previous application.

## Reading Input from the Command Line with `cin`

You should have attempted this in an exercise already, so hopefully nothing here is that new.  Just in case though, let us see how we capture input from the command line in C++. 

```cpp
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main(int argc, char **argv)
{
    // Declare strings to store name
    string first_name;
    string last_name;
    string full_name;

    // Prompt for first name
    cout << "Please enter your first name: ";
    // Read in first_name using cin
    cin >> first_name;
    
    // Check if your name is Kevin
    if (first_name == "Kevin")
    {
        cout << "Hey! Another Kevin\n";
    }
    else
    {
        cout << "Oh well\n";
    }
    
    // Output number of characters entered
    cout << "You entered " << first_name.length() << " characters" << endl;
    // Prompt for last name
    cout << "Please enter your last name: ";
    cin >> last_name;
    // Output number of characters entered
    cout << "You entered " << last_name.length() << " characters" << endl;
    
    // Join the strings
    full_name = first_name + string(" ") + last_name;
    
    // Print name
    cout << "Your full name is " << full_name << " which is ";
    cout << full_name.length() << " characters long" << endl;;
    
    return 0;
}
```

Let us look at some of these lines, particularly where we have done things differently:

- Lines 12 - 14 -- declare the C++ `string` objects we are going to use
- Line 19 -- we read in from `cin` the `first_name` value using the stream input (`>>`) operator
- Line 22 -- we perform a string comparison.  Note now we can just use the standard equality operator (`==`) rather than calling a function to compare.  The equality operator will perform the same process
- Line 32 -- we use the `length` method to get the length of the string.  This will return the same value as `size` and therefore is interchangeable.

As you can see, working with input-output and strings is easier in C++ than C.  This is one of the benefits of having object-orientation.  We can operate on our data more effectively and therefore reduce our code.

## Using `getline` to Read Lines of Text

OK, this is our final example of working with the C++ `string` object before moving onto the main point of this unit.  Here we are going to use a nice helper function provided in the C++ Standard Library known as `getline`.  This function allows us to read an entire line from an input stream until we encounter the newline character.  This allows us to work around the problem of having space characters in our input streams.  The example application is below.  It simply prompts for and reads in someone's full name.

```cpp
#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::getline;
using std::endl;

int main(int argc, char **argv)
{
    // Declare string to store name
    string full_name;

    // Prompt for name
    cout << "Please enter your full name: ";
    // Read in full_name using cin and getline
    getline(cin, full_name);
    
    // Print name
    cout << "Your full name is " << full_name << " which is ";
    cout << full_name.length() << " characters long" << endl;;
    
    return 0;
}
```

Line 18 is where we are using the `getline` function.  Notice is takes two parameters:

1. the stream to read from.  This could be the command line, a file, or something similar
2. the `string` to read into

**Compile and run this application to get an idea of the result**.  You should understand everything else about this code by now.

## Passing by Value (Copying Data)

With that short tour of C++ focusing on command line interaction and strings we are ready to move onto the main focus of this unit -- how values are passed to functions / operations in C and C++.  This is where we have to start understanding a little about how values are passed as parameters, and our initial introduction to the stack in the *Inline Assembly* unit will help us here.

Over the next few sections we are going to look at the three techniques for passing a value as a parameter to a function / operation.  There are as follows:

- Passing a value by copying it to the function / operation (*pass-by-value*)
- Passing a value by providing a reference to the function / operation (*pass-by-reference*)
- Passing a value by providing a pointer to the function / operation (*pass-by-pointer*)

The first technique we will look at is pass-by-value.  This is the technique we have been using in most cases up until now.  This technique involves creating a copy of our value(s) and giving them to the function / operation.  This means that anything the function / operation does with the value is not reflected in the caller.

With that in place, let us look at our pass-by-value application.  This is below.

```cpp
#include <iostream>

using std::cout;
using std::endl;

void foo(int x)
{
    cout << "Start of function, x = " << x << endl;
    x = 20;
    cout << "End of function, x = " << x << endl;
}

int main(int argc, char **argv)
{
    int x = 10;
    cout << "Before function call, x = " << x << endl;
    foo(x);
    cout << "After function call, x = " << x << endl;
    return 0;
}
```

There is nothing unusual or new in this application.  The idea we are trying to examine is what is happening in memory and with the variables.  We have already covered the stack, and we have mentioned the stack pointers (that tell us the bottom and top of the stack).  With that in mind, we can visualise what is happening in our application as shown in Figure~\ref{fig:pass-by-value}.

![pass-by-value](pass-by-value.png)

To start with we have our value that is declared in our main application.  This is the value at the bottom of the pointer.  When we call the function, we push a copy of \texttt{x} onto the stack (let us assume that there is something else on the stack between our two \texttt{x} values).  When we change the value of \texttt{x} in the function, only the function's copy is modified.  The original value (at the bottom of the stack) is unaffected. Therefore, when the function exits, this change has been lost.

Running this application will give an output as shown below:

\begin{lstlisting}[style=DOS, caption=Output from Pass-by-Value Application]
Before function call, x = 10
Start of function, x = 10
End of function, x = 20
After function call, x = 10
\end{lstlisting}

\begin{framed}
\textbf{Scope (yet again)}

Basically we are looking at scope here again.  The scope of the main application is different than the scope of the function.  As such, any variables that are \emph{not references or pointers} will be copies, and be different in each scope.  Our work in pass-by-reference and pass-by-pointer allows us to overcome scoping limitations such as these.
\end{framed}

## \section{Passing by Reference}

Now let us move onto working with \emph{pass-by-reference}.  This technique allows us to avoid passing a copy of a value to a function / operation but rather pass a \emph{reference} to the value.  This means that the function / operation is directly accessing the same value as the caller of the function.

When it comes to calling a function / operation that uses pass-by-reference, you as the caller of the function / operation has to do nothing different.  It is the function / operation that declares that is taking in a reference to a value.  It does this by declaring a parameter as a reference using the \emph{reference-type} specifier.  This is the ampersand (\texttt{\&}) character.  For example, to pass a parameter using pass-by-reference we would declare our function / operation as follows:

\begin{lstlisting}
return-type function-name(parameter-type &name) { ... }
\end{lstlisting}

Any type can have the \emph{reference-type} specifier added to it.  For example, a reference to a \texttt{char} is of type \texttt{char\&}.  An \texttt{int} is of type \texttt{int\&}.  And so on.

\begin{framed}
\textbf{The \texttt{\&} Specifier and the \texttt{\&} Operator}

We are now getting into one of the areas that can really confuse new C++ programmers - the use of the \texttt{\&} symbol.  We now have four different uses for this symbol.  These are summarised in the following table.
\begin{center}
\begin{tabularx}{\textwidth}{|l|l|X|}
\hline
\textbf{Use} & \textbf{Example} & \textbf{Description} \\
\hline
Bitwise and operator & \texttt{int c = a \& c} & Performs a bitwise and operation on two values.  This takes the bit pattern of the value and logically ands the individual bits. \\
\hline
Logical and operator & \texttt{bool c = a \&\& b} & Performs a logical and on two boolean values. \\
\hline
Address of operator & \texttt{int *a = \&b} & Gets the address (to create a pointer) of a value. \\
\hline
Reference to specifier & \texttt{int \&a = b} & Declares a variable as a reference type. \\
\hline
\end{tabularx}
\end{center}

The main confusion comes between the use of \texttt{\&} as an operator to get a pointer to a value and declaring a variable as a reference type.  This is because they are related.  Both of these capabilities rely on us not storing a value directly but having a way of accessing the value.

To help clarify the difference, try and remember the following:
\begin{itemize}
\item A pointer type is declared using \texttt{*} (e.g. \texttt{char*}).  To get a pointer to a value, we use the \texttt{\&} operator on a variable.  When using \texttt{\&} on a variable, we are getting a pointer to it.
\item A reference type is declared using \texttt{\&} (e.g. \texttt{char\&}).  To get a reference to a value, we simply assign the variable to the reference type.  We use \texttt{\&} to declare types (e.g. variable declarations, parameter declarations) as we do with \texttt{*} for pointer types.
\end{itemize}
\end{framed}

References may seem strange but you have actually been using them all the time in modern object-oriented languages.  Everything in Java and C\# (except the primitive types such \texttt{int}) are passed as references.  This means that in all likelihood you already think in references.  This can make working in \emph{pass-by-value} a bigger headache.  However, as you may notice, we can pass any type as a reference in C++ (using the \texttt{\&} specifier).  In Java we cannot, although C\# does provide some of this capability.

With that introduction to pass-by-reference let us move onto our example application.  This is the same as the previous pass-by-value one but this time we use a reference for the parameter.  The code is below.

\begin{lstlisting}[caption=Passing a Parameter by Reference]
#include <iostream>

void foo(int &x)
{
    std::cout << "Start of function, x = " << x << std::endl;
    x = 20;
    std::cout << "End of function, x = " << x << std::endl;
}

int main(int argc, char **argv)
{
    int x = 10;
    std::cout << "Before function call, x = " << x << std::endl;
    foo(x);
    std::cout << "After function call, x = " << x << std::endl;

    return 0;
}
\end{lstlisting}

Our change is on line 3 where we declare the parameter \texttt{x}.  Now the type is \texttt{int\&} rather than just \texttt{int}.  This means that we are modifying the exact same value that \texttt{main} has in \texttt{foo}.  Figure~\ref{fig:pass-by-reference} provides an example.

\begin{figure}[htb]
\centering
\includegraphics[width=\textwidth]{pass-by-reference}
\caption{Interpretation of the Stack Using Pass-by-Reference}
\label{fig:pass-by-reference}
\end{figure}

Running this application will provide the following output:

\begin{lstlisting}[style=DOS, caption=output from Pass-by-Reference Application]
Before function call, x = 10
Start of function, x = 10
End of function, x = 20
After function call, x = 20
\end{lstlisting}

As we can see, the modification to \texttt{x} in the function is reflected in the main application.  The reference means that we have not created a copy of the value.

\begin{framed}
\textbf{Why use References?}

There are a number of reasons for and against using references over copying data between functions.  A few to consider are:
\begin{enumerate}
\item \emph{Pass-by-value} copies data when the variable is passed.  On a sized data types this is unlikely to concern us as the memory overhead and cost of copying is low.  However, on anything larger than the size of copy for a reference we start to degrade performance.  A reference is only 4 bytes in size (or 8 on a 64-bit operating system) and therefore can be copied in a single instruction.  Anything larger than this on pass-by-value will be slower.
\item \emph{Pass-by-Reference} allows you to modify (and therefore return) multiple values in a function.  This has its advantages when trying to write some operations that need to output multiple values.
\item \emph{Pass-by-Reference} does mean that you can modify values in a function.  This could cause unforeseen behaviour if you are calling someone else's code.
\item \emph{Pass-by-Reference} can lead to multiple objects having access to the same value.  This can enable multiple objects to \emph{mutate the state} (in other words modify the attributes) of the object and be difficult to track in large applications.
\end{enumerate}

The developers of Java decided that pass-by-reference was the best method (they have a garbage collector to clean up memory - C++ doesn't which we will explore next unit).  In practice, pass-by-reference is also recommended in C++, but it has it's limitations.  For example, there is no such thing as a \texttt{null} reference in C++.  This means a reference must also point to an initialised value.  Also, a reference cannot change to point to a different location in memory.  It is fixed and will also point to the same location.  This has it's pros and cons.  The pointer type is more versatile, but therefore also more volatile.
\end{framed}

\section{Example - Copying and Sorting by Value and Reference}

Let us look at how pass-by-value impacts memory usage in comparison to pass-by-reference.  We will build an application that performs a bubble sort on two large arrays of data in two different ways.  The first way will involve pass-by-copy which will require two copies of the array to be in existence, and hence more memory being used.  The second will involve pass-by-reference and hence reduce memory usage.  To do this we will also use a \texttt{vector} to store our data.

\begin{framed}
\textbf{What is a \texttt{vector} in C++}

A \texttt{vector} in C++ terms is very similar to a standard array except it provides mechanisms to add, remove, insert, etc.  The \texttt{vector} will resize itself based on requirements.  This means that if you add a value to the \texttt{vector} it will increase in size, and if you remove an item the \texttt{vector} will decrease in size.

It is very likely that you have used a data store object that resizes in other languages.  In Java this is known as an \texttt{ArrayList}.  We will use \texttt{vector} in places from now on, but we will cover data structures in more depth in a later unit.

A \texttt{vector} has a type associated with it.  This is declared in angle brackets in the variable declaration.  For example, to declare a \texttt{vector} that stores type \texttt{int} we use \texttt{vector<int>}.  This uses a technique called \emph{templates} which allow us to provide compile time type information.  We will only briefly cover templates as they can be used for far more sophisticated purposes than we can fully cover in the module.
\end{framed}

Our test application is below.

\begin{lstlisting}[caption=Passing a Vector by Value and Reference]
#include <iostream>
#include <vector>

void sort_copy(std::vector<int> data)
{
    // Iterate through each value
    for (int i = 0; i < data.size(); ++i)
    {
        // Loop through values above index i
        for (int j = 0; j < data.size() - (i + 1); ++j)
        {
            // Test if data[j] > data[j + 1]
            if (data[j] > data[j + 1])
            {
                // Swap values
                int temp = data[j + 1];
                data[j + 1] = data[j];
                data[j] = temp;
            }
        }
        if (i % 1000 == 0)
			std::cout << ((float)i / (float)data.size()) * 100.0f << "% sorted" << std::endl;
    }
}

void sort_reference(std::vector<int> &data)
{
    // Iterate through each value
    for (int i = 0; i < data.size(); ++i)
    {
        // Loop through values above index i
        for (int j = 0; j < data.size() - (i + 1); ++j)
        {
            // Test if data[j] > data[j + 1]
            if (data[j] > data[j + 1])
            {
                // Swap values
                int temp = data[j + 1];
                data[j + 1] = data[j];
                data[j] = temp;
            }
        }
        if (i % 1000 == 0)
            std::cout << ((float)i / (float)data.size()) * 100.0f << "% sorted" << std::endl;
    }
}

int main(int argc, char **argv)
{
    std::vector<int> data;
    for (int i = 0; i < 262144; ++i)
        data.push_back(262144 - i);

    std::cout << "Sorting by copy..." << std::endl;
    sort_copy(data);
    std::cout << "Sorting by reference..." << std::endl;
    sort_reference(data);
    
    return 0;
}
\end{lstlisting}

Let us point out a few lines of interest:
\begin{description}
\item[line 4] - here we are passing the vector by \emph{value}.  Note that we don't use any specifier on the data type for the parameter.
\item[lines 7, etc.] - we use the method \texttt{size} on the \texttt{vector}.  This provides the number of elements currently stored in the \texttt{vector}.
\item[line 13, etc.] - notice that we can use standard array notation to access members of the \texttt{vector}, e.g. \texttt{data[i]}.  Within the \texttt{vector} is an actual array used to store the data.  C++ provides \emph{operator overloading} which allows us to access this array.
\item[line 26] - here we are passing the vector by \emph{reference}.  We have used the \texttt{\&} specifier on the data type for the parameter.
\item[line 52] - we use the \texttt{push\_back} method on the \texttt{vector} to add values to the end of the data store.  For the first call to \texttt{push\_back} we set the $0^{th}$ element, for the second call the $1^st$ element, and so on.
\item[line 55] - we call the pass-by-value version of sort.  Notice we don't have to use any additional code to call with pass-by-value.
\item[line 57] - we call the pass-by-reference version of sort.  Notice we don't have to use any additional code to call with pass-by-reference.
\end{description}

The size of the \texttt{vector} data in memory is approximately 1 megabyte.  When we use the pass-by-value version, we create a copy of the \texttt{vector} and therefore add another 1 megabyte of memory usage.  This can be seen using the Windows Task Manager.

### \subsection{Exercise}

To truly test this application you will need to open Windows Task Manager.  Watch the application memory usage when the application has copied the vector, and also when it has passed by reference.  An example is shown in Figure~\ref{fig:taskmgr}.

\begin{figure}[htb]
\centering
\begin{subfigure}[b]{.45\textwidth}
\includegraphics[width=\textwidth]{taskmgr-copy}
\end{subfigure}
\begin{subfigure}[b]{.45\textwidth}
\includegraphics[width=\textwidth]{taskmgr-ref}
\end{subfigure}
\caption{Task Manager During Pass-by-Copy (left) and Pass-by-Reference (right)}
\label{fig:taskmgr}
\end{figure}

## \section{Array Library in C++}

We have now introduced enough C++ to allow us to reimplement our simple array library using C++ objects and techniques.  Remember that we created three pieces of functionality:
\begin{enumerate}
\item Searching for an item in the array
\item Sorting data in the array
\item Generating random values to fill the array
\end{enumerate}

We will not implement the search method this time - mainly because the \texttt{vector} provides this capability.  To be fair, C++ provides a sort capability which you can look at in the exercises.  The other change we will make is the use of the C++ \texttt{vector} rather than a raw array.  Let us look at the two other functions in turn.

### \subsection{Sorting}

Our C++ header for sort is again called \texttt{sort.h}.  Remember that it just takes the array data and its size.  Now we are using a \texttt{vector} the size is provided as a method.  Our \texttt{sort.h} is declared below.

\begin{lstlisting}[caption=\texttt{sort.h} Header File in C++]
#pragma once

#include <vector>

void sort(std::vector<int> &data);
\end{lstlisting}

The implementation undertakes the same bubble sort approach as we did in the C version.  The only difference is that we are using the \texttt{vector} data type rather than the raw array.  The code for \texttt{sort.cpp} is below.

\begin{lstlisting}[caption=\texttt{sort.cpp} Code File in C++]
#include "sort.h"
#include <iostream>

void sort(std::vector<int> &data)
{
    // Iterate through each value
    for (int i = 0; i < data.size(); ++i)
    {
        // Loop through values above index i
        for (int j = 0; j < data.size() - (i + 1); ++j)
        {
            // Test if data[j] > data[j + 1]
            if (data[j] > data[j + 1])
            {
                // Swap values
                int temp = data[j + 1];
                data[j + 1] = data[j];
                data[j] = temp;
            }
        }
        if (i % 1000 == 0)
            std::cout << ((float)i / (float)data.size()) * 100.0f << "% sorted" << std::endl;
    }
}
\end{lstlisting}

### \subsection{Generating}

Our C generation method required our data to generate into and its size.  For the C++ version we will just take a size value and return a new \texttt{vector} of that size filled with random values.  As such, our header file \texttt{generate.h} is defined as follows:

\begin{lstlisting}[caption=\texttt{generate.h} Header File in C++]
#pragma once

#include <vector>

std::vector<int> generate(int size);
\end{lstlisting}

The implementation will use C++ random mechanisms to create the \texttt{vector}.  The code is below.  We will look at C++ random after the code is introduced.

\begin{lstlisting}[caption=\texttt{generate.cpp} Code File in C++]
#include "generate.h"
#include <random>

std::vector<int> generate(int size)
{
    // Create random generator
    std::random_device rd;
    // Create distribution
    std::uniform_int_distribution<int> dist;
    // Generate random numbers
    std::vector<int> data;
    for (int i = 0; i < size; ++i)
        data.push_back(dist(rd));

    return data;
}
\end{lstlisting}

\begin{framed}
\textbf{Random Numbers in C++}

Random number generation is a relatively new feature in C++.  Until the C++11 standard (released in 2011), C++ programmers used the same random function as C.  With the introduction of C++11, C++ programmers have quite a wide ranging set of objects to generate random numbers.

C++ random number generation uses two objects:
\begin{description}
\item[random number generation engine] - this object is responsible for generating random numbers using a particular algorithm.  This is the \texttt{random\_device} object in our code.
\item[value distribution] - this object can take a random engine and return a value of the required type and within a given range.  This is our \texttt{uniform\_int\_distribution} object in our code.  It allows us to get values of type \texttt{int} from the random engine.  We could also define a minimum and maximum value to be produced by providing these as parameters.
\end{description}

We can get random numbers without using a distribution, but generally you will want to use one.  To get a value within the distribution we use the following code:

\texttt{\emph{type} val = distribution(engine);}
\end{framed}

### \subsection{Test Application}

We can now build a test application to test our library.  This is shown below.  As can be seen, using C++ and object orientation reduces our code requirement.

\begin{lstlisting}[caption=Test Application for C++ Array Library]
#include "generate.h"
#include "sort.h"
#include <iostream>

int main(int argc, char **argv)
{
    std::vector<int> data = generate(65536);
    sort(data);

    // Print the first 100 values
    for (int i = 0; i < 100; ++i)
        std::cout << data[i] << std::endl;
    
    return 0;
}
\end{lstlisting}

### \subsection{Exercise}

You can now build the application (remember - you should be using make files for this).  There is a library component (the sort and generate parts), and the main application.  Ensure that you are building a separate library that you link in the main application build.  We have already covered this, so go back and review the content to ensure you can replicate it.  An example output is given below:

\begin{lstlisting}[style=DOS, caption=Output from C++ Array Library Test Application]
... previous lines

2416421
2453633
2472376
2515740
2585328
2588164
2609197
2623708
2625554
2660361
2669049
2669493
2678787
2750678
2751473
2772010
\end{lstlisting}

## \section{Reading Files in C++}

In the last unit we took our array library and combined it with some file input-output.  We will repeat this now for C++ and see the difference working with object-orientation provides.  C++ works on the basis of \emph{streams}, which we have already seen with \texttt{cout} and \texttt{cin}.  Files, once opened, are also just streams we can read from and write to.  Table~\ref{tab:stream-types} describes some of the common base stream types in C++.

\begin{table}[htb]
\centering
\begin{tabularx}{\textwidth}{|l|X|X|}
\hline
\textbf{Type} & \textbf{Friendly Name} & \textbf{Description} \\
\hline
\texttt{istream} & input stream & A stream that data can be read from. \\
\hline
\texttt{ostream} & output stream & A stream that data can be written to. \\
\hline
\texttt{iostream} & input-output stream & A stream that can be read from and written to \\
\hline
\texttt{fstream} & file stream & Represents an input-output stream that points to a file.  \texttt{ifstream} and \texttt{ofstream} also exist. \\
\hline
\texttt{stringstream} & string stream & Provides a stream that can be written to to create a \texttt{string}. Can be used instead of appending. \\
\hline
\end{tabularx}
\caption{Common Stream Types in C++}
\label{tab:stream-types}
\end{table}

The one we are interested in here is \texttt{fstream}, or more specifically \texttt{ifstream} to read data from.  We will look at \texttt{ofstream} in the next section.

\begin{framed}
\textbf{Working with \texttt{ifstream}}

Before looking at our application let us introduce how we work with the \texttt{ifstream} type.

\begin{description}
\item[Creating a \texttt{ifstream}] - to create a \texttt{ifstream} object (and either open or create a file accordingly) we use the call \texttt{ifstream \emph{var-name}(\emph{filename}, \emph{mode});}.  The \emph{filename} parameter is a \texttt{string} representing the filename.  The mode determines the mode we open the file in (e.g. binary).
\item[Seeking in a File] - we can seek to a particular position in a file using the \texttt{seekg} command.  We can use this to move to the end of a file and then get the position using \texttt{tellg}.
\item[Getting the Current File Position] - we can use \texttt{tellg} to tell us which position in the file (byte number) we are currently accessing.
\item[Reading in Data] - we can use the streaming operator to read in individual values.  However, we can also use \texttt{read} to read in a set amount of data into an area of memory
\item[Closing a \texttt{ifstream}] - the method \texttt{close} is used to close a \texttt{ifstream}
\end{description}
\end{framed}

Our application to read from a data file is below.  With the \texttt{ifstream} operations described above you should be able to understand what we are doing.

\begin{lstlisting}[caption=Reading Binary Files in C++]
#include <iostream>
#include <fstream>
#include <string>
#include "sort.h"

std::vector<int> readfile(std::string &filename)
{
    // Open the file
    std::ifstream file(filename, std::ios::binary);
    // Get the size of the file - seek to end
    file.seekg(0, file.end);
    std::streampos size = file.tellg();
    // Seek back to start
    file.seekg(0, file.beg);
    // Number of elements is size / sizeof(int)
    int elements = size / sizeof(int);
    // Create an array of data to read into
    int *temp = new int[elements];
    // Read in data
    file.read((char*)temp, size);
    // Close the file
    file.close();
    // Copy data into the vector
    std::vector<int> data(temp, temp + elements);
    // Delete the data
    delete[] temp;
    // Return the vector
    return data;
}

int main(int argc, char **argv)
{
    // Read in a vector
    std::vector<int> data = readfile(std::string("numbers.dat"));
    // Print the vector size
    std::cout << "Numbers read = " << data.size() << std::endl;
    // Sort the vector
    sort(data);
    // Output first 100 numbers
    for (int i = 0; i < 100; ++i)
        std::cout << data[i] << std::endl;
    
    return 0;
}
\end{lstlisting}

Let us look at some of these lines in more detail.
\begin{description}
\item[line 6] - note that we are passing the name of the file as a reference to \texttt{readFile}.  This is because we don't need a copy of the filename in our \texttt{readFile} operation.
\item[line 9] - here we open our file.  Note the mode we open with - \texttt{std::ios::binary}.  This means that we are opening the file as a binary file.
\item[line 11] - we use \texttt{seekg} to seek to the end of the file (0 from \texttt{end} of \texttt{file}).  This is important for the next line.
\item[line 12] - we get the position in the file using \texttt{tellg}.  We now know the size of the file in bytes.
\item[line 14] - we seek back to the start of the file (0 from \texttt{beg}inning of \texttt{file}).
\item[line 16] - we calculate the number of \texttt{int} values in the file by dividing its size by the size of an \texttt{int}.
\item[line 18] - we allocate memory to store the file contents using the \texttt{new} operator.  We will cover this in more detail in the next unit.
\item[line 20] - we read the file into our allocated memory.  Note that we have to cast to a \texttt{char*} for this to happen.
\item[line 22] - we close the file.
\item[line 24] - this is a new way of creating our \texttt{vector} and might seem a bit strange.  What we are doing is giving \texttt{vector} a starting and ending memory location, which is used to copy the data into the \texttt{vector}.  The starting memory location is the pointer representing our memory we read the file into.  The end location is this memory location plus the number of elements (which will be implicitly multiplied by the size of the data type).  This line takes a bit of getting used to, so take your time and ensure you understand it.
\item[line 26] - we free the allocated memory from line 18.  This will be covered in the next unit.
\end{description}

\begin{framed}
\textbf{Using \texttt{new} and \texttt{delete} in C++}

In this example we have used to new concepts - \texttt{new} and \texttt{delete}.  These commands are used in C++ to allocate memory and free it after we have finished with it.  We have looked at these ideas a little in C.  You are very likely used to working with \texttt{new} in Java.  However, in C++ things are different in that we need to ensure that we free up any memory created using \texttt{new}.  This is unlike Java where the garbage collector does this for us.  Working out when we need to allocate and free memory is an important skill in C++.
\end{framed}

\section{Writing Files in C++}

Let us now look at writing files in C++.  The code for our application is below.  This should be straightforward by now.

\begin{lstlisting}[caption=Writing Text Files in C++]
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

std::vector<std::string> readfile(std::string &filename)
{
    // Open file - default is text
    std::ifstream file(filename);
    // String to read into
    std::string line;
    // Data to return
    std::vector<std::string> data;
    // Read until end of file
    while (std::getline(file, line))
        data.push_back(line);
    // Close file
    file.close();
    // Return data
    return data;
}

void writefile(std::string &filename, std::vector<std::string> &data)
{
    // Open file - default is text
    std::ofstream file(filename);
    // Write each line into file starting at end of vector
    for (int i = data.size() - 1; i >= 0; --i)
        file << data[i] << std::endl;
    // Close the file
    file.close();
}

int main(int argc, char **argv)
{
    // Read in file
    std::vector<std::string> data = readfile(std::string("sorted.txt"));
    // Print lines read
    std::cout << "Lines read = " << data.size() << std::endl;
    writefile(std::string("reversed.txt"), data);

    return 0;
}
\end{lstlisting}

Line 15 uses the \texttt{get\_line} command to read a line of the text file into a string.  This call returns \texttt{true} as long as there are lines of code to read.  This is why we use the \texttt{while} loop to fill the \texttt{vector} with read strings.  The other line to take note of is line 29 where we using the streaming operator to write lines to the file.

## \section{\texttt{const} References}

Our final look at references considers the use of \texttt{const}.  Remember in C we used \texttt{const} to define constant values, whether it be variables or parameters.  We can also declare references as \texttt{const}.  This means that the value stored in the reference cannot be changed.  Let us look at an example.

\begin{lstlisting}[caption=Passing \texttt{const} References]
#include <iostream>
#include <string>

std::string join(const std::string &a, const std::string &b)
{
    // This line won't compile
    return a.append(b);
}

int main(int argc, char **argv)
{
    std::string greeting = join(std::string("Hello,"), std::string(" World!"));

    std::cout << greeting << std::endl;
    
    return 0;
}
\end{lstlisting}

The \texttt{append} method used on line 6 is not \texttt{const}, and therefore your code won't compile.  However, if we modify our \texttt{join} function to use the append operator (\texttt{+}) we create a copy of the strings and therefore get around the problem.  This code is below.

\begin{lstlisting}[caption=Adding Two \texttt{const string} Values Together in C++]
std::string join(const std::string &a, const std::string &b)
{
    // This line will compile
    return a + b;
}
\end{lstlisting}

You might ask then why do we pass by \texttt{const} at all.  For one reason, safety - we are stating we are not going to modify the value.  For another reason, the compiler can actually improve the application performance if it knows a value is \texttt{const}.  This can be an important benefit when writing optimised code, and you should consider using \texttt{const} whenever it is suitable.

### \subsection{Exercise}

Can you write another version of \texttt{join} that uses the \texttt{append} method of \texttt{string}?  This is possible.  You must use the same function prototype as already defined (i.e. the values must be \texttt{const}).

## \section{Pointers}

So references where the easier part of this unit.  The more difficult part is understanding pointers.  Pointers are considered the most difficult part of working with C and C++ as they take novice programmers a bit of time to understand.  This isn't helped by the use of similar symbols between references and pointers in C++.

Remember that a pointer is just a location in memory that we treat like a particular value.  This is similar to references, except that we can make a pointer point to different parts of memory as required.  Remember that a reference is fixed.

To declare a pointer we use the \texttt{*} specifier with the type.  For example, a pointer to an \texttt{int} is declared as \texttt{int*}.  To get the address of a variable we use the \texttt{\&} operator (address of operator).  To get the value stored in the memory location pointed to by a pointer we use the \texttt{*} operator.  Let us summarise this a little.  This is given in Table~\ref{tab:pointers}.

\begin{table}[htb]
\centering
\begin{tabularx}{\textwidth}{|l|l|X|}
\hline
\textbf{Operator / Specifier} & \textbf{Example} & \textbf{Description} \\
\hline
Pointer type specifier & \texttt{int *x;} & Declares that a variable or parameter is a pointer type. \\
\hline
Address-of operator & \texttt{int *x = \&y;} & Gets the memory address of a variable \\
\hline
Dereference operator & \texttt{int z = *x;} & Gets the value stored in the memory location represented by the pointer \\
\hline
\end{tabularx}
\caption{Pointer Operators and Specifiers}
\label{tab:pointers}
\end{table}

Let us now implement our \emph{pass-by-pointer} application as we did for pass-by-value and pass-by-reference.  This time we will also print out the memory location of our variable to illustrate that it is not changing throughout the application.  The code for our application is below.  Note the use of the \emph{address-of} and \emph{dereference} operators.

\begin{lstlisting}[caption=Passing a Value as a Pointer]
#include <iostream>

void foo(int *x)
{
    std::cout << "Address of x in function = " << x << std::endl;
    std::cout << "Start of function, x = " << *x << std::endl;
    // Have to dereference pointer to change value
    *x = 20;
    std::cout << "End of function, x = " << *x << std::endl;
    std::cout << "Address of x at end of function = " << x << std::endl;
}

int main(int argc, char **argv)
{
    int x = 10;
    std::cout << "Starting address of x = " << &x << std::endl;
    std::cout << "Before function call, x = " << x << std::endl;
    // Have to pass the pointer (or address of) x to the function
    foo(&x);
    std::cout << "After function call, x = " << x << std::endl;
    std::cout << "End address of x = " << &x << std::endl;

    return 0;
}
\end{lstlisting}

An example output from this application is below.  Note that the memory address remains the same throughout the application.

\begin{lstlisting}[style=DOS, caption=Output from Pass-by-Pointer Application]
Starting address of x = 003FFC30
Before function call, x = 10
Address of x in function = 003FFC30
Start of function, x = 10
End of function, x = 20
Address of x at end of function = 003FFC30
After function call, x = 20
End address of x = 003FFC30
\end{lstlisting}

## \section{Arrays as Pointers to Memory}

One of the most common uses for pointers in C and C++ is when we are working with arrays.  Arrays are just blocks of memory, and as pointers hold memory locations, an array is just a pointer to the starting memory location of the block of memory representing the array.  This allows us to pass around large blocks of memory as a pointer thus avoiding copying.

\begin{framed}
\textbf{Arrays Revisited}

We have covered arrays in C and C++ in a few places now, although we haven't delved to far into the subject (this will happen in the next unit).  Remember to create an array in C / C++ we use the following:

\texttt{\emph{type} name[size];}

This will create a \emph{fixed} (compile time defined) size array.  This is an important distinction in C in comparison to Java.  In Java, array sizes are defined at runtime as standard.  In C and C++ our arrays are of fixed size at compile time unless we use memory allocation.

In C, memory allocation is handled using the \texttt{malloc} function.  This returns a pointer to a memory block of the required size.  In C++ we can use the \texttt{new} operator to create an array of the required size at runtime:

\texttt{\emph{type} *name = new \emph{type}[size];}

This is how you are likely to remember array allocation in Java (apart from the pointer part).  

In C and C++ arrays are a pointer to the start of the memory block where the memory is located.  The size of the array is not stored however (unlike in Java) so we have to pass this value around.  This is why working with \texttt{vector} in C++ is almost always a better choice.
\end{framed}

An example array application is below:

\begin{lstlisting}[caption=Passing Arrays as Pointers]
#include <iostream>

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
    for (int i = 0; i < 20; ++i)
        std::cout << data[i] << std::endl;

    data = create_array_new();
    // Print out all elements
    for (int i = 0; i < 20; ++i)
        std::cout << data[i] << std::endl;
    // Free the memory
    delete[] data;
    // Set to nullptr
    data = nullptr;
    
    // Create array from pointer
    // This will cause a memory allocation error
    // nullptr (memory address 0) cannot be allocated to
    create_array(data);
    
    // Allocate memory
    data = new int[20];
    // Create array from pointer
    create_array(data);
    // Print out all elements
    for (int i = 0; i < 20; ++i)
        std::cout << data[i] << std::endl;
    // Free the memory
    delete[] data;
    // Set to nullptr
    data = nullptr;
    
    return 0;
}
\end{lstlisting}

Compiling this version of the code will cause a runtime error because of line 48 (or more specifically on line 26 which is called by line 48).  Try running the application as is to check this.  After that, comment out line 48 and run.  You should get an output as follows:

\begin{lstlisting}[style=DOS, caption=Output from Arrays as Pointers Application]
0
14754591
14908184
14908272
6291172
14908272
6291164
14754917
6291172
6291184
14768466
14908272
-255
14908272
6291192
14751355
6291208
14755646
14908272
14908272
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
\end{lstlisting}

The interesting values printed out are the first 20.  This is what happens when we return a pointer to a location on the stack which is no longer valid.  The data here has been overwritten.  This means that we have a variable that is pointing to an area of the stack we may use later, which will cause a possible \emph{stack corruption} problem later.  Stack corruption is where our stack is modified unintentionally, commonly by pointing to an invalid location on the stack.  Figure~\ref{fig:stack-corruption} provides an illustration of what is happening.

\begin{figure}[htb]
\centering
\includegraphics[width=\textwidth]{stack-corruption}
\caption{Data and Stack Corruption Example - Returning Non-Valid Memory}
\label{fig:stack-corruption}
\end{figure}

## \section{\texttt{const} Pointers and Pointers to \texttt{const}}

We covered \texttt{const} in relation to references previously.   Now let us look at how \texttt{const} affects pointers.  There are actually two potential \texttt{const} parts to a pointer - the data stored in the pointer (\emph{constant data}) and the memory location pointed to by the pointer (\emph{constant pointer}).  Table~\ref{tab:const-pointer} illustrates the different approaches.

\begin{table}[htb]
\centering
\begin{tabularx}{\textwidth}{|l|l|X|}
\hline
\textbf{\texttt{const} Part} & \textbf{Example} & \textbf{Description} \\
\hline
Value & \texttt{const int *x} & The value pointed to by the pointer is constant and cannot be changed.  The memory address can be changed however. \\
\hline
Pointer & \texttt{int *const x} & The memory address cannot be changed (is constant).  However, the value pointed to can be changed. \\
\hline
Value and Pointer & \texttt{const int *const x} & Both the value pointed to and the memory address are \texttt{const}. \\
\hline
\end{tabularx}
\caption{\texttt{const}ness of Pointers}
\label{tab:const-pointer}
\end{table}

Let us now build an example application.  The code below has a number of lines you will have to comment out, but you should first build the code without the commented out lines.  This is so you can see the compiler error that C++ will provide.

\begin{lstlisting}[caption=\texttt{const} Pointers and Pointers to \texttt{const}]
#include <iostream>

void foo(const int *x)
{
    std::cout << "Address of x in function = " << x << std::endl;
    std::cout << "Start of function, x = " << *x << std::endl;
    // Wont compile - value pointed to is const
    *x = 20;
    std::cout << "End of function, x = " << *x << std::endl;
    std::cout << "Address of x at end of function = " << x << std::endl;
}

void foo2(int *const x)
{
    std::cout << "Address of x in function = " << x << std::endl;
    std::cout << "Start of function, x = " << *x << std::endl;
    // Will compile - pointer is const, not value pointed to
    *x = 20;
    std::cout << "End of function, x = " << *x << std::endl;
    std::cout << "Address of x at end of function = " << x << std::endl;
}

void foo3(int *const x)
{
    std::cout << "Address of x in function = " << x << std::endl;
    std::cout << "Start of function, x = " << *x << std::endl;
    // Won't compile - trying to change address pointed to
    x = nullptr;
    std::cout << "End of function, x = " << *x << std::endl;
    std::cout << "Address of x at end of function = " << x << std::endl;
}

int main(int argc, char **argv)
{
    int x = 10;
    std::cout << "Starting address of x = " << &x << std::endl;
    std::cout << "Before function call, x = " << x << std::endl;
    // Have to pass the pointer (or address of) x to the function
    foo2(&x);
    std::cout << "After function call, x = " << x << std::endl;
    std::cout << "End address of x = " << &x << std::endl;

    return 0;
}
\end{lstlisting}

The compiler error provided by Microsoft's C++ compiler is as follows:

\begin{lstlisting}[style=DOS, caption=Compiler Error from Trying to Modify a \texttt{const}]
        cl const_pointer.cpp
Microsoft (R) C/C++ Optimizing Compiler Version 18.00.30501 for x86
Copyright (C) Microsoft Corporation.  All rights reserved.

const_pointer.cpp
C:\Program Files (x86)\Microsoft Visual Studio 12.0\VC\INCLUDE\xlocale(337) : wa
rning C4530: C++ exception handler used, but unwind semantics are not enabled. S
pecify /EHsc
const_pointer.cpp(8) : error C3892: 'x' : you cannot assign to a variable that i
s const
const_pointer.cpp(28) : error C3892: 'x' : you cannot assign to a variable that
is const
\end{lstlisting}

\begin{framed}
\textbf{What is \texttt{nullptr}?}

We have introduced another new term in this code - \texttt{nullptr}.  This is a new addition to C++11 and provides the equivalent of \texttt{null} in Java.  \texttt{nullptr} effectively points at memory location 0.  \texttt{NULL} is a commonly defined value in C and C++ and is also 0.  It is quite common to point unallocated memory to location 0 to allow code checks.
\end{framed}

We've only begun to stray into pointers here, and the next unit will look at memory allocation and management.  Here we have to use pointers, although the C++11 standard has introduced some helper objects to make our life easier.

## \section{Namespaces}

One final idea from C++ we will introduce in this unit is the idea of \emph{namespaces}.  A namespace is just a nice way of managing a collection of code that we consider to be part of a unit (such as a library).  We've actually been using namespaces since the start of our C++ work.  This is the \texttt{std} part we have been putting in front of our objects from the standard library.

There is a debate amongst C++ programmers about when you should use the full object name, but usually you want to reduce the amount of typing you have to undertake when coding.  Typically in our main application we want to just tell the compiler that we are using a particular namespace and then just use the object names directly.  We do this using the \texttt{using} statement:

\begin{lstlisting}
using namespace std;
\end{lstlisting}

Because we have told C++ that we are using a particular namespace we can now access our objects directly.  So instead of writing \texttt{std::string} we can just write \texttt{string}.  \emph{From this point onwards our applications will use the \texttt{std} namespace}.  This will always occur in our main applications.  However, in header files we will not use the namespace.  This is common practice in C++ code.

As an example application, let us rewrite our file I/O code with a \texttt{using} statement.

\begin{lstlisting}[caption=Using Namespaces in C++]
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

vector<string> readfile(string &filename)
{
    // Open file - default is text
    ifstream file(filename);
    // String to read into
    string line;
    // Data to return
    vector<std::string> data;
    // Read until end of file
    while (getline(file, line))
        data.push_back(line);
    // Close file
    file.close();
    // Return data
    return data;
}

void writefile(string &filename, vector<string> &data)
{
    // Open file - default is text
    ofstream file(filename);
    // Write each line into file starting at end of vector
    for (int i = data.size() - 1; i >= 0; --i)
        file << data[i] << endl;
    // Close the file
    file.close();
}

int main(int argc, char **argv)
{
    // Read in file
    vector<string> data = readfile(string("sorted.txt"));
    // Print lines read
    cout << "Lines read = " << data.size() << endl;
    writefile(string("reversed.txt"), data);

    return 0;
}
\end{lstlisting}

As can be seen, our code is a bit simpler and there is less to write.  You are likely to come across different approaches to using namespaces in other peoples C++ code, but the approach taken in this module is that described above.  This is the expected coding practice of the module.

\section{Exercises}

This has been a large unit, and you should familiarise yourself with the content.  However, the following exercises will help you strengthen your understanding and knowledge of C++.

\begin{enumerate}
\item Investigate \texttt{std::setprecision} and how it can be used to determine the number of decimal places printed out on the command line.  Write an application that tests the \texttt{std::setprecision} method on the command line to see the different results.
\item C++ provides \texttt{std::find} and \texttt{std::sort} methods.  Investigate these and then use them to rewrite the array library developed in this unit using \texttt{std::vector}.  In particular, compare the performance of the \texttt{sort} method with our trivial bubble sort.
\item Our \texttt{generate} function did seed its random (see discussion on \texttt{srand} previously).  Discover how to seed a random engine in C++ and do this in your library to ensure the random numbers cannot be predicted.
\item Other C++ random engines exist.  Investigate these random engines by using them in your array library.  Look at the output results to understand how they generate values.
\item Modify the distribution in your array library so that numbers only up to 255 are generated.
\item \textbf{For the Brave} - we haven't covered certain aspects of call conventions in this unit.  Investigate the \texttt{\_\_cdecl}, \texttt{\_\_stdcall} and \texttt{\_\_fastcall} calls.
\end{enumerate}