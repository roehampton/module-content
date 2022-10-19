## Implmenting the builder pattern

#### The interface for the builder classes
```c#
public interface IEnclosureBuilder {
    public void buildLand();

    public void buildWater();

    public void buildBoundary();

    public void reset();

    public List<string> getEnclosure();

}

```

#### The concrete builder for an elephant enclosure
```c#
// Note that inheritance could be used here
class ElephantEnclosureBuilder : IEnclosureBuilder
{
    //Product - the Elephant Enclosure features
    List<string> enclosureFeatures = new List<string>();

    public void reset()
    {
        this.enclosureFeatures = new List<string>();
    }
    public void buildLand()
    {
        enclosureFeatures.Add("large meadow");
    }

    public void buildWater()
    {
        enclosureFeatures.Add("Large water hole");
    }

    public void buildBoundary()
    {
        enclosureFeatures.Add("wide ditch");
    }

    public List<string> getEnclosure()
    {
        return this.enclosureFeatures;
    }


}
```

#### The concrete builder for a penguin enclosure
```c#
// Note that inheritance could be used here
class PenguinEnclosureBuilder : IEnclosureBuilder
{
    //Product - the Penguin Enclosure features
    List<string> enclosureFeatures = new List<string>();

    public void reset()
    {
        this.enclosureFeatures = new List<string>();
    }
    public void buildLand()
    {
        enclosureFeatures.Add("Small patch of grass");
    }

    public void buildWater()
    {
        enclosureFeatures.Add("Large lake with slide");
    }

    public void buildBoundary()
    {
        enclosureFeatures.Add("Low wall");
    }

    public List<string> getEnclosure()
    {
        return this.enclosureFeatures;
    }


}
```

#### The concrete builder for a lion enclosure
```c#
// Note that inheritance could be used here
class LionEnclosureBuilder : IEnclosureBuilder
{
    //Product - the Lion Enclosure features
    List<string> enclosureFeatures = new List<string>();

    public void reset()
    {
        this.enclosureFeatures = new List<string>();
    }

    public void buildLand()
    {
        enclosureFeatures.Add("Hills and rocks");
    }

    public void buildWater()
    {
        enclosureFeatures.Add("Small water hole");
    }

    public void buildBoundary()
    {
        enclosureFeatures.Add("Large ditch and high fence");
    }

    public List<string> getEnclosure()
    {
        return this.enclosureFeatures;
    }


}
```


#### Director class - knows how specific animal enclosures are built
```c#
// This class knows how to build specific animal enclosures
class AnimalEnclosureDirector
{
    private IEnclosureBuilder enclosureBuilder;

    public AnimalEnclosureDirector(IEnclosureBuilder builderType) {
        this.enclosureBuilder = builderType;
    }
    public List<string> makeLionEnclosure()
    {
        this.enclosureBuilder.buildLand();
        this.enclosureBuilder.buildWater();
        this.enclosureBuilder.buildBoundary();
        return this.enclosureBuilder.getEnclosure();
    }

    public List<string> makeElephantEnclosure()
    {
        this.enclosureBuilder.buildLand();
        this.enclosureBuilder.buildWater();
        this.enclosureBuilder.buildBoundary();
        return this.enclosureBuilder.getEnclosure();
    }

        public List<string> makePenguinEnclosure()
    {
        this.enclosureBuilder.buildLand();
        this.enclosureBuilder.buildWater();
        this.enclosureBuilder.buildWater();
        this.enclosureBuilder.buildBoundary();
        return this.enclosureBuilder.getEnclosure();
    }


}
```

### IAnimal, from week 2

```c#
public interface IAnimal 
{
    public string makeSound();
    public string getFood();
    public string getName();
    public void setName(string name);

}
```


### Elephant, from week 2
```c#
class Elephant : IAnimal 
{
    // Properties
    private string name;
    private string sound = "TRUMPETTTT";
    private string eats = "Twigs and leaves";

    public Elephant(string name) {
        this.name = name;
    }
    public string makeSound() {
        return this.sound;

    }
    public string getFood() {
        return $"give me {this.eats}";
    }
    public string getName() {
        return $"{this.name}, the {this.GetType()}";
    }
    
    public void setName(string name) {

        this.name = name;

    }


}
```


### Lion, from week 2
```c#
class Lion : IAnimal 
{
    // Properties
    private string name;
    private string sound = "ROAAAR";
    private string eats = "Lots of meat";

    public Lion(string name) {
        this.name = name;
    }
    public string makeSound() {
        return this.sound;

    }
    public string getFood() {
        return $"give me {this.eats}";
    }
    public string getName() {
        return $"{this.name}, the {this.GetType()}";
    }
    
    public void setName(string name) {

        this.name = name;

    }


}
```


### The Factory method class, knows how to create different kinds of animals
```c#
public class AnimalFactory
{

    public IAnimal makeAnimal(string type, string name)
    {

        if (type == "Lion")
        {
            return new Lion(name);

        }

        else if (type == "Elephant")
        {
            return new Elephant(name);
        }

        else {
            return new Lion("default animal");
        }

    }

}
```


### The singleton zoo

```c#

// Make the zoo into a singleton as it is the single point of reference for the zoo.
class Zoo
{
    // The Zoo holds an instance of itself.
    private static Zoo zooInstance = null;
    private List<IAnimal> animals = new List<IAnimal>();

    // Have a factory class ready and waiting
    private AnimalFactory animalFactory = new AnimalFactory();

    private Zoo()
    {

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

    public void addAnimal(string type, string name)
    {
        this.animals.Add(this.animalFactory.makeAnimal(type, name));

    }

    public void feedAnimals()
    {

        foreach (IAnimal animal in animals)
        {
            Console.WriteLine(animal.getFood());
        }
    }

    public void listAnimals()
    {
        foreach (IAnimal animal in animals)
        {
            Console.WriteLine(animal.getName());
        }
    }
}


```


### Main
```c#
﻿using System;

class Program
{

    static void Main()
    {

        // Demonstrate the singleton pattern
        // Now lets make a zoo, there should only be one.
        Zoo zoo = Zoo.getInstance();

        /* Create the zoo without a factory
        zoo.addAnimal(new Lion("Elsa"));
        zoo.addAnimal(new Elephant("Elmer"));
        zoo.addAnimal(new Elephant("George"));
        zoo.addAnimal(new Lion("Walter"));
        */

        // Create the zoo with factory.  Now the client code doens't need to know anything about classes for different animals.
        // We use an animal factory object that is part of the zoo singleton.
        // We use the IAnimal interface we created already.
        zoo.addAnimal("Lion", "Elsa");
        zoo.addAnimal("Elephant", "Elmer");

        // Get the instance again and see if its the same
        // Note that this cannot run:  Zoo zoo1 = new Zoo();

        Zoo zoo1 = Zoo.getInstance();

        zoo1.feedAnimals();
        zoo1.listAnimals();


        // Lets demonstrate the builder pattern. 
        // Lets instantiate the builder for Elephants
        IEnclosureBuilder eb = new ElephantEnclosureBuilder();
        AnimalEnclosureDirector ed = new AnimalEnclosureDirector(eb);
        List<string> enclosure = ed.makeElephantEnclosure();

        // find out if we got what we expected for elephants
        Console.WriteLine("The Elephant house has...");
        foreach (string feature in enclosure)
        {
            Console.WriteLine($"    {feature}");
        }

        // Lets instantiate the builder for Lions
        IEnclosureBuilder el = new LionEnclosureBuilder();
        AnimalEnclosureDirector ld = new AnimalEnclosureDirector(el);
        List<string> lenclosure = ld.makeLionEnclosure();

        // find out if we got what we expected for lions
        Console.WriteLine("The Lion house has...");
        foreach (string feature in lenclosure)
        {
            Console.WriteLine($"    {feature}");
        }

        // Lets instantiate the builder for Penguins
        IEnclosureBuilder pl = new PenguinEnclosureBuilder();
        AnimalEnclosureDirector pd = new AnimalEnclosureDirector(pl);
        List<string> penclosure = pd.makePenguinEnclosure();

        // find out if we got what we expected for Penguins
        Console.WriteLine("The penguin house has...");
        foreach (string feature in penclosure)
        {
            Console.WriteLine($"    {feature}");
        }


    }
}```
