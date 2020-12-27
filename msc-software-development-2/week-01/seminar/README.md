# Software Development 2 Seminar 1 -- Team Forming and Scrum

## What is Scrum?

Scrum is a project management and group working philosophy.  For project management, the idea is simple: check your project regularly to see if it is heading in the right direction.  It is that simple, but few people manage a project this way.  The idea has been around for a while:

- *"In preparing for battle I have always found that plans are useless, but planning is indispensable."* Dwight D. Eisenhower.
- *"Plans are of little importance, but planning is essential."* Winston Churchill.
- *"All human plans [are] subject to ruthless revision by Nature, or Fate, or whatever one preferred to call the powers behind the Universe."* Arthur C. Clarke.
- *"Planning is useful.  Blindly following plans is stupid."* Jeff Sutherland, co-creator of Scrum.

A plan is never right.  It will be wrong from the start.  So you need to constantly change the plan, so why not build that into your process by monitoring your current plan.

Scrum works in iterations, called **Sprints**.  A Sprint has a fixed length of time (typically two weeks) where a set of tasks will be completed.  The team decides which tasks they will complete in a Sprint and then analyse how well they did at the end of the Sprint.  This allows a team to work towards a goal in increments.  The team needs to *know the goal*, *see the goal*, and *work incrementally towards the goal.*  This is as far as you plan in detail.

## Components of Scrum

In Scrum we use the following terminology:

- Product Backlog.
- Task Board (or Scrum Board, or Kanban Board).
- User Stories.
- Sprints.
- Sprint Planning.
- Story Points.
- Planning Poker.
- Daily Standup.
- Sprint Review and Retrospective.

### Product Backlog

The Product Backlog is the list of all currently identified tasks.  You start by defining all the tasks you can think of at the start of the project.  We will look at defining tasks later.  The tasks are prioritised by the **Product Owner** to determine which provide the greatest amount of value quickly to the customer.

### Task Board

To keep track of your tasks we write them on sticky-notes and place them on a whiteboard, something as follows:

<a title="By Dr ian mitchell [CC BY-SA 2.5 
 (https://creativecommons.org/licenses/by-sa/2.5
) or CC0], from Wikimedia Commons" href="https://commons.wikimedia.org/wiki/File:Kanban_board_example.jpg"><img width="1024" alt="Kanban board example" src="https://upload.wikimedia.org/wikipedia/commons/thumb/f/f5/Kanban_board_example.jpg/1024px-Kanban_board_example.jpg"></a>

To start with you will define four columns:

1. Backlog (or *Open Issues*).
2. Sprint.
3. In progress.
4. Done (or *Closed Issues*).

Tasks flow from the the Backlog to Done as they are completed.  There are many online tools to achieve this.  We will use the one built into GitHub.  [Trello](https://trello.com/) is another popular tool.

### User Stories

When defining a task it should be part of a *User Story*.  This allows the team to understand **why the task is needed.**

- As a student I want to submit a coursework so that I can pass the module.

This story has a number of tasks associated with it.  We need to upload a file.  That file needs to be associated with an assessment.  An assessment needs to associated with a module.  We need to login to the system.  And so on.

### Sprints

A Sprint is a period of time when a team does work.  The typical length of time is two weeks.  At the end of the Sprint the product must have moved forward and be usable by the customer.  That is, the customer has to see new features added and completed so they can judge them.  If the product is not usable at the end of the Sprint you have a problem.  If a task is not fully finished at the end of the Sprint then it is not done - the effort was wasted in this Sprint and something else could have been developed and shown to the customer instead.

### Sprint Planning

To plan a Sprint, the team selects tasks they believe they can complete during the Sprint.  These tasks are selected from the prioritised task list.

### Story Points

Each task is scored based on an estimated cost.  We don't talk about hours, days, or any other concept of time.  We are allocating points.  And points are a relative score.  For example, we could rate our tasks using animal sizes:

- Mouse.
- Dog.
- Deer.
- Hippo.
- Elephant.
- Blue Whale.

Humans cannot judge the time it will take to complete a task.  But they can compare sizes really well.  For example:

- Student can login (mouse).
- Student can upload a file (dog).
- Uploaded file is associated with an assessment (horse).
- etc.

Each of the sizes is given a value:

- Mouse (1).
- Dog (2).
- Deer (3).
- Hippo (5).
- Elephant (8).
- Blue Whale (13).

This is the Fibonacci sequence, and has been found to be the best approach to estimate relative task size.  And we use the entire team to estimate, because collectively you can come to a better estimate.  Estimation is done via Planning Poker.

### Planning Poker

Planning Poker doesn't use animals but numbers - you just need to remember what the numbers represent.  We are comparing task size, not determining days of work.  Planning Poker card decks are available:

<a title="By Hkniberg at English Wikipedia (Transferred from en.wikipedia to Commons.) [Public domain], via Wikimedia Commons" href="https://commons.wikimedia.org/wiki/File:CrispPlanningPokerDeck.jpg"><img width="256" alt="CrispPlanningPokerDeck" src="https://upload.wikimedia.org/wikipedia/commons/e/eb/CrispPlanningPokerDeck.jpg"></a>

The process is:

1. Select a task.
2. Everyone picks a card from their deck to score the task, but does not reveal it.
3. When everyone is ready, everyone reveals their card at the same time (so no groupthink comes in).
4. If the cards are within two of each other (e.g. a 2, 3, and 5 range) then sum the cards and divide by number of voters to get the average.  That is your estimated cost.
5. If the cards are not within two of each other, then the smallest and largest scorers describe why they gave the points they did.  Then a re-vote.  Repeat until the group are within two cards of each other, then average.

Remember - **this is an estimate**, and an estimate for a tiny part of the project.  You don't know.  But you need to constantly review your scores based on what you have learnt during the project.  You will get a better estimate of completion time the longer you work on the project.

### Daily Stand-up

**At the same time every day** the team meets for up to 15 minutes.  Each person answers the following three questions:

1. What did you do since the last stand-up?  
2. What are you going to do before the next stand-up?  
3. What is getting in your way?

The daily stand-up builds a routine, and people love routines.  It also allows the team to spot blockages.  **Question 3 is essential.**  If one of the team has a problem (e.g. *"I cannot connect to the SQL database."*) then someone might have their solution (e.g. *"I know how to do it, let me help."*).  **This is teamwork.**  Work will be completed faster as tasks will not be blocked.

### Sprint Review and Retrospective

After a Sprint and before the next Sprint the team undertakes a review and retrospective.  How fast are the team working?  What went well?  What went badly?  How can we increase our productivity?  In retrospective the team can spot problems and adjust.  Remember, *inspect and adapt.*

The team should ask the following questions:

1. Is there anything we can do differently to speed things up?
2. Can we offload some Backlog items (i.e. give them to other teams)?
3. Can we not do some things (i.e. remove items from the backlog)?

We are also interested in how the team is doing, both collectively and individually.  So each person answers the following questions:

1. On a scale from 1 to 5, how do you feel about your role in the company?
2. On the same scale, how do you feel about the company as a whole?
3. Why do you feel that way?
4. What one thing would make you happier in the next Sprint?

The team then vote on which improvement to make and execute it in the next Sprint.  It needs to be a task with a clear measure of whether it has been successfully done at the next retrospective.  Doing this, and doing it consistently Sprint-to-Sprint will mean the team learns, evolves and improves as it works.

## Scrum Team and Roles

A team must have the necessary skills to get the work done.  A team should contain all the members needed to deliver the project/product, but should be seven people (plus or minus two) in size.  Any larger will create too many communication channels.  Smaller teams (as you will have in the module) are fine for smaller projects.

By all skills, we mean everything.  DevOps is an intersection:

<p><a href="https://commons.wikimedia.org/wiki/File:Devops.svg#/media/File:Devops.svg"><img src="https://upload.wikimedia.org/wikipedia/commons/thumb/b/b5/Devops.svg/1200px-Devops.svg.png" alt="Devops.svg"></a><br>By <a href="//commons.wikimedia.org/wiki/File:Devops.png" title="File:Devops.png">Devops.png</a>: <a href="//commons.wikimedia.org/w/index.php?title=User:Rajiv.Pant&amp;action=edit&amp;redlink=1" class="new" title="User:Rajiv.Pant (page does not exist)">Rajiv.Pant</a>
derivative work: <a href="//commons.wikimedia.org/wiki/User:Wylve" title="User:Wylve">Wylve</a> - This file was derived from:&nbsp;<a href="//commons.wikimedia.org/wiki/File:Devops.png" title="File:Devops.png">Devops.png</a>:&nbsp;<a href="//commons.wikimedia.org/wiki/File:Devops.png" class="image"></a>, <a href="https://creativecommons.org/licenses/by/3.0" title="Creative Commons Attribution 3.0">CC BY 3.0</a>, <a href="https://commons.wikimedia.org/w/index.php?curid=20202905">Link</a></p>
IT Operations are part of your team.  They help you deliver your product.  Your team might include sales, admin, or other people.  The team needs all the skills for your product/project.

Also, a team member should only be a member of that one team.  No other. If a team member is dividing their attention across multiple projects/products then they aren't committed to either.

### Roles

Scrum defines two roles within the team:

1. The **Product Owner** decides what the work should be.  They own the Backlog, what's on it, and most importantly, what order it's in.
2. The **Scrum Master** keeps the team working, solves blockages, and keeps the rhythm going.  Their job is to help the team work as best they can.

Notice there is no Project Manager, no leader, no boss.  Teams are autonomous and self-organising.  If there is a problem in the team they collectively solve it.  Deal with problem team members.  Reflect and be honest.  Have integrity and honesty.  Get the work done and support the team.

### Transparency

Another key concept of working in a Scrum team is that everyone knows everything.  No hiding information or keeping problems to yourself.  It helps no-one.  This is why Scrum teams are small - everyone can talk to each other.  Also, the rhythm of meetings means everyone should be aware of what is happening.

Scrum also avoids handing off tasks between teams.  On a handoff information is lost.  The team knows everything that is happening, the work that needs done, and how to do it.  **Everyone knows everything.**

## Scrum Process

How do we run a Scrum team?

1. Produce an initial product backlog.
2. Prioritise the backlog.
3. Do an initial estimate of the work.
4. Decide on what work to do in the next Sprint - *Sprint Planning*.
5. Every day have a daily stand-up - *Daily Scrum*.
6. End of the Sprint, review - *Sprint Review*.
7. Analyse how the team has worked and modify based on outcome of review: update estimates, add new tasks, learn lessons, etc. - *Sprint Retrospective*.
8. Repeat 4-7 until product is delivered to the customer.

Scrum uses a **Plan, Do, Check, Act (PDCA) Cycle**:

<a title="By Johannes Vietze [CC BY-SA 3.0 
 (https://creativecommons.org/licenses/by-sa/3.0
)], from Wikimedia Commons" href="https://commons.wikimedia.org/wiki/File:PDCA_Process.png"><img width="512" alt="PDCA Process" src="https://upload.wikimedia.org/wikipedia/commons/thumb/a/a8/PDCA_Process.png/512px-PDCA_Process.png"></a>

Unlike a Waterfall approach, Scrum refines the plan throughout the project.  Every iteration - *every Sprint* - planning is done in just enough detail to deliver the next increment.  We don't set the plan in great detail because we don't know what could happen.

### Product Backlog

When producing and managing a backlog there are some points to consider:

- Focus on delivering what is valuable - **deliver what people actually want or need**.  Do not deliver everything you can possibly come up with.  Do not add unnecessary features.  If you tie up resources in features and tasks that don't deliver value *that is a waste*.
- Everything cannot be a priority.  **If everything is a priority, nothing is.**
- Time is limited, as is the team's work time.  **Treat time as finite.**

### Sprint Planning

Plan your sprint based on what work is ready.  When deciding to do a task you need to ask two questions:

1. Is the task ready to be done (e.g., nothing is blocking the task)?  You need a **Definition of Ready**.
2. How will you determine when the task is complete?  You need a **Definition of Done**.

For a *Definition of Ready*, we can use the **INVEST Criteria**:

- **Independent** - the task can be completed on its own.  It should not be dependent on another task.
- **Negotiable** - until it is being done a task can be changed.
- **Valuable** - it delivers value to the customer, user, or stakeholder.
- **Estimable** - you can size the task.
- **Small** - task is small enough to estimate and plan.  If not, break it down into smaller tasks.
- **Testable** - the task has a test it will need to pass to determine if it is complete.  Write the test before you start the task.

For a *Definition of Done* we use the *testable* condition.

To decide what tasks to do, you select from the prioritised product backlog.  The **Product Owner** needs to answer the following questions:

- What tasks will provide the biggest impact?
- What tasks are most important to the customer?
- What tasks can make the most money?
- What tasks are easiest to do?

Remember you will be constantly reviewing, so the priority of tasks will change.  That is the point of Scrum - *you are constantly reviewing your plan*.

### Sprint Execution

Basically, **do the work**.  Try and complete the tasks in the Sprint Plan.  Work is only completed when it is **Done**.  Done means you have a complete, deliverable product that can be used by the customer.  **Work that is half-done is not done.**  You expended resources, effort and time and not produced a deliverable product.  That is the aim of a Sprint.

At the end of the Sprint you need to be able to demo the product to the customer.  **Demo or die.**

### Daily Standup

Every day at the same time the team stands up and updates on where they are in the project.  Everyone answers the following questions:

1. What did you do yesterday to help the team finish the Sprint?
2. What will you do today to help the team finish the Sprint?
3. What obstacles are getting in the team's way?

The daily standup builds routine.  It builds a rhythm for the team.  It is essential to the team's wellbeing that everyone gets together at the same time every day.  Missing these meetings, being late for these meetings, or otherwise being disruptive does not help the team.

### Sprint Review and Retrospective

At the end of the Sprint the team counts the number of points completed that iteration: the team **velocity**.  You need to know and measure your velocity, but doing it once is not enough.  It will take a number of Sprints to get an understanding of how fast the team can work.

Once you know your team velocity, you can perform one of two estimates:

- **delivery = velocity * time of project**.  In other words, if you have a deadline and a velocity, you can estimate how much you can deliver.
- **date = work / velocity**.  In other words, if you have a set of features and work to deliver, you know when you can deliver it.

Typically, the first measure is what we care about.  We have a deadline and we deliver to it.  As we are delivering value first, we have given the customer what they need.

If the deadline cannot be met, ask the following questions:

1. Is there anything we can do differently to speed things up?
2. Can we offload some Backlog items?
3. Can we not do some things?

The team then undertakes a retrospective as described above to improve how the team works.

### Scrum Framework

To summarise the Scrum Framework see below:

![Scrum Framework](scrum-framework.png)

## Your Task

1. Pick a **team**.  You need four people for your team.
2. Define a **Code of Conduct**. What are the expectations of the team?
3. Pick a **Product Owner**.
4. Pick a **Scrum Master**.
5. Product owner creates and prioritises a **Product Backlog** with help from the team.
6. The team refines and estimates the **Product Backlog.**
7. Scrum Master schedules **Sprint planning session**.
8. Scrum Master schedules **daily stand-ups**.
9. Scrum Master schedules **Sprint review**.
10. Scrum Master schedules **Sprint retrospective**.

Your team should work on everything together.  **Work on the labs together.**  **Study the material together.** **Work on the coursework together.**  By this, you will increase the overall capability of the team above what the individuals can do by helping each other.  **Remember, you are a team.**

## Spotify Engineering Culture

To illustrate how Scrum ideals (and agile principles in general) can work, watch the following video by Spotify:

<iframe width="800" height="600" src="https://www.youtube.com/embed/4GK1NDTWbkY" frameborder="0" allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>

## FAQs - Scrum Usage in the Module

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