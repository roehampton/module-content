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
  document.write(name + "<br>");
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