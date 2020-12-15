# Software Development 2 Lecture 5 -- Requirements Gathering

In this lecture we will examine requirements.  Requirements are considered one of the most difficult facets of software development.  We will examine what a requirement is, how we manage these in an agile approach, and some ideas around gathering and thinking about requirements.

## What is a Requirement?

A requirement is something that drives a design choice.  It is the need of a stakeholder for a product that will provide value to the stakeholder.  Requirements define what the developers should implement.  Requirements specify system behaviours, properties and/or attributes. They may also define constraints.

The IEEE Standard Glossary of Software Engineering Terminology defines a requirement as:

1. A condition or capability needed by a user to solve a problem or achieve an objective.
2. A condition or capability that must be met or possessed by a system or system component to satisfy a contract, standard, specification, or other formally imposed document.
3. A documented representation of a condition or capability as in 1 or 2.

Software requirements should also have a temporal dimension:

- Present tense about current capability.
- Future tense, for goals that are high, medium, or low priority.
- Past tense, for requirements now discarded.

There are a number of different requirement types and definitions, including:

| **Term**                           | **Definition**                                               |
| ---------------------------------- | ------------------------------------------------------------ |
| **Business requirement**           | A high-level organisation objective.                         |
| **Business rule**                  | A policy, guideline, standard, or regulation that defines or constrains the business. |
| **Constraint**                     | A restriction on development choices.                        |
| **External interface requirement** | Requirements on how a system interacts with external users, services, and applications. |
| **Feature**                        | Capability required by the customer, defined as a set of functional requirements. |
| **Functional requirement**         | Behaviour that the system must exhibit.                      |
| **Nonfunctional requirement**      | A property of the system.                                    |
| **Quality attribute**              | A nonfunctional requirement for service or performance levels. |
| **System requirement**             | Top-level requirement for a large system with multiple components. |
| **User requirement**               | Goal or task that a user wishes to perform with the system.  |

### Problem and Solution Domains

We can further layer requirements, features, and needs as follows:

![Problem and Solution Domain](problem-domain.png)

**Needs** are the problem domain we are working in.  The solution domain is the features and subsequent requirements that allow us to meet these needs.  From software requirements we define three distinct requirement types: 

- **Business requirements** are why the business is building the system.  Recorded in a vision and scope document.
- **User requirements** are goals and tasks the user wants to perform.
- **Functional requirements** specify behaviours the product will perform to enable users to complete tasks.

Functional requirements enable users to complete tasks (user requirements) which thereby satisfy business requirements.  Therefore, we can consider the problem domain as the business requirements - the **needs** of the organisation for the system.

## Project Management Triangle (The Iron Triangle)

In project management, there is an understanding that three properties constrain a project:

- **Requirements** (or scope) is what we will do in the project.
- **Resources** (or cost) is the budget (including people and materials) for the project.
- **Time** is the duration of the project.

The idea is that if one of these items change then the other two most also change - the triangle must scale based on the change of constraints in the project.  The triangle is sometimes referred to as the *Iron Triangle* because of this fixed nature:

![The Project Management Triangle](iron-triangle.png)

With traditional project management we set the requirements as fixed: we **know** what the project must deliver.  The question is the time and resources required to deliver the project.  These are estimated based on experience.

### Problems with the Iron Triangle

The main problem with the Iron Triangle is what we estimate: *resources* and *time*.  No organisation can actually plan for variable project costs and time to deliver.  This is why products are delivered late and over budget, and normally do not deliver what was required.  This is known as *The Iron Triangle Trap*, which is a feature of traditional waterfall approaches.

In waterfall, our approach is to perform full requirements definition, then spending time to deliver those requirements.  This is no longer viable.  Business requirements change, and therefore fixing project requirements is not suitable.  We need to do better.

Another problem emerges when requirements are fixed.  Although we claim resources and time are estimates, as stated these are really fixed based on what the organisation has available.  So only one attribute can change: the quality of the product.  This is the only variable project team members can change.  And reducing quality is not sustainable.

So why is the Iron Triangle and waterfall method still in use today?  Some points to consider (taken from *Agile Software Requirements* by Dean Leffingwell):

- Waterfall aimed to fix the old technique of "code it, fix-it, code-it-some-more-until-it's-quickly-not-maintainable". 
- The general idea seems sound: understand requirements; design a solution to the requirements; code it; test it.
- It works to a point.  Lots of software has been built using waterfall.  Business processes have been built around this model.
- Customers still want fixed delivery time and requirements from suppliers.

## Agile and Requirements

We previously covered the [Four Values of the Agile Manifesto](https://agilemanifesto.org/).  The Agile Manifesto also defines [twelve principles](https://agilemanifesto.org/principles.html), two of which are of interest when discussing requirements:

- **Manifesto principle 1** *Our highest priority is to satisfy the customer through early and continuous delivery of valuable software.*
- **Manifesto principle 2** *Welcome changing requirements, even late in development. Agile processes harness change for the customer’s competitive advantage*.

Principle 1 tells us that delivering satisfactory value to the customer is our highest priority.  Principle 2 tells us that requirements change.  This goes against our *Iron Triangle* view - requirements are **not** fixed.

Another key aspect of agile and Scrum is the team.  Focusing just on delivering means we are not thinking about the people who deliver the work.  Management wants change and improvement, but it is the team that decides how to do so.  Remember that we seek *continuous improvement*.  The team overworking to deliver rigid requirements in a rigid time is not beneficial to the team.

### Inverting the Iron Triangle

In agile, we invert the Iron Triangle as follows:

![Inverted Iron Triangle](inverted-triangle.png)

This changes a project so that:

- Time is **fixed**.
- Resources are **fixed**.
- Requirements/scope are **estimated**.

Remember we are working in Scrum teams.  Therefore, we are going to fix the quality of our product, and deliver new value in an increment timebox.  Then we repeat the process forever.  This works with the idea of business requirement change.  Features decrease in value over time. We need to release features first or fast enough to benefit from their value.

### Vision Statement

From *Agile Software Requirements*:

> The Vision answers the big questions for the system, application, or product, including the following:
>
> - What problem does this particular solution solve?
> - What features and benefits does it provide?
> - For whom does it provide it?
> - What performance, reliability, and so on, does it deliver?
> - What platforms, standards, applications, and so on, will it support?

These are aspects we have already covered in many regards.  Problems are the needs we are addressing.  Users are also discussed above.  Quality requirements (performance, reliability, etc.) are named.  And constraints (platforms, standards, etc.) are defined.  So a vision statement really tries to cover everything about the product we are developing. The main content of the Vision is the new features for users and the benefits there from.

Another approach is to use a **Business Model Canvas** which can contain important information in a small visible form.  An example is below:

<p><a href="https://commons.wikimedia.org/wiki/File:Business_Model_Canvas.png#/media/File:Business_Model_Canvas.png"><img src="https://upload.wikimedia.org/wikipedia/commons/1/10/Business_Model_Canvas.png" alt="Business Model Canvas.png" height="453" width="640"></a><br>By Business Model Alchemist - <a rel="nofollow" class="external free" href="http://www.businessmodelalchemist.com/tools">http://www.businessmodelalchemist.com/tools</a>, <a href="https://creativecommons.org/licenses/by-sa/1.0" title="Creative Commons Attribution-Share Alike 1.0">CC BY-SA 1.0</a>, <a href="https://commons.wikimedia.org/w/index.php?curid=11892574">Link</a></p>

### Stakeholders

A key part of project management is working with the **project stakeholders.**  A system stakeholder is someone who:

- uses the system (the **users**);
- uses the results from the system;
- are impacted by the deployment and use of the system;

A project stakeholder is someone who:

- has an interest in the budget and delivery date of the project;
- has an interest in how the project is deployed;
- will be involved in selling, maintaining, etc. (aftercare) of the project deliverable(s);

To develop the group of stakeholders we ask the following questions (taken from *Agile Software Requirements*):

- Who needs to be consulted on the scope of this project?
- Who has input to the budget and schedule?
- Who ultimately manages the business relationship between the teams and the customer?
- Who will determine how and when the system is released to customers?
- Who can support or harm this project politically?
- What partners are dependent on our system?
- Who cares about the process we use to develop the system?

So stakeholders can be a diverse list of people.  They include users as a key group, but project funders, marketing, external suppliers, etc. can all be involved.

## Working with Requirements in Agile

User stories are the main requirement work undertaken in agile.  Stories need identified, maintained, prioritised, scheduled, elaborated, implemented, tested, and accepted:

- Identified via discovery (see below).
- Maintained by the Product Owner working with the team.
- Prioritised by the Product Owner, on the product backlog
- Scheduled by the team, by pulling them into a Sprint.
- Elaborated by the team by asking questions.
- Implemented by the team.
- Tested by the team (unit test, functional test, acceptance test).
- Accepted by the Product Owner as complete, based on the Definition of Done.

Requirements are no longer defined by others and handed off to the developers.  The entire team defines requirements, determining trade-offs, implementing requirements, testing, integrating the results, and delivering to the customer.  In agile development , it is the developer’s job to speak the language of the user, not the user’s job to speak the language of developers .

Requirements are not an output of the project.  We don't care that we've done a good job in managing our requirements.  Our job is to deliver value, and our requirements do so via our discussion with the customer.  We deliver what they need.  We communicate with our customer to ensure that the requirements do so.

### Product Owner

The Product Owner is the person who can communicate and support the requirements work of the agile team.  This comes from the *vision* that the Product Owner defines.  Stakeholders appoint the Product Owner who creates the vision and works with the team in its delivery.  The Product Owner is important as they have the responsibility of defining and prioritising the requirements.

The Product Owner must (taken from *Agile Software Requirements*):

- determine requirements by working with product managers, business analysts, customers, and other stakeholders.
- maintain the backlog and prioritise based on relative user value.
- set iteration objectives.
- elaborate stories, participate in progress reviews, and accept new stories.

The Product Owner also supports requirements at the Sprint Planning Meeting:

- reviewing the iteration objective.
- presenting each backlog item, individually, for discussion.
- supporting the team as they discuss each item until it is well enough understood to implement and estimate.

### Requirements Discovery

So outside the team, the Product Owner has to help shape the vision and define the requirements.  How do they do this?  Some methods include (taken from *Agile Software Requirements*):

- Requirements workshops.
- Brainstorming.
- Interviews and questionnaires.
- User experience mock-ups.
- Product council.
- Competitive analysis.
- Customer change request systems.
- Use-case modelling.

These methods may also involve members of the team depending on their nature.  The key is that the Product Owner is the conduit for the information being given to the team.  This is why the Product Owner is part of the team.

### Release Planning

Much of modern development is driven by release planning.  A Product Owner has a vision and features they want delivered.  The question is deciding with features will be delivered in a given increment, and how many increments will lead to a release.

Release planning leads to a **roadmap** which defines how value will be delivered over time.  A series of planned release dates are defined, each date with a theme, objectives, and features.  The next release is the one the team has committed to deliver for the organisation.  All other releases are not committed and can be redefined based on changing needs.  Being flexible is the key to agile delivery.

## Start With Why

*Start With Why* is a popular book from Simon Sinek.  Sinek makes the argument that people do not by what a product does but why it does it.  This is refined into what Sinek calls *The Golden Circle* which puts *why* at the centre.

<p><a href="https://commons.wikimedia.org/wiki/File:Golden_circle.png#/media/File:Golden_circle.png"><img src="https://upload.wikimedia.org/wikipedia/commons/3/3e/Golden_circle.png" alt="Golden circle.png" height="480" width="482"></a><br>By <a href="//commons.wikimedia.org/wiki/User:Mosborne01" title="User:Mosborne01">Mosborne01</a> - <span class="int-own-work" lang="en">Own work</span>, <a href="https://creativecommons.org/licenses/by-sa/3.0" title="Creative Commons Attribution-Share Alike 3.0">CC BY-SA 3.0</a>, <a href="https://commons.wikimedia.org/w/index.php?curid=10403628">Link</a></p>

A quote from Sinek is:

> People do not buy what you do, they buy why you do it.

Why is this relevant to our discussion on requirements?  Because this emulates our pyramid separating the problem domain and solution domain:

![Problem and Solution Domain](problem-domain.png)

The three questions Sinek defines are:

- Why you do it (the needs).
- How you do it (the features).
- What you do (the requirements).

Thinking of your product in this manner can help you produce a better vision.  A strong why is seen as key to the successes of Apple and Microsoft.

Sinek's TEDx talk is worth watching around this:

[![Start With Why TEDx Talk](https://img.youtube.com/vi/u4ZoJKF_VuA/0.jpg)](https://www.youtube.com/watch?v=u4ZoJKF_VuA)

Further information can be found by reading Sinek's book *Start With Why*.

## Summary

We've covered a lot of concepts here, and little about actual direct methods of gathering requirements.  That is because the point is having collaborative methods with stakeholders, and features driven by a Product Owner.  We have:

- Defined what a software requirement is - something required by a project stakeholder.
- Evaluated the problems with traditional project management and requirements - particularly the *Iron Triangle Trap*.
- Discussed requirements in the context of agile software development - examining the role of the Product Owner and team in working with requirements.