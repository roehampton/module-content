# Introduction to Object Orientated Programming

In this lab we will look at how you can design and organise your code by using Object Orientated principles.

We will use javascript in the backend (using node.js/ express.js) as this will help you to build a good structure for your server-side code which organises the data which will be pulled from the database (we will connect to a database in next weeks lab).

The emphasis in this lab is on learning the basics of OOP that apply to all languages that support OOP.

## Preparation

>Ensure that you have the express.js code from last weeks lab up and running.  ie.

>Your express-server.js file that contains the following:

```Javascript

// Import express.js
const express = require("express");

// Create express app
var app = express();

// Create a route for root - /
app.get("/", function(req, res) {
    res.send("Hellox world!");
});

// Create a route for /goodbye
// Responds to a 'GET' request
app.get("/goodbye", function(req, res) {
    res.send("Goodbye world!");
});

// Create a dynamic route for /hello/<name>, where name is any value provided by user
// At the end of the URL
// Responds to a 'GET' request
app.get("/hello/:name", function(req, res) {
    // req.params contains any parameters in the request
    // We can examine it in the console for debugging purposes
    console.log(req.params);
    //  Retrieve the 'name' parameter and use it in a dynamically generated page
    res.send("Hellox " + req.params.name);
});

// Start server on port 3000
app.listen(3000,function(){
    console.log(`Server running at http://127.0.0.1:3000/`);
});
```
Preparation Tasks:

1. Please rename the ```express-server.js``` file to ```app.js```  As this is a more standarised structure for express.
2. Ensure you can run the application from the terminal using EITHER

```nodemon app.js```

OR 

```supervisor app.js```

3. Check that you can access 'Hello world' at http://127.0.0.1:3000/
4. Check that you can update your code and trigger a reload so you can see your changes immediately by changing the out put to 'Hello x' (you should see the server reload in your console in response to your saving the file)


## Object-orientation in JavaScript

JavaScript is an object-oriented language. 

In OOP, your objects are designed to model entities or objects in the real world.

Remember the following:

 * Classes are the code that define objects​: objects are specific **instances of** classes

 * Classes contain both Data (properties) and behaviour (functions/methods) ​

 * Classes should be modelled on real-world entities or concepts​

 * The 'black box' principle – the implementation within a class can be changed so long as the inputs and outputs remain the same.  This supports maintainability​

 * Re-usability – classes can be re-used throughout your programme and exported into others.  Inheritance and abstraction can be used to make the code even more re-usable

You've already been using objects in JavaScript -- `document.write()` means call (invoke, use) the `write` method on the `document` object. The `document` object is the web page your JavaScript program was executing on.

> ### JavaScript's History of OOP
>
> JavaScript is actually an implementation of something called [ECMAScript](https://en.wikipedia.org/wiki/ECMAScript). Until 2015, objects where possible in JavaScript, but not in a manner most programmers would recognise. For example, there was no `class` keyword. ECMAScript 2015 (or ES6) introduced classes and a variety of other language features, making it more similar to Python and Java, for example.
>
> This means there are many JavaScript tutorials online that ignore classes, and write object-oriented code in a strange and hard to maintain manner. We will be using the language features of ES6 which provides a better OOP experience.

### Classes in JavaScript

To declare a class in JavaScript we use the `class` keyword. For example:

```js
class Student {
  // ... contents of the class.
}
```
Note: that class names usually start with a capital letter. This is a style convention, preferred, but not imposed by the language.  Languages and indeed individual companies set style guides for example: https://google.github.io/styleguide/jsguide.html.


You will usually put the class definition in a file with the same name as the class, but in lower case.  You can also tidy your codebase by putting your class definition in a directory called 'models'.  We are calling it models because we are loosly using the MVC (Model View Controller) design pattern in which the 'models' contain code related to data, the 'views' handle presentation and the 'controller' mediates between the two.  Currently, the app.js file is your controller, and we will add views later on.

### Getting started...

1. Create a directory in the same directory as your app.js file called 'models'
2. Inside the models directory, create a file called student.js

Now you can begin writing your Student class.

A class needs a `constructor` which is used to create instances of the class. For example:

```js
class Student {
  constructor() {
    // ... define initial variables
  }
}
```



We define the attributes (properties) (data) of the class by listing them in the class definition.  Depending on the languge, we may or may not set a data type and we may be able to set default values that will be present in every object (instance of the class, remember)

```js
class Student {
  // Attributes
  firstName;
  lastName;
  courseId;
  
  constructor() {
  }
}
```

Add this code to your student.js file

### Using your class definition

To run your code you need to do the following:

1. Add the following to the end of your ```students.js``` file.  

```js
module.exports =  {
      Student
  }
```

You will use this technique frequently... this tells your node.js application that your Student code (module, in other words) is ready and available for use throughout your application.  You use this technique for functions as well as classes.

1. In your ```app.js``` file, add the following line near the top. This tells makes the code for your Student class available to your app.js file:


```js
const { Student } = require('./models/student.js');
```

2. Now you can use the code you have written to create and examine an object created from the Student class.  Add the following additional code to your root route in app.js

```js
app.get("/", function(req, res) {

    // Instantiate a Student object using the student class definition
    var student1 = new Student();
    
    // Examine the object you have created
    console.log(student1);
    
    // Send some output to the browser - doesn't matter what it is right now
    res.send("Hello world!");
});

```

Save your changes, check in your terminal window that nodemon or supervisor has detected your changes and reloaded, then reload http://localhost:3000.  The web page should look the same, but you should see the following in your VS studio code console.

```bash
[nodemon] restarting due to changes...
[nodemon] starting `node app.js`
Server running at http://127.0.0.1:3000/
Student {
  firstName: undefined,
  lastName: undefined,
  courseId: undefined
}
```

**Well done** You have created your first class, made it available to your application, instantiated an object using your class definition and examined it in the console.


## Building your Student class



Our class becomes a lot more useful if we add parameters to the constructor that will set the initial values of our attributes.  This will also help us understand the relationship between a class (a template or blueprint for our object) and our object (a specific instance of a given class )

```js
class Student {
  // Attributes
  firstName;
  lastName;
  courseId;
  
  constructor(firstName, lastName, courseId) {
  
	  this.firstName = firstName;
	  this.lastName = lastName;
	  this.courseId = courseId;
  }
}
```

The `this` keyword is used to refer to the local object, ie. the very object we are defining, So writing `this.firstName(firstName)` means...
Assign the value of the argument supplied to the function firstName, and assign it to the object property called firstName.  

*Note that in this case the name of the parameter and the class property match, but they don't have to, as this.firstName and firstName are completely different variables.


#### Your task
Go back to your app.js file and amend your root route to do the following:

1. Create an object called Student1 with firstName Lisa and lastName Haskel and courseId 1,
2. Create a second object called Student2 with firstName Kevin and lastName Chalmers and courseId 2.
3. Use console.log() to examine both of your objects.
4. Observe how you can access the attributes of your class directly using the dot notation.  Try the following:

```js
console.log(student1.firstName);  
```

5. Now add the student1.firstName to the browser output so you will see Hello and the the firstname of Student1.

### Methods

So far we have looked at the following ideas with objects:

- Defined classes using the `class` keyword.
- Defined a `constructor` for a class.
- Created objects (class instances) using the `new` keyword.
- Added attributes to a class.
- Set attributes of an object in the `constructor` using the `this` keyword.

So far, we have covered the data aspect of an object. Classes become much more interesting when we add behaviour that uses that data. Remember that we use our classes to model real-world things and their behaviour to make our code more understandable.

Methods are very much like functions ie. re-usable sections of code that can be passed parameters.  

Lets add a method to our student class to return a formatted version of a student's name.

Add the method inside the body of the class, underneath the constructor:

```js
 getFormattedName() {
        return this.firstName + ' ' + this.lastName;
    }
```

Now go back to your app.js file and use this method to output some student names to the browser.

**Exercise:** Add an additional attribute to your Student class called Year of Birth.  Write a method to return the current age of the student.

### Referencing classes within other classes

You start to see the power of OOP when you see how an object can be an attribute of another object.

Imagine a student records system that wants to print a register which consists of a list of expected students plus a teachers name and room number. We could implement this by having a class called Lesson, where one of its attributes is an array of Students.  OOP encourages us to take a design led approach, so lets do a diagram before we try any implementation.  See the below:

![Image](./class-lesson.png)


**Your task**
Implement the Lesson class as shown here.
In the addStudents method, you should push a student object onto the students array in the lesson class.

In your app.js file, write some code that will

1. create a lesson object with a teachers name and room number
2. populate the students attribute of the Lesson object with student objects
3. Finally, create a register by printing out the lesson teacher, room number and all students

[Solution here](./solution.md)


### Public and private modifiers

Serverside JavaScript supports private attributes and methods. These are attributes and methods only accessible from within the object itself. We denote a private member with a `#`.

The reason for this is the OOP principles of 'ecapsulation' and the 'black box'.  We want to control how other parts of your program access the attributes and methods so we can continually improve their internal implementation if we want to.


```js
class Example {
  // A private attribute
  #value1;
  
  // A private method
  #method1() {
  
	}
}
```

Let us look at an example by extending our student class. Update your `student.js` file to the following:

```js

class Student {
    // Attributes
    #firstName;
    #lastName;
    #courseId;
    
    constructor(firstName, lastName, courseId) {
    
        this.#firstName = firstName;
        this.#lastName = lastName;
        this.#courseId = courseId;
    }

    getFormattedName() {
        return this.#firstName + ' ' + this.#lastName;
    }
  }

  module.exports = {
      Student
  }
```

In this way, we have ensured that the only way other parts of our program can access the names of our students is via the getFormattedName() method.  This helps us enforce consistency and quality.

## Getters and Setters

JavaScript classes support special methods known as getters and setters. These allow getting and setting attributes of an object while keeping them private within the class.  This is part of the principle of encapsulation.

We use the keywords `get` and `set` to do so.

```js 
class Example {
  #value;
  
  constructor(value) {
    this.#value = value;
  }
  
  // Get value
  get value() {
    return this.#value;
  }

	// Set value
	set value(value) {
    this.#value = value;
  }
}

// Create Example object.
var example = new Example(5);
// Get value
var val = example.value;
// Set value
example.value = 10;
```

We can update our `student.js` file to have getters and setters:

```js

class Student {
    // Attributes
    #firstName;
    #lastName;
    #courseId;
    
    constructor(firstName, lastName, courseId) {
    
        this.#firstName = firstName;
        this.#lastName = lastName;
        this.#courseId = courseId;
    }

    getFormattedName() {
        return this.#firstName + ' ' + this.#lastName;
    }

    get firstName() {
        return this.#firstName;
    }

    get lastName() {
        return this.#lastName
    }

    set firstName(firstName) {
        this.#firstName = firstName;
    }

    set lastName(lastName) {
        this.#lastName = lastName;
    }
  }



  module.exports = {
      Student
  }
```

Now in our code that uses the class we can do the following

```js
// use the getter
 output += '<p>' + student.firstName + '</p>';
 
// use the setter: make the firstname john
student.firstName = 'john';
 
```


> ### Why Have Getters and Setters?
>
> OK, why did we do through this process when we could have just left our attributes public. Getters and setters have a number of benefits, but in particular they allow:
>
> - Public getters allow access to an attribute while stopping it being updated outside the object.
> - Getters and setters can have additional code, which can, for example, check that the correct value is being set.

### Now you try

Make the attributes privat and write getters and setters for the `Lesson` class. 

