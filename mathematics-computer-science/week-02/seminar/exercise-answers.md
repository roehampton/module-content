# Mathematics for Computer Science -- Relations

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

## Answers

1. $$R$$ = {(1, 1), (2, 2), (3, 3), (4, 4), (5, 5), (6, 6), (1, 2), (1, 3), (1, 4), (1, 5), (1, 6), (2, 6), (3, 6), (2, 4)}.
2. Relation types
   1. Not reflexive, not symmetric, not antisymmetric, not transitive.
   2. Reflexive, symmetric, not antisymmetric, transitive.
   3. Not reflexive, symmetric, not antisymmetric, not transitive.
   4. Not reflexive, not symmetric, antisymmetric, not transitive.
   5. Reflexive, not symmetric, not antisymmetric, not transitive.
   6. Not reflexive, not symmetric, not antisymmetric, not transitive.
3. {(1, 1), (1, 2), (2, 1), (2, 2)}
4. $$2^{n^2} = 2^{4^2} = 65536$$
5. Relations
   1. $$R_1 \cup R_2$$ = {(a, a), (b, b), (c, c), (a, b), (a, c), (a, d)}
   2. $$R_1 \cap R_2$$ = {(a, a)}
   3. $$R_2 - R_1$$ = {(a, b), (a, c), (a, d)}
   4. $$R_1 \oplus R_2$$ = {(a, b), (a, c), (a, d), (b, b), (b, c)}
6. Matrices.

$$
\begin{aligned}
M_{R_1 \cup R_2} &= M_{R_1} \lor M_{R_2} &=
\begin{bmatrix}
1 & 0 & 1 \\
1 & 1 & 1 \\
1 & 1 & 0
\end{bmatrix} \\
M_{R_1 \cap R_2} &= M_{R_1} \land M_{R_2} &=
\begin{bmatrix}
1 & 0 & 1 \\
0 & 0 & 0 \\
0 & 0 & 0
\end {bmatrix}
\end{aligned}
$$

7. Graphs.

   a. {(a, b), (a, c), (b, c), (c, b)}

   b. {(b, a), (a, c), (c, d), (d, b)}

   c. {(a, a), (b, b), (c, c), (b, a), (a, c), (b, c)}

   d. {(a, a), (b, b), (c, c), (d, d), (a, b), (b, a), (c, a), (c, d)}



