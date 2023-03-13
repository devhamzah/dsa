#include <stdio.h>
#include <stdlib.h>

struct node
{
 int data;
 struct node *left, *right;
};
// Creating Node Function
struct node *newNode(int data)
{
 struct node *temp = malloc(sizeof(struct node));
 if (temp != NULL)
 {
  temp->left = NULL;
  temp->right = NULL;
  temp->data = data;
 }
 return temp;
}
// Inserting Node
struct node *insert(struct node *node, int data)
{
 if (node == NULL)
  return newNode(data);
 // Traverse to right place and insert Node
 if (data < node->data)
 {
  node->left = insert(node->left, data);
 }
 else
 {
  node->right = insert(node->right, data);
 }
 return node;
}
// Pre Order Traversal
void preorder(struct node *root)
{
 if(root == NULL) return;
 printf(" %d -->",root->data);
 preorder(root->left);
 preorder(root->right);
}
// Inorder Traversal 
void inorder(struct node *root)
{
 if(root != NULL)
 {
  // Traverse Left
  inorder(root->left);
  // Print
  printf(" %d -->",root->data);
  // Traverse Right 
  inorder(root->right);
 }
}
// Post-Order Traversal
void postorder(struct node *root)
{
 if(root != NULL)
 {
  postorder(root->left);
  postorder(root->right);
  printf(" %d -->",root->data);
 }
}
// Reverse In-order Traversal
void reverseorder(struct node *root)
{
 if(root != NULL)
 {
  reverseorder(root->right);
  printf(" %d ",root->data);
  reverseorder(root->left);
 }
}
// Find the in order sucessor 
struct node *minNode(struct node *root)
{
 struct node *current = root;
 while (current && current->left != NULL)
 {
  current = current->left;
 }
 return current;
}
// Delete Node 
struct node *deleteNode(struct node *root,int data)
{
 // Return if the tree is empty!
 if(root == NULL) return root;
 // Find the node to be deleted Move recursively 
 if(data < root->data)
 {
  root->left = deleteNode(root->left,data);
 } else if (data > root->data)
 {
  root->right = deleteNode(root->right,data);
 }
 else
 {
  // If node is whith only one child or no child
  if(root->left == NULL)
  {
   struct node *temp = root->right;
   free(root);
   return temp;
  }else if (root->right == NULL)
  {
   struct node *temp = root->right;
   free(root);
   return temp;
  }
  // If the node has two children
  struct node *temp = minNode(root->right);
  // Place the inorder sucessor in the postion 
  // of the node to be deleted 
  root->data = temp->data;
  // Delete the inorder sucessor 
  root->right = deleteNode(root->right,temp->data);
 }
 return root;
}

int main()
{
 struct node *root = NULL;
 root = insert(root,50);
 root = insert(root,17);
 root = insert(root,9);
 root = insert(root,23);
 root = insert(root,19);
 root = insert(root,14);
 root = insert(root,12);
 root = insert(root,76);
 root = insert(root,54);
 root = insert(root,72);
 root = insert(root,67);


 printf(" Inorder Taraversal:  \n");
 inorder(root);
 printf("\n");
 printf(" Pre Order Traversal: \n");
 preorder(root);
 printf("\n");
 printf(" Post Order Traversal: \n");
 postorder(root);
 printf("\n");
 printf(" Reverse Order: \n");
 reverseorder(root);
 // printf(" Delete Node 6 \n");
 // deleteNode(root,6);
 // printf(" After Deletion \n");
 // inorder(root);

 return 0;
}