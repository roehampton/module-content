## Exception Handling in C++

C++ does support error handling using `try ... catch`, although it is sometimes frowned upon. Error handling in this manner is expensive and is not used in any area where performance is important (for example, in games development). Indeed, there is very little in the C++ standard library that will throw an exception. This is in stark contrast to languages such as Python, Java, and C# where you will find exceptions thrown in many places. In Java especially, the compiler will raise an error if you are not properly managing your exceptions. C++ simply doesn't do that. The compiler will generate an executable and it will run, with undefined behaviour potentially occurring.

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
- If an exception is raised, print error and loop, asking for input again.

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

As you become a better programmer and start writing your own libraries, you will have to write code that also raises exceptions. This is normally quite easy and uses a keyword in most languages. For example, in C++ (and Java, C#, etc.) the keyword is `throw`. **Enter and run the code below.**

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