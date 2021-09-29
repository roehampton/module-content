# Seminar - Week 1
In this first seminar we will review some traditional problems with an algoritmic solution. 

## Task 1. Fibonacci sequence

The Fibonacci numbers Fn, form a sequence, called the Fibonacci sequence, such that each number is the sum of the two preceding ones, starting from 0 and 1.
This sequence is useful for many thing in mathematics (  https://en.wikipedia.org/wiki/Fibonacci_number ) maybe the most famous is its relation with the Golden ratio.

### Algorithm

Input: An integer number N>=0 <br>
Output: A Fibonacci sequence of order N

###  F<sub>0</sub> = 0;  F<sub>1</sub> = 0;
###  F<sub>n</sub> = F<sub>n-1</sub> + F<sub>n-2</sub>

Do you think the algorithm is correct?

Let's see how to code a Fibonacci sequence in Python and C.
Python version

```Python
ef recur_fibo(n):
   if n <= 1:
       return n
   else:
       return(recur_fibo(n-1) + recur_fibo(n-2))

nterms = 10

# check if the number of terms is valid
if nterms <= 0:
   print("Plese enter a positive integer")
else:
   print("Fibonacci sequence:")
   for i in range(nterms):
       print(recur_fibo(i))
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
What does this two implementations have in common? Both are recursive versions. They follow exactly the way the algorithm is defined. 


## Task2. Great Common Divisor (GDC)

The GDC is the largest natural number that divides both a and b without leaving a remainder.

### Algorithm (Euclide's algorithm)
Input: Two natural numbers a>=0,b>=0 <br>
Output: The GDC between a and b.

The algorithm can be written as a sequence of equations
### a=q<sub>0</sub>b + r<sub>0</sub>
### b=q<sub>1</sub>r<sub>0</sub> + r<sub>1</sub>
### r<sub>0</sub>=q<sub>2</sub>r<sub>1</sub> + r<sub>2</sub>
### r<sub>1</sub>=q<sub>3</sub>r<sub>2</sub> + r<sub>3</sub>
### . . .

k is an integer that counts the steps of the algorithm, starting with zero. Each step begins with two nonnegative remainders rk−1 and rk−2, rk−1 < rk−2. The goal of the kth step is to find a quotient qk and remainder rk that satisfy the equation
###  r<sub>k-2</sub> = q<sub>k</sub>r<sub>k-1</sub> + r<sub>k</sub> and to have 0 ≤ rk < rk−1.  <br>

Since the remainders decrease with every step but can never be negative, a remainder r<sub>N</sub> must eventually equal zero, at which point the algorithm stops

Example   (from https://en.wikipedia.org/wiki/Euclidean_algorithm#Background:_greatest_common_divisor):
a = 1071 and b = 462
<table border = 1>
	<tr>
		<td>
			Step	
		</td>
		<td>
			Equation	
		</td>
		<td>
			Quotient and remainder
		</td>
	</tr>
	<tr>
		<td>
			0	
		</td>
		<td>
			1071 = q0 462 + r0	
		</td>
		<td>
			q0 = 2 and r0 = 147	
		</td>
	</tr>
	<tr>
		<td>
			1	
		</td>
		<td>
			462 = q1 147 + r1	
		</td>
		<td>
			q1 = 3 and r1 = 21	
		</td>
	</tr>
	<tr>
		<td>
			2	
		</td>
		<td>
			147 = q2 21 + r2
		</td>
		<td>
			q2 = 7 and r2 = 0; algorithm ends
		</td>
	</tr>
</table>

Do you think the algorithm is correct?

Let's see how to code a GCD in Python and C.

Python version

``` Python
def GCDEuclid(x, y):
     while(y):
       x, y = y, x % y
     return x
 
a = int(input("First number "))
b = int(input("Second number "))
print (GCDEuclid(a,b))

```
<i> In Python, there is the math.gcd(a,b) function </i>

``` Python
# Python code to demonstrate gcd()
# method to compute gcd

import math

print ("The gcd of 60 and 48 is : ",end="")
print (math.gcd(60,48))

```
C version

``` C
#include <stdio.h>
gcd(int u, int v) {
  if (u < 0) u = -u;
  if (v < 0) v = -v;
  if (v) while ((u %= v) && (v %= u));
  return (u + v);
}

int main()
{
	int a,b;
 	printf("First number: ");    
    	scanf("%d",&a);    
	printf("Second number: ");    
    	scanf("%d",&b);    
	printf("GCD of %d and %d is %d ", a, b, gcd(a, b));
	return 0;
}


```
## Task 3. Towers of Hanoi

### Algorithm
Input: Number of disks <br>
Ouput: A series of steps explaining how to move the disks according to the rules

Move the top N−1 disks to an intermediate rod.
Move the bottom disk to the destination rod.
Finally, move the N−1 disks from the intermediate peg to the destination peg.

We already see that the algorithm is not only correct, but efficient. 

Let us review some recursive implementations in Python and C
``` Python
# Recursive Python function to solve the tower of hanoi

def TowerOfHanoi(n , source, destination, auxiliary):
	if n==1:
		print "Move disk 1 from source",source,"to destination",destination
		return
	TowerOfHanoi(n-1, source, auxiliary, destination)
	print "Move disk",n,"from source",source,"to destination",destination
	TowerOfHanoi(n-1, auxiliary, destination, source)
		
# Driver code
n = 4
TowerOfHanoi(n,'A','B','C')
# A, C, B are the name of rods

# Contributed By Dilip Jain

```
```Python
def moveTower(height,fromPole, toPole, withPole):
    if height >= 1:
        moveTower(height-1,fromPole,withPole,toPole)
        moveDisk(fromPole,toPole)
        moveTower(height-1,withPole,toPole,fromPole)

def moveDisk(fp,tp):
    print("moving disk from",fp,"to",tp)

moveTower(3,"A","B","C")
```

C version

```C
#include <stdio.h>

// C recursive function to solve tower of hanoi puzzle
void towerOfHanoi(int n, char from_rod, char to_rod, char aux_rod)
{
	if (n == 1)
	{
		printf("\n Move disk 1 from rod %c to rod %c", from_rod, to_rod);
		return;
	}
	towerOfHanoi(n-1, from_rod, aux_rod, to_rod);
	printf("\n Move disk %d from rod %c to rod %c", n, from_rod, to_rod);
	towerOfHanoi(n-1, aux_rod, to_rod, from_rod);
}

int main()
{
	int n = 4; // Number of disks
	towerOfHanoi(n, \'A\', \'C\', \'B\'); // A, B and C are names of rods
	return 0;
}

```

What about an iterative version of the Hanoi Towers? Sadly, it is not trivial and you need to use one of the data structures we will review later in this unit: Stacks.
