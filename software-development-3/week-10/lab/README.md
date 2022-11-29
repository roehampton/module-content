# Software Development 3 
# Lab 10 Beginning F#


## Setting up a new project in Visual Studio 2022

Let's create a new Console Application project by launching the Visual Studio.
  * Select the Create a new project option.
  * Choose F# as language, and in the template pane, select Console App (.NET Core) and
  * click Next button.
  * Enter the project name, you can change the location and solution name or  leave it as is and click on the Create button.
  
You will see a new project is created.

You will work in the Program.fs file which has been created for you.

## Printing to the console

You will see this which you can immediately run 

 
```f#
// For more information see https://aka.ms/fsharp-console-apps 

printfn "Hello from F#" 

```

(Use the run arrow to see the output)

## Hello world

Amend the code to start your adventures with f# in the time-honoured way

```f#

printfn "Hello world" 
```

## Formatting text output

You can use Console.WriteLine() just as you did in c# to output text.  if you want to do this you would need to do this...

```f#
open System;
Console.WriteLine("Welcome to SD3_F# Lab Session.")
```

However its more in keeping with f# to use the formatted print function, printfn.  This is similar to the C-style family of print functions such as sprintf.  In printfn you put placeholders in your text for the variable values and put the variable names followng the text string.  Here's more information:
[https://fsharpforfunandprofit.com/posts/printf/](https://fsharpforfunandprofit.com/posts/printf/)

Try these examples:

```f#
let name = "lisa" 
// String substution see: https://fsharpforfunandprofit.com/posts/printf/ 
printfn "Hello from %s" name 

let age = 21 
// Integer substution see: https://fsharpforfunandprofit.com/posts/printf/ 
printfn "I am %i years old" age
```


## Your first function

Write and experiment with the addOne function

```f#
let addOne n = n + 1 
let result = addOne 2  // parenthesis are not necessary 
printfn "%i" result  //output should be 3 
```

In visual studio, roll over the function name to see its 'signature'

Try it with strings:

```f#

// Try it with strings 

let addString s = s + "xxxx" 
let sResult = addString "lisa" 
printfn "%s" sResult 

```

## First class functions

```f#
// Pass a function as a parameter 
let result1 = addOne (addOne 2)  // parenthesis help here! 
printfn "%i" result1  //output should be 3 
```

**Exercise:
Create a function to calculate the square of number n.
Use this function to calculate n<sup>4</sup>**

## Try some things that won't work

#### You cannot mix types

```f#
//Try to mix types 
let nResult = addOne "lisa"  // Can't do this, as addOne implicitly knows its input should be an int 
```

#### Values (variables) are immutable by default

```f#
//Try to reassign a variable 
let result = addOne 1 // Cant reassign using let, duplicate definition error 
result = addOne 1 //Also an error, can’t change the value 
```

## Mutable variables

Create a mutable variable to fix the above

```f#
let mutable r = addOne 2 
r = addOne 1  
printfn "%i" r 
```

**Exercise:
Using your square numbers function, create a mutable variable to which you can assign firstly the result of 2<sup>2</sup> and then the result of 2<sup>4</sup>


## Write a recursive function

Fibonacci sequence

```f#
let rec fib n =        // use rec keyword to create recursion function   ​ 
    if n < 2 then  
        1 
    else  
        fib (n - 1) + fib (n - 2) 

```

Exercise: get this working and then use it to output the the sum of the fibonnaci sequence when n = 5 and when n = 10.


## Pattern matching

Pattern matching is a powerful feature of f# and is widely used.  See: [https://learn.microsoft.com/en-us/dotnet/fsharp/language-reference/pattern-matching](https://learn.microsoft.com/en-us/dotnet/fsharp/language-reference/pattern-matching)

The general format is:

```f#
match expression with
| pattern [ when condition ] -> result-expression
```


Here is an example of a function that takes an input and prints "x is a" if the input is a and "x is b" if the input is b and "its something else" if the input is another letter.

```f#
let simplePatternMatch x =  
    match x with 
    | "a" -> printfn "x is a" 
    | "b" -> printfn "x is b" 
    | _ -> printfn "its somethign else" 

```

Exercise: Get this working (take care of indentation and whitespace), and run this function on a number of different letters.

Exercise: Write and use a pattern matching function that when give a test mark between 1 - 100 can output a message saying if the mark is a pass or fail. (pass mark of 50)

HINT: YOu will need the when part of the pattern match expression, ie your pattern. This example may help

```f#
let sign x =
    match x with
    | 0 -> 0
    | x when x < 0 -> -1
    | x when x > 0 -> 1
 ```