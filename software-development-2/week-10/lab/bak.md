# Software Development 2 Lab 09 -- Input Validation and Handling Errors

<script src="https://cdn.jsdelivr.net/npm/code-line"></script>
<script>CodeLine.initOnPageLoad({toggleBtn: {show: false}, copyBtn: {show: false}})</script>

<link rel="stylesheet" href="/module-content/css/block.css">

In this lab we will explore how we ensure that the input into our programs is correct. This is a very important concept. Invalid input is one of the main reasons your program can fail, and one of the main security risks for you programs.

## Testing if a Value Input is a Number

At the moment, when you read in input from the user, we don't do any validation to ensure that the user input the expected data type. This is quite bad. It can lead to your program failing in a manner where you don't have any control to rectify. For example, **enter and run the following program.**

```cpp
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

int main(int argc, char **argv)
{
  // int we will read into
  int x;
  cout << "Enter a number: ";
  cin >> x;
  cout << "You entered " << x << endl;

  return 0;
}
```

When you enter a number, this program will work as expected. However, what happens when we enter just the letter `a` as input:

```shell
Enter a number: a
You entered 0
```

So, C++ interpreted this as 0. It takes more than incorrect input to fail a C++ program, but it doesn't help us ensure that our programs are correct. So how can we do better?

## Basic Input Checking -- Loop Until Correct

One thing we can do is loop until we get the correct input. For example, **enter and run the below program that asks for a password.**

```cpp
#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;

int main(int argc, char **argv)
{
  // String to read into
  string buffer;
  // Ask for password
  cout << "Enter password: ";
  cin >> buffer;
  // Loop until buffer is correct
  while (buffer != "password")
  {
    cerr << "Password incorrect" << endl;
    cout << "Enter password: ";
    cin >> buffer;
  }
  // Print congratulations message
  cout << "Password correct" << endl;
  return 0;
}
```

This is a very simple program, although we using the following new concept:

- `cerr` -- this is the error output. It just goes to the command line, although you can for example set a different colour for your error output than normal output.

We can expand this idea to except correct number input. Let us say we want to input a number between 1 and 5, for example in a menu application. This is a fairly easy concept to work to as shown below.

```cpp
#include <iostream>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;

int main(int argc, char **argv)
{
  int number;
  // Get number input
  cout << "Enter a number (1 to 5): ";
  cin >> number;
  // Loop until number is in range
  while (number < 1 || number > 5)
  {
    cerr << "Error" << endl;
    cout << "Enter a number (1 to 5): ";
    cin >> number;
  }
  cout << "You entered " << number << endl;

  return 0;
}
```

As you can see, this application will:

- Read in a number.
- Loop while the number is not between 1 and 5.
  - This will also catch any erroneous input, which will mean the number is 0.

This is all well and good, but what if we want to allow 0 as an input? How do we ensure that our input is correct? This is where we can use `cin` to tell us the outcome.

## `cin` Fail

`cin` is an object in C++ that provides a lot of additional functionality, such as padding, setting number precision, etc. One of the things it can do is tell you if input has failed. Input fails when `cin` does not successfully read due to, for example, the type of data trying to be read. **Enter and run the below application.**

```cpp
#include <iostream>
#include <limits>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::numeric_limits;
using std::streamsize;

int main(int argc, char **argv)
{
  int number;
  // Ask for number
  cout << "Enter a number: ";
  cin >> number;
  // Loop while cin fails to read a number
  while (cin.fail())
  {
    // Need to clear the cin buffer
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cerr << "Error" << endl;
    cout << "Enter a number: ";
    cin >> number;
  }

  cout << "You entered " << number << endl;

  return 0;
}
```

We've added a few additional ideas here:

- `cin.fail()` -- this tests if the last read was successful or not. It returns a boolean value -- `true` or `false`. If our input fails, we loop.
- `cin.clear()` -- this clears any error flags on `cin`. This is necessary to ensure that the next read will possibly be successful.
- `cin.ignore(numeric_limits<streamsize>::max(), '\n');` -- this tells `cin` to ignore everything else on the stream up to the next newline `\n`. The `numeric_limits<streamsize>::max()` returns the maximum size of the stream buffer, so we are saying *clear all the stream buffer (maximum size) up to the next newline character.*

So we have finally created a working version of our first application. We don't even need to use `cin.fail()` as C++ supports operator overloading, allowing us to replace `cin.fail()` just with `!cin` as indicated below:

```cpp
#include <iostream>
#include <limits>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::numeric_limits;
using std::streamsize;

int main(int argc, char **argv)
{
  int number;
  // Ask for number
  cout << "Enter a number: ";
  cin >> number;
  // Loop while cin fails to read a number
  while (!cin)
  {
    // Need to clear the cin buffer
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cerr << "Error" << endl;
    cout << "Enter a number: ";
    cin >> number;
  }

  cout << "You entered " << number << endl;

  return 0;
}
```

This is just the same program as last time, but the check in the `while` loop has been changed. We can also go one step further, and test this during the inputting of data explicitly. See the program below.

```cpp
#include <iostream>
#include <limits>

using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::numeric_limits;
using std::streamsize;

int main(int argc, char **argv)
{
  int number;
  // Ask for number
  cout << "Enter a number: ";
  // Loop while cin fails to read a number
  while (!(cin >> number))
  {
    // Need to clear the cin buffer
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cerr << "Error" << endl;
    cout << "Enter a number: ";
  }

  cout << "You entered " << number << endl;

  return 0;
}
```

We've moved `cin >> number` into the `while` condition, and if it returns `false` (`!(cin >> number)`) we fail and try and read again. **This is the safest way to read in data using `cin` that you should be following.**

## Reading Files and Testing for End of File

Failing input also works for file input and output. Indeed, you can use any of the examples above for `cin` and replace them with a  `ifstream` object created by opening a file. Files also allow a further test -- `eof` (short for End of File). The following programme illustrates the basic concept.

```cpp
#include <iostream>
#include <fstream>
#include <string>

using std::string;
using std::cout;
using std::endl;
using std::ifstream;
using std::getline;

int main(int argc, char **argv)
{
  string buffer;
  // Open file for reading
  ifstream file("test.txt");
  // Loop until end of file
  while (!file.eof())
  {
    // Get next line of text from file
    getline(file, buffer);
    // Print the read line
    cout << buffer << endl;
  }
  return 0;
}
```

**Enter and run this program now.** You will need to create a file called `test.txt` to use it. However, as you can see, this program doesn't need to allocate memory to read into. We just use a `string` and work accordingly. **This is one of the main differences between C (not object orientated) and C++ (object orientated).** C++ has a more modern standard library, allowing us to write code in a simpler manner.

## Exception Handling in C++

C++ does support error handling using `try ... catch`, although it is sometimes frowned upon. Error handling in this manner is expensive, and is not used in any area where performance is important (for example, in games development). Indeed, there is very little in the C++ standard library that will throw an exception. This is in stark contrast to languages such as Python, Java, and C# where you will find exceptions thrown in many places. In Java especially, the compiler will raise an error if you are not properly managing your exceptions. C++ simply doesn't do that. The compiler will generate an executable and it will run, with undefined behaviour potentially occurring.

As a first example, **enter and run the following application.**

```cpp
#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::stoi;

int main(int argc, char **argv)
{
  // Ask the user for input
  string input;
  cout << "Enter a number: ";
  cin >> input;
  // Try and convert the input string to a number
  int n = stoi(input);
  // Output number
  cout << "You entered " << n << endl;
  return 0;
}
```

If you enter something that is not a number (e.g., `banana`) as input, the call to `stoi` will throw an exception. `stoi` is a function that tries to convert a `string` to an `int`. If the `string` does not represent a number, the application will fail. For example, on my MacBook, the following output will occur:

```shell
Enter a number: banana
libc++abi.dylib: terminating with uncaught exception of type std::invalid_argument: stoi: no conversion
[1]    86364 abort      ./a.out
```

The exception thrown is `std::invalid_argument`, and it provides a message -- `stoi: no conversion`. So, in other words, we know `stoi` was unable to convert our `string` as we gave it an invalid argument. `banana` is not a number essentially.

Let us fix this code so that it correctly inputs our data. The below is essentially a different approach to our first application, but using `try` and `catch` rather than testing `cin`. **This method is generally discouraged in C++, but is the way most other programming languages approach the problem:**

- Read input from the keyboard.
- Try and convert the input to a number (or whatever you are trying to do).
- If exception raised, print error and loop, asking for input again.

```cpp
#include <iostream>
#include <string>
#include <stdexcept>

using std::string;
using std::cin;
using std::cout;
using std::cerr;
using std::endl;
using std::stoi;
using std::invalid_argument;

int main(int argc, char **argv)
{
  // Ask the user for input
  string input;
  // Loop until break
  while (true)
  {
    try
    {
      cout << "Enter a number: ";
      cin >> input;
      // Try and convert the input string to a number
      int n = stoi(input);
      // Output number
      cout << "You entered " << n << endl;
      // If we get here, break out of loop
      break;
    }
    catch(const invalid_argument& e)
    {
      cerr << e.what() << endl;
    }
  }
  return 0;
}
```

### Throwing Your Own Errors

As you become a better programmer, and start writing your own libraries, you will have to write code that also raises exceptions. This is normally quite easy, and uses a keyword in most languages. For example, in C++ (and Java, C#, etc.) the keyword is `throw`. **Enter and run the code below.**

```cpp
#include <iostream>
#include <stdexcept>

using std::cout;
using std::endl;
using std::invalid_argument;

int divide(int numerator, int denominator)
{
  if (denominator == 0)
  {
    throw invalid_argument("Divide by zero");
  }
  return numerator / denominator;
}

int main(int argc, char **argv)
{
  cout << divide(5, 0) << endl;
  return 0;
}
```

The output from this program on my MacBook is as follows:

```shell
libc++abi.dylib: terminating with uncaught exception of type std::invalid_argument: Divide by zero
[1]    86615 abort      ./a.out
```

As you can see, we get the correct exception `std::invalid_argument` and the correct message `Divide by zero`. So we have the correct output occurring.

## Advanced -- Regular Expressions

So far our input validation is based on checking is a value is an expected type. This is fine for many situations, but not really enough when we are dealing with complex data entry.

For example, let us say we want to test that user input starts with a `K`. We can do this simply as follows:

```cpp
#include <iostream>
#include <string>

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main(int argc, char **argv)
{
  // Ask for user input
  cout << "Enter your name: ";
  // Input a string
  string name;
  cin >> name;

  // Check if string starts with a K
  if (name[0] == 'K')
  {
    cout << "Your name starts with K" << endl;
  }
  else
  {
    cout << "Your name doesn't start with K" << endl;
  }
  return 0;
}
```

This is all well and good, but as you can imagine, this becomes problematic if you want to test for more complex data types. For example, how do we check if an input is a postcode, which can be:

- SW15 5PU
- E1 4FG
- G12 9RF

How do we do that? This is where we look at regular expressions.

### What is a Regular Expression?

A regular expression is a description of a pattern that we can test if a string matches. It uses basic parameters to describe a pattern. The most basic pattern match is `.*`. The `.` means we any character, and `*` means accept any number. This is effectively a regular expression that does nothing.

If we want to accept a string starting with `K`, we can expand our regular expression to do so. `^K.*` means accept a string with `K` at the start and then any number of characters. `K.*` would mean accepting any string which had a `K` then any character, `K` then any character, etc. So `KaKeKcKf` would be acceptable for `K.*` but `Kevin` would not be.

C++ supports regular expressions using the `regex` library. Below is a sample application. **Enter the code and run it.**

```cpp
#include <iostream>
#include <string>
#include <regex>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::regex;
using std::regex_match;

int main(int argc, char **argv)
{
  // Define regular expression
  regex reg("^K.*");
  // Ask user for input
  cout << "Enter your name: ";
  // Get input from user
  string input;
  cin >> input;
  // Test if string matches regular expression
  if (regex_match(input, reg))
  {
    cout << "Input matches regular expression" << endl;
  }
  else
  {
    cout << "Input doesn't match regular expression" << endl;
  }

  return 0;
}
```

We are using two new objects here:

- `regex` -- this is an object representing a regular expression.
- `regex_match` -- undertakes a match of a `string` against a `regex`. It returns `true` or `false` based on the success of matching.

For example, running this application:

```shell
Enter your name: Kevin
Input matches regular expression
...             
Enter your name: Alex
Input doesn't match regular expression
```

### More Regular Expressions

What if we want to check to see if a name is entered correctly. We will be very bad programmers and assume that all names start with a capital letter, and then have a series of lowercase letters. To do this we will use two additional regular expression features:

- `[A-Z]` -- this means accept a character from the set defined in the range `A` to `Z`.
- `[a-z]` -- this means accept a character from the set defined in the range `a` to `z`.
- `([a-z]*)` -- this parentheses `(...)` defines a group. This allows us to treat different parts of the 

Let us define our regular expression. **Enter and run the following program.**

```cpp
#include <iostream>
#include <string>
#include <regex>

using std::string;
using std::cin;
using std::cout;
using std::endl;
using std::regex;
using std::regex_match;

int main(int argc, char **argv)
{
  // Create a regex that accepts uppercase characters, a space, then numbers
  regex reg("^[A-Z]([a-z]*)");
  // Ask user for an input
  string input;
  cout << "Enter a string: ";
  cin >> input;
  // Test regular expression
  if (regex_match(input, reg))
  {
    cout << "String matches regular expression" << endl;
  }
  else
  {
    cout << "String does not match regular expression" << endl;
  }

  return 0;
}
```

We accept a single uppercase letter at the start of the regular expression, then accept any number of lowercase letters. When you run this application you will see that it accepts `Kevin` but not `KeVin`.

## So You Want to Know More

You can look up the following cheatsheet that explains how regular expressions in C++ can be defined. [c++11-regex-cheatsheet.pdf (cpprocks.com)](https://cpprocks.com/files/c++11-regex-cheatsheet.pdf){:target="_blank"}

Slightly more advanced tutorial on the power of regular expressions -- [Introduction to Regular Expressions With Modern C++ - DZone IoT](https://dzone.com/articles/introduction-to-regular-expression-with-modern-c){:target="_blank"}.