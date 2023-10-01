# Software Development 3

## Lab  Week 2


We will practice planning and creating classes, adding methods, modifiying them to be public or private as appropriate.

We will then create an interface to see how 'polymorphism' can occur in our code.

__Today - we are going to model a zoo and its animals.__


1. Consider classes for Lion and Elephant with some relevant properties that you can think of.  Sketch a class diagram showing the basic properties and behaviours you are going to implement. Give your two classes at least one method, makeSound() which returns approriate animal sounds. 

2. Implement your Lion and Elephant classes in c#. You may use the default constructor for now, ie. an object will be created with no properties set.  

3. Write a main method in your Program.cs file that will create at least one Lion and one Elephant, and call the methods you have chosen to create, something like the below (yours may differ):

```c#
class Program
{
	public void main() 
	{

		Elephant e1 = new Elephant();
		Lion l1 = new Lion();

		Console.WriteLine(l1.makeSound());
		Console.WriteLine(e1.makeSound());

	}
}

```

3. Now lets improve the properties of your animals, set some in the constructor, ensure they are private and create getters and setters for client code to interact with them.

   * Create an age property for each of your animals __that is private__
   * Set the age of the animal in its constructor
   * Provide getters and setters to retrieve or replace the age value (you may use the c# or generic OOP way of writing these)
   * Create at least one additional property in your class with getters and setters.

   * Demonstrate the use of your class in your Main method.

4. Create an interface called IAnimal and define at least two methods that you think MUST be present for all your animal classes.  For example,  makeSound() and eatFood().  

5. Amend your Elephant and Lion classes such that they must implement the IZooAnimal interface,  ie. indicate in the class definition that the Interface should be implemented. You will notice that if the necessary methods are not yet implemented in your classes, your code will not compile until you add them.

6. Once the Elephant and Lion are working, add a new class, Penguin, that implements IZooAnimal and has the required methods.

7. Write client code that creates a list of IZooAnimal objects which you can call 'zoo', and then loops through them calling the methods required by the interfaces.




#### Reference code

Everything you need for the lab can be adapted from the example code from the lecture.  Here it is again:


#### Class with private property and getters and setters 

Square class

```c#
// Square implements the IShape interface
class Square : IShape
{
    // Property is private and has a default value
    private int height = 200;

    // Returns the area of the shape
    public double getArea()
    {
        return this.height * this.height;
    }

    // Returns the perimeter of the shape
    public double getPerimeter()
    {
        return 4 * this.height;
    }
    // Set the otherwise private property from outside the program
    public void setHeight(int h)
    {
        this.height = h;
    }

    // Return the otherwise private property from outside the prgram

    public int getHeight()
    {
        return this.height;
    }

}




 ```
 
 Circle class
 
 ```c#
 // Circle class implements the IShape interface
class Circle : IShape
{
    // c# style creation of radius property with getters and setters
    public int radius { get; set; } = 50;

    public double getArea()
    {

        // Area of a circle πr-squared 
        return Math.PI * (this.radius * this.radius);
    }

    public double getPerimeter()
    {

        // Circumference of a circle 2πr
        return 2 * Math.PI * this.radius;

    }
}
```


IShape interface

```c#
interface IShape
{
    public double getArea();
    public double getPerimeter();

}
```

Client

```
using System;

class Program
{

    static void Main()
    {
        // Create a list of different shapes (they must all implement IShape)
        List<IShape> shapes = new List<IShape>();

        // New square
        Square s1 = new Square();
        // Use the setter we created
        s1.setHeight(30);
        shapes.Add(s1);

        // New circle
        Circle c1 = new Circle();
        // Use the c# style shorthand setter
        c1.radius = 20;
        shapes.Add(c1);

        // Another new circle
        Circle c2 = new Circle();
        shapes.Add(c2);

        // Loop through the shapes getting their perimeter and radius - code works regardless if its a circle or a square
        foreach (IShape s in shapes) {
            Console.WriteLine($"{s.GetType()} has perimeter {s.getPerimeter()} and area {s.getArea()}");
        }
    }
}
```
