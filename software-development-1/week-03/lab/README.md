# Software Development 1
# Lab 3 

In this lab we will go in more depth into the Syntax and Semantics of Python

1. A variable can be assigned many times. It always retains the value of the most recent assignment. Here is an interactive Python session that demonstrates the point: 

         # We initialize our variable
           myVar = 10 
           myVar
    
         # We can use the variable without modifying it 
          print(myVar - 7)
          myVar 
    
         # We can update the variable itself
         # The current value of a variable can be used to update its value
          myVar = myVar + 1 
          myVar



2. When Python encounters a call to input, it prints the prompt on the screen. Python then pauses and waits for the user to type some text and press the <Enter> key. Whatever the user types is then stored as a string. Consider: 

       # Lets try creating a variable for storing our name
       name = input ( "Enter your name: ")
       name

Executing the input statement caused Python to print out the prompt **Enter your name:** and then the interpreter paused waiting for user input. The string that the user put in is remembered in the variable name. Evaluating **name** gives back the string of characters that were typed by the user.
 

3. When the user input is a number, we need a slightly more complicated form of input statement: 

       <variable> = srt(input(<prompt>)) 

Here, we have used casting from an integer number into a string. That way, we ensure that whatever we are given by the user can be stored in our variable as a string type. We can then write a program that takes the first, middle and last names and displays the initials. By adding the extra casting into string, we ensure that any name, even the controversial X Æ A-12 (the name of Grimes's kid), can be read.

    # Read the user’s name 
    first = str(input("Enter your first name: "))
    middle = str(input("Enter your middle name: "))
    last = str(input("Enter your last name: "))

    # Extract the first character from each string and concatenate them 
    initials = first[0] + middle[0] + last[0] 

    # Display the initials 
    print("Your initials are", initials)

4. Let’s create and analyse a program and identify keywords, conditionals and structure (colons)
We will work through a program that reads a letter of the alphabet from the user. If the user enters a, e, i, o or u then the program should display a message indicating that the entered letter is a vowel. If the user enters y then the program should display a message indicating that sometimes y is a vowel, and sometimes y is a consonant. Otherwise it should display a message indicating that the 
letter is a consonant. 

Determine if a letter is a vowel or a consonant. 


    # Read a letter from the user 
    letter = input("Enter a letter: ")
    
    # Classify the letter and report the result 
    if letter == "a" or letter == "e" or \ 
    letter == "i" or letter == "o" or \
    letter == "u": 
      print("It’s a vowel.") 
    elif letter == "y": 
      print("Sometimes it’s a vowel... Sometimes it’s a consonant.") 
    else: 
      print("It’s a consonant.") 




