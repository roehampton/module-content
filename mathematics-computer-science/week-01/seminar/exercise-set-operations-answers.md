# Mathematics for Computer Science - Exercise 2 Set Operations

<script src="https://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-AMS-MML_HTMLorMML" type="text/javascript"></script>

## Answers

1. Perform set operations.
   1. {11, 33, 44}
   2. {11, 33}
   3. {33}
   4. {44}
   5. {44}
2. Prove

| $A$  | $B$  | $\overline{A}$ | $\overline{B}$ | $\overline{A}  \cap \overline{B}$ | $A \cup B$ | $\overline{A \cup  B}$ |
| ---- | ---- | -------------- | -------------- | --------------------------------- | ---------- | ---------------------- |
| 1    | 1    | 0              | 0              | 0                                 | 1          | 0                      |
| 1    | 0    | 0              | 1              | 0                                 | 1          | 0                      |
| 0    | 1    | 1              | 0              | 0                                 | 1          | 0                      |
| 0    | 0    | 1              | 1              | 1                                 | 0          | 1                      |

or
$$
\begin{aligned}
\overline{A \cup B} &= \{x | ¬(x \in A \lor x \in B)\} \\
 &= \{x | ¬(x \in A) \land ¬(x \in B)\} \\
 &= \{x | (x \in \overline{A}) \land (x \in \overline{B}\} \\
 &= \overline{A} \cap \overline{B}
\end{aligned}
$$

3. Bit strings.
   1. {1, 0, 1, 0, 1, 0, 1, 0, 1, 0}
   2. {0, 1, 0, 1, 0, 1, 0, 1, 0, 1}
   3. {1, 1, 1, 1, 1, 0, 0, 0, 0, 0}
   4. {0, 1, 0, 1, 0, 1, 0, 1, 0, 1}