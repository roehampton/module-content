# Software Development 3

# Lab week 6


## Behavioural Design Patterns


Tasks

### State pattern

Our zoo would like to find out which animals are fed and which are hungry.  

1. Implement this, using the lecture slides to help you.

HINT: Implement a base class for animals if you have not done so already and alter all the animal classes so they inherit from this base class. This will make additional functionality much easier to implement.

HINT contd: Create an additional property in the AnimalBase class for the Animal state and a setState() method.

NOTICE: The state pattern can implement different behaviours according to state.  Initially, set the initial state of an Animal object when it is instantiated to AnimalHungry.  When feedAnimal() is called, the caller will be told to bring food, and the Animal's state can then be set to AnimalNotHungry.

ADDITIONAL TASKS: 
   * Create an additional state for the animals, for example, animal only a bit hungry.  See if you can create a new state for this.
   * Consider how you might handle a situation where animals can only change state from not hungry, to quite hungry to hungry to fed, without missing any steps.  This is similar to a 'workflow' model that is found in many content management systems.

### Decorator pattern

Implement different kinds of tickets for the zoo, using the slides to help you.

Start with adult and child tickets, but then add a ticket that has unusual functionality, such as an Christmas ticket or a VIP ticket.


### Observer pattern

Our zoo would like to have a system whereby users can 'subscribe' to special offers of different types (eg. family, group).  When an offer is available, the subscribers are sent a message.

1. Implement this using the code shown in the lecture slides to help you.

2. Implement an additional offer, for students.  Add some student 'observers' and print out a list of students who have subscribed to the offer when the offer is made available.

Independent task:  Go back to our student/ person/ staff example, and use the observer pattern to create a notifier for a cohort of students which will inform them of timetable changes or assessment date changes.



### Visitor pattern

The visitor pattern enables new behaviour to be enacted by objects, which may differ between related types, without having to add this behaviour to the orginal class.  instead of adding new methods, the object we want to alter is passed to a method of a new class, and then its data and behaviours can be accessed from there.

In our zoo, we want to be able animals to receive a visit from either the vet or the zoo keeper.  In the future, there may be other regular visitors who do different functions.  Additionally, the actions of the visitor may alter depending on what type of animal they visit.

1. Implement this using the lecture slides to help you.
2. Add an additional visitor, for example a photographer, who will also visit all the animals.

Implementing the zoo as a singleton will help you with this task.
