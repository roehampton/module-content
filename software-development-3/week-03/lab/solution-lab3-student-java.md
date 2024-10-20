# Solution lab 3: Student/staff/Person example (with inheritance)

Person.java

```java
abstract class Person {

    //Properties
    protected String firstName;
    protected String lastName;

    //Constructor
    public Person(String firstName, String lastName) {
        this.firstName = firstName;
        this.lastName = lastName;
    }

    //Method to return an info string about the student
    public String print() {
        return String.format("Student name %s %s", this.firstName, this.lastName);
    }
}

```


Student.java

```java

public class Student extends  Person {

    int courseId;

    //Constructor
    public Student(String firstName, String lastName, int courseId) {
        super(firstName, lastName);
        this.courseId = courseId;
    }

    //Method to return an info string about the student
    @Override
    public String print() {
        return String.format("Student %s %s is in course %s", this.firstName, this.lastName, this.courseId);
    }
}








```


Staff.java
```java
public class Staff extends Person {

    private int salary;

    //Constructor
    public Staff(String firstName, String lastName, int salary) {
        super(firstName, lastName);
        this.salary = salary;
    }

    //Method to return an info string about the student
    @Override
    public String print() {
        return String.format("Staff member %s %s has salary %s", this.firstName, this.lastName, this.salary);
    }
}





```
Main.java


```java

import java.util.ArrayList;
import java.util.List;

public class Main {
    public static void main(String[] args) {
        Person su1 = new Student("Lisa", "Haskel", 3);
        Person st1 = new Staff("Touseef", "Tahir", 1000);

        System.out.println(su1.print());
        System.out.println(st1.print());
    }

}





```