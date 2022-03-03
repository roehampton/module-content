# Computational Thinking Seminar 07 -- Hand-tracing Algorithms

**Remember to give a break every hour or so.**

## Review and Recap

Start the session by asking the students to write down the top three things they learned last week. Then ask them to tell the class. Focus on correcting any misunderstandings and reflecting on the critical essential takeaways.

## Introduction

The purpose of this session is for students to start reading an algorithm by computing it as the computer would. To start we will use the following simple example:

```pseudocode
BEGIN
    READ N
    READ M
    LET sum = N + M
    PRINT sum
END
```

Approach this as follows:

- As we execute each line, use a marker to show what is executing.
- For any variables, write them on the board and show them changing. Comment on this is what the computer is doing.
- Have an area of the whiteboard that is for output.

- Ask the students to give a number N that is read in.
- Ask the students to give a number M that is read in.
- Compute the value of sum.
- Show the value of sum in the output.

Now ask the students to run through the below example step-by-step on the whiteboard. Explain what `%` does -- it gets the remainder of a division. So, for example:

- `1 % 2 = 1`
- `2 % 2 = 0`
- `3 % 2 = 1`
- `10 % 5 = 0`
- `12 % 5 = 2`

```pseudocode
BEGIN
    READ N
    LET remainder = N % 2
    IF remainder = 0 THEN
        PRINT "N is even"
    ELSE
        PRINT "N is odd"
    END IF
END
```

## Working with Loops

The next example requires updating two variables in memory:

- `number`
- `sum`

Start with the values of `sum` and `number` on the board: `number = 1` and `sum = 0`. Then run through the loop.

1. Is `number > 10`? No, so:
   - `sum = sum + number = 0 + 1 = 1`
   - `number = number + 1 = 1 + 1 = 2`
2. Is `number > 10`? No, so:
   - `sum = sum + number = 1 + 2 = 3`
   - `number = number + 1 = 2 + 1 = 3`

And so on until `number > 10`.

```pseudocode
BEGIN
    LET number = 1
    LET sum = 0
    LOOP UNTIL number > 10
        sum = sum + number
        number = number + 1
    END LOOP
    PRINT sum
END
```

## Complex Example

This is one for the students to work through in small groups. Best method is to give the starting values of `x`, `y`, and `z`. Then let the students work out what the program does.

```pseudocode
BEGIN
    READ x
    READ y
    READ z
    IF x > y THEN
        IF x > z THEN
            PRINT x
            IF y > z THEN
                PRINT y
                PRINT z
            ELSE
                PRINT z
                PRINT y
            END IF
        ELSE
            PRINT z
            PRINT x
            PRINT y
        END IF
    ELSE
        IF y > z THEN
            PRINT y
            IF x > z THEN
                PRINT x
                PRINT z
            ELSE
                PRINT z
                PRINT x
            END IF
        ELSE
            PRINT z
            PRINT y
            PRINT x
        END IF
    END IF
END
```

## Lists

This is getting a bit more advanced, but introducing lists at this stage is useful. Present a list as a variable with an index. Draw it on the board as follows:

|        | **0** | **1** | **2** | **3** | **4** |
| ------ | ----- | ----- | ----- | ----- | ----- |
| `data` | 1     | 6     | 9     | 25    | 81    |

So, `data[0] = 1`, `data[1] = 6`, etc.

Discuss zero-indexing and why we use it. Now run through the following on the board.

```pseudocode
BEGIN
    LET data = [1, 6, 9, 25, 81]
    READ number
    LET found = FALSE
    LET index = 0
    LOOP UNTIL index >= LENGTH data OR found
        IF data[index] = number THEN
            found = TRUE
        END IF
        index = index + 1
    END LOOP
    IF found THEN
        PRINT "Number found"
    ELSE
        PRINT "Number not found"
    END IF
END
```

The next example requires changing the values of the list. Have the students guide the execution and show the data changing over time.

```pseudocode
BEGIN
    LET data = [1, 16, 12, 9, 4]
    LET index = 0
    LET stop = LENGTH data - 1
    LOOP LENGTH data - 1 TIMES
        LOOP stop TIMES
            IF data[index] > data[index + 1] THEN
                LET temp = data[index]
                data[index] = data[index + 1]
                data[index + 1] = temp
            END IF
            index = index + 1
        END LOOP
        stop = stop - 1
    END LOOP
    PRINT data
END
```

## Lab

More work on flowcharts.