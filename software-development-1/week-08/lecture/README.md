# Software Development 1 
# Lecture 8 -– Functions in Python

In this lab we will explore:

1. How to pass parameters and arguments
2. Use Python's dictironary file type
3. Understand the scope of Local and Global variables


First, let's do a functions recap:

A _function_ is like a mini-program within a program.

We have seen that the basic structure of a function is:


    def function_name ( variable_name ) :
        | instruction_a
        | instruction_b
        | instruction_c
        retrun (variable_name)



The first line is a def statement, which defines a function with a name. The code in the block that follows the def statement is executed only when the function is called (not when the function is first defined).

To use or &quot; **call**&quot; a function, we use its name followed by parentheses (function calls). If the function needs an _input_ we need to give these as **arguments** in between the parentheses. When the main program being executed reaches these **function calls** , it will jump to the top line in the function and begin executing the code there. When it reaches the end of the function, the execution returns to the line that called the function and continues moving through the code. This code jumping can be confusing at first, but it will let you re-use pieces of code that you have written and make the flow of your program more intuitive. Actually, when writing software from scratch, you&#39;ll often find that it&#39;s easy at first to just duplicate your code. However, you always want to avoid duplicating code because, if the code ever needs updating or if you find a bug you need to fix, you&#39;ll have to remember to change the code everywhere you copied it.

_**Style Tip**: Deduplicating your_ code (getting rid of duplicated or copy-and- pasted code) is a key practice of good programming. The aim is to always make your programs shorter, easier to read, and easier to update. 


## Lesson 1: Passing parameters and arguments
Video: https://roehampton.cloud.panopto.eu/Panopto/Pages/Viewer.aspx?id=dbffa9e7-2099-4e59-a64e-ac710143375b

Knowing when to encapsulate code that gets executed multiple times into functions is a skill that you will learn with practice. We can pass arguments (values that the function needs) by typing them in the parenthesis when calling a function. To store the kinds of values we need, when defining our functions, we define a **parameter** in which an argument is stored as a variable. Remember that any symbolic name used for a memory space is a **variable**. Any variable that is passed to a function call, is called a **parameter**. Consider the following program:


    def hello(name):
        print(“Hello “ + name)

    hello(“Arturo”) 
    hello(“Kevin”)


The first time the _hello()_ function is called, it&#39;s with the argument &quot;Arturo&quot;. The program execution enters the function, and the parameter _name_ is automatically set to &quot;Arturo&quot;, which is what gets printed by the _print()_ statement. However, the _name_ parameter is a **local**. The value stored in a parameter, like any other values stored in variables inside a function, is forgotten when the function returns. For example, try adding:


    print(name)


The program gives us a _NameError_ because there is no variable named name.

Most arguments are identified by their position in the function call. For example, random.randint(1, 10) is different from random.randint(10, 1). The function call random.randint(1, 10) will return a random integer between 1 and 10, because the first argument is the low end of the range and the second argument is the high end (while random.randint(10, 1) causes an error).

_keyword arguments_ are identified by the keyword put before them in the function call. Keyword arguments are often used for optional parameters. For example, the _print()_ function has the optional parameters _**end**_ and _**sep**_ to specify what should be printed at the end of its arguments and between its arguments (separating them), respectively.

Compare:

    print(“Hello”) 
    print(“World”) 


and


    print(“Hello”, end=““) 
    print(“World”) 


The output is printed on a single line because there is no longer a new line printed after &quot;Hello&quot;. Instead, the blank string is printed. This is useful if you need to disable the newline that gets added to the end of every _print()_ function call. Similarly, when you pass multiple string values to _print()_, the function will automatically separate them with a single space. Try the following:

    print(“cats”, “dogs”, “mice”) 



But you could replace the default separating string by passing the **sep** _keyword_ argument:


    print(“cats”, “dogs”, “mice”, sep=“ ,”) 



You can add _keyword arguments to the functions_ you write as well, but first you&#39;ll have to learn about dictionary, which we&#39;ll tackle in the next section.



## Lesson 2: Dictionaries
Video: https://roehampton.cloud.panopto.eu/Panopto/Pages/Viewer.aspx?id=6522ce00-69f3-43ab-8214-ac7101433704


The **dictionary data type** provides a flexible way to access and organize data. In code, a dictionary is typed with braces, **{}**. Like a list, a _dictionary_ is a collection of many values. But unlike indexes for lists, indexes for dictionaries can use many different data types (not just integers like lists). Indexes for dictionaries are called _keys_, and a key with its associated value is called a _key-value pair_.

Dictionary example:


    myDinosaur = {“size”: “large”, “colour”: “gray”, “disposition”: “loud”} 
    
    
This assigns a dictionary to the myDinosaur variable. This dictionary&#39;s keys are &quot;size&quot;, &quot;colour&quot;, and &quot;disposition&quot;. The values for these keys are &quot;fat&quot;, &quot;gray&quot;, and &quot;loud&quot;, respectively. You can access these values through their keys:


    myDinosaur[“size”]
    “My dinosaur has “ + myDinosaur[“colour”] + “ skin.” 




Unlike lists, items in dictionaries are unordered. The first item in a list named test would be test[0]. But there is no &quot;first&quot; item in a dictionary. It does not matter in what order the key-value pairs are entered in a dictionary.

Exercise: compare the following dictionaries:


    test = [“cats”, “dogs”, “mice”] 
    bacon = [“dogs”, “micee”, “cats”] 
    test == bacon



    eggs = {“name”: Zara, “species”: “cat”, “age”: “8”} 
    ham = {“species”: “cat”, “age”: “8”, “name”: "Zara"} 
    eggs == ham



However, they can&#39;t be manipulated as easily as lists. For instance, trying to access a key that does not exist in a dictionary will result in a _KeyError_ error message (like a list&#39;s &quot;out-of-range&quot; _IndexError_ error message).


    birthdays = {“Rachel”: “Apr 18”, “Charles”: “Dec 2”, “Anakin”: “May 4”} 
    while True:
        print(“Enter a name: (blank to quit)”) 
        name = input()
        if name == ““: 
           break 
    
        if name in birthdays:
            print(birthdays[name] + “ is the birthday of “ + name) 
        else:
                print(“I do not have birthday information for “ + name) 
                print(“What is their birthday?”)
                bday = input()
                birthdays[name] = bday
                print(“Birthday database updated.”) 

    

You create an initial dictionary and store it in birthday. You can see if the entered name exists as a key in the dictionary with the in keyword, just as you did for lists. If the name is in the dictionary, you access the associated value using square brackets; if not, you can add it using the same square bracket syntax combined with the assignment operator.

There are three dictionary methods that will return list-like values of the dictionary&#39;s keys, values, or both keys and values: keys(), values(), and items(). The values returned by these methods are not true lists: They cannot be modified and do not have an append() method. But these data types


    dict_keys
    dict_values
    dict_items 




can be used in for loops.


    test = {“colour”: “red”, “age”: 42}
    for j in test.values():
        print(j)

    for k in test.keys():
        print(k)

    for l in test.items():
        print(l)




The values in the _dict\_items_ value returned by the _items()_ method are tuples of the key and value. If you want a true list from one of these methods, pass its list-like return value to the _list()_ function.


    test = {“colour”: “red”, “age”: 42} 

    test.keys()

    list(test.keys())




You can also use these operators to see whether a certain key or value exists in a dictionary


    test = {“name”: “Leah”, “age”: 7} 
    “name” in test.keys()

    “Leah“ in test.values()

    “colour” in test.keys() 

    “colour” not in test.keys() 

    “colour” in test




There are a couple of kye methods we need to get familiar with. The _**get()**_ methodtakes two arguments: the key of the value to retrieve and a fallback value to return if that key does not exist.

Example:


    picnicItems = {“apples”: 5, “cups”: 2}
    “I am bringing “ + str(picnicItems[“eggs”]) + “ eggs.” 



Which produces an error vs


    picnicItems = {“apples”: 5, “cups”: 2}
    “I am bringing “ + str(picnicItems.get(“eggs”)) + “ eggs.”




Because there is no &quot;eggs&quot; key in the _picnicItems_ dictionary, the default value 0 is returned by the get() method. To set a value in a dictionary for a certain key only if that key does not already have a value, we can use the _**setdefault() Method.**_ The first argument passed to the method is the key to check for, and the second argument is the value to set at that key if the key does not exist. If the key does exist, the _setdefault()_ method returns the key&#39;s value.


    test = {“name”: “Godzilla”, “age”: 5} 
    test.setdefault(“colour”, “black”) 
    test



    test.setdefault(“colour”, “white”)
    test



The first time _setdefault()_ is called, the dictionary in test changes to {&quot;colour&quot;: &quot;black&quot;, &quot;age&quot;: 5, &quot;name&quot;: &quot;Godzilla&quot;}. The method returns the value &quot;black&quot; because this is now the value set for the key &quot;colour&quot;. When _test.setdefault(&quot;colour&quot;, &quot;white&quot;)_ is called next, the value for that key is not changed to &quot;white&quot; because test already has a key named &quot;colour&quot;.

Takeaway: Dictionaries are useful because you can map one item (the key) to another (the value), as opposed to lists, which simply contain a series of values in order. Values inside a dictionary are accessed using square brackets just as with lists. Instead of an integer index, dictionaries can have keys of a variety of data types: integers, floats, strings, or tuples



## Lesson 3: Local and Global variables

Video: https://roehampton.cloud.panopto.eu/Panopto/Pages/Viewer.aspx?id=e8cc33d8-49cd-49ff-9f6f-ac7101433732

Parameters and variables that are assigned in a called function are said
 to exist in that function&#39;s _**local scope**_. Variables that are assigned outside all functions are said to exist in the _**global scope**_. A variable that exists in a local scope is called **a** _**local variable**_, while a variable that exists in the global scope is called a _**global variable**_. A variable must be one or the other; it cannot be both local and global.

Think of a **scope** as a container for variables. When a scope is destroyed, all the values stored in the scope&#39;s variables are forgotten. There is only one global scope, and it is created when your program begins. When your program terminates, the global scope is destroyed, and all its variables are forgotten. Otherwise, the next time you ran your program, the variables would remember their values from the last time you ran it.

A local scope is created whenever a function is called. Any variables assigned in this function exist within the local scope. When the function returns, the local scope is destroyed, and these variables are forgotten. The next time you call this function, the local variables will not remember the values stored in them from the last time the function was called.


![Alt text](img_scopes.png?raw=false "Local and Global scopes and variables")


Key things to remember:

- Code in the global scope cannot use any local variables.
- However, a local scope can access global variables.
- Code in a function&#39;s local scope cannot use variables in any other local scope.
- You can use the same name for different variables if they are in different scopes. That is, there can be a local variable named var\_1 and a global variable also named var\_1.

There are many reasons why Python has different scopes. One of the most important one, shared by multiple programming languages is to narrow down the list code lines that may be causing a bug.

If we only had global variables, when variables are modified by the code in a particular call to a function, they might change in ways that we don&#39;t necessarily want. The bug search space can be enormous in programs with millions of lines of code. However, if the function interacts with the rest of the program only through its parameters and the return value, then this narrows down where the bug can be. Local variables make bad values easier to spot because you are easily able to trace the function that could have set that value incorrectly.

**Style tip** : Using global variables in small programs is ok, but it is a bad habit to rely on them as your programs get larger and larger. Use a combination of both and keep your programs compartmentalized and your functions reusable.

Multiple local scopes are the norm in Python programs. Consider:


    def breakfast():  
        eggs = 99 
        lunch() 
        print(eggs) 

    def lunch(): 
        ham = 101 
        eggs = 0 
        print(eggs)

    breakfast() 




When the program starts, the _breakfast ()_ function is called, and a local scope is created. The local variable eggs is set to 99. Then the _lunch()_ function is called, and a second local scope is created. Multiple local scopes can exist at the same time. In this new local scope, the local variable ham is set to 101, and a local variable _eggs_, which is different from the one in _breakfast ()_&#39;s local scope, is also created and set to 0.

When _lunch()_ returns, the local scope for that call is destroyed. The program execution continues in the _breakfast()_ function to print the value of eggs , and since the local scope for the call to _breakfast()_ still exists here, **the eggs variable is set to 99**. This is what the program prints.

Takeaway: local variables in one function are completely separate from the local variables in another function.

Exercise: Identify the global and local variables


    def snack(): 
        eggs = “eggs local 1”
        print(eggs) 

    def dinner(): 
        eggs = “bacon local 2” 
        print(eggs)
        snack()
        print(eggs)

    eggs = “eggs global” 
    dinner()
    print(eggs) 





**Style Tip** : While technically, it&#39;s legal to do so in Python, avoid using local variables that have the same name as a global variable or another local variable.

If you need to **modify a global variable** from within a function, use the **global statement**.


    def munchies(): 
        global eggs
        eggs = “eggs locally sourced”
    eggs = “eggs from around the world” 
    munchies ()
    print(eggs) 





If you try to use a local variable in a function before you assign a value to it, as in the following program, Python will give you an error:


    def munchies(): 
        print(eggs)
        eggs = “eggs locally sourced”
    eggs = “eggs from around the world” 
    munchies ()




The takeaway lesson is that functions are the primary way to compartmentalize your code into logical groups. Since the variables in functions exist in their own local scopes, the code in one function cannot directly affect the values of variables in other functions. This limits what code could be changing the values of your variables, which can be helpful when it comes to debugging your code.

Happy Coding!

FIN

