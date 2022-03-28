# Software Development 2 Seminar 10 -- Regular Expressions and State Machines

<script src="https://cdn.jsdelivr.net/npm/mermaid/dist/mermaid.min.js"></script>

In this seminar, the aim is for students to understand regular expressions through state machines. This will require students to draw state machines that represent a regular expression.

## Review

Start by refreshing students' knowledge of state machines. Ask them what a state machine is, and ensure you cover the following:

- What is a state?
- What is a state transition?
- What is a start state?
- What is an end state?

Now remind students that state machines can be used to model what inputs a system can accept. For example, use the following state machine:

<div class=mermaid>
stateDiagram-v2
	direction LR
	[*] --> s0
	s0 --> s0 : 0
	s0 --> s1 : 1
	s1 --> s1 : 1
	s1 --> s0 : 0
	s1 --> [*]
</div>

This state machine will only accept binary strings that end in one. If a zero is entered, then the machine won't accept a stop state and until a one is entered again.

## Accepting Strings

Now ask the students to create a state machine that will accept their names. This should be fairly simple, as demonstrated below:

<div class=mermaid>
stateDiagram-v2
	direction LR
	[*] --> s0
	s0 --> s1 : K
	s1 --> s2 : e
	s2 --> s3 : v
	s3 --> s4 : i
	s4 --> s5 : n
	s5 --> [*]
</div>

**Now ask the students to define a state machine that will accept their age.**

## Regular Expressions

Describe what a regular expression is in general -- a pattern matching string. For example, we can write the following:

```
ac+|bd
```

This regular expression accepts:

- `a` followed by one or more `c`, OR
- `b` followed by `d`.

We can draw this as the following state machine:

<div class=mermaid>
stateDiagram-v2
    direction LR
	[*] --> s0
	s0 --> s1 : a
	s1 --> s2 : c
	s2 --> s2 : c
	s2 --> [*]
	s0 --> s3 : b
	s3 --> s4 : d
	s4 --> [*]
</div>

To accept a string that starts with an uppercase `K`, we would define the following regular expression:

```
^K.*
```

- `^K` means starts with a `K`.
- `.*` means accept zero or more of any character.

**Have the students draw this as a state machine. Below is the answer:**

<div class=mermaid>
stateDiagram-v2
	direction LR
	[*] --> s0
	s0 --> s1 : K
	s1 --> s1 : .
	s1 --> [*]
</div>

**Next, have students create the state machine for the following regular expression:**

```
a(b*|c)d
```

Below is the answer:

<div class=mermaid>
stateDiagram-v2
	direction LR
	[*] --> s0
	s0 --> s1 : a
	s1 --> s2 : b
	s2 --> s2 : b
	s2 --> s4 : d
	s1 --> s3 : c
	s1 --> s4 : d
	s3 --> s4 : d
</div>

## Simplifying State Machines

In the following example, have the students help simplify the state machine that accepts `last`, `list`, or `lost`. The starting state machine is:

<div class=mermaid>
stateDiagram-v2
	direction LR
	[*] --> s0
	s0 --> s1 : l
	s1 --> s2 : a
	s2 --> s3 : s
	s3 --> s4 : t
	s4 --> [*]
	s0 --> s5 : l
	s5 --> s6 : i
	s6 --> s7 : s
	s7 --> s8 : t
	s8 --> [*]
	s0 --> s9 : l
	s9 --> s10 : o
	s10 --> s11 : s
	s11 --> s12 : t
	s12 --> [*]
</div>

We can simplify the start by merging on `l`:

<div class=mermaid>
stateDiagram-v2
	direction LR
	[*] --> s0
	s0 --> s1 : l
	s1 --> s2 : a
	s2 --> s3 : s
	s3 --> s4 : t
	s4 --> [*]
	s1 --> s5 : i
	s5 --> s6 : s
	s6 --> s7 : t
	s7 --> [*]
	s1 --> s8 : o
	s8 --> s9 : s
	s9 --> s10 : t
	s10 --> [*]
</div>

Then merging on `t`:

<div class=mermaid>
stateDiagram-v2
	direction LR
	[*] --> s0
	s0 --> s1 : l
	s1 --> s2 : a
	s2 --> s3 : s
	s3 --> s4 : t
	s4 --> [*]
	s1 --> s5 : i
	s5 --> s3 : s
	s1 --> s6 : o
	s6 --> s3 : s
</div>

And finally merging the centre, using the choice `{ a | i | o }`

<div class=mermaid>
stateDiagram-v2
	direction LR
	[*] --> s0
	s0 --> s1 : l
	s1 --> s2 : {a | i | o}
	s2 --> s3 : s
	s3 --> s4 : t
	s4 --> [*]
</div>

## Exercises

Depending on the time available, work on the following regular expressions:

- Phone number.
- Email address.
- Post code.

Have the students work in groups to see if they can solve the regular expression. Introduce other parts of regular expressions as needed.

