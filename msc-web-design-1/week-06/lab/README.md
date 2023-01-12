# Session 6: Navigation


# Lab

# Using HTML and CSS to build a menu system




## Introduction

In this lab we will 'handcode' the HTML code needed to build firstly a 'nav bar' primary navigation and then a right sidebar secondary navigation, and then style it with an external style sheet.


## Getting started - placing the menus in the page

You will need a basic page to whichyou an add your menus.  Use something you have worked on already, or this code:  (note the semantic, HTML5 tags)

```html

<!DOCTYPE html>

<head>

    <title>My page title</title>

</head>

<body>
    <!-- Here is our main header that is used across all the pages of our website -->

    <header>
        <h1>My page title</h1>
    </header>

    <nav class="primary">
        <!-- Your top navigation goes here -->
     

    </nav>
      <!-- start a container div for layout --> 
    <div class="container">
    <nav class="sidebar">
            <h3 class="menu-header">Sidebar menu</h3>
            <!--secondary navigation here-->
        </nav>

    <!-- Here is our page's main content -->
    <main>
        <!-- It contains an article -->
        <article>
            <h2>Article heading</h2>

            <p>
                Lorem ipsum dolor sit amet, consectetur adipisicing elit. Donec a diam
                lectus. Set sit amet ipsum mauris. Maecenas congue ligula as quam
                viverra nec consectetur ant hendrerit. Donec et mollis dolor. Praesent
                et diam eget libero egestas mattis sit amet vitae augue. Nam tincidunt
                congue enim, ut porta lorem lacinia consectetur.
            </p>

            <h3>Subsection</h3>

            <p>
                Pelientesque auctor nisi id magna consequat sagittis. Curabitur
                dapibus, enim sit amet elit pharetra tincidunt feugiat nist imperdiet.
                Ut convallis libero in urna ultrices accumsan. Donec sed odio eros.
            </p>

            <h3>Another subsection</h3>

            <p>
                Vivamus fermentum semper porta. Nunc diam velit, adipscing ut
                tristique vitae sagittis vel odio. Maecenas convallis ullamcorper
                ultricied. Curabitur ornare, ligula semper consectetur sagittis, nisi
                diam iaculis velit, is fringille sem nunc vet mi.
            </p>
        </article>
        

        <!-- the aside content can also be nested within the main content -->
        
  </main>
  </div>  

    <!-- And here is our main footer that is used across all the pages of our website -->

    <footer>
        <h3>Footer</h3>
        <p>©Copyright 2050 by nobody. All rights reversed.</p>
        <!-- Additional footer links here -->
    </footer>
</body>

</html>


```

## Adding menu links


To add links to your menu, most often the 'unordered list' markup is used.  Don't worry if this doesn't look much like a menu at first - it will just look like an ordinary list of links.  We will style it later.

Add links to your primary nav, secondary nav and footer.  Here is an example.  in this example, the ```#``` character will render a link but with no destination.  If you already have several pages, add in the relevant links.

```html

        <ul>
            <li><a href="#">Home</a></li>
            <li><a href="#">Our team</a></li>
            <li><a href="#">Projects</a></li>
            <li><a href="#">Contact</a></li>
        </ul>
```

## Layout

Add a link to an external stylesheet in the head section by adding the following

```html
<link rel="stylesheet" href="style.css">
```

Add the following basic layout code to your styles. This will implement a very basic grid layout and set some colours for parts of your page which will be ugly but will help you ensure that your styles are targetting the correct elements of your page.

```
h1 {
    color: red;
}

h2 {
    color: green;
}

h3 {
    color: teal;
}

.container {
    display: grid;
    grid-template-columns: 1fr 3fr;
    gap: 10px;
  }

  nav.sidebar {
    grid-column: 1/2;
  }

  main {
    grid-column: 2;
  }


```

Please use your CSS knowlege to improve the look of this page!!!


## Styling the menus

Add the following to your stylesheet to remove the bullets, and inline the top menu

```html
 /* remove the list bullets */
  ul {
    list-style-type: none;
    margin: 0;
    padding: 0;
  }

   /* inline the top menu only  */
  .primary li {
    display: inline;
  }
 ```
 

### Improving the look!

Add the following to your stylesheet.  Once you have this working, amend the styles to your satisfaction!!

```css
 ul {
    overflow: hidden;
    background-color: #333;
  }


  li a {
    display: block;
    color: white;
    text-align: center;
    padding: 14px 16px;
    text-decoration: none;

  }
  
  /* Change the link color to #111 (black) on hover */
  li a:hover {
    background-color: #111;
  }

  .primary li a {
    float:left;
  }


```


### Setting an 'active' style

Add an 'active' style for the home page, ie. indicate to your user what page they are on. 

1. Make the following amendment to your top menu
 
 ```html
  <nav class="primary">
        <ul>
            <li><a class="active" href="#">Home</a></li>
            <li><a href="#">Our team</a></li>
            <li><a href="#">Projects</a></li>
            <li><a href="#">Contact</a></li>
        </ul>
        <!-- Your top navigation goes here -->
    </nav>
 
 ```
 
 2. Add a corresponding style
 
 ```html
  /* active menu styling */
  .active {
    background-color: #04AA6D;
    color: white;
  }
  
  ```
  
  
## Additional tasks

1. Improve the overall look and feel of your page
2. Add some additional pages and link them. Remember to set the active style accordingly.  Remember to use the external stylesheet for every page.


References:

https://www.w3schools.com/css/css_navbar_horizontal.asp
https://www.w3schools.com/css/css_navbar.asp