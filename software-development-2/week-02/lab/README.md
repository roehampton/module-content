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

## Casting Between Types -- Numbers

A good question to ask now is how 

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



## Generic Typing



### Lists

```python
data = []
for i in range(10):
    str = input("Enter data: ")
    data.append(str)
data.sort()
for str in data:
    print(str)
```



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
    vector<string> data;
    for (int i = 0; i < 10; ++i)
    {
        string str;
        cout << "Enter data: ";
        cin >> str;
        data.push_back(str);
    }
    cout << "Sorting..." << endl;
    sort(data.begin(), data.end());
    for (string str : data)
    {
        cout << str << endl;
    }
    return 0;
}
```



### Dictionaries

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
    unordered_map<string, string> lecturers;
    lecturers["Software Development 2"] = "Kevin";
    lecturers["Software Development 1"] = "Arturo";
    lecturers["Databases"] = "Wei";
    lecturers["Computer Systems"] = "Oge";
    for (auto entry : lecturers)
    {
        cout << entry.first << " " << entry.second << endl;
    }
    return 0;
}
```



### Creating a Generic Typed Function

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
    auto num = my_add(5, 4);
    cout << "num = " << num << endl;
    auto str = my_add(string("Hello, "), string("world!"));
    cout << "str = " << str << endl;
    auto num2 = my_add(5.0f, 10.0f);
    cout << "num2 = " << num2 << endl;
    auto logic = my_add(true, false);
    cout << "logic = " << logic << endl;
    return 0;
}
```



## Longer Example -- Generate Random Numbers



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