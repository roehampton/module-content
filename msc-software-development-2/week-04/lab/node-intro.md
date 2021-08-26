

## Serving web pages with Node.js

### Installing and Testing Node

Node.js is a popular server-side runtime that can run JavaScript code outside a browser. Node.js is available from https://nodejs.org/en/.

1. **Download Node.js for your operating system.**
2. **Install Node.js onto your system. Make sure you have Node.js added to the PATH in Windows.** 
3. **Follow the rest of this lab.**

Once Node.js is installed, you can open the command prompt and type `node` to test it. You will be presented with the following:

```shell
~ node
Welcome to Node.js v14.7.0.
Type ".help" for more information.
>
```

Much like Python's interactive console, you can enter JavaScript commands here:

```shell
> console.log("Hello, world!");
Hello, world!
undefined
```

We aren't going to use Node.js in this manner. Type `.exit` into the command prompt to exit Node.js.

### Your First Node.js Application

Let us recreate the *Hello World* JavaScript example in a file and ask Node to run it for us. **Create a new file called `hello.js` and use the following code:**

```javascript
console.log("Hello, world!");
```

**In Visual Studio Code, select View then Terminal from the main menu. This will open a terminal at the bottom of the Visual Studio window.**

![image-20201226183646432](image-20201226183646432.png)

This is just a normal command-line terminal. It is just embedded into Visual Studio Code to make our life easier.

**To run your program, enter the command `node hello.js` in the terminal. `Hello, world!` will be printed to the terminal.**

This is generally how we will run our Node applications at the moment. Things will change later in the module.

#### Now you try

Update the application to print `Hello, <name>` where `<name>` is your name.

### A Node.js Server

Although Node.js can run applications locally, JavaScript is a language aimed at how the web and Internet work. It is not good at applications that interact with users on a local machine. Rather, Node.js is used to create server-side applications. Indeed, Node.js makes this quite easy. Try the following Node.js application, `server.js`:

```javascript
// Load the http module from Node's standard library
const http = require("http");

// The hostname we will run the server on.
// 127.0.0.1 is the localhost
const hostname = "127.0.0.1";
// The port the server will listen on.
const port = 3000;

// Create the server.
// The server requires a function with parameters req, res
// that will run when requests are received from a web browser.
// req - the incoming request from the web browser.
// res - the outgoing response we will send from the browser.
const server = http.createServer(function(req, res) {
    // Respond with OK message.
    res.statusCode = 200;
    // The type of content we are returning. Just plain text.
    res.setHeader("Content-Type", "text/plain");
    // The plain text we are returning.
    res.end("Hello, world!");
});

// Start the server listening on the port of the hostname.
// A function is required to execute on successful server start.
// Notice these are backticks ` and not single quotes '.
server.listen(port, hostname, function() {
    console.log(`Server running at http://${hostname}:${port}/`);
});
```

**Run in the Visual Studio Code terminal by executing `node server.js`.** Once running, **go to `127.0.0.1:3000` using your web browser.** You should see `Hello, world!` in the browser.

> #### HTTP Status Codes
>
> You can find out more about HTTP status codes on [Wikipedia](https://en.wikipedia.org/wiki/List_of_HTTP_status_codes). You've probably seen some of these before, such as the dreaded 404.

**To stop the HTTP server, use `CTRL-C` in the terminal.**

#### Now you try

1. Change the server to respond with `Hello, <name>` where `<name>` is your name.
2. Modify the line `res.end("Hello, world!");` to `res.end("Hello, " + req.url);` and then go to the URL `127.0.0.1:3000/<name>` where `<name>` is your name. Explain what has happened.

### Serving Static Web Pages

We can use the above technique to serve our previous web pages (*static web pages*), but this is quite error prone. Instead, we can use a Node.js package to do a lot of the work for us. **First, run the following in the Visual Studio Code terminal.**

```shell
npm install node-static
```

`npm` is the *Node Package Manager*. We are asking it to install the `node-static` library. This allows us to enter the following program, `static.js` (below). **Make sure this file is created and ran from the same location as your HTML files**:

```javascript
// Import the node-static library
const static = require("node-static");
// Import the http server library
const http = require("http");

// This creates a static file server for on the directory __dirname
// __dirname is the directory the Node application is working in.
// Similar to cwd (Current Working Directory)
var file = new(static.Server)(__dirname);

// The hostname and port the server will listen on.
var hostname = "127.0.0.1";
var port = 3000;

// Create the HTTP server with the function used to service requests.
const server = http.createServer(function(req, res) {
    // Delegate request to the static file server.
    file.serve(req, res);
});

// Start the server.
server.listen(port, hostname, function() {
    console.log(`Server running at http://${hostname}:${port}/`);
});
```

**Run the `static.js` file from the Visual Studio Code terminal:**

```shell
node static.js
```

Now you access your previous HTML files from this lab by using, for example, the following URL `127.0.0.1:3000/first.html`.

#### Now you try

Without restarting the Node.js server we just started, create a new file -- `test.html` -- and add some HTML content to it. You should be able to immediately access this file in your web browser using `127.0.0.1:3000/test.html`.

#### So you want to know more

The main Node.js documentation is available at https://nodejs.org/en/docs/. TutorialsPoint also provides a [Node.js tutorial](https://www.tutorialspoint.com/nodejs/index.htm). We will cover many of these ideas in the module, but additional resources are always useful.

## Exercises

1. Update the Node.js server so it prints to the console the URL requested.
2. Update the Node.js server so that if the URL `/roehampton` is requested, the server returns `Hello from Roehampton!`. **HINT** -- use an `if` statement to test the value of URL. Remember to add `res.end();` to complete the response.
3. Update the Node.js server so that if the URL `/roehampton` is requested, the server will redirect the browser to Roehampton's website. **HINT** -- the status code for a redirect is 302, and you will need to set the `Location` using `res.setHeader`.