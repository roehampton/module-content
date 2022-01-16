# Software Development 2 Lab 01 -- Getting Started with C++

<script src="https://cdn.jsdelivr.net/npm/code-line"></script>
<script>CodeLine.initOnPageLoad({toggleBtn: {show: false}, copyBtn: {show: false}})</script>
<script src="/module-content/script/links.js"></script>

<link rel="stylesheet" href="/module-content/css/block.css">

These tutorials are designed to teach you several C++ principles with sophisticated topics and examples. C++  is a general-purpose, high-level, compiled language. C++ is widely used in applications, operating systems, games development, and embedded system development. Its influence is seen in most modern programming languages. 

> **What does compiled mean?**
>
> Python is an interpreted language. That is, you write some code and then run it. If there are any mistakes, the program only fails when it tries to run code that is in error.
>
> C++ (and most common languages) are compiled. A program will first check the program and convert it into machine code. If there are errors in the program, it won't compile. There is no way of running a program that won't compile.

There are many ways you can develop in C++. Today there are three main compilers:

- GNU Compiler Collection – `gcc`
- `clang`
- Microsoft C/C++ Compiler – `cl`

We will use Microsoft’s compiler, although you can use any compiler. The C++ we use is a standard. How you compile programs will be different.

## Writing Your First C++ Application

**Watch the following video to get started with Visual Studio 2019.**

<iframe src="https://roehampton.cloud.panopto.eu/Panopto/Pages/Embed.aspx?id=65764892-d620-443e-9c13-ae1f016cf16a&autoplay=false&offerviewer=true&showtitle=true&showbrand=false&captions=true&interactivity=all" height="405" width="720" style="border: 1px solid #464646;" allowfullscreen allow="autoplay"></iframe>

C++ program begins inside a function called `main`. A function is simply a collection of commands that do *something*. The `main` function is always called when the program first executes. We can call other functions from `main`, whether they be written by us or by others or use built-in language features. To access the standard functions of your compiler, you need to include a header with the `#include` directive. Our first program is *Hello, World!*.

***TODO***

```c++
#include <iostream>

using std::cout;
using std::endl;

int main(int argc, char **argv)
{
    cout << "Hello, world!" << endl;
    return 0;
}
```

**NOTE** -- all executable code lines end with a semi-colon (`;`). This is important. If you forget a semi-colon, your program will fail to compile.

**NOTE** -- a function body starts with a `{` and ends with a `}`.

What does this program do?

- Line 1, we `#include` the `iostream` library. `iostream` means *input-output streams*. It allows us to use objects that output messages to the screen and input messages from the user.
- Line 3 states `using std::cout`. `std` is the *standard library*. The more important part is `cout` which is the default *character output* (the command line). This is what we will use to print a message to the screen.
- Line 4 states `using std::endl`. `endl` is the *end-of-line* character that prints a new line.
- Line 6 is the start of our main program. It has the signature `int main(int argc, char **argv)`:
  - `int` at the start is the *return type* of the main program. An `int` (*integer*) is a number.
  - `main` is the name of the function. Our main program must be called `main`.
  - `int argc` is a number that refers to the number of command-line arguments provided to the program. It is at least one -- the name of the program.
  - `char **argv` is the actual command-line arguments. We will return to what `char **` meand much later in the module.

- Line 8 is how we print a message to the command line. We send the message `Hello, world!` using `<<` to the `cout` object, followed by the endline character `endl`.
- Line 9 returns `0` (effectively *OK*) from the program.

## Reading Input From the User

We've performed the most straightforward program -- outputting to the command line. The next important thing we need is reading from the command line. We do so using the `cin` object.

**TODO**

1. **Create a new project for the below code.**
2. **Set your new project to the startup project.**
3. **Enter the code below.**
4. **Run and test your program. Document your output.**

```c++
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main(int argc, char **argv)
{
    string name;
    cout << "Enter your name: ";
    cin >> name;
    cout << "Hello " << name << endl;
    return 0;
}
```

As you can see, this program is very similar to the last one:

- Line 1 includes the `iostream` library.
- Line 2 includes the `string` library -- `string` is not a foundational type, unlike Python.
- Lines 4 to 7, we define our `using` statements for the objects we want: `cout`, `cin` (*character input* -- reads from the command line), `endl`, and `string`.
- Line 9 defines our main program. **Try and remember what the signature means -- then look back to check.**
- In line 11, we declare a new variable of type `string` called `name`.
  - This is how we define variables in C++: `type variable-name;`. Unlike in Python, where you only require the name.
- In line 12, we output a prompt to enter the user's name.
- In line 13, we read the user's name into the `name` variable. `cin` (character input) is streaming the user input into (`>>`) the `name` variable. **This is how user input works in C++.**
- Line 14, we output `Hello` followed by the entered name.
- In line 15, we return `0` (OK) from the program.

### Your Task

Extend the input program to check if the name entered is *Kevin*. To do so, we need an `if` statement. In C++, an `if` statement is:

```c++
if (test)
{
    // Do something
}
```

To check if our entered `name` value is `Kevin,` we can perform the following test:

```c++
if (name == "Kevin")
{
    // Do something
}
```

Update the program to output `Another Kevin!` if the name entered is *Kevin*.

## C++ Data Types

**Typing is one of the most important concepts in programming.** C++ is a *statically typed language*. In C++, a variable must have a data type. A variable must contain a value based on the type it has been declared with. This is unlike Python, where a variable can change type. For example:

- An `int` can only contain numbers. It cannot be a string; e.g., "hello".
- A `bool` can only contain `true` or `false,` not 54423.
- Etc.

C++ types are broken down as follows:

- Fundamental types:
  - `void` (no type).
  - `nullptr_t` (pointer to nothing).
  - Arithmetic types:
    - `float`, `double`, etc. -- numbers with a decimal point (e.g., 5.4334).
    - Integral (whole number) types:
      - `bool` for `true` and `false`.
      - `char` for a character, e.g., 'a', '5', etc.
      - Integers of various sizes (e.g., `int`, `signed short`).
  - Compound types (more on these later in the module):
    - References.
    - Pointers.
    - Arrays.
    - Functions.
    - Enumerations.
    - Classes.

For now, we are most interested in the foundational types, starting with the *Integers*.

### Integer Types

Integers come in different types based on two criteria:

- The size of the integer in bytes -- the more bytes, the greater the range of values that can be stored.
- Signing -- can the integer store negative numbers (`signed`) or only positive numbers (`unsigned`). The default is `signed`.

Combined, these criteria determine the greatest and smallest value that the integer can store.

- 8 bits (1 byte) = 2<sup>8</sup> (2 * 2 * 2 * 2 * 2 * 2 * 2 *2 = 256) possible values.
- 16 bits (2 bytes) = 2<sup>16</sup> (65,536) possible values.
- 32 bits (4 bytes) = 2<sup>32</sup> (4,294,967,296 -- over 4 billion) possible values.
- 64 bits (8 bytes) = 2<sup>64</sup> (18,446,744,073,709,551,616 -- over 18 quintillion or 18 billion billion) possible values.

C++ integer sizes are not 100% uniform, but in a standard Microsoft C++ compiler, the following sizes and minimum and maximum values are available.

| **Type**             | **Size** | **Value range**                                         |
| -------------------- | -------- | ------------------------------------------------------- |
| `char`               | 1 byte   | -128 to 127                                             |
| `unsigned char`      | 1 byte   | 0 to 255                                                |
| `short`              | 2 bytes  | -32,768 to 32,767                                       |
| `unsigned short`     | 2 bytes  | 0 to 65535                                              |
| `int`                | 4 bytes  | -2,147,483,648 to 2,147,483,647                         |
| `unsigned int`       | 4 bytes  | 0 to 4,294,967,295                                      |
| `long`               | 4 bytes  | -2,147,483,648 to 2,147,483,647                         |
| `unsigned long`      | 4 bytes  | 0 to 4,294,967,295                                      |
| `long long`          | 8 bytes  | -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 |
| `unsigned long long` | 8 bytes  | 0 to 18,446,744,073,709,551,615                         |

> **Why is `char` a Number?**
>
> Although we mentioned that `char` represents a character, a character is defined by ASCII (American Standard Code for Information Interchange), where a number is used for characters. You can read more about ([ASCII - Wikipedia](https://en.wikipedia.org/wiki/ASCII)).

To get the exact size of a type or a variable on a particular platform, you can use the sizeof operator. The expression `sizeof(type)` yields the storage size of the object or type in bytes.

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
    cout << "Size of short: " << sizeof(short) << " bytes" << endl;
    cout << "Size of int: " << sizeof(int) << " bytes" << endl;
    cout << "Size of long: " << sizeof(long) << " bytes" << endl;
    cout << "Size of long long: " << sizeof(long long) << " bytes" << endl;
    return 0;
}
```

When run, you should get the following output.

```shell
Size of short: 2 bytes
Size of int: 4 bytes
Size of long: 4 bytes
Size of long long: 8 bytes
```

### Floating-Point Types

Floating-point data types are numbers with a decimal point, e.g., 3.14159. C++ provides three different floating-point types:

- `float` -- the primary floating-point type commonly used.
- `double` -- larger than `float`, allowing more precision (more numbers after the decimal point).
- `long double` -- larger than `double`.

The following program will let you see how many bytes each floating-point type uses.

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
    cout << "Size of float: " << sizeof(float) << " bytes" << endl;
    cout << "Size of double: " << sizeof(double) << " bytes" << endl;
    cout << "Size of long double: " << sizeof(long double) << " bytes" << endl;
    return 0;
}
```

### C++ Functions and the `void` Type

The `void` type specifies that no specific type is available. It is used in three kinds of situations:

- Functions return void -- the function doesn't return a value.
- Function arguments as void -- the function does not accept any parameters. Generally, we don't add this.
- Pointers to void -- in this instance, we have a pointer to a block of memory that we don't know the type of. We will return to pointers much later in the module.

Staying with functions, let us write a program that introduces C++ functions.

1. **Create a new project for the below code.**
2. **Set your new project to the startup project.**
3. **Enter the code below.**
4. **Run and test your program. Document your output.**

```c++
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

void print_name(string name)
{
    cout << "Hello " << name << endl;
}

string get_name()
{
    string name;
    cout << "Enter your name: ";
    cin >> name;
    return name;
}

int main(int argc, char **argv)
{
    string name = get_name();
    print_name(name);
    return 0;
}
```

Let us consider some of these lines of code.

- Line 9 defines the `print_name` function. It has the following signature:
  - `void` is the return type -- therefore, it does not return anything.
  - `print_name` is the name of the function we use to call it.
  - The function takes one parameter -- `string name`. The parameter is called `name` and is of type `string`.
- Line 14 defines the `get_name` function. It has the following signature:
  - `string` is the return type.
  - `get_name` is the name of the function we use to call it.
  - The function takes no parameters.
- Line 24 calls the `get_name` function, using it to set the variable `name`.
- Line 25 calls the `print_name` function, passing `name` as a parameter.

#### Your Task

Add a third method `check_name` that returns true if the name is Kevin and false otherwise. Use the value returned from the function to print `Another Kevin!` if necessary. To help, the signature of the function should be:

```c++
bool check_name(string name)
{
    // Your code here.
}
```

## C++ Variables

A variable declaration in C++ looks as follows:

```c++
type name;
```

For example:

```c++
int number;
float length;
string name;
```

That is:

- We **must** define the type of the variable.
- We **must** give the variable a name.

The *type* defines how much memory a variable will use. This is used during compilation, so our program knows what resources are required. Each variable in C++ has a specific type, which determines the size and layout of the variable's memory; the range of values stored within that memory; and the set of operations that can be applied to the variable. The name of a variable can be composed of letters, digits, and the underscore character. It must begin with either a letter or an underscore. Upper and lowercase letters are distinct because C++ is case-sensitive.

### Variable Declarations in C++

In C++, we must declare variables before we use them. It is pretty common to declare your necessary variables at the start of a function, although it isn't required. The following program will illustrate.

1. **Create a new project for the below code.**
2. **Set your new project to the startup project.**
3. **Enter the code below.**
4. **Run and test your program. Document your output.**

```c++
#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main(int argc, char **argv)
{
    char charValue;
    short shortValue;
    int intValue;
    float floatValue;
    string stringValue;

    cout << "Enter a char: ";
    cin >> charValue;
    cout << "You entered: " << charValue << endl;
    cout << "Enter a short: ";
    cin >> shortValue;
    cout << "You entered: " << shortValue << endl;
    cout << "Enter an int: ";
    cin >> intValue;
    cout << "You entered: " << intValue << endl;
    cout << "Enter a float: ";
    cin >> floatValue;
    cout << "You entered: " << floatValue << endl;
    cout << "Enter a string: ";
    cin >> stringValue;
    cout << "You entered: " << stringValue << endl;

    return 0;
}
```

> **`cin` is (Somewhat) Clever**
>
> `cin` will generally know how to read in that value based on its type. So, we can read in an `int`, `float`, `string`, etc., reasonably easily. C++ is unlike some other languages where you must convert the input string to the correct type (e.g., through parsing).

An example run of this program is.

```shell
Enter a char: a
You entered: a
Enter a short: 45
You entered: 45
Enter an int: 10000000
You entered: 10000000
Enter a float: 45.034
You entered: 45.034
Enter a string: hello
You entered: hello
```

#### Your Tasks

1. Try and enter values that are different from the expected types and document what happens. For example:
   - Enter `abc` for `char` rather than a single character.
   - Enter `2000000` for `short` (a greater value than it can store).
   - Enter `45.034` for `int`.
   - Enter `hello` for `float`.
   - Can you think about what we might have to do to avoid these issues (hint -- it is what you have to do in Python).
2. What happens when you remove one of the variable definitions (e.g., line 14) and try and run the program?

## C++ Arithmetic Operators

An arithmetic operator performs mathematical operations such as addition, subtraction, multiplication, division etc., on numerical values (constants and variables). C++ supports the basic arithmetic operators you will be familiar with from Python.

- `+` for addition.
- `-` for subtraction.
- `*` for multiplication.
- `\` for division.
- `%` to get the remainder from a division.

Below is a program that demonstrates each of these operations.

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
	int a = 9;
    cout << "a = " << a << endl;
    int b = 4;
    cout << "b = " << b << endl;
    int c = a + b;
    cout << "a + b = " << c << endl;
    c = a - b;
    cout << "a - b = " << c << endl;
	c = a * b;
    cout << "a * b = " << c << endl;
    c = a / b;
    cout << "a / b = " << c << endl;
	c = a % b;
    cout << "Remainder of a / b = " << c << endl;
	return 0;
}
```

Your output should be as follows. **Double check you have the correct output**:

```shell
a = 9
b = 4
a + b = 13
a - b = 5
a * b = 36
a / b = 2
Remainder of a / b = 1
```

### Summing User Input

As a final example this week, let us write a program that reads input from the user and sums the input numbers until the user enters zero.

1. **Create a new project for the below code.**
2. **Set your new project to the startup project.**
3. **Enter the code below.**
4. **Run and test your program. Document your output.**

 ```c++
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main(int argc, char **argv)
{
    int sum = 0;
    int num = -1;
    while (num != 0)
    {
        cout << "Enter a number: ";
        cin >> num;
        sum += num;
    }
    cout << "Total: " << endl;
    return 0;
}
 ```

> **`while` Loop in C++**
>
> A `while` loop in C++ is similar to Python. We state `while (condition),` and the program will run the code until the condition is false. In the example above, we use the condition `num != 0` -- *num is not equal to zero*.

### Your Task

Write C++ programs that do the following and describe the result:

1. A program that divides an integer by zero and prints the result.
2. A program that reads in a number from the user and increments a counter by one if the number is greater than zero and decrements a counter by one if the number is less than zero. The program should loop until zero is entered, and then it should display the value of the counter and exit.