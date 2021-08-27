# Software Development 2 Lab -- Express.js

We can now create web pages and make them interactive with javascript and HTML forms. We can also run a webserver to receive requests, route them to the correct file and return an appropriate response.

To take this to the next stage, we will use another Node.js library -- Express.js. This will enable use to create more sophisticated 'routes' ie. paths to files or functions with more sophisticated functionality that can process dynamic input and produce output accordingly.

You can install it by running the following in the terminal in the root folder of your repository:

```shell
npm install express
```

So what is Express.js? It provides RESTful interfaces.

## RESTful Interfaces

REST stands for [Representational State Transfer](https://en.wikipedia.org/wiki/Representational_state_transfer). This is a software architecture for web services that is driven by URLs. We interact with our web service by accessing a URL with a particular HTTP message type:

- `GET` will return data from the web service. This is the standard HTTP message used when we get a webpage.
- `POST` sends data to the web service. This is the HTTP message used when you send data from a webpage, such as in a form.
- `DELETE` allows deletion of data in the web service.

The approach Express takes is to provide a framework in which we define URLs or 'routes'.  These call a function when our server receives a request.  Most importantly, parts of the URL can by dynamic ie. can send a variable in to the function.

 Let us build a first Express.js application. **Enter this code as `express_server.js`:**

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
app.listen(3000,function(){
    console.log(`Server running at http://127.0.0.1:3000/`);
});
```

Here we have defined the `/` (root folder) to respond with `Hello world!`. **Now run this programme with the following:**

```shell
node express_server.js
```



**Open your browser, and go to `127.0.0.1:3000`**. You should see `Hello world!` displayed.

To build up an application we will get Express to listen on some other URLS, in other words, we will create 'routes' for our requests and give back different responses according to the requested route.

**Shutdown the server with CTRL-C and update `express-server.js` to the following:**

```javascript
// Import express.js
const express = require("express");

// Create express app
var app = express();

// Create a get for root - /
app.get("/", function(req, res) {
    res.send("Hello world!");
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
    res.send("Hello " + req.params.name);
});

// Start server on port 3000
app.listen(3000,function(){
    console.log(`Server running at http://127.0.0.1:3000/`);
});
```

There are now three URLs you can visit:

- `127.0.0.1:3000` will display `Hello world!`.
- `127.0.0.1:3000/goodbye` will display `Goodbye world!`.
- `127.0.0.1:3000/hello/<name>` will display `Hello <name>` for any value of `<name>`. Try your own name.

### Dynamic values in routes

Note that the parts of the URL prefaced with a ':' are dynamic, ie. the name you provide is just a label - think of it as a variable name - for a dynamic value.  These parameters are the available via the req.params variable.

Try running the above code but put a colon before the 'hello' in the route.  Examine the console output and explain what has now happened.

### Now you try

Add the following end point URLs to the application:

- `/test` will display `Welcome to the test page!`
- `/student/:id/:name` should display a table with the submitted student ID and name. **HINT** -- you will have to construct the string in the response to be HTML.

