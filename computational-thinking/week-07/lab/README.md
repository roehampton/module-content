# Computational Thinking Lab 07 -- Flowcharts and Pseudocode

In this lab, you will be using [diagrams.net](https://app.diagrams.net/) to draw flowcharts from pseudocode. We will be using the examples you have seen before.

## Starting Example

For the starting example, the pseudocode is as follows:

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

**Use diagrams.net to draw this flowchart. It looks as follows:**

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

## Egg Boiling

The pseudocode for egg boiling is as follows:

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

**Use diagrams.net to draw the flowchart. Ask for feedback on your solution.**

## Conditionals

Conditionals (choice, if-statements), use a diamond to indicate the selection. We used the first example below:

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

**Now create the flowchart using diagrams.net. It will look as follows.**

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

**Now draw the flowchart for the following pseudocode. Ask for feedback on your solution.**

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

## Loops

Loops use conditionals to go back to a previous step in the flowchart. Below is our first example:

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

**Draw the flowchart in diagrams.net. It should look as follows:**

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

**Now draw the flowchart for the following pseudocode. Ask for feedback on your solution.**

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

