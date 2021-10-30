# Software Development 1 
# Seminar 6 

1. A for loop executes once for each item in a collection. The collection can be a range of integers constructed by calling the range function. It can also be a list. The following example uses a for loop to total the values in data.


```
# Initialize data and total
data = [2.71, 3.14, 1.41, 1.62] 
total = 0

# Total the values in data
for value in data: 
    total = total + value
    # Display the total
    print("The total is", total)
 ```  
   
Explain in your own words how this loop works   
        
2. We have seen that the *len* function can be used with the *range* function to make a collection of integers that includes all of the indices for a list. This is accomplished by passing the length of the list as the only argument to range. A subset of the indices can be constructed by providing a second argument to range. Make a program that demonstrates this by using a for loop to iterate through all of data’s indices, except the first, to identify the position of the largest element in data.

3. While loops can also be used when working with lists. Usea while loop to identify the index of the first positive value in the list:

   
       data = [0, -1, 4, 1, 0]


4. Sometimes a list has all of the correct elements in it, but they aren’t in the order needed to solve a particular problem. Two elements in a list can be swapped using a series of assignment statements that read from and write to individual elements in the list, as shown in the following code segment.


```
# Create a list
data = [2.71, 3.14, 1.41, 1.62]

# Swap the element at index 1 with the element at index 3
temp = data[1] 
data[1] = data[3] 
data[3] = temp

# Display the modified list
print(data)
```

      
Explore the methods **.reverse()** and **.sort()** on *data*. What do these do?

5. Write a program that reads integers from the user and stores them in a list. Your program should continue reading values until the user enters 0. Then it should display all of the values entered by the user (except for the 0) in ascending order, with one value appearing on each line. Use either the sort method or the sorted function
to sort the list.


6. Create a program that reads words from the user until the user enters a blank line. After the user enters a blank line your program should display each word entered by the user. Then remove all the duplicate words. The words should now be displayed in
the same order that they were first entered. For example, if the user enters:

```
first
second
first
third
second
```

then your program should display:

```
first
second
third
```

