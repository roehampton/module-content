# Software Development 1 Seminar Workshop 01 -- Pseudocode

In this seminar, we are going to learn how to solve computational problems by breaking them down to simple steps.

> In computer science, pseudocode is a plain language description of the steps in an algorithm or another system. Pseudocode often uses structural conventions of a normal programming language, but is intended for human reading rather than machine reading.

## Instructions

Your group have to program a computer to draw various flags. The computer is very simple and only understands the following instruction.

```
Draw COLOUR rectangle from START to END
```

`COLOUR` is the fill-in colour of the rectangle.

`START` and `END` are coordinates in the two-dimensional plane. For example, consider the Ukraine flag.

![image-20210331202934366](image-20210331202934366.png)

Let us say that the top left corner is coordinate `(0, 0)` and bottom-right corner is `(600, 400)`. Then, to draw the Ukraine flag we will issue the following commands to the computer.

```
DRAW light_blue rectangle from (0,0) to (600, 200)
DRAW yellow rectangle from (0, 200) TO (600, 400)
```
> Recall: what we have done during the lab?
```
rect = Rectangle(Point(0, 0), Point(600, 200))
rect.setFill('blue')
rect.draw(Ukraine)
rect = Rectangle(Point(0, 200), Point(600, 400))
rect.setFill('yellow')
rect.draw(Ukraine)
```

### Now you try

Your group must come up with the instructions to draw the following flags.

- **Monaco**

![image-20210331203839536](image-20210331203839536.png)

- **Austria**

![image-20210331203903372](image-20210331203903372.png)

- **Armenia**

![image-20210331203914773](image-20210331203914773.png)

- **Germany**

![image-20210331203924428](image-20210331203924428.png)

- **Sierra Leone**

![image-20210331203933042](image-20210331203933042.png)

- **Columbia**

![image-20210331203941828](image-20210331203941828.png)

- **Nigeria**

![image-20210331203951159](image-20210331203951159.png)

- **Chad**

![image-20210331204005331](image-20210331204005331.png)

- **Madagascar**

![image-20210331204014356](image-20210331204014356.png)

- **Benin**

![image-20210331204022849](image-20210331204022849.png)
