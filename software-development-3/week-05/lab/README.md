# Software Development 3
# Lab week 5
## Structural Design patterns


Tasks

#### Composite pattern

Using the IAnimal, zoo and animal classes from previous weeks ([Week 4 solution - not all of the code here is needed](https://roehampton.github.io/module-content/software-development-3/week-04/lab/solution-lab4.html)), Add some additional animals of different type such as snakes and goldfish.

Refactor the data structure holding the animals in the zoo singleton so that it follows the composite design pattern.  Use the types of animals to create the tree structure that is the hallmark of this pattern.

Print all the animals in the zoo.

BONUS TASK: Can you adjust the print method so that the tree structure is more visible by passing a 'depth' paramter?  (hint - look at how the getTotalCost() method works and see if you can do something similar)

_INDEPENDENT TASK_ Create a university student list, using the composite design pattern to group students into Undergrad and postgrad, year 1, year 2, year 3 etc.  

Print the student list with the correct headings.


#### Decorator pattern

Create a ticketing system for the zoo, such that a base ticket is created, and then decorators "wrap" the base ticket such that different tariffs (such as adult, child), and different activities (such as feeding the penguins) can be added.

Print the ticket and calculate the cost.

Consider the advantages of creating a ticketing system in this way.

_INDEPENDENT TASK_ Having created the student list as above, use the decorator pattern to add information to each student about their grades without changing the student class itself.

Consider how this is a way to add new responsibilities to an existing object.


#### Adaptor pattern

Part of the zoo application needs the ticket price in Euros.  How can you achieve this using the decorator/adaptor pattern?


#### Bridge pattern

Implement the colours and shapes solution in the lecture slides.  Add  more colours and shapes.
