---
header-includes:
  - \usepackage{algorithm2e}
---

# Computational Thinking Week 06 Seminar -- Pseudocode

**Remember to give a break every hour or so.**

## Review and Recap

Start the session by asking the students to write down the top three things they learned last week. Then ask them to tell the class. Focus on correcting any misunderstandings and reflecting on the critical essential takeaways.

## Introduction

The point of this seminar is to have students move from visualising computation to writing computation in structured English. This will take students to the point of starting to write programs.

### What is Pseudocode?

Pseudocode is a structured English method of writing what an algorithm does. It provides a stepping stone to programming. There is no standard way of writing pseudocode, so we will use the following:

\begin{algorithm}[H]
\DontPrintSemicolon
\SetAlgoLined
\KwResult{Write here the result}
\SetKwInOut{Input}{Input}\SetKwInOut{Output}{Output}
\Input{Write here the input}
\Output{Write here the output}
\BlankLine
\While{While condition}{
    instructions\;
    \eIf{condition}{
        instructions1\;
        instructions2\;
    }{
        instructions3\;
    }
}
\caption{While loop with If/Else condition}
\end{algorithm} 