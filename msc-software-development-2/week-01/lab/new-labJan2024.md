# Introducton to HTML

## Setup development environment

> In this module, we are going to use Visual Studio Code to edit our code files. Visual Studio Code is an enhanced text editor that supports extensions. As web pages are just text files this makes Visual Studio Code an ideal tool to use.

 > Visual Studio Code can be downloaded from https://code.visualstudio.com/.

> 1. **Download Visual Studio Code for your operating system.**
> 2. **Install Visual Studio Code**.
> 3. **Once installed, start Visual Studio Code**.

> Once started, you will be presented with the following window:

> ![image-20201226180131969](image-20201226180131969.png)


> ### Visual Studio Code Extensions

> On the left hand side of the Visual Studio Code window, you will see five buttons. These are:

> * **Explorer** where you can view the files in your project.
> * **Search** which lets you find items in your project.
> * **Source Control** which is about managing versions of your software. We will explore this in more detail next week.
> * **Extensions** which allows us to manage installed extensions in Visual Studio Code.

> **Click the Extensions button and the screen will change to the following:**

> ![image-20201226181004403](image-20201226181004403.png)

> #### To install an extension:

> 1. Search for it in the search bar at the top of the extensions panel.
> 2. Click the install button.

> **Add the following extensions to Visual Studio Code:**

>  **Auto Close Tag.** This extension makes life a little easier for HTML.*


### Creating Your First Project

**Click on the Explorer button on the left-hand side of the Visual Studio Code window. The window will change to the following:**

![image-20201226182020475](image-20201226182020475.png)

**Click the Open Folder button. Go to the folder that you plan to work from in this module.** Your screen should now be as follows:

![image-20201226182328618](image-20201226182328618.png)

**Right-click the explorer pane (outlined in blue in the image above) and select New File to create a new file.  Call this file ```index.html```.  Write your name in the file and save it.

### Setting out your development environment

<hr>

 **NOTE**: You will need to open the file you have created directly in your web browser, which is different from how you usually access a web page which is via its 'url'.  
 
__To open a file__ click into the browser window and press crtl o .  You will see the path to your file in the browser address bar similar to: file:///home/lisah/lessons/github/module-content/msc-software-development-2/week-01/seminar/Slide6.jpg.  

Use the refresh button to show new changes you save to your html file as you develop your pages.
<hr>


## Developer tools

Using the browser developer tools (found in all browsers, but chrome is most commonly used) to debug and refine your front-end code is an essential skill.

__Try it now:__

In your browser window, right click in the page and choose 'inspect'.  A set of windows will appear, probably at the bottom or perhaps to the right of your screen.  Here you will be able to examine the source code of your own page and ensure that it is as you expect. You can even find you can edit the markup, content and styles.



Note that you can do this for any web page!!.  Your changes will only be visible on your own browser and will disappear after you refresh the page.

![devtools.png](devtools.png)

Reference:
https://developer.chrome.com/docs/devtools/overview/

__practice__

![Inspector button](inspector.png)

Click on the inspector tool which you will find in the toolbar as shown above - its the square with the arrow pointing into it - and then onto the heading of your page. You will see the relevant part of the code highlighted in the main 'elements' part of developer tools, and below in the 'styles' window, you will see the CSS rules that have been applied.


See if you can visit this newspaper site which is famous for mis-spellings and change the menu item 'sport' to 'sporty' https://www.theguardian.com/uk

Play with your own pages, so you are full familiar with the relationship between the code editor, browser and developer tools.

## Setting out your development environment

Your enjoyment writing code, and your productivity will be enhanced by gaining fluency in the fundamental tools of web development and its processes.


![Developers Desktop](./developers-desktop.png)

Your desktop should look like the image above where:

   * Your code is visible in Visual Studio Code and you can edit it
   * You also have a browser window open.  __You can see your changes by refreshing the browser without having to reopen the browser window__
   * You can use developer tools to check what the browser is rendering.  You can also use the tools there to check CSS and Javascript as well as other information related to the browser.  You will find out more about this further in this lab sheet.
   * You can use the VS code file explorer to check your file structure

You may also have a terminal window open where you can use git and other command line tools which you will learn next week.



** You are now ready to continue on with the rest of the lab.



## HTML exercises

__Use our [cheatsheet](html-cheatsheet.md) to help plus [W3 schools HTML reference](https://www.w3schools.com/tags/) to find out about the available attributes and correct useage for tags.__

### Basic Page Structure

Create a simple webpage with a title and a heading.

```html

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>My First Webpage</title>
</head>
<body>
    <h1>Welcome to My Webpage</h1>
</body>
</html>
```


Save this code and refresh your browser. Check that you can view it in the browser, and that the HTML code can be seen in developer tools.

Make some changes in the code and check that your changes are coming through.

### Headings and Paragraphs

Expand the previous example with multiple headings and paragraphs.
Notice that various heading levels to emphasize the importance of hierarchy.


```html

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Heading Levels</title>
</head>
<body>
    <h1>Main Heading (Level 1)</h1>
    <p>This is the main content of the page.</p>
    <h2>Subheading (Level 2)</h2>
    <p>Additional text for the subheading.</p>
    <h3>Sub-subheading (Level 3)</h3>
    <p>More text for the sub-subheading.</p>
</body>
</html>
```


### Hyperlinks

Create hyperlinks to navigate between pages. NOTE that you will first need to create `page1.html` and `page2.html`.  These will need to be in the same directory as your `index.html` file.

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Hyperlinks</title>
</head>
<body>
    <h1>Visit Other Pages</h1>
    <ul>
        <li><a href="page1.html">Page 1</a></li>
        <li><a href="page2.html">Page 2</a></li>
    </ul>
</body>
</html>
```

### Tables

Create a table with some data.  Note how the tags here need to be 'nested' correctly

```html

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Table Example</title>
</head>
<body>
    <h1>Student Information</h1>
    <table border="1">
        <tr>
            <th>Name</th>
            <th>Age</th>
            <th>Grade</th>
        </tr>
        <tr>
            <td>John</td>
            <td>20</td>
            <td>A</td>
        </tr>
        <tr>
            <td>Maria</td>
            <td>22</td>
            <td>B</td>
        </tr>
    </table>
</body>
</html>
```

### Images

Add an image to your webpage.

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Image Example</title>
</head>
<body>
    <h1>Beautiful Sunset</h1>
    <img src="sunset.jpg" alt="A beautiful sunset">
</body>
</html>
```

Note that you can use a full URL to an image in the src attribute.  This will work in codepen, for example

```
 <img src="https://upload.wikimedia.org/wikipedia/commons/thumb/a/a4/Anatomy_of_a_Sunset-2.jpg/300px-Anatomy_of_a_Sunset-2.jpg" alt="A beautiful sunset">
```



## Styles

Apply some basic styles to your page.

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Styled Page</title>
    <style>
        body {
            font-family: 'Arial', sans-serif;
            background-color: #f2f2f2;
            margin: 20px;
        }
        h1 {
            color: #0077cc;
        }
    </style>
</head>
<body>
    <h1>Welcome to My Styled Page</h1>
</body>
</html>
```


### Forms

Create a simple form with text input and a submit button.

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Simple Form</title>
</head>
<body>
    <h1>Contact Us</h1>
    <form>
        <label for="name">Name:</label>
        <input type="text" id="name" name="name">
        <br>
        <label for="email">Email:</label>
        <input type="email" id="email" name="email">
        <br>
        <input type="submit" value="Submit">
    </form>
</body>
</html>
```




### HTML5 Page Structure

Use HTML5 semantic elements to structure the page.

```html
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>HTML5 Page Structure</title>
</head>
<body>
    <header>
        <h1>Company Name</h1>
        <nav>
            <ul>
                <li><a href="#home">Home</a></li>
                <li><a href="#about">About</a></li>
                <li><a href="#services">Services</a></li>
                <li><a href="#contact">Contact</a></li>
            </ul>
        </nav>
    </header>

    <main>
        <section>
            <h2>About Us</h2>
            <p>Information about the company.</p>
        </section>

        <section>
            <h2>Our Services</h2>
            <ul>
                <li>Service 1</li>
                <li>Service 2</li>
                <li>Service 3</li>
            </ul>
        </section>
    </main>

    <aside>
        <h2>Latest News</h2>
        <p>Stay updated with our latest news and announcements.</p>
    </aside>

    <footer>
        <p>&copy; 2024 Company Name. All rights reserved.</p>
    </footer>
</body>
</html>
```


Create an account in Codepen and share a link to enter our contest for the best webpage using these tags!