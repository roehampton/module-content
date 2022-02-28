# Computational Thinking Week 06 Seminar -- Pseudocode

**Remember to give a break every hour or so.**

## Review and Recap

Start the session by asking the students to write down the top three things they learned last week. Then ask them to tell the class. Focus on correcting any misunderstandings and reflecting on the critical essential takeaways.

## Introduction

The point of this seminar is to have students move from visualising computation to writing computation in structured English. This will take students to the point of starting to write programs.

### What is Pseudocode?

Pseudocode is a structured English method of writing what an algorithm does. It provides a stepping stone to programming. There is no standard way of writing pseudocode, so we will use the following:

- `BEGIN` -- denotes the start of the computation.
- `END` -- denotes the end of the computation.
- `LET x = 5` -- denotes declaring a variable in memory.
- `PRINT` -- denotes printing something to the screen.
- `READ x` -- denotes reading something from the keyboard.
- `IF x = 5 THEN` -- denotes a conditional (*if statement*).
- `ELSE` -- denotes what happens when the `IF` is false.
- `END IF` -- denotes the end of the `IF`.
- `LOOP` -- denotes a loop. We will look at different versions.
- `END LOOP` -- denotes the end of a loop.

This is a lot to take in, but we will use examples to explore further.

### Simple Example

The first example is the one we've used already.

```pseudocode
BEGIN
    STAND UP
    TURN 180
    STEP FORWARD
    TURN 180
    STEP FORWARD
    SIT DOWN
END
```

### Egg Boiling

Ask the students to write this out first. An example is:

```pseudocode
BEGIN
    FILL SAUCEPAN WITH WATER
    SET HOB TO HIGH
    PUT SAUCEPAN ON HOB
    WAIT UNTIL WATER BOILING
    ADD EGG TO WATER
    WAIT ONE MINUTE
    REMOVE SAUCEPAN FROM HOB
    WAIT SIX MINUTES
    REMOVE EGG FROM WATER
END
```

### Travel

Now ask the students to explore a travel example, e.g., Roehampton to Oxford Circus.

## Conditionals

Introduce the concept of conditional. We've already covered the concept of choice in a program -- either true/false or yes/no. Now introduce how to represent this in pseudocode. Use the following example:

```pseudocode
BEGIN
    READ username
    IF username = "Kevin" THEN
        PRINT "ACCESS GRANTED"
    ELSE
        PRINT "ACCESS DENIED"
    END IF
END
```

Add another example on accepting a friend request in social media:

```pseudocode
BEGIN
	LET requester = RECEIVE REQUEST
	IF requester IS KNOWN THEN
	    IF requester IS LIKED THEN
	        ACCEPT REQUEST
	    ELSE
	        IGNORE REQUEST
	    END IF
	ELSE
	    IGNORE REQUEST
	END IF
END
```

Finally, ask students to do one for travel from Roehampton to Oxford Circus by using conditionals to make choices on what transport to take.

## Loops

A loop repeats the instructions inside it until a condition is met. For example, we can use a loop to get the average age of the class.

```pseudocode
BEGIN
    LET total = 0
    LET count = 0
    LOOP UNTIL ALL PEOPLE ASKED
        READ age
        total = total + age
        count = count + 1
    END LOOP
    LET average = total / count
    PRINT average
END
```

Now show an example where we output all numbers up to 100 that are divisible by seven.

```pseudocode
BEGIN
    LET counter = 1
    LOOP UNTIL counter > 100
        IF counter divisible by 7 THEN
            PRINT counter
        END IF
        counter = counter + 1
    END LOOP
END
```

Now provide a problem to work through. Ask the students for a particular problem that they can relate to, but keep it simple. For example, you can use making tea and coffee for a group of people. This would be related to the age summing example.

## Lab

Drawing flowcharts using a suitable tool (e.g., [diagrams.net](https://app.diagrams.net/)).

## Exercises

1. Write pseudocode that generates the first 50 items of the Fibonacci series:

   Note: Fibonacci series is defined as a sequence of numbers in which the first two numbers are 1 and 1, or 0 and 1, depending on the selected beginning point of the sequence, and each subsequent number is the sum of the previous two. 

   **How to Generate Fibonacci Series?**

   ![img](../../week-05/seminar/clip_image001-3778289.png)

2. Write pseudocode for printing even numbers between 9 and 100

   Note: Any integer that can be divided exactly by 2 is an even number.

   Example of even number  2, 4, 6, 8, 10, . . . 

3. Write pseudocode for an Order-Filling Process which will involve Credit Cheek, Inventory check, Production, Shipment and finally Billing. 

   Note: Order-Filling is the process of receiving goods, then processing and delivering orders to customers. The process starts with a customer placing an order and ends once they receive it. 

4. Write pseudocode for a traffic light scenario.

   Note: A good driver will always follow traffic laws. Let us assume you are a car driver starting from your home and approaching the traffic light. Write pseudocode for the traffic light rules.

5. Write pseudocode for the ATM system for withdrawal of cash-based scenario:

   Note: An automated teller machine (ATM) is an electronic banking outlet that allows customers to complete basic transactions without the aid of a branch representative or teller. Anyone with a credit card or debit card can access cash at most ATMs.

6. Write pseudocode to illustrate each of the following scenarios:

   An online banking application allows users to perform a number of operations on their bank account. The following description covers the actions of the system once the user has logged in and selected an account. A menu will be displayed with the options Show Balance, Show Transactions, Transfer Money, and home. The options will work as follows:

   - Show Balance will retrieve the balance from the database and display it on the page.
   - Show transactions will retrieve a transaction from the database and display it on the page, this will continue until there are no more transactions to display.
   - Transfer money will prompt the user for the sort code and account number of the account they are transferring to. It will then ask for the amount. If the amount is <= 0 then the user will be prompted again. Once an amount has been entered then the details of the transfer will be displayed (account details and amount) and the user will be asked to confirm that they want the transfer to go ahead. If they confirm that the transfer is to go ahead then the transfer details will be sent to the bank’s main server.
   - Home will redirect the user to the bank’s home page. Produce a flowchart that describes the displaying of the menu and the actions of the 4 options. 