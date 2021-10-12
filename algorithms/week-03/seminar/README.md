# Queues

## Provide an algorithm to convert a positive integer to its binary representation using a queue

## Going from Decimal base to binary base (and vice versa)

Watch: https://youtu.be/a2FpnU9Mm3E

The first five decimal numbers have the following binary equivalence
Decimal : 1        2         3        4          5

Binary :    1       10       11     1000      101

A -not that easy- algorithm to comvert numbers from decimal to binary, is using a stack

## Algorithm
Input:  An integer number n in base 10
Output: A binary representation of n

1. Create an empty Queue – this will be used to generate the binary numbers
2. Create an empty List/ Array – this will be used to hold the results , i.e, the list of generated binary numbers till n
3. Enqueue “1” in the queue
4. Generate the binary numbers inside a loop that runs till “n” binary numbers has been added to the list. <br>
    4.1 Remove an element from the queue – call this “X” <br>
    4.2 Generate the next two binary numbers by adding a “0” and “1” to “X” respectively. The two new binary numbers thus generated are “X0” and “X1” <br>
    4.3 Enqueue “X0” and “X1” into the queue <br>
    4.4 Add “X” to the result list
