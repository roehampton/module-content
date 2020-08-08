# Computer Systems Lab 1 - Introduction to C Programming

## Aim

The aim of this lab is to introduce you to the C programming language and output some data in different formats. Along the way, we will examine the basics of working with a Unix command line. This is to allow you to create simple C programs and run them.

## Basics of the Unix Command Line

Unix is a family of operating systems that has heavily influenced modern computing. In particular, the directory structure and commands of many modern operating systems derive from Unix:

- Linux is very similar to Unix. We will be using Linux for this lab. Android is a Linux-based operating system, although the Linux part is hidden.
- Mac OS X is another Unix derivative, although this is more hidden from the end user. iOS is similarly derived from Unix but hidden.
- Windows is not Unix based, although has some influences. Windows has slowly been moving towards a stronger Unix influence over the past few years.

We will use the command line in this lab to create folders and files using commands that will work in Linux and Mac OS X, and partially in Windows. You can also install a Linux command line in Windows via [Windows Subsystem for Linux](https://docs.microsoft.com/en-us/windows/wsl/install-win10).

The command line is case sensitive. You need to enter commands using the right capitalisation of letters.

> The **computer is dumb.** It does not know when you type `LS` you actually meant `ls`. To the computer, these are different. One of the first skills you have to learn when studying computing is **precision**. The computer has no ability to guess what you mean. It works on exactly interpreting what you enter. This also means you need **patience**. Developing the skills and problem solving ability in computing means taking your time. This takes **practice**.

### Command Prompt

On the Linux lab machine, once you have logged in, you will be presented with something similar to the following:

```bash
student@ML-RefVm-999999:~$
```

The command prompt has the following parts:

- `student` is the **user name**.
- `ML-RefVM-999999` is the **computer name**. So `student@ML-RefVm-999999` means the user `student` on computer `ML-RefVm-999999`. Your computer name is probably different.
- `~` is the current directory. We will examine what this means next.
- `$` is the start of the command prompt we can start typing at.

We don’t need to concern ourselves too much with the command prompt.

### Print Working Directory

The **working directory** is the current directory the command prompt is running in. We can print the current working directory string by using `pwd`.

```bash
student@ML-RefVm-999999:~$ pwd
/home/student
```

When you first login you are in the user’s (`student`) home directory - `/home/student`. As this folder is regularly used, we have a shortcut rather than typing `/home/student` each time - `~`.

> `~` is a shortcut for the current user’s home directory - `/home/<username>`.

#### Directory Structure

You are probably familiar with how a folder structure works on a computer. When working on the command line, we can move to a different folder (directory). We just need to understand how a directory string is constructed.

Each `/` breaks the different directory and file names up, much like a URL on a website. So `/home/student` is a directory `student` within the `home` directory. When we type a whole directory string such as `/home/student`, we are giving the **absolute path**.

> Full directory strings, such as `/home/student` are **absolute paths**.

All absolute paths are relevant to the root directory `/`,

A **relative path** is based on the current location of the command prompt or file. For example, when you are in the `/home` directory, you can refer directly to `student`.

> A directory string referring to subdirectories and files from the current location are **relative paths**.

### Listing Directory Contents

You can list the current contents of a directory using the `ls` (short for *list*) command.

```bash
student@ML-RefVm-999999:~$ ls
student@ML-RefVm-999999:~$ 
```

Nothing will be printed right now as there are no files in our home directory. Let us create some.

### Creating a File

We can create a file from the command prompt using `touch`. Let us create a file called `file1`.

```bash
student@ML-RefVm-999999:~$ touch file1
```

Now let us list the directory contents again:

```bash
student@ML-RefVm-999999:~$ ls
file1
```

We can use `ls` to print more details. The `-l` flag prints the **long format** details.

```bash
student@ML-RefVm-999999:~$ ls -l
total 0
-rw-rw-r-- 1 student student 0 Jul 25 10:44 file1
```

`file1` has a further collection of details associated with it.

- `-rw-rw-r---` is the file permissions which we don’t examine in this module.
- The first `student` is the user who owns the file.
- The second `student` is the user belongs to. The `student` user belongs to the `student` group; i.e., their own group.
- `0` is the size of the file in bytes. The file is empty so has `0` size.
- The date and time of the last file modification is also provided.

You can also use `ls` to list hidden files:

```bash
student@ML-RefVm-999999:~$ ls -a
.  ..  .bash_history  .bash_logout  .bashrc  .cache  .gnupg  .local  .profile  .ssh  file1
```

These files have special meanings in Linux which we don’t cover here. For those who want to learn more about using the Linux operating system can use the following tutorials.

- [Guru 99](https://www.guru99.com/unix-linux-tutorial.html)
- [Ryan’s Tutorials](https://ryanstutorials.net/linuxtutorial/)

### Deleting a File

Let us delete the file we just created. We can do this with the `rm` (short for *remove*) command:

```bash
student@ML-RefVm-999999:~$ rm file1
student@ML-RefVm-999999:~$ ls
student@ML-RefVm-999999:~$
```

### Creating a Directory

We can create a new directory using the `mkdir` (short for *make directory*) command. Let us create a new directory called `directory`.

```bash
student@ML-RefVm-999999:~$ mkdir directory
student@ML-RefVm-999999:~$ ls
directory
```

### Changing Directory

Now that we have a directory let us move into it using the `cd` (short for *change directory*) command:

```bash
student@ML-RefVm-999999:~$ cd directory
student@ML-RefVm-999999:~/directory$
```

Notice how the command prompt has changed to reflect the directory we are in - `~/directory`.

### Editing a File

We have used `touch` to create a file, but how do we edit a file? There are actually several options. We will use a tool called `nano` which is probably the easiest to work with.

`nano` can also create files. Let us use `nano` now to create and open a file, `file2` for editing:

```bash
student@ML-RefVm-999999:~$ nano file2
```

This will change the command prompt window to the `nano` editor screen.

![Nano Window](nano.png)

You can type straight into the window as if it was a simple text editor. Write the following into the window:

```
Hello world!
```

To save the file, we need to `Write Out`. At the bottom of the window, you will see this is signified by `^O`. This just means holding down the `Ctrl` key (`Command` on a Mac) and pressing `O`. `nano` will ask you the name of the file:

```
File Name to Write: file2
```

Just press return to use the name we already used. The file will be saved with the current contents.

To exit `nano` we use `^X`. Remember, this means holding down `Ctrl` (or command) and pressing `X`.

Back on the command line, we can now list the file details to see that the file exists.

```bash
student@ML-RefVm-999999:~/directory$ ls -l
-rw-rw-r-- 1 student student 14 Jul 25 14:45 file2
```

### Deleting a Directory

We can delete a directory using the `rmdir` (short for *remove directory*) command. Let us remove the directory we just created. First we have to move out of the directory. We can move up the directory structure to the parent directory using `cd`:

```bash
student@ML-RefVm-999999:~/directory$ cd ..
student@ML-RefVm-999999:~$ 
```

Let us now remove `directory`:

```bash
student@ML-RefVm-999999:~$ rmdir directory
rmdir: failed to remove 'directory': Directory not empty
```

OK, that didn’t work. We cannot simply remove a directory that it not empty. As `directory` contains `file2` we cannot delete it.

We have two options here:

1. Change into `directory` and delete `file2`. This is OK here, but would take a lot of time if we had multiple files and subdirectories.
2. Delete `directory` and all its contents in one command.

For option 2, we can use `rm` (*remove*) with the `-r` option, which means recursively delete the contents:

```bash
student@ML-RefVm-999999:~$ rm -r directory
student@ML-RefVm-999999:~$ ls
student@ML-RefVm-999999:~$ 
```

### Reference Unix Commands

We have used all the commands necessary for this lab. You should try and practice using the command line as much as possible on your computer rather than using the window system. The more you practice the better you will be.

- `pwd` - prints current directory.
- `ls` - lists directory contents.
- `touch` - creates a file.
- `rm` - removes a file.
- `mkdir` - creates a directory.
- `cd` - changes directory.
- `cd ..` - move up the directory structure.
- `cd ~` - change to the user’s home directory.
- `nano` - opens file editor.
- `rmdir` - removes (deletes) a directory.
- `rm -r` - recursively deletes a directory and its contents.

### Exercise

We need a directory structure for our work. Create the following:

1. A `computer-systems` directory in your user `home` directory (i.e., `/home/student`).
2. A `lab01` directory in the `computer-systems` directory.

## Your First C Program - *Hello World*

### Creating a C Program File

We will now start our work with C. First we need to create a file in the `lab01` directory called `hello.c`. Use `nano` to create and open the file.

C is a **compiled language**. This means that a program on the computer, **a compiler**, is used to convert the file of C code into executable program code that the computer understands.

### *Hello World* Code

Let us look at our *Hello World* code.

> **DO NOT COPY AND PASTE.** You may think this makes you work faster but in the long term it will slow you down as you will have not gained as much understanding. Or maybe you just want to shortcut typing in code. **You need to practice typing in code.** Remember, **patience** and **precision** are key to developing your skills in computing. Take your time and type in the code. When you fix your mistakes you will learn more. As you take your time, you will understand the code more. These help you in the long run and save far more time in the future.

```c
#include <stdio.h>

int main(int argc, char **argv)
{
    printf("Hello, world!\n");
    return 0;
}
```

Let us look at each line of code one at a time and explain what is happening:

- `#include <stdio.h>` asks the C compiler to include the **STanDard Input-Output** library into our code. This allows us to interact with the command line, such as printing to the screen and reading input from the keyboard.
- `int main(int argc, char **argv)` declares the main part of our program, called the **entry point**. This is where the program will start running from.
  - `int main` means the program returns an integer (number) and the bit of code is called is `main`.
  - `int argc` represents the number of parameters/arguments (*ARGument Count*) given to the program. For example, when we used `rm -r` we passed the `-r` argument to the program. We won’t use this until much later in the module.
  - `char **argv` represents the actual arguments as *character* (text) data.
- `printf("Hello, world!\n");` prints `Hello, world!` to the screen. The `\n` part means print a new line.
- `return 0` is the return value from the program. Programs can return error codes which can be useful when a system fails.

### Compiling *Hello World*

Now we have a program, we need to compile it. **Save the file and exit nano**.

We will use GCC to compile our program. GCC used to stand for [GNU](https://en.wikipedia.org/wiki/GNU_Project) C Compiler, but today means GNU Compiler Collective as GCC can compile more languages than just C. We use `gcc` to compile our program:

```bash
student@ML-RefVm-999999:~/computer-systems/lab01$ gcc hello.c
student@ML-RefVm-999999:~/computer-systems/lab01$ ls
a.out  hello.c
```

Notice that `gcc` has created a new file called `a.out`. This the created executable.

> **My program didn’t compile. Help!**
>
> The first thing to do is check that you’ve typed in everything correctly. Almost all starting errors come from incorrectly entering the code. **Be precise. Be patient. And practice.** Don’t look quickly and assume you have it right. Try to find the problem.
>
> If you are still stuck, ask for help.

### Running Hello World

To run the program we ask the command line to execute it.

```bash
student@ML-RefVm-999999:~/computer-systems/lab01$ ./a.out
Hello, world!
```

`./` just means *execute this file in the current directory*.

### Exercise

Create another program called `hello-me.c`. This program should print out `Hello` followed by your name.

## Your Second C Program

Let us now create a program that asks the user to input their name and prints it. Create the file `name.c` with the following code:

```c
#include <stdio.h>

int main(int argc, char **argv)
{
    char name[30];
    printf("Enter your name: ");
    scanf("%29s", name);
    printf("Hello, %s!\n", name);
    return 0;
}
```

We have some new code to explore here:

- `char name[30];` declares a variable or area or memory to store `char` (text) data. We have allocated 30 characters of space.
- `scanf("%29s", name);` means we will read from the keyboard. We will read up to 29 characters of data into the `name` area of memory. We can only read 29 as the string of character data must place an *end-of-string* identifier in memory as well.
- `printf("Hello, %s!\n", name);` prints the `Hello <name>!` to the screen. `%s` is a placeholder for a string to be printed here. After the comma, we provide the string (`name`) we want to put there.

> This isn’t a programming module, and you will learn more about programming and what we are doing in a programming module. We won’t really be dealing with user input much in this module.

We can now compile and run our program:

```bash
student@ML-RefVm-999999:~/computer-systems/lab01$ gcc name.c
student@ML-RefVm-999999:~/computer-systems/lab01$ ./a.out
Enter your name: Kevin
Hello, Kevin!
```

## Outputting Data in C

Now let us get to where we where heading in this lab - displaying raw data. C is a language very close to the machine, and so we can get a good understanding of how data is represented via C.

### Bytes

Recall that a byte is just eight bits of data. This means a byte has a maximum value of 255:

| 2^7^ | 2^6^ | 2^5^ | 2^4^ | 2^3^ | 2^2^ | 2^1^ | 2^0^ |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| 128  | 64   | 32   | 16   | 8    | 4    | 2    | 1    |

128 + 64 + 32 + 16 + 8 + 4 + 2 + 1 = 255. We can define an 8-bit value in C using the `int8_t` type. The following program, `bytes.c`, demonstrates.

```c
#include <stdio.h>
#include <stdint.h>

int main(int argc, char **argv)
{
    int8_t x = 0;
    int8_t y = 100;
    int8_t z = 200;
    printf("x = %i\n", x);
    printf("y = %i\n", y);
    printf("z = %i\n", z);
    return 0;
}
```

> `#include <stdint.h>` includes the standard integer library which defines `int8_t`. `char` is provided in C as an 8-bit value. As we will use other datatypes later in this lab which have different sizes we’ve used `int8_t` for consistency.

We are going to print out `0`, `100`, and `200`. The `%i` place holder means print an integer (number). Let us compile and run the program and see what happens:

```bash
student@ML-RefVm-999999:~/computer-systems/lab01$ gcc bytes.c
student@ML-RefVm-999999:~/computer-systems/lab01$ ./a.out
x = 0
y = 100
z = -56
```

OK, what happened with `z`? Remember our discussion on **two’s compliment** in the lecture and how the first bit in a binary number is used to represent if the number is positive or negative. We can actually work out that this has happened. 200 in binary is `1100 1000`:

| 2^7^ | 2^6^ | 2^5^ | 2^4^ | 2^3^ | 2^2^ | 2^1^ | 2^0^ |
| ---- | ---- | ---- | ---- | ---- | ---- | ---- | ---- |
| 128  | 64   | 32   | 16   | 8    | 4    | 2    | 1    |
| 1    | 1    | 0    | 0    | 1    | 0    | 0    | 0    |

128 + 64 + 8 = 200.

56 in binary is `0011 1000`. Remember the system of two’s compliment:

1. Flip 0’s to 1’s and 1’s to 0’s.
2. Add 1.

So, for 56:

1. `0011 1000` becomes `1100 0111`.
2. Adding 1 to `1100 0111` gives us `1100 1000`.

> Remember once again, **the computer is dumb**. It did exactly what you told it to do - store 200 in an 8-bit value. It’s not its fault what happens. It just did exactly what it was asked.

#### Signed and Unsigned

If you want to store numbers greater than 127 in an 8-bit value you have to use an **unsigned** integer. This is a `uint8_t` data type - the `u` at the start representing *unsigned*.

**Exercise** - modify `bytes.c` to use `uint8_t`, compile and output the result to test this works.

#### Octal Output

We can ask our C program to output data in octal format. Create a file called `octal.c` with the following code:

```c
#include <stdio.h>
#include <stdint.h>

int main(int argc, char **argv)
{
    uint8_t x = 0;
    uint8_t y = 100;
    uint8_t z = 200;
    printf("%i in octal is %o\n", x, x);
    printf("%i in octal is %o\n", y, y);
    printf("%i in octal is %o\n", z, z);
    return 0;
}
```

The `%o` placeholder in `printf` tells the program to print out the octal version of the data. We’re not changing the data, we’re just telling the computer to print it in a different format, which is an easy thing for the computer to do. Compiling and running this program gives:

```bash
student@ML-RefVm-999999:~/computer-systems/lab01$ gcc octal.c
student@ML-RefVm-999999:~/computer-systems/lab01$ ./a.out
0 in octal is 0
100 in octal is 144
200 in octal is 310
```

#### Hexadecimal Output

We can also output data from C in a hexadecimal format. The following program, `hex.c` illustrates:

```c
#include <stdio.h>
#include <stdint.h>

int main(int argc, char **argv)
{
    uint8_t x = 0;
    uint8_t y = 100;
    uint8_t z = 200;
    printf("%i in hex is %x\n", x, x);
    printf("%i in hex is %x\n", y, y);
    printf("%i in hex is %x\n", z, z);
    return 0;
}
```

`%x` is the placeholder for printing data as a hexadecimal value. Compiling and running the program gives us:

```bash
student@ML-RefVm-999999:~/computer-systems/lab01$ gcc hex.c
student@ML-RefVm-999999:~/computer-systems/lab01$ ./a.out
0 in hex is 0
100 in hex is 64
200 in hex is c8
```

#### Binary

C unfortunately does not provide a mechanism for printing data as binary. So we will have to convert the number to binary using the method described in the lecture. Don’t worry too much about how this works at the moment. Once you’ve studied enough programming come back to the code and it will make far more sense.

> This program is very much a hack to get around the lack of binary output in C. It won’t work on negative numbers.

Our test program, `binary.c` is below:

```c
#include <stdio.h>
#include <stdint.h>

void binary(uint8_t n)
{
    if (n > 1)
        // Divide by 2 and repeat.
        binary(n / 2);
    // Print remainder.
    printf("%i", n % 2);
}

int main(int argc, char **argv)
{
    uint8_t x = 0;
    uint8_t y = 100;
    uint8_t z = 200;
    printf("%i in binary is ", x);
    binary(x);
    printf("\n");
    printf("%i in binary is ", y);
    binary(y);
    printf("\n");
    printf("%i in binary is ", z);
    binary(z);
    printf("\n");
    return 0;
}
```

Compiling and running gives us:

```bash
student@ML-RefVm-999999:~/computer-systems/lab01$ gcc binary.c
student@ML-RefVm-999999:~/computer-systems/lab01$ ./a.out
0 in binary is 0
100 in binary is 1100100
200 in binary is 11001000
```

### Integer Types

There are a number of different integer sizes we can use in C:

- `uint16_t` for unsigned 16-bit values (65,535 maximum value).
- `uint32_t` for unsigned 32-bit values (4,294,967,295 maximum value).
- `uint64_t` for unsigned 64-bit values (18,446,744,073,709,551,615 maximum value).

**Exercise** - repeat some of the programs we have covered here using different data types and larger values. You might have to replace the standard `%i` placeholder with `%lu` to manage larger data types.

## Text (Strings) and ASCII

We will finish this lab examining how text is represented in the computer. There are actually a few different methods, but the most common is [ASCII](https://en.wikipedia.org/wiki/ASCII) - the American Standard Code for Information Interchange. ASCII is quite simple. It just represents characters of text as numbers. For example, 32 represents a space.

A simple program to demonstrate this, `ascii.c`, is below:

```c
#include <stdio.h>

int main(int argc, char **argv)
{
    char x = 'K';
    char y = 'e';
    char z = 'v';
    printf("%c is %i (%x)\n", x, x, x);
    printf("%c is %i (%x)\n", y, y, y);
    printf("%c is %i (%x)\n", z, z, z);
    return 0;
}
```

```bash
student@ML-RefVm-999999:~/computer-systems/lab01$ gcc ascii.c
student@ML-RefVm-999999:~/computer-systems/lab01$ ./a.out
K is 75 (4b)
e is 101 (65)
v is 118 (76)
```

The point of this exercise is to show you that we can represent text with numbers, which we represent with binary. Everything in the computer is represented by numbers. For information, a complete ASCII table is below.

<p><a href="https://commons.wikimedia.org/wiki/File:ASCII-Table-wide.svg#/media/File:ASCII-Table-wide.svg"><img src="https://upload.wikimedia.org/wikipedia/commons/thumb/1/1b/ASCII-Table-wide.svg/1200px-ASCII-Table-wide.svg.png" alt="ASCII-Table-wide"></a><br>By <a href="//commons.wikimedia.org/wiki/File:ASCII-Table.svg" title="File:ASCII-Table.svg">ASCII-Table.svg</a>: ZZT32
derivative work: LanoxxthShaddow - <a href="//commons.wikimedia.org/wiki/File:ASCII-Table.svg" title="File:ASCII-Table.svg">ASCII-Table.svg</a>, Public Domain, <a href="https://commons.wikimedia.org/w/index.php?curid=10388973">Link</a></p>

## Exercises

1. C does allow you to define a value using binary. For example, `int x = 0b0100;` will set the value of `x` to 4. The `0b` prefix means the number is in binary. Use this technique to write a program that prints the decimal values of the following binary values:
   - `1000 0000`
   - `1000 0000 0000`
   - `1000 0000 0000 0000`
   - `1111 1111 1111 1111`
   - `1111 0000 1111 0000 1111`
2. C also allows the definition of values in hexadecimal using the `0x` prefix. For example, `int x = 0xffff;` will set the value of `x` to 65,535. Use this technique to write a program that prints the decimal values of the following hexadecimal values:
   - `f`
   - `ff`
   - `f0f`
   - `fccf`
   - `bfffffff`