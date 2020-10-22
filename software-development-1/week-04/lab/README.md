# Software Development 1 
# Lab 4 -- Decomposition and abstraction


In this lab, we’ll explore 
1. Introduction to Functions
2. Function Creation
3. Syntax & Semantics of Functions

By the end of this lab, you will

## Lesson 1: Introduction to functions
Video:

We&#39;ve learned the basics data structures and loops, which are the basic forms of recipes.

By now we should know that our programming language, Python, has:

    data (computational representations of things)

    assignments (the ability to give names to values and save them)

    conditionals (make judgements and decisions if, elif, else)

    input/output (print, input to communicate with the outside world)

    Loop structures (the basic recipes while, for)



What can we compute with these? Basically anything!

Python is a Turing-complete language. This means that with those set of constructs, anything you can describe algorithmically you can compute.

Does this mean we&#39;re done? Well no. You&#39;ve learned the basic building blocks of our recipes. The fundamentals of computation are captured in that set of mechanisms. But the real issue is how to develop computational thinking: How do we build programs with these blocks that allow us to tackle particular problems? With these sets of constructs, it is actually not that easy to write a program. You can do it, but it will cost you a lot of effort.

There are more things we should know to let us problem-solve well. You could technically use a blunt knife to do a screwdriver&#39;s job; but wat you&#39;ll be valued for as a programmer is knowing which screwdriver to use and where. The more tools you have in your toolbelt, the more precision you&#39;ll have, the better job you&#39;ll do.

For instance, if you are asked to make a program that calculates AM or PM from a 24-hour clock, you would have to do something like:

input(time)

    if time > 12 :
    	 time_pm = time-12
    	 print( time_pm, “ PM”)
    else : 
       print (time, “AM”)


However, if you know there is a built-in mathematical operation that can do this for you, like modulus. The modulo (or &quot;modulus&quot; or &quot;mod&quot;) is the remainder after dividing one number by another.

    
    Example: 100 mod 9 equals 1

    Because 100/9 = 11 with a remainder of 1

    Another example: 14 mod 12 equals 2

    Because 14/12 = 1 with a remainder of 2
    

It is like we aren&#39;t interested in how many times we go around, just where we end up.

Python has this built in as one of its core mathematical operations as % (percent sign)

So

    14 % 2 = 2

Our normal 12-hour time uses modulo 12 (14 o&#39;clock becomes 2 o&#39;clock), so knowing that it&#39;s there could save you a lot of trouble!

But how about the things that are not &quot;built into&quot; Python?

For instance, **logarithm**  is the inverse function to exponentiation. That means the logarithm of a given number x is the exponent to which another fixed number, the base b, must be raised, to produce that number x. **Logarithm** is defined as the exponent or power to which a base must be raised to yield a given number. A useful approximation for the logarithm is:
![Alt text](img_logarithm.png?raw=false "Approximation of Logarithm")

if I want to know the logarithm of 0.5, I can approximate it with:



    x=0.5

    n=10000

    my_ln= n * ((x ** (1/n)) - 1)

    my_ln
    

Compare this with importing a function that gives you access to a program someone else has made:


    import math

    math.log(0.5)
    

If we wanted to write this program and re-use it somewhere else in the code, I&#39;d have to write it again as many times I need it. Or, I could transform it into a function. I can write it once, give it a name and then use it a s many times I want:
    
    def my_ln(x):
    n = 10000.0 
    return n * ((x ** (1/n)) - 1)


## Lesson 2: Functions
Video:

If I wanted to write a program, we write this in one file. We start at the beginning, walk through all the way to the end. For the early coursework, it&#39;s not a bid deal. 10-20 lines of code is perfectly tractable. Professionally, however, code is usually hundreds or thousands of lines of code. It&#39;s really hard to keep track of things!

For this, **decomposing** and **abstracting** the problem can help put structure to even programs with millions of lines of code. We want to **decompose** , or break the code, into self-contained modules: modules that makes sense on their own. Like splitting a TV series into stand-alone episodes that make sense even if you haven&#39;t seen the entire thing. **Abstraction** is more about downplaying details, shifting focus to the bigger picture without worrying about the specifics of something. Think of it as a &quot;black box&quot; where you put something in, it does something specific to it and you get an answer out. This is called a &quot;contract&quot; which is just a fancy word for &quot;if you put the right kind of inputs in, you&#39;ll get the right output out&quot;. The key here is that you don&#39;t have to know what&#39;s happening inside of that box.

Both **decomposing** and **abstracting** are really important. The idea is that, by isolating key components of the process, we create these modules that we can reuse in multiple places. We just call them in, and if we give them the right value, because of this &quot;contract&quot;, we&#39;ll get the right calculation out. Like our function for the logarithm. It was created, then we can just call it in and not worry about what code is inside. It&#39;s separated from our code.

Functions are going to provide both of these things. Remember when we talked about Alan Turing and the primitives? And how people have been using them to build higher primitives? Well you can do it too!

We can capture a pattern of computation, like the logarithm, in a piece of code, and then refer to it by a name. If we did our job right, then all we need to do is give it the right arguments, the correct input, and it will give us the right answer. We don&#39;t have to worry about what&#39;s inside anymore. We trust that it satisfies our &quot;contract&quot;. And with that, we get to name a new higher primitive. A word we can call in to execute this piece of code for us.

People have devoted quite a considerable amount of time to create such primitives, and the way you can access them is by importing **libraries**. For instance, for the kind of simple maths like modulus, the function is built into Python as a primitive: a **%** b. However, programs for fancier mathematics like log, sine and tan can be easily accessed by asking at the start of the program to import the library that contains them. We could import the function one by one:

Remember, I used the following calculations to get the logarithm:


    x=0.5
    n=10000
    my_ln= n * ((x ** (1/n)) - 1)
    my_ln



but if we know the right words to communicate with python we could ask politely for python to give us a program that someone else wrote:

    from math import log10
    a = 10
    log(a)

or simply import the whole library

    import math
    a = 10
    math.log(a)

Takeaway: If we rely on the fact or &quot;contract&quot; that we wrote the code well and that we trust it to give us the right answer then all we need to worry about is giving it the right input.


## Lesson 3: Specification
Video: 

We need a contract that need a contract that says, here&#39;s what I want in terms of things that you&#39;re going to take as input, here&#39;s what you&#39;re going to produce at the

output, and the details of what they do inside are up to them.

We need to be precise describing the syntax and the semantics of what we are doing. We start creating out function by using the python keyword **def** , which means define, immediately followed by the name you want to use to define that function


     def function_name ( variable_name ) :
    	| instruction_a
    	| instruction_b
    	| instruction_c
    	retrun (variable_name)


Notice that we have parenthesis with a variable inside it. This is how we&#39;ll define the formal parameters of the function (what&#39;s coming in). Some functions will have nothing coming into them, so the parentheses can be empty then. You then perform a computation with that variable and then **return** a value at the end. Try, for instance:


    def increase (x) :
    	"""this program increases a number by one"""
    	x = x+1
    	return x

    increase (1)


**Style tip** : The double quotes in a row inside functions are like comments. They tell us what the function is supposed to do and how to use it correctly. These are known as specifications. You should always specify your functions!

Sometimes there is nothing to return, so you return the special value **None**. This special value is actually quite useful when we are doing comparisons in our functions.

**Style tip:** End every possible path in your **if** branches with a **return**. If the program doesn&#39;t return anything (not even a **None** value) then it means you are not going into the branches and you&#39;ve got a bug in your logic.

When we invoke functions, they bind the variable inside the parenthesis with whatever value you put in there; but this binding is local. It only holds while the function you invoked is running. Almost like it is running this little program in a completely different environment to the main program. So, whatever happens inside the function, stays inside the function, except for the **return** value. If you want to keep that return value, you then have to bind it to another variable else outside the function.

A variable **x** inside our function _increase_ can only be seen by whatever is happening in that local environment. We can do all sorts of local bindings inside the local environment, and the only thing that will come out is whatever I tell it to return. We can then save that value as a new variable or bind it to a previous variable, but everything that happened inside of the function will be ignored and not affect the global program.

Takeaway: instead of copying and pasting code over and over again, we can re-use it by writing it as a function and invoking it thought our program by its name.

a more general logarithm program, for any base b including clock (base 12) or binary (base 2) can be written as:


    def log(x, base):
    log_b = 2
    while x != int(round(base ** log_b)):
        log_b += 0.01
        print log_b
        return int(round(log_b))


compare the results against the the built-in log function. Which one is better?
