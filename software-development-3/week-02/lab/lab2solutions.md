# Lab 2 solutions

## Animal classes with interface

![Animals with interface](./animals-with-interface.png)

## IAnimal.cs

```c#

interface IAnimal 
{
    public string makeSound();
    public string getFood();
    public string getName();
    public void setName(string name);

}
```



## Elephant.cs

```c#
class Elephant : IAnimal 
{
    // Properties
    private string name;
    private string sound = "TRUMPETTTT";
    private string eats = "Twigs and leaves";

    public Elephant(string name)
    {
        this.name = name;
    }

    public string makeSound()
    {
        return this.sound;
    }

    public string getFood()
    {
        return $"give me {this.eats}";
    }

    public string getName()
    {
        return $"{this.name}, the {this.GetType()}";
    }
    
    public void setName(string name)
    {
        this.name = name;
    }


}

```
## Lion.cs

```c#
class Lion : IAnimal 
{
    // Properties
    private string name;
    private string sound = "ROAAAR";
    private string eats = "Lots of meat";

    public Lion(string name)
    {
        this.name = name;
    }

    public string makeSound()
    {
        return this.sound;
    }

    public string getFood()
    {
        return $"give me {this.eats}";
    }

    public string getName()
    {
        return $"{this.name}, the {this.GetType()}";
    }
    
    public void setName(string name)
    {
        this.name = name;
    }

}

```



## Program.cs

```c#

using System;

class Program
{

    public static void Main()
    {
        List<IAnimal> animals = new List<IAnimal>();

        // Add some animals
        animals.Add(new Lion("Elsa"));
        animals.Add(new Elephant("Elmer"));
        animals.Add(new Elephant("George"));
        animals.Add(new Lion("Walter"));

        //List the animals
        foreach (IAnimal animal in animals)
        {
            Console.WriteLine(animal.getName());
        }

        //Feed the animals
        foreach (IAnimal animal in animals)
        {
            Console.WriteLine(animal.getFood());
        }
    }
}

```


