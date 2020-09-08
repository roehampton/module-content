# Mathematics for Computer Science -- Functions

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

1. $\{01, 11, 10, 00, 11\} = \{00, 01, 10, 11\}$
2. $\{0, 1, 4, 9, 16, 25, ...\}$
3. No, it's not a one-to-one function. For example, if we consider integer values 1 and -1 from the domain of all integers, their corresponding range values are $f(1) = 1^2 + 2 = 3$ and $f(-1) = -1^2 + 2 = 3$, and these are the same values from the codomain. As one-to-one functions must have a distinct codomain value designed for each of the domain instances, the function is not one-to-one.
4. The function is onto because for every integer $y$ there is an integer $x$ such that $f(x) = y$. To sett this, not that $f(x) = y$ if and only if $x + 1 = y$.
5. Invertible functions
   1. Has an inverse because the function is a one-to-one correspondance. To reverse the correspondance, suppose that $y$ is the image of $x$, so that $y = x + 1$. This means that $y - 1$ is the unique element of $Z$ that is sent to $y$ by $f$. Consequently, $f - 1 (y) = y - 1$
   2. It is not invertible because $f(-2) = f(2) = 4$, so $f$ is not one-to-one. If an inverse function were defined, it would have to assigne two elements to 4. Hence, $f$ is not invertible.
6. Find values.
   1. 1
   2. -1
   3. 3
   4. -10
   5. -2
   6. 3
   7. -6
   8. 1
   9. 1
   10. 2
7. The composition $f \circ g$ is defined by $(f \circ g)(a) = f(g(a)) = f(b) = 2$, $(f \circ g)(b) = f(g(b)) = f(c) = 1$, and $(f \circ g)(c) = f(g(c)) = f(a) = 3$. Note that $g \circ f$ is not defined because the range of $f$ is not a subset of the domain of $g$.
8. Find function.

$$
\begin{aligned}
(f - h)(x) &= f(x) - f(x) \\
&= (5x^2 + 2x - 5) - (4x^2 - 10) \\
&= 5x^2 + 2x - 5 - 4x^2 + 10 \\
&= x^2 + 2x + 5
\end{aligned}
$$



