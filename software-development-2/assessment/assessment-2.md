# Software Development 2 Coursework 2

## Overview

This is coursework two of Software Development 2. This coursework is worth 20% of the module total mark.

**Please note the requirement to write some assembly code in this assessment. This is not negotiable.**

You work for an organisation that must process large pieces of text quickly. You are to build a command line tool that can modify a text file by either:

- Converting all text to upper case.
- Converting all text to lower case.
- Counting the number of words by counting the number of spaces in a file plus one.

The command line tool will take a number of arguments which will tell it how to work. For example, to convert a file `test.txt` to a file `output.txt` the command will be:

```shell
convert -u -i test.txt -o output.txt
```

The specification will go into detail about how the application should function and be implemented.

## Specification

The `convert` program is required to convert a given input to a given output based on the command line parameters passed to the program on the command line. At a minimum, the program must understand the command line arguments below:

| **Argument**  | **Description**                                              |
| ------------- | ------------------------------------------------------------ |
| `-u`          | Indicates that text should be converted to upper-case.       |
| `-l`          | Indicates that text should be converted to lower-case.       |
| `-c`          | Count the number of words in the file by counting the number of spaces plus one. |
| `-i filename` | Indicates the input file name.                               |
| `-o filename` | Indicates the output file name.                              |

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
2. The application can count the number of spaces as well as converting the text.
3. If no input filename is provided then the application should read from `stdin`.
4. If no output filename is provided then the application should write to `stdout`.

**As the application must be high performance, your organisation has insisted that the functions to convert the case of the text and counting spaces must be mainly written in assembly code.**

### Examples

Some example outputs from the covert application are shown below:

| **Input text**      | **Upper-case**      | **Lower-case**      | **Count** |
| ------------------- | ------------------- | ------------------- | --------- |
| `Hello World!`      | `HELLO WORLD!`      | `hello world!`      | 2         |
| `I am 20 years old` | `I AM 20 YEARS OLD` | `i am 20 years old` | 5         |
| `123456`            | `123456`            | `123456`            | 1         |
| `:-)`               | `:-)`               | `:-)`               | 1         |
| `A B C D E F G H I` | `A B C D E F G H I` | `a b c d e f g h i` | 9         |

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

| **Criteria**                                                 | **Excellent**                                                | **Good**                                                     | **Developing**                                               | **Not Attempted**                                            |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| **Solution** the completeness of the code fo meet the specification given. | A completed solution meeting all the specifications.         | A completed solution that does not quite meet all the specifications. | A completed solution is implemented and runs but lacks much of the specification. | Solution doesn’t run or does not meet the specifications defined. |
| **Correctness** ability to create code that reliably produces correct answers or appropriate results. | Program produces correct answers or appropriate results for all inputs tested. | Program produces correct answers or appropriate results for most inputs. | Program approaches correct answers or appropriate results for most inputs but can contain miscalculations. | Program does not produce correct answers or appropriate results for most inputs. |
| **Logic** ability to use correct program structures appropriate to the problem domain. | Program logic is correct with no known boundary errors, and no redundant or contradictory conditions. | Program logic is mostly correct but may contain an occasional boundary error or redundant or contradictory condition. | Program logic is on the right track but shows no recognition of boundary conditions (such as < vs. <=). | Program contains some conditions that specify the opposite of what is required (less than vs. greater than), confuse Boolean AND/OR operators, or lead to infinite loops. |
| **Robustness** ability of the program to handle unexpected input and error conditions correctly as evidenced via testing. | Program handles erroneous or unexpected input gracefully; action is taken without surprising the user. Boundary cases are considered and tested. | All obvious error conditions are checked for and appropriate action is taken. Nearly all boundary cases are considered and tested. | Some obvious error conditions are checked for and some sort of action is taken. Most boundary cases are considered and tested. | Program often fails or fails completely. Boundary conditions are not tested for. |
| **Error freedom** removal of all errors existing within the current program. | All errors removed such that the program will compile and run under all conditions. | All obvious errors are removed but there are some smaller issues not rectified. Program will compile and run. | Some obvious errors fixed but some still exist. Program will compile and run. | Program either fails to compile, or if it does not further errors have been fixed. |
| **Clarity** ability to format and document code for human consumption (Good Style) | Program contains appropriate documentation for all major functions, variables, or non-trivial algorithms. Formatting, indentation, and other white space aids readability. | Program contains some documentation on major functions, variables, or nontrivial algorithms. Indentation and other formatting is appropriate. | Program contains some documentation (at least the student’s name and program’s purpose) but has occasionally misleading indentation. | Program contains no documentation, or grossly misleading indentation. |

### Academic Misconduct

All submissions will be processed through a code plagiarism tool. If signs of misconduct are found, all students involved will be contacted to discuss further steps. Please see here for information on academic integrity at the university <https://portal.roehampton.ac.uk/information/Pages/Academic-Integrity.aspx>.

Our guiding principle is that academic integrity and honesty are fundamental to the academic work you produce at the University of Roehampton. You are expected to complete coursework which is your own and which is referenced appropriately. The university has in place measures to detect academic dishonesty in all its forms. If you are found to be cheating or attempting to gain an unfair advantage over other students in any way, this is considered academic misconduct and you will be penalised accordingly. Please don’t do it.