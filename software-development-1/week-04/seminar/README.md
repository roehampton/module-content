
1.	Define the following function:

        def drawBox():
          print("**********")
          print("*        *")
          print("*        *")
          print("**********")

How do you print it on screen?
How do you print many of these onscreen?

2.	Make a function that draws a box by taking input from the user (arguments) for its height and width. Tip: Two arguments must be supplied when the drawBox function When the function executes the value of the first argument will be placed in the first parameter variable, and similarly, the value of the second argument will be placed in the second parameter variable. 


3.	Write a function that takes three numbers as parameters and returns the median value of those parameters as its result. Include a main program that reads three values from the user and displays their median. Tip: The median value is the middle of the three values when they are sorted into ascending order. It can be found using if statements, or with a little bit of mathematical creativity.  


4.	Write a function that takes a string, s, as its first parameter, and the width of the window in characters, w, as its second parameter. Your function will return a new string that includes whatever leading spaces are needed so that s will be centred in the window when the new string is printed. The new string should be constructed in
the following manner:
a.	 If the length of s is greater than or equal to the width of the window then s should be returned.
b.	If the length of s is less than the width of the window then a string containing (len(s) - w) // 2 spaces followed by s should be returned.  

  Write a main program that demonstrates your function by displaying multiple strings centred in the window. 



5.	Write a function that generates a random password. The password should have a random length of between 7 and 10 characters. Each character should be randomly selected from positions 33 to 126 in the ASCII table. Your function will not take any parameters. It will return the randomly generated password as its only result. Display the randomly generated password by calling the program. Tip: You will probably find the *chr* function helpful when completing this exercise. Detailed information about this function is available online.
