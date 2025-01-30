:w
#  Backend programming with Node.js and Express.js

## Whats in this lab?

Now that you have your development environment running, in this lab you will start writing 'backend' code. This means, code that runs on the server side, catching requests from the user, using business logic and information from those requests to compose and send out the required response.

You will be using the Express.js framework to provide the 'routing engine' that accepts requests on different URL paths, writing business logic to process the users request and then send a response back out to the requestors browser.

A basic node.js and express.js framework is provided for you via the scaffolding files you have download and are running within Docker.

In the scaffolding files, we have a file ```index.js``` which forwards requests to a file called app.js.    In app.js we will write our server-side code.


### Running the scaffolding files

Make sure you can run docker-compose up and reach display the text "hello world" at http://localhost:300

### Express


Our application code runs in the ```app.js``` file.  

Note the 'require' statements that create an express app and a static folder, AND pull in code that help you connect to the database.

The main purpose of the app.js file is to 
  * Run a web server that listens on a given port (lines 46 - 48)
  * Intercept client requests
  * Define functions that will run when particular URL paths are reqested

### Basic routing

An example of a route is this (line 14)

```
// Create a route for root - /
app.get("/", function(req, res) {
    res.send("Hello world!");
});

```

Here we intercept requests to '/' and send a response back with the text 'hello world'

__EXERCISE 1__: Change this route to say hello + your name.  Watch the server reload in the terminal and reload your browser to see the result of your changed code.

__EXERCISE 2__: Create a new route with path '/roehampton which should send the text 'hello roehampton' to the user when they request the url: ```http://localhost/roehampton```

__EXERCISE 3__: Create a new route with path '/roehampton which should send the text 'hello roehampton' to the user when they request the url: ```http://localhost/roehampton```

__EXERCISE 4__: practice debugging to the console: In the route you have just created, add the following line to the body of your function:

```
console.log(req.url)
```

Notice when you load your page, the path is displayed in the terminal window

__EXERCISE 5__: Add some programming logic in your route function

   * create a variable in which you capture the request path
   * send only the first 3 letters out to the browser
   

Your function will now look something like this;

```
// Create a route for roehampton with some logic processing the request string
app.get("/roehampton", function(req, res) {
    console.log(req.url)
    let path = req.url;
    res.send(path.substring(0,3))
});


```




### Dynamic routes

Note that the parts of the URL prefaced with a ':' are dynamic, ie. the name you provide is just a label - think of it as a variable name - for a dynamic value.  These parameters are the available via the req.params variable.

See for example the function in the scaffolding files:

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

__EXERCISE 1 :__ Run this code by sending a request, for example:

```
http:://localhost:3000/hello/lisa

```
Observe the output, and also the console

Now try:

```
http:://localhost:3000/hello/john

```

Notice that the req.params object contains the label and the value of the parameter passed

__EXERCISE 2 :__

Create a dynamic route which where a user may request /user/:id where the ID can be any ID number.  Output the input ID to the browser.

__EXERCISE 3 :__

Create a dynamic route which where a user may request /student/:name/:id where the ID can be any ID number, and the name can be any name.  Output the name and ID to the browser

__EXERCISE 4 :__

Using the above route: output the name and ID in an HTML table



### Serving static files

When you work in app.js the server must reload each time the code changes. For a more conventional webserver that can serve 'static' content such as html files or images, a 'static' directory has been created for you.

#### Exercise

Without restarting the Node.js server, create a new file -- `test.html` -- and add some HTML content to it. 

Make sure this file is in the directory called 'static'.

Note the path to this in the app.js file.

You should be able to immediately access this file in your web browser using `127.0.0.1:3000/test.html`.


### Additional tasks

__Additional task 1__: More javascript practice.  

   * capture the request in a variable
   * create an array of all the characters in the request
   * remove the leading '/'
   * print roehampton backwards in the browser

(just to show how you can use any programming logic inside a routing function and start to use javascript documention to help you write code.  HINTS:  try split, splice, reverse and join)

__Additional task 2__: 

Create a dynamic route where the user may request /number/:n where n is any number.  Output all the numbers from 0 to the number entered, formatted in an HTML table.



## Coming next...

Later, we will connect a database to our express application and use the dynamic routes to create, retrieve, update and delete information in the database.  We will also look at how the presentation (ie. HTML generation) can be improved but kept seperate from business logic by using a templating system and MVC (Model View Controller) architecture.

ie. we will have everything we need to create a simple 'CRUD' web application using some best pratices in software design.
