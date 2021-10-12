# Queues

## Provide an algorithm to convert a positive integer to its binary representation using a queue

Algorithm
Create an empty Queue – this will be used to generate the binary numbers
Create an empty List/ Array – this will be used to hold the results , i.e, the list of generated binary numbers till n
Enqueue “1” in the queue
Generate the binary numbers inside a loop that runs till “n” binary numbers has been added to the list. Here’s what happens inside the loop:
Remove an element from the queue – call this “X”
Generate the next two binary numbers by adding a “0” and “1” to “X” respectively. The two new binary numbers thus generated are “X0” and “X1”
Enqueue “X0” and “X1” into the queue
Add “X” to the result list
