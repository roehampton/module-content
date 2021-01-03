# Software Development 2 Lecture 01 -- Software Development Lifecycle

You are probably familiar with the development of software in principle, at least from a *programming* perspective. Software Development is bigger than programming though. From [Wikipedia](https://en.wikipedia.org/wiki/Software_development) (emphasis mine):

> Software development is the process of **conceiving**, **specifying**, **designing**, **programming**, **documenting**, **testing**, and **bug fixing** involved in creating and maintaining applications, frameworks, or other software components.

So we have seven areas defined for software development:

1. **Conceiving** or coming up with an idea. This is an open-ended question based on personal choice and market need.
2. **Specifying** is coming up with requirements to build the software. We will only skim across this idea with use case modelling.
3. **Designing** takes the specification to produce some form of model for the software. We will do a bit of UML in this module.
4. **Programming** is the one most students are familiar with.
5. **Documenting** is the part most people dislike, but is fundamental for software reuse. We will touch on areas of documenting.
6. **Testing** is another area people dislike. We will look at unit testing and test automation in this module.
7. **Bug fixing** is an area that a lot of time is spent on. This is not debugging your local code, but fixing bugs in production software.

As you can see, it is likely your software development education has only scratched the surface of software development. The focus will have been on programming. We will cover the other areas (except *conceiving*) through this module.

## Software Development Lifecycle (SDLC)

A Software Development Lifecycle (SDLC) is the process of developing software. The term has been around since about the 1960s. The following image illustrates the main phases:

[![Systems Development Life Cycle.jpg](https://camo.githubusercontent.com/a5b2c600315e9f88dd0df2cff47e56478cd55c297038248027289370ff83e2f9/68747470733a2f2f75706c6f61642e77696b696d656469612e6f72672f77696b6970656469612f636f6d6d6f6e732f622f62622f53797374656d735f446576656c6f706d656e745f4c6966655f4379636c652e6a7067)](https://commons.wikimedia.org/wiki/File:Systems_Development_Life_Cycle.jpg#/media/File:Systems_Development_Life_Cycle.jpg)
By US Department of Justice (redrawn by [Eugene Vincent Tantog](https://commons.wikimedia.org/wiki/User:Mdd)) - [INFORMATION RESOURCES MANAGEMENT](http://www.usdoj.gov/jmd/irm/lifecycle/ch1.htm), Public Domain, [Link](https://commons.wikimedia.org/w/index.php?curid=5530145)

These stages are still used today. How we use them has changed. The software industry has produced three key approaches.

## Three Key Methods in Software Development

1. **Waterfall** -- original ideas from 1950s, formally defined in the 1970s. Still common today.
2. **Spiral** or incremental development -- originally from the late 1980s.
3. **Agile** -- from the mid 1990s.

### Waterfall

The waterfall model gets a lot of bad press, but is still successfully used in industry today. The biggest criticism is the rigid format it uses, in that each stage must be completed before moving onto the next stage. This means we cannot adapt to changing customer needs. Below is a typical representation:

[![Waterfall model.svg](https://camo.githubusercontent.com/d96d4f166e2b1bc4a39f5f6fed608028819aa83aceb627eaedb53b260aa96126/68747470733a2f2f75706c6f61642e77696b696d656469612e6f72672f77696b6970656469612f636f6d6d6f6e732f7468756d622f652f65322f576174657266616c6c5f6d6f64656c2e7376672f3132303070782d576174657266616c6c5f6d6f64656c2e7376672e706e67)](https://commons.wikimedia.org/wiki/File:Waterfall_model.svg#/media/File:Waterfall_model.svg)
By Peter Kemp / Paul Smith - Adapted from Paul Smith's work at [wikipedia](https://en.wikipedia.org/wiki/File:Waterfall_model.svg), [CC BY 3.0](https://creativecommons.org/licenses/by/3.0), [Link](https://commons.wikimedia.org/w/index.php?curid=10633070)

The original phases are:

- **Requirements gathering** or defining what is needed in the software.
- **Analysis** of the requirements to define models and rules.
- **Design** to produce the software architecture.
- **Coding** to build the software.
- **Testing** to ensure the software is working as expected.
- **Operation** of the software where needed.

### Spiral

The spiral model builds on some of the ideas of the waterfall model but provides ability to adapt due to its iterative nature.

[![Spiral model (Boehm, 1988).svg](https://camo.githubusercontent.com/ae090b1a0ec9f4519b84f1658fcfa98a993ca3a3d0819fb79aeb93c98ab697c3/68747470733a2f2f75706c6f61642e77696b696d656469612e6f72672f77696b6970656469612f636f6d6d6f6e732f7468756d622f652f65632f53706972616c5f6d6f64656c5f253238426f65686d2532435f313938382532392e7376672f3132303070782d53706972616c5f6d6f64656c5f253238426f65686d2532435f313938382532392e7376672e706e67)](https://commons.wikimedia.org/wiki/File:Spiral_model_(Boehm,_1988).svg#/media/File:Spiral_model_(Boehm,_1988).svg)
By Conny derivative work: [Spiral_model_(Boehm,_1988).png](https://commons.wikimedia.org/wiki/File:Spiral_model_(Boehm,_1988).png): Marctroy derivative work: [Conan](https://commons.wikimedia.org/wiki/User:Conan) ([talk](https://commons.wikimedia.org/wiki/User_talk:Conan)) - [File:Spiralmodel_nach_Boehm.png](https://commons.wikimedia.org/wiki/File:Spiralmodel_nach_Boehm.png), [Spiral_model_(Boehm,_1988).png](https://commons.wikimedia.org/wiki/File:Spiral_model_(Boehm,_1988).png), Public Domain, [Link](https://commons.wikimedia.org/w/index.php?curid=9000950)

Spiral works by iterating through the following four stages until software is released:

1. **Determine objectives** for this iteration.
2. **Identify and resolve risks** for this iteration.
3. **Development and test** for this iteration.
4. **Plan the next iteration**.

### Agile

Agile methods build on the iterative approach, but focus on **human-centric** ideas where software is evolved by collaboration between teams and customers. Teams are self-organising, and support multiple parts of the development process. The point is that the teams can adapt (*be agile*) as requirements evolve with the client and the problems in development are discovered.

#### Agile Manifesto

Available [here](http://agilemanifesto.org/). Signatories state that as developers they value:

- **Individuals and Interactions** over *processes and tools*.
- **Working Software** over *comprehensive documentation*.
- **Customer Collaboration** over *contract negotiation*.
- **Responding to Change** over *following a plan*.

They follow these principles:

- Our highest priority is to satisfy the customer
  through early and continuous delivery
  of valuable software.
- Welcome changing requirements, even late in
  development. Agile processes harness change for
  the customer's competitive advantage.
- Deliver working software frequently, from a
  couple of weeks to a couple of months, with a
  preference to the shorter timescale.
- Business people and developers must work
  together daily throughout the project.
- Build projects around motivated individuals.
  Give them the environment and support they need,
  and trust them to get the job done.
- The most efficient and effective method of
  conveying information to and within a development
  team is face-to-face conversation.
- Working software is the primary measure of progress.
- Agile processes promote sustainable development.
  The sponsors, developers, and users should be able
  to maintain a constant pace indefinitely.
- Continuous attention to technical excellence
  and good design enhances agility.
- Simplicity--the art of maximizing the amount
  of work not done--is essential.
- The best architectures, requirements, and designs
  emerge from self-organizing teams.
- At regular intervals, the team reflects on how
  to become more effective, then tunes and adjusts
  its behavior accordingly.