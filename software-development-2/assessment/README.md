# Software Development 2 Coursework

This coursework is worth 60% of the module total. The coursework is delivered in three parts.

In this coursework, you will be given a starting application that you have to fix and extend based on the given criteria for each stage. The program requires you to read and understand existing code, as well as research what some of the code means. The program itself is quite simple, but requires careful planning and thought to extend.

The rest of the coursework requirements are laid out as follows:

- Requirements -- details of any overarching requirements for this coursework.
- Program Specification -- details how the program should work.
- Part One -- details the requirements for submitting coursework one.
- Part Two -- details the requirements for submitting coursework two.
- Part Three -- details the requirements for submitting coursework three.

## Requirements and Submission

The following requirements cover all parts of the coursework.

**Your application must be in C++ using the standard library** This means:

- **You cannot use libraries that are not provided by standard C++.**
- **Your code must compile using Microsoft's standard C/C++ compiler, which is part of Visual Studio.** If your code is specific for macOS or Linux then it will be marked down accordingly.

**Your code must be submitted in Moodle by the deadline provided.** The submission must be your own work. **If it is suspected that your submission is not your own work then your work will be referred for an academic misconduct investigation.**

The submission to Moodle must be a ZIP file containing the following:

- The code file(s) required to build your application.
- A read me file indicating the bugs you've fixed and/or the features implemented.

Your ZIP file **must** use your student ID as a name. For example, if your student ID is abc1234, your ZIP file should be called `abc1234.zip`.

**All coursework submissions must be demonstrated to the module tutor in class during lab time. Any submissions not demonstrated to the module tutor will be marked at zero.**

## Program Specification

You have been given a program that manages employee data. Employee data is maintained in a data structure with the following fields:

- The employee number -- an `int`.
- The employee name -- a `string`.
- The employee date of birth (dob) -- a `string`.
- The employee telephone number -- a `string`.
- The employee postcode -- a `string`.
- A checksum code for validation -- an `int`.

The program will present the user with a menu. There are five options:

1. Add a new employee from the keyboard -- this will prompt the user for the above fields.
2. Print all the employees -- this will print all the entered employee details in a table format.
3. Read employee data from a file -- this will prompt the user for a filename from which to read existing employee data.
4. Write employee data to a file -- this will prompt the user for a filename to output the current employee data to.
5. Exit the program.

### Printing the Employee Data

Employee data must be printed in a table with the following specifications:

- Employee number -- should be in a cell 10 characters wide.
- Name -- should be in a cell 20 characters wide.
- Date of birth -- should be in a cell 12 characters wide.
- Telephone number -- should be in a cell 13 characters wide.
- Postcode -- should be in a cell 10 characters wide.

## Part One

**Submission date: Thursday 10th March by 14:00 via Moodle.**

**Part one of the coursework is worth 33% of the coursework total, and 20% of the module total.**

Part one of the coursework covers the following two module learning outcomes:

- **Use types and type-error messages to write and debug programs.**
- **Analyse the extent to which another programmer’s code meets documentation and programming style standards.**

The current version of the program can be downloaded from Moodle. However, it has a number of issues that you must fix.

- The code is a mess. You must tidy the code to make it readable.
- The program lacks documentation. You must add appropriate commenting to the code to tell other programmers what the program does.
- The program doesn't compile due to type errors. You must fix the issue with the types (hint -- remember the difference between an `int` and a `string`). **You cannot change the `employee` data structure to make this work.**
- The employee data is not printed in a table meeting the specifications above.

### Rubric

| **Criteria**                                                 | **Excellent**                                                | **Very Good**                                                | **Good**                                                     | **Developing**                                               | **Not Attempted**                                            |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| **Solution** the completeness of the code to meet the specification given. | A completed solution meeting all the specifications.         | A completed solution that does not quite meet all the specifications. | A completed solution that meets approximately 50% of the specification. | A completed solution is implemented and runs but lacks much of the specification. | The solution doesn’t run or does not meet the specifications defined. |
| **Correctness** ability to create code that reliably produces correct answers or appropriate results. | The program produces correct answers or appropriate results for all inputs tested. | The program produces correct answers or appropriate results for most inputs. | The program approaches correct answers or appropriate results for most inputs but can contain miscalculations. | The program often produces incorrect answers or inappropriate results, but is almost there in many cases. | The program does not produce correct answers or appropriate results for most inputs. |
| **Error freedom** removal of all errors existing within the current program. | All errors are removed such that the program will compile and run under all conditions. | All obvious errors are removed but there are some smaller issues not rectified. The program will compile and run. | Some obvious errors are fixed but some still exist. The program will compile and run. | Program will compile but will fail during execution due to existing errors. | The program either fails to compile or if it does not further errors have been fixed. |
| **Clarity** ability to format and document code for human consumption (Good Style) | Program contains appropriate documentation for all major functions, variables, or non-trivial algorithms. Formatting, indentation, and other white space aids readability. | The program contains some documentation on major functions, variables, or nontrivial algorithms. Indentation and other formatting is appropriate. | The program contains some key documentation such as in functions and variables, but the documentation is not descriptive or helpful. | The program contains some documentation (at least the student’s name and the program’s purpose) but has occasionally misleading indentation. | The program contains no documentation, or grossly misleading indentation. |
| **Submission.** The submission meets norms described for the coursework. | Coursework has been submitted in a correct zip file, including a read me, and contains all the files necessary to run the program. | Coursework submission missing a particular factor (e.g., incorrectly named zip, not a ZIP, or read me missing). | Coursework submission two or more factors, or maybe missing files that are necessary for building. | Coursework submission is missing several factors.            | Coursework submission missing many factors and is not in a quilty state for a professional submission. |

## Part Two

**Submission date: Thursday 31st of March by 14:00 via Moodle.**

**Part two of the coursework is worth 33% of the coursework total, and 20% of the module total.**

Part two of the coursework covers the following learning outcome:

- **Write simple programs at the assembly/machine level for string processing and manipulation.**

The program contains two functions that process the name of the employee:

- `capitalise_name` ensures that each character in the name is capitalised (e.g., `a` becomes `A`, `b` becomes `B`, etc.).
- `generate_checksum` calculates the checksum for the employee by adding up the characters in the name.

We want to improve the performance of processing multiple employees, and it is believed that these functions may be faster if they were programmed in assembly. Your task is to convert `capitalise_name` and `generate_checksum` to be assembly based. That is, these functions should process the string character data using only assembly instructions written in inline assembly.

### Helpful Advice

From ASCII we know that uppercase characters have values 65 to 90. Lowercase characters have values 97 to 122. Therefore:

```
a - A = 32
b - B = 32
...
z - Z = 32
```

### Rubric

| **Criteria**                                                 | **Excellent**                                                | **Very Good**                                                | **Good**                                                     | **Developing**                                               | **Not Attempted**                                            |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| **Solution** the completeness of the code to meet the specification given. | A completed solution meeting all the specifications.         | A completed solution that does not quite meet all the specifications. | A completed solution that meets approximately 50% of the specification. | A completed solution is implemented and runs but lacks much of the specification. | The solution doesn’t run or does not meet the specifications defined. |
| **Correctness** ability to create code that reliably produces correct answers or appropriate results. | The program produces correct answers or appropriate results for all inputs tested. | The program produces correct answers or appropriate results for most inputs. | The program approaches correct answers or appropriate results for most inputs but can contain miscalculations. | The program often produces incorrect answers or inappropriate results, but is almost there in many cases. | The program does not produce correct answers or appropriate results for most inputs. |
| **Logic** ability to use correct program structures appropriate to the problem domain. | Program logic is correct with no known boundary errors, and no redundant or contradictory conditions. | Program logic is mostly correct but may contain an occasional boundary error or redundant or contradictory condition. | Program logic is generally correct but contains a few boundary errors and redundant conditions. | Program logic is on the right track but shows no recognition of boundary conditions (such as < vs. <=). | The program contains some conditions that specify the opposite of what is required (less than vs. greater than), confuse Boolean AND/OR operators, or lead to infinite loops. |
| **Error freedom** removal of all errors existing within the current program. | All errors are removed such that the program will compile and run under all conditions. | All obvious errors are removed but there are some smaller issues not rectified. The program will compile and run. | Some obvious errors are fixed but some still exist. The program will compile and run. | Program will compile but will fail during execution due to existing errors. | The program either fails to compile or if it does not further errors have been fixed. |
| **Clarity** ability to format and document code for human consumption (Good Style) | Program contains appropriate documentation for all major functions, variables, or non-trivial algorithms. Formatting, indentation, and other white space aids readability. | The program contains some documentation on major functions, variables, or nontrivial algorithms. Indentation and other formatting is appropriate. | The program contains some key documentation such as in functions and variables, but the documentation is not descriptive or helpful. | The program contains some documentation (at least the student’s name and the program’s purpose) but has occasionally misleading indentation. | The program contains no documentation, or grossly misleading indentation. |

## Part Three

**Submission date: Thursday 28th of April by 14:00 via Moodle.**

**Part three of the coursework is worth 33% of the coursework total, and 20% of the module total.**

Much of the data read by this program is not validated. That is, it is possible to enter data that is not in the correct format. You must extend the program so that only correctly entered data can be accepted into the store of employees.

- The name must only contain letters and appropriate symbols.
  - For example, the following are acceptable:
    - Kevin Chalmers
    - Kimia Aksir
    - Mary O'Neil
    - Ahmed Al-Dubai
  - The following are not acceptable:
    - Kevin4 -- contains a number
    - Pelumi @Roehampton -- contains an inappropriate symbol.

- The date of birth must use the format `yyyy/mm/dd` -- this is to allow quick sorting of dates.
  - For example, the following are acceptable:
    - `2021/01/24`
    - `2021/10/01`
    - `1984/07/19`
  - The following are not acceptable:
    - `21/10/15` -- year must be four digits.
    - `2021/1/16` -- month must be two digits.
    - `2021/01/1` -- day must be two digits.
    - `2021/13/12` -- there is no month greater than 12.
    - `2021/05/32` -- there is no day greater than 31.
  - Your organisation thinks it would be fantastic and will pay a bonus if you can ensure the date is valid. That is, only the correct number of days for a month are stored, including leap years. That is:
    - `2021/04/31` -- is invalid, as April only has 30 days.
    - `2021/02/29` -- is invalid, as February only has 29 days in 2021.
    - `2020/02/29` -- is valid, as February had 29 days in 2020.
- Phone numbers are of the right length, starting with a `0`.
  - For example, the following are acceptable:
    - 01224565501
    - 07777000000
  - The following are not acceptable:
    - 9520111111 -- doesn't start with a `0`
    - 01234 -- isn't 11 digits long
    - 01234 567890 -- has a space
- Postcodes must follow the correct format for a postcode. That is one to two uppercase letters, one to two numbers, a space, a number, then two uppercase letters.
  - For example, the following are acceptable:
    - SW15 1PU
    - E1 5RF
    - G12 6PT
    - EH1 1HR
  - The following are not acceptable:
    - SSS5 9PU -- has three letters at the start.
    - S154 9LP -- has three numbers before the space.

You can choose whichever method you like to ensure that the data structure will contain correct data, but your mark will depend on the approach you use. For example, regular expressions are considered a hard approach, input validation medium, and simply asking one at a time and looping is considered easy.

### Rubric

| **Criteria**                                                 | **Excellent**                                                | **Very Good**                                                | **Good**                                                     | **Developing**                                               | **Not Attempted**                                            |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| **Solution** the completeness of the code to meet the specification given. | A completed solution meeting all the specifications.         | A completed solution that does not quite meet all the specifications. | A completed solution that meets approximately 50% of the specification. | A completed solution is implemented and runs but lacks much of the specification. | The solution doesn’t run or does not meet the specifications defined. |
| **Correctness** ability to create code that reliably produces correct answers or appropriate results. | The program produces correct answers or appropriate results for all inputs tested. | The program produces correct answers or appropriate results for most inputs. | The program approaches correct answers or appropriate results for most inputs but can contain miscalculations. | The program often produces incorrect answers or inappropriate results, but is almost there in many cases. | The program does not produce correct answers or appropriate results for most inputs. |
| **Logic** ability to use correct program structures appropriate to the problem domain. | Program logic is correct with no known boundary errors, and no redundant or contradictory conditions. | Program logic is mostly correct but may contain an occasional boundary error or redundant or contradictory condition. | Program logic is generally correct but contains a few boundary errors and redundant conditions. | Program logic is on the right track but shows no recognition of boundary conditions (such as < vs. <=). | The program contains some conditions that specify the opposite of what is required (less than vs. greater than), confuse Boolean AND/OR operators, or lead to infinite loops. |
| **Robustness** ability of the program to handle unexpected input and error conditions correctly as evidenced via testing. | The program handles erroneous or unexpected input gracefully; action is taken without surprising the user. Boundary cases are considered and tested. | All obvious error conditions are checked for and appropriate action is taken. Nearly all boundary cases are considered and tested. | Some obvious error conditions are checked for and some sort of action is taken. Most boundary cases are considered and tested. | The program deals with the most obvious error conditions, but the program will often just exit or restart when this occurs. | The program often fails or fails completely. Boundary conditions are not tested for. |
| **Validation approach** to use advanced features to ensure correct input is entered by the user. | The program uses regular expressions almost exclusively and ensures that correct data is input by the user before outputting to a file. The additional edge cases defined either all dealt with or almost all dealt with. | Program possibly uses regular expressions in parts, but mainly uses input validation to ensure correct data is entered before outputting to a file. Some additional edge cases were possibly dealt with. | Program possibly uses input validation in parts, but mainly breaks down input into sections to deal with any issues of input. No edge cases were dealt with. | The program only deals with the simplest of input validation (e.g., no space in a phone number). | Input is not validated correctly or is barely validated. This leads to incorrect data being written to the file. |

### Academic Misconduct

All submissions will be processed through a code plagiarism tool. If signs of misconduct are found, all students involved will be contacted to discuss further steps. Please see here for information on academic integrity at the university <https://portal.roehampton.ac.uk/information/Pages/Academic-Integrity.aspx>.

Our guiding principle is that academic integrity and honesty are fundamental to the academic work you produce at the University of Roehampton. You are expected to complete coursework that is your own and which is referenced appropriately. The university has in place measures to detect academic dishonesty in all its forms. If you are found to be cheating or attempting to gain an unfair advantage over other students in any way, this is considered academic misconduct and you will be penalised accordingly. Please don’t do it.