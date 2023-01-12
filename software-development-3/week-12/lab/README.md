# Simplified booking system


To demonstrate how you may use a boolean property to add some functionality to your classes, we will use the example from weeks 1 - 3 in which we created a person base class with derived classes student and staff.

Please follow and understand this lab and you should then be able to use a boolean property within the base class of your bookable items (accomodation, vehicle, item or whatever you have chosen) to create the ability to 'book' or 'unbook' any of your items.

__You can follow this lab with the video: https://roehampton.cloud.panopto.eu/Panopto/Pages/Viewer.aspx?id=248b714f-1ea3-4fce-b841-af6a01304932__

## Get started

This is the lab solution from week 3.

Please ensure that you have created the four files: Person.cs, staff.cs, Student.cs and the Program.cs as below, and can run the program.cs code to give the expected output.


###  Lab week 3 solution:  Student/Staff inheritance


FILE: Person.cs

```c#
using System;

abstract class Person
{
    protected string firstName;
    protected string lastName;
    
    public Person(string firstName, string lastName)
    {
        this.firstName = firstName;
        this.lastName = lastName;
    }

    // Return a formatted string with persons firstname and last name, this method can be overridden by derived classes
    public virtual string Print()
    {
        // code that returns the first name, last name - but this code is never used as its virtual!!
        return $"Person: {this.firstName} {this.lastName}";

    }

    public string PrintName() {
        // code that returns the first name, last name - can be used by any derived class
        return $"Person: {this.firstName} {this.lastName}";
    }
}
```

FILE: Student.cs

```c#
using System;

class Student : Person
{
	
	private int courseId = 1;

	public Student(string firstName, string lastName, int courseId) : base (firstName, lastName)
	{
		this.courseId = courseId;
	}
	
	// Return a formatted string with students firstname, last name and course: we are overriding the virtual method

    public override string Print()
    {
        // code that returns the first name, last name and course id for the student.
        return $"{this.GetType()}: {this.firstName} {this.lastName} is in course {this.courseId}";
    }
}
```

FILE: Staff.cs

```c#
using System;

class Staff : Person
{
	
	private int salary;

	public Staff(string firstName, string lastName, int salary) : base (firstName, lastName)
	{
		this.salary = salary;
	}
	
	// Return a formatted string with students firstname, last name and course: we are overriding the virtual method

    public override string Print()
    {
        // code that returns the first name, last name and salary for the staff member.
        return $"{this.GetType()}:  {this.firstName} {this.lastName} has salary {this.salary}";
    }
}
```


FILE: Program.cs

```c#
using System;
class Program
{

    // static void main is the entrypoint to your program
    static void Main()
    {
        

        // We can declare EITHER Person or Student/Staff.
        Person st1 = new Student("lisa", "haskel", 1);
        Person st2 = new Staff("arturo", "araujo", 1000);
        Staff st3 = new Staff("Kimia", "Aksir", 1000);

        Console.WriteLine("Using the PrintName method on the Base class -------");

        Console.WriteLine(st1.PrintName());
        Console.WriteLine(st2.PrintName());
        Console.WriteLine(st3.PrintName());
        
        
        Console.WriteLine("Using the Print method on the derived classes -------");
        
        Console.WriteLine(st1.Print());
        Console.WriteLine(st2.Print());
        Console.WriteLine(st3.Print());

    }
}
```

#### expected output

```
Using the PrintName method on the Base class -------
Person: lisa haskel
Person: arturo araujo
Person: Kimia Aksir
Using the Print method on the derived classes -------
Student: lisa haskel is in course 1
Staff:  arturo araujo has salary 1000
Staff:  Kimia Aksir has salary 1000
```

## Add a property to indicate presence/absence

Add a boolean property to your person class.  If the property is true it will indicate that the person is present.  If the property is false it will indicate that the person is absent.

We will set its default value to false.

Add a new property called isPresent to the Person class. The properties should now look like this:

```c#
 protected string firstName;
 protected string lastName;
 protected bool isPresent = false;
 ```
 
## Add get and set methods for your new property
 
 ```c#
 
    // Set the isPresent property.  Should be true if the person is present or false if absent
    public void setIsPresent(bool isPresent) {
        this.isPresent = isPresent;
    }

    // Return the isPresent property
    public bool getIsPresent() {
        return this.isPresent;
    }
 
 ```
 

## Add a method that can output a string indicating presence or absence

This method simply returns a string to indicate presence or absence.  It uses the PrintName() method we have already created.

```c#

	// A nicely formatted string to indicate presence or absence
    public string printPresence() {
        if (this.isPresent == true) {
            return $"{this.PrintName()} is present";
        }
        else {
            return $"{this.PrintName()} is absent";
        }
    }
```

## Make use of your new functionality in your Main program

Add the following lines to your main method in teh Program.cs file (make sure that earlier in your main method you have created the objects st1, st2 and st3)

```cs

        // Mark some people as present or absent
        st1.setIsPresent(true);
        st2.setIsPresent(false);
        st3.setIsPresent(true);

        Console.WriteLine("Printing the register -------");

        Console.WriteLine(st1.printPresence());
        Console.WriteLine(st2.printPresence());
        Console.WriteLine(st3.printPresence());



```

#### Expected output

```

Printing the register -------
Person: lisa haskel is present
Person: arturo araujo is absent
Person: Kimia Aksir is present




```


## Consider how to use this example to design your booking/ reservation system

You could now use this technique to create your booking/ reservation system by creating a property called isReserved in your base class.

You can then use a setIsReserved() method to change the status from unreserved to reserved and reserved to unreserved.  

