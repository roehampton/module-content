#  Lab week 3 solution:  Student/Staff inheritance


Person.cs

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

Student.cs

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

Staff.cs

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


Program.cs

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


output

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
