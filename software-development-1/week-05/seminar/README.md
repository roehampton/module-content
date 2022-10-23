Seminar 5.	

Write a Flowchart or Pseudocode for the following programs:

1. Write a function that takes three numbers as parameters and returns the median value of those parameters as its result. Include a main program that reads three values from the user and displays their median. Tip: The median value is the middle of the three values when they are sorted into ascending order. It can be found using if statements, or with a little bit of mathematical creativity.


2. A function that takes a string, s, as its first parameter, and the width of the window in characters, w, as its second parameter. Your function will return a new string that includes whatever leading spaces are needed so that s will be centred in the window when the new string is printed. The new string should be constructed in the following manner:
a. If the length of s is greater than or equal to the width of the window then s should be returned.
b. If the length of s is less than the width of the window then a string containing (len(s) - w) 2 spaces followed by s should be returned. Calling this function should display any strings centred in the window.


3. A function that generates a random password. The password should have a random length of between 7 and 10 characters. 


4. Write a flowchart for the following code:

```
import random
secretNumber = random.randint(1, 20)
print('I am thinking of a number between 1 and 20.')
for guessesTaken in range(1, 7):
                 print('Take a guess.')
                 guess = int(input())
                 if guess < secretNumber:
                     print('Your guess is too low.')
                 elif guess > secretNumber:
                     print('Your guess is too high.')
                 else:
                     break 
if guess == secretNumber:
                 print('Good job! You guessed my number in ' + str(guessesTaken) + ' guesses!')
else:
                 print('Nope. The number I was thinking of was ' + str(secretNumber))
```

5. A prime number is an integer greater than one that is only divisible by one and itself. Write a function that determines whether or not its parameter is prime, returning True if it is, and False otherwise. Write a flowchart for a program that reads an integer from the user and displays a message indicating whether or not it is prime. 

IV. Saturday nights changed forever when Lotto was introduced back in 1994. Since then, it’s become the nation’s favourite game – played by millions in towns and cities across the country. In order to win the top prize in the National Lottery’s lotto, one must match all 6 numbers of a ticket to the 6 numbers between 1 and 59 that are drawn by the lottery organizer. Write a flowchart for a program that generates a random selection of 6 numbers for a lottery ticket. Ensure that the 6 numbers selected do not contain any duplicates. Finally, display the numbers in ascending order. If you wish, you can use your program to pick your lucky number at : https://www.national-lottery.co.uk/games/lotto/about-lotto


