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
