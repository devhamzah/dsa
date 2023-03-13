#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode
{
 struct treeNode *right;
 int value;
 struct treeNode *left;
} treeNode;

treeNode *createNode(int value)
{
 treeNode *result = malloc(sizeof(treeNode));
 if (result != NULL)
 {
  result->right = NULL;
  result->value = value;
  result->left = NULL;
 }
 return result;
}

void printTree(treeNode *root)
{
 if (root != NULL)
 {
  // Doing Pre order traversal recursively 
  printf(" value = %d\n",root->value);
  printf(" left\n");
  printTree(root->left);
  printf(" right\n");
  printTree(root->right);
  printf(" Done!\n");
 }
 else
 {
  printf(" Tree is empty! \n");
 }
}

int main()
{
 treeNode *n1 = createNode(10);
 treeNode *n2 = createNode(11);
 treeNode *n3 = createNode(12);
 treeNode *n4 = createNode(13);
 treeNode *n5 = createNode(14);

 n1->left = n2;
 n1->right = n3;
 n3->left = n4;
 n3->right = n5;

 printTree(n1);

 return 0;
}
