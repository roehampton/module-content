# Software Development 2 Lab 03 -- Data Sizes and Data Representation

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
<script src="https://cdn.jsdelivr.net/npm/code-line"></script>
<script>CodeLine.initOnPageLoad({toggleBtn: {show: false}, copyBtn: {show: false}})</script>

<link rel="stylesheet" href="/module-content/css/block.css">


C++ is often referred to as a systems language as it provides a close approximation to how the computer works. As such, when we declare data in C++ it has a direct representation in memory. This has advantages when working with memory, but does mean we need to be more cautious in comparison to languages such as Java and C\# (which are often referred to as *managed languages*).

When it comes to working with data in C++, we have to understand how data is represented and how to find out the sizes of our data types. Memory size is also an important consideration when worrying about system performance and limitations.

## Getting the Size of Data Using `sizeof`

How big is a value? Well, that does actually depend on the system you are working in and the compiler you are using. In C++ we can use the `sizeof` function to get the size of a data type in bytes.

> **The `sizeof` Function**
>
> `sizeof` is a very useful function we will use when we work with memory allocation later in the module. It requires either a type or a value and will return the number of bytes used to represent the type or value.
>
> `sizeof` returns a value of type `size_t`.  Although this type is compiler specific, it is normally of type `unsigned int`.  We will typically just treat it as `int`.

Let us now test the size of the standard `int` type. The following application will print this value out for us.

1. **Create a new project for the below code.**
2. **Set your new project to the startup project.**
3. **Enter the code below.**
4. **Run and test your program. Document your output.**

```c++
#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char **argv)
{
    cout << "The size of int is " << sizeof(int) << " bytes" << endl;
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

1. **Create a new project for the below code.**
2. **Set your new project to the startup project.**
3. **Enter the code below.**
4. **Run and test your program. Document your output.**

```c++
#include <iostream>

using std::cout;
using std::endl;
using std::boolalpha;
using std::noboolalpha;

int main(int argc, char **argv)
{
    int a = -500;
    unsigned int b = -500;
    unsigned int c = (unsigned int)a;
    float f = -500;

    // Print out values as signed and unsigned
    cout << "a signed: " << a << " a unsigned: " << (unsigned int)a << endl;
    cout << "b signed: " << (int)b << " b unsigned: " << b << endl;
    cout << "c signed: " << (int)c << " c unsigned: " << c << endl;

    // Print out if values are equal
    cout << boolalpha << "a == b: " << (a == b) << noboolalpha << endl;
    cout << boolalpha << "a == c: " << (a == c) << noboolalpha << endl;
    cout << boolalpha << "a == f: " << (a == f) << noboolalpha << endl;
    
    return 0;
}
```

On line 7 and 8 we declare our `unsigned` values -- on line 7 the value is even set as negative.  Our `cout` statement tries to print all the values as `signed` and `unsigned`.  We also print out if the values are equal.  Running this application provides the following output:

```shell
a signed: -500 a unsigned: 4294966796
b signed: -500 b unsigned: 4294966796
c signed: -500 c unsigned: 4294966796
a == b: true
a == c: true
a == f: true
```

Notice that `cout` treats all the `int` values as if they were the same value.  This is because they have the same bit representation. C++ has undertaken a rather crude conversion between `signed` and `unsigned` values.

Looking at the equality tests though shows us that C++ does do more work here.  `a` is shown to be equal to `f`, although the bit representations are different.  This is because C++ will attempt to convert the values to the same type.  There are rules that govern this conversion.  You will learn them through practice.

## Minimum and Maximum Values of Data Types

Given that we can work out the size of a data type in bytes using `sizeof` and know the difference between `signed` and `unsigned` values and the overhead of having `signed` values, we are able to work out the maximum and minimum values of each type.  We could do this by hand, but we would have to do it for every system we compiled our programs for.  This isn't very efficient either.  Thankfully we have the `limits` header file which provides us with this information.

> **`limits`**
>
> The `limits` header file contains a collection of different values that define the minimum and maximum values of the standard types.  We will be looking at these shortly.  If you need to know the maximum or minimum of the standard values then include the `limits` header.

Let us do a quick test of finding out the limits. **Create and run the following application**:

```c++
#include <iostream>
#include <limits>

using std::cout;
using std::endl;
using std::numeric_limits;

int main(int argc, char **argv)
{
    cout << "unsigned int is " << sizeof(unsigned int);
    cout << " bytes, min value " << numeric_limits<unsigned int>::min();
    cout << " max value " << numeric_limits<unsigned int>::max() << endl;
    cout << "int is " << sizeof(int);
    cout << " bytes, min value " << numeric_limits<int>::min();
    cout << " max value " << numeric_limits<int>::max() << endl;
    return 0;
}
```

> **What is `numeric_limits`?**
>
> `numeric_limits` is a helper object that tells us information about a number type in C++. It can be quite useful when we want to know the minimum and maximum value storable in a type (which varies by the compiler).

Running this application will give the following result (based on your system).

```shell
unsigned int is 4 bytes, min value 0, max value 4294967295
int is 4 bytes, min value -2147483648, max value 2147483647
```

So we now know how to get the size of a value and also how to get the minimum and maximum values.  Let us combine these ideas into a single application.

## Number Types

The following application will print the sizes, minimum, and maximum values of the standard C++ types.  The application is below. It will output the data in a table format.

> **Setting Width of Output with `cout`**
>
> By default, `cout` will just display data as it is given. Sometimes, we may want to define the width of an output, for example when displaying a table of data. To do so we use the following:
>
> ```c++
> cout << setw(length) << output;
> ```
>
> `setw` is part of the `iomanip` library (IO MANIPulation). `cout` will now print the value and either fill with spaces up to `length`, or will cut the output based on `length`.

1. **Create a new project for the below code.**
2. **Set your new project to the startup project.**
3. **Enter the code below.**
4. **Run and test your program. Document your output.**

```c++
#include <iostream>
#include <string>
#include <limits>
#include <iomanip>

using std::cout;
using std::endl;
using std::string;
using std::numeric_limits;
using std::setw;

template<typename T>
void print_type(string type)
{
    cout << setw(20) << type;
    cout << setw(8) << sizeof(T);
    cout << setw(25) << +numeric_limits<T>::min();
    cout << setw(25) << +numeric_limits<T>::max();
    cout << endl;
}

int main(int argc, char **argv)
{
    cout << setw(20) << "Type" << setw(8) << "Size" << setw(25) << "Min" << setw(25) << "Max" << endl;
    print_type<unsigned char>("unsigned char");
    print_type<char>("char");
    print_type<unsigned short>("unsigned short");
    print_type<short>("short");
    print_type<unsigned int>("unsigned int");
    print_type<int>("int");
    print_type<unsigned long>("unsigned long");
    print_type<long>("long");
    print_type<unsigned long long>("unsigned long long");
    print_type<long long>("long long");
    print_type<float>("float");
    print_type<double>("double");
    print_type<long double>("long double");
    
    return 0;
}
```

> **What is the Magic `print_type` Function?**
>
> You should be able to work this out from our work on generic typing last week. Essentially, `print_type` takes a type parameter `T` which it uses with `sizeof` and `numeric_limits` when called. For example, the call `print_type<int>("int")` actually becomes the function:
>
> ```c++
> void print_type(string type)
> {
>     cout << setw(20) << type;
>     cout << setw(4) << sizeof(int);
>     cout << setw(25) << +numeric_limits<int>::min();
>     cout << setw(25) << +numeric_limits<int>::max();
>     cout << endl;
> }
> ```

> **Why no `unsigned` Floating Points?**
>
> We have used the floating-point values in this application, but we haven't defined any `unsigned` floating-point values.  This is because they don't exist as the CPU does not support `unsigned` floating-point values, therefore neither does C++.  All floating-point values are `signed`.

Running this application provides the following output. **Please ensure you look back through the code and check you understand what is happening.**

```shell
                Type    Size                      Min                      Max
       unsigned char       1                        0                      255
                char       1                     -128                      127
      unsigned short       2                        0                    65535
               short       2                   -32768                    32767
        unsigned int       4                        0               4294967295
                 int       4              -2147483648               2147483647
       unsigned long       4                        0               4294967295
                long       4              -2147483648               2147483647
  unsigned long long       8                        0     18446744073709551615
           long long       8     -9223372036854775808      9223372036854775807
               float       4              1.17549e-38              3.40282e+38
              double       8             2.22507e-308             1.79769e+308
         long double      16             3.3621e-4932            1.18973e+4932
```

The table provides an overview of the integer data types and their sizes based on our result of running this program using the Microsoft compiler on Windows.  Note that these data sizes are not consistent across other operating systems and compilers.  You should always check your data sizes in the environment you are working in.

| **Type**             | **Size (bytes)** | **Minimum Value** | **Maximum Value** |
| -------------------- | ---------------- | ----------------- | ----------------- |
| `unsigned char`      | 1                | 0                 | $2^8 - 1$         |
| `signed char`        | 1                | $-2^7$            | $2^7 - 1$         |
| `unsigned short`     | 2                | 0                 | $2^{16} - 1$      |
| `signed short`       | 2                | $-2^{15}$         | $2^{15} - 1$      |
| `unsigned int`       | 4                | 0                 | $2^{32} - 1$      |
| `signed int`         | 4                | $-2^{31}$         | $2^{31} - 1$      |
| `unsigned long`      | 4                | 0                 | $2^{32} - 1$      |
| `signed long`        | 4                | $-2^{31}$         | $2^{31} - 1$      |
| `unsigned long long` | 8                | 0                 | $2^{64} - 1$      |
| `signed long long`   | 8                | $-2^{63}$         | $2^{63} - 1$      |

### Fixed-width Number Types

To avoid the confusion that can occur with C++ number types, new number data types were introduced to support code reuse across compilers and architectures. Below is a summary of these new datatypes.

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

Now let us look at how the different methods of creating a string affect the data sizes allocated.  We have been using the `string` type in C++, but this isn't the only method to store strings. Indeed, in C++ a `string` is just a wrapper around what is called a *character pointer* (or `char*`). This is just a location in memory where we say character data is stored. To declare a string, we therefore have three techniques:

- Declaring a pointer to `char` in memory -- a `char*`.
- Declaring a fixed-size array of `char` (a list) -- a `char[]`.
- Declaring a `string`.

C++ treats these approaches in different ways.  Let us write a test application to see what happens:

```c
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

int main(int argc, char **argv)
{
    char *hello = "Hello World!";
    char goodbye[15] = "Goodbye World!";
    string str = "I'm another string";
    
    // Print the messages
    cout << "Hello message: " << hello << endl;
    cout << "Goodbye message: " << goodbye << endl;
    cout << "String: " << str << endl;
    
    // Get sizes
    cout << "Size of hello: " << sizeof(hello) << endl;
    cout << "Size of goodbye: " << sizeof(goodbye) << endl;
    cout << "Size of string: " << sizeof(str) << endl;

    // Get string length
    cout << "Length of hello: " << strlen(hello) << endl;
    cout << "Length of goodbye: " << strlen(goodbye) << endl;
    cout << "Length of string: " << str.length() << endl;
    
    return 0;
}
```

> **What is `strlen`?**
>
> `strlen` is a function that measures the length of a string in characters. It only works on `char*` types.

Running this application will give you the following output:

```shell
Hello message: Hello World!
Goodbye message: Goodbye World!
String: I'm another string
Size of hello: 4
Size of goodbye: 15
Size of string: 24
Length of hello: 12
Length of goodbye: 14
Length of string: 18
```

Let us look at the 6 sizes output:

1. `hello` is 4 bytes as it is a pointer to a string of character data.  A pointer is 4 bytes in size on a 32-bit machine (if you compile this in 64-bit the answer will be 8 bytes). `hello` is just a pointer -- it does not contain the data of the string.
2. `goodbye` is 15 bytes.  This is because we have created a fixed-size array, which C++ knows the size of.
2. `str` is 24 bytes. This is because we have created a `string` object which contains more than just the character data.
2. The length of `hello` is 12 characters -- which is correct if you count the characters. It is more than four bytes.
2. The length of `goodbye` is 14 characters -- which is correct if you count the characters. It is only one less than the size. This is due to a special character -- the null terminator -- which signifies the end of the string but is not part of its length.
3. The length of `str` is 18 characters -- which is correct if you count the characters. It is less than 24 bytes.

So the same general rules apply to sizing strings as they do to sizing other data types.  The new interesting value is the array size.  *This only works for fixed-size arrays*.  We will look at arrays in far more detail as we go through the module, and understand the limitations C++ has when working with array data. `string` also adds more memory usage. It doesn't look like much but can add up in memory-constrained applications.

## Defining `struct`s

Having simple data types only provides us with so much capability.  In the real world, we want to construct more complex data types to support our applications.  We do this using the `struct` keyword.  A `struct` is just a collection of values that we consider as a single value.

### A `struct` in Memory

Let us consider a simple example that we will use in our test application.  This `struct` will contain student details, and we define it as follows:

```c++
struct student
{
    unsigned int id;
    string name;
    string address;
};
```

The student data type contains three values:

- An `unsigned int` used to represent the ID number of the student
- A `string` used to represent the student's name
- A `string` used to represent the student's address

We treat a variable of type `student` more or less like a normal data type, with some exceptions that we will cover shortly.  First, let us consider how a value of type `student` is stored in memory. Below illustrates how the bytes are laid out to store the `student struct`.

| **Byte** | **Data** |
| -------- | -------- |
| 0        | ID       |
| 1        | ID       |
| 2        | ID       |
| 3        | ID       |
| 4        | name     |
| 5        | name     |
| ...      | name     |
| 27       | name     |
| 28       | address  |
| 29       | address  |
| ...      | address  |
| 51       | address  |

As can be seen, our data takes 52 bytes of storage and is stored in the sequence of its declared member values.  We are just stating that a variable is of that type, and therefore the number of required bytes are stored.

### Accessing `struct` Members

To access a value in a `struct` we use the dot notation `.` to allow us to access members of the `struct`.  This is the same notation you are likely to remember from using Java.  This is a simple method to allow us to use a variable name and the name of the member to access its value:

```c
variable.member_name
```

We can get and set the member using this technique.  We will explore these concepts far more later in the module.

### Declaring a `struct` Variable

We declare a variable of a `struct` type as follows:

```c
<type> <name>;
```

It is much the same as a standard variable declaration and can access the values accordingly.

### Passing `struct` Values as Parameters

Basically, a parameter pass is the same as declaring a variable for the function.  It is just that we are providing that variable when we call the function.

### `struct` Test Application

Our test application for working with `struct` data types is below.  We are using our `student` data type, setting the values, and then printing the data type.

```c++
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

// A data structure containing student information
struct student
{
    unsigned int id;
    string name;
    string address;
};

// Prints student information
void print_student(student s)
{
    cout << "id: " << s.id << endl;
    cout << "name: " << s.name << endl;
    cout << "address: " << s.address << endl;
}

int main(int argc, char **argv)
{
    // Output size of the struct
    cout << "Size of student struct is " << sizeof(student) << " bytes" << endl;
    // Create a student data structure
    student s;
    s.id = 1234;
    s.name = "Kevin Chalmers";
    s.address = "School of Arts";
    // Print student data
    print_student(s);
    return 0;
}
```

On line 23 we print the size of `studen`.  Based on what we know about the value we should be able to work this out:

- the `id` value is an `unsigned int` which is 4 bytes in size
- the `name` value is a `string` which is 24 bytes in size
- the `address` value is a `string` which is 24 bytes in size

Thus our `student` value should be 52 bytes in size.  But what does running the application tell us:

```shell
Size of student struct is 56 bytes
id: 1234
name: Kevin Chalmers
address: School of Arts
```

Building complex data types that represent our real world data is very important.  We will investigate this further when we look at object-orientation later in the module.  However, we will use `struct` data occasionally from this point onwards.

## Case Study -- Combining What We Know



```c++
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::getline;
using std::stoi;
using std::endl;
using std::setw;
using std::setfill;
using std::string;
using std::vector;

struct student
{
    unsigned int id;
    string name;
    string address;
};

void print_student(student s)
{
    cout << setw(12) << setfill('0') << s.id << setfill(' ');
    cout << setw(30) << s.name;
    cout << setw(40) << s.address;
    cout << endl;
}

student read_student()
{
    student s;
    string tmp;
    cout << "Enter id: ";
    getline(cin, tmp);
    s.id = stoi(tmp);
    cout << "Enter name: ";
    getline(cin, s.name);
    cout << "Enter address: ";
    getline(cin, s.address);
    return s;
}

int main(int argc, char **argv)
{
    vector<student> students;
    for (int i = 0; i < 10; ++i)
    {
        students.push_back(read_student());
    }
    cout << setw(12) << "ID Number";
    cout << setw(30) << "Name";
    cout << setw(40) << "Address";
    cout << endl;
    for (auto s : students)
    {
        print_student(s);
    }
    return 0;
}
```



## Exercises

1. Write an application that adds 1 to the maximum value of the standard data types and subtracts 1 from the minimum.  Your application should print out the values that you have after performing these operations.
2. Write an application that has a menu system using an `enum` and `switch` statement which provides the ability to enter a student's details, print the student's details, or exit the system.  Your application should only have one student variable in existence.  It should just overwrite the existing details when a new student is entered.
3. Develop another menu based application which asks the user if they want to print out a triangle, a Christmas tree, or their name surrounded by stars.  It should prompt the user for the size of the triangle / tree or their name based on the choice selected.  You should use functions to simplify your application.