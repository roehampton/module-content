# Software Development 2 Lab 04 -- Connecting to a Database

This Lab covers a variety of topics, mainly about connecting your web page to a database. To give an overview so you can refer to this lab later for certain aspects you might find useful elsewhere:

- Installing and using SQLite on the command line.
- How to ignore certain files in our Git repository.
- How to output (dump) the SQL of a SQLite database.
- How to import SQL into an SQLite database.
- How to connect to an SQLite database in Node.js.
- How to create a RESTful interface using Express.js.
- How to communicate from Node.js to our webpage using JSON.

**In next week's lab we will start afresh and build a project from scratch.** At this point things might start to feel overwhelming, but we will take a step back next week and repeat many of these steps while building a new project properly.

## SQLite

SQLite is a simple SQL tool that manages a file as a database. It is probably the simplest SQL tool available. Because of this, it is supported in Android and iOS to allow apps to have local (i.e., on device) databases. SQLite is not meant for multiple concurrent users like MySQL. It is a single file solution.

SQLite is installed as standard on MacOS, and if you use Linux is likely installed or easily installed by a package manager. On Windows, we have to do a bit more work.

### Installing SQLite on Windows

SQLite can be downloaded from https://sqlite.org/download.html. There are two ZIP files you need to download:

* `sqlite-dll-win64-x64` -- this contains the DLL for running SQLite databases.
* `sqlite-tools-win32-x86` -- this contains the programmes for creating and manipulating a SQLite database on the command line.

**Unzip both these files into the same folder -- `C:\sqlite`.** Your folder should look like this:

![image-20201230093119838](image-20201230093119838.png)

We now have to add this folder to the `PATH` of Windows. The `PATH` is where your operating system looks for programs when you run them from the command line. To add `C:\sqlite` to your `PATH`, **perform the following steps:**

1. **Open the start menu.**

2. **Type `env` and press return.**

3. **The following window is displayed.**

   ![image-20201230100332545](image-20201230100332545.png)

4. **Click Environment Variables to open the following screen.**

   ![image-20201230100456711](image-20201230100456711.png)

5. **On the bottom panel (System variables), select Path and click Edit...**

   ![image-20201230100649460](image-20201230100649460.png)

6. **Click New, and enter `C:\sqlite' as the new entry.**

7. **Click OK on all the windows until they are closed.**

You are now ready to continue on with the lab.

### Working with SQLite

SQLite understands standard SQL. All we need to do it create a database with the command line tool and interact with it from there.

#### Creating a Database

1. Open a terminal / command prompt, and navigate to the folder where you have your Git repository (e.g., `/Users/kevin/sd2`). If you don't remember, we use `cd` to change directory.
2. Now create a SQLite database by running the following command: `sqlite3 students.db`. This will create a file `students.db` which is an SQLite database. It will also open the SQLite command prompt.

```shell
SQLite version 3.32.3 2020-06-18 14:16:19
Enter ".help" for usage hints.
sqlite>
```

#### Executing Queries

> ##### WARNING -- A lot of SQL Incoming
>
> This section aims to cover SQL for you again, but there is quite a bit of SQL we will enter with little explanation. If you'd prefer to skip this section you can download the SQL here: https://raw.githubusercontent.com/kevin-chalmers/sd2/main/students.sql. **Save this file in the root of your repository.**
>
> To import the SQL as a database, run the following command in the root of your repository:
>
> **MacOS and Linux**
>
> ```shell
> cat students.sql | sqlite3 students.db
> ```
>
> **Windows**
>
> ```shell
> type students.sql | sqlite3 students.db
> ```
>
> Now skip to the [Version Contolling SQLite Section](#Version Controlling a SQLite Database).

SQLite works just as a normal SQL database on the surface. There are differences, but we don't need to concern ourselves with those now. Let us create a table. **Enter this into the sqlite prompt now:**

```sqlite
sqlite> CREATE TABLE Modules (
   ...> code VARCHAR(10) PRIMARY KEY,
   ...> name VARCHAR(50) NOT NULL);
```

This has created a table for storing modules. Let us insert some data into it. **Enter this into the sqlite prompt now:**

```sqlite
sqlite> INSERT INTO Modules VALUES ("CMP020C101", "Software Development 1");
sqlite> SELECT * FROM Modules;
CMP020C101|Software Development 1
```

##### Now you try

**Insert the following values into the `Modules` table.**

| **Code**   | **Name**                         |
| ---------- | -------------------------------- |
| CMP020C102 | Computer Systems                 |
| CMP020C103 | Mathematics for Computer Science |
| CMP020C104 | Software Development 2           |
| CMP020C105 | Computing and Society            |
| CMP020C106 | Databases                        |
| PHY020C101 | Physics Skills and Techniques    |
| PHY020C102 | Mathematics for Physics          |
| PHY020C103 | Computation for Physics          |
| PHY020C104 | Classical Physics                |
| PHY020C105 | Introduction to Modern Physics   |
| PHY020C106 | Introduction to Astrophysics     |

**Now let us add the `Programmes` table**:

```sqlite
CREATE TABLE Programmes (
   ...> id VARCHAR(8) PRIMARY KEY,
   ...> name VARCHAR(50));
```

**And we will add three programmes:**

```sqlite
INSERT INTO Programmes VALUES ("09UU0001", "BSc Computer Science");
INSERT INTO Programmes VALUES ("09UU0002", "BEng Software Engineering");
INSERT INTO Programmes VALUES ("09UU0003", "BSc Physics");
```

We are now going to create a joining table between `Modules` and `Programmes`. Remember, these are tables that contain keys from other tables to link information in one-to-many relationships.

**Execute the following SQL statement:**

```sqlite
CREATE TABLE Programme_Modules(
   ...> programme VARCHAR(8) NOT NULL,
   ...> module VARCHAR(10) NOT NULL,
   ...> FOREIGN KEY (programme) REFERENCES Programmes(id),
   ...> FOREIGN KEY (module) REFERENCES Modules(code));
```

And we can now add modules to programmes:

```sqlite
INSERT INTO Programme_Modules VALUES ("09UU0001", "CMP020C101");
```

##### Now you try

The following information needs to be added to the `Programme_Modules` table:

- BSc Computer Science
  - Software Development 1 -- we have just added this.
  - Computer Systems
  - Mathematics for Computer Science
  - Software Development 2
  - Computing and Society
  - Databases
- BEng Software Engineering -- the same as BSc Computer Science
- BSc Physics
  - Physics Skills and Techniques
  - Mathematics for Physics
  - Computation for Physics
  - Classical Physics
  - Introduction to Modern Physics
  - Introduction to Astrophysics

**Now add a `Student` table (with `id` and `name` only) and add some students, for example the ones we have used in our programmes so far.**

**Finally, add a `Student_Programme` table to link the students to a programme.**

### Version Controlling a SQLite Database

SQLite saves its database file as a binary file. **Remember the warning about versioning binary files.** We need a different solution. Thankfully, SQLite allows us to output (*dump*) the SQL code for the database.

#### Ignoring Files in Git

The first thing we need to tell Git is to ignore the SQLite database file. This is quite easy -- we just need to create a `.gitignore` file in the root folder of our repository. **Do this now -- you can do it in Visual Studio Code.** The contents of the file will be:

```
*.db
```

This means Git will now ignore all files with the suffix `.db`.

**STOP, COMMIT** -- commit the `.gitignore` file now and push it to GitHub. `.db` files will no longer be tracked in your repository.

#### Outputting SQL from an SQLite Database

To output the SQL of our database, we just do the following in the terminal:

```shell
sqlite3 students.db .dump
```

This will output the SQL onto the terminal, which isn't actually that useful. We can redirect the output into a file as follows:

```shell
sqlite3 students.db .dump > students.sql
```

This will output the SQL into `students.sql`. **Before running this, you should delete any existing students.sql` file.**

**STOP, COMMIT** -- commit the `students.sql` file now and push it to GitHub.

#### Inputting SQL into an SQLite Database

**MAKE SURE YOU FIRST DELETE YOUR `students.db` file.** We are about to recreate it from raw SQL. You can do this in the terminal using `rm students.db`.

To input SQL into an SQL database we perform the following operation on the command line:

**MacOS and Linux**

```shell
cat students.sql | sqlite3 students.db
```

**Windows**

```shell
type students.sql | sqlite3 students.db
```

`cat` and `type` outputs the contents of a file, and `|` pipes (transfers) output from one program to another -- in this instance `sqlite3`.

You now know how to version control your SQLite database. However, you might find this difficult to remember to do. Before each commit, you'll have to dump the database, and commit it. Then you'll have to remember to delete the database before recreating it.

## SQLite with Node.js

Now we have done our work with SQLite, we can use Node.js to talk to our SQLite database. First, we need to install the SQLite package for Node.js.

1. **Open Visual Studio Code.**

2. **Open the folder of your repository in Visual Studio Code.**

3. **Open the terminal in Visual Studio Code.**

4. **Run the following command:**

   ```shell
   npm install --save sqlite3@^5.0.0
   ```

You now have the necessary packages to work with SQLite databases in Node.js. *But wait!* Look at your Source Control panel in Visual Studio Code. Over 1000 untracked files. What has happened?

`nom` installs packages locally by default. That is, the files are installed in your project folder. This is good as it avoids create conflicts in your system, but means we have over 1000 new files to track. What do we do?

We update our `.gitignore` file. Thankfully, someone else has defined which things we need to ignore in Node projects.

1. **Go to https://github.com/github/gitignore/blob/master/Node.gitignore.**
2. **Click on the Raw button.**
3. **Copy the page contents.**
4. **Paste it into your `.gitignore` file and save.**
5. **Add changes (there should only be two), commit, and push.**

You have now learned about setting up appropriate `.gitignore` for a project. Simple searches on Google like `node.js .gitignore` will find these for you.

**NOTE** -- as your packages are not in the repository, you will have to install them in each machine you work on. However, you can do this quickly by just running the following in the root directory of your repository:

```shell
npm install
```

### Opening a SQLite Database in Node.js

We can now create a Node.js program to open our SQLite database. **Create `db_test.js` with the following code:**

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

// Close the database connection.
// Always close the connection when you are finished with it.
// Function is callback when connection is closed.
db.close(function(err) {
    // If an error, print it out.
    if (err) {
        return console.error(err.message);
    }
    console.log("Closed connection to students database.");
});
```

We have used two operations to create and close our database connection:

- `new sqlite3.Database("<filename>", function(err))` opens a database connection by creating a new `Database` object.
- `close(function(err))` closes the database connection on a `Database` object.

**Run `db_test.js` in the Visual Studio Code terminal using the following command:**

```shell
node db_test.js
```

You should get the following output:

```shell
Connected to students database.
Closed connection to students database.
```

**STOP** -- commit and push your changes.

### Performing Queries

You are hopefully familiar with making SQL queries by now. Let us perform one on our `students.db` file now. **Update `db_test.js` to the following:

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

// *** NEW CODE STARTS HERE ***
// SQL query to run
var sql = "SELECT * FROM Modules";

// Execute SQL query, and run function on every row returned.
db.each(sql, function(err, row) {
    // If error display
    if (err) {
        return console.error(err.message);
    }
    // Print the code column and name column from row seperated by a tab \t
    console.log(row.code + "\t" + row.name);
});

// *** NEW CODE ENDS HERE ***

// Close the database connection.
// Always close the connection when you are finished with it.
// Function is callback when connection is closed.
db.close(function(err) {
    // If an error, print it out.
    if (err) {
        return console.error(err.message);
    }
    console.log("Closed connection to students database.");
});
```

We have used `db.each` to run a function on each returned for from our query. The following pseudocode provides a similar idea in as a for loop:

```
rows = EXECUTE QUERY ON Database
FOR EACH row IN rows
    PRINT row["code"] TAB row["name"]
```

**Run the code using:**

```shell
node db_test.js
```

You should see the modules printed to the terminal.

**STOP, COMMIT** -- commit and push your changes. The habit should be forming by now. This will be the last reminder.

#### Now you try

Perform some other select queries on your database. For example:

- `SELECT * FROM Students`

- `SELECT * FROM Programmes`

- ```sql
  SELECT Modules.name
  FROM Programmes, Modules, Programme_Modules
  WHERE Programmes.name = "BSc Computer Science"
  AND Programme_Modules.programme = Programmes.id
  AND Programme_Modules.module = Modules.code
  ```

#### `all`

`db.all` allows us to get all the rows returned by the query and then execute some code accordingly. For example, we can rewrite our query above as:

```javascript
// SQL query to run
var sql = "SELECT * FROM Modules";

// Execute SQL query, and run function with all rows.
db.all(sql, function(err, rows) {
    // If error display
    if (err) {
        return console.error(err.message);
    }
    // Print the code column and name column from row seperated by a tab \t
    for (var row of rows) {
        console.log(row.code + "\t" + row.name);
    }
});
```

This is useful when you want to have all the rows of data available for a particular purpose. `all` is more useful for returning complete data to our webpage from our Node application.

#### `get`

`db.get` retrieves just the first row of the result of a query. This is useful when you know only one row will be returned. The idea is the same as the other query execution types we have seen:

```javascript
var sql = "SELECT * FROM Modules";

// Execute SQL query, and run function on first row.
db.get(sql, function(err, row) {
    // If error display
    if (err) {
        return console.error(err.message);
    }
    // Print the code column and name column from row seperated by a tab \t
    console.log(row.code + "\t" + row.name);
});

```

#### `run`

So far, we have focused on how we work with data returned from `SELECT` queries. But what about other SQL statements? For those we use `run`. For example, to insert a new entry into the `Students` table we can do the following:

```javascript
// SQL statement to run
var sql = `
    INSERT INTO Students
    VALUES (100, "Mohammed Ali")`;

// Execute SQL statement
db.run(sql);
```

Notice we don't need a function this time -- there is nothing to run a function on. **However, you probably want to have a function that deals with errors.** Below is a better example:

```javascript
// SQL statement to run
var sql = `
    INSERT INTO Students
    VALUES (200, "Ada Lovelace")`;

// Execute SQL statement
db.run(sql, function(err) {
    // If error, print it out
    if (err) {
        return console.error(err.message);
    }
    console.log("Row inserted into database.")
});
```

##### Now you try

Use `db.run` to delete the students we have just added.

**STOP, COMMIT** -- commit and push your changes to GitHub.

#### Summary of Executing SQLite Statements in Node.js

- `each` -- runs a function on each row returned by a `SELECT`.
- `all` -- runs a function with all the rows returned by a `SELECT`.
- `get` -- runs a function on the first row returned by a `SELECT`.
- `run` -- executes an SQL statement that doesn't return rows (i.e., not a `SELECT`).

## Express.js

OK, we have a webpage that we can display data in our browser. We are also able to get data from a SQLite database in a Node.js application. How do we get the data from Node.js to our webpage? For this, we will use another Node.js library -- Express.js. You can install it by running the following in the terminal in the root folder of your repository:

```shell
npm install express
```

So what is Express.js? It provides RESTful interfaces.

### RESTful Interfaces

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

#### Now you try

Add the following end point URLs to the application:

- `/test` will display `Welcome to the test page!`
- `/student/<id>/<name>` will display a table with the student ID and name. **HINT** -- you will have to construct the string in the response to be HTML.

### JSON -- JavaScript Object Notation

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

```javascript
// Create a get for /students
app.get("/students", function(req, res) {
    var sql = "SELECT * FROM Students";
    db.all(sql, function(err, rows) {
        if (err) {
            return console.error(err);
        }
      	res.header("Access-Control-Allow-Origin", "*");
        res.json(rows);
    });
});
```

#### Now you try

Add the following endpoints to the application with appropriate SQL queries:

- `/programme/<id>` to get a programme of a given id.
- `/programmes` to get all programmes.
- `/module/<code>` to get a module of a given code.
- `/modules` to get all modules.

### Putting it All Together -- Reading JSON

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

We have come far in this lab, going from our SQLite database, through RESTful interfaces with Express.js, and displaying our returned JSON data using jQuery. This is a lot of web technology we have covered, but you are now using close to a full-stack of technology. We are now doing the following:

- Displaying HTML webpages in our browser (user-interface).
- Reacting to events in our HTML with JavaScript (client controller).
- Sending data between the server and client using JSON.
- Providing a RESTful interface to our server using Express.js in Node.js (application/business logic).
- Accessing data using an SQLite database via Node.js (data layer).

Next lab we will build a new project from scratch to go over these ideas once again.

## So you want to know more

SQLite provides a tutorial on how to use SQLite with Node.js: https://www.sqlitetutorial.net/sqlite-nodejs/.

TutorialsPoint also provides an Express.js tutorial: https://www.tutorialspoint.com/expressjs/index.htm.

## Exercises

1. Add the necessary code to display the table of programmes on the webpage.
2. Add the necessary code to display the table of modules on the webpage.
3. Create a new webpage -- `module_search.html` -- which has a text box allowing getting a single module based on it's code.
4. Do the same for a student.
5. Do the same for a programme.