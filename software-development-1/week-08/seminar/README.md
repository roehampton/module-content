Seminar 8

1. **Summing Integers:** Design a recursive function that computes the sum of all the integers from 0 up to and including some positive integer, n.



2. **String Reversal** : Using recursion, write a function that computes the reverse of a string.

The basic idea is to think of a string as a recursive object; a large string is composed out of smaller objects, which are also strings. In fact, one very handy way to divide up virtually any sequence is to think of it as a single first item that just happens to be followed by another sequence. In the case of a string, we can divide it up into its first character and &quot;all the rest.&quot; If we reverse the rest of the string and then put the first character on the end of that, we&#39;ll have the reverse of the whole string.



3. **Anagrams** : Write a function that generates a list of all the possible anagrams of a string.

An anagram is formed by rearranging the letters of a word. Anagrams are often used in word games, and forming anagrams is a special case of generating the possible permutations (rearrangements) of a sequence, a problem that pops up frequently in many areas of computing and mathematics.



4. **: Roman Numerals** : Create a recursive function that converts a Roman numeral to an integer. Your function should process one or two characters at the beginning of the string, and then call itself recursively on all of the unprocessed characters. Use an empty string, which has the value 0, for the base case. In addition, write a main program that reads a Roman numeral from the user and displays its value.


As the name implies, Roman numerals were developed in ancient Rome. Even after the Roman empire fell, its numerals continued to be widely used in Europe until the late middle ages, and its numerals are still used in limited circumstances today.

Roman numerals are constructed from the letters M, D, C, L, X, V and I which represent 1000, 500, 100, 50, 10, 5 and 1 respectively. The numerals are generally written from largest value to smallest value. When this occurs the value of the number is the sum of the values of all of its numerals. If a smaller value precedes a larger value then the smaller value is subtracted from the larger value that it immediately precedes and that difference is added to the value of the number. 
