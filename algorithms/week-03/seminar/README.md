# Queues

## Provide an algorithm to convert a positive integer to its binary representation using a queue

## Binary to Decimal


## Algorithm
1. Create an empty Queue – this will be used to generate the binary numbers
2. Create an empty List/ Array – this will be used to hold the results , i.e, the list of generated binary numbers till n
3. Enqueue “1” in the queue
4. Generate the binary numbers inside a loop that runs till “n” binary numbers has been added to the list. <br>
    4.1 Remove an element from the queue – call this “X” <br>
    4.2 Generate the next two binary numbers by adding a “0” and “1” to “X” respectively. The two new binary numbers thus generated are “X0” and “X1” <br>
    4.3 Enqueue “X0” and “X1” into the queue <br>
    4.4 Add “X” to the result list
