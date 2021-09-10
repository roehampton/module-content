# Software Development 2 Lab 05 -- Express.js

OK, we have a webpage that we can display data in our browser. We are also able to get data from a SQLite database in a Node.js application. How do we get the data from Node.js to our webpage? For this, we will use another Node.js library -- Express.js. You can install it by running the following in the terminal in the root folder of your repository:

```shell
npm install express
```

So what is Express.js? It provides RESTful interfaces.

## RESTful Interfaces

REST stands for [Representational State Transfer](https://en.wikipedia.org/wiki/Representational_state_transfer). This is a software architecture for web services that is driven by URLs. We interact with our web service by accessing a URL with a particular HTTP message type:

- `GET` will return data from the web service. This is the standard HTTP message used when we get a webpage.
- `POST` sends data to the web service. This is the HTTP message used when you send data from a webpage, such as in a form.
- `DELETE` allows deletion of data in the web service.

The approach we take is to declare URLs that will have a function called when our server receives a request. Let us build a first Express.js application. **Enter this code as `express_server.js`:**

```javascript
// Import express.js
const express = require("express");

// Create express app
var app = express();

// Create a get for root - /
app.get("/", function(req, res) {
    res.send("Hello world!");
});

// Start server on port 3000
app.listen(3000);
```

Here we have defined the `/` (root folder) to respond with `Hello world!`. **Now run this programme with the following:**

```shell
node express_server.js
```

**Open your browser, and go to `127.0.0.1:3000`**. You should see `Hello world!` displayed.

Let us expand this application to listen on some other URLs. **Shutdown the server with CTRL-C and update `express-server.js` to the following:**

```javascript
// Import express.js
const express = require("express");

// Create express app
var app = express();

// Create a get for root - /
app.get("/", function(req, res) {
    res.send("Hello world!");
});

// Create a get for /goodbye
app.get("/goodbye", function(req, res) {
    res.send("Goodbye world!");
});

// Create a get for /hello/<name> with name provided by user
app.get("/hello/:name", function(req, res) {
    // req.params contains any parameters in the request
    res.send("Hello " + req.params.name);
});

// Start server on port 3000
app.listen(3000);
```

There are now three URLs you can visit:

- `127.0.0.1:3000` will display `Hello world!`.
- `127.0.0.1:3000/goodbye` will display `Goodbye world!`.
- `127.0.0.1:3000/hello/<name>` will display `Hello <name>` for any value of `<name>`. Try your own name.

### Now you try

Add the following end point URLs to the application:

- `/test` will display `Welcome to the test page!`
- `/student/<id>/<name>` will display a table with the student ID and name. **HINT** -- you will have to construct the string in the response to be HTML.

## JSON -- JavaScript Object Notation

So we can now get data information from our Node.js server. How do we send our database information? That is actually quite easy as JavaScript supports easy sending of data using JavaScript Object Notation (JSON). **First, let us create a new JavaScript file -- `db_server.js`:**

```javascript
// Import SQLite library.
// Use verbose mode to give more detailed error outputs
const sqlite3 = require("sqlite3").verbose();

// Connect to the database.
// Function is callback when connection completed.
// err is any error message that occurs
let db = new sqlite3.Database("students.db", function(err) {
    // If an error, print it out.
    if (err) {
        return console.error(err.message);
    }
    console.log("Connected to students database.");
});

// Import express.js
const express = require("express");

// Create express app
var app = express();

// Add static files location
app.use(express.static("static"));

// Create a get for /student
app.get("/student/:id", function(req, res) {
    var sql = `
        SELECT * FROM Students
        WHERE id = ${req.params.id}`;
    db.get(sql, function(err, row) {
        if (err) {
            return console.error(err.message);
        }
        res.json(row);
    });
});

// Create a get for /students
app.get("/students", function(req, res) {
    var sql = "SELECT * FROM Students";
    db.all(sql, function(err, rows) {
        if (err) {
            return console.error(err);
        }
        res.json(rows);
    });
});

// Start server on port 3000
app.listen(3000);
```

Note that we are going to server static files again from the `/static` folder. **Create that folder in your repository now.**

Everything else you have seen before, except what we do in `app.get`. Here, we execute the SQL as normal using `get` (as we are getting a single student). The callback function now sets `res.json(row)`. **Now run the program with `node db_server.js` in the Visual Studio Code terminal. Then connect to `127.0.0.1:3000/student/1` to see the JSON returned. It should look like this**:

```json
{"id":1,"name":"Kevin Chalmers"}
```

And that is it. It is that easy to send our data back. This will also work for multiple rows of data -- just use `res.json(rows)`. So, to get all students we can add the following endpoint:

### Now you try

Add the following endpoints to the application with appropriate SQL queries:

- `/programme/<id>` to get a programme of a given id.
- `/programmes` to get all programmes.
- `/module/<code>` to get a module of a given code.
- `/modules` to get all modules.

## Putting it All Together -- Reading JSON

We've come very far in this lab -- we've connected to our database, created a RESTful front end, and returned JSON data to our web page. Now we need to get this JSON data into our client web application so we can display it as a table. There are many ways we can do this, and we will use a particular method later in the module. For the moment, we are going to use another common JavaScript library -- jQuery. We won't explain much about jQuery here as we are only going to use one part of it. jQuery is essentially a library that allows easier manipulation of webpages.

**First, create the following`students.html` file in the `static` folder**:

```html
<!DOCTYPE html>
<html>
    <head>
        <title>Student List</title>
        <script src=https://code.jquery.com/jquery-3.5.1.js></script>
        <script src="student.js"></script>
    </head>
    <body onload="printStudents()">
        <h2>Students</h2>
        <div id="main"></div>
    </body>
</html>
```

This is very similar to our last `students.html` file but with the inclusion of jQuery. **Now add `student.js` to the `static` folder with the following content:**

```javascript
// Tells the browser we want JavaScript to run in strict mode.
// This means faster code, but JavaScript needs to be cleaner.
"use strict";

// A definition of a student
class Student {
    // Student ID
    #id;
    // Student name
    #name;

    // Creates a new instance (object) of type Student
    constructor(id, name) {
        // Set the id and name of the object instance
        this.#id = id;
        this.#name = name;
    }

    tableRow() {
        return `<tr><td>${this.#id}</td><td>${this.#name}</td></tr>`;
    }
}

function printStudents() {
    $.getJSON("/students", function(result) {
        // Create array of students
        var students = [];
        // Iterate over data returned
        for (var row of result) {
            var student = new Student(row.id, row.name);
            students.push(student);
        }
        // Build html for table.
        var html = `
        <table border="1">
            <tr>
                <th>ID</th>
                <th>Name</th>
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
    });
}
```
/student-list.html
We've simplified the `Student` class to just work with an ID and name. Then our changes are just to `printStudents()`:

- We use `$.getJSON` to get the JSON document from the server. `$` is how we access jQuery functions. We use the URL `/students` as this is the endpoint we have created.
- When the data is returned, the function is called filling the `result` parameter. This is our JavaScript.
- We create an empty array to store the students.
- We then iterate across every `row` in the `result` parameter. `result` will contain a JSON array of data, so we can use a `for ... of` loop here.
- We then create a `Student` object from the `row` data -- `id` and `name`.
- We then add the `Student` to the `students` array.
- The rest of the function works as before.

**Open your browser and go to `127.0.0.1/students` to see the result. You should get the table of students from the database.**

![image-20201231132828594](image-20201231132828594.png)

## Summary

We've gone far in this lab, through RESTful interfaces with Express.js, to displaying our returned JSON data using jQuery. This is a lot of web technology we have covered, but you are now using close to a full-stack of technology. We are now doing the following:

- Displaying HTML webpages in our browser (user-interface).
- Reacting to events in our HTML with JavaScript (client controller).
- Sending data between the server and client using JSON.
- Providing a RESTful interface to our server using Express.js in Node.js (application/business logic).
- Accessing data using an SQLite database via Node.js (data layer).

Next lab we will build a new project from scratch to go over these ideas once again.

## So you want to know more

TutorialsPoint also provides an Express.js tutorial: https://www.tutorialspoint.com/expressjs/index.htm.

## Exercises

1. Add the necessary code to display the table of programmes on the webpage.
2. Add the necessary code to display the table of modules on the webpage.
3. Create a new webpage -- `module_search.html` -- which has a text box allowing getting a single module based on it's code.
4. Do the same for a student.
5. Do the same for a programme.