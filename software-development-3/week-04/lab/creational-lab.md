# Creational design patterns lab


1. Using your animal classes from week 2, implement the zoo as a singleton pattern ie. ensure that there is always and can always only be one zoo.
2. Create a List of animals as a property of your zoo singleton.
2. Write a Main method in which you create the zoo and then add animals to it using the list you created
3. Create a AnimalFactory class with a makeAnimal() method which takes the type of animal to be created and a name for that animal, for example makeAnimal("elephant", "elmer"). The method should return an object of the correct type, which should implement the IAnimal interface.
4. Add an AnimalFactory property to  your Zoo class and an addAnimal(type, name) method to your zoo so that you can add animals to the zoo in a main method without your main method having to know anything about how the different animals should be created.
5. Implement the Builder pattern to create enclosures for different animals with appropriate land, water and boundary features.
