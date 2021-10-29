# Software Development 1 
# Lecture 6 -– Data Manipulation in Python

In this lab we will explore:

1. How to manipulate objects in lists
2. Python-specific syntax: Indentation of Code Blocks
3. Importing Functions

## Lesson 1: Lists
Video: [https://roehampton.cloud.panopto.eu/Panopto/Pages/Viewer.aspx?id=632a1366-d6ca-4ba6-a24d-ac6301617611](https://roehampton.cloud.panopto.eu/Panopto/Pages/Viewer.aspx?id=632a1366-d6ca-4ba6-a24d-ac6301617611)

We have seen the basic recipe structures:

- When you don&#39;t know ahead of time how often you&#39;re going to iterate, use **while loop**


      i = 1
      while i < 6:
        print(i)
        i += 1


- The **for** loop can be used to iterate a fixed number of times. If you know ahead of time how many times you need to loop, use for.


         for i in range(6):
            print(i)

- The **for** loop can iterate over any sequence (like a list or a string), as well as execute a fixed number of times (thanks to the **range** function).

The range function is in the form **range(start, stop, step)**, where


     Start (optional): integer number specifying at which position to start (Default is 0).

     Stop (required): integer number specifying at which position to stop (not included).

     Step (optional): integer number specifying the incrementation. (Default is 1).


Example

     list(range(5))



When range() is called with a single argument it generates a sequence of numbers from 0 up to the argument specified (but not including it). That&#39;s why the number 5 is not included in the sequence.

Example

     list(range(5, 10))


Example: Create a sequence of numbers from 3 to 5, and print each item in sequence. A for loop is going to let us iterate through all the elements in the list.

    x = range(3, 5)
    list(x)

try

    for n in x:
    print(n)



**range** returns a list, which we talked about when we discussed Collections of Objects, and we can use the **for** loop to go over such collections of objects. Special amongst these are tuples (which are immutable) and lists, which are mutable. Lists can contain numbers, characters, strings or even other lists:


    empty_list=[]
    cs_students = ["BSc", "MSc"]
    numbers = [1, 2, 3, 4, 5]


Think of these things sitting in memory as objects. For instance, if I append empty\_list to another, empty\_list becomes a list of lists:


    empty_list.append (cs_students)
    empty_list


**Append** is a **method** : a function with different syntax **.** We&#39;ll see later why we have this syntax, but for now, think of it as another way to write a function call.

Lists are very powerful notions as we can do interesting things with them. I can flatten them by using **concatenate** operator instead of _append_. This creates a new object and needs to be saved in a variable or you will lose it. It doesn&#39;t affect either of the original list objects.

    numbers + cs_students
    
    
So **+** or **concatenation** flattens it one level, **append** sticks the object at the end of the list, changing the original object.


    numbers.append(cs_students)
    numbers



Another method is **remove** , which does what it says: it removes a specified item form the list.


    my_list = [1, 2.0, "Arturo", False, ["cat", "dog", "pig"] ]
    my_list.remove("Arturo")
    my_list


The **in** operator is powerful. It can determine whether one thing is inside of another.


    my_list = [1, 2.0, "Arturo", False, ["cat", "dog", "pig"] ]

    if "Arturo" in my_list :
        print("Arturo is in list")
    else: 
        print("Arturo is NOT in list")





Example: lets create a list of numbers:


    numbers = []
    for i in range (1,10) :
        numbers.append(i)
    numbers


Example: Let&#39;s tackle odd numbers. Odd numbers are whole numbers that cannot be divided exactly into pairs. Odd numbers, when divided by 2, leave a remainder of 1.


    odd_numbers = []
    even_numbers = []

    for i in numbers :
        if (i%2==0) :
            even_numbers.append(i)
        else :
            odd_numbers.append(i)
    print("even numbers :", even_numbers)
    print("odd numbers :", odd_numbers)even_numbers






## Lesson 2: Blocks in Python

Video: [https://roehampton.cloud.panopto.eu/Panopto/Pages/Viewer.aspx?id=b9ba9f64-0c2a-4b74-9d9c-ac6400a13435](https://roehampton.cloud.panopto.eu/Panopto/Pages/Viewer.aspx?id=b9ba9f64-0c2a-4b74-9d9c-ac6400a13435)


We have seen the basic data and recipe structures. These are things common to all programming languages. However there are things we need to remember that are python specific. Python code is easy to read: the language was designed with that specific goal in mind. Guido van Rossum, the language&#39;s creator, wanted to create a powerful programming tool that produced code that was easy to maintain, which meant code created in Python has to be easy to read, too. For this he implemented **indentation** to demarcate a block of code, which Python programmers prefer to call **suite**. If you come from a &quot;curly- braced language&quot; like java or c++ you might struggle with indentation _at first_, but you&#39;ll get used to it in no time.

For instance, remember how you make decisions with the if/elif/else statement? The if, elif, and else keywords precede these blocks of code, or &quot;suites.&quot; The idea is that _suites_ within any Python program are easy to spot, as they are always indented. This helps your brain quickly identify suites when reading code. The other visual clue for you to look out for is the colon character ( **:** ), which is used to introduce a suite that&#39;s associated with any of Python&#39;s control statements (such as _if, elif, else_ and _for_). This is a syntactical requirement of the language.

Any suite can contain any number of embedded suites, which also have to be indented. When Python programmers talk about embedded suites, they tend to talk about **levels of indentation**. The initial level of indentation for any program is generally referred to as the _first_ or (as is so common when it comes to counting with many programming languages) indentation level _zero_. Subsequent levels are referred to as the second, third, fourth, and so on (or level one, level two, level three, and so on).

Let&#39;s identify the suites and levels in the following code:



    state = "OK"
    today =  "Saturday"
    if today == "Saturday" :
       print("Party (but socially distant)")
       state = "Hangover"
    elif today == "Sunday":
        if state == "Hangover":
            print("Rest and Recover")
       elif state == "OK":
           print("Just Rest")
    else:
         print ("Study and Work")




![Alt text](img_blocks.png?raw=false "Many levels of suites")




The key point is that indentation is used to demarcate suites of code in Python. It is important to note that code at the same level of indentation is only related to other code at the same level of indentation if all the code appears _within the same suite_. Otherwise, they are in separate suites, and it does not matter that they share a level of indentation.

One problem that some programmers do have with indentation occurs when they mix _tabs_ with _spaces_. Due to the way interpreters count **whitespace** , this can lead to problems, in that the code &quot;looks fine&quot; but refuses to run. This is frustrating when you&#39;re starting out with Python.

Style tip: _don&#39;t mix tabs with spaces in your Python code_.

Technically, the number of spaces needed for indentation is up to you as a programmer, but it has to be at least one. However, you have to be consistent. You have to use the same number of spaces in the same block of code, otherwise Python will give you a syntax error. In fact, the creators of Python advise to use _four space_s are the preferred indentation method. _Tabs_ should be used solely to remain consistent with code that is already indented with tabs.

The full Style guide, as coined by the creators of Python, can be found at:

[https://www.python.org/dev/peps/pep-0008/](https://www.python.org/dev/peps/pep-0008/)


So now you know about indentation and how this delineates block in python. In the next session we need to get creative.



## Lesson 3: Importing functions

Video: https://roehampton.cloud.panopto.eu/Panopto/Pages/Viewer.aspx?id=dc971706-4055-4e83-b105-ac6400a13460

The **standard library** supplies reusable modules that help you with everything from, working with data, through manipulating ZIP archives, to sending emails, to working with HTML. You can import a specific function from a module. For example, the random module has a very useful function called **randint** that generates a **random integer** within a specified range. From **time** import **sleep,** we can invoke the **sleep function** , letting you delay the code response.

Here&#39;s how to determine the identity of your underlying operating system, by first importing the sys module, then accessing the platform attribute:


    import sys
    sys.platform


Import the module, then invoke the functionality we need

There&#39;s time we all have enough of it, we just need to use it wisely. The _standard library can_ tell us what time it is. After importing the time module, call the **strftime** function and specify how you want the time displayed. In this case, we are interested in the current time&#39;s hours (%H) and minutes (%M) values in 24-hour format:


    import time 
    import time 
    time.sleep(5) 
    time.strftime("%H:%M")


Example:


    import random
    random.randint(1,60) 


Example:

    import datetime
    datetime.date.today() 


You can access the day, month, and year values separately by appending an attribute access onto the call to date.today:

    print(datetime.date.today().day)
    print(datetime.date.today().month)
    print(datetime.date.today().year)

Example:

    datetime.date.isoformat(datetime.date.today()) 


Functions are inside modules inside the standard library. Don&#39;t worry about what each of these modules does at this stage, but it is important to know how this is structured:


![Alt text](img_standard.png?raw=false "Modules in the Standard Library")



The Python documentation has all the answers on the standard library. Here&#39;s the kicking-off point: [https://docs.python.org/3/library/index.html.](https://docs.python.org/3/library/index.html.)

The standard library isn&#39;t the only place you&#39;ll find excellent importable modules to use with your code. The Python community also supports a thriving collection of third-party modules, some of which we&#39;ll explore later in the course. If you want a preview, check out the community-run repository: _http://pypi.python.org_.

Example:

When **today** is invoked, it returns a &quot;time object,&quot; which contains many pieces of information about the current time. These are the current time&#39;s **attributes** , which you can access via the customary **dot-notation** syntax. In this program, we are interested in the minute attribute, which we can access by appending **.minute** to the method invocation, as shown above. The resulting value is then assigned to the **right\_this\_minute** variable. You can think of this line of code as saying: _create an object that represents today&#39;s time, then extract the value of the minute attribute before assigning it to a variable._ It is tempting to _split_ this single line of code into two lines to make it &quot;easier to understand,&quot; as follows:

    # First determine the current time
    time_now = datetime.datetime.today()
    time_now


    # then extract the minute value
    time_this_minute = time_now.minute 
    time_this_minute




Example: is this an odd minute?


    from datetime import datetime 
    odds=[1, 3, 5, 7, 9,11,13,15,17,19, 21, 23, 25, 27, 29, 31, 33, 35, 37, 39, 41, 43, 45, 47, 49, 51, 53, 55, 57, 59 ] 
    right_this_minute = datetime.datetime.today().minute 
    if right_this_minute in odds:
        print("This minute seems a little odd.") 
    else:
        print("Not an odd minute.")


You can explore this library at: [https://docs.python.org/3/library/](https://docs.python.org/3/library/)

FIN
