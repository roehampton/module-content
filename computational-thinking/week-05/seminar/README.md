# Computational Thinking Seminar 05 -- Flowcharts

<script src="https://cdn.jsdelivr.net/npm/mermaid/dist/mermaid.min.js"></script>

**Remember to give a break every hour or so.**

## Review and Recap

Start the session by asking the students to write down the top three things they learned last week. Then ask them to tell the class. Focus on correcting any misunderstandings and reflecting on the critical essential takeaways.

## Introduction

The point of this seminar is to have students visualise computation. They already did this in part when playing Light Bot. Now we will do it using flowcharts.

### What is a Flowchart?

A flowchart is just a way to visualise computation. Explore the following example.

1. Stand up.
2. Turn 180.
3. Step forward.
4. Turn 180.
5. Step forward.
6. Sit down.

<div class="mermaid">
flowchart TD;
    id1(Stand up)
    id2(Turn 180)
    id3(Step forward)
    id4(Turn 180)
    id5(Step forward)
    id6(Sit down)
    id1 --> id2 --> id3 --> id4 --> id5 --> id6
</div>

### Start and Stop

Now introduce the concept of a flowchart starting and stopping. Add this to the existing flowchart.

<div class="mermaid">
flowchart TD;
    start([Start])
    id1[Stand up]
    id2[Turn 180]
    id3[Step forward]
    id4[Turn 180]
    id5[Step forward]
    id6[Sit down]
    stop((Stop))
    start --> id1 --> id2 --> id3 --> id4 --> id5 --> id6 --> stop
</div>
Reflect on how start and stop can be represented in different ways, but normally quite obvious.

<div class="mermaid">
flowchart TD;
    id1(READ string)
    id2(LET index = LENGTH OF string - 1)
    id3(SET string[index] = 'Y')
    id4{index > 1}
    id5(SET index = index - 1)
    id6((Stop))
    id1 --> id2 --> id3 --> id4 --> id5 --> id3
    id
</div>

Now work through two more examples.

### Egg Boiling

Egg boiling. Let the students lead but use the following example if necessary.

<div class="mermaid">
    flowchart TD;
    	start([Start])
    	id1(Fill the saucepan with water)
    	id2(Turn on the hob to high heat)
    	id3(Put the saucepan on the hob)
		id4(Wait for the water to boil)
		id5(Add egg to water)
		id6(Wait for one minute)
		id7(Remove saucepan from the hob)
		id8(Wait for six minutes)
		id9(Remove egg from water)
    	stop((Stop))
    	start --> id1 --> id2 --> id3 --> id4
    	id4 --> id5 --> id6 --> id7 --> id8 --> id9
    	id9 --> stop
</div>

### Travel

Now ask the students to explore a travel example, e.g., Roehampton to Oxford Circus.

## Conditionals

Introduce the concept of conditional. We've already covered the concept of choice in a program -- either true/false or yes/no. Now introduce how to represent this in a flowchart. Use the following example:

<div class="mermaid">
    flowchart TD;
    	start([Start])
    	id1(Read in username)
    	id2{username = Kevin?}
    	id3(Display access granted)
    	id4(Display access denied)
    	stop((Stop))
    	start --> id1 --> id2
    	id2 -->|Yes| id3 --> stop
    	id2 -->|No| id4 --> stop
</div>

Add another example on accepting a friend request in social media:

<div class="mermaid">
  flowchart TD;
  		start([Start])
        id1(Receive friend request)
        id2{Know requester?}
        id3{Like requester?}
        id4(Accept request)
        id5(Ignore request)
        stop((Stop))
        start --> id1 --> id2
        id2 -->|Yes| id3
        id3 -->|Yes| id4 --> stop
        id3 -->|No| id5
        id2 -->|No| id5 --> stop
</div>


Finally, ask students to do one for travel from Roehampton to Oxford Circus by using conditionals to make choices on what transport to take.

## Loops

Demonstrate that we can repeat instructions by jumping back to an earlier point in the flowchart from a conditional. Use age averaging example:

<div class="mermaid">
  flowchart TD;
    start([Start])
    id1(Let total = 0, count = 0)
    id2(Let age = Next person's age)
    id3(total = total + age)
    id4(count = count + 1)
    id5{More people in the class?}
    id6(Let average = total / count)
    id7(Output average)
    stop((Stop))
    start --> id1 --> id2 --> id3 --> id4 --> id5
    id5 --> |Yes| id2
    id5 --> |No| id6 --> id7 --> stop
</div>

Now show an example where we output all numbers up to 100 that are divisible by seven.

<div class="mermaid">
  flowchart TD;
    start([Start])
    id1(Let counter = 1)
    id2{Counter divisible by seven?}
    id3(Display counter)
    id4(counter = counter + 1)
    id5{counter <= 100}
    stop((Stop))
    start --> id1 --> id2
    id2 --> |Yes| id3 --> id4
    id2 --> |No| id4
    id4 --> id5
    id5 --> |Yes| id2
    id5 --> |No| stop
</div>

Now provide a problem to work through. Ask the students for a particular problem that they can relate to, but keep it simple. For example, you can use making tea and coffee for a group of people. This would be related to the age summing example.

## Lab

Lab time is focused on the class test.

## Exercises

1. Draw a flowchart that generates first 50 items of the Fibonacci series:

   Note: Fibonacci series is defined as a sequence of numbers in which the first two numbers are 1 and 1, or 0 and 1, depending on the selected beginning point of the sequence, and each subsequent number is the sum of the previous two. 

   **How to Generate Fibonacci Series?**

   ![img](clip_image001-3778289.png)

2. Draw a flowchart of printing even numbers between 9 and 100

   Note: Any integer that can be divided exactly by 2 is an even number.

   Example of even number  2, 4, 6, 8, 10, . . . 

3. Draw a flowchart for an Order-Filling Process which will involve Credit Cheek, Inventory check, Production, Shipment and finally Billing. 

   Note: Order-Filling is the process of receiving goods, then processing and delivering orders to customers. The process starts with a customer placing an order and ends once they receive it. 

4. Design a flowchart for a traffic light scenario.

   Note: A good driver will always follow the traffic laws. Let us assume you are a car driver starting from your home and approaching the traffic light. Design a flowchart for the traffic light rules.

5. Design a flowchart for the ATM system for withdrawal of cash-based scenario:

   Note: An automated teller machine (ATM) is an electronic banking outlet that allows customers to complete basic transactions without the aid of a branch representative or teller. Anyone with a credit card or debit card can access cash at most ATMs.

6. Draw a flowchart to illustrate each of the following scenarios:

   An online banking application allows users to perform a number of operations on their bank account. The following description covers the actions of the system once the user has logged in and selected an account. A menu will be displayed with the options Show Balance, Show Transactions, Transfer Money, and home. The options will work as follows:

   - Show Balance will retrieve the balance from the database and display it on the page.
   - Show transactions will retrieve a transaction from the database and display it on the page, this will continue until there are no more transactions to display.
   - Transfer money will prompt the user for the sort code and account number of the account they are transferring to. It will then ask for the amount. If the amount is <= 0 then the user will be prompted again. Once an amount has been entered then the details of the transfer will be displayed (account details and amount) and the user will be asked to confirm that they want the transfer to go ahead. If they confirm that the transfer is to go ahead then the transfer details will be sent to the bank’s main server.
   - Home will redirect the user to the bank’s home page. Produce a flowchart that describes the displaying of the menu and the actions of the 4 options. 
