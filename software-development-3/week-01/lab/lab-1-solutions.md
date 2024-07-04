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




