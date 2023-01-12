# Software Development 1
## Lab 6: List, tuple, set and dictionary

## Lists
```
mylist = []
```
- Adding Element into list
```
mylist.append(5)
mylist.append(10)
print("Adding 5 and 10 in list", mylist)
```

- Popping Elements from list
```
mylist.pop()
print("Popped one element from list", mylist)
print()
```

## Set
```
s = set()
```

- Adding element into set
```
s.add(5)
s.add(10)
print("Adding 5 and 10 in set", s)
```

- Removing element from set
```
s.remove(5)
print("Removing 5 from set", s)
```

## Tuple
```
t = tuple(mylist)
```

- Tuples are immutable
```
print("Tuple", t)
print()
```

## Dictionary
```
d = {}
```

- Adding the key value pair
```
d[5] = "Five"
d[10] = "Ten"
print("Dictionary", d)
```
- Removing key-value pair
```
del d[10]
print("Dictionary", d)
```

## Exercises

1. Sorted Order: Write a program that reads integers from the user and stores them in a list. Your program should continue reading values until the user enters 0. Then it should display all of the values entered by the user (except for the 0) in ascending order, with one value appearing on each line. Use either the sort method or the sorted function
to sort the list.


2. Reverse Order. Write a program that reads integers from the user and stores them in a list. Use 0 as a sentinel value to mark the end of the input. Once all of the values have been read your program should display them (except for the 0) in reverse order, with one value
appearing on each line.

3. Remove Outliers: When analysing data collected as part of a science experiment it may be desirable to remove the most extreme values before performing other calculations. Write a function that takes a list of values and an non-negative integer, n, as its parameters. The function should create a new copy of the list with the n largest elements and the n smallest elements removed. Then it should return the new copy of the list as the function’s only result. The order of the elements in the returned list does not have to match the order of the elements in the original list.
Write a main program that demonstrates your function. It should read a list of numbers from the user and remove the two largest and two smallest values from it by calling the function described previously. Display the list with the outliers removed, followed by the original list. Your program should generate an appropriate error message if the user enters less than 4 values.

