# Software Development 1 
# Lecture 2 -- Introduction to Programming

In this week, we’ll explore 
1.  What is Programming 
2.  Programming Languages 
3.  Introduction to Python

By the end of this week, you’ll have knowledge of programming concepts, programming skills and problem-solving abilities. Our goal is to make you think as a computer scientist so that when you are faced with a challenge, you’ll immediately think:

> "How am I going to write a piece of code to help me tackle this?"

## Lesson 1:  What is Programming?

Video: https://roehampton.cloud.panopto.eu/Panopto/Pages/Viewer.aspx?id=94ff6a2b-948b-4b73-adb2-ac4900c517a5

To understand this, we need to separate computer from computation. Computation is independent of the way is it is implemented in a computer. Think of the difference between knowing something vs knowing how to do something. For instance, knowing what is your favourite food vs how to make your favourite food. 

    Exercise: Do you know how to make you favourite food? Can you write down a recipe for how to make it?

A recipe is a description of a set of steps; a sequence of specific instructions in order for you to accomplish an objective. 
We define computation as the techniques of capturing this process in a mechanical fashion.

Some of the earliest computers, known as **fixed program computers**, were designed to do just one thing. For instance, early calculators were designed to do only maths. In the 1940’s Dr Alan Turing made the Bombe computer with the sole purpose of breaking German code (cryptography). Trough computing, we want to capture the idea of problem solving.

 > Suppose you invent a circuit that reads a circuit diagram and reconfigures itself to act like that that circuit diagram. You would have to invent a machine that takes a recipe, and acts like what is described in that recipe. This is known as an interpreter. 
     What happens when you change the circuit?

This is the idea behind **Stored Program Computers**, the multipurpose device we will be working with. These computers usually have the following elements:

    Memory-> Control Unit-> ALU-> Programme Counter
    
![Alt text](img_stored_program.png?raw=false "Stored Program Computer")

Programming is the process of creating a set of instructions that tell a computer how to perform a task. Programming can be done using a variety of computer programming languages, such as Matlab, Python, and C++

Back in the olden days, computers had physical cards that need punching, etc. 

    Do you know of any of these old physical computing mechanisms? 

## Lesson 2: Programming Languages

Video: https://roehampton.cloud.panopto.eu/Panopto/Pages/Viewer.aspx?id=92cb69a2-0d52-4b23-ae58-ac4900c51714

To describe recipes, we need a language. So far, we have been using English to describe these recipes. However, to be able to communicate with the computer, we need a different language. Our digital devices understand instructions in 1s and 0s. The basic programming languages take this into account and create basic words or instructions that translate into something the computer can do with those 1s and 0s. We discussed how some of these old computers had tapes and other mechanical mechanisms to handle instructions and data. The first computer languages then needed to translate our commands to something the computer could understand. From these a basic set of instructions, or primitives, were born.

> Given a fixed set of primitives (defined then as the most basic instructions for the Stored Program Computers to work) we can program anything. 

1936 Turing showed that with 6 primitives (having to do with the way tapes are being read or written), anything that can be described in a mechanical process, can be programmed with those 6 primitives. Furthermore, he showed that anything that you can do in one programming language you can do in another programming language (Turing compatibility). Fast forward 90 years, the languages have gotten more complex with many more higher-level primitives that more closely resemble our human languages. Square root can be a primitive.

We’ll explore some of these modern primitives, how we make them and understand how the affect the flow of control. Like human languages, there are 100s of programming languages including Visual Basic, C, Mathematica, Matlab, C++, Java, Processing and Python. 

We’ll use **python** for this class, but this course is not about **python**. We need to know how to use it, but it’s not about where do the semicolons go in Python. It’s about using Python as a tool to think. We are interested here in learning how to learn, how to design recipe, how to structure recipes, how to do things in ways that can be translated to other languages. Once you know how to think like this, you can then learn another language in a few weeks.

We refer to the *“dimension of language”* when we are asking how close are we to the guts of the machine?
> *Assembly language* is when you are programming at the level of the primitives, moving one piece of data from one location in memory to the next. 
> *High level language* is a more recognisable set of actions. For example, when you ask Python to *print* some information, it will literally print in the display the information. 


When we discuss *General* vs *Targeted* languages, what we want to know is how broad are the applications. Are they very specific or can they be used for many things?
> Matlab, for instance, is a language targeted to Matrices.


Finally, when we ask whether a language is *Interpreted* vs *Compiled*, we are asking whether the source code goes directly to an interpreter, or if the source code first runs into a checker or compiler and then creates object code. The latter helps catch bugs in the code and converts it into a more efficient sequence of instructions that you then run. It’s not as fast as going directly to the interpreter though. 

> Therefore, Python is a high level, general purpose, interpreted language.

## Lesson 3:  Introduction to Python

Video: https://roehampton.cloud.panopto.eu/Panopto/Pages/Viewer.aspx?id=058f6deb-ebd6-4f9f-90eb-ac4900c51768

Python Syntax vs Semantics
> Syntax says what are the legal expressions in this language (cat, dog, etc).
> Semantics says how we construct expressions.

*Static Semantics* in Python determine which programs are meaningful; which expressions make sense. Consider for instance: 
    My desk is Susan

Does it make sense?

> False.

*Static Semantics* asks what does the program mean? What’s going to happen when I run it? Thought this, Python checks your syntax, one bug at a time.

Typical Problems that can arise are: 
    It could not run, it could loop forever, or it gives you a wrong answer. 

But the problem is that if the program is complex enough you might not be able to tell! To help tackle this, we need to develop a **good style**: write in a way that allows you to spot problems.

The goal for this lab session is to have a set of primitives that we combine into complex expressions that we can then abstract and treat as *higher primitives*. For this, we will use a sequence of instructions in this flow of control in order to deduce new information. 


Python has different Types of values: 

> Strings are **strings**

> Numbers can be **integer, floats**

> Logical (true or false) are **Boolean**

Higher programming languages have a set of operators that expect a certain type of input to give a certain type of output. Let’s explore the typical set of arithmetic operations:
>    5*5

>    3+2

>    7/3


What do these have in common?
> We have an "operand" first, then an "operator", then another "operand".

What happens if we do something like “cat”/“tree"?
> Error

Commands (statements) take a value and ask the computer to do something with it. 

What is the difference between:    
    
    print (5*4)
    
    print ("5*4")
    
    print ("5"*"4")


Finally, we use Variables to store things

    mystringis = (assign or bind to this name the value of this expression)
    
We’ll continue exploring variables in the lab session.
    


FIN 
