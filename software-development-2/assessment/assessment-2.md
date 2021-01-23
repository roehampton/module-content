# Software Development 2 Coursework 2

## Overview

This is coursework two of Software Development 2. This coursework is worth 20% of the module total mark.

You work for an organisation that must process large pieces of text quickly. You are to build a command line tool that can modify a text file by either:

- Converting all text to upper case.
- Converting all text to lower case.

The command line tool will take a number of arguments which will tell it how to work. For example, to convert a file `test.txt` to a file `output.txt` the command will be:

```shell
convert -u -i test.txt -o output.txt
```

The specification will go into detail about how the application should function and be implemented.

## Specification

The `convert` program is required to convert a given input to a given output based on the command line parameters passed to the program on the command line. At a minimum, the program must understand the command line arguments below:

| **Argument**  | **Description**                                        |
| ------------- | ------------------------------------------------------ |
| `-u`          | Indicates that text should be converted to upper-case. |
| `-l`          | Indicates that text should be converted to lower-case. |
| `-i filename` | Indicates the input file name.                         |
| `-o filename` | Indicates the output file name.                        |

Therefore we can convert a file to upper-case using the command:

```shell
convert -u -i input.txt -o output.txt
```

We can also convert a file to lower-case as follows:

```shell
convert -l -i input.txt -o output.txt
```

Some default functionality required by the application:

1. The application should default to converting to upper-case if nothing is specified.
2. If no input filename is provided then the application should read from `stdin`.
3. If no output filename is provided then the application should write to `stdout`.

**As the application must be high performance, your organisation has insisted that the functions to convert the case of the text must be mainly written in assembly code.**

### Examples

Some example outputs from the covert application are shown below:

| **Input text**      | **Upper-case**      | **Lower-case**      |
| ------------------- | ------------------- | ------------------- |
| `Hello World!`      | `HELLO WORLD!`      | `hello world!`      |
| `I am 20 years old` | `I AM 20 YEARS OLD` | `i am 20 years old` |
| `123456`            | `123456`            | `123456`            |
| `:-)`               | `:-)`               | `:-)`               |

### Helpful Advice

From ASCII we know that uppercase characters have values 65 to 90. Lowercase characters have values 97 to 122. Therefore:

```
a - A = 32
b - B = 32
...
z - Z = 32
```

## Restrictions and Resources

**Your application must be based purely in C using the C standard library** This means:

- **You cannot write any code in C++.**
- **You cannot use libraries that are not provided by standard C.**
- **Your code must compile using a standard C compiler, such as Microsoft's `cl`, `gcc`, and `clang`.**

## Submission

**Your code must be submitted in Moodle by the deadline provided.** The submission must be your own work. **If it is suspected that your submission is not your own work then your work will be referred for an academic misconduct investigation.**

The submission to Moodle must be a ZIP file containing the following:

- The code file(s) required to build your application.
- A collection of test files to test your application.
- A read me file indicating how to use your programme.

Your ZIP file **must** use your student ID as a name. For example, if your student ID is abc1234, your ZIP file should be called `abc1234.zip`.

## Marking Scheme

The following rubric will be used:



