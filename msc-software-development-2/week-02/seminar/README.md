# Software Development 2 Seminar 02 -- Task Management with Kanban + getting started with your group

## Overview of Kanban

Kanban is a Japanese word (看板) meaning signboard or billboard.  This doesn't tell us much on its own.  Boards we will discuss later, but they are only part of the Kanban idea.

Kanban is often referred to as a *supermarket method*.  It works in a similar manner to how a supermarket sells goods to a customer.

- Customer buys goods from a shelf.
- Supermarket notices shelf becoming empty, restocks shelf from local storage.
- Local storage starts to become empty, initiating a delivery from regional storage (or similar).
- Regional storage starts to become empty, initiating a purchase from a supplier.
- Supplier runs low on product, and produces more to meet demand.

At no point is the supermarket purchasing or storing more than necessary to meet customer demand.  The supplier is also not producing more product than demand dictates.  The inventory in the system meets demand.  Goods are pulled through the system based on the purchasing of a customer.

This technique is used in a number of industries around the world, and is often referred to as **Just in Time (JiT) manufacturing**.  There are a number of reasons to work like this, some of the big ones being:

- organisations do not store inventory, which costs money to store.

- organisations do not store levels of inventory which are no longer saleable.
- organisations produce goods quickly to meet demand from customers.

Toyota are seen as the key developers of Kanban-like systems.  You can read Toyota's view [here](https://www.toyota-global.com/company/vision_philosophy/toyota_production_system/just-in-time.html).  These methods revolutionised the manufacturing industry in the 1980s, changing from slow storage-based methods to lean, Just-in-Time manufacturing processes.  The following image (taken from [Wikipedia](https://en.wikipedia.org/wiki/Kanban)) illustrates how Kanban can be viewed from a manufacturing point of view:

<p><a href="https://commons.wikimedia.org/wiki/File:Kanban_principles.svg#/media/File:Kanban_principles.svg"><img src="https://upload.wikimedia.org/wikipedia/commons/thumb/a/ab/Kanban_principles.svg/1200px-Kanban_principles.svg.png" alt="Kanban principles.svg"></a><br>By <a href="//commons.wikimedia.org/wiki/File:Kanban_principles.jpg" title="File:Kanban principles.jpg">Kanban_principles.jpg</a>: Jean-Baptiste Waldner
derivative work: <a href="//commons.wikimedia.org/wiki/User:Jbarta" title="User:Jbarta">Jbarta</a> - This file was derived from:&nbsp;<a href="//commons.wikimedia.org/wiki/File:Kanban_principles.jpg" title="File:Kanban principles.jpg">Kanban principles.jpg</a>:&nbsp;<a href="//commons.wikimedia.org/wiki/File:Kanban_principles.jpg" class="image"></a>, <a href="https://creativecommons.org/licenses/by-sa/2.5" title="Creative Commons Attribution-Share Alike 2.5">CC BY-SA 2.5</a>, <a href="https://commons.wikimedia.org/w/index.php?curid=24883253">Link</a></p>


### The Kanban Card

Kanban is well known for using cards.  In a manufacturing environment, a card is a message that informs that a certain material or product needs replaced.  When a material or product is consumed from its location, the card from that location is placed upstream (for example, to a table or board).  At a certain point, when the upstream location is full, new materials or products are sourced and the cards returned downstream.  It seems simple -- and it is -- but this basic concept revolutionised the manufacturing process to being more on-demand based.


### Limiting Work-in-Progress (WiP)

Work-in-Progress is a key concept in Kanban. Kanban is popular in software development as it allows us to limit WiP.  In manufacturing, we only produce inventory as items are required.  We stop doing work just to do work.


## Kanban in Software Development

The lean movement in software development has taken inspiration from the numerous lean manufacturing principles in general.  Kanban is perhaps the most well known as it provides a visual tool.  This is a key principle of DevOps where we want to **make work visible**.

Kanban in software development appears to have evolved from Microsoft in the 2000s.  There have been several books on Kanban in software development, but the principles have been applied to other sectors such as human resources, marketing, and general service management.  The key concept that always appears is the Kanban board, which has been used in various forms.

### Kanban Board

In simple terms, a Kanban board is a set of columns that have Kanban cards in them.  Below is a simple Kanban board.

<p><a href="https://commons.wikimedia.org/wiki/File:Simple-kanban-board-.jpg#/media/File:Simple-kanban-board-.jpg"><img src="https://upload.wikimedia.org/wikipedia/commons/d/d3/Simple-kanban-board-.jpg" alt="Simple-kanban-board-.jpg" height="382" width="640"></a><br>By <a href="//commons.wikimedia.org/w/index.php?title=User:Jeff.lasovski&amp;action=edit&amp;redlink=1" class="new" title="User:Jeff.lasovski (page does not exist)">Jeff.lasovski</a> - <span class="int-own-work" lang="en">Own work</span>, <a href="https://creativecommons.org/licenses/by-sa/3.0" title="Creative Commons Attribution-Share Alike 3.0">CC BY-SA 3.0</a>, <a href="https://commons.wikimedia.org/w/index.php?curid=19121595">Link</a></p>

This is the simplest form of Kanban board, and is used in many places.  We have three columns:

- a **To Do** column which contains cards that need to be worked on.
- a **Doing** column which contains cards currently being worked on.
- a **Done** column which contains cards where the work is completed.

Remember the roots of Kanban from manufacturing.  The cards will be pulled through the system based on capacity and need.  The aim with a Kanban board is to simulate a value stream.  Below is a more detailed Kanban board.

<p><a href="https://commons.wikimedia.org/wiki/File:Kanban_board_example.jpg#/media/File:Kanban_board_example.jpg"><img src="https://upload.wikimedia.org/wikipedia/commons/f/f5/Kanban_board_example.jpg" alt="Kanban board example.jpg" height="480" width="581"></a><br>By <a href="//commons.wikimedia.org/w/index.php?title=User:Dr_ian_mitchell&amp;action=edit&amp;redlink=1" class="new" title="User:Dr ian mitchell (page does not exist)">Dr ian mitchell</a> - <span class="int-own-work" lang="en">Own work</span>, <a href="https://creativecommons.org/licenses/by-sa/2.5" title="Creative Commons Attribution-Share Alike 2.5">CC BY-SA 2.5</a>, <a href="https://commons.wikimedia.org/w/index.php?curid=20245783">Link</a></p>

This board tries to model a software production value stream:

- **backlog** is our product or Spring backlog.
- **in progress** is the work currently being done.
- **peer review** is tasks requiring a review from another member of the team.
- **in test** is tasks that need tested.
- **done** is the completed tasks.
- **blocked** is tasks that are blocked for some reason.

Also notice the numbers in column titles.  This is our card limit for that column, or the WiP limit.  The column should not have more cards than this number.

Kanban boards can be more detailed still.  Below is a final example:

<p><a href="https://commons.wikimedia.org/wiki/File:Sample_Kanban_Board.png#/media/File:Sample_Kanban_Board.png"><img src="https://upload.wikimedia.org/wikipedia/commons/thumb/c/c2/Sample_Kanban_Board.png/1200px-Sample_Kanban_Board.png" alt="Sample Kanban Board.png"></a><br>By <a href="//commons.wikimedia.org/w/index.php?title=User:Andycarmichaeluk&amp;action=edit&amp;redlink=1" class="new" title="User:Andycarmichaeluk (page does not exist)">Andy Carmichael</a> - <span class="int-own-work" lang="en">Own work</span>, <a href="https://creativecommons.org/licenses/by-sa/4.0" title="Creative Commons Attribution-Share Alike 4.0">CC BY-SA 4.0</a>, <a href="https://commons.wikimedia.org/w/index.php?curid=55448101">Link</a></p>


## Tools

Kanban has seen the rise of a number of tools.  Really, most of these tools just provide task boards which are in themselves not enough for Kanban.  Scrum for example defines task boards.  However, we've put these under the Kanban tool banner as this is how people generally view them.

- **GitHub Projects** provides a view of your issues in a task board style.  There is also automation of issue status based on the column a card is placed.
- **Jira** provides a fairly substantial Kanban solution (see [here](https://www.atlassian.com/agile/tutorials/how-to-do-kanban-with-jira-software) for a tutorial).  Jira is a large issue tracking piece of software, so works in a manner similar to GitHub under the hood.
- **Trello** is perhaps the most well known task board solution.  Via extensions it is possible to implement stronger Kanban features, but Trello itself is designed for easy entry for list management.

## Group Tasks Today

1. Gather your group together
2. Decide who will be your Scrum master (ie. faciltates meeting)
3. Decide who will be your product owner (ie. oversee the documentation of tasks and their journey through the task board)
4. Draft your code of conduct.  Consider what is important to you and what will keep your project on track.
5. Decide on a technology that will support your Kanban system. The suggestions above should help.

Finally - discuss your idea!!



## Some help:

### Spotify Engineering Culture

To illustrate how Scrum ideals (and agile principles in general) can work, watch the following video by Spotify:

<iframe width="800" height="600" src="https://www.youtube.com/embed/4GK1NDTWbkY" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>

### FAQs - Scrum Usage in the Module

1. **Do we really need to meet once a day?**

It would be good if you could, but in reality three times a week will probably be enough.  Also, use technology to get around the problem.  Skype or similar can allow you to communicate.  The point is to meet at the same time each day for no more than 10-15 minutes. Use the defined Scrum questions.

2. **We cannot find a time to all meet.  What do we do?**

You need to commit to your team and your learning.  You need to see it as a priority.  But life does get in the way.  Talk to a member of the module team to discuss how to resolve.

3. **How will Scrum be used by the teaching team?**

In two ways:

- The assessment is designed with 3-week Sprints.  Each Sprint end will involve a review with a member of the teaching team that will be assessed.
- Every lab your team will have a 10-minute standup with a member of the teaching team to check how everything is progressing.

4. **If we are having a standup does that mean I have to attend every lab?**

Yes.  This is for your benefit.

5. **Does my team have to all be in the same lab session?**

Yes.  You should consider this when organising your team.

6. **Does my team have to work on the lab material together?**

Yes.  You are a team and should see your learning in the module as part of the team effort.

7. **We have a problem with a team member.  What should we do?**

Identify quickly and resolve by addressing with the team member.  If there is a still a problem bring it up at the lab standup.  If you have fallen out then ask yourselves if it can be solved.  Try and be professional and courteous as a team.

8. **Can we sack a team member?**

We'd prefer not to, but if this is necessary bring it up at the lab standup.