Seminar Questions:

1. What is an absolute path?

1. What is a relative path? What is it relative to?

1. What do the os.getcwd() and os.chdir() functions do?

1. What are the . and .. folders?

1. Write a program that reads a person&#39;s name and computes the corresponding username. Use the basic input output process.

1. **Batch Usernames**. To see how all these pieces fit together, let&#39;s redo the username generation program. Our previous version created usernames interactively by having the user type in his or her name. If we were setting up accounts for a large number of users, the process would probably not be done interactively, but in batch mode. In batch processing, program input and output is done through files. Write a new program to process a file of names. Each line of the input file will contain the first and last names of a new user separated by one or more spaces. The program should produce an output file containing a line for each generated username.

*For this exercise use the [names.txt](https://raw.githubusercontent.com/roehampton/module-content/master/software-development-1/week-06/seminar/names.txt) dataset. Right-Click on the link and save it in your CWD.





1. **Two Word Random Password.** While generating a password by selecting random characters usually creates one that is relatively secure, it also generally gives a password that is difficult to memorize. As an alternative, some systems construct a password by taking two English words and concatenating them. While this password may not be as secure, it is normally much easier to memorize. Write a program that reads a file containing a list of words, randomly selects two of them, and concatenates them to produce a new password. When producing the password ensure that the total length is between 8 and 10 characters, and that each word used is at least three letters long. Capitalize each word in the password so that the user can easily see where one word ends and the next one begins. Finally, your program should display the password for the user.

*For this exercise use the [words.txt](https://raw.githubusercontent.com/roehampton/module-content/master/software-development-1/week-06/seminar/words.txt) dataset. Right-Click on the link and save it in your CWD.





