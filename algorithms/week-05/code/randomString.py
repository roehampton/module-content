import random

# Random string of length 5
for j in range(1,11):
    result_str = ''.join((random.choice('abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ') for i in range(9)))
    print(result_str)
