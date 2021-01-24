# Software Development 2 Lab 02 -- More C

 These tutorials are designed to teach you a number of C Programming principles with sophisticated topics and examples. The goal of each problem is not to solve that specific problem, but to exercise a certain set of skills, or to practice solving a certain type of problem. 

## If statements in C

The `if` statement in C is used to perform the operations based on some specific condition. The operations specified in if block is executed if and only if the given condition is true.

### Basic `if` Syntax

The structure of an if statement is as follows:

```c
if (condition)
{
  // Code to execute.
}
```

Here is a simple example that shows the syntax:

```c
if (5 < 10)
{
  printf(“Five is now less than ten, that’s a big surprise”);
}
```

Here, we’re just evaluating the statement, “is five less than ten”, to see if it is true or not; with any luck, it is! Let us write a full scenario:

```c
#include <stdio.h>

int main(int argc, char ** argv) 
{
	int x = 20;
  int y = 22;
	if (x<y)
	{
		printf("Variable x is less than y");
	}
	return 0;
}
```

Anything inside braces is called a compound statement, or a block. When using if statements, the code that depends on the `if` statement is called the **body** of the `if` statement.

### `else`

Sometimes when the condition in an `if` statement evaluates to false, it would be nice to execute some code instead of the code executed when the statement evaluates to true. The `else` statement effectively says that whatever code after it (whether a single line or code between brackets) is executed if the `if` statement is FALSE.

It can look like this:

```c
if (TRUE)
{
	// Execute these statements if TRUE
}
else
{
	// Execute these statements if FALSE
}
```

### `else if`

Another use of else is when there are multiple conditional statements that may all evaluate to true, yet you want only one if statement’s body to execute. You can use an `else if` statement following an `if` statement and its body; that way, if the first statement is true, the `else if` will be ignored, but if the `if` statement is false, it will then check the condition for the `else if` statement. If the `if` statement was true the `else` statement will not be checked. It is possible to use numerous else if statements to ensure that only one block of code is executed.

**When you compile and execute the below program, what this program will produce the result?** 

```c
#include <stdio.h> 

int main(int argc, char ** argv)
{
	int age;             /* Need a variable... */
	printf("Please enter your age: "); /* Asks for age */
	scanf("%d", &age);   /* The input is put in age */
  if (age < 100)       /* If the age is less than 100 */
  {      
		printf("You are pretty young!\n");
  }
	else if (age == 100) /* If the age is equal 100 */
  { 
		printf("You are old\n");
  }
	else 
  {
		printf("You are really old\n");
	}
 return 0;
}
```

**Now you need to implement the following programs.** 

1. Write a C program to read the age of a candidate and determine whether they are eligible for casting his/her own vote. If eligible print the message: `Congratulations! You are eligible to cast your vote`. If not print the message: `Sorry, you are not eligible to cast your vote`. Along with another message" `You would be able to cast your vote after N years` where `N` is the number of years until the candidate is 18. 
2. Write a C program to find the eligibility of admission for Computer Science course in the University of Roehampton London based on the following criteria:
   - Marks in Maths >=65
   - Marks in Phy >=55
   - Marks in Chem>=50
   - Total in all three subjects >=180 or Total in Math and Physics >=140

## `switch` Statement

When we discussed `if` statements, we introduced the idea of using multiple `else if` statements to combine different conditions. Although this is good for many general cases, we sometimes want to branch based on the value of a variable. This is where `case` statements come in useful. A `switch` statement allows a variable to be tested for equality against a list of values. Each value is called a `case`, and the variable being switched on is checked for each `switch case`.

### Syntax

The syntax for a switch statement in C programming language is as follows:

```c
switch (expression)
{
	case constant-expression:
		statement(s);
		break; /* optional */
	case constant-expression:
		statement(s);
		break; /* optional */
	/* you can have any number of case statements */
	default: /* Optional */
		statement(s);
}
```

The following rules apply to a `switch` statement:

- The expression used in a `switch` statement must have an integral or enumerated type or be of a class type in which the class has a single conversion function to an integral or enumerated type.
- You can have any number of `case` statements within a `switch`. Each case is followed by the value to be compared to and a colon.
- The constant-expression for a `case` must be the same data type as the variable in the switch, and it must be a constant or a literal.
- When the variable being switched on is equal to a `case`, the statements following that case will execute until a `break` statement is reached.
- When a `break` statement is reached, the `switch` terminates, and the flow of control jumps to the next line following the `switch` statement.
- Not every `case` needs to contain a `break`. If no `break` appears, the flow of control will fall through to subsequent cases until a `break` is reached.
- A `switch` statement can have an optional `default` case, which must appear at the end of the `switch`. The `default` case can be used for performing a task when none of the cases are true. No `break` is needed in the default case.

 As an example, we are going to write a simple calculator programme. 

```c
#include <stdio.h>

int main(int argc, char **argv)
{
	char operator;
	double n1, n2;
	printf("Enter an operator (+, -, \*, /): ");
	scanf("%c", &operator);
	printf("Enter two operands: ");
	scanf("%lf %lf",&n1, &n2);
	switch (operator)
	{
		case '+':
			printf("%.1lf + %.1lf = %.1lf",n1, n2, n1+n2);
			break;
		case '-':
			printf("%.1lf - %.1lf = %.1lf",n1, n2, n1-n2);
			break;
		case '*':
			printf("%.1lf * %.1lf = %.1lf",n1, n2, n1*n2);
			break;
		case '/':
			printf("%.1lf / %.1lf = %.1lf",n1, n2, n1/n2);
			break;
		// operator doesn’t match any case constant +, -, *, /
		default:
			printf("Error! operator is not correct");
	}
	return 0;
}
```

**When you compile and execute the program, what this program will produce the result?** 

As an example, we are going to write a program which is a Menu-Driven Program to perform a simple calculation.

```c
#include <stdio.h>

int main(int argc, char **argv)
{
	int num1, num2, opt;
	printf("Enter the first Integer :");
	scanf("%d", &num1);
	printf("Enter the second Integer :");
	scanf("%d", &num2);
  printf("\nInput your option :\n");
	printf("1-Addition.\n2-Substraction.\n3-    Multiplication.\n4-Division.\n5-Exit.\n");
	scanf("%d", &opt);
	switch (opt)
  {
		case 1:
			printf("The Addition of %d and %d is: %d\n",num1,num2,num1+num2);
			break;
		case 2:
			printf("The Substraction of %d and %d is: %d\n",num1,num2,num1-num2);**
			break;
		case 3:
			printf("The Multiplication of %d and %d is: %d\n",num1,num2,num1\*num2);**
			break;
		case 4:
			if (num2==0)
      {
				printf("The second integer is zero. Devide by zero.\n");
			} 
      else 
      {
				printf("The Division of %d and %d is : %d\n",num1,num2,num1/num2);
			} 
			break;
		case 5:
			break; 
		default:
      printf("Input correct option\n");
			break;
	}
}
```

**When you compile and execute the program, what this program will produce the result?** 

**Now you need to do implement the below programs by yourself.**

1. Write a program to read any day number in integer and display day name in the word. For example, Test Data: 4 ; Expected Output: Thursday
2. Write a program to read any digit, display in the word. For example, Test Data: 0; Expected Output: Zero

## C Loops 

There may be a situation, when you need to execute a block of code several number of times. In general, statements are executed sequentially: The first statement in a function is executed first, followed by the second, and so on. Programming languages provide various control structures that allow for more complicated execution paths. A loop statement allows us to execute a statement or group of statements multiple times and following is the general form of a loop statement in most of the programming languages. 

C programming language provides the following types of loops to handle looping requirements.

###  `while` Loop in C

A `while` loop statement in C programming language repeatedly executes a target statement as long as a given condition is true.

The syntax of a while loop in C programming language is:

```c
while (condition)
{
	statement(s);
}
```

Here, statement(s) may be a single statement or a block of statements. The condition may be any expression, and true is any nonzero value. The loop iterates while the condition is true.

**When you compile and execute the below program, what this program will produce the result?** 

```c
#include <stdio.h>

int main (int argc, char **argv) 
{
  /* local variable definition */
  int a = 10;
  /* while loop execution */
  while (a < 20)
  {
    printf("value of a: %d\n", a);
    a++;
  }
  return 0;
}
```

### `for` loop in C

 A `for` loop is a repetition control structure that allows you to efficiently write a loop that needs to execute a specific number of times.

The syntax of a for loop in C programming language is:

```c
for (init; condition; increment)
{
  statement(s);
}
```

Here is the flow of control in a for loop:

1. The init step is executed first, and only once. This step allows you to declare and initialize any loop control variables. You are not required to put a statement here, as long as a semicolon appears.

2. Next, the condition is evaluated. If it is true, the body of the loop is executed. If it is false, the body of the loop does not execute, and flow of control jumps to the next statement just after the for loop.
3. After the body of the for loop executes, the flow of control jumps back up to the increment statement. This statement allows you to update any loop control variables. This statement can be left blank, as long as a semicolon appears after the condition.
4. The condition is now evaluated again. If it is true, the loop executes and the process repeats itself (body of loop, then increment step, and then again condition). After the condition becomes false, the for loop terminates.

**When you compile and execute the below program, what this program will produce the result?** 

```c
 #include <stdio.h>

int main(int argc, char **argv)
{
  /* for loop execution */
  for (int a = 10; a < 20; a = a + 1)
  {
    printf("value of a: %d\n", a);
  }
  return 0;
}
```

### `do`...`while` loop in C 

Unlike `for` and `while` loops, which test the loop condition at the top of the loop, the `do`...`while` loop in C programming language checks its condition at the bottom of the loop. A `do`...`while` loop is similar to a `while` loop, except that a `do`...`while` loop is guaranteed to execute at least one time.

The syntax of a do...while loop in C programming language is:

```c
do
{
	statement(s);
} while (condition);
```

Notice that the conditional expression appears at the end of the loop, so the statement(s) in the loop execute once before the condition is tested.

**When you compile and execute the below program, what this program will produce the result?** 

```c
#include <stdio.h>

int main (int argc, char **argv ) 
{
  /* local variable definition */
  int a = 10;
  /* do loop execution */
  do
  {
    printf("value of a: %d\n", a);
    a = a + 1;
  } while(a < 20);
  return 0;
}
```

**Now you need to implement the following yourself:** 

1. Print half Pyramid of \*.
2. Print half Pyramid of Numbers.
3. Print half Pyramid of Alphabets.
4. Print inverted half pyramid of \*.
5. Print inverted half pyramid of numbers.
6. Print full Pyramid of \*.