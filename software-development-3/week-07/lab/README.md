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

ADDITIONAL TASK: Create an additional state for the animals, for example, animal at the vet which will affect if it will need to be fed.  See if you can create a new state for this.


### Observer pattern

Our zoo would like to have a system whereby users can 'subscribe' to special offers of different types (eg. family, group).  When an offer is available, the subscribers are sent a message.

1. Implement this using the code shown in the lecture slides to help you.

2. Implement an additional offer, for students.  Add some student 'observers' and print out a list of students who have subscribed to the offer when the offer is made available.

Independent task:  Use the observer pattern to create a notifier for a cohort of students which will inform them of timetable changes or assessment date changes.

### State pattern

Our zoo would like to inform visitors if they should take food for the animals when they go to see them.  

1. Implement this, using the lecture slides to help you.

HINT: Implement a base class for animals if you have not done so already and alter all the animal classes so they inherit from this base class. This will make additional functionality much easier to implement.

HINT contd: Create an additional property in the AnimalBase class for the Animal state and a setState() method.

NOTICE: The state pattern can implement different behaviours according to state.  Initially, set the initial state of an Animal object when it is instantiated to AnimalHungry.  When viewAnimal() is called, the caller will be told to bring food, and the Animal's state can then be set to AnimalNotHungry.

ADDITIONAL TASK: Once you have the code from the lecture slides working, experiment with different ways of changing the hungry or not hungry state of the animals ie. either from the client code, or from other state objects.


### Visitor pattern

The visitor pattern enables new behaviour to be enacted by objects, which may differ between related types, without having to add this behaviour to the orginal class.  instead of adding new methods, the object we want to alter is passed to a method of a new class, and then its data and behaviours can be accessed from there.

In our zoo, we want to be able animals to receive a visit from either the vet or the zoo keeper.  In the future, there may be other regular visitors who do different functions.  Additionally, the actions of the visitor may alter depending on what type of animal they visit.

1. Implement this using the lecture slides to help you.
2. Add an additional visitor, for example a photographer, who will also visit all the animals.


HINT:  here is some revised code for the zoo singleton which will make it easy for you to interate over the animals and send in the visitors:

```c#
// Make the zoo into a singleton as it is the single point of reference for the zoo.
class Zoo
{
    // The Zoo holds an instance of itself.
    private static Zoo zooInstance = null;
    private List<IAnimal> animals = new List<IAnimal>();

    private Zoo()
    {

        IAnimal m1 = new Elephant("elmer");
        animals.Add(m1);

        IAnimal m2 = new Lion("elsa");
        animals.Add(m2);

        IAnimal f1 = new Shark("Sharky");
        animals.Add(f1);

        IAnimal r1 = new Snake("Snakey");
        animals.Add(r1);
    }

    public static Zoo getInstance()
    {

        // Make sure zoo is instantiated only once
        if (zooInstance == null)
        {
            zooInstance = new Zoo();
        }
        return zooInstance;

    }

    public void visitAnimals(IVisitor visitor)
    {
        foreach (IAnimal animal in animals)
        {
            animal.acceptVisitor(visitor);
        }

    }

}
```
