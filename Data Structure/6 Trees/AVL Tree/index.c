#include <stdio.h>
#include <stdlib.h>
// Structure of the tree Node
struct node
{
 int data;
 struct node *left, *right;
 int height;
};
// Global initialization of root Node
struct node *root = NULL;
// Function's signatures or Prototype
int height(struct node *);
int max(int a, int b);
struct node *create(int);
struct node *insert(struct node *, int data);
int getBalance(struct node *N);
struct node *rightRotate(struct node *N);
struct node *leftRotate(struct node *N);
struct node *minValue(struct node *root);
void print(struct node *root);
// Manin function
int main()
{
 return 0;
}
// Creating Node
struct node *create(int data)
{
 struct node *newNode = malloc(sizeof(struct node));
 if (newNode != NULL)
 {
  newNode->left = NULL;
  newNode->right = NULL;
  newNode->data = data;
  newNode->height = 1;
 }
}

// Insert Node
struct node *insert(struct node *root, int data)
{
 if (root == NULL)
 {
  return create(data);
 }
 if (data < root->data)
 {
  root->left = insert(root->left, data);
 }
 else if (data > root->data)
 {
  root->right = insert(root->right, data);
 }
 else
 {
  return root;
 }
 // Update the balance factor of each node
 // Balance the tree
 root->height = 1 + max(height(root->left), height(root->right));
 int balance = getBalance(root);

 if(balance > 1 && data < root->left->data)
   return rightRotate(root);
 if(balance < -1 && data > root->right->data)
   return leftRotate(root);
 if(balance > 1 && data > root->left->data ){
  root->left = leftRotate(root->left);
  return rightRotate(root);
 }
 if(balance < -1 && data < root->right->data)
 {
  root->right = rightRotate(root->right);
  return leftRotate(root);
 }
 return root;
}

// Calculate height
int height(struct node *N)
{
 if (N == NULL)
  return 0;
 return N->height;
}

// Checking difference in value return bigger
int max(int a, int b)
{
 return (a > b) ? a : b;
}

// Get Balance Factor
int getBalance(struct node *N)
{
 if (N == NULL)
  return 0;
 return height(N->left) - height(N->right);
}

// Function Right rotate Node
struct node *rightRotate(struct node *N)
{
 struct node *x = N->left;
 struct node *z = x->right;

 x->right = N;
 N->left = z;

 x->height = max(height(x->left), height(x->right)) + 1;
 z->height = max(height(z->left), height(z->right)) + 1;

 return x;
}

// Function Left rotate Node
struct node *leftRotate(struct node *N)
{
 struct node *x = N->right;
 struct node *z = x->left;

 x->left = N;
 N->right = z;

 x->height = max(height(x->left), height(x->right)) + 1;
 z->height = max(height(z->left), height(z->right)) + 1;

 return x;
}

// Smalles value in the tree
struct node *minValue(struct node *root)
{
 struct node *current = root;
 while (current->left != NULL)
 {
  current = current->left;
 }
 return current;
}

// Print the tree (In-Order)
void print(struct node *root)
{
 if (root == NULL)
  return;
 print(root->left);
 printf(" %d ", root->data);
 print(root->right);
}
