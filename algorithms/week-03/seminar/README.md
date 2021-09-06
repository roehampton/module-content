# Linked-list, Stack and Queue execises

## 1. Code your algorithm to order a set of numbers stored in a linked-list
1. You can fix the size of the linked-list to n=10 for example
2. The values be random integer numbers between 0 and n+10
3. You can use an temporal list to insert the ordered values
 
## 2. Code your algorithm to reverse the words in a sentence (only letters and spaces)
1. You need to ask the user for the sentence to reverse.


## 3. Code your algorithm to convert a positive integer to its binary representation using a queue
1. To make your life easier, you can, for example, use the collections library from Python

``` Python
from collections import deque

q = deque()
q.append('a')
q.append('b')
q.append('c')
print("Initial queue")
print(q)
print("\nElements dequeued from the queue")
print(q.popleft())
print(q.popleft())
print(q.popleft())
print("\nQueue after removing elements")
print(q)
```


