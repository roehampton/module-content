# Software Development 1 
# Lecture 11 -- Object Orientation


In this lab we'll explore:

1. In Python, everything&#39;s an object.

2. The road ahead

We shall cover a key aspect of phython: the ability to abstract anything as an object and we'll end with an overview of all the things that you can expore with python.


## Lesson 1: In Python, everything&#39;s an object.
Video: https://roehampton.cloud.panopto.eu/Panopto/Pages/Viewer.aspx?id=63d1f6a6-fd00-4fa5-b2d5-ac8700b404b8

We previously talked about how functions allow you to compartmentalize blocks of code that do specific tasks. However, python is an object-oriented language, which allows you to compartmentalize code _and_ data_._ The term _object_ stems from the fact that the model resembles objects in the real word in that each object is a thing that has certain attributes and characteristics that make it unique. For example, a car is an object. In the real world, there are lots of different cars that differ in size, shape, colour, and features. But they&#39;re all still cars. We can recognize one when we see it, even though they are not all the same. Like python&#39;s functions, they all have certain _attributes_ (year, make, model, colour) that make each one unique. They also share certain actions or _methods_ that all cars can do. For example, cars all have go, stop, and turn actions you can control pretty much the same in each one. You can think of the class &quot;cars&quot; as being sort of a factory that creates all cars. After it&#39;s created, each car is an independent object. Changing one car has no effect on the other cars or the Car class.

![Alt text](img_car.png?raw=false "A class to make car objects")

Class then is like of blueprint for the construction of objects. For instance, take dogs. No, there is no physical blueprint for creating dogs. But there is some dog DNA that pretty much does the same thing. The dog DNA can be considered a type of blueprint (like a Python class) from which all dogs are created. Dogs vary in the attributes like breed, colour, and size, but they share certain behaviours (methods) like &quot;bark&quot; &quot;eat&quot; and &quot;sleep.&quot;

![Alt text](img_dog.png?raw=false "A class to make dog objects")

The main point is that each instance of a class is its own independent object with which you can work. Changing one instance of a class has no effect on the class or on other instances, just as painting one car a different colour has no effect on the car factory or on any other cars produced by that factory. For now

- **Class:** A piece of code from which you can generate a unique object, where each object is a single instance of the class. Think of it as a blueprint or factory from which you can create individual objects.
- **Instance:** One unit of data plus code generated from a class as an instance of that class. Each instance of a class is also called an _object_ just like all the different cars are objects, all created by some car factory (class).
- **Attribute:** A characteristic of an object that contains information about the object. Also called a _property_ of the object. An attribute name is preceded by dot, as in dog.name which may contain the name for one of our dog objects.
- **Method:** A Python function that&#39;s associated with the class. It defines an action that object can perform. In an object, you call a method by preceding the method name with a dot, and following it with a pair of parentheses. For example dog.bark() may be a method that plays a barking sound in a dog abject.

You create your own classes like you create your own functions. All you need is the word _class_ followed by a space, a class name of your choosing, and a colon.

**Style Tip:** It&#39;s customary to start a class name with an uppercase letter to help distinguish classes from variables.

For example, to create a new class named Dog

    # Define a new class name Dog. 

    class Dog:
    “““This is a class that makes dog objects”””
    variable = “dog’s name”

      def function(self)”
        print(“Guau Guau”)

    new_dog= Dog()


Now the variable &quot;new\_dog&quot; holds an object of the class &quot;Dog&quot; that contains the variable (dog&#39;s name) and the function (for barking) defined within the class called &quot;Dog&quot;.

We can access the variable inside of the newly created object &quot;new\_dog&quot;

    print(new_dog.variable)
    
You can create multiple different objects that are of the same class(have the same variables and functions defined). However, each object contains independent copies of the variables defined in the class. For instance, if we were to define another object with the &quot;Dog&quot; class and then change the string in the variable above:

    new_dog1= Dog()
    new_dog2= Dog()

    new_dog1.variable= “Fido”
    new_dog2.variable= “Rex”


    print(new_dog1.variable)
    print(new_dog2.variable)


![Alt text](img_class.png?raw=false "A class to make car objects")

There&#39;s much more to know about classes that would require a course on it&#39;s own. However I would encourage you to experiment with these. The takeaway is that a class is just a way of organizing information about a type of data so a programmer can reuse elements when making multiple instances of that data type.



