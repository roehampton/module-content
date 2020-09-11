# Mathematics for Computer Science -- Proof Techniques

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

1. Let $P(n)$ be the proposition that $1 + 2 + 2^2 + \dots 2^n = 2^{n + 1} - 1$ for the integer $n$.

   **BASIS STEP** $P(0)$ is true because $2^0 = 1 = 2^1 - 1$.

   **INDUCTIVE STEP** For the inductive hypothesis, we assumer that $P(k)$ is true. That is, we assume that $1 + 2 + 2^2 + \dots + 2^k = 2^{k + 1} - 1$. To carry out the inductive step using this assumption, we must show that when we assume that $P(k)$ is true, then $P(k + 1)$ is also true. That is, we must show that:

   $1 + 2 + 2^2 + \dots + 2^k + 2{k + 1} = 2^{(k + 1) + 1} - 1 = 2^{k + 2} - 1$

   Under the assumption of $P(k)$, we see that:
   $$
   \begin{aligned}
   1 + 2 + 2^2 + \dots + 2^k + 2^{k + 1} &= (1 + 2 + 2^2 + \dots + 2^k) + 2^{k + 1} \\
   &= (2^{k + 1} - 1) + 2^{k + 1} \\
   &= 2\cdot2^{k + 1} - 1 \\
   &= 2^{k + 2} - 1
   \end{aligned}
   $$
   Because we have completed the basis step and the inductive step, by mathematical induction we know that $P(n)$ is true for all nonnegative integers $n$. That is, $1 + 2 + 2^2 + \dots 2^n = 2^{n + 1} - 1$ for the integer $n$.

2. Let $P(n)$ be the proposition that $n < 2^n$.

   **BASIS STEP** $P(1)$ is true, because $1 \lt 2^1 = 2$.

   **INDUCTIVE STEP** Assume $P(k)$ is true for all positive integers $k$, that is, $k \lt 2^k$ (inductive hypothesis). We need to show that if $k \lt 2^k$, then $k + 1 \lt 2^{k + 1}$. If we add $1$ to both sides of $k \lt 2^k$ we get $k + 1 < 2^k + 1$. This shows that $P(k + 1)$ is true, and thus $k + 1 \lt 2^{k+1}$. As the basis step and inductive step are completed we have proven $n \lt 2^n$ for all positive integers $n$.

3. Let $P(n)$ be the proposition $1^2 + 2^2 + \dots + n^2 = n(n + 1)(2n + 1)/6$.

   **BASIS STEP** $P(1)$ is true as $1^2 = 1 \cdot 2 \cdot 3 / 6 = 6/6 = 1$.

   **INDUCTIVE STEP** We assume that $1^2 + 2^2 + \dots + k^2 = k(k + 1)(2k + 1)/6$ (inductive hypothesis). We want to show that $1^2 + 2^2 + \dots + k^2 + (k + 1)^2 = (k + 1)(k + 2)(2k + 3)/6$.
   $$
   \begin{aligned}
   1^2 + 2^2 + \dots + k^2 + (k + 1)^2 &= k(k + 1)(2k + 1)/6 + (k + 1)^2 \\
   &= (k + 1)/6(k(2k + 1) + 6(k + 1)) \\
   &= (k + 1)/6(2k^2 + 7k + 6) \\
   &= (k + 1)/6(2k^2 + 4k + 3k + 6) \\
   &= (k + 1)(k + 2)(2k + 3)/6
   \end{aligned}
   $$
   As basis step and inductive step are true then $1^2 + 2^2 + \dots + n^2 = n(n + 1)(2n + 1)/6$ is true for all positive integers $n$.

4. Let $P(n)$ be the proposition $1^2 + 3^2 + 5^2 + \dots + (2n + 1)^2 = (n + 1)(2n + 1)(2n + 3)/3$.

   **BASIS STEP** $P(0)$ is true, because $1^2 = 1 \cdot 1 \cdot 3 / 3 = 3 / 3 = 1$.

   **INDUCTIVE STEP** We assume that $1^2 + 3^2 + 5^2 + \dots + (2k + 1)^2 = (k + 1)(2k + 1)(2k + 3)/3$ (inductive hypothesis). We want to show that $1^2 + 3^2 + 5^2 + \dots + (2k + 1)^2 + (2k + 3)^2 = (k + 2)(2k + 3)(2k + 5)/3$.
   $$
   \begin{aligned}
   (1^2 + 3^2 + 5^2 + \dots + (2k + 1)^2) + (2k + 3)^2 &= (k + 1)(2k + 1)(2k + 3)/3 + (2k + 3)^2 \\
   &= (2k + 3)/3((k + 1)(2k + 1) + 3(2k + 3)) \\
   &= (2k + 3)/3((2k^2 + 3k + 1) + (6k + 9)) \\
   &= (2k + 3)/3(2k^2 + 9k + 10) \\
   &= (2k + 3)/3(2k^2 + 4k + 5k + 10) \\
   &= (2k + 3)/3(2k(k + 2) + 5(k + 2)) \\
   &= (k + 2)(2k + 3)(2k + 5)/3
   \end{aligned}
   $$
   As the basis step and inductive step are true, then $1^2 + 3^2 + 5^2 + \dots + (2n + 1)^2 = (n + 1)(2n + 1)(2n + 3)/3$ whenever $n$ is a nonnegative integer.

5. Either:

$$
\begin{aligned}
& \neg(r \lor(q \land(\neg r \implies \neg p))) & \\
\equiv& \neg r \land \neg (q \land (\neg r \implies \neg p)) &\text{ [De Morgan's Law]} \\
\equiv& \neg r \land \neg (q \land (\neg \neg r \lor \neg p)) &\text{ [Conditional Rewritten Disjunction]} \\
\equiv& \neg r \land \neg (q \land (r \lor \neg p)) &\text{ [Double Negation Law]} \\
\equiv& \neg r \land (\neg q \lor \neg (r \lor \neg p)) &\text{ [De Morgan's Law]} \\
\equiv& \neg r \land (\neg q \lor (\neg r \land \neg \neg p)) &\text{ [De Morgan's Law]} \\
\equiv& \neg r \land (\neg q \lor (\neg r \land p)) &\text{ [Double Negation Law]} \\
\equiv& (\neg r \land \neg q) \lor (\neg r \land \neg r \land p) &\text{ [Distributive Law]} \\
\equiv& (\neg r \land \neg q) \lor (\neg r \land p) &\text{ [Idempontent Law]} \\
\equiv& \neg r \land (\neg q \lor p) &\text { [Distributive Law]}
\end{aligned}
$$

Alternatively.

| $p$  | $q$  | $r$  | $\neg p$ | $\neg q$ | $\neg r$ | $\neg r \implies \neg p$ | $q \land (\neg r \implies \neg q)$ | $r \lor (q \land (\neg r \implies \neg q))$ | $\neg (r \lor (q \land (\neg r \implies \neg q)))$ | $\neg q \lor p$ | $\neg r \land (\neg q \lor p)$ |
| ---- | ---- | ---- | -------- | -------- | -------- | ------------------------ | ---------------------------------- | ------------------------------------------- | -------------------------------------------------- | --------------- | ------------------------------ |
| T    | T    | T    | F        | F        | F        | T                        | T                                  | T                                           | F                                                  | T               | F                              |
| T    | T    | F    | F        | F        | T        | F                        | F                                  | F                                           | T                                                  | T               | T                              |
| T    | F    | T    | F        | T        | F        | T                        | F                                  | T                                           | F                                                  | T               | F                              |
| T    | F    | F    | F        | T        | T        | F                        | F                                  | F                                           | T                                                  | T               | T                              |
| F    | T    | T    | T        | F        | F        | T                        | T                                  | T                                           | F                                                  | F               | F                              |
| F    | T    | F    | T        | F        | T        | T                        | T                                  | T                                           | F                                                  | F               | F                              |
| F    | F    | T    | T        | T        | F        | T                        | F                                  | T                                           | F                                                  | T               | F                              |
| F    | F    | F    | T        | T        | T        | T                        | F                                  | F                                           | T                                                  | T               | T                              |

