In this seminar we&#39;ll go through some exercises to reinforce what we learned about common code patterns

1. a) Write down a flow chart for the following program:

       if name == 'Alice':
       print('Hi, Alice.')


b) compare it to the flowchart of:

    if name == 'Alice':
      print('Hi, Alice.')
    else:
     print('Hello, stranger.')



2. Use elif to create a program for the following flowchart:

![Alt text](img_2.png?raw=false "Flowchart Exercise 2")




3. Transform the following program from an if conditional to a while loop and write a flowchart for each.

       spam = 0
       if spam < 5:
           print('Hello, world.')
           spam = spam + 1


4. Consider the list **spam = [&#39;cat&#39;, &#39;bat&#39;, &#39;rat&#39;, &#39;elephant&#39;]**. Which is the 0th element? How about the 3rd? What happens when you try to access the element 1000? What happens when you try to access a negative index like **spam[-1]?**


5. Write a program for the following for flowchart:

![Alt text](img_5.png?raw=false "Flowchart Exercise 5")



6. In the list **animal\_list = [&#39;cat&#39;, &#39;bat&#39;, &#39;rat&#39;, &#39;elephant&#39;]** , replace the value at index 1 with &quot; **aardvark**&quot;. Can you use assignments to change all the elements on the list to &quot; **aardvark**&quot;?



7. Experiment with List Concatenation and List Replication. What happens when you enter the following?

       [1, 2, 3] + ['A', 'B', 'C']
       
       animal_list = ['cat', 'bat', 'rat', 'elephant']
       
       animal_list*3


8. How do you make the following program reach the end? Hint: writing down a flowchart might help!

       name = ''
       while name != 'your name': 
         print('Please type your name.') 
         name = input() 
         print('Thank you!') 
