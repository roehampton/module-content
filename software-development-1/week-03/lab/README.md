# Software Development 1
# Lab 3 -- Common code patterns

In this lab, we’ll explore:
1. Iterative Programs : While
2. Debugging
3. Iterative Programs : For

By the end of this lab you will know how to abstract problem data into a computational set of instructions, and you will have familiarized yourself with some common structures: While and For Loops as well as basic debugging.

## Lesson 1 : Iterative Programs : While

Video: https://roehampton.cloud.panopto.eu/Panopto/Pages/Viewer.aspx?id=17e105b1-4f19-415f-9f97-ac5601034022


Our goal here is to build recipes: Take problems and break them down into a sequence of steps: computational instructions that allow us to capture that process.

We&#39;ve discussed primitives (words), but now we need to capture the ideas of the problems in a language that the computer understands (Python). We&#39;ve separated Syntax (what are the legal expressions in this language) vs Semantics (static semantics asks: &quot;which programs are meaningful?&quot;; full semantics ask: &quot;what&#39;s going to happen when I run it?&quot;). You will familiarize yourself with both as you keep programming. Python will tell you if your syntax is wrong (there&#39;s no excuse for hand in in coursework with bad syntax). However, Python won&#39;t give you much help in Semantics. To tackle this, you need to develop Good Style to catch these bugs.

You will use the primitives we&#39;ve learned and combine them into expressions, which we can then use as a sequence of instructions in a **flow of control** to deduce new information. We have discussed **data** (numbers, string, Boolean), **operations** (+, \*, for numbers/strings and, or for booleans) and **commands** (assignments, input/output, conditionals, loop mechanisms). This is really all we basically need to start creating our sets of instructions. We will learn how to put them together to build common patterns of code to tackle certain kinds of regular problems.

Let&#39;s talk about our first general recipe: **Iterative programs:** programs that loop. In these programs there is a **Variable that counts** (it could be increasing a number one by one, sound familiar?). To create this, we need to **initialize the variable outside of the loop** and define when the loops should end through a **setup and test involving the counting variable** (the thing that&#39;s changing). We need to make sure to **change the variable inside of the loop** , and finally **what to do when we are done.** This kind of program is a thing of beauty and can save you so much time and effort but applied recklessly it can lead you to loop infinitely.

Then we&#39;re going to construct the block of code:

Let&#39;s use the idea of needing salt in a recipe: _If necessary, add salt_.

Let&#39;s identify here the variable inside the loop, the one that will keep changing and will tell us when to end: _the level of saltiness_. Our loop would look something like:

    while (needs more salt)
      Add salt
      Does it need more salt?

Example: Type this simple loop that prints the numbers from 1 to 5 in your Jupyter notebook:

    count = 1
    while count <= 5: 
      print(count)
      count += 1 


To write these kinds of recipe structures, we use a visualization tool called a flow chart:

![Alt text](flowchart.png?raw=false "Flowchart Example")

Start is represented by a rounded rectangle, variables are in a square box, tests are in a diamond, print in trapezoid and ends with a box that says stop

Flowcharts leet us see where the loop is along with all the components and help make sure it&#39;s contained and doesn&#39;t spiral out of control, eating all the resources, overheating your computer, beating children and kicking puppies (in the right hardware embodiment this is a possibility. Final Project?)

For simple branching programs, like the ones we in the last session, the time it takes to run (complexity of the program) is finite, bounded by the number of instructions you have. But looping programs have a complexity that depends on the test that we are making: how many times am I cycling to get to the answer? If I put in a loop inside the loop, then the complexity starts increasing non-linearly. In your career, you&#39;ll find that there are classes of computation that inherently much more complex, but in the meantime, the takeaway here is that you have all you need to start writing your own recipes. But like Shakespeare learning words and sentences, we&#39;ll have to practice a lot to be able to write code functionally and beautifully.


## Lesson 2 : Debugging the Code

Video: https://roehampton.cloud.panopto.eu/Panopto/Pages/Viewer.aspx?id=85bce52d-614c-4056-b3bd-ac5601033fb7

We have discussed that Python will tell you if your syntax is wrong (there&#39;s no excuse for hand in in coursework with bad syntax). However, Python won&#39;t give you much help in Semantics. To tackle this, you need to develop **Good Style** to catch these bugs. One of the best way to catch these bugs is to &quot;simulate&quot; the code: pick a set of values that will give you a rough idea of what you&#39;ll get, and walk through the code with them. This will be helpful specially in making sure that we won&#39;t loop forever. Some programmers prefer to put print statements at various places.

For instance, for salt example, let&#39;s say that my taste in salt is 10 spoons of salt.

    salt_taste = 10
    # we set the variable that will count up to a desired value
    salt= 0 
    while salt < salt_taste :
    	print(“add another spoon of salt”)
    	salt= salt+1


What&#39;s the problem here? It stops at 9. It doesn&#39;t stop at the right place! If you don&#39;t do the test, you are going to get wrong answers, or worse, loop forever, spiralling out of control, eating all the resources, overheating your computer, beating children and kicking puppies.

I could have used prints as well to spot the error, for instance:

    salt_taste = 10
    salt= 0
    while salt < salt_taste :
    	print(salt); # Our debugging printout
    	print(“add another spoon of salt”)
    	salt= salt+1


. Including this extra print at the start of the loops allows me to see how many times the loop has ran. It would show I&#39;ve only done this 9 times, so I can spot the error and correct it:

    salt_taste = 10
    salt= 0
    while salt <= salt_taste : # Corrected test
    	print(“add another spoon of salt”)
    	salt= salt+1


The idea is that simulation it on simple examples letch you check, especially:

1. **For what values of our iterating variable does this code terminate**
2. **Does it give the right answer?**

What about negative number, for instance? What if I, as a user of this algorithm, actually like my food with less of a salty taste? What if I really want to take the food and run a napkin on top to take the salt out?

**Does this code ever terminate? Yes**! It stops at the first iteration!

**Does it give me the right answer? No**. It still has too much salt! We need to modify the code, perhaps adding an if case inside of the loop.

There is a version of debugging called &quot;Defensive Programming&quot;, where you test every single path of the code. This is probably the best if it&#39;s a life or death scenario for your code, but we&#39;ll come back to it.

The takeaway is that, to debug, you really need to make sure of two things: **Does this code ever terminate?** **Does it give me the right answer?** If you got those two, you&#39;ve debugged your program.



## Lesson 3: Common code patterns: For
Video: https://roehampton.cloud.panopto.eu/Panopto/Pages/Viewer.aspx?id=68dbbff2-8db5-43e1-af86-ac5601033fd9

Imagine you have a collection of numbers, and you want to go through every single one of these numbers. If you want to go through each element of data at a time, luckily there is a very useful construct to help us called the &quot;for&quot; loop.

Exercise: It&#39;s legal Python to step through a sequence like this:
        
    rabbits = ['Flopsy', 'Mopsy', 'Cottontail', 'Peter'] 
    current = 0
    while current < len(rabbits):
         print(rabbits[current]) 
         current += 1


But a better, more **Pythonic** way is:

    for rabbit in rabbits: 
      print(rabbit)


The basic form of this loop is:

    For <variable> in <some collection>
       |block of code


The difference between the for loop and the while loop is that we don&#39;t need to keep track of an iterating variable: the loop is bounded by the number of elements you have in your collection. For instance, if I absolutely know that my recipe will be needing 10 spoons full of salt, I can enumerate them as
    salt_taste = 10
    for 1 in range(1, salt_taste): 
    	print (“add more salt”)


Tip: **range** is a built-in python function that generates all the integers from 1 up to, but not including, the variable you put in. The basic format is _range( start, stop, step )_. If you omit _start_, the range begins at 0. The only required value is _stop_. The last value created will be just before _stop_. The default value of _step_ is 1, but you can go backward with -1.

Example: Let&#39;s make the range 0, 1, 2:

    for x in range(0,3): 
      print(x)

Example: Let&#39;s make a list of numbers with range():
    
    list( range(0, 3) )

Example: to make a range from 2 down to 0:
   
    for x in range(2, -1, -1): 
       print(x)


Example: String iteration produces a character at a time :
     
     word = 'cat'
     for letter in word:
        print(letter) 



**Create a list with [] or list()**

A list is made from zero or more elements, separated by commas, and surrounded by square brackets:

    empty_list = [ ]
    weekdays = ['Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday']
    big_birds = ['emu', 'ostrich', 'cassowary']
    first_names = ['Graham', 'John', 'Terry', 'Terry', 'Michael']


You can also make an empty list with the list() function:

    another_empty_list = list()
    another_empty_list
    [ ]


Python&#39;s list() function converts other data types to lists. The following example converts a string to a list of one-character strings:
    
    list('cat')

Lists can contain elements of different types, including other lists, as illustrated here:

    small_birds = ['hummingbird', 'finch']
    extinct_birds = ['dodo', 'passenger pigeon', 'Norwegian Blue']
    carol_birds = [3, 'French hens', 2, 'turtledoves']
    all_birds = [small_birds, extinct_birds, 'macaw', carol_birds]


The list collecting here could be anything, really. We&#39;ll see more examples of these kinds of collections in the future but it&#39;s important to know about a special collection called a tuple. Tuples are ordered sequence of elements which are immutable (we can&#39;t change it). For instance, the number of spoons of salt that I like in my recipes could be a tuple collection:

    salt_spoons_list = [ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10] is a type list

    salt_spoons_tuple = ( 1, 2, 3, 4, 5, 6, 7, 8, 9, 10) is a type tuple


Positions in lists start being enumerated as zero (this is because it is an index). I can access each of the elements in my collection by asking for the position of each element such as the zeroeth element on the list:

    salt_spoons_list [0] 
     1
    
    salt_spoons_tuple [4] 
    5


List has **mutable** nature i.e., list can be changed or modified after its creation according to needs whereas tuple has **immutable** nature i.e., tuple can&#39;t be changed or modified after its creation. Lists has **variable length,** tuple has **fixed length**. Using a tuple instead of a list can give the programmer and the interpreter a hint that the data should not be changed.

    salt_spoons_list [0] = 4

    salt_spoons_list 
    [ 4, 2, 3, 4, 5, 6, 7, 8, 9, 10]

    salt_spoons_tuple[4] = 8
    Error

    salt_spoons_tuple
    [ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]


Example:

    for 1 in salt_spoons_list: 
      print (“add more salt”)


Exercise: Transform the list we have crated to Tuples by Using ( ) instead of []. Be sure to check their type.

    empty_tuple = ( )
    weekdays_tuple = ('Monday', 'Tuesday', 'Wednesday', 'Thursday', 'Friday')
    big_birds_tuple = ('emu', 'ostrich', 'cassowary')
    first_names_tuple = ('Graham', 'John', 'Terry', 'Terry', 'Michael')


 We&#39;ll explore more of the functionality of list and tuples in the next lessons.

Now you know how to abstract problem data into a computational set of instructions, and you have familiarized yourself with some common structures: While and For Loop.

Happy Coding!
