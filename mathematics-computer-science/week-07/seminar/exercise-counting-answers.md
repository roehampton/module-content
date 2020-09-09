# Mathematics for Computer Science -- Counting

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

1. Apply the product rule / sum rule.
   1. If Alex is assigned with an office in twelve ways as there are twelve offices, then Sam can be assigned in eleven ways as $12 - 1 = 11$. As Alex has an office, that is an office Sam cannot have. By the product rule, there are $12 \cdot 11 = 132$ ways to assign offices to the two employees.
   2. Here, there are twenty-six choices for each letter and ten choices for each number. There are three of each type, so we have $26 \cdot 26 \cdot 26 \cdot 10 \cdot 10 \cdot 10 = 17,576,000$.
   3. There are three lists and the student can choose any project from any list. So the number of projects is just the sum of the three lists, $23 + 15 + 19 = 57$.
2. Let's consider the vulnerable to be $A_1$ and the affected to be $A_2$. The people who are either vulnerable of affected will be $A_1 \cup A_2$ and the people who are both vulnerable and affected will be $A_1 \cap A_2$. We need to find $\mid A_1 \cup A_2 \mid - \mid A_1 \cap A_2 \mid$ for the number of people who are either vulnerable, affected, or both. Now, we know $\mid A \cup A_2\mid = \mid A_1 \mid + \mid A_2 \mid - \mid A_1 \cap A_2 \mid$ which is $250 + 50 - 45 = 255$. We subtract this from the total number of people to get our answe $500 - 255 = 245$.
3. The number of ways to pick three prize winners is the number of ordered selections of three elements from a set of 100 elements. That is, the number of 3-permutations of a set of 100 elements. The answer is $P(100, 3) = 100 \cdot 99 \cdot 98 = 970,200$.
4. The number of possible paths between the cities is the number of permutations of seven elements because the first city is determined. The remaining cities can be ordered arbitrarily. Therefore, there are $7! = 7 \cdot 6 \cdot 5 \cdot 4 \cdot 3 \cdot 2 \cdot 1 = 5040$ ways for the salesperson to chose their tour.
5. Because the order in which the five cards are dealt does not matter, there are $C(52, 5) = 52!/5!47!$ different hands of five cards. First, divide the numerator and denomiator by $47!$ to obtain $C(52,5) = (52 \cdot 51 \cdot 50 \cdot 49 \cdot 48)/(5 \cdot 4 \cdot 3 \cdot 2 \cdot 1)$. You can simplify this further by, for example, dividing 50 by 5 to give 10. However, we can see that $C(52, 5) = 311,875,200/120 = 2,598,960$. This is the number of different five-card poker hands that can be dealt from a 52 card deck. Note that $C(52,47) = 52!/47!5! = 52!/5!47! = C(52,5)$. So there are also 2,598,960 possible ways to select 47 cards from a standard deck of 52 cards.
6. The number of ways to select a crew of six from the pool of 30 people is in the number of 6-combinations of a set with 30 elements as the order of people chosen does not matter. The number of such combinations is $C(30,6) = 30!/6!24! = (30 \cdot 29 \cdot 28 \cdot 27 \cdot 26 \cdot 25)/(6 \cdot 5 \cdot 4 \cdot 3 \cdot 2 \cdot 1) = 427,518,000/720 = 593,775$.
7. By the product rule, the answer is the product of the number of 3-combinations of a set with nine elements and the number of 4-combinations of a set with eleven elements. The number of ways to select the committee is $C(9, 3) \cdot C(11, 4) = (9!/3!6!)\cdot(11!/4!7!) = 27,720$.
8. To calculate the probability, note that there are nine possible outcomes, and four of those outcomes produce a blue ball. Hence, the probability that a blue ball is chosen is $4/9$.
9. Let $E_1$ be the event that the integer selected at random is divisible by 2 and let $E_2$ be the event that it is divisible by 5. Then $E_1 \cup E_2$ is the event that it is divisible by either 2 or 5. Also, $E_1 \cap E_2$ is the event that it is divisible by both 2 and 5, or equivelently that it is divisible by 10. Because $\mid E_1 \mid = 50$, $\mid E_2 \mid = 20$, and $\mid E_1 \cap E_2 \mid = 10$, it follows that $p(E_1 \cup E_2) = p(E_1) + p(E_2) - p(E_1 \cap E_2) = 50/100 + 20/100 - 10/100 = 0.5 + 0.2 - 0.1 = 0.6 = 3/5$.
10. Let $E$ be the event that a family with two children has two boys, and let $F$ be the event that a family with two children has at least one boy. It follows that $E = \{BB\}, F = \{BB, BG, GB\}$ and $E \cap F = \{BB\}$. Because the four possibilities are equally likely, it follows that $p(F) = 3/4$ and $p(E \cap F) = 1/4$. We conclude that $p(E \mid F) = p(E \cap F)/p(F) = (1/4)/(3/4) = 1/3$. 

Answers are available [here](exercise-counting-answers).