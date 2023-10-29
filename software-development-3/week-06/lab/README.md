# Creational design patterns lab

## Singleton pattern

1. Using your animal classes from week 2, implement the zoo as a singleton pattern ie. ensure that there is always and can always only be one zoo.  

### Too do this you will need to
1. Create a singleton class, Zoo with a private constructor and a static getInstance() method that returns the static zoo property  (the code is in the lecture slides)
2. Create a List of animals as a property of your zoo class
2. Now write a Main method in which you get the instance of the zoo singleton, and then add animals to it.

__I suggest you use the debugger in visual studio to track the zoo singleton and ensure that its behaviour is exactly as you expect__

## Factory Method pattern


1. Create a AnimalFactory class with a makeAnimal() method which takes the type of animal to be created and a name for that animal, for example makeAnimal("elephant", "elmer"). The method should return an object of the correct type, which should implement the IAnimal interface.
4. Add an AnimalFactory property to  your Zoo class and an addAnimal(type, name) method to your zoo so that you can add animals to the zoo in a main method without your main method having to know anything about how the different animals should be created.

## Builder pattern

Implement the Builder pattern to create enclosures for different animals with appropriate land, water and boundary features (you will find example code and explanation in the slides)



