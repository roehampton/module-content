# Computer Systems Coursework 1 -- Assembly Programming

Part 1 of the coursework is worth 40% of the total coursework mark. The submission deadline is **Friday 20th November online via Moodle by 23.59.**

Part 1 of the coursework focuses on assembly programming. This coursework meets the module learning outcome *Write assembly code segments.* You will submit an assembly code file to complete this coursework.

The aim of the coursework is to create a program that reads in an input from the user and displays a message according to said input. The output of the program will be:

- If the user enters `1` then the output is "Welcome to my assembly program."
- If the user enters `2` then the output is "The second choice."
- If the user enters `3` then the output is "The last choice."
- If the user enters `q` then the output is "Goodbye!" and the program will exit.
- If the user enters any other input, the output message is "ERROR! Please try again."

The program will prompt the user when it runs by outputting "Please enter a choice: ". The program will continuously loop until the user enters `q`.

The **Appendix** provides an example of how we can read input from the user in assembly.

## Submission Requirements

You must submit your assembly code file to Moodle. The file should be documented to explain your implementation. Name the code file `coursework.asm`.

**Do not submit any other files.** Your mark will be adversely affected if you submit incorrect files.

## Marking Scheme

The following rubric will be used to assess your work.

| **Criteria**                                                 | **Excellent**                                                | **Good**                                                     | **Developing**                                               | **Not attempted**                                            |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| **Syntax** ability to understand and follow the rules of the programming language. | Program compiles and contains no evidence of misunderstanding or misinterpreting the syntax of the language. | Program compiles and is free from major syntactic misunderstandings, but may contain non-standard usage or superfluous elements. | Program compiles, but contains errors that signal misunderstanding of syntax. | Program does not compile.                                    |
| **Solution** the completeness of the code to meet the specification given. | A completed solution meeting all the specifications.         | A completed solution that does not meet all the specifications. | A completed solution is implemented and runs but lacks much of the specification. | Solution doesn't run or does not meet the specifications defined. |
| **Correctness** ability to create code that reliably produces correct answers or appropriate results. | Program produces correct answers or appropriate results for all inputs tested. | Program produces correct answers or appropriate results for most inputs. | Program approaches correct answers or appropriate results for most inputs but can contain miscalculations. | Program does not produce correct answers of appropriate results for most inputs. |
| **Logic** ability to use correct program structures appropriate to the problem domain. | Program logic is correct with no known boundary errors, and no redundant or contradictory conditions. | Program logic is mostly correct but may contain an occasional boundary error or redundant or contradictory condition. | Program logic is on the right track but shows no recognition of boundary conditions (such as wrong `JMP` condition). | Program contains some conditions that specify the opposite of what is required (inverse `JMP` condition), confuse comparison operators, or lead to infinite loops. |
| **Clarity** ability to format and document code for human consumption. | Program contains appropriate documentation for all major functions, variables, or non-trivial algorithms. Formatting, indentation, and other white space aids readability. | Program contains some documentation on major functions, variables, or non-trivial algorithms. Indentation and other formatting is appropriate. | Program contains some documentation (at least the student's name and program's purpose) but has occasionally misleading indentation. | Program contains no documentation, or grossly misleading indentation. |
| **Robustness** ability of the program to handle unexpected input and error conditions correctly as evidenced via testing. | Program handles erroneous input gracefully; action is taken without surprising the user. Boundary cases are considered and tested. | All obvious error conditions are checked for and appropriate action is taken. Nearly all boundary cases are considered and tested. | Some obvious error conditions are checked for and some sort of action is taken. Most boundary cases are considered and tested. | Program often fails or fails completely. Boundary conditions are not tested for. |
| **Submission** ability to provide a submission that meets the requirements given. | Correct files submitted only and with correct names.         | Correct files submitted only but incorrect file names used.  | Correct files submitted but with unwanted files provided and possibly incorrect file names. | Incorrect files submitted.                                   |

## Academic Misconduct

All submissions will be processed through a code plagarism tool. If signs of misconduct are found, all students involved will be contacted to discuss further steps. Please see here for information on academic integrity at the university https://portal.roehampton.ac.uk/information/Pages/Academic-Integrity.aspx. Our guiding principle is:

> Academic integrity and honesty are fundamental to the academic work you produce at the University of Roehampton. You are expected to complete coursework which is your own and which is referenced appropriately. The university has in place measures to detect academic dishonesty in all its forms. If you are found to be cheating or attempting to gain an unfair advantage over other students in any way, this is considered academic misconduct and you will be penalised accordingly.

## Appendix -- Reading and Testing Values in Assembly

Reading input from the keyboard in assembly can be done in a number of different ways. We will look at the most basic -- accessing the raw input stream from standard input. The following code demonstrates how to store input into a variable `num`.

```assembly
; Read and store the user input
    mov eax, 3		; set system call to perform a read (SYS_READ)
    mov ebx, 0		; set input stream to standard input (STDIN)
    mov ecx, num	; set the location to read into
    mov edx, 2		; set the number of bytes to read, 2
    int 0x80		; call the operating system
```

**Note that to get one character from the user you need to read in two bytes -- one for the character and one for the carriage return.**

To check the input, we have to place it in an 8-bit register and use `cmp`. We have to use an 8-bit register as we have only read a byte. For example:

```assembly
; Check input
    mov al, [num]	; move num read into al register
    cmp al, 'x'		; compare al to character x
```

