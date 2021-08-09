# Seminar - Week 1
In this first seminar we will review traditional algoritms 
## Fibonacci

The Fibonacci numbers Fn, form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1.

###  F<sub>0</sub> = 0;  F<sub>1</sub> = 0;
###  F<sub>n</sub> = F<sub>n-1</sub> + F<sub>n-2</sub>

This sequence is useful for many thing in mathematics (  https://en.wikipedia.org/wiki/Fibonacci_number ) maybe the most famous is its relation with the Golden ratio. 

# Program to display the Fibonacci sequence up to n-th term

nterms = int(input("How many terms? "))

# first two terms
n1, n2 = 0, 1
count = 0

# check if the number of terms is valid
if nterms <= 0:
   print("Please enter a positive integer")
# if there is only one term, return n1
elif nterms == 1:
   print("Fibonacci sequence upto",nterms,":")
   print(n1)
# generate fibonacci sequence
else:
   print("Fibonacci sequence:")
   while count < nterms:
       print(n1)
       nth = n1 + n2
       # update values
       n1 = n2
       n2 = nth
       count += 1
