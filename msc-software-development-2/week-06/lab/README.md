# Software Development 2: Using node.js, Express.js and connecting to MySQL

## Prerequisites

You will need to add to your development environment to enable you to work across all of our server-side software.

We use the industry  standard tool, Docker, to build a consistent cross-platform development environment.

## Docker development environment quickstart

1. Ensure Docker is installed on your computer OR use the azure virtual machine installation.
2. Download the zip file of the startup files you'be been given and extract it.
3. Move the extracted folder into your documents (win) or home (mac) directory.
2. Open a new window in VS code, choose 'open folder' and open the folder you just created. Choose, yes I trust the authors.  You should now see the startup files in your file explorer.
3. Open a new terminal in VS code
4. run 

```npm install```


5. run 

```docker-compose up```


Pulling the docker containers will take some time and you may see the server start and restart several times.  This is normal for the first startup.

6. To check everything is running visit (in your browser)

http://127.0.0.1:3000  
http://127.0.0.1:8081  

At the first address you are accessing the node.js server and at the second one, the phpmyadmin interface to MySql.


## Express.js

Before diving into database driven development, lets look at the node.js framework Express.js, which is providing us with a 'middleware' framework, receiving requests, giving us a framework for processing them which may include accessing a database, and sending back a response.

### RESTful Interfaces

REST stands for [Representational State Transfer](https://en.wikipedia.org/wiki/Representational_state_transfer). This is a software architecture for web services that is driven by structured  URLs. 
We interact with our web service by accessing a URL with a particular HTTP message type:

- `GET` will return data from the web service. This is the standard HTTP message used when we get a webpage.
- `POST` sends data to the web service. This is the HTTP message used when you send data from a webpage, such as in a form.
- `DELETE` allows deletion of data in the web service.

The approach Express takes is to provide a framework in which we define URLs or 'routes'.  These call a function when our server receives a request.  Most importantly, parts of the URL can by dynamic ie. can send a variable in to the function.


## Dynamic routes

We now know how to create web pages and make them interactive with javascript and HTML forms. We can also run a webserver to receive requests, route them to the correct file and return an appropriate response.

To take this to the next stage, we will use another Node.js library -- Express.js. This will enable use to create more sophisticated 'routes' ie. paths to files or functions, with more sophisticated functionality that can process dynamic input and produce output accordingly.

You can install it by running the following in the terminal in the root folder of your repository - but it should be present in your scaffolding files.

```shell
npm install express
```



## Simple Express.js application

Look at your scaffolding files, at the app.js file.  This file has code which processes all web requests that are received.

Find the following lines of code in app.js.

```javascript
// Import express.js
const express = require("express");

// Create express app
var app = express();

// Create a get for root - /
app.get("/", function(req, res) {
    res.send("Hello world!");
});

```

And make sure you understand them.  Visit http://127.0.0.1:3000.  Do you see what you expect?

Alter this code so that it says 'Hello everybody'.  If the scaffolding files are working correctly, you will NOT have to restart your node.js webserver manually to see you changes.

Now find the following lines of code.  This creates a route for /goodbye and we can put any logic we need to run when a GET request is received.

```

// Create a route for /goodbye
// Responds to a 'GET' request
app.get("/goodbye", function(req, res) {
    res.send("Goodbye world!");
});
```

Visit http://127.0.0.1:3000/goodbye

do you get the result you expect?

Visit http://127.0.0.1:3000/goodbye-student

do you get the result you expect?  (HINT: you have not defined any functionality for this route yet, so it will probably be an error of some kind)

__Add a route for goodbye-student which sends some output to the screen when this route is accessed.__


## Dynamic routes in Express.js

Find the following code in the app.js file:

```
// Create a dynamic route for /hello/<name>, where name is any value provided by user
// At the end of the URL
// Responds to a 'GET' request
app.get("/hello/:name", function(req, res) {
    // req.params contains any parameters in the request
    // We can examine it in the console for debugging purposes
    console.log(req.params);
    //  Retrieve the 'name' parameter and use it in a dynamically generated page
    res.send("Hello " + req.params.name);
});
```

This is an example of a dynamic route. 

The ```:name``` part, indentified by the colon prefix, is not a fixed value but is instead a variable name for a 'parameter' you can then use in your code. We can retrieve the variable via the ```req.params``` object. 

Run this code by visting the following in your browser:

```
http://127.0.0.1/hello/Lisa
```

Look in the console (terminal window of VS code) as you run this and see the console.log message.  You will see the name parameter and its value appended to the req.params object.

### Build your understanding

_1. _What happens if you append a different name to the url in the browser?__

_2.  _Try running the above code but put a colon before the 'hello' in the route.  Examine the console output and explain what has now happened.__

### Further tasks

Add the following end point URLs to the application:

- `/test` will display `Welcome to the test page!`
- `/student/:id/:name` should display a table with the submitted student ID and name. **HINT** -- you will have to construct the string in the response to be HTML.

## Checking database connectivity

### Check your understanding

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
   

### Create a test table and access via Express

   1. Find the sb2-test.sql file in the scaffolding files.
   2. Access Phpmyadmin by going to http://127.0.0.1:8081.
   3. Click onto the sd2-test database in the left side, and, using the SQL    window, paste the contents of the SQL file there.  Click run. You will now have some content for the test table
   4. Access http://127.0.0.1/db_test to see the contents of the table
   
   
   
 ## Further tasks
 
Develop your knowlege and skills with connecting to a database from Express with the following lab sheet:
 
 [Asynchronous Javascript introduction](./session-6-db-and-async.md)