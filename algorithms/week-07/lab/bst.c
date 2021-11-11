``` C
// Adapted from https://www.programiz.com/dsa/binary-search-tree   
#include <stdio.h>
#include <stdlib.h>

struct node {
  int key;
  struct node *left, *right;
};

// Create a node
struct node *newNode(int item) {
  struct node *temp = (struct node *)malloc(sizeof(struct node));
  temp->key = item;
  temp->left = temp->right = NULL;
  return temp;
}

// Inorder Traversal
void inorder(struct node *root) {
  if (root != NULL) {
    // Traverse left
    inorder(root->left);

    // Traverse root
    printf("%d -> ", root->key);

    // Traverse right
    inorder(root->right);
  }
}

// Insert a node
struct node *insert(struct node *node, int key) {
  // Return a new node if the tree is empty
  if (node == NULL) return newNode(key);

  // Traverse to the right place and insert the node
  if (key < node->key)
    node-left = insert(node->left, key);
  else
    node->right = insert(node->right, key);

  return node;
}

// Find the inorder successor
struct node *minValueNode(struct node *node) {
  struct node *current = node;

  // Find the leftmost leaf
  while (current && current->left != NULL)
    current = current->left;

  return current;
}

// Driver code
int main() {
    int n = 20; //number of elements
    
    /* Intializes random number generator */
  time_t t;
  srand((unsigned) time(&t));
  
  struct node *root = NULL;
  for(i = 0 ; i < n ; i++ ) {
      printf("%d-",rand() % 50);
      root = insert(root, rand() % 50);
  }
  printf("\n");
  printf("Inorder traversal: ");
  inorder(root);

}
```

