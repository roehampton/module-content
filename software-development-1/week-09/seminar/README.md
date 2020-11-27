Seminar 9

1. Approximately how many iterations will binary search need to find a value in a list of 512 items?
2. What do recursions on sequences often use as a base case?
3. What does an infinite recursion result in?
4. A palindrome is a sentence that contains the same sequence of letters reading it either forwards or backwards. For example is &#39;Able was I, ere I saw Elba.&quot; Write a recursive function that detects whether a string is a palindrome. The basic idea is to check that the first and last letters of the string are the same letter; if they are, then the entire string is a palindrome if everything between those letters is a palindrome. There are a couple of special cases to check for. If either the first or last character of the string is not a letter, you can check to see if the rest of the string is a palindrome with that character removed. Also, when you compare letters, make sure that you do it in a case-insensitive way.
Use your function in a program that prompts a user for a phrase and then tells whether or not it is a palindrome. Here&#39;s another classic for testing: &#39;A man, a plan, a canal, Panama!&quot;

5. Write and test a recursive function max to find the largest number in a list. The max is the larger of the first item and the max of all the other items.
6. Computer scientists and mathematicians often use numbering systems other than base 10. Write a program that allows a user to enter a number and a base and then prints out the digits of the number in the new base. Use a recursive function baseConversion(num, base) to print the digits. Hint: Consider base 10. To get the right most digit of a base 10 number, simply look at the remainder after dividing by 10. For example,153 % 10 is 3. To get the remaining digits, you repeat the process on 15, which is just 153 / 10. This same process works for any base. The only problem is that we get the digits in reverse order (right to left).
