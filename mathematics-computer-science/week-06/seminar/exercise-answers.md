# Mathematics for Computer Science -- Predicate Logic

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

1. As $P(4) = 4^2 < 10$ is false, it follows that $\forall x P(x)$ is false.
2. True.
3. True.
4. As $P(0) = 0 > 0$ is false, it follows that $\forall x P(x)$ is false.
5. $P(x)$ is false for all $x$ in the domain, therefore $\exists x P(x)$ is false.
6. As there is no prime number less than 2, $\exists x P(x)$ is false.
7. True.
8. Quantifiers.
   1. $\exists x (P(x) \land Q(x))$
   2. $\exists x (P(x) \land \neg Q(x))$
   3. $\forall x (P(x) \lor Q(x))$
   4. $\forall x \neg (P(x) \lor Q(x))$
9. Let $P(x)$ be *"$x$ is perfect"*; let $F(x)$ be *"$x$ is your friend"*; and let the domain be all people.
   1. $\forall x \neg P(x)$
   2. $\neg \forall x P(x)$
   3. $\forall x(F(x) \implies P(x))$
   4. $\exists x(F(x) \land P(x))$
   5. $\forall x(F(x) \land P(x))$ or $(\forall xF(x)) \land (\forall xP(x))$
   6. $(\neg \forall xF(x)) \lor (\exists x \neg P(x))$
10. Express the statements.
    1. $\forall x(P(x) \implies Q(x))$
    2. $\exists x (P(x) \land \neg R(x))$
    3. $\exists x (Q(x) \land \neg R(x))$



