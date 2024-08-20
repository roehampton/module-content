# Software Development 3 lab week 3
## Inheritance


### Student example

Implement inheritance using the student example from week 1 as your starting point.  
Start by drawing a class diagram showing the Person, Student and Staff classes.  
  
* Create a 'Person' abstract base class and derived classes Student and Staff.  
* Person should have a firstname and lastname
* Person should have a printName() method that returns the firstname and last name in a single string.
* Students only should have a course and staff only should have a salary.
* The Person constructor should take the firstname and lastname as parameters.
* The staff and student classes should have the relevant 'getters' and 'setters' so that course and salary can be set and retrieved.
* Create a virtual method in the base class "Print()" and override it in the Student and Staff derived classes so that:

   * The Staff print() method returns firstname, lastname and salary
   * The Student print() method returns firstname, lastname and course name
   
* Write a Main program that creates some students and staff objects, and uses both the print() and the printName() methods to show some output.
   


### Zoo animals example

Refactor the zoo animals example from week 2 such that there is a base class: AnimalBase from which the Elephant, Lion etc. inherit.


### Coursework

Start to plan out a class diagram for the coursework,  making use of what you know now about inheritance as well as encapsulation and interfaces.




### Helpful Resources

  * Lab 1 solution (student class is at the end) [Lab1 solution](https://roehampton.github.io/module-content/software-development-3/week-01/lab/lab-1-solutions.html)
  * Worked example of inheritance (shapes) [Shapes worked example](./solution-lab3.html)
  * Use the lecture notes to help you as most of the student example is there.
  * Zoo animals solution (no inheritance) [Zoo animals example with IAnimal interface](https://roehampton.github.io/module-content/software-development-3/week-02/lab/lab2solutions.html)
  * Solution: [lab 3 solution] (https://github.com/roehampton/module-content/blob/master/software-development-3/week-03/lab/solution-student-lab3.md)
