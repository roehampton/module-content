# Seminar 5 - User Stories, user flows and breaking your user stories down into tasks

## User Stories

Remember that your user stories take the form:

> As a **< user role >**, I can **< activity >** so that **< business value >**.

The parts that need to add are:

- **User role** is who the story involves.  It needs to be specific enough to allow a conversation.  *User* is not a legitimate user role
- **Activity** is the task the user wants or is required to do
- **Business value** is why the task is important



### Conditions of Satisfaction

So we have user stories, and we have a *card* with the user story written on it.  This is not enough information for the development team.  Along with a general *Definition of Done*, each user story needs conditions of satisfaction, written on the back of the card.

**Conditions of Satisfaction** or **Acceptance criteria** are questions that need to be answered for the user story to be completed to the quality required by the Product Owner.  They are the *conditions* that will *satisfy* the *Product Owner* that the story is complete.

For example, consider a user story:

> As a wheelchair user I want to go into the computer lab so that I can do my assignment on a lab computer.

in order to meet the conditions of satisfaction, a whole host of other issues may arise...

> Is the door to the lab large enough to let in a wheelchair?
> Is the door to the lab automatic to allow the wheelchair user access?
> Is the button to open the doors at a suitable height for a wheelchair user?
> Is their space for a wheelchair user to navigate the lab freely?
> Are the desks in the lab at a suitable height for a wheelchair user?
> Is the space at each desk enough for a wheelchair user?

 Conditions of Satisfaction can grow as more is understood about the story.  That is, they provide more information to the team about what is required to fulfill the user story.
 
### User flows

Once you have agreed your user stories, you can start to think about how they might be implemented within your system.  Taking the users point of view, you can develop a flowchart that represents how the user will fulfill each part of the user story.  If the 'user journey' in your idea has significant elements that are not online, then taking a service design approach and creating user journey documentation will be useful

[Short article on user flow diagrams and user journey maps](https://uxpressia.com/blog/user-flow-vs-user-journey)


You can also develop wireframes or lo-fi prototypes which you should do as very quick sketches, these can ensure that as a team you have a shared understanding of what you are going to build.  When you have clients or customers, these are essential for communicating your intentions to them as well before you spend too much time (and money!).  These are a form of throwaway prototypes and you can even do user testing with them

[Article on different forms of prototyping](https://blog.adobe.com/en/publish/2017/11/29/prototyping-difference-low-fidelity-high-fidelity-prototypes-use.html#gs.dybx5e)


### Tasks

Stories can be further decomposed into tasks.  Tasks are pieces of work that can be completed by individual team members.  Tasks also lead to the completion of a user story.

Tasks are different from user stories in that they have a single owner (the person who has taken responsibility for delivering the task) and are estimated in hours rather than points.  A task should typically take a person 4-8 hours to complete.  That is, they are big enough to be a serious piece of work, but not too big to take more than a day of work.

A user story map is a useful way of breaking down simple user stories into actionable tasks

[NN Group article on User Story maps](https://www.nngroup.com/articles/user-story-mapping/)


### Working with the Product Owner

The Product Owner is key to working with user stories.  They are responsible for creating and signing-off user stories throughout the development process.  This is why the Product Owner is part of the Scrum team - the development team need access to the Product Owner to clarify what is being asked for and to check that what has been delivered meets what the Product Owner wants.

There are three stages that the Product Owner helps the development team work with user stories:

- **Definition**: the developer needs to work with the Product Owner to understand what is meant by a story.  A good rule of thumb for the Product Owner to think about here is *if you don't know how to do IT, then you don't really know what IT is*.
- **Building**: during development new topics and ideas may come out.  Again the developer and Product Owner is required to ensure story understanding evolves during development.
- **Testing**: a story must pass an acceptance test which checks that the code delivers against the story.  The Product Owner can assist by helping the developer understand the functionality of the user story, and doing some inspection of the behaviour defined.


### Story Acceptance Test

A **Story Acceptance Test** determines if a story has been implemented correctly.  A story can have one or more acceptance tests.  These tests check functionality of the system delivered.  In this way, they are different than *Conditions of Satisfaction* which require certain conditions to be met, rather than functionality implemented.



## Your Task

Elect a product owner for this week.  Usually in a project there is just one product owner throughout, but for this project we will rotate this task.

The product owner should lead and structure your team's activities.

1. Review and revise your user stories. When you are happy that you have got these to a good place, add them to your taskboard and break them into several user flows. Represent these as user flow diagrams, and then start sketching lo-fi prototypes that represent the flows.
2. Once you have understood what you are are building ie. how users will interface with it, break the stories down into developer tasks.