# Software Development 2 Lab 1 -- Getting Started with Web Development

## Setting Up a Development Environment

In this module, we are going to use Visual Studio Code to edit our code files. Visual Studio Code is an enhanced text editor that supports extensions. As web pages are just text files this makes Visual Studio Code an ideal tool to use.

Visual Studio Code can be downloaded from https://code.visualstudio.com/.

1. **Download Visual Studio Code for your operating system.**
2. **Install Visual Studio Code**.
3. **Once installed, start Visual Studio Code**.

Once started, you will be presented with the following window:

![image-20201226180131969](image-20201226180131969.png)

### So you want to know more?

We are going to dive into Visual Studio Code here, but if you want to spend more time become familiar with the tool, the documentation has a collection of videos that introduce the core features. The documentation is available at https://code.visualstudio.com/Docs and the videos are available at the bottom of this page.

### Visual Studio Code Extensions

On the left hand side of the Visual Studio Code window, you will see five buttons. These are:

* **Explorer** where you can view the files in your project.
* **Search** which lets you find items in your project.
* **Source Control** which is about managing versions of your software. We will explore this in more detail next week.
* **Run** which allows us to run our code if that is suitable.
* **Extensions** which allows us to manage installed extensions in Visual Studio Code.

**Click the Extensions button and the screen will change to the following:**

![image-20201226181004403](image-20201226181004403.png)

To install an extension:

1. Search for it in the search bar at the top of the extensions panel.
2. Click the install button.

#### Now you try

**Add the following extensions to Visual Studio Code:**

- **Auto Close Tag.** This extension makes life a little easier for HTML.

### Creating Your First Project

**Now click on the Explorer button on the left-hand side of the Visual Studio Code window. The window will change to the following:**

![image-20201226182020475](image-20201226182020475.png)

**Click the Open Folder button. Go to the folder that you plan to work from in this module.** Your screen should now be as follows:

![image-20201226182328618](image-20201226182328618.png)

**Right-click the explorer pane (outlined in blue in the image above) and select New File to create a new file.** You are now ready to continue on with the rest of the lab.

## Document Structure

We interact with numerous documents in our day-to-day life -- from web articles, to books, newspaper articles, and flyers. One common aspect of documents are they have a structure. For example, a book has:

- A title.
- Chapter headings.
- Text.
- Possibly images.

Structure helps us understand how to read a document. A web page is no different.

When physical documents are represented as web pages, they are often very similar. A news article and an FAQ follows the same guidelines.

For example, you can create a Word document using the different styles such as headers. For example:

> # This is the Main Heading
>
> This is some introduction text. We normally introduce our text.
>
> ## This is a Sub-Heading
>
> We use sub-headings to break up large documents.
>
> ## This is Another Sub-Heading
>
> Some more text.

HTML -- HyperText Markup Language -- is how we describe web page structure. An HTML file is just a text document. We set the structure using HTML elements defined via opening and closing tags.

## Introduction to HTML and Web Pages

Let us look at the most basic web page using our content for a Word document above.

```html
<!DOCTYPE html>
<html>
  <head>
    <title>My First Web Page!</title>
  </head>
  <body>
    <h1>
      This is the Main Heading
    </h1>
    <p>
      This is some introduction text. We normally introduce our text.
    </p>
    <h2>
      This is a Sub-Heading
    </h2>
    <p>
      We use sub-headings to break up large documents.
    </p>
    <h2>
      This is Another Sub-Heading
    </h2>
    <p>
      Some more text.
    </p>
  </body>
</html>
```

> **STOP**. Take your time now and look at the HTML code above and compare it to the document presented previously. Can you see the structure of the document.

You can find the web page generated from this code [here](first.html).

> **EXERCISE** Enter this code into your editor and save the file as `first.html`. Then open this file in your web browser to see the result.

HTML files use *tags* to specify elements. A tag defines an *element* in our web page. For example, `<p>` is used for a paragraph or text element.

Most elements are defined using an opening tag, e.g., `<p>`, and a closing tab, e.g., `</p>`. Everything within the opening and closing tag is part of the defined element.

HTML tags can also have *attributes*. For example, try changing one of the opening `<p>` tags to the following:

`<p style="color:red; ">`

A tag's attribute is set using its *name* (here we set `style`) and use `=` and a value in quotes. We will come across various tags as we continue to develop our skills.

Let us look at the different parts of the HTML document:

- `<!DOCTYPE html>` starts an HTML file. **THIS IS REQUIRED**. Your browser uses this tag to know what type of document it is receiving.
- `<html> ... </html>` denotes the main HTML document contents.
- `<head> ... </head>` defines the header of the HTML document. Most header information is not displayed on the web page. It is used to provide additional information about the web page.
- `<title> ... </title>` is the title of the web page as it appears in the browser tab. The title is not displayed in the web page itself. It is just used as the page title in the browser tab.
- `<body> ... </body>` is the main body of the HTML page. This is the contents rendered by the browser and displayed to the user.
- `<h1> ... </h1>` is a top-level (level 1) header.
- `<h2> ... </h2>` is a level 2 header (sub-heading).
- `<p> ... </p>` defines a paragraph

### Now you try

Try and create the following web pages using HTML and view them in your browser. You will probably need to use the resources listed in **So you want to know more.**

First page.

> # Welcome to Software Development 2
>
> This is a module delivered at [The University of Roehampton](https://www.roehampton.ac.uk).
>
> We can also define list items:
>
> - List item 1.
> - List item 2.
> - List item 3.
> - List item 4.
>
> And tables:
>
> | Column Header 1 | Column Header 2 | Column Header 3 |
> | --------------- | --------------- | --------------- |
> | Some data       | Some data       | Some data       |
> | Some data       | Some data       | Some data       |

Second page.

> # My Personal Web Page
>
> Images are easy. You can get the Wikipedia Logo [here](https://upload.wikimedia.org/wikipedia/en/thumb/8/80/Wikipedia-logo-v2.svg/1200px-Wikipedia-logo-v2.svg.png)
>
> ![Wikipedia Logo](https://upload.wikimedia.org/wikipedia/en/thumb/8/80/Wikipedia-logo-v2.svg/1200px-Wikipedia-logo-v2.svg.png)

### So you want to know more

We don't aim to teach you HTML as part of this module. HTML is quite a simple concept once you understand the idea of tagging sections of a text file to present it in a particular manner in the browser.

One of the best places to learn web development for free is [w3schools](https://www.w3schools.com/).

[TutorialsPoint](https://www.w3schools.com/html/default.asp) also provides good web resources.

There are many HTML references online. We recommend [Mozilla's](https://developer.mozilla.org/en-US/docs/Web/HTML/Reference) as a good one.

## Introduction to JavaScript

HTML isn't really programming. There is no execution -- sequence, selection, or iteration. HTML just describes a document structure. So how do we program the web?

There are actually a number of ways we can program websites. This has increased greatly since 2017 since the adoption of the [WebAssembly](https://en.wikipedia.org/wiki/WebAssembly) standard -- that's right, assembly programming for the web. Many organisations are interested in WebAssembly as it can be generated from multiple languages and creates fast web pages.

However, the majority of the web is today programmed in JavaScript. This module focuses on using JavaScript for both front-end (web page or client-side) and back-end (server-side) programming.

Let us look at an example of some JavaScript:

```javascript
document.write("Hello, world!");
```

This simply adds the text `Hello, world!` to a web page. `document` is the web page that the JavaScript is running on.

JavaScript is similar to Python and other C like languages. As we start building some web pages with JavaScript code you will see what we mean.

### Your First JavaScript Enabled Web Page

There are various ways to use JavaScript in your web page. We are going to split our JavaScript code into a separate file from our HTML document. You can embed JavaScript into a web page, but it does not allow easy reuse of JavaScript.

> **Create a new file called `script1.js` and save it in the same folder as your HTML files. Use the the JavaScript code from above.**

To add the script to a HTML file we use the `<script>` element. Add the following to one of the HTML files within the `<head> ... </head>` section, just under the `<title>` tag.

```html
<script src="script1.js"></script>
```

**Make sure you have saved the changes to all files.** Then open the HTML file again in your browser and you should see `Hello, world!` displayed on the page.

> #### The `<script>` Tag
>
> We use `<script>` to import a script into our web page. There are two main ways we can do this.
>
> 1. Setting the `src` attribute to point to the file we want to import.
> 2. Putting the code between the opening and closing `<script>` tags.
>
> For example, for two, we could have written the following directly into our HTML page:
>
> ```html
> <script>
> document.write("Hello, world!");
> </script>
> ```
>
> `<script>` tags can be placed anywhere in your HTML document. As we've placed our `<script>` tag at the top of the page, it is processed there, which means `Hello, world!` appears at the top of the page.
>
> **EXERCISE** Try putting the `<script>` tag in the body of the page and see what happens.
>
> Your HTML document can also have multiple `<script>` tags.
>
> **EXERCISE** Try adding the `<script>` tag in multiple places in your HTML file to see what happens.

### More on JavaScript Code

JavaScript has many similarities to Python. It is an interpreter language (you don't have to compile code) and it is dynamically typed (variables can change type). As such, many of ideas you know from Python will work in JavaScript. Let us look at various elements in JavaScript here as a reference point.

#### Variables

Variables in JavaScript are declared with the `var` keyword.

```javascript
var name = "Kevin";
var age = 42;
var male = true; // Notice all lowercase true
```

Apart from requiring the `var` keyword, variables in JavaScript work much the same as Python.

#### Sequence

As Python and any *imperative* language, JavaScript statements are executed in order. **NOTE** JavaScript statements all end in a semi-colon -- `;`.

#### Conditionals -- Selection

JavaScript provides `if` conditional statements that operate the same as Python. The general structure of a JavaScript `if` statement is as follows:

```javascript
if (condition) {
  // block of code to run when condition is true
}
```

There are two things to note that are different to Python:

- The condition **must** be surrounded by parentheses, e.g., `(age == 42)` not `age == 42`.
- JavaScript requires curly brackets `{ ... }` to denote which code to execute if the `if` statement is `true`. This is different to Python's use of indentation. **THIS IS A VERY IMPORTANT DIFFERENCE.**

An `else` branch can also be defined:

```javascript
if (condition) {
  // block of code to run when condition is true
}
else {
  // block of code to run when condition is false
}
```

JavaScript doesn't have `elif` as Python, and so the `else if` must be written out in full.

```javascript
if (condition) {
  // block of code to run when first condition is true
}
else if (condition) {
  // block of code to run when second condition is true
}
else {
  // block of code to run when both conditions are false
}
```

JavaScript also supports a `switch` statement. If you've not used a `switch` statement, it checks the value of a variable and then runs the appropriate code block. For example:

```javascript
switch (age) {
  case 40:
    // block of code to run when age == 40
    break;
  case 42:
    // block of code to run when age == 42
   	break;
  default:
    // block of code to run when otherwise
}
```

You can find out more about JavaScript `switch` statements [here](https://www.w3schools.com/js/js_switch.asp).

#### Loops -- Iteration

JavaScript supports both `for` and `while` loops.

##### `for` Loops

JavaScript has three different for loops. The first one is normally used to iterate across a range of numbers.

```javascript
for (var i = 0; i < 10; i++) {
  // block of code to run 10 times
}
```

There are a few points to note in this code.

- The general structure of the `for` loop is `for (initialisation; condition; post statement)`. Notice that these must be surrounded by brackets, and separated by semi-colons.
- The `initialisation` part is where we declare our counting variable.
- The `condition` part is checked at the start of every loop iteration to determine if the loop should continue.
- The `post statement` is run at the end of every loop iteration.
- The statement `i++` increments `i` -- it is the same as saying `i = i + 1`. Incidentally, `i--` will decrements `i`.

The second type of `for` loop is `for (var of collection)`. It is the same as Python's `for value in collection` loop. For example:

```javascript
var names = ["Kevin", "Amitave", "Kimia"];
for (var name of names) {
  documents.write(name + "<br>");
}
```

This will add each name to the HTML document. `<br>` is the HTML tag for inserting a new line.

Finally, JavaScript has a `for (var in object)` loop. This loop iterates through the properties of an object. We're going to examine object-orientation in this module, and will return to this `for` loop then.

##### `while` Loops

JavaScript provides two `while` loops. The first one you will be familiar with:

```javascript
while (condition) {
  // block of code to run while condition is true.
}
```

The second is a `do ... while (condition)` loop. This is different to the standard `while` loop as it *will always run at least once.* A normal `while` loop may not run, but a `do ... while` loop will always run at least once. A `do ... while` loop is shown below:

```javascript
do {
  // block of code to run.
}
while (condition);
```

#### Functions

Functions in JavaScript are also similar to Python:

```javascript
function myfunction(parameters) {
  // code to execute
  return value;
}
```

Apart from using `function` to declare a function, and using curly brackets to define the start and end of the function, everything is the same in JavaScript and Python.

#### Comments

Comments in JavaScript start with `//`. As comments can contain anything we won't go into any further details. 

> **EXERCISE** You now know enough to translate many of your previous programs written in Python into JavaScript. Select one such program of sufficient complexity and convert it to run in the browser. **NOTE** You don't know how to do input yet, so either select a program that does not require user input, or modify one that does to use hard-coded values.

### Your Second JavaScript Enabled Web Page -- Using Buttons

HTML can define user interfaces to suit our needs. In this example we will add a button to our page. Save the following HTML code as `second.html`.

```html
<!DOCTYPE html>
<html>
  <head>
    <title>Buttons!</title>
    <script src="script2.js"></script>
  </head>
  <body>
    <h1>
      Click the button!
    </h1>
    <input type="button" value="Click Me!" onclick="msg()">
  </body>
</html>
```

The new HTML element we've introduced here is `<input>`. We have defined three attributes:

- `type` is the type of input element. We are using a button, so we set this to `button`. There are other input types we can also define.
- `value` is the text on the button. We've set this to `Click Me!`.
- `onclick` is the code that will be run when we click the button. This is an *event* that our JavaScript will respond to. It will execute the `msg` function.

All we need to do is write our JavaScript code in `script2.js`. We need to implement the `msg` function.

```javascript
function msg() {
    document.write("You clicked the button!");
}
```

**Save everything and then open the HTML document in your browser.** When you click the button the web page will be replaced with `You clicked the button!`

> **EXERCISE** add a second button to the HTML page. When this button is clicked, it should display the message `Not that button!`

### Manipulating HTML Elements

OK, so far we've done the following:

* Displayed a message in the window.
* Reacted to a button press.

Let's complete the basic use of interacting with HTML from JavaScript by manipulating an HTML element that exists on the web page. Our new web page is defined as follows:

```html
<!DOCTYPE html>
<html>
  <head>
    <title>My Changing Web Page!</title>
    <script src="script3.js"></script>
  </head>
  <body>
    <h1>
      Click the button!
    </h1>
    <input type="button" value="Click me!" onclick="change()">
    <p id="my_text">
      Hello, world!
    </p>
  </body>
</html>
```

Notice our `<p>` element has the attribute `id` set to `my_text`. This gives this HTML element a unique name (just like a variable) that means our JavaScript can get the element from the web page. `script3.js` shows how we do this:

```javascript
function change() {
    var element = document.getElementById("my_text");
    element.innerText = "You clicked me!";
}
```

Our two lines of code do the following:

- `document.getElementById("my_text")` gets the HTML element with the `id` `my_text` -- our `<p>` element we set earlier. We set this to a `var` named `element`.
- We set `innerText` of the element to `You clicked me!`. `innerText` is the text within the HTML. To start with, this is `Hello, world!`.

**Save all the files and open the HTML document in your browser.** You can click the button and the text of the `<p>` element will change.

Well done! You've actually covered a good amount of how we can program web pages:

- Setting events.
- Getting elements by their `id`.
- Changing elements.

### Now you try

This exercise combines the parts we've learned so far. Create a web page with some text in a paragraph element and with a button. When the user clicks the button, it should change the colour of the text in the paragraph to red. As some help, once you have got the HTML element, you can use this code to change the *style* of an HTML element to set its colour to `red`.

```javascript
element.style['color'] = "red";
```

Then add a second button that will change the text colour to blue.

### So you want to know more

This module focuses on JavaScript, so we will cover much more code. But if you want to do more, [Tutorialspoint](https://www.tutorialspoint.com/javascript/index.htm) also has a JavaScript tutorial.

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
4. 