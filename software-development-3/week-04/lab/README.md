# Lab 4: Class relationships


## Student/staff example

Go back to your person/student/staff example code.

In your previous student class, you had an int for the Course id as a property of the student

Refactor this so that:

   * You create a course class with a course id and course name property, a constructor, and get/set methods accordingly.
   * Instead of the simple int property for the course in the student class, make your course class a property of the student class.
   * Adjust your Print() method of the student to make use of the course class such that the course name can be nicely displayed together with the students' name, ie. your output should be similar to this example:
     '''
     Student: Arturo Arajo is on course Physics
     '''

__HINT__: in your Main method you will need to create a course object before you create at student object so that you can pass the course object as an argument to the student constructor

## Animals example

Find your animals code where you should have your AnimalBase, Lion and Elephant classes ready.

   * Create a new class called 'zoo'.  Give your class properties you think will be relevant which should include (at least) a name and a C# list of your zoo animals.
     
__HINT__: C# lists must specify the type of object that will be in that list.  To enable your list of animals to contain any animal, you can declare it as being a List populated by types of AnimalBase as follows:

```
   List<AnimalBase> animals = new List<AnimalBase>();

```

References: 
https://www.c-sharpcorner.com/article/c-sharp-list/
https://learn.microsoft.com/en-us/dotnet/api/system.collections.generic.list-1?view=net-7.0

  * Create a method in your Zoo class which will add a new animal object to the animals list.
  * Create a method in your Zoo class which will print out a list of all the animals in the zoo
  * Create a Main progam which will create the zoo, add some animals and finally show the name of your zoo and print a list of all the animals in the zoo.

__HINT 2__

To loop through your list of animals try this:

```
        foreach (AnimalBase animal in animals)
        {
            Console.WriteLine(animal.getName());
        }

```

## Animals example extension task

 * In your animal class, add a boolean property to indicate if the animal has been fed.  Set it to false by default.
 * Add a 'setter',such that you can indicate if the animal has been fed recently by setting the boolean property to true.
 * In your Main method, create some animals, add them to the zoo and set some of them to fed recently.
 * Now see if you can print out a list of animals who are still hungry.
