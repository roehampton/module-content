# Computational Thinking Seminar 03 -- Solving Logical Problems

<script>
MathJax = {
  tex: {
    inlineMath: [['$', '$'], ['\\(', '\\)']]
  },
  svg: {
    fontCache: 'global'
  }
};
</script>
<script type="text/javascript" id="MathJax-script" async
  src="https://cdn.jsdelivr.net/npm/mathjax@3/es5/tex-svg.js">
</script>

**Remember to give a break every hour or so.**

## Review and Recap

Start the session by asking the students to write down the top three things they learned last week. Then ask them to tell the class. Focus on correcting any misunderstandings and reflecting on the key important takeaways.

## Introduction

Cover the three basic logical operators again:

- AND
- OR
- NOT

Then cover implication (IF ... THEN).

Use some example puzzles and ask the students to convert from the statements to symbolic logic:

- If the sun shines today, then it won't shine tomorrow.
  - p = Sun shines today
  - q = Sun shines tomorrow
  - $p \implies \lnot q$
- If I receive a friend request, I will either accept it or reject it.
  - p = I receive a friend request.
  - q = I accept the friend request.
  - r = I ignore the friend request.
  - $p \implies q \lor r$
- Today it will rain or shine, but not both.
  - p = It will rain today.
  - q = It will shine today.
  - $(p \lor q) \land \lnot (p \land q)$
- No shoes, no shirt, no service.
  - p = Has shoes.
  - q = has shirt.
  - r = has service.
  - $(\lnot p \lor \lnot q) \implies \lnot r$
- My sister wants a black and white cat.
  - This one can be interpreted in two ways:
    - p = My sister wants a black and white cat
    - $p$
  - Or
    - p = My sister wants a black cat.
    - q = My sister wants a white cat.
    - $p \land q$

## Truth Tables

Cover the following truth tables:

**AND**

| p    | q    | p $\land$ q |
| ---- | ---- | ----------- |
| T    | T    | T           |
| T    | F    | F           |
| F    | T    | F           |
| F    | F    | F           |

**OR**

| p    | q    | p $\lor$ q |
| ---- | ---- | ---------- |
| T    | T    | T          |
| T    | F    | T          |
| F    | T    | T          |
| F    | F    | F          |

**NOT**

| p    | $\lnot$ q |
| ---- | --------- |
| T    | T         |
| F    | F         |

**IF ... THEN ... (or implication)**

| p    | q    | p $\implies$ q |
| ---- | ---- | -------------- |
| T    | T    | T              |
| T    | F    | F              |
| F    | T    | T              |
| F    | F    | T              |

**XOR (Exclusive Or)**

| p    | q    | p $\oplus$ q |
| ---- | ---- | ------------ |
| T    | T    | F            |
| T    | F    | T            |
| F    | T    | T            |
| F    | F    | F            |

Cover that truth tables can be combined to solve complex logical statements by looking up the meaning in the base tables. e.g.,

$(p \land q) \implies \lnot q$

| $p$  | $q$  | $p \land q$ | $\lnot q$ | $p \land q \implies \lnot q$ |
| ---- | ---- | ----------- | --------- | ---------------------------- |
| T    | T    | T           | F         | F                            |
| T    | F    | F           | T         | T                            |
| F    | T    | F           | F         | T                            |
| F    | F    | F           | T         | T                            |

## Logic Circuits

Just introduce the general idea of how logic circuits are what is inside the computer. They take in a signal (0 or 1 for false or true), and output a 0 or 1 depending on the inputs and the logic circuit. Below are the main logic circuits (except for not).

![img](instrumentationtools.com_digital-logic-gates-truthtables.png)

NAND is NOT AND, so is the inverse of AND. NOR is NOT OR, and XNOR is NOT XOR.

## Lab

Use the logic questions from Numbas. Advise that these form the test.