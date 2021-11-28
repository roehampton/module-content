# Computer Systems Coursework 1 -- Assembly Programming

Part 1 of the coursework is worth 40% of the total coursework mark.

Part 1 of the coursework focuses on assembly programming. This coursework meets the module learning outcome *Write assembly code segments.* You will submit an assembly code file to complete this coursework.

## Question 1: write an assembly program using `NASM` that outputs the timetables from 1 to 13. The output should be:

```
     1   2   3   4   5   6   7   8   9  10  11  12  13
 1   1   2   3   4   5   6   7   8   9  10  11  12  13
 2   2   4   6   8  10  12  14  16  18  20  22  24  26
 3   3   6   9  12  15  18  21  24  27  30  33  36  39
 4   4   8  12  16  20  24  28  32  36  40  44  48  52
 5   5  10  15  20  25  30  35  40  45  50  55  60  65
 6   6  12  18  24  30  36  42  48  54  60  66  72  78
 7   7  14  21  28  35  42  49  56  63  70  77  84  91
 8   8  16  24  32  40  48  56  64  72  80  88  96 104
 9   9  18  27  36  45  54  63  72  81  90  99 108 117
10  10  20  30  40  50  60  70  80  90 100 110 120 130
11  11  22  33  44  55  66  77  88  99 110 121 132 143
12  12  24  36  48  60  72  84  96 108 120 132 144 156
13  13  26  39  52  65  78  91 104 117 130 143 156 169
```

Code requirements:

- **Your assembly code must calculate each timetable value.** That is, to output the value of 10 * 7 your program must undertake that calculation. **Simply printing a stored string of results will provide a mark of 0.**
- **Your assembly code must use `nam` as an assembler. Not doing so will result in a mark of 0.**


## Question 2: Write a program that can check if a number is divisible by 2 and 8. The program could print numbers in a loop and remember to draw a flowchart or state machine representation of your program.

## Submission Requirements

You must submit your assembly code file to Moodle. The file should be documented to explain your implementation. Name the code file `coursework.asm`.

**Your assembly code must be buildable using `nasm`. This is not negotiable. If you use a different assembler your assessment will be graded at 0.**

**Do not submit any other files.** Your mark will be adversely affected if you submit incorrect files.

## Marking Scheme

The following rubric will be used to assess your work.

| **Criteria**                                                 | **Excellent**                                                | **Satisfactory**                                             | **Not satisfactory**                                         | **Not attempted**                                            |
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

