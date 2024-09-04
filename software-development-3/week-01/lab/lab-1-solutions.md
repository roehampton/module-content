# Lab 1 solutions


## Java fundamentals

#### HelloWorld.java


```java
package org.roehampton.sd3.examples;
// You need to import the ArrayList library
import java.util.ArrayList;

public class HelloWorld {
    public static void main(String[] args) {

        /* ArrayLists are collection objects that can be dynamic in size.
        The type of thing that is going to be stored in the ArrayList needs to be specified in the angled brackets.
        Also note the keyword 'new'.
         */
        ArrayList<String> myList = new ArrayList<String>();
        myList.add("one");
        myList.add("two");
        myList.add("three");

        // Check the contents of the list:
        System.out.println(myList);

        // A simple 'for' loop can iterate over myList, creating a new variable list with every iteration of the loop
        for  (String listElement : myList) {
            // Note use of print instead of println to suppress the line break
            System.out.print("index:" + myList.indexOf(listElement));
            System.out.println(listElement);

        }

        // Now with the conditional
        for  (String listElement : myList) {
            // Note use of print instead of println to suppress the line break
            if (listElement.equals("three")) {
                System.out.println ("Got three");
            }
            else if (listElement.equals("two")) {
                System.out.println ("Got two");
            }
            else {
                System.out.println("Got something else");

            }
        }
    }
}
```


#### Student class

##### Student.java

```java

public class Student {

    //Properties
    String firstName;
    String lastName;
    int courseId;

    //Constructor
    public Student(String firstName, String lastName, int courseId) {
        this.firstName = firstName;
        this.lastName = lastName;
        this.courseId = courseId;
    }

    //Method to return an info string about the student
    public String getFormattedName() {
        return String.format("Student %s %s is in course %s", this.firstName, this.lastName, this.courseId);
    }
}



```





```java
public class HelloWorld {
    public static void main(String[] args) {
        
        // Create instances of student
        Student s1 = new Student("Lisa", "Haskel", 1);
        Student s2 = new Student("Touseef", "Tahir", 2);

        // Print the students info
        System.out.println(s1.getFormattedName());
        System.out.println(s2.getFormattedName());

    }
}
```