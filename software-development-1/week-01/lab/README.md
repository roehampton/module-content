# Software Development 1 
# Lab 1 -- Programming Flags
1. Start the **Anaconda Navigator** application. 
2. Create a **Jupyter notebook** file with Python 3 kernal (ipykernel).
3. Install graphic library through pip
> In this drawing flag task, we will use **graphics.py** library, which is a simple object oriented graphics library designed to make it very easy for novice programmers to experiment with computer graphics in an object oriented fashion. To install graphics.py library, we use package manager **pip**. 


```
!pip install graphics.py
```

4. After the library is installed, import (almost) everything from graphics.py, which allows using the various objects (variables, classes, methods...) from graphics.py without prefixing them with the module's name.
 ```
 from graphics import *
 ```
 
5. In graphics.py, the graphics are drawn in a window. **GraphWin()** can construct a new graphics window for drawing on the screen. The parameters are optional; the default title is “Graphics Window,” and the default size is 200 x 200 pixels.

```
win = GraphWin()
```

6. We can set colour of the background by **setBackground()**.

```
win.setBackground('white')
```

8. We can close the window by **win.close()**

```
win.close()
```

So far, we are able to create a window, set background colour, and close the window. Next, let's explore more.

9. Create a window with given name, width and height.
> As mentioned in step 5, **GraphWin()** can have optional parameters, **GraphWin(title, width, height)**

```
win = GraphWin('name', 600, 400)
```

10. Create a rectangle.
> Windows have coordinates. (0, 0) is the top-left corner. (*w*, *h*) is the bottom-right corner, where *w* is the window width and *h* the height.
> A Rectangle has a start point and end point.

```
rect = Rectangle(Point(0, 0), Point(100, 200))
```

11. Set the colour fill to the rectangle.

```
rect.setFill('blue')
```

12. Draw the rectangle (**rect**) to the window (**win**)

```
rect.draw(win)
```

So far we have learnt how to create rectangle with specific colour. Think about the French flag (as below). How can we  draw it by python?
![alt text][logo]

The French flag consists of three rectangles with 




