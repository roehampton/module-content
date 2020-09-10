# Mathematics for Computer Science -- Further Counting

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

1. There are 101 possible scores on the final from 0 to 100. So for any two students to achieve the same score for sure, 102 students will be needed in the class.
2. If we have four boxes for four different suits from the cards and using generalised Pigeonhold Principle, let's assume we have $N$ selected cards. We can say while selecting three cards from the same suit the selection would be $[N/4]\geq 3$. The smallest integer $N$ is such $N = 2.4 + 1 = 9$. Note, if eight cards are selected then it's possible to have two cards for each suit, so for it to be three cards from the same suit we need at least nine cards.
3. Suppose that we label the workstations $W_1, W_2, ..., W_{15}$, and the servers $S_1, S_2, ..., S_{10}$. Furthermore, suppose we connect $W_k$ to $S_k$ for $k = 1, 2, ..., 10$ and each of $W_{11}, W_{12}, W_{13}, W_{14}$, and $W_{15}$ to all 10 servers. We have a total of 60 direct connections.<br> Clearly any set of 10 or fewer workstations can simultaneously access different servers. We see this by noting that if workstation $W_j$ is included with $1 \leq j \leq 10$ it can access server $S_j$, and for each workstation $W_k$ with $k \geq 11$ included, there must be a corresponding workstation $W_j$ with $1 \leq j \leq 10$ not included, so $W_k$ can access server $S_j$. This follows because ther are at least as many available servers $S_j$ as there are workstations $W_j$ with $1 \leq j \leq 10$ not included. <br> Now suppose there are fewer than 60 direct connections between workstations and servers. Then some server would be connected to at most $59/10 = 5$ workstations. If all servers were connected to at least six workstations, there would be at least $6 \cdot 10 = 60$ direct connections. This means that the remaining nine servers are not enough to allow the other ten workstations to simultaneously access different servers. Consequently, at least 60 direct connections are needed.
4. First we translate each letter of "STOP GLOBAL WARMING" to the corresponding element of $Z_{26}$. This produces the string (18 19 14 15) (6 11 14 1 0 11) (22 0 17 12 8 13 6). We apply the shift $f(p) = (p + 11) \mod{} 26$ to each number in this string to obtain (3 4 25 0) (17 22 25 12 11 22) (7 11 2 23 19 24 17). Translating this back to letters we obtain the ciphertext "DEXA RWZMLW HLCXTYR."
5. To decrypt the ciphertext we first translate the letters back to elements of $Z_{26}$ to obtain (11 4 22 11 24 15 11 20 9 11) (15 25) (7) (13 24 11 7 0) (0 11 7 9 14 11 24). Next we shift each of these numbers by $-k = -7 \mod{} 26$ to obtain (4 23 15 4 17 8 4 13 2 4) (8 18) (0) (6 17 4 0 19) (19 4 0 2 7 4 17). Finally, we translate these numbers back to letters to obtain the plaintext "EXPERIENCE IS A GREAT TEACHER."
6. Because we know that the intercepted cipher text message was encrypted using a shift cipher, we begin by calculating the frequency of letters in the ciphertext. We find that the most common letter in the ciphertext is K. So, we hypothesise that the shift cipher sent the plaintext letter E to the ciphertext letter K. If this hypothesis is correct, we know that $10 = 4 + k \mod{} 26$, and therefore $k =6$. Next, we shift the letters of the message by $-6$, obtaining "THE EARLY BIRD GETS THE WORM." Because this message makes sense, we assume that the hypothesis that $k = 6$ is correct.
7. The integers 17 and 22 have no positive common divisors other than 1, so $gcd(17, 22) = 1$.
8. Because $gcd(10, 17) = 1$, $gcd(10, 21) = 1$, and $gcd(17, 21) = 1$, we conclude that 10, 17, and 21 are pairwise relatively prime. Because $gcd(10, 24) = 2 > 1$, we see that 10, 19, and 24 are not pairwise relatively prime.

