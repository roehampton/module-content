# Software Development 3 lab week 3
## Inheritance


### Student example

Implement inheritance using the student example from week 1 as your starting point.  
Start by drawing a class diagram showing the Person, Student and Staff classes.  
  
* Create a 'Person' abstract base class and derived classes Student and Staff.  
* Person should have a firstname and lastname
* Person should have a PrintName() method that returns the firstname and last name in a single string.
* Students only should have a course and staff only should have a salary.
* The Person constructor should take the firstname and lastname as parameters.
* The staff and student classes should have the relevant 'getters' and 'setters' so that course and salary can be set and retrieved.
* Create a virtual method in the base class "Print()" and override it in the Student and Staff derived classes so that:

   * The Staff Print() method returns firstname, lastname and salary
   * The Student Print() method returns firstname, lastname and course name
   
* Write a Main program that creates some students and staff objects, and uses both the Print() and the PrintName() methods to show some output.
   







### Helpful Resources

  * Lab 1 solution (student class is at the end) [Lab1 solution](https://roehampton.github.io/module-content/software-development-3/week-01/lab/lab-1-solutions.html)
  * Worked example of inheritance (shapes) [Shapes worked example](./solution-lab3.html)
  * Use the lecture notes to help you as most of the student example is there.

