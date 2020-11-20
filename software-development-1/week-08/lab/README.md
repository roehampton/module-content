# Software Development 1 
# Lab 8 -– Recussion and Exceptions

In this lab we will explore:

1. Concept of Recursion
2. Recursive Functions
3. Managing Errors and Exceptions


## Lesson 1: Recursion
Video: https://roehampton.cloud.panopto.eu/Panopto/Pages/Viewer.aspx?id=74469649-369b-457e-901b-ac7900c7ea65


We have explored many aspects of functions and we have seen that you can call a function from within a function.

An interesting aspect of functions however, is that a function can call itself. This known as recursion and can be a powerful technique for solving some problems.

We&#39;ll say that a function is _recursive_ if it is defined in terms of itself. If the definition is circular, however, it might not be that useful for us. What we really want in recursive functions is that it is being defined in terms of a simpler version of itself. As it cycles through itself, it must make progress towards a solution to a given problem. The classic recursive example in mathematics is factorial:


    n! =  n(n-l)(n-2). . . (1) 
    
    
and also by definition:


    0! = 1
    

For instance, as some of you might know, I&#39;m a wine enthusiast. If you go to a wine tasting, they&#39;ll give you five different wines to try. However, drinking the various flavours in different orders might affect how the others taste: If you drink a sweet one first and then a spicy one, it will be different than if you start with the spicy one and move on to the sweet one. If you wanted to try out every possible ordering, how many different orders would there be? It turns out the answer is a surprisingly large number: 120 different ways of combining them. The value 120 is the **factorial** of 5.


    5! =5(4)(3)(2)(1) 
    
    
Factorial is very useful for when we&#39;re trying to count:


1. how many different orders there are for things.

2. how many different ways we can combine things.

3. how many ways you can choose things from a collection of things.




We can implement a program to compute factorials using a simple loop that accumulates the factorial product. The basic outline would be:


    Input number to take factorial of, n 
    Compute factorial of n, fact
    Output fact 


Obviously, the tricky part here is in the second step.
 To compute the factorial we can decompose the process: To calculate **the factorial of 5, or 5!,** we first multiply (4) = 20. Then we take that result and do another multiplication: 20(3) = 60. This result is multiplied by 2: 6(2) = 120. Finally, we multiply this result by 1: 120(1) = 120.

Do you notice a pattern? We are doing repeated multiplications. Every time we multiply, we keep track of the product. This is called an accumulator pattern because we build up, or accumulate, a final value piece by piece. This common accumulator algorithm is as follows:


    Initialize the accumulator variable 
    Loop until final result is reached 
        update the value of accumulator variable 


To calculate factorial in a program, we can use an accumulator variable (to store each multiplication) and a loop structure.


    fact = 1
    for factor in [5,4,3,2,1]: 
        fact = fact * factor 


We have a couple of different range commands that produce an appropriate list of factors for computing the factorial of _n_. using the three-parameter version of range and a negative step to cause the counting to go backwards: range (n,1,-1). This one produces a list starting with _n_ and counting down (step -1) to, but not including 1:


    def factorial (n):
    fact = 1
    for factor in range(n,1,-1): 
        fact = fact * factor
    print("The factorial of", n, "is", fact) 

Is there a way to capture the essence of this calculation we are constantly repeating?


## Lesson 2: Recursive Functions in Python
Video: https://roehampton.cloud.panopto.eu/Panopto/Pages/Viewer.aspx?id=e4424dce-2529-4143-96ed-ac7900c7ead5


Looking at the calculation of _5!_, you will notice something interesting: it divides into subproblems that are just smaller versions of the original. If we remove the 5 from the front, what remains is a calculation of _4!_ . 
More generally:

![Alt text](img_factorial.png?raw=false "Expressin factorial as a recursive structure")


This gives us another way of expressing factorial in general: The factorial of any number greater than zero is defined to be that number times the factorial of one less than that number. This is a recursive definition, and it provides a very simple method of calculating a factorial. Consider the value of _4!_. By definition we have


    4! = 4(4 - 1)! = 4(3!)
   
To find out what is _3!_ we apply the definition again:


    4! = 4(3!) = 4[(3)(3- 1)!] = 4(3)(2!)


Now, of course, we have to expand 2!, which requires 1!, which requires 0!. Since 0! is simply 1, that&#39;s the end of the calculation.


    4! = 4(3!) = 4(3)(2!) = 4(3)(2)(1!) = 4(3)(2)(1)(0!) = 4(3)(2)(1)(1) = 24
    
    
In order to reach a solution, a recursive function must have at least one case where it is able to produce the required result without calling itself. This is known as the _base case_. The other instances where the function calls itself are referred to as _recursive cases_. Each appli­cation of our function causes us to request the factorial of a smaller number (our recursive cases). Eventually we get down to 0, which doesn&#39;t require another application of the definition (our _base case_).

Recursive functions must meet the following:


1. There are one or more base cases for which no recursion is required.

2. All chains of recursion eventually end up at one of the base cases.


The easiest way to make sure that these conditions are met is to make each recursion to be on a smaller version of the original prob­lem. A very small version of the problem that can be solved without recursion then becomes the base case. So our recursive function would be:


    def factorial2(n): 
        if n == 0: 
            return 1 
        else: 
            return n * factorial2(n-1) 


Compare this with the solution we previously obtained:

![Alt text](img_factorial2.png?raw=false "Expressin factorial as a recursive structure")


The takeaway is that a recursive function is one that calls itself. The function first checks to see if we are at the base case (in the factorial case n == 0 and, if so ,returns 1) . If not, the function returns the result of multiplying _n_ by the factorial of _n-1_, which in turn is calculated by a recursive call to factorial2(n-1).


## Lesson 3: Handling Errors and Exceptions
Video: https://roehampton.cloud.panopto.eu/Panopto/Pages/Viewer.aspx?id=a9f46841-85f3-488f-aae9-ac7900c7ea9a


Right now, getting an error, or _exception_, in your Python program means the entire program will crash. You don&#39;t want this to happen in real-world programs. Instead, you want the program to detect errors, handle them, and then continue to run.

For example, consider the following program, which has a &quot;divide-by- zero&quot; error.


    def divideBy(x,y):
                 return x / y

    print(divideBy (4,2))
    print(divideBy (9,3))
    print(divideBy (5,0))
    print(divideBy (10,40))


A ZeroDivisionError happens whenever you try to divide a number by zero. Errors can be handled with **try** and **except** statements. The code that could potentially have an error is put in a try clause. The program execution moves to the start of an **except clause** if an error happens. We can put the previous divide-by-zero code in a try clause and have an except clause contain code to handle what happens when this error occurs.


    
    def divideBy (x,y):
        try:
            return x / y
        except ZeroDivisionError:
            print(“Error: Invalid argument”)

    print(divideBy (4,2))
    print(divideBy (9,3))
    print(divideBy (5,0))
    print(divideBy (10,40))



When code in a try clause causes an error, the program execution immediately moves to the code in the except clause. After running that code, the execution continues as normal:


Furthermore, any errors that occur in function calls in a **try** block will also be caught.


    def divideBy (x,y):
        return x / y

    try: 
        print(divideBy (4,2))
        print(divideBy (9,3))
        print(divideBy (5,0))
        print(divideBy (10,40))
    
    except ZeroDivisionError:
        print(“Error: Invalid argument”)



The reason print(divideBy (10,40)) is not executed is because once the error makes the program jump to the code in the **except** clause, it does not return to the **try** clause. It just continues moving down as normal, but the program doesn&#39;t break.


**Style tip** : It is good style to add **try** and **except** statements to all of your programs to detect whether the user types are correct. For instance, normally the int() function will raise a _ValueError_ error if it is passed a noninteger string, as in int(&#39;dinosaur&#39;). In the **except** clause, you can print a message to the user saying &quot;they must enter an integer&quot;.


FIN
