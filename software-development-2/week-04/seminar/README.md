# Software Development 2 Seminar 04 -- Case Study

In this seminar we will use the techniques from the previous weeks. We will also combine your C coding skills with your flowcharting skills.

## Specification

Consider the following specification:

> Your program will attempt to calculate the distance traveled when making a journey. It will first allow the user to enter details of the journey, it will then calculate the journey length and then print out a report. Initially the program should accept a journey description (a string) and then a series of latitudes and longitudes (e.g. `-0.02137955608`, `51.46639893622`). Note that the user will normally be asked to enter the latitude and longitude separately. When the user has entered all of the latitudes and longitudes they should enter 0 to indicate that they have finished.
>
> Finally your program should print out the journey description and total distance traveled .

### Sample Data

Here are some sample latitudes and longitudes:

```
-0.04247292248, 51.48487326661
-0.04374790707, 51.48537115578
-0.04641003533, 51.48644070181
-0.04837121115, 51.48739960288
-0.04930547842, 51.4877838475
-0.05144180331, 51.48869165398
-0.05209244877, 51.48897224352
```

## Calculating the Distance Between Two Points

We need to be able to calculate the distance between two latitude and longitude points. There already exists a solution to this, called the [Haversine formula](http://rosettacode.org/wiki/Haversine_formula#C). Web implementing existing mathematical functions we will find that someone has already done it for us. We just use the `dist` function from the following code:

```c
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
#define R 6371
#define TO_RAD (3.1415926536 / 180)

double dist(double th1, double ph1, double th2, double ph2)
{
	double dx, dy, dz;
	ph1 -= ph2;
	ph1 *= TO_RAD, th1 *= TO_RAD, th2 *= TO_RAD;
 
	dz = sin(th1) - sin(th2);
	dx = cos(ph1) * cos(th1) - cos(th2);
	dy = sin(ph1) * cos(th1);
	return asin(sqrt(dx * dx + dy * dy + dz * dz) / 2) * 2 * R;
}
 
int main()
{
	double d = dist(36.12, -86.67, 33.94, -118.4);
	/* Americans don't know kilometers */
	printf("dist: %.1f km (%.1f mi.)\n", d, d / 1.609344);
	return 0;
}
```

When using someone else's code always take time to test the code rst of all. **Never assume that code that you have legitimately obtained from the Internet is correct!**

## Tasks

Using the skills gained earlier approach this development task as follows:

1. Produce a high-level flowchart for your program.
2. Using functional decomposition, split any large processes into subprocesses with their own chart.
3. Produce a pseudocode listing.
4. Translate your pseudocode into C and compile.
5. Test your program.

## Reflection

In groups of 4-5 discuss any difficulties that you had with the development task. Compare your designs, code and results.

- Do your designs match? If they are different, explain the differences.
- Does your code match? Can you understand each other's code?
- Do your results match? If not, why not?