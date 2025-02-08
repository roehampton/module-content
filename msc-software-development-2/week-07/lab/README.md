# Software Development 2: Using MySQL with node.js



## Prerequisites

Last week, you set up node.js, express.js and mysql using docker.  Today you will use the same set-up to practice retrieving data from a database and using the express framework to surface that data to the browser.

Next week, we will look at the PUG templating system that allows you to properly separate data from presentation, but this lab is crucial to enable you to fully understand the process and debugging techniques.

## Understanding asynchronous javascript

Before you embark on using node.js to connect to a database you need to understand the basics of an important feature of javascript - synchronous and asynchronous code.

In most procedural code, you can be sure that your code will run simply in sequence, proceeding line by line, with the next line being executed when the one before has finished executing. This leads to predictable results, but can also lead to frustration as tasks that take a long time may delay other code from executing.

However, Javascript has the ability to run code asynchronously, ie with multiple tasks running at the same time. This makes javascript fast and therefore desirable for a web programming language.

However, because of this, you need to be careful how you write your code.  You will need to be aware of dependencies on values set in your program, and ensure you write your code so that the values you need are definately complete.  For example, there are many times when you need the return value of a function in order to proceed with the next step in your program.  One such example of this is a call to a database.  A database call can be relatively slow, so we need to tell our application to wait for the database result before it continues with certain steps.  Meanwhile however, some other steps are not dependent on the result and may proceed synchonously, ie. while we are still waiting for the result of earlier operations. this substantially speeds up our programme.

Study this article and its links for more information.

[MDN article on Asychronous javascript](https://developer.mozilla.org/en-US/docs/Learn/JavaScript/Asynchronous)

### Callbacks and Promises

There are a number of different styles of writing asynchronous code in Javascript which you may encounter.  We will use the most uptodate style which makes use of 'Promises'.

_"Essentially, a Promise is an object that represents an intermediate state of an operation — in effect, a promise that a result of some kind will be returned at some point in the future. There is no guarantee of exactly when the operation will complete and the result will be returned, but there is a guarantee that when the result is available, or the promise fails, the code you provide will be executed in order to do something else with a successful result, or to gracefully handle a failure case."_

https://developer.mozilla.org/en-US/docs/Learn/JavaScript/Asynchronous/Promises

Older styles of javascript uses 'callbacks' which can result in confusing, highly nested code.

In newer versions of javascript there are three language constructs which we will use to implement asynchronous code with promises: 

__async__ functions.  If a function or method definition is prefaced with the work __async__ then the progam knows that the function will likely contain code that must return a result before the next line is executed.

__await__ keyword.  This keyword indicates that the value needs to be obtained before the next code is executed.  A 'Promise' is returned in the interim

Try typing the following lines into your browser's JS console:

```js
function hello() { return "Hello" };
hello();
```

But what if we turn this into an async function? Try the following:

```js
async function hello() { return "Hello" };
hello();
```
In the second version, a Promise is returned (in this case it is immediately fulfilled as the code does not take time to execute)

Within an async function, the 'await' keyword will be found: 'await' can ONLY be used within functions with the async keyword, and can be called on any function that returns a promise.

Using _await_ tells your program to only continue once the Promise has been resolved.  See the following example:



__.then()__ 

If you are outside an async function, and you need to make sure that your code calling an async function only executes when the fully 'resolved' value of the promise is returned, you can use a .then() block.


Because getting data from a database is one of the more time consuming operations, we will use async functions and promises in our code to ensure that we have the values we need for certain code blocks, while still being able to execute non-dependent blocks of code.


Examples taken from : 
[MDN article on callbacks and promises](https://developer.mozilla.org/en-US/docs/Learn/JavaScript/Asynchronous/Introducing)

## Your first database driven application

By following the steps in our previous lab, you will have built your environment from my Docker starter recipe which makes a lot of things simple for you!  You will also have the necessary libraries installed and some code that manages the connection to your database.

Setup screencast: [Screencast Link](https://roehampton.cloud.panopto.eu/Panopto/Pages/Viewer.aspx?id=c98901e7-f193-4b9b-b071-af3e018163fb)
Scaffolding files: [Files link](https://moodle.roehampton.ac.uk/mod/url/view.php?id=1269475)

### Checklist 1:  Getting your environment running again

* Can you run ```docker-compose up``` without error
Can you access http://127.0.0.1:3000 without error and see the words 'hello world'?
 * With your containers running, can you alter this block of test code in app/app.js, save, then reload the browser and see your changes? (HINT: watch the console)

```js
app.get("/", function(req, res) {
    res.send("Hello world!");
});
```
 * Can you access phpmyadmin at http://127.0.0.1:8081 and log in using your credentials set in your .env file?
 
### Checklist 2: Check your understanding

  * __Visit the file services/db.js.  Note the following:__ 
 
   1. we require the dotenv package which is able to read configuration from the .env file
   2. We require the mysql2 package (which has some more advanced features that the mysql npm package, specifically the part that works with Promises) see: https://www.npmjs.com/package/mysql2
   3. We use the mysql configuration to create a 'pool' of connections
   4. A utility async function query() is supplied that will handle sending a query to the database and returning rows as the result. (This function is a wrapper around the Mysql2 provided execute function which itself provides useful utilities such as prepared statements and releasing a connection back to the pool).
   
```js
// Utility function to query the database
async function query(sql, params) {
  const [rows, fields] = await pool.execute(sql, params);

  return rows;
}
```
   
  * __Visit the app.js file. Note the following__
  
   1. Note that we require the db.js file to set up the database connection
   2. Check that each of the routes already defined work as expected. Make sure you understand every line of code.


### Adding some more data to the database

Populate your database by adding the following data via SQL queries. You can do this in bulk straight into phpmyadmin. 

  * Click onto the sd2-db database in the left sidebar
  * Click SQL in the tabs along the top
  * Paste the sql code below into the SQL window and click 'go'
  * You will see the tables and data being created

NB: A screencast of this step is here:  which also includes some troubleshooting advice in case you get the error when your containers start of 'port already allocated'.[Import database screencast](https://roehampton.cloud.panopto.eu/Panopto/Pages/Viewer.aspx?id=1134b8ab-dc72-4ce3-bda7-af45010735f1)


```sql
CREATE TABLE Modules (
code VARCHAR(10) PRIMARY KEY,
name VARCHAR(50) NOT NULL);
INSERT INTO Modules VALUES('CMP020C101','Software Development 1');
INSERT INTO Modules VALUES('CMP020C102','Computer Systems');
INSERT INTO Modules VALUES('CMP020C103','Mathematics for Computer Science');
INSERT INTO Modules VALUES('CMP020C104','Software Development 2');
INSERT INTO Modules VALUES('CMP020C105','Computing and Society');
INSERT INTO Modules VALUES('CMP020C106','Databases');
INSERT INTO Modules VALUES('PHY020C101','Physics Skills and Techniques');
INSERT INTO Modules VALUES('PHY020C102','Mathematics for Physics');
INSERT INTO Modules VALUES('PHY020C103','Computation for Physics');
INSERT INTO Modules VALUES('PHY020C106','Introduction to Astrophysics');
CREATE TABLE Programmes (
id VARCHAR(8) PRIMARY KEY,
name VARCHAR(50));
INSERT INTO Programmes VALUES('09UU0001','BSc Computer Science');
INSERT INTO Programmes VALUES('09UU0002','BEng Software Engineering');
INSERT INTO Programmes VALUES('09UU0003','BSc Physics');
CREATE TABLE Programme_Modules(
programme VARCHAR(8) NOT NULL,
module VARCHAR(10) NOT NULL,
FOREIGN KEY (programme) REFERENCES Programmes(id),
FOREIGN KEY (module) REFERENCES Modules(code));
INSERT INTO Programme_Modules VALUES('09UU0001','CMP020C101');
INSERT INTO Programme_Modules VALUES('09UU0001','CMP020C102');
INSERT INTO Programme_Modules VALUES('09UU0001','CMP020C103');
INSERT INTO Programme_Modules VALUES('09UU0001','CMP020C104');
INSERT INTO Programme_Modules VALUES('09UU0001','CMP020C105');
INSERT INTO Programme_Modules VALUES('09UU0001','CMP020C106');
INSERT INTO Programme_Modules VALUES('09UU0002','CMP020C101');
INSERT INTO Programme_Modules VALUES('09UU0002','CMP020C102');
INSERT INTO Programme_Modules VALUES('09UU0002','CMP020C103');
INSERT INTO Programme_Modules VALUES('09UU0002','CMP020C104');
INSERT INTO Programme_Modules VALUES('09UU0002','CMP020C105');
INSERT INTO Programme_Modules VALUES('09UU0002','CMP020C106');
INSERT INTO Programme_Modules VALUES('09UU0003','PHY020C101');
INSERT INTO Programme_Modules VALUES('09UU0003','PHY020C102');
INSERT INTO Programme_Modules VALUES('09UU0003','PHY020C103');
INSERT INTO Programme_Modules VALUES('09UU0003','PHY020C106');
CREATE TABLE Students(
id INT PRIMARY KEY,
name VARCHAR(50) NOT NULL);
INSERT INTO Students VALUES(1,'Kevin Chalmers');
INSERT INTO Students VALUES(2,'Lisa Haskel');
INSERT INTO Students VALUES(3,'Arturo Araujo');
INSERT INTO Students VALUES(4,'Sobhan Tehrani');
INSERT INTO Students VALUES(100,'Oge Okonor');
INSERT INTO Students VALUES(200,'Kimia Aksir');
CREATE TABLE Student_Programme(
id INT,
programme VARCHAR(8),
FOREIGN KEY (id) REFERENCES Students(id),
FOREIGN KEY (programme) REFERENCES Programmes(id));
INSERT INTO Student_Programme VALUES(1,'09UU0002');
INSERT INTO Student_Programme VALUES(2,'09UU0001');
INSERT INTO Student_Programme VALUES(3,'09UU0003');
INSERT INTO Student_Programme VALUES(4,'09UU0001');
```

You should now see tables listed in test_database, populated with values

Finally, you are ready to build some database-driven web pages!!


### Beginning a database-driven app for students, programmes and modules

You will now work through the following tasks.  The first set are worked through for you in the provided video. 

#### Worked tasks

1. Provide JSON output listing all students
2. Provide an HTML formatted output listing all students in a table where each student is linked to a single-student page
3. Create a single-student page which lists a student name, their programme and their modules

See the screencast for the worked example:
[https://roehampton.cloud.panopto.eu/Panopto/Pages/Viewer.aspx?id=d52ae6e3-d16f-43d8-83bc-add100d52764](https://roehampton.cloud.panopto.eu/Panopto/Pages/Viewer.aspx?id=d52ae6e3-d16f-43d8-83bc-add100d52764)

CONCENTRATE ON THE FIRST TWO TASKS

#### Independent tasks

1. Provide a JSON output of all programmes
2. Provide a HTML formatted output of all programmes in a table, where each programme is linked to a single-programme page
3. Create a single-programme page showing the programme title and listing all modules for the programme
4. Provide a JSON output of all modules
5. Provide a HTML formatted output of all modules in a table, where each module is linked to a single-module page
6. Provide a single-module page showing a module title, its programme and all the students for that module.


### Considering best practices

The worked example here is messy but it is useful as it provides a simple solution that introduces the most important principles all in one place, but this is not professional standard code.

Next week we will 'refactor' this code to provide a cleaner solution.  We will be usingthe following programming techniques to improve our code:

 * Custom classes
 * Async functions and the await keyword
 * Separation of presentation and functionality (hint: we will use the Pug templating system to do this)
  * Adherence to accepted coding standards
