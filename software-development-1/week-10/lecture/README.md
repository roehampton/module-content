# Software Development 1 
# Week 10 --Introduction to fundamental concepts of algorithms

In this lab, we’ll explore:
1. Concept of an algorithm
2. Comparing algorithms
3. Simulation


## Lesson 1: Concept of an algorithm
Video: https://roehampton.cloud.panopto.eu/Panopto/Pages/Viewer.aspx?id=b955ee6f-d1eb-49ca-868d-ac8000a4c19f

One of the central issues that software developers face is the design and analysis of algorithms. On the last session we got a glimpse of a particularly powerful way of thinking about algorithms (recursion) but you probably also use algorithms in your daily life. For instance, when you learned to multiply single-digit numbers, you probably memorized the multiplication table: 100 specific solutions to all the possible combinations. That kind of knowledge is not algorithmic. Instead of memorizing the answers, however, you might have learned a few techniques. For example, to find the product of _n_ and 9, you can write _n-1_ as the first digit and _10-n_ as the second digit. This trick is a general solution for multiplying any single-digit number by 9. That is an algorithm. Similarly, the techniques you learned for addition with carrying, subtraction with borrowing, and long division are all algorithms.

An **Algorithm** is a mechanical process for solving a category of problems. It is a step-by-step procedure, which defines a set of instructions to be executed in a certain order to get the desired output. Some important categories of algorithms in the context of data structures are:




**Searching**  − Algorithms that search an item in a data structure.

**Sorting**  − Algorithms that sort items in a certain order.

**Inserting**  − Algorithms that insert item in a data structure.

**Updating**  − Algorithms that update an existing item in a data structure.

**Deleting**  − Algorithms that delete an existing item from a data structure.




One of the characteristics of algorithms is that they do not require any intelligence to carry out. They are mechanical processes where each step follows from the last according to a simple set of rules. Designing algorithms can be very interesting, intellectually challenging, and a central part of computer science. Algorithms, especially the ones powered by tons of data, are being integrated into our health, economic and social decision-making. If you are interested, I would specially recommend Dr Hannah Fry&#39;s book &quot;Hello World&quot;, in which Dr Fry describes how some of the things that people do naturally, without difficulty or conscious thought, are the hardest to express algorithmically. For instance, most of us understand natural languages (especially our mother tongues), but so far no one has been able to explain _how_ we do it, at least not in the form of an algorithm. Google, Amazon and Apple, using Artificial Intelligence algorithms to power their devices, have tried to tackle this with the word2vec algorithm (or a similar but proprietary technique), which uses a neural network model to learn word associations from a large corpus of text.

Not all procedures can be called an algorithm. An algorithm should have the following characteristics:




**Independent**  − An algorithm should have step-by-step directions, which should be independent of any programming code

**Unambiguous**  − Algorithm should be clear and unambiguous. Each of its steps (or phases), and their inputs/outputs should be clear and must lead to only one meaning.

**Input**  − An algorithm should have 0 or more well-defined inputs.

**Output**  − An algorithm should have 1 or more well-defined outputs, and should match the desired output.

**Feasibility**  − Should be feasible with the available resources.

**Finiteness**  − Algorithms must terminate after a finite number of steps.




There are no well-defined standards for writing algorithms. Rather, it is problem and resource dependent. Algorithms are never written to support a particular programming code. As we know that all programming languages share basic code constructs like loops (for, while), flow-control (if-elif), etc. All these common constructs, which you now know, can be used to write an algorithm.

We write algorithms in a step-by-step manner, but it is not always the case. Algorithm writing is a process and is executed after the problem domain is well-defined. That is, we should know the problem domain, for which we are designing a solution.

Example

Let&#39;s try to learn algorithm-writing by using an example.



**Problem**  − Design an algorithm to add two numbers and display the result.

**step 1** − START

**step 2** − declare three integers **a** , **b** &amp; **c**

**step 3** − define values of **a** &amp; **b**

**step 4** − add values of **a** &amp; **b**

**step 5** − store output of step 4 to **c**

**step 6** − print **c**

**step 7** − STOP



Algorithms tell the programmers how to code the program. We can observe what operations are being used and how the process is flowing. (Writing  **step numbers** is optional). We design an algorithm to get a solution of a given problem. A problem can be solved in more than one ways.

![Alt text](img_problems.png?raw=false "A problem can be solved in more than one ways")


Hence, many solution algorithms can be derived for a given problem. The next step is to analyse those proposed solution algorithms and implement the best suitable solution.

What do the creators of Python have to say on the way it tackles algorithms? In the Zen of Python ( a collection of 19 &quot;guiding principles&quot; for writing computer programs that influenced the design of the Python programming language) it is stated that _&quot;there should be one—and preferably only one—obvious way to do it&quot;_. Unfortunately, sometimes this isn&#39;t obvious. We&#39;ve faced many of these decisions in our journey. Is it better to use a _for_ or a _while_ loop? Do we want things to be faster, or easier to understand?


Zen of Python: https://www.python.org/dev/peps/pep-0020/




## Lesson 2: Comparing algorithms
Video: https://roehampton.cloud.panopto.eu/Panopto/Pages/Viewer.aspx?id=a9eb2013-ad49-40da-a390-ac8000a4c1d1

Let&#39;s consider a very common and well-studied programming problem: searching. Searching is the process of looking for a particular value in a collection. You may recall from our discussion of list operations that Python actually provides a number of built-in search-related methods. For example, we can test to see if a value appears in a sequence using in:

    if x in nums:
     #do something

If we want to know the position of x in a list, we can simply use the index method:

    nums = [3,1,4,2,5]

    nums.index(4)

We could implement search using index by simply catching the exception and returning -1 for that case:


    def search(x, nums):
    #nums is a list of numbers and x is a number
        try:
            return nums.index(x) 
     #Returns the position in the list where x occurs or -1 if 
        # x is not in the list.   
        except:
            return - 1

    search(4, [3, 1, 4, 2, 5])
    
    
    nums = [3,1,4,2,5]  
    nums.index(4)


The question here is how does Python actually search the list? What is the algorithm? Lets compare some different search strategies:

Linear Search: suppose that I gave you a page full of numbers in no particular order and asked whether the number 6 is in the list. We can simply scan down the list comparing each value to 6 and, when we see 6 in the list, we stop and report the result. If we get to the very end of the list without seeing 6, then we report it&#39;s not there. This strategy is called a linear search. You are searching through the list of items one by one until the target value is found. This algorithm translates directly into simple code:



    def lin_search(x, nums):
    for i in range(len(nums)):
         if nums[i] == x: #item found, return the index value .
            return i
    return -1 #loop finished, item was not in list
    
    
    lin_search(7, [3, 1, 4, 2, 5])

This algorithm was not hard to develop, and it will work very nicely for modest-sized lists. For an unordered list, this algorithm is as good as any. The Python in and index operations both implement linear searching algorithms. If we have a very large collection of data, however, we might want to organize it in some way so that we don&#39;t have to look at every single item to determine where, or even if, a particular value appears in the list. Suppose that the list is stored in sorted order (lowest to highest). As soon as we encounter a value that is greater than the target value, we can quit the linear search without looking at the rest of the list. On average, that saves us about half of the work. But if the list is sorted, we probably could do better.

Binary Search: When a list is ordered, we can use a much better searching strategy, which we have already used. In Seminar 7 we made a program that picks a number between 1 and 20, and you try to guess what it is. Each time you guess, it tells you whether your guess is correct, too high, or too low. What was your strategy? Some adopted a strat­egy of simply guessing numbers at random. Others employed a systematic approach corresponding to linear search, guessing 1, 2, 3, 4, . . . until the mystery value was found. Logically, however, your first guess should be the middle value 10. If told that the number is higher, then the range of possible values is 11-20. The next logical guess is 15. Each time we guess the middle of the remaining numbers to try to narrow down the possible range. This strategy is called a binary search. Binary means &quot;two,&quot; and at each step, we are dividing the remaining numbers into two parts.

We can employ a binary search strategy to look through a sorted list. The basic idea is that we use two variables to keep track of the endpoints of the range in the list where the item could be. Initially, the target could be anywhere in the list, so we start with variables low and high set to the first and last positions of the list, respectively. The main structure of the algorithm is a loop that looks at the item in the middle of the remaining range to compare it to x. If x is smaller than the middle item, then we move high, so that the search is narrowed to the lower half. If x is larger, then we move low, and the search is narrowed to the upper half. The loop terminates when x is found or there are no longer any more places to look.



    def bin_search(x, nums): 
    low= 0
    high= len(nums) - 1 
    while low <= high: #There is still a range to search 
        mid= (low + high)//2 #position of middle item
        item= nums[mid]
        if x== item : #Found it! Return the index
            return mid 
        elif x < item:  #x is in lower half of range
            high = mid - 1 # move top marker down
        else:  #x is in upper half
            low = mid + 1 # move bottom marker up
    return -1 #no range left to search, x is not there
    
    
    bin_search(4, [ 1, 2, 3, 4, 5, 6, 7, 8])
    
    

This algorithm is more sophisticated than the simple linear search. Which one is better? The linear search algorithm is much easier to understand and implement. On the other hand, we expect that the binary search is more efficient, because it doesn&#39;t have to look at every value in the list. Intuitively, then, we might expect the linear search to be a better choice for small lists and binary search a better choice for larger lists. How could we actually confirm such intuitions?

Computer scientists attack these problems by analysing the number of steps that an algorithm will take relative to the size or difficulty of the specific problem instance being solved. For searching, the difficulty is determined by the size of the collection. Obviously, it takes more steps to find a number in a collection of a million than it does in a collection of ten. The pertinent question is &quot;How many steps are needed to find a value in a list of size n?&quot; We are particularly interested in what happens as n gets very large.

Let&#39;s consider the linear search first. If we have a list of ten items, the most work our algorithm might have to do is to look at each item in turn. The loop will iterate at most ten times. Suppose the list is twice as big. Then it might have to look at twice as many items. If the list is three times as large, it will take three times as long, etc. In general, the amount of time required is linearly related to the size of the list n. This is what computer scientists call a linear time algorithm, why this method is called a linear search.

What about the binary search? Let&#39;s start by considering a concrete example. Suppose the list contains sixteen items. Each time through the loop, the remaining range is cut in half. After one pass, there are eight items left to consider. The next time through there will be four, then two, and finally one. How many times will the loop execute? It depends on how many times we can halve the range before running out of data:


![Alt text](img_bisection.png?raw=false "some problems can be halved")


Can you see the pattern here? Each extra iteration of the loop doubles the size of the list. If the binary search loops _i_ times, it can find a single value in a list of size _2i_. Each time through the loop, it looks at one value (the middle) in the list. To see how many items are examined in a list of size n, we need to solve this relationship: _n = 2 <sup>i</sup>_ for _i_ (_i_ is an exponent with a base of 2). Using the appropriate logarithm gives us this relationship: _i = log<sub>2</sub> n_. This is the number of times that a collection of size _n_ can be cut in half. This an example of a log time algorithm : the amount of time it takes to solve a given problem thus grows as the logarithm of the problem size. In the case of binary search, each additional iteration doubles the size of the problem that we can solve.
#

Can you appreciate just how efficient binary search really is? Let&#39;s put it in perspective. If we look at the Roehampton University registry, we have over 8000 names listed in alphabetical order. You could walk up to anyone registered in campus and propose to try to guess their name. Each time you guess a name, they only have to tell you whether their name comes alphabetically before or after the name your guessed. How many guesses will you need? Our analysis above shows the answer to this question is log <sub>2</sub> 8000:

2<sup>10</sup> = 1024

2<sup>3</sup> = 8

2<sup>10</sup> x 2<sup>3</sup> = 1024 x 8 = 8192 = 2<sup>13</sup>

So searching 8 thousand items requires only 13 guesses. Let&#39;s upscale. Imagine you have access to the registry of UK&#39;s TikTok users (8.5 million UK users) and you ask the same question. This is log2 8,500,000:


2<sup>10</sup> x 2<sup>10</sup> x 2<sup>3</sup> = 1024 x 1024 x 8 = 8,388,608= 2<sup>23</sup>

So searching 8 million items requires only 23 guesses! With only one guess more (24 guesses) we can search among 16 million names. By comparison, a linear search would require around 6 million guesses.

Python uses a linear search algorithm to implement its built-in searching methods. You might why doesn&#39;t Python use a binary search instead? The reason is that the binary search is less general: in order to work, the list must be in order. If you want to use binary search on an unordered list, the first thing you have to do is put it in order or sort it (which is another important problem in computer science).

The takeaway is that, when it comes to algorithms, you need to compare alternatives. The key thing to note here is that the basic idea behind the binary search algorithm is to successively divide the problem in half. This is sometimes referred to as a &quot;divide and-conquer&quot; approach to algorithm design, and it often leads to very efficient algorithms. The important aspect of divide-and-conquer algorithms is that the original problem divides into subproblems that are just smaller versions of the original: it is recursive problem solving.



## Lesson 3: Simulation
Video: https://roehampton.cloud.panopto.eu/Panopto/Pages/Viewer.aspx?id=82480190-7002-4ddd-94aa-ac8000a4c179


It may not feel like it, but you have reached a milestone in the jour­ney to becoming a computer scientist. You now have all the tools to write pro­grams that solve interesting problems: problems that would be difficult or impossible to solve without the ability to write and imple­ment computer algorithms, what we know as **nontrivial computing**. One particularly powerful technique for solving real-world problems is **sim­ulation**. Computers can be used to model real-world processes to provide otherwise unob­tainable information. You may know some of these applications: predicting the weather, designing vehicles, creating special effects for movies, video game scenarios, cancer research, phycological testing and much much more. Some of these may sound like very complex algorithms, but the trick is that the right abstraction and modest implementation is what most of the times sheds the most light on tricky problems. There are many ways you can design an algorithm that will tackle a real-world problem. Design is a combination of art and science and practice is the best way to become a better designer. Our own Dr Kevin Chalmers has admitted that computer science, and especially software development, can be considered as a craft. In the future we will explore some of these implementations, like top-down and bottom-up approaches to problem solving.

A **top-down approach** , as its name suggests, starts with the big picture. It breaks down from there into smaller segments. For instance, if you are modelling checkers, you start by defining the problem, like designing the board, and then move to the next level down: the procedures, the pieces and how they interact.

A **bottom-up approach** is the piecing together of systems to give rise to more complex systems, thus making the original systems sub-systems of the emergent system. For instance, if you know the behaviour of one bird and want to know how birds act together, you design just the one bird that avoids crowding neighbours, steers towards average heading of neighbours and steer towards average position of neighbours. We can let if &quot;fly&quot; towards a random direction if we import the random function (simulation techniques that rely on chance events are known as Monte Carlo simulations) Would you be able to predict what it is going to do if let alone? What do you think will happen when 2 of these are let loose on the screen? What about 3? 100? 1000? We start threading into the unknown. This is where &quot;science&quot; in computer science comes in.

To make sense of results from simulations, we use **the scientific method** : an empirical method of acquiring knowledge that has characterized the development of science since. Since the 17th century, we have accepted that cognitive assumptions and our own biases can distort how one interprets observations. By making careful observations and applying rigorous scepticism about our observations or data, we can formulate hypotheses. We can summarise the scientific method with the following flowchart:

![Alt text](img_scientific.png?raw=false "The scientific method")


We humans are naturally curious, and everyday new questions about our world are in need of answering. The best hypotheses lead to predictions that can be tested in various ways, and us computer scientists can use our skills to tackle many of today&#39;s pressing questions (including the best way to tackle an epidemic)

It involves formulating hypotheses (via induction) based on such observations, experimental and measurement-based testing of deductions drawn from the hypotheses, and refinement (or elimination) of the hypotheses based on the experimental findings. These are principles of the scientific method, as distinguished from a definitive series of steps applicable to all scientific enterprises. We will be using this to tie everything we have seen so far to make original contributions to the world in the next session.


FIN
