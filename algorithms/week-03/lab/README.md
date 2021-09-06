# Week 3 - Lab Session

## Task 1. Create a priority queue.
For this task, you should first read the pre-session lecture on week 3. <br>
The elements in the queue are latin letters (a,b,c, ..., z) and the priority is given by which letter comes first in the ABC. For example, <br>
- queue = {r,y,d,a,h}
- e1 <- queue.pop() will return an **'a'** and queue is now {r,y,d,h}
- e2 <- queue.pop() will now return **'d'** and queue is now {r,y,h} and so on. 


## Task2. Postfix or Polish notation
Usually, you express a sum like 4 + 7; and a division as  10 / 5. But many computational systems (like compilers) use posfix notation, where operands come first, followed by an operator (+, -, *, /). When an operator is read in, it uses the previous operands to perform the calculation: <br>

4 + 7 is 4 7 + and 10/5 is 10 5 /

You can use a stack to do arithmetic operations on a postfix expression:

1. Read the input and push numbers onto a stack until you reach an operator.
2. When you see an operator, apply the operator to the two numbers that are popped from the stack.
3. Push the resulting value back onto the stack.
4. When the input is complete, the value left on the stack is the result.

For example, if the expression  1 2 + 3 * 6 + 2 3 + / is the input, the program should apply the above algorithm and return 3




