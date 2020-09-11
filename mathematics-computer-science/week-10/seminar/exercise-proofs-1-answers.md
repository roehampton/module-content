# Mathematics for Computer Science -- Introduction to Mathematical Proofs

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

1. Let's consider $p$ and $q$ are the two odd integers, where $p = 2k + 1$ and $q = 2j + 1$, where $k, j \in Z$. Now, $p + q = (2k + 1) + (2j + 1) = 2k + 2j + 2 = 2(k + j + 1)$. Let $a = k + j + 1$. We know $a \in Z$. Two times any member of $Z$ is even, hence $2a$ is even. Thus, $p + q = 2a$ is even.
2. Let's assume $n = 2k$. Now, $-1^n = -1^{2k} = (-1^2)^k = 1^k = 1$.
3. We know one week is seven days. $7 \cdot 3 = 21$ days, where at least each day of the week occurs three times. The $22^{nd}$ day will also be one of the seven days. Hence, it is proved that at least four days of 22 are the same day.
4. If we multiply both sides by $n \geq 1$ we find $n^2 \geq n$.
5. Let's consider that both $x$ and $y$ are integers. Now, $5(x + 5y) = 1723$, thus $x + 5y = 1723/5$. As 1723 is not divisible by 5, either $x$ or $y$ cannot be an integer.
6. Suppose we have two integers $a$ and $b$ where $a = 2k$ and $b = 2m$, where $k, m \in Z$. Adding the above integers we find $a + b = 2k + 2m = 2(k + m)$. As $k + m \in Z$, $2(k + m)$ will be even.
7. We use direct proof. We can write $a + b = 2k$, or $a = 2k - b$. Also, $b + c = 2m$, or $c = 2m - b$. Now, $a + c = 2k - b + 2m - b = 2(k + m - b)$. As $k + m - b \in Z$, $2(k + m - b)$ is even.
8. We use proof by contradiction. Consider $z = x \cdot y$ or $y = z/x$, where $x$ is a nonzero rational and $y$ is irrational. Now, if we assume $z$ is rational then $y = z/x$ would be rational, which is a contradiction. Hence, the product of a nonzero rational number and an irrational number must be rational.
9. Let's assume that for the given statement $x \geq 1$ and $y \geq 1$ is false. So we can write $x < 1$ and $y < 1$. Now, adding $x$ and $y$ we find $x + y \lt 2$, which is the negation of $x + y \geq 2$. Hence, by contradiction, for $x + y \geq 2$, $x \geq 1$ or $y \geq 1$.
10. Let's assume if $n$ is odd, then $n = 2k + 1$ where $k \in Z$. Now, $n^3 + 5 = (2k + 1)^3 + 5 = 8k^3 + 4k^2 + 6k + 6 = 2(4k^3 + 2k^2 + 3k + 3)$. As any integer multiplied by 2 becomes an even integer, it is proved that $n$ is an even integer for $n^3 + 5$ to be odd.