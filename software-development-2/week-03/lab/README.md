# Data Sizes and Data Representation

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

Looking at the equality tests though shows us that C does do more work here.  `a` is shown to be equal to `f`, although the bit representations are different.  This is because C will attempt to convert the values to the same type.  There are rules that govern this conversion.  You will learn them through practice.

## Minimum and Maximum Values of Data Types

Given that we can work out the size of a data type in bytes using `sizeof` and know the difference between `signed` and `unsigned` values and the overhead of having `signed` values, we are able to work out the maximum and minimum values of each type.  We could do this by hand, but we would have to do it for every system we compiled our programs for.  This isn't very efficient either.  Thankfully we have the `limits.h` header file which provides us this information.

> **`limits.h`**
>
> The `limits.h` header file contains a collection of different values that define the minimum and maximum values of the standard types.  We will be looking at these shortly.  If you need to know the maximum or minimum of the standard values then include the `limits.h` header.

Let us do a quick test of finding out the limits. **Run the following application**:

```c
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(int argc, char **argv)
{
    printf("unsigned int is %d bytes, min value %u, max value %u\n", sizeof(unsigned int), 0, UINT_MAX);
    printf("int is %d bytes, min value %d, max value %d\n", sizeof(int), INT_MIN, INT_MAX);
    return 0;
}
```

Notice that for `unsigned int` we use `0` as the minimum -- there is no other minimum defined.  The other values (`UINT_MAX`, `INT_MIN` and `INT_MAX`) are all defined in the `limits.h` header file.  Running this application will give the following result (based on your system).

```shell
unsigned int is 4 bytes, min value 0, max value 4294967295
int is 4 bytes, min value -2147483648, max value 2147483647
```

So we now know how to get the size of a value and also how to get the minimum and maximum values.  Let us combine these ideas into a single application.

## Number Types

The following application will print the sizes, minimum, and maximum values of the standard C types.  We will use `float.h` to get the minimum and maximum values of the floating point number types as well.  The application is below.  It also includes pointer values.

```c
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
```

> **More `printf` Placeholders**
>
> We have introduced two new placeholders for `printf` this time.  These are as follows:
>
> - `%l` -- placed before another placeholder means that we expect a `long` version of the value (`signed` or `unsigned`).  Can be used with another long placeholder for `long long` values.
> - `%e` -- prints out the value in scientific notation format.

> **Why no `unsigned` Floating Points?**
>
> We have used the floating point values in this application, but we haven't defined any `unsigned` floating point values.  This is because they don't exist as the CPU does not support `unsigned` floating point values, therefore neither does C.  All floating point values are `signed`.

Running this application provides the following output:

```shell
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
```

> **Pointers and Pointer Sizes**
>
> The pointer values are all 4 bytes in size above.  This is because we it was a 32-bit application.  A 32-bit application uses 32-bit (*4 byte*) values to represent memory locations, and a pointer is just a memory location.  If you calculate the maximum number of addressable memory locations using the standard calculation ($2^{32}$) you end up with 4294967296 bytes - or 4 GB.  You might recognise this as the maximum amount of memory that a 32-bit operating system supports.  It is also the maximum amount of memory that a 32-bit application can allocate.

The table provides an overview of the integer data types and their sizes based on our result of running this program using the Microsoft compiler on Windows.  Note that these data sizes are not consistent across other operating systems and compilers.  You should always check your data sizes in the environment you are working in.

| **Type**             | **Size (bytes)** | **Minimum Value** | **Maximum Value** |
| -------------------- | ---------------- | ----------------- | ----------------- |
| `unsigned char`      | 1                | 0                 | $2^8 - 1$         |
| `signed char`        | 1                | $-2^7 - 1$        | $2^7 - 1$         |
| `unsigned short`     | 2                | 0                 | $2^{16} - 1$      |
| `signed short`       | 2                | $-2^{15} - 1$     | $2^{15} - 1$      |
| `unsigned int`       | 4                | 0                 | $2^{32} - 1$      |
| `signed int`         | 4                | $-2^{31} - 1$     | $2^{31} - 1$      |
| `unsigned long`      | 4                | 0                 | $2^{32} - 1$      |
| `signed long`        | 4                | $-2^{31} - 1$     | $2^{31} - 1$      |
| `unsigned long long` | 8                | 0                 | $2^{64} - 1$      |
| `signed long long`   | 8                | $-2^{63} - 1$     | $2^{63} - 1$      |

### Fixed-width Number Types

To avoid the confusion that can occur with C number types, new number data types were introduced to support code reuse across compilers and architectures. Below is a summary of these new datatypes.

| **Type**   | **Size (bytes)** | **Minimum Value** | **Maximum Value** |
| ---------- | ---------------- | ----------------- | ----------------- |
| `uint8_t`  | 1                | 0                 | $2^8 - 1$         |
| `int8_t`   | 1                | $-2^7 - 1$        | $2^7 - 1$         |
| `uint16_t` | 2                | 0                 | $2^{16} - 1$      |
| `int16_t`  | 2                | $-2^{15} - 1$     | $2^{15} - 1$      |
| `uint32_t` | 4                | 0                 | $2^{32} - 1$      |
| `int32_t`  | 4                | $-2^{31} - 1$     | $2^{31} - 1$      |
| `uint64_t` | 8                | 0                 | $2^{64} - 1$      |
| `int64_t`  | 8                | $-2^{63} - 1$     | $2^{63} - 1$      |

## Strings

Now let us look at how the different methods of creating a string affect the data sizes allocated.  Remember we had a few different methods of declaring a string.  We will look at two separate techniques:

- Declaring a pointer to a `char` -- a `char*`.
- Declaring a fixed size array of `char` -- a `char[]`

C treats these two approaches in different ways.  Let us write a test application to see what happens:

```c
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
```

> **Dereferencing a Pointer**
>
> On lines 20 and 21 we have used the following pieces of code:
>
> - `*hello`
> - `*goodbye`
>
> When we use the star (`*`) in front of a pointer variable, we are asking to *dereference* the pointer.  This means that we want to access the *data* stored in the pointed to memory location rather than just the pointer.  We will be covering pointers later in the module, so you don't have to worry about this idea at the moment.

Running this application will give you the following output:

```shell
Hello message: Hello World!
Goodbye message: Goodbye World!
Size of hello message: 4 bytes
Size of goodbye message: 15 bytes
Size of data in hello message: 1 bytes
Size of data in goodbye message: 1 bytes
Length of hello message: 12 bytes
Length of goodbye message: 14 bytes
```

Let us look at the 6 sizes output:

1. Hello message is 4 bytes as it is a pointer to a string of character data.  Remember that a pointer is 4 bytes in size on a 32-bit machine (if you compile this in 64-bit the answer will be 8 bytes).
2. Goodbye message is 15 bytes long.  This is because we have created a fixed size array, which C knows the size of.
3. Size of data in hello is 1 byte.  We have dereferenced the pointer to access the data which is of type `char`.  Remember that a `char` is 1 byte in size.
4. Size of data in goodbye is the same as hello.
5. Length of hello is 12 bytes.  The message is 12 `char` long.
6. Length of goodbye is 14 bytes.  The message is 14 `char` long

So the same general rules apply to sizing strings as they do to sizing other data types.  The new interesting value is the array size.  *This only works for fixed size arrays*.  We will look at arrays in far more detail as we go through the module, and understand the limitations C and C++ has when working with array data.

## Casting Between Types

So we have looked at data sizes and we understand how numbers are represented on the machine (to a basic level -- *Computer Systems* teaches you more).  So what about converting a number between different types and representations?  Well, to do this we use a technique called *casting*.  Casting becomes quite a big concept when we work in object-orientation and we will cover some of these ideas later in the module.  However, let us look at how we cast numbers.

> **Casting**
>
> Casting is the operation of converting one type of value to another.  It actually happens all the time when you are programming.  A lot of the time you just don't see it.  We will discuss automatic casting shortly.
>
> To perform a cast we use the following syntax:
>
> ```c
> type casted_value = (type)original_value;
> ```
>
> The C compiler will take care of the necessary operations to convert from one type to another if necessary, although sometimes no specific operation occurs.  As an example, if we wanted to convert form a `int` to a `float` we would do the following:
>
> ```c
> int x = 10;
> float y = (float)x;
> // y is now 10.0f
> ```
>
> However, if we performed the same operation trying to convert `x` to a `char*` you won't be converting an `int` to a string:
>
> ```c
> int x = 10;
> char *y = (char*)x;
> // y now points to memory location 10!!!
> ```
>
> In this instance, an `int` is converted to a memory location.  Your pointer is now pointing at memory location 10.  This is a piece of memory you cannot manipulate (it will be controlled by the operating system).  If you try and print the data at this memory location your application will crash.

Casting is a useful operation when working with different number types.  However, it does have its limitations as our test application will explore.  In particular you need to think about what happens when you take a large number (say a `long long`) and convert it to a shorter number (say a `short`).  What happens to the data that is lost?  What does the number become?  Our test application will examine this.

```c
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
```

Running this application will give you the following output:

```shell
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
```

For our `unsigned char` value, we first convert it to a `signed char`.  This makes it -1!  What has happened here?  Well, a `signed char` has a maximum value of 127 with a signed bit.  This is represented by the following binary string:

`0111 1111`

For a `unsigned char` the value 255 is represented by the following binary string:

`1111 1111`

When converting this second binary string to a `signed char`, using standard negative number conversion (remember your *Computer Systems* work) this gives as -1.  Every other data value is large enough to take the binary digits.  The table illustrates how the number is represented in binary for each of the different data types.  It also shows how C converts the numbers (very trivially for `int` types). 

| **Type**        | **Binary String**                                            | **Value** |
| --------------- | ------------------------------------------------------------ | --------- |
| `unsigned char` | `1111 1111`                                                  | 255       |
| `signed char`   | `1111 1111`                                                  | -127      |
| `short`         | `0000 0000 1111 1111`                                        | 255       |
| `int`           | `0000 0000 0000 0000 0000 0000 1111 1111`                    | 255       |
| `long`          | `0000 0000 0000 0000 0000 0000 1111 1111`                    | 255       |
| `long long`     | `0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 1111 1111` | 255       |

When we go in reverse we are converting the `long long` value 9223372036854775807 (all binary digits 1).  In this instance we just remove binary digits until we reach the desired size.  As we are dealing with signed values this equates to -1 in each instance.

| **Type**    | **Binary String**                                            | **Value**           |
| ----------- | ------------------------------------------------------------ | ------------------- |
| `long long` | `0111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111 1111` | 9223372036854775807 |
| `long`      | `1111 1111 1111 1111 1111 1111 1111 1111`                    | -1                  |
| `int`       | `1111 1111 1111 1111 1111 1111 1111 1111`                    | -1                  |
| `short`     | `1111 1111 1111 1111`                                        | -1                  |
| `char`      | `1111 1111`                                                  | -1                  |

For the `float`, conversions work since a `float` is not represented in this way in binary.  Floating point conversion is therefore more likely to convert to a close approximation of the value required, although note that numbers are not rounded up but down.  The conversion to `char` follows standard binary conversion which is why the value is 43.  This is because C number conversion with floating point values follow certain rules:

- Find the smallest data type that the values will convert into with enough bits to get the entire value
- Convert value to common data type
- Convert to target data type

So, for example, the conversion from `float` to `char` is as follows:
$$
float \Rightarrow int \Rightarrow char
$$
Or in binary:
$$
\text{binary float} \Rightarrow \text{0000 0000 0000 0000 0000 0010 0010 1011} \Rightarrow \text{0010 1011}
$$
Value conversion is an important idea to grasp, and in particular when we move onto object-oriented programming with C++.  C does support more complex data types as well using the `struct` keyword.  Let us look at that next.

## Defining `struct`s

Having simple data types only provides us with so much capability.  In the real world we want to construct more complex data types to support our applications.  We do this using the `struct` keyword.  A `struct` is just a collection of values that we consider as a single value.

### A `struct` in Memory

Let us consider a simple example that we will use in our test application.  This `struct` will contain student details, and we define it as follows:

```c
struct student
{
    unsigned int id;
    char *name;
    char *address;
};
```

The student data type contains three values:

- An `unsigned int` used to represent the ID number of the student
- A `char*` (string) used to represent the student's name
- A `char*` (string) used to represent the student's address

We treat an variable of type `student` more or less as a normal data type, with some exceptions that we will cover shortly.  First let us consider how a value of type `student` is stored in memory. Below illustrates how the bytes are laid out to store the `student struct`.

| **Byte** | **Data** |
| -------- | -------- |
| 0        | ID       |
| 1        | ID       |
| 2        | ID       |
| 3        | ID       |
| 4        | name     |
| 5        | name     |
| 6        | name     |
| 7        | name     |
| 8        | address  |
| 9        | address  |
| 10       | address  |
| 11       | address  |

As can be seen, our data takes 12 bytes of storage, and is stored in the sequence of its declared member values.  There is no additional overhead in C or C++ for storing data in a `struct`.  We are just stating that a variable is of that type, and therefore the number of required bytes are stored.

### Accessing `struct` Members

To access a value in a `struct` we use the dot notation `.` to allow us to access members of the `struct`.  This is the same notation you are likely to remember from using Java.  This is a simple method to allow us to use a variable name and the name of the member to access its value:

```c
variable.member_name
```

We can get and set the member using this technique.  We will explore these concepts far more later in the module.

### Declaring a `struct` Variable

In C (not C++ as we will discover later in the module), we declare a variable of a `struct` type as follows:

```c
struct <type> <name>;
```

It is much the same as a standard variable declaration, except that we have to place the keyword `struct` in front of the type.  Otherwise, we have declared the variable as normal, and can access the values accordingly.

### Passing `struct` Values as Parameters

As when declaring a `struct` variable we must also use the keyword `struct` when passing as a parameter.  Again this is only in C.  Basically a parameter pass is the same as declaring a variable for the function.  It is just that we are providing that variable when we call the function.

### `struct` Test Application

Our test application for working with `struct` data types is below.  We are using our `student` data type, setting the values, and then printing the data type.

```c
#include <stdio.h>
#include <stdlib.h>

// A data structure containing student information
struct student
{
    unsigned int id;
    char *name;
    char *address;
};

// Prints student information
void print_student(struct student s)
{
    printf("id no: %u\n", s.id);
    printf("name: %s\n", s.name);
    printf("address: %s\n", s.address);
}

int main(int argc, char **argv)
{
    // Output size of the struct
    printf("Size of student struct is %d bytes\n", sizeof(struct student));
    // Create a student data structure
    struct student s;
    s.id = 1234;
    s.name = "Kevin Chalmers";
    s.address = "School of Arts";
    // Print student data
    print_student(s);
    
    return 0;
}
```

On line 23 we print the size of the `student struct`.  Based on what we know about the value we should be able to work this out:

- the `id` value is an `unsigned int` which is 4 bytes in size
- the `name` value is a `char*` which is 4 bytes in size
- the `address` value is a `char*` which is 4 bytes in size

Thus our `student` value should be 12 bytes in size.  Running this application (below) shows that this is the case.

```shell
Size of student struct is 12 bytes
id no: 42001290
name: Kevin Chalmers
address: School of Arts
```

Building complex data types that represent our real world data is very important.  We will investigate this further when we look at object-orientation later in the module.  However, we will use `struct` data occasionally from this point onwards.

## `enum` Values and `switch` Statements

Another data type we can declare is an `enum`.  An `enum` allows us to declare a collection of options that a value could take.  This is very useful for having easily read (to the programmer) code for ideas such as menu entries and system states.  An `enum` can replace a numerical value for this case.

An example `enum` declaration is given below:

```c
enum CHOICE
{
    EXIT = 0,
    HELLO = 1,
    GOODBYE = 2
};
```

Notice that we can also attach numerical values to our `enum` (although this is not required).  To declare a variable of this type we just do the following:

```c
CHOICE ch;
```

We can then set the value of this variable as follows:

```c
ch = HELLO;
```

`enum` values are about making your code easier to understand.  They are especially useful when working with `switch` statements.  Underneath, an `enum` is just an `int` value.  We are simply adding some *syntactic sugar* to our code to make it easier for others to understand.  A simple test application using `enum` and `switch` is given below:

```c
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
```

Running this application can give you an output as follows:

```shell
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
```

As you can see, `enum` values are very useful for working with menu like applications.  You should consider using them whenever possible to make your code easier to read.

## `const`

We now know how to declare values in C.  `struct` and `enum` is all C really provides in this regard.  Let us now move onto examining other type modifiers.  The first one we will look at is `const`.  A `const` value is one that cannot be changed -- it has a *constant* value.

To declare a `const` value we just put the `const` keyword before the variable type:

```c
const <type> <name>;
```

This can be used for variable declaration and for passing parameters into functions.  Below is an example program that tries to modify a `const` value.

```c
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
```

Trying to compile this application will give a compiler error as shown below:

```shell
Microsoft (R) C/C++ Optimizing Compiler Version 18.00.30501 for x86
Copyright (C) Microsoft Corporation.  All rights reserved.

constants.c
constants.c(12) : error C2166: l-value specifies const object
constants.c(22) : error C2166: l-value specifies const object
```

If you look at the code file you will see that it is lines 12 and 22 (as noted in the compiler error) that are at fault.  We are trying to modify a `const` value.  The error essentially states that the left hand side of the expression (the *l-value*) is `const`.

## `static` Values

Another type modifier that we can apply to our variables in C is `static`.  A `static` value is one that exists throughout the execution of the application.  This is especially useful for functions, where we declare variables for use in the function which only normally exist while that function is being used.  `static` allows a variable to retain its value after the function has ended.  A `static` value is one that has runtime context rather than just the standard context.  We will look at context and variable lifespan later in the module.

For just now, try the following example application.  It illustrates the basic idea of using a `static` value.

```c
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
```

Running this application provides the following output (suitably truncated):

```shell
x = 0
x = 1
x = 2
x = 3

....

x = 97
x = 98
x = 99
```

Using `static` variables like this is not that common, but it can be useful occasionally.  Object-orientation overcomes this requirement as we will find later.

## Exercises

1. Write an application that adds 1 to the maximum value of the standard data types and subtracts 1 from the minimum.  Your application should print out the values that you have after performing these operations.
2. Write an application that has a menu system using an `enum` and `switch` statement which provides the ability to enter a student's details, print the student's details, or exit the system.  Your application should only have one student variable in existence.  It should just overwrite the existing details when a new student is entered.
3. Develop another menu based application which asks the user if they want to print out a triangle, a Christmas tree, or their name surrounded by stars.  It should prompt the user for the size of the triangle / tree or their name based on the choice selected.  You should use functions to simplify your application.