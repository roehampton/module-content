``` Python
#Adapted from https://www.programiz.com/dsa/binary-search-tree
# Binary Search Tree operations in Python


# Create a node
class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None


# Inorder traversal
def inorder(root):
    if root is not None:
        # Traverse left
        inorder(root.left)

        # Traverse root
        print(str(root.key) + "->", end=' ')

        # Traverse right
        inorder(root.right)


# Insert a node
def insert(node, key):

    # Return a new node if the tree is empty
    if node is None:
        return Node key)

    # Traverse to the right place and insert the node
    if key < node.key:
        node.left = insert(node.left, key)
    else:
        node.right = insert(node.right, key)

    return node

from random import randrange
n = 20 #number of elements
root = None
for i in range(0,n)
    print(randrange(50),end=' ');
    root = insert(root, randrange(50))


print("\nInorder traversal: ", end=' ')
inorder(root)
```

