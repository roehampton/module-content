# Software Development 2 Lab 02 -- Dynamic, Static, and Generic Typing

<script src="https://cdn.jsdelivr.net/npm/code-line"></script>
<script>CodeLine.initOnPageLoad({toggleBtn: {show: false}, copyBtn: {show: false}})</script>
<link rel="stylesheet" href="/module-content/css/block.css">

In this lab, we will explore three different methods of typing: dynamic, static, and generic. These forms of typing change how you approach writing a program and therefore change how you build a solution to a problem. A general overview of these different forms of typing is:

- **Dynamic typing** allows a variable to change type during program execution. A variable does not have a fixed type in a dynamically typed language.
- **Static typing** means a variable cannot change type during execution. A variable has a fixed type and can only store values of that type. An integer cannot store a string `"hello"`. Storing an incorrect value in a variable causes an error.
- **Generic typing** is where the type itself is a parameter; we can set the type when using the function or object. We will explore generic typing shortly. It is a powerful feature of programming languages.

## Dynamic and Static Typing

Python is an example of a dynamically typed language. It is perfectly legal Python to write:

```python
num = 5
num = "hello"
```

C++ is a statically typed language. Code as the above will not compile in C++. The equivalent code is below:

1. **Create a new project for the below code.**
2. **Set your new project to the startup project.**
3. **Enter the code below.**
4. **Try running the code. What is the error you receive? Do you understand the problem?**

```cpp
int main(int argc, char **argv)
{
    int num = 5;
    num = "hello";
    return 0;
}
```

> **Working with Compiler Errors**
>
> A skill you must develop as a programmer is understanding compiler errors. These errors are telling you what the problem is with your code, and also tell you the line number of the problem. You will find fixing these errors is a bigger task than the simple idea of writing new code.

## Casting Between Types -- Numbers

A good question to ask now is how we change between different types. For example, if we have an `int`, `5` but we want to work with a `float` what do we do? We use a technique called *typecasting*. It takes the following form:

```c++
new_type a = new_type(b);
```

For example:

```c++
float f = float(num);
```

Here, we are converting the variable `num` from its current type to a `float`. *Casting between types is an important skill in statically typed languages, especially when working with object orientation.* Let us examine an example program.

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
    int myInt = 100;
    float myFloat = float(myInt);
    cout << "int = " << myInt << " float = " << myFloat << endl;
    myFloat = 255.767f;
    myInt = int(myFloat);
    cout << "int = " << myInt << " float = " << myFloat << endl;
    return 0;
}
```

The output from the following program will be:

```shell
int = 100 float = 100
int = 255 float = 255.767
```

**Note** -- when converting from `float` to `int` we just drop the value after the decimal point. *The number is not rounded -- the fraction is trimmed.*

### Problems with Casting 1 -- Losing Information

Casting between types has to be considered carefully. We saw the issue of casting between a `float` and an `int`, but there are other issues.

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
    long long num64 = 9000000000000L;
    cout << "long long " << num64 << endl;
    int num32 = int(num64);
    cout << "int " << num32 << endl;
    short num16 = short(num32);
    cout << "short " << num16 << endl;
    char num8 = char(num16);
    cout << "char " << +num8 << endl;
    return 0;
}
```

> **Some Notes -- L and +**
>
> Two things we've done in this program:
>
> - We declared 9000000000000L (with an L at the end). This tells the compiler we want a *long* number. If we don't put the L we would get a compiler error.
> - We used `cout` for `num8` as `+num8`. This is to force `cout` to print the numerical value of `num8` rather than a `char`.

Your output will be as follows:

```c++
long long 9000000000000
int 2043514880
short -28672
char 0
```

**What is happening here? It makes no sense!**

Well, it does, if you think about how numbers are represented in the computer -- a string of binary digits. Let us start with `long long` of `9000000000000`:

`0000 0000 0000 0000 0000 10000 0010 1111 0111 1001 1100 1101 1001 0000 0000 0000`

Our `long long` has 64 bits. When we cast this to an `int` we remove the first 32 bits. That is:

~~`0000 0000 0000 0000 0000 10000 0010 1111`~~`0111 1001 1100 1101 1001 0000 0000 0000`

The remaining binary represents `2043514880`. When we cast to `short`:

~~`0111 1001 1100 1101`~~ `1001 0000 0000 0000`

Which represents `-286672` (we'll come to why this is negative soon). The casting to `char` (an 8 bit value) leaves us with:

~~`1001 0000`~~ `0000 0000`

Which is zero.

#### Your Task

Write the above program in reverse. That is, start with a `char` (say equal to `100`) and then cast the value upwards from `char` to `short`, then `int` and finally `long long`. What is the output? Do you understand why?

### Problems with Casting 2 -- `signed` and `unsigned`

A related problem in C++ is when we cast from unsigned values to signed values. Try the following.

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
    unsigned int unum = 4000000000;
    int num = int(unum);
    cout << "unsigned " << unum << " signed " << num << endl;
    return 0;
}
```

Your output will be:

```shell
unsigned 4000000000 signed -294967296
```

*So why does this result in a negative number? How are negative numbers represented?* For this we need to understand **two's compliment.**

#### Negative Number Representation and Two's Compliment

In decimal numbers (i.e., 0 to 9), we use `-` to denote a negative number. But computers only have two values to use -- 0 and 1. How do we represent negative numbers then? We use a method called two's complement.

In two's complement, we use one bit of the value to denote that it is negative. This is the left-most digit. For example, let us consider an 8-bit value:

0xxx xxxx -- this is a positive value.

1xxx xxxx -- this is a negative value.

With this in mind, how do we convert a positive value to a negative one? We use two's complement. This is where we flip the bits of the positive number, and then add 1. The following table illustrates:

| **Positive value** | **Bits**  | **Inverse bits** | **Two's complement (inverse + 1)** | **Negative value** |
| ------------------ | --------- | ---------------- | ---------------------------------- | ------------------ |
| 0                  | 0000 0000 | 1111 1111        | 0000 0000                          | 0                  |
| 1                  | 0000 0001 | 1111 1110        | 1111 1111                          | -1                 |
| 2                  | 0000 0010 | 1111 1101        | 1111 1110                          | -2                 |
| 20                 | 0001 0100 | 1110 1011        | 1110 1100                          | -20                |
| ...                |           |                  |                                    |                    |

Two's complement is also how we subtract numbers in binary. Let's say we have 12 and we want to subtract 4.

|      | **Bits**  | **Comment**                            |
| ---- | --------- | -------------------------------------- |
|      | 0000 1100 | 12 in binary                           |
| +    | 1111 1100 | -4 in binary (0000 0100 --> 1111 1100) |
|      | 0000 1000 | 8 in binary                            |

**If you are unsure how the addition worked for binary, ask the module tutor.**

## Generic Typing

Generic typing is a technique we see in statically typed languages to aid code reuse. It is normally seen when working with collections (e.g., lists and dictionaries). As you should have explored lists and dictionaries in Python, we will explore generic typing first through these examples.

### Lists

Remember in Python we can store lists of items using the square bracket notation -- `[1, 2, 3, 4]`. As Python is dynamically typed, we can just store items in our list without much concern. So, in Python, we can write the following program:

```python
data = []
for i in range(10):
    str = input("Enter data: ")
    data.append(str)
data.sort()
for str in data:
    print(str)
```

In C++, this doesn't work. We need to know the type of data we are working with. In C++, we cannot just say:

```c++
list = [1, 2, 3, 4, 5];
```

`list` needs a type. But what type is `list`? Do we create a `list` for each type (e.g., `int_list`, `float_list`, etc.)? That would be inefficient. This is where generic typing comes in.

In C++, we can type certain functions and objects using a generic type. In C++, we use a `vector` for a list, and if we want a list of type `int` we denote it as `vector<int>`. The compiler takes care of ensuring the correct types are used. The general syntax for generics is:

```c++
type<generic> name;
```

For example, with our `vector` type, we can declare different containers as follows:

```c++
vector<float> float_list;
vector<int> int_list;
vector<string> string_list;
vector<student> student_list;
```

Generics mean we only write the `vector` code once and then can reuse it. Let us build an example program.

1. **Create a new project for the below code.**
2. **Set your new project to the startup project.**
3. **Enter the code below.**
4. **Run and test your program. Document your output.**

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::sort;

int main(int argc, char **argv)
{
    // Equivalent to line 1 in Python code
    vector<string> data;
    // Equivalent to line 2 in Python code
    for (int i = 0; i < 10; ++i)
    {
        // These three lines are equivalent to line 3 in Python code
        string str;
        cout << "Enter data: ";
        cin >> str;
        // Equivalent to line 4 in Python code
        data.push_back(str);
    }
    cout << "Sorting..." << endl;
    // Equivalent to line 5 in Python code
    sort(data.begin(), data.end());
    // Equivalent to line 6 in Python code
    for (string str : data)
    {
        // Equivalent to line 7 in Python code
        cout << str << endl;
    }
    return 0;
}
```

> **`for` Loops in C++**
>
> We have also introduced C++ `for` loops in this program. There are two types:
>
> `for (initialiser; condition; change)`
>
> Is the most common type of `for` loop. It allows us to loop over a range. For example:
>
> `for (int i = 0; i < 10; ++i)`
>
> Means to loop 10 times. To break down the parts of the loop:
>
> - **Initialiser** -- sets the starting state; `int i = 0`.
> - **Condition** -- loops while the condition is true; `i < 10`. The loop will keep going until `i` is 10 or greater.
> - **Change** -- what happens at the end of each loop; `++I` means increment (add one to) `i`.
>
> `for (int i = 0; i < 10; ++i)` is equivalent to `for i in range(0, 9):` in Python. But as we are not using `i` in our application we can just write `for i in range(10):` (which goes from 1 to 10 rather than 0 to 9).
>
> The second type of `for` loop in C++ is across a collection, such as a `vector`. This takes the form:
>
> `for (type name : collection)`
>
> For example, we can use:
>
> `for (string str : data)`
>
> Each iteration through the loop will set `str` to the next value in the collection. This is equivalent to `for str in data:` in Python.

> **Comparing C++ and Python Code**
>
> One thing we hope you are noticing is how similar Python and C++ code can be when it comes to actual executing code. Yes, C++ requires more imports, setup, type declarations, etc. But this is due to the age of the language as well as it being statically typed. Fundamentally, the program is the same -- **and you should start recognising this.** Most problems are solvable in the same way with different programming languages. Start thinking about how to solve the general problem rather than implementation details for a specific language.

#### Your Task

Modify the above program so you read in `int` rather than a `string` (you only need to change a few lines). Reflect on the what you would have to do in Python to make this work. Do you think the change to C++ is easier to understand than that for Python.

### Dictionaries

The other data store you would have used in Python is the dictionary, denoted by curly brackets `{ }`. For example, we can create a Python dictionary program as follows:

```python
lecturers = { }
lecturers["Software Development 2"] = "Kevin"
lecturers["Software Development 1"] = "Arturo"
lecturers["Databases"] = "Wei"
lecturers["Computer Systems"] = "Oge"
for first, second in lecturers.items():
    print(first, " ", second)
```

In C++, we have to use a `unordered_map` type to act as a dictionary. It has two type parameters -- *one for the key*, and *one for the value*. Therefore, we would declare an `unordered_map` as follows:

```c++
unordered_map<string, string> data;
```

Let us look at an example.

1. **Create a new project for the below code.**
2. **Set your new project to the startup project.**
3. **Enter the code below.**
4. **Run and test your program. Document your output.**

```cpp
#include <iostream>
#include <string>
#include <unordered_map>

using std::cout;
using std::endl;
using std::string;
using std::unordered_map;

int main(int argc, char **argv)
{
    // Equivalent to line 1 in Python code
    unordered_map<string, string> lecturers;
    // Equivalent to lines 2 to 5 in Python code
    lecturers["Software Development 2"] = "Kevin";
    lecturers["Software Development 1"] = "Arturo";
    lecturers["Databases"] = "Wei";
    lecturers["Computer Systems"] = "Oge";
    // Equivalent to line 6 in Python code
    for (auto entry : lecturers)
    {
        // Equivalent to line 7 in Python code
        cout << entry.first << " " << entry.second << endl;
    }
    return 0;
}
```

> **The `auto` Keyword**
>
> On line 19 of the C++ code we use a new keyword -- `auto`. What does this do?
>
> `auto` means we will let the compiler work out the type for us. This can be *extremely useful* when types get complicated. For example, the type of `entry` above is actually:
>
> ```c++
> pair<const string, string>
> ```
>
> Which is quite a lot to type out, and we'd have to explain what a `pair` is, and why the first parameter is `const`. `auto` makes our life easier. **However, `auto` is not dynamic typing -- it is compile-time typing and still static.**

### How Does Generic Typing Work in C++? Creating a Generic Typed Function

So how does generic typing work in C++? We have to declare something as using a `template`, declare a type as a variable, and then use it accordingly. For example:

```c++
template<typename T>
T my_function(T value)
{
    // ...
}
```

Here we have declared `my_function` as taking a type parameter `T` which is used as the return type of the function and for one of the parameter. If we were to call the function with `float` as the type:

```c++
float num = my_function<float>(5.0f);
```

Then the compiler will generate the following code:

```c++
float my_function(float value)
{
    // ...
}
```

If we used `string`:

```c++
string my_function(string value)
{
    // ...
}
```

And so on. The compiler generates the code we need. Below is an example.

1. **Create a new project for the below code.**
2. **Set your new project to the startup project.**
3. **Enter the code below.**
4. **Run and test your program. Document your output.**

```c++
#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::string;

template<typename T>
T my_add(T left, T right)
{
    return left + right;
}

int main(int argc, char **argv)
{
    auto num = my_add<int>(5, 4);
    cout << "num = " << num << endl;
    auto str = my_add<string>(string("Hello, "), string("world!"));
    cout << "str = " << str << endl;
    auto num2 = my_add<float>(5.0f, 10.0f);
    cout << "num2 = " << num2 << endl;
    auto logic = my_add<bool>(true, false);
    cout << "logic = " << logic << endl;
    return 0;
}
```

> **Why Does `bool` Print as `1`?**
>
> Basically, `bool` is still a number. The general rule is:
>
> - `false` is `0`
> - `true` is not `0`, and normally `1`
>
> So `true + false` is just `1 + 0 = 1`.

## Longer Example -- Generate Random Numbers

Let us now look at a longer example using generic types and `auto` -- random number generation. Random number generation in C++ is quite complex, but that is because the C++ standard library provides lots of control on how random numbers are generated.

1. **Create a new project for the below code.**
2. **Set your new project to the startup project.**
3. **Enter the code below.**
4. **Run and test your program. Document your output.**

```c++
#include <iostream>
#include <random>

using std::cout;
using std::cin;
using std::endl;
using std::random_device;
using std::uniform_int_distribution;

int main(int argc, char **argv)
{
    random_device random;
    uniform_int_distribution<int> distribution(1, 50);
    auto answer = distribution(random);
    int guess = -1;
    while (guess != answer)
    {
        cout << "Enter guess: ";
        cin >> guess;
        if (guess < answer)
        {
            cout << "Too low" << endl;
        }
        else if (guess > answer)
        {
            cout << "Too high" << endl;
        }
        else
        {
            cout << "Correct!" << endl;
            break;
        }
    }
    return 0;
}
```

There are three lines of interest here:

- **Line 12** creates a `random_device`. This is a link to hardware on the computer that can generate random numbers, if available. The `random_device` will generate random numbers, but they will range from 0.0 to 1.0 (and the possible values inbetween).
- **Line 13** creates a `uniform_int_distribution` ranging from 1 to 50. This is used to convert the random number (range 0.0 to 1.0) to a number between 1 and 50. It is uniform as it ensures that the numbers are evenly spread across the range 1 to 50.
- **Line 14** generates the random number. We use `distribution(random)` to use the `random_device` to give a random number to the `uniform_int_distribution` which converts the value to between 1 and 50.

## Your Task

For the end of lab exercise, you will extend the random number generation program to run a lottery simulation. The program will do the following:

1. It will generate six random numbers between 1 and 50 and store them in a `vector`. Each of the six random numbers should be unique -- no duplicates in the `vector`.
2. It will sort the `vector`.
3. It will then ask the user to input their six numbers ensuring no duplicates are entered.
4. The program will then check how many numbers the user has as a match to the randomly selected numbers, and output this number to the command line (e.g., `You matched 3 numbers`).
5. The program will loop, asking the user for numbers, until the user enters 0.