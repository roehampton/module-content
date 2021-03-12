# Software Development 2 Lab 09 -- Input Validation and Handling Errors

<script src="https://cdn.jsdelivr.net/npm/code-line"></script>
<script>CodeLine.initOnPageLoad({toggleBtn: {show: false}, copyBtn: {show: false}})</script>

<link rel="stylesheet" href="/module-content/css/block.css">

In this lab we will explore how we ensure that the input into our programmes is correct. This is a very important concept. Invalid input is one of the main reasons your programme can fail

- Read in number but isn't a number

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



- Basic input check -- loop until the input is correct.



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



- Check if input is in a range.



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



- Cin fail

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



- !cin



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

- While !cin >> data

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



- Eof and get line



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



- Catching errors -- stoi



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



- Throwing your own errors
- Declaring functions have errors
- Advanced -- regular expressions