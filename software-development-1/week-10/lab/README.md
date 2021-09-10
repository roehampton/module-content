1. A palindrome is a word or sentence that contains the same sequence of letters reading it either forwards or backwards. For example is &#39;madam.&quot; Write a recursive function that detects whether a string is a palindrome. The basic idea is to check that the first and last letters of the string are the same letter; if they are, then the entire string is a palindrome if everything between those letters is a palindrome. There are a couple of special cases to check for. If either the first or last character of the string is not a letter, you can check to see if the rest of the string is a palindrome with that character removed. Also, when you compare letters, make sure that you do it in a case-insensitive way.
Use your function in a program that prompts a user for a phrase and then tells whether or not it is a palindrome. A few words for for testing are: &#39;noon&quot;, &#39;rotator&quot;, &#39;tenet&quot;

2. Write and test a recursive function max to find the largest number in a list. The max is the larger of the first item and the max of all the other items.


4. Computer scientists and mathematicians often use numbering systems other than base 10. Write a program that allows a user to enter a number and a base and then prints out the digits of the number in the new base. Use a recursive function baseConversion(num, base) to print the digits. Hint: Consider base 10. To get the right most digit of a base 10 number, simply look at the remainder after dividing by 10. For example,153 % 10 is 3. To get the remaining digits, you repeat the process on 15, which is just 153 // 10. This same process works for any base. The only problem is that we get the digits in reverse order (right to left).


6. Transform our Binary Search code from the lab into a recursive function.
