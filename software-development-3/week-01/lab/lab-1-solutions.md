# Lab 1 solutions

```c#
using System;
class Program
{

    // Performs a calculation
    static void Main()
    {
        int a = 42;
        string b = "119";
        // If c should be a string, then the variables are concatenated
        string c = a + b;
        Console.WriteLine(c);
    }
}
```




OR


```c#
using System;
class Program
{

    // Performs a calculation
    static void Main()
    {
        int a = 42;
        string b = "119";
        // If c should be an int, b needs to be converted to an int
        int c = a + Convert.ToInt16(b);
        Console.WriteLine(c);
    }
}
```


```c#

using System;
class Program
{

    static void Main()
    {
        int a = 42;
        int[] b = { 1, 4, 6, 7 };
        // Print each item in b
        foreach (int item in b)
        {
            Console.WriteLine(item);
        }
    }
}
```




```c#

using System;
class Program
{

    /*
     * Main entrypoint to the code
     * 
     */
    static void Main()
    {
        int a = 42;
        int[] b = { 1, 4, 6, 7 };
        // iterate through b
        foreach (int item in b)
        {
            // Only output if the number is 6
            if (item == 6)
            {
                Console.WriteLine(item);
            }
        }
    }
}
```


```c#

using System;

public class Student
{
	string firstName;
	string lastName;
	int courseId;
	
	public Student(string firstName, string lastName, int courseId )
	{
		this.firstName = firstName;
		this.lastName = lastName;
		this.courseId = courseId;
	}
	
	// Return a formatted string with students firstname, last name and course.
	public string getFormattedName() 
	{
		// code that returns the first name, last name and course id for the student.
		return $"Student: {this.firstName} {this.lastName} is in course {this.courseId}";
	}
}
```
