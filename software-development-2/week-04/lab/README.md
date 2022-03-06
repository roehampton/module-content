# Software Development 2 Lab 04 -- Program Tracing

<script src="https://cdn.jsdelivr.net/npm/code-line"></script>
<script>CodeLine.initOnPageLoad({toggleBtn: {show: false}, copyBtn: {show: false}})</script>

<link rel="stylesheet" href="/module-content/css/block.css">

So far, we have been writing code and trying to fix errors as we go, hoping that the compiler will detect any problems we have. But what if our logic is incorrect? How do we find and resolve errors? You will find that this takes a significant amount of the work you will do as a programmer -- finding bugs and fixing them. Let us now practice reading code.

## Reading Code

In the following code fragments, you will be asked the outcome of the program. **Do not type in the program first -- work out the code and then try entering the program to check your understanding. **

### Exercise One -- Reading a `for` Loop

Below is a simple `for` loop. **What is the value of `x` at the end of the program?** Some help:

- `*=` is just a shortcut. `x *= i;` is the same as `x = x * i;`.
- Work through the `for` loop step by step.
  - Initial value of `x` is `0`
  - First loop: `x *= 0`. So what is the value of `x` after this operation?
  - Second loop: `x *= 1`. So what is the value of `x`?
  - ... up to tenth loop.

```c++
int x = 0;
for (int i = 0; i < 10; ++i)
{
    x *= i;
}
cout << x << endl;
```

**Enter the program (you'll have to remember the appropriate `include` and `using` statements) and check your answer.**

### Exercise Two -- Modulus Operator

In the following example, we introduce the modulus operator `%`. This gets the remainder of dividing one number by another. For example:

- `2 % 2 == 0`
- `2 % 3 == 1`
- `10 % 4 == 2`
- `15 % 5 == 0`

`+=` is another shortcut operator. `x += 1` is the same as `x = x + 1`.

**What is the value of `x` at the end of this program?** Again, take each iteration through the loop one at a time:

- The initial value of `x` is `0`.
- First attempt at loop, `x` is less than `10` (`0 < 10`), so loop will execute this time.
- Check if `x` is divisible by `2` and manipulate `x` accordingly.
- Check if `x < 10`, if so run loop again.
- Keep going until `x >= 10`.

```c++
int x = 0;
while (x < 10)
{
    if (x % 2 == 0)
    {
        x += 1;
    }
    else
    {
        x *= 2;
    }
}
cout << x << endl;
```

**Enter the program (you'll have to remember the appropriate `include` and `using` statements) and check your answer.**

### Exercise Three -- More Loops and Modulus

You will start receiving less guidance now. **What is the output (the value of `num`) at the end of this program?** Remember to work through each step of the loop one at a time to start with, but you might want to short cut after you recognise the pattern.

```c++
int num = 0;
for (int i = 1; i <= 1000; ++i)
{
    if (i % 3 == 0 || i % 5 == 0)
    {
        num += i;
    }
}
cout << num << endl;
```

**Enter the program (you'll have to remember the appropriate `include` and `using` statements) and check your answer.**

### Exercise Four

Below is the next exercise. You might be able to work out what the program does based on the variable names. There are two new features in the program:

- `sqrt` gets the square root of a number. For example, `sqrt(9)` will return `3`.
- `break` exits the current loop. That means, when `break` is encountered below, the inner `for` loop is exited and control returned to the outer `for` loop.

**What is the output from this program?**

```c++
for (int n = 1; n <= 1000; ++n)
{
    bool prime = true;
    for (int i = 0; i < sqrt(n); ++i)
    {
        if (n % i == 0)
        {
            prime = false;
            break;
        }
    }
    if (prime)
    {
        cout << n << endl;
    }
}
```

**Enter the program (you'll have to remember the appropriate `include` and `using` statements) and check your answer.**

### Exercise Five -- Passing by Reference

This is a two part exercise. **What do you think the value of `x` is at the end of this program?**

```c++
void change(int x)
{
    x = 100;
}

int main(int argc, char **argv)
{
    int x = 5;
    change(x);
    cout << x << endl;
    return 0;
}
```

**Enter the program (you'll have to remember the appropriate `include` and `using` statements) and check your answer.**

When you pass a variable as a parameter of a function, **a copy of the value is created.** So for the code above, the answer is `x == 5`. When the function `change` is called, `x` is copied into the function. *It is a different value in memory.*

We can pass a **reference** to a value in C++. A *reference* is a not a copy, but points to the same memory location. **Reference types** are another type that C++ (and most modern languages) also supports. To declare that a variable or parameter is a reference type, we use `&`:

```c++
void change(int &x)
{
    // ...
}

int main(int argc, char **argv)
{
    int x = 5;
    int &y = x;
}
```

**A reference cannot be initialised with a value, it must point to an existing variable.** References are the same value. When you change a reference, you change all values pointing to that location in memory. It has two advantages:

- It minimises memory copying -- a relatively expensive process.
- It allows a program to manipulate data that can be seen in other areas of a program, thus avoiding global variables.

So, given what we've just described, **what do you think the value of `x` is at the end of this program?**

```c++
void change(int &x)
{
    x = 100;
}

int main(int argc, char **argv)
{
    int x = 5;
    change(x);
    cout << x << endl;
    return 0;
}
```

**Enter the program (you'll have to remember the appropriate `include` and `using` statements) and check your answer.**

### Exercise Six -- Working with Files

We will cover reading and writing to files in more depth as we work through the module. However, let us introduce an example now.

- `ifstream` is used to read data from a file.
- `ofstream` is used to write data to a file.

These are both *stream objects.* That is, they behave like `cout` and `cin`. Once you have opened the file in this way, then you can just act as if you are reading and writing to the command line.

**Can you work out what the following program does? Again, you might be able to work this out quickly by looking at a couple of lines of code.**

```c++
ifstream file("data.txt");
vector<int> data;
while (file)
{
    string x;
    file >> x;
    int y = stoi(x);
    data.push_back(y);
}
sort(data.begin(), data.end());
ofstream output("output.txt");
for (int i = 0; i < data.size(); ++i)
{
    output << i << endl;
}
```

**Enter the program (you'll have to remember the appropriate `include` and `using` statements) and check your answer. `ifstream` and `ofstream` require the `fstream` include file. You will also need to create a file `data.txt` to read from that contains a list of numbers.** 

### Exercise Seven -- More Work with Files

**What is the output from the following program?**

```c++
ifstream input("data.txt");
vector<float> data;
while (input)
{
    string str;
    input >> str;
    float x = stof(str);
    data.push_back(x);
}
float n = numeric_limits<float>::min();
for (int i = 0; i < data.size(); ++i)
{
    if (data[i] > n)
    {
        n = data[i];
    }
}
cout << n << endl;
```

**Enter the program (you'll have to remember the appropriate `include` and `using` statements) and check your answer.**

### Exercise Eight

Now for a slightly more complicated example. You will probably have to write out the output to work out what is happening here. **What is the output of the following program?**

```c++
string str;
cout << "Enter your name: ";
cin >> str;
for (int i = 0; i < str.length() + 4; ++i)
{
    cout << "*";
}
cout << endl;
cout << "* " + str + " *" << endl;
for (int i = 0; i < str.length() + 4; ++i)
{
    cout << "*";
}
cout << endl;
```

**Enter the program (you'll have to remember the appropriate `include` and `using` statements) and check your answer.**

## Printing Trace Messages

One simple method we have to debug a program is to print a trace (messages on what is happening) and analyse the problem. Let us start with an example program to help you understand the idea.

```c
#include <iostream>

using std::cout;
using std::endl;

int my_function(int x, int y)
{
    cout << "my_function entered. x = " << x << " y = " << y << endl;
    int temp = x / y;
    cout << "my_function exiting. Returning " << temp << endl;
    return temp;
}

int main(int argc, char **argv) 
{
    int x = 5;
    int y = 10;
    cout << "Calling my_function with " << x  << " " << y << endl;
    int result = my_function(x, y);
    cout << "my_function returned " << result << endl;
    x = 20;
    y = 2;
    cout << "Calling my_function with " << x  << " " << y << endl;
    result = my_function(x, y);
    printf("my_function returned %d\n", result);
    x = 100;
    y = 0;
    cout << "Calling my_function with " << x  << " " << y << endl;
    result = my_function(x, y);
    cout << "my_function returned " << result << endl;
    return 0;
}
```

**Create this program -- `trace.cpp` -- then compile and run it. What is the error?**

As we are printing out trace messages, we are able to find the bug by examining the inputs and outputs of functions. We can discover quite quickly where our error is.

Program tracing comes in two forms:

- Tracing by adding code to print information.
- Tracing by hand by reading code.

**You need to start developing both skills.** Adding print statements to your code will help you find errors in your code when you aren't sure where your bug is. It allows you to check how far your program progresses before it crashes.

Tracing by hand will help you quickly work out what a bug is if you know where it is. When you are in class and ask for help, most of the time the lecturer will hand trace the algorithm first to understand what the issue might be.

