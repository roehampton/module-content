# Software Development 1 
# Lab 2 -- Basic syntax and semantics of a higher-level language 


In this lab, we’ll explore 
1. What are the syntax and semantics of a programming language?
2. Syntax of Phyton
3. Syntax & Semantics of Python

By the end of this lab, know what is the basic syntax and semantics of a higher-level language, you will have familiarized yourself with variables and have learned the difference between a straight line and a branching program. 


## Lesson 1: What are the syntax and semantics of a programming language?
Video: https://roehampton.cloud.panopto.eu/Panopto/Pages/Viewer.aspx?id=177f276a-4380-442e-bb28-ac4f008f8f9a


In this lesson we&#39;ll go in more depth through the syntax and semantics of a programming language. Specifically, we&#39;ll talk about processes and how we use them to deduce new kinds of information. To **write recipes or programs** , we need

1. some form of representation for **fundamental data** : **numbers (numeric things)**, **strings (textual information)** and **Booleans (logic**).
  With these we set the **value** of the data. Associated with each of these fundamental values there is a **type**. For numbers we have ints for integers and floats for fractional (floating-point) numbers, for strings we have str.

1. A way to give instructions to the computer to handle and manipulate that data (description of the recipe). We do this in the form of **Expressions.** We combine all of the fundamental data into &quot; **expressions**&quot; to make a set of instructions, or a &quot; **script**&quot;. Expressions are made up of **operands and operators**. An example of an expression is 2 \* 4.

Example:

A template for the print statement including the keyword parameter to specify the ending text looks like this: 

    print( <expr>, <expr>,  ..., <expr>, end = " \n " ) 

One common use of the end parameter in print statements is to allow multiple prints to build up a single line of output. 

Compare in your Jupyter notebook:

    print ("The meaning of life is") 
    print(40 + 2) 

and

    print ("The meaning of life is", end=" ") 
    print(40 + 2) 



We need to keep in mind that, for an expression to be accepted by Python, it has to be **syntactically** correct **(operand, operator, operand**), but we also we need to give it the kind of operand it expects ( **semantics** ).

We can do things like add 2 numbers, concatenate two strings, but not add one number and one string. Consider:

    2 + “ is my favourite number”

It does not work in python. To tackle this, we can convert one type to another:

    str (2) + “ is my favourite number”

Python does basic type checking, but we need to learn to be disciplined with our type usage.


### Exercise 1: Make a program that takes in your name and your age and displays:

    “Hi, my name is (Your Name), and I am (Your Age)” years old. 

We have a list of operators, the most common of which are mathematical ones such as addition (+), subtraction (−), multiplication (\*), division (/), and exponentiation (\*\*). However, what&#39;s the precedence of these operators? Do I do the addition first, or the multiplication? We can tell it by using parenthesis to do certain operations first. When in doubt, use parenthesis.

    ( )  >>  ** (exponentiation)  >>  * ,   /   >>    + , -



Example: Operators in Python can do more that just maths. For instance

**3 \* &quot;a&quot;** will give us the string &quot; **aaa**&quot;

We can take Strings and add them together or concatenate them.

What would happen inf we evaluate **3 + &quot;a&quot; ?** This is a **static sematic error**. They **syntax is ok** (operand, operator, operand), **but it doesn&#39;t make sense**. **Oh no!** What can we do? we can explicitly ask Python to convert it into a string with type conversion:

    str(3) + str(a)

It is good that python tells us that this is type checking error, but we must be careful here. If we make a mistake, python will carry the wrong results forward into all the other operations that we are doing, and it can be very hard to trace it down. It&#39;s good to make sure that we are checking out results. **Good style** will help us find these mistakes.

**Style Tip:** Exercise **Type discipline**. Check operators and the types of data that you are working with!

\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

**Syntax of Python**

When we get a value, we want to store them somewhere, and for this we have **variables**. We want to hang on to these values so we can refer to them in other places. We do this by naming the value we want to keep using an **assignment statement**. The basic assignment statement has this form:

    <variable> = <expr>
    
    
For instance,

**var\_1 = 20.0**

Take the float 2.0 and create a **binding** for that name (var\_1) to the value of the expression (20.0)

**var\_2 = 20**

Take the int 2 and create a **binding** for that name (var\_2) to the value of the expression (20)

In the case **var\_3 = 4 \* 5** we create a **binding** for (var\_3) to the valuation of the expression: the integer value 20.

Imagine that we have inside the machine **a virtual space that contains all possible values**. All the numbers, words and logic results there can be, including 2, 20 and even the name &quot;Arturo&quot;. When we create a set of variables (var\_1, var\_2, var\_3, ), we then create a list with the names that we want to use to hold our data. By assigning, we create a pointer, a link, from that name in our variable list to the value in our virtual space (which remember, contains all possible values).

![Alt text](img_variables.png?raw=false "Values in Memory are binded to by variables")

So if we do the following assignment:

**var\_4 = var\_1**

We read this as: **let var\_4 be bound to the value var\_1** , and through this, we create a pointer from the new var\_4, not to var\_1 itself, but to the value of var\_1.

Do **variables have a type**? Yes! **They inherit it from their value**. var\_1 is an int, var\_2 is a float and var\_3 is a string. What type is var\_4? In python, these types are **dynamic**. They change depending on what the current value it is bound to.

If somewhere later in the code, I do this:

var\_1 = &quot;Arturo&quot;

we&#39;ve changed they type of var\_1, which originally was a float, into a string. Remember that we had assigned var\_4 = var\_1. Does this change the value or type of var\_4? No! Because it&#39;s bound to a value in the virtual space of values. Check if the programming language you use supports dynamic variables.

This could create all sorts of bugs and complications, so to avoid this we need to develop some **good style**.

**Style Tip** : unless you really need it, avoid changing types!

Where can we use variables? Well, pretty much anywhere we can use the value! In technical terms: **Any place it is legal to use the value.**

### Lesson 2: Semantics of Python
Video: https://roehampton.cloud.panopto.eu/Panopto/Pages/Viewer.aspx?id=66611393-d3cf-4cd1-ba6f-ac4f008f8f43

We know that we can create an expression that allows us to calculate a value, or just get a value. We can then name and store these values in variables, but we really want to store them because we want to use them later, to manipulate them. For this we have **Statements** : **legal expressions (commands) that python can interpret**. We&#39;ve used a couple of **commands** like **print() , + , \* , and = (assignment).**

We&#39;ll get familiarized with more of these like how to get input from the user, how to transform it, how to save and retrieve it, etc.

A big part of the structure of programs are **comments.** The **# sign or &quot;Hash&quot; identifies a comment** , telling you what&#39;s going on inside of the code. What&#39;s the **intuition** behind it, maybe explain any **pre-conditions** that are needed: does the program only take certain kinds of number, do we need to have done something before it? You need to have those comments there. They are part of **good style**.

**Style tip** : Comment your program in such a way that anyone can read it and know what it is you are trying to do. After a few weeks, come back to your code. Can you understand what you were trying to do? It&#39;s a sign of good style if you can!

**A good choice of variable name** is actually a great way to help commenting your code: **use variable names that make sense**. What are you trying to capture in this variable?

Example: Let's try to capture data from the user and store it in variables that make sense.
    # Read the names from the user 
    first = input("Enter the first name: ")
    last = input("Enter the last name: ") 
    
    # Concatenate the strings 
    both = last + ", " + first 

    # Display the result 
    print(both) 




There are a few things we can&#39;t use for variable names:

**Python 2 has 30 keywords. Python 3 has 33.**

\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

Let's try the following in Python:

    import keyword
    keyword.kwlist

\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

**True** for instance is one of these keywords, so we can&#39;t use it to store data in it. It is protected, blocked out.


Example: Remember the len function from last lesson? Let's use it by computing the length of a person&#39;s name.

    # Read the name from the user 
    first = input("Enter your first name: ") 
    
    # Compute its length 
    num_chars = len(first) 
    
    # Display the result 
    print("Your first name contains", num_chars, "characters") 


### Exercise 2: Sort 3 integers values entered by the user into increasing order.

    # Read the numbers from the user, naming them a, b and c 
    a = int(input("Enter the first number: ")) 
    b = int(input("Enter the second number: ")) 
    c = int(input("Enter the third number: ")) 


Since min and max are the names of functions in Python we should not use those names for variables. Instead, we use variables named **mn** and **mx** to hold the minimum and maximum values respectively. 

    # the minimum value
    mn = min(a, b, c)
    
    # the maximum value
    mx = max(a, b, c)
    
    # the middle value 
    md = a + b + c - mn - mx 
    
    
    # Display the result 
    print("The numbers in sorted order are:")
    print(" ", mn)
    print(" ", md)
    print(" ", mx)



## Lesson 3: Syntax & Semantics of Python

Video: https://roehampton.cloud.panopto.eu/Panopto/Pages/Viewer.aspx?id=409562a6-a401-43ee-9623-ac4f008f8f52


Now we know we can write expressions, perform operations, get out values and store them away. However, so far we have only worked with &quot; **straight Line programs**&quot;: programs which executes the sequence of instructions one by one.

Going back to our recipe analogy, some of the instruction may say &quot;add a pinch of salt, if needed&quot;. This is a **conditional** : a decision needs to be made at this point. Does it need more salt, or doesn&#39;t it? If the **conditional is true** , then we add more salt. Otherwise, we do something different. We branch out. We call these **Branching programs**

**Branching programs- change the order of instructions based on some test** (usually a value of a variable).

We **use == to compare values**

Is this thing equal to in value to this other thing?

\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

### Exercise 3: Compare a string with a number? Does this work?

\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

Example: Identify wheter a user-given number is 0 or not using *if* statements.

    # Read a number from the user
    num = float(input("Enter a number: "))

    # Store the appropriate message in result
      if num == 0:
    result = "The number was zero" ;
    if num != 0:
      result = "The number was not zero" ;

    # Display the message
    print(result)
    
 Let's try that again, but this time using *else* conditional   


    # Read a number from the user
    num = float(input("Enter a number: ";))

    # Store the appropriate message in result
    if num == 0:
      result = "The number was zero" ;
    else:
      result = "The number was not zero" ;

    # Display the message
    print(result)
\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

These are key to understand the syntax and the flow of control inside of a program. There&#39;s a particular format to them:

    if <some test> :
      instruction a
      instruction b
      instruction c
    else :
      instruction d
      instruction e
      instruction f


Colon is important. It defines the beginning of a block of instructions. The carriage return identifies the end. &quot; **if&quot;** indicates I&#39;ve got an expression. If it is **true** , I&#39;m going to evaluate whatever is following the colon and is indented. If it is **false** , I&#39;m going to skip it. We can use a second keyword, &quot; **else&quot;** , to specify what to do if it is false.

If this thing has some particular value, then do one thing. Otherwise, do something different. Let&#39;s explore its syntax.

\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

Example: Let's write a piece of code that identifies whether a number is even or odd. Tip: we need it to get an input and identify and print out whether it is even or odd.

    # Initialize our variable
    x = 3

    # our branching program
    if (x/2)*2 == x
      print ("even");
    else: print ("odd");
    
\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_

### Exercise 4: Classifying Triangles 
A triangle can be classified based on the lengths of its sides as equilateral, isosceles or scalene. All three sides of an equilateral triangle have the same length. An isosceles triangle has two sides that are the same length, and a third side that is a different 
length. If all of the sides have different lengths, then the triangle is scalene.
Write a program that reads the lengths of the three sides of a triangle from the 
user. Then display a message that states the triangle’s type. 

\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_\_


We’ll continue this journey in the next Lesson! Happy coding!

FIN
