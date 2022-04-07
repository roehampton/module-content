# Software Engineering - Task Management with Kanban

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

### YOUR TASK

Have a look at each of the tools above and decide which one you think you may want to use for the group project of this module.