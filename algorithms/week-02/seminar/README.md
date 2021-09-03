# Seminar Week 2
# ADT List - Implementation

<p>In this second seminar we will review how to implement the ADT List and review some clasic algorithms involving lists.<br>
From our session, we know that <b>Lists</b> are the most common and basic non-primitive data structures.<br>
In SD 1&2, you already know a lot about how to implent lists in C (called Arrays) and Phyton. For example, in C, you create a static array of characters like this:</p>

``` C
char s[] = "Algorithms 101";
char s[50] = "Algorithms 101";
char s[] = {'A', 'l', 'g', 'o','r', 'i', 't', 'h','m','s', ' ', '1', '0', '1','\0'};
char s[15] = {'a', 'l', 'g', 'o','r', 'i', 't', 'h','m','s', ' ', '1', '0', '1', '\0'};
```

While in Python
``` Python
s='Algorithms 101'
```
We can characterised the above codes as the implementation for the <b>CREATOR</b> function in the ADT List. <br>

Some things to remember:
- Each element of a list has an index number, and these elements can be accessed or retrieved using their index number.
- In C and Python, lists (arrays) indexes start with 0.

``` C
printf("%c", s[0]);  //printf("%c", *name);  
```

``` Phython
print(s[0])
```

Both codes print **A**  <br>

### Producers - create new objects from old objects of the type.
For example, functions like concat() and substring() produce a new list

``` C
 //Use strcat to concat two strings
 char str1[100] = "Algorithms ", str2[] = "101";
 strcat(str1, str2);   // concatenates str1 and str2
 puts(str1);
```

``` Python
str1 = "Algorithms "
str2 = "101"
print(a + b)
```
### Observers - take objects of the abstract type and return objects of a different type.
For example, the functions size() and get() returns non-list objects

``` C
//Get the size (number of positions) of an array in ANSI C
#define SIZEA(x)  (sizeof(x) / sizeof((x)[0]))
size_t n1 = SIZEA(str1);
printf("sizeof of: %d\n", (int) n1);

//get an element from an array
printf("%d",str1[0]);  //Why is 65 and not A?
```

``` Python
str1 = "Algorithms"
print(len(str1))
```
### Mutators - change objects.
For example, the functions add(), remove() and sort() mutate a list.
``` C
  char str1[11] = "Algorithms";
  str1[strlen(str1)-1] = '\0'; // removing the last character i
  printf("%s\n",str1);

```

``` Python
str1 = "Algorithms"
print(print(str1.replace('s', '')))
```


## Task 1. Write an algorithm to find the Max and Min values in a numerical array.

## Task 2. Write an algorithm to sort elements of a numerical list.

## Task 3. Write an algorithm to create a new list from a given list of integers shifting all zeros to the left direction. 
