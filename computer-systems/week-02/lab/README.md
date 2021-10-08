# Computer Systems Lab 2 - Logic Design

<script src="https://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS-MML_HTMLorMML" type="text/javascript"></script>

1. Work environment
2. Basic one -- switch and light
3. Inverter
4. OR
5. AND
6. XOR
7. Complex logic circuits
8. 





This lab aims to implement simple logic circuits. The software used is Logic.ly The focus is to learn how to design the circuits, find the truth table for the gates, and simulate the combination of gates.

## Work Environment

When you start Logic.ly, a blank canvas screen is provided for defining circuits.

![Logic.ly starting window](logic.ly.png)

There is a menu for handling project-specific tasks such as creating new diagrams and file management. To create a new logic gate diagram select **File**, **New**, and the **Gate Diagram**.

![Creating new gate diagram with Logic.ly](logic-friday-new-gate.png)

This will open the logic gate components window at the bottom-right of the main window.

![Logic gate component window](logic-friday-components.png)

The components we can create are:

- **NAND**, **NOR**, **AND**, and **OR** gates. The 2-In, 3-In, and 4-In prefix defines the number of inputs the gates will take.
- An **Inverter** which is the **NOT** gate.
- A 2-In **XOR** gate.
- Constant 0 or 1 values.
- Inputs and outputs.
- Wires (the button next to **Cancel**).

## Finding a Truth Table

We will now examine the truth table for an **AND** gate.

1. **Add a 2-in AND gate to the canvas.**
2. **Add an Input to the canvas to the left of the AND gate. For the Variable Name leave it as default (A).**
3. **Add a second Input to the canvas below the other Input. For the Variable Name leave it as default (B).**
4. **Connect the two Inputs to the AND gate using a wire.**
5. **Add an Output to the canvas to the right of the AND gate. For the Variable Name leave it as default (F0).**
6. **Connect the AND gate to the Output using a wire.**

Your diagram should look something like this:

![AND diagram](and-diagram.png)

Now, **click the Submit button on the Components Window.** The logic diagram will be analysed and the equation and truth table generated. Your screen will look something like this:

![Analysis of AND gate](logic-friday-and-analysis.png)

At the moment, only the 1 (true) outputs are shown on the truth table on the left. In the menu, **select Truthtable** then **Show all rows.** The full truth table will be shown.

Above the canvas, the function equation is shown. This is:

```
F0 = A B;
```

An AND gate is sometimes represented by multiplication (e.g., A B) rather than with the logical and symbol. An OR gate is sometimes represented by a plus (e.g., A + B) rather than with the logical or symbol. This does not matter for this lesson. We are only concerned with gates and truth tables.

### Increasing the Inputs

We can edit the gate diagram by clicking **Gates** then **Modify Gate Diagram**. Now perform the following steps:

1. **Delete the existing 2-In AND gate.**
2. **Add a 3-In AND gate.**
3. **Wire up the existing two Inputs and Output to the gate.**
4. **Add a third Input (C) to the diagram and wire it to the gate.**
5. **Click Submit to analyse the system.**
6. **Select Truthtable then Show all rows to see all the rows.**

Your diagram should be:

![3-In AND gate](3-in-and.png)

### Exercises

1. Find the truth table for OR, NOT, and NOR with two inputs.
2. Find the truth table for a NAND with four inputs.
3. Find the truth table for an XOR with four inputs (hint - you need three gates in total).

## Working with Multiple Gates

Let us draw the logic circuit for the following:


$$
f = A \lor C \lor ¬B
$$


We will need two 2-in OR gates and one NOT gate (Invertor).

1. **Create a new Gate Diagram.**
2. **Draw the three gates.**
3. **Add three Inputs: A, B and C.**
4. **Wire A and C into a single OR gate**.
5. **Wire the output from this gate into the second OR gate.**
6. **Wire B into the NOT gate.**
7. **Wire the output from the NOT gate into the second OR gate.**
8. **Add an Output F0.**
9. **Wire the output from the second OR gate into F0.**

Your diagram should look something like this:

![Multi-gate Diagram](multi-gate.png)

**Click Submit**, then **Truthtable, Show all rows** to analyse the diagram. It should be the same as:

| A    | B    | C    | =>   | F0   |
| ---- | ---- | ---- | ---- | ---- |
| 0    | 0    | 0    |      | 1    |
| 0    | 0    | 1    |      | 1    |
| 0    | 1    | 0    |      | 0    |
| 0    | 1    | 1    |      | 1    |
| 1    | 0    | 0    |      | 1    |
| 1    | 0    | 1    |      | 1    |
| 1    | 1    | 0    |      | 1    |
| 1    | 1    | 1    |      | 1    |

## Exercises

Implement the following logical expressions and derive their truth tables.

1. $$¬(A \land B) \lor ¬B$$
2. $$(A \land B) \lor ¬(B \land C)$$
3. $$(A \oplus C) \land ¬B$$
4. $$(A \land B \land (C \lor D)) \lor (C \land D)$$
