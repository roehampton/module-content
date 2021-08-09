# Seminar - Week 1
In this first seminar we will review traditional algoritms 
## Fibonacci

The Fibonacci numbers Fn, form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1.

###  F<sub>0</sub> = 0;  F<sub>1</sub> = 0;
###  F<sub>n</sub> = F<sub>n-1</sub> + F<sub>n-2</sub>

This sequence is useful for many thing in mathematics (  https://en.wikipedia.org/wiki/Fibonacci_number ) maybe the most famous is its relation with the Golden ratio.

Python version

```Python
n = int(input("How many terms? "))
# first two terms
n1, n2 = 0, 1
count = 0
# check if the number of terms is valid
if n <= 0:
   print("Please enter a positive integer")
# if there is only one term, return n1
elif nterms == 1:
   print("Fibonacci sequence upto",n,":")
   print(n1)
# generate fibonacci sequence
else:
   print("Fibonacci sequence:")
   while count < n:
       print(n1)
       nth = n1 + n2
       n1 = n2
       n2 = nth
       count += 1
```
C version
``` C
#include<stdio.h>    
void Fibonacci(int n){    
    static int n1=0,n2=1,n3;    
    if(n>0){    
         n3 = n1 + n2;    
         n1 = n2;    
         n2 = n3;    
         printf("%d ",n3);    
         printFibonacci(n-1);    
    }    
}    
int main(){    
    int n;    
    printf("Enter the number of elements: ");    
    scanf("%d",&n);    
    printf("Fibonacci Series: ");    
    printf("%d %d ",0,1);    
    Fibonacci(n-2);//n-2 because 2 numbers are already printed    
  return 0;  
 }    
```



