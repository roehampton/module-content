# Software Development 2 Coursework 3

## Overview

This is coursework two of Software Development 2. This coursework is worth 20% of the module total mark.

Your organisation wants to ensure that the data it receives from users is correct. They have developed some command line tools in C++, but they want to explore how to undertake input validation. They have asked you to right a test program that will accept four pieces of information from a user:

- Their name.
- Their date of birth.
- Their telephone number.
- Their postcode.

You have to write a program in C and/or C++ that accepts these pieces of data.

## Specification

The `validate` program is required to ask users for input until `q` is entered as an option. The four pieces of information must be saved as text to an output file, `output.txt`. `validate` must ensure that the data saved is of the correct format. This means:

- Names are capitalised.
  - For example, the following are acceptable:
    - Kevin Chalmers
    - George Alexander Louis Windsor
    - Mohandas Karamchand Gandhi
    - Augusta Ada King
  - The following are not acceptable:
    - Harriet tubman
    - amitave Banik
    - Martin luthor King
  - Your organisation thinks it would be fantastic and will pay a bonus if you can deal with the following name styles
    - Jean-Luc Picard
    - Mary O'Brien
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
- Phone numbers are of the right length, start with a `0`. The phone number may have a single space within it.
  - For example, the following are acceptable:
    - 01224565501
    - 01224 565501
    - 07777000000
  - The following are not acceptable:
    - 9520111111 -- doesn't start with a `0`
    - 01234 -- isn't 11 digits long
    - 01234 567 890 -- has two spaces
- Postcodes must follow the correct format for a postcode. That is one to two uppercase letters, one to two numbers, a space, a number, then two uppercase letters.
  - For example, the following are acceptable:
    - SW15 1PU
    - E1 5RF
    - G12 6PT
    - EH1 1HR
  - The following are not acceptable:
    - SSS5 9PU -- has three letters at the start.
    - S154 9LP -- has three numbers before the space.

You can choose whichever method you like to ensure that `output.txt` will contain correct data, but your mark will depend on the approach you use. For example, regular expressions are considered a hard approach, input validation medium, and simply asking one at a time and looping is considered easy.

## Restrictions and Resources

**Your application must be based in C and/or C++ using the standard library** This means:

- **You cannot use libraries that are not provided by standard C or C++.**
- **Your code must compile using a standard C compiler, such as Microsoft's `cl`, `gcc`, and `clang`.**

## Submission

**Your code must be submitted in Moodle by the deadline provided.** The submission must be your own work. **If it is suspected that your submission is not your own work then your work will be referred for an academic misconduct investigation.**

The submission to Moodle must be a ZIP file containing the following:

- The code file(s) required to build your application.
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
| **Validation approach** ability to use advanced features to ensure correct input is entered by the user. | Program uses regular expressions almost exclusively and ensures that correct data is input by the user before outputting to a file. The additional edge cases defined either all dealt with or almost all dealt with. | Program possibly uses regular expressions in parts, but mainly uses input validation to ensure correct data is entered before outputting to a file. Some additional edge cases possibly dealt with. | Program possibly uses input validation in parts, but mainly breaks down input into sections to deal with any issues of input. No edge cases dealt with. | Input is not validated correctly, or is barely validated. This leads to incorrect data being written to the file. |
| **Clarity** ability to format and document code for human consumption (Good Style) | Program contains appropriate documentation for all major functions, variables, or non-trivial algorithms. Formatting, indentation, and other white space aids readability. | Program contains some documentation on major functions, variables, or nontrivial algorithms. Indentation and other formatting is appropriate. | Program contains some documentation (at least the student’s name and program’s purpose) but has occasionally misleading indentation. | Program contains no documentation, or grossly misleading indentation. |

### Academic Misconduct

All submissions will be processed through a code plagiarism tool. If signs of misconduct are found, all students involved will be contacted to discuss further steps. Please see here for information on academic integrity at the university <https://portal.roehampton.ac.uk/information/Pages/Academic-Integrity.aspx>.

Our guiding principle is that academic integrity and honesty are fundamental to the academic work you produce at the University of Roehampton. You are expected to complete coursework which is your own and which is referenced appropriately. The university has in place measures to detect academic dishonesty in all its forms. If you are found to be cheating or attempting to gain an unfair advantage over other students in any way, this is considered academic misconduct and you will be penalised accordingly. Please don’t do it.