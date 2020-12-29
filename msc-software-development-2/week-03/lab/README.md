# Software Development 2 Lab 03 -- More Object-orientation and Events

## Cloning Your Repo

At the end of the last lab we deleted the local version of our repository. This isn't a problem -- we already had it saved to GitHub. We just need to clone it again. The steps to do this where:

1. **Open Visual Studio Code.**
2. **Make sure no folder is currently open. We can do this by using File then Close Folder from the main menu.**
3. **Click on the Source Control button on the left-hand side of the Visual Studio Code window.**
4. **Your window should now look like this.**

![image-20201227134347876](image-20201227134347876.png)

We need the the location of our repository.  This is the URL of the repository you created, which should be of the form `https:\\github.com\<user-name>\sd2` (or whatever project name you gave).  For example, my repository is [https:\\github.com\kevin-chalmers\sd2](https:\\github.com\kevin-chalmers\sd2).

**Click the Clone Repository button and Visual Studio Code will ask for the repository URL at the top of the window**.

![image-20201227134725482](image-20201227134725482.png)

1. **Press return, and Visual Studio Code will ask you where you want to save the repository. Pick somewhere sensible.**

2. **Visual Studio Code will ask you if you want to open the repository. Choose to do so.**

You now have your GitHub repository cloned to the local machine and opened in Visual Studio Code.

## Methods

So far we have looked at the following ideas with objects:

- Defined classes using the `class` keyword.
- Defined a `constructor` for a class.
- Created objects (class instances) using the `new` keyword.
- Added attributes to a class.
- Set attributes of an object in the `constructor` using the `this` keyword.

So far, we have covered the data aspect of an object. Let us now look at the code aspect by defining some methods. Update `students.js` to the following:

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

  	// Returns student details as a HTML table row.
    tableRow() {
        return `<tr><td>${this.id}</td><td>${this.name}</td></tr>`;
    }
}

// An array of students.
var students = [
    new Student("001", "Kevin Chalmers"), 
    new Student("002", "Lisa Haskel"), 
    new Student("003", "Arturo Araujo")];

function printStudents() {
    // Build html for table.
    var html = 
        `<table border="1">
            <tr>
                <th>ID</th>
                <th>Name</th>
            </tr>`;
    // Iterate over all the students
    for (var student of students) {
        html += student.tableRow();
    }
    // End html table.
    html += `</table>`
    // Get the main element
    var main = document.getElementById("main");
    // Set the innerHTML to html
    main.innerHTML = html;
}
```

The changes we have made are the addition of `tableRow` method to `Student`, and a rewrite of the `printStudents` function.

> ### HTML Tables
>
> HTML supports tables using the following tags.
>
> - `<table>` denotes the table HTML element. We can set properties such as the `border`.
> - `<tr>` denotes a table row.
> - `<th>` is a table header.
> - `<td>` is table data, or a single table cell.

**STOP -- take your time now to ensure you understand how the HTML for the table is generated. Write it out by hand to ensure you know.**

**COMMIT** -- commit and push your code changes once everything works.

### Now you try

Can you extend the `printStudents()` function so that is also prints a table with the name first and id second. That is:

| **Name**       | **ID** |
| -------------- | ------ |
| Kevin Chalmers | 001    |
| Lisa Haskel    | 002    |
| Arturo Araujo  | 003    |

**The current table should also still be displayed above this table.** **HINT** -- you will need another method in the `Student` class.

**STOP, COMMIT** -- commit and push your changes to GitHub.

Now, add a `programme` attribute to the `Student` class that stores the name of the student's programme. Update your programme so that it displays the two tables with the programme information:

- Table 1 -- ID, Name, Programme
- Table 2 -- Name, ID, Programme

**HINT** -- you will need to update the following parts of your programme:

- Add a new attribute to the `Student` class.
- Update the constructor so the programme name can be set.
- Update the two methods for getting the `Student` data as a row.
- Update the `Student` array creation to provide the programme names. The names of the programmes don't matter.

Finally, add yourself to the array of `Student`.

**STOP, COMMIT** -- commit and push your changes to GitHub.

## Private Attributes and Methods

JavaScript supports private attributes and methods. These are attributes and methods only accessible from within the object itself. We denote a private member with a `#`:

```javascript
class Foo {
  // A private attribute
  #value1;
  
  // A private method
  #method1() {
  
	}
}
```

Let us look at an example by extending our student programme. Update your `student.js` file to the following:

```javascript
// Tells the browser we want JavaScript to run in strict mode.
// This means faster code, but JavaScript needs to be cleaner.
"use strict";

// A definition of a programme
class Programme {
    // Programme code
    #code;
    // Programme name
    #name;

    // Creates a new instance of type Programme
    constructor(code, name) {
        this.#code = code;
        this.#name = name;
    }
}

// A definition of a student
class Student {
    // Student ID
    #id;
    // Student name
    #name;
    // Student programme
    #programme;

    // Creates a new instance (object) of type Student
    constructor(id, name, programme) {
        // Set the id and name of the object instance
        this.#id = id;
        this.#name = name;
        this.#programme = programme;
    }

    tableRow() {
        return `<tr><td>${this.#id}</td><td>${this.#name}</td><td>${this.#programme.#name}</td></tr>`;
    }
}

// An array of students.
var students = [
    new Student("001", "Kevin Chalmers", new Programme("001", "Software Engineering")), 
    new Student("002", "Lisa Haskel", new Programme("002", "Computing")), 
    new Student("003", "Arturo Araujo", new Programme("003", "Physics"))];

function printStudents() {
    // Build html for table.
    var html = `
        <table border="1">
            <tr>
                <th>ID</th>
                <th>Name</th>
                <th>Programme</th>
            </tr>
    `;
    // Iterate over all the students
    for (var student of students) {
        html += student.tableRow();
    }
    // End html table.
    html += `</table>`
    // Get the main element
    var main = document.getElementById("main");
    // Set the innerHTML to html
    main.innerHTML = html;
}
```

There are a few things we have done here:

1. Declared a new class `Programme` that contains information about a programme.
2. Set the attributes to private. **NOTE** -- we have to use `this.#name` to access the attribute. This is because the `#` forms part of the attribute name.
3. Updated `Student` so that its attributes are private.
4. Added a `#programme` attribute to `Student`.
5. Updated `tableRow()` to try and get the name from `#programme`. **NOTE** -- this will not work, meaning our programme won't work.
6. Updated the `students` array creation to pass a `Programme` object.

**Now reload your `students.html` file and click the button. Nothing will happen.**

The attributes of `Programme` and `Student` are private and cannot be accessed outside the object. Let us look at a feature of JavaScript which will allow us to access these private variables.

## Getters and Setters

JavaScript classes support special methods known as getters and setters. These allow getting and setting attributes of an object. We use the keywords `get` and `set` to do so.

```javascript
class Foo {
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

// Create Foo object.
var foo = new Foo(5);
// Get value
var val = foo.value;
// Set value
foo.value = 10;
```

Let us now update our `student.js` file to have getters and setters for `Programme`:

```javascript
// A definition of a programme
class Programme {
    // Programme code
    #code;
    // Programme name
    #name;

    // Creates a new instance of type Programme
    constructor(code, name) {
        this.#code = code;
        this.#name = name;
    }

    // Get code
    get code() {
        return this.#code;
    }

    // Set code
    set code(value) {
        this.#code = value;
    }

    // Get name
    get name() {
        return this.#name;
    }

    // Set name
    set name(value) {
        this.#name = value;
    }
}
```

And finally we need to update `tableRow()` of `Student` to the following:

```javascript
tableRow() {
    return `<tr><td>${this.#id}</td><td>${this.#name}</td><td>${this.#programme.name}</td></tr>`;
}
```

Now, reload your `students.html` web page and click the button. It should now work again.

**STOP, COMMIT** -- commit and push your changes to GitHub.

> ### Why Have Getters and Setters?
>
> OK, why did we do through this process when we could have just left our attributes public. Getters and setters have a number of benefits, but in particular they allow:
>
> - Public getters allow access to an attribute while stopping it being updated outside the object.
> - Getters and setters can have additional code, which can, for example, check that the correct value is being set.

### Now you try

Add getters and setters for the `Student` class. Have ones for all the attributes.

**STOP, COMMIT** -- commit and push your changes to GitHub.

## References

Most object-orientated languages, including JavaScript and Python, use referencing of objects. Referencing means that we don't actually hold a copy of an object, but a reference to it.

This is very similar to the idea of storing data in memory locations. A reference is a location that our object is stored in. We can copy that location to other variables and attributes. Therefore, an object can be manipulated in multiple locations. Below is an example.

```javascript
class Foo {
  value;
  
  constructor(value) {
    this.value = value;
  }
}

var foo1 = new Foo(5);
var foo2 = new Foo(6);
var foo3 = foo1;

// Displays 5
console.log(foo3.value);
// Change value to 7
foo1.value = 7;
// Displays 7
console.log(foo3.value);
// Change foo3 to reference foo2
foo1 = foo2;
// Displays 6
console.log(foo3.value);
```

Let us extend our `students.js` file to work with references to shared programmes.

```javascript
"use strict";

class Programme { 
  // As before
}

class Student {
  // As before
}

// Dictionary of Programmes
var programmes = {
    "Comp": new Programme("001", "Computing"),
    "SoftEng": new Programme("002", "Software Engineering"),
    "Phys" : new Programme("003", "Physics")
};

// An array of students.
var students = [
    new Student("001", "Kevin Chalmers", programmes["SoftEng"]), 
    new Student("002", "Lisa Haskel", programmes["Comp"]), 
    new Student("003", "Arturo Araujo", programmes["Phys"]),
    new Student("004", "Foo Bar", programmes["Comp"])];

// Change the name of Comp programme to Computer Science
programmes["Comp"].name = "Computer Science";

// Rest of code as before.
```

**Reload your web page and click the button. You should see all instances of Computing have been changed to Computer Science in the table.**

**STOP, COMMIT** -- commit and push your code changes to GitHub.

### So you want to know more

Understanding references is a key concept in most object-oriented languages. The following links will further explain how referencing works in JavaScript: https://javascript.info/object-copy

## Events and Callbacks

In Lab 01 we used events from buttons to call JavaScript functions. For example, we have:

```html
<input type="button" value="Click Me!" onclick="msg()">
```

We have also seen where we pass a function as a parameter to another function:

```javascript
server.listen(port, hostname, function() {
    console.log(`Server running at http://${hostname}:${port}/`);
});
```

One of JavaScript's strengths is the ability to write *asynchronous* programmes. We pass functions as parameters (such as for an event) and these functions are called when a process is finished. Think about the two scenarios above:

- We don't know for sure when the user will click the button. We just set up which function should be called when the button is clicked. We have to wait for the user. This would block the program if we wrote code that waited for the user, as we have done for user input on the command line.
- We don't know for sure when a server will start. There is a lot of background operations that have to occur. Rather than wait for the server to start, we say which code we want to run when it has started.

These functions are often called *callback* functions. They are run when another function completes. This allows asynchronous behaviour as we don't fully know when functions and operations will be called. This is especially true with events. *We have to write code that will run when events occur (like a button press)*. Our code must reflect this behaviour -- we cannot write blocking functions that cause our applications to stop when an event occurs.

HTML provides a wealth of different events that we write JavaScript functions for. The most common (taken from [TutorialsPoint](https://www.w3schools.com/js/js_events.asp)) are:

| Event         | Description                                        |
| :------------ | :------------------------------------------------- |
| `onchange`    | An HTML element has been changed                   |
| `onclick`     | The user clicks an HTML element                    |
| `onmouseover` | The user moves the mouse over an HTML element      |
| `onmouseout`  | The user moves the mouse away from an HTML element |
| `onkeydown`   | The user pushes a keyboard key                     |
| `onload`      | The browser has finished loading the page          |

Let us update our `students.html` file so that the table of students is displayed when the page is loaded. **Update `students.html` to the following:**

```html
<!DOCTYPE html>
<html>
    <head>
        <title>Student List</title>
        <script src="student.js"></script>
    </head>
    <body onload="printStudents()">
        <h2>Students</h2>
        <div id="main"></div>
    </body>
</html>
```

**Reload the webpage -- it should now display the table of students automatically.**

**STOP, COMMIT** -- commit and push your changes to GitHub.

### Adding New Students

Let us now update our web application so we can add new students to the table. **First, update `students.html` to the following:**

```html
<!DOCTYPE html>
<html>
    <head>
        <title>Student List</title>
        <script src="student.js"></script>
    </head>
    <body onload="printStudents()">
        <h2>Add New Student</h2>
        <table>
            <tr>
                <td>ID</td>
                <td><input id="studentID" type="text"></td>
            </tr>
            <tr>
                <td>Name</td>
                <td><input id="studentName" type="text"></td>
            </tr>
            <tr>
                <td>Programme</td>
                <td><input id="studentProgramme" type="text"></td>
            </tr>
        </table>
        <input type="button" value="Add Student" onclick="addStudent()">
        <h2>Students</h2>
        <div id="main"></div>
    </body>
</html>
```

We are using a table to layout a small form that will allow us to enter the student ID, name, and programme. We use `<input type="text">` for text boxes. Each text box is given an `id` which will allow us to lookup the details in the text boxes. We also have a button that will call `addStudent()` when it is clicked. **Add the following `addStudent()` function to the bottom of `student.js`:**

```javascript
function addStudent() {
    // Get the value in the student ID textbox.
    var id = document.getElementById("studentID").value;
    // Get the value in the student name textbox.
    var name = document.getElementById("studentName").value;
    // Get the value in the student programme textbox.
    var programme = document.getElementById("studentProgramme").value;
    // Clear the textboxes
    document.getElementById("studentID").value = "";
    document.getElementById("studentName").value = "";
    document.getElementById("studentProgramme").value = "";
    // Create the student object
    // We lookup the programme from the programmes dictionary.
    var student = new Student(id, name, programmes[programme]);
    // Add student to the students array
    students.push(student);
    // Redisplay the table
    printStudents();
}
```

This function follows five steps:

1. It gets the value contained in the text boxes.
2. It clears the values of the text boxes.
3. It creates a new `Student` object from the values in the text boxes. **NOTE** -- the programme is used as a lookup value.
4. The new `Student` is added to the `students` array.
5. `printStudents()` is called again, redisplaying the table of students.

**Reload the `students.html` web page. You should now be able to add a new student to the table.**

**STOP, COMMIT** -- once this is working, commit and push the code.

### Now you try

Add the necessary updates to `students.html` and `student.js` so you can also add a new programme. Make sure you test your application so you know it is working.

**REMEMBER** -- once you have done this, commit and push your changes.

## A Bit of Reflection

We have come quite far in our journey with HTML and JavaScript. There is a structure to what we are doing:

- We define our **user interface** in HTML.
- We execute JavaScript code when **events** happen.
- JavaScript updates the interface based on events and data.
- Data is represented by objects, and updated via JavaScript.

Understanding how information and control flows from one part of our web application to another is an important idea to understand. Try drawing a diagram to understand what is going on.

## Exercises

**REMEMBER TO COMMIT AFTER EVERY EXERCISE.**

1. Create a `Module` object which represents a module for a `Programme`. A `Module` has a `code` and a `name`. These attributes must be private with getters and setters.
2. Now update `Programme` so it has an array of `Module` associated with it. This should be a private attribute. Add at least three modules to each `Programme` object. **NOTE** -- if you can, try and share modules between programmes. Remember the information on references.
3. Display the programme information in a table, with the programme ID, name, and list of modules (code and name).
4. Finally, update the webpage so you can add a new module. Test your webpage to make sure you can add new modules, and add modules to programmes.