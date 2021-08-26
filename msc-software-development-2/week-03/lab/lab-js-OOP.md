## Object-orientation in JavaScript

JavaScript is an object-oriented language. But what does object-oriented mean? Let us take the [Wikipedia](https://en.wikipedia.org/wiki/Object-oriented_programming) definition (emphasis mine):

> Object-oriented programming (OOP) is a **programming paradigm** based on the concept of **"objects"**, which can **contain data and code**: **data in the form of fields (often known as attributes or properties)**, and **code, in the form of procedures (often known as methods).**

Object-oriented programming (OOP or OO) is a programming paradigm. This just means it is an approach to write programs. For example, you are probably used to *imperative procedural programming*. This is where we build our programs from functions/procedures. Object-orientation is also imperative, but uses objects to construct programs.

OOP has the following terms associated with it:

- **Objects** -- are a collection of data and/or code. Objects are *instances* of classes.
- **Classes** -- are a description of what data and/or code an object has within it.
- **Data** -- the attributes or properties of an object. Essentially, the variables *associated* with an object.
- **Code** -- the procedures, functions, or methods of an object that can be used to manipulate its data.

You've already been using objects in JavaScript -- `document.write()` means call (invoke, use) the `write` method on the `document` object. The `document` object is the web page your JavaScript program was executing on.

> ### JavaScript's History of OOP
>
> JavaScript is actually an implementation of something called [ECMAScript](https://en.wikipedia.org/wiki/ECMAScript). Until 2015, objects where possible in JavaScript, but not in a manner most programmers would recognise. For example, there was no `class` keyword. ECMAScript 2015 (or ES6) introduced classes and a variety of other language features, making it more similar to Python.
>
> This means there are many JavaScript tutorials online that ignore classes, and write object-oriented code in a strange and hard to maintain manner. We will be using the language features of ES6 which provides a better OOP experience.

### Classes in JavaScript

To declare a class in JavaScript we use the `class` keyword. For example:

```javascript
class Foo {
  // ... contents of the class.
}
```

A class needs a `constructor` which is used to create instances of the class. For example:

```javascript
class Foo {
  constructor() {
    // ... define initial variables
  }
}
```

We can then create instances of this class using the `new` keyword:

```javascript
var foo = new Foo();
```

We can say that a class has attributes (data) just by listing them in the class:

```javascript
class Foo {
  // Attributes
  value1;
  value2;
  
  constructor() {
    // ... define values
  }
}
```

And we can pass parameters to the constructor that will set the initial values of these attributes.

```JavaScript
class Foo {
  // Attributes
  value1;
  value2;
  
  // Constructor builds the object
  constructor(value1, value2) {
    // Set local values to parameters given.
    this.value1 = value1;
    this.value2 = value2;
  }
}
```

The `this` keyword is used to refer to the local object. So saying `this.value1` means `value1` associated with this particular object instance. Let us look at a more concrete example -- a `Student` class:

```javascript
// A definition of a student
class Student {
    // Student ID
    id;
    // Student name
    name;

    // Creates a new instance (object) of type Student
    constructor(id, name) {
        // Set the id and name of the object instance
        this.id = id;
        this.name = name;
    }
}

var student = new Student("001", "Kevin Chalmers");
```

Let us turn the student example into a more concrete example. **Create `students.html` with the following code:**

```html
<!DOCTYPE html>
<html>
    <head>
        <title>Student List</title>
        <script src="student.js"></script>
    </head>
    <body>
        <h1>
            Click the button!
        </h1>
        <input type="button" value="Click Me!" onclick="printStudents()">
        <div id="main"></div>
    </body>
</html>
```

> #### What is a `<div>` Tag?
>
> A `<div>` tag is used to define a division or a section of your HTML document. A `<div>` can have any other HTML within it. It is a useful method for creating areas of our document we can manipulate independently. For example, we have created a section called `main` here.

Now we need our `student.js` file:

```javascript
// Tells the browser we want JavaScript to run in strict mode.
// This means faster code, but JavaScript needs to be cleaner.
"use strict";

// A definition of a student
class Student {
    // Student ID
    id;
    // Student name
    name;

    // Creates a new instance (object) of type Student
    constructor(id, name) {
        // Set the id and name of the object instance
        this.id = id;
        this.name = name;
    }
}

// An array of students.
var students = [
    new Student("001", "Kevin Chalmers"), 
    new Student("002", "Lisa Haskel"), 
    new Student("003", "Arturo Araujo")];

function printStudents() {
    // Build text to display
    var text = "";
    // Iterate over all the students
    for (var student of students) {
        text = text + student.id + ": " + student.name + "<br>";
    }
    // Get the main element
    var main = document.getElementById("main");
    // Set the innerHTML to text
    main.innerHTML = text;
}
```

> #### `"use strict";`
>
> `"use strict"` is useful as it tells the browser to have a strict interpretation of our JavaScript code. This means your code must avoid certain issues that lazy JavaScript programmers perform. Our code will be less error-prone, and faster.

> #### `<br>` Tag
>
> The `<br>` tag is just a line break. We are putting a new line after each student in our output.

**Open the web page file so it is opened in your browser. Click the button to ensure that it works correctly.**

#### STOP -- Commit Your Changes!

If your new web page works as expected it is time to commit your updates to GitHub.

1. Add your files to the commit.
2. Create the commit. Use the message `Added students.html and students.js files.`
3. Push your changes to your GitHub repository.

**Once you have committed your changes and pushed them to GitHub:**

1. Close Visual Studio Code.
2. Delete the folder you were working in. It's OK -- it is stored in GitHub.

## Debugging in the Web Browser

If you've hit any problems with your JavaScript code so far you might be wondering how you find this out. Your web page loads but nothing happens -- what has gone wrong. Thankfully, browsers come with tools to support web development.

**What follows is how we can debug applications using Chrome/Chromium based browsers:**

- Google Chrome
- Chromium
- Microsoft Edge

If you are using Safari, the same general idea also works. See here for a brief explanation of accessing the development tools: https://developer.apple.com/safari/tools/.

For Mozzila Firefox, see here: https://developer.mozilla.org/en-US/docs/Tools

### Checking Errors

**To open the Developer Tools press F12.** This will bring up the following window:

![image-20201231140253862](image-20201231140253862.png)

This provides a wealth of information about the running webpage. Of particular note is how it shows errors in your code. For example, the following intentional error has been added to `script3.js` of `third.html` from our previous work.

![image-20201231140952898](image-20201231140952898.png)

The JavaScript is trying to find `my_tex` rather than `my_text`. Note that the error says we don't have `innerHTML` defined on the variable `element`. That is because `element` will be `null` as there is no HTML element found. The Developer Tools have provided an error, and tried to highlight where the problem is. This can be very useful.

### So you want to know more

You **should** follow the [Chrome DevTools](https://developers.google.com/web/tools/chrome-devtools/) guide provided by Google. We are only introducing the idea of how to open these tools. We will leave the Developer Tools here and expect you to learn them to support your development practice based on which browser you are working in.