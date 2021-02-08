# Software Development 2 Coursework 1

This is coursework two of Software Development 2. This coursework is worth 20% of the module total mark. **Submission deadline is Week 5 -- Friday 19th of February by 16.00 (4 pm) UK Time.**

You work for an organisation that builds small command line programs. Your colleague has written a programme, but is having real problems making it work. They are new to programming in C and are struggling with getting the program to build and then run. They have provided their code, and you need to fix it and add some additional features for them.

The program presents the user with a menu. The user then selects an option from the menu. The menu provides the following options:

1. Play guessing game.
2. Temperature conversion.
3. Find the smallest number.
4. Find the largest number.
5. Convert a number to English words.

If `0` is entered the program will exit. The five options behave as follows:

1. The computer will randomly select a number and then ask the user to guess the number. The computer will tell the user if the guess is too high or too low. When the user correctly guesses, the computer congratulates them.
2. The computer will ask the user if they want to convert from Fahrenheit to Celsius or from Celsius to Fahrenheit. The computer then asks for a temperature and provides the appropriately converted temperature.
3. The computer asks the user to enter 10 numbers. It then finds the smallest number from the 10 numbers entered.
4. As option 3 except the largest number is returned.
5. The computer will ask the user for a number. It will then convert this into English words. For example, entering 1050 will output one thousand and fifty; 239 will output two hundred and thirty nine.

## Requirements

Your colleague is really struggling to get this program to work. Currently, the program doesn't compile, and they are unsure why. When it did compile, they noticed the following bugs:

- Getting the user's choice for the menu doesn't seem to work. The choice always comes back as an incorrect choice.
- Guess the number has some odd behaviour. It doesn't appear to be random. Each time the application is restarted, the application starts using the same numbers as the last time it ran.
- Finding the smallest number doesn't work at all. It can rarely return the right answer, but it is most often wrong.
- The menu system when it was working just seems to run all the options.

Your colleague is so perplexed, they haven't even attempted to implement the following features:

- Converting temperatures -- they have no idea how to do it.
- Finding the largest number -- they cannot get find smallest to work, so how will they get find largest to work.
- Number to English -- they don't know where to start.

Your task is to fix the bugs in the program, and implement the unfinished features.

Finally, as your colleague needs to understand what the code does, you will need to provide clear comments explaining what the code you write does.

## Restrictions and Resources

**Your application must be based purely in C using the C standard library** This means:

- **You cannot write any code in C++.**
- **You cannot use libraries that are not provided by standard C.**
- **Your code must compile using a standard C compiler, such as Microsoft's `cl`, `gcc`, and `clang`.**

## Submission

**Your code must be submitted in Moodle by the deadline provided.** The submission must be your own work. **If it is suspected that your submission is not your own work then your work will be referred for an academic misconduct investigation.**

The submission to Moodle must be a ZIP file containing the following:

- The code file(s) required to build your application.
- A read me file indicating the bugs you've fixed and the features implemented.

Your ZIP file **must** use your student ID as a name. For example, if your student ID is abc1234, your ZIP file should be called `abc1234.zip`.

## Deadline

**This coursework is due 16.00 (4pm) UK time on Friday 19th of February. Late submissions will be capped at 40%.**

## Marking Scheme

The following rubric will be used:

| **Criteria**| **Excellent** | **Good** | **Developing** | **Not Attempted** |
| ----------- | ------------- | -------- | -------------- | ------------------------ |
| **Solution** the completeness of the code fo meet the specification given. | A completed solution meeting all the specifications.           | A completed solution that does not quite meet all the specifications. | A completed solution is implemented and runs but lacks much of the specification. | Solution doesn’t run or does not meet the specifications defined. |
| **Correctness** ability to create code that reliably produces correct answers or appropriate results. | Program produces correct answers or appropriate results for all inputs tested. | Program produces correct answers or appropriate results for most inputs. | Program approaches correct answers or appropriate results for most inputs but can contain miscalculations. | Program does not produce correct answers or appropriate results for most inputs. |
| **Logic** ability to use correct program structures appropriate to the problem domain. | Program logic is correct with no known boundary errors, and no redundant or contradictory conditions. | Program logic is mostly correct but may contain an occasional boundary error or redundant or contradictory condition. | Program logic is on the right track but shows no recognition of boundary conditions (such as < vs. <=). | Program contains some conditions that specify the opposite of what is required (less than vs. greater than), confuse Boolean AND/OR operators, or lead to infinite loops. |
| **Robustness** ability of the program to handle unexpected input and error conditions correctly as evidenced via testing. | Program handles erroneous or unexpected input gracefully; action is taken without surprising the user. Boundary cases are considered and tested. | All obvious error conditions are checked for and appropriate action is taken. Nearly all boundary cases are considered and tested. | Some obvious error conditions are checked for and some sort of action is taken. Most boundary cases are considered and tested. | Program often fails or fails completely. Boundary conditions are not tested for. |
| **Error freedom** removal of all errors existing within the current program. | All errors removed such that the program will compile and run under all conditions. | All obvious errors are removed but there are some smaller issues not rectified. Program will compile and run. | Some obvious errors fixed but some still exist. Program will compile and run. | Program either fails to compile, or if it does not further errors have been fixed. |
| **Clarity** ability to format and document code for human consumption (Good Style) | Program contains appropriate documentation for all major functions, variables, or non-trivial algorithms. Formatting, indentation, and other white space aids readability. | Program contains some documentation on major functions, variables, or nontrivial algorithms. Indentation and other formatting is appropriate. | Program contains some documentation (at least the student’s name and program’s purpose) but has occasionally misleading indentation. | Program contains no documentation, or grossly misleading indentation. |

### Academic Misconduct

All submissions will be processed through a code plagiarism tool. If signs of misconduct are found, all students involved will be contacted to discuss further steps. Please see here for information on academic integrity at the university <https://portal.roehampton.ac.uk/information/Pages/Academic-Integrity.aspx>.

Our guiding principle is that academic integrity and honesty are fundamental to the academic work you produce at the University of Roehampton. You are expected to complete coursework which is your own and which is referenced appropriately. The university has in place measures to detect academic dishonesty in all its forms. If you are found to be cheating or attempting to gain an unfair advantage over other students in any way, this is considered academic misconduct and you will be penalised accordingly. Please don’t do it.