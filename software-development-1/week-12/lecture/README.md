## Lesson 12: The road ahead…
Video: https://roehampton.cloud.panopto.eu/Panopto/Pages/Viewer.aspx?id=74748ce6-b733-4c71-8519-ac8700b404e4

The goal of this course was always to show you enough Python to get you up to speed as quickly as possible. There is still a lot more to cover. Not all of these will be key to you, but if you find any of these interesting, I would encourage you to pursue them.

#
**Virtual Programming Environments**

A virtual environment lets you create a new, clean Python environment

within which you can run your code. You can install third-party modules into

one virtual environment without impacting another, and you can have as many virtual environments as you like on your computer, switching between them by activating the one you want to work on.

For instance, if you are working with two collaborators or clients, one with Python code that relies on one version of a third-party module, and another that relies on a _different_ version of the same third-party module for their code, you might struggle to to maintain both projects&#39; code. This is where Virtual environments come in handy. Each virtual environment can maintain its own copy of whatever third-party modules you wish to install, you can use two different virtual environments, one for each of your client projects discussed above.

Before doing so, however, you have to make a choice: use the virtual environment technology, called _venv_, that is included with Python 3&#39;s standard library, or install the _virtualenv_ module from PyPI (which does the same thing as venv, but has more bells and whistles). It&#39;s best if you make an informed choice.

To learn more about venv, check out its documentation page: https://docs.python.org/3/library/venv.html

To find out what virtualenv offers over and above venv, start here: https://pypi.org/project/virtualenv/

#
**More from the Standard Library**

Python&#39;s _standard library_ is full of goodness. It&#39;s always a worthy exercise to take 20 minutes every once in a while to review what&#39;s available, starting at the official documentation (your most trustworthy source of knowledge):

https://docs.python.org/3/library/index.html 

If what you need is in the _standard library_, don&#39;t waste your precious time rewriting
 it. Use (and/or extend) what&#39;s already available. In addition to the Python docs, _Doug Hellmann_ has ported his popular _Module of the Week_ material over to Python 3. Find Doug&#39;s excellent material here:

https://pymotw.com/3/ 

#
**GUIs with Tkinter**

Python comes with a complete library called tkinter (the _Tk interface_) for building cross-platform GUIs. It comes preinstalled and ready for use with almost every Python installation.

An interesting part of this is the turtle module (which is also part of the _standard library_). According to the Python docs: _Turtle graphics is a popular way for introducing programming to kids. It was part of the original Logo programming language developed by Wally Feurzig and Seymour Papert in 1966_. Programmers (i.e., mainly kids, but fun for newbies, too) can use commands like left, right, pendown, penup, and so on to draw on a GUI canvas (provided by tkinter).

Try for instance a small program from the turtle docs:

    from turtle import *

    color("purple", "cyan")
    begin_fill()

    while True:
        forward(200)
        left(170)
        if abs(pos()) < 1 :
            break

    end_fill()
    done()

#
**IDEs**

An IDE (integrated development environment) is an application that provides most of the things you need for software development. It normally consists of a source code editor, build automation tools and a debugger. Some IDEs, such as NetBeans and Eclipse, contain the necessary compiler, interpreter, or both; We have been using a web-based IDE, the Jupyter notebook. Depending on your professional needs, you may use an IDE different from Anaconda. The most popular in the Python space at the moment are:

_Eclipse_: https://www.eclipse.org 

_and PyCharm_: https://www.jetbrains.com/pycharm/ 

_Eclipse_ is a completely open-source technology, so won&#39;t cost you more than the download. _PyCharm_ is a commercial product with &quot;community versions&quot; available for download at no cost (but with some restrictions). Unlike _Eclipse_, which targets many programming languages, _PyCharm_ target Python programmers specifically and, like all IDEs, have great support for project work, links to source code management tools (like _git_), support for teams, links to the Python docs, and so on. We encourage you to try both, then make your choice.

#
**Data Science**

Python&#39;s adoption and usage came about by the world of **data science** : the one domain that continues to experience explosive growth. The tools available to data scientists using Python are top-class (used by academics and the industry as the standard in data science). There are libraries and modules readily available to you if you are interested in data science (or any other scientificendeavours, for that matter).

**bokeh** : A set of technologies for publishing interactive graphics on web pages: https://docs.bokeh.org/


**matplotlib** : A comprehensive set of graphing modules (which integrates with ipython and _Jupyter Notebook_): https://matplotlib.org/


**numpy** : Among other things, allows you to efficiently store and manipulate multidimensional data (matrices): https://numpy.org/


**scipy** : A set of scientific modules optimized for numerical data analysis, which complements and expands upon what&#39;s provided by numpy: https://www.scipy.org/


**pandas** : Pandas is a _killer_ Python application. It provides optimized analysis data structures and tools (and is built on top of numpy and matplotlib). The need to use pandas is what brings a lot of data folk to the community: https://pandas.pydata.org/


**scikit-learn** : A set of machine learning algorithms and technologies implemented in Python: https://scikit-learn.org/


One of the best place to start learning about the intersection of Python and _data science_ is the _PyData_ website: http://pydata.org

Click on _Downloads_, then marvel at what&#39;s available (all as open source). Have fun!

#
**The Python Community**

One of the best things about Python is how friendly and inclusive the Python community is. Check out: https://www.python.org/community/


A lot of this attitude perhaps stems from Python&#39;s creator Guido van Rossum, for which he was the &quot;Benevolent dictator for life&quot; (BDFL) of the Python community until he stepped down in July 2018. _Naomi Ceder,_ another inspirational figure in the Python community, gave a seminaltalk at _EuroPython,_ surveying a life in Python and discussing how the community supports diversity, and how there&#39;s always more work for everyone to do. It is worth a watch:

https://www.youtube.com/watch?v=cCCiA-IlVco 

As you can imagine, Python means many things to different people. Many moons ago, Tim Peters, a major contributor to the original Python programming language, sat down and wondered: _what is it that makes Python Python?_ He wrote down his thoughts in _The Zen of Python_, which we have briefly discussed throughout the course. I&#39;d recommend you take frequent looks at it by inputting:

    import this

Python is the status quo at the moment, but it wasn&#39;t when I was learning to program, and it might not be in 20 years from now, but what you&#39;ve learned here is not Python. You&#39;ve learned the fundamental constructs of programming language, any programming language. We&#39;ve given you the foundations on which to build whatever it is that you like. You can build many small software architectures, or devote your entire life to building a software cathedral. Coding is becoming a standard for many jobs, but I hope we&#39;ve also encouraged you to create your own fortune. Find what your interests are, start small, be consistent and get good at it. Like in martial arts, it&#39;s all about practice and keeping up your good style. Many programmers use code kata as daily programming exercises which can help you hone your skills through practice and repetition. If you want to know more about this concept, I recommend the book &quot;The Pragmatic Programmer&quot; by Andrew Hunt and David Thomas.

It&#39;s good to have a good job in a competitive market, but there&#39;s nothing to stopping you from creating an entire new market. I find that computer science can give you a lot of freedom to choose how you want to spend your time. My final advice is to stay curious. The world is changing at such a pace that sometimes is hard for us to comprehend. People talk a lot about the economic tide, but like all the things we&#39;ve learned this year, that is a human construct, constantly changing and evolving. The only skill that you need to make it, the only skill that you&#39;ve always needed is just learning how to learn. Whatever the world needs from you, you&#39;ll just need to learn how to provide it, and what you need from the world, you&#39;ll just need to learn how to ask for it. I commend you for taking a step into what I&#39;m sure is going to be a great adventure, and if you ever feel like a beginner trying to understand a bigger idea, then do not panic. That means you are in the right track. This first step is to being bad at it. Just make sure you are moving forward, that you are less bad at it every day, and then one day you realize you are just better at it. Give it time and effort (you can&#39;t complain about the things you didn&#39;t get with the effort you didn&#39;t put). Go forth and do Computer Science.

FIN

