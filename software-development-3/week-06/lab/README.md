# Creational design patterns lab

## Singleton pattern

1. In week 2 and 3 you implemented zoo animals with that implement an IAnimal interface and/or have an AnimalBase base class.
   Use these to implement a zoo as a singleton pattern ie. ensure that there is always and can always only be one zoo. The Zoo should have a name and a list of animals.

A zip file of animals with IAnimal interface is here: (https://moodle.roehampton.ac.uk/pluginfile.php/4782498/mod_resource/content/1/org.roehampton.sd3.zoo.zip)[https://moodle.roehampton.ac.uk/pluginfile.php/4782498/mod_resource/content/1/org.roehampton.sd3.zoo.zip]

### Too do this you will need to
1. Create a singleton class, Zoo with a private constructor and a static getInstance() method that returns the static zoo property  (the code is in the lecture slides)
2. Create an ArrayList of animals which should be a property of your zoo class.  This ArrayList should hold IAnimal or AnimalBase types.
2. Now write a Main method in which you get the instance of the zoo singleton.  Go on to create instances of animals and add them to the zoo.
3. Print out all of the animals in the zoo

## Practice using the debugger in intellij

__Use the debugger in intellij to track the zoo singleton and ensure that its behaviour is exactly as you expect__


## Simple factory class

1. Create an AnimalFactory class with a makeAnimal() method which takes the type of animal to be created and a name for that animal as parameters, for example makeAnimal("elephant", "elmer"). The method should return an object of the correct type of animal. Use this in your main method to neatly add animals to the zoo.  You will need to make use of polymophism via the the IAnimal inteface or AnimalBase class.

# Extension tasks

## Factory method pattern

1. Take the previous exercise to the next level by creating a IAnimalFactory interface, and AnimalFactory classes for each of your animals, or groups of animals such as Herbivores and Carnivores.  Add logic for adding the different kinds of animals with different characteristics such as different kinds of food or sounds.

## Combine factory method and singleton

1. Use your factory classes as above to populate your zoo.  


## Builder pattern

Implement the Builder pattern to create enclosures for different animals with appropriate land, water and boundary features (you will find example code and explanation in the slides)

## Random number generator

Create a singleton that can generate unique, random ID numbers for your animals.
