# Computational Thinking Seminar 05 -- Flowcharts

<script src="https://cdn.jsdelivr.net/npm/mermaid/dist/mermaid.min.js"></script>

**Remember to give a break every hour or so.**

## Review and Recap

Start the session by asking the students to write down the top three things they learned last week. Then ask them to tell the class. Focus on correcting any misunderstandings and reflecting on the critical essential takeaways.

## Introduction



### What is a Flowchart?



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



<div class="mermaid">
flowchart TD;
    start(Start)
    id1[Stand up]
    id2[Turn 180]
    id3[Step forward]
    id4[Turn 180]
    id5[Step forward]
    id6[Sit down]
    stop(Stop)
    start --> id1 --> id2 --> id3 --> id4 --> id5 --> id6 --> stop
</div>



8. Computational Thinking Seminar 04 -- Flowcharts

   These tutorials are designed to teach you a number of techniques. As all of you know a flowchart is a type of diagram that represents a workflow or process which is a picture of the separate steps of a process in sequential order. In essence, a flowchart can also be defined as a diagrammatic representation of an algorithm, a step-by-step approach to solve a task. Moreover, flowchart shows the steps as boxes of various kinds, and their order by connecting the boxes with arrows. 

   Most importantly, flowcharts help programmers develop the most efficient coding because they can clearly see where the data is going to end up. Flowcharts help programmers figure out where a potential problem area is and helps them with debugging or cleaning up code that is not working. Now we are going to implement our knowledge. 

   ## Exercises

   1. Draw a flowchart which generates first 50 items of the Fibonacci series:

      Note: Fibonacci series is defined as a sequence of numbers in which the first two numbers are 1 and 1, or 0 and 1, depending on the selected beginning point of the sequence, and each subsequent number is the sum of the previous two. 

      **How to Generate Fibonacci Series?**

      ![img](clip_image001-3778289.png)

   2. Draw a flowchart of printing even numbers between 9 and 100

      Note: Any integer that can be divided exactly by 2 is an even number.

      Example of even number  2, 4, 6, 8, 10, . . . 

   3. Draw a flowchart for an Order-Filling Process which will involve Credit Cheek, Inventory check, Production, Shipment and finally Billing. 

      Note: Order-Filling is the process of receiving goods, then processing and delivering orders to customers. The process starts with a customer placing an order and ends once they receive it. 

   4. Design a flowchart for traffic light scenario.

      Note: A good driver will always follow the traffic laws. Let us assume you are a car driver starting from your home and approaching the traffic light. Design a flowchart for the traffic light rules.

   5. Design a flowchart for the ATM system for withdrawal of cash-based scenario:

      Note: An automated teller machine (ATM) is an electronic banking outlet that   allows customers to complete basic transactions without the aid of a branch representative or teller. Anyone with a credit card or debit card can access cash at most ATMs.

   6. Draw a flowchart to illustrate each of the following scenarios:

      An online banking application allows users to perform a number of operations on their bank account. The following description covers the actions of the system once the user has logged in and selected an account. A menu will be displayed with the options Show Balance, Show Transactions, Transfer Money, and home. The options will work as follows:

      - Show Balance will retrieve the balance from the database and display it on the page.
      - Show transactions will retrieve a transaction from the database and display it on the page, this will continue until there are no more transactions to display.
      - Transfer money will prompt the user for the sort code and account number of the account they are transferring to. It will then ask for the amount. If the amount is <= 0 then the user will be prompted again. Once an amount has been entered then the details of the transfer will be displayed (account details and amount) and the user will be asked to confirm that they want the transfer to go ahead. If they confirm that the transfer is to go ahead then the transfer details will be sent to the bank’s main server.
      - Home will redirect the user to the bank’s home page. Produce a flowchart that describes the displaying of the menu and the actions of the 4 options. 