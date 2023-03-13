#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
// User defined
#define NUM_CHAR 256
// Node for Trie
typedef struct node
{
 bool terminal;
 struct node *childern[NUM_CHAR];
} node;
// Initializing New Node
node *createNode()
{
 node *newNode = malloc(sizeof(struct node));
 for (int i = 0; i < NUM_CHAR; i++)
 {
  newNode->childern[i] = NULL;
 }
 newNode->terminal = false;
 return newNode;
}
// Inserting Node in Tries
bool insertNode(node **root, char *signedtext)
{
 if (*root == NULL)
 {
  *root = createNode();
 }
 unsigned char *text = (unsigned char *)signedtext;
 node *temp = *root;
 int length = strlen(signedtext);

 for (int i = 0; i < length; i++)
 {
  if (temp->childern[text[i]] == NULL)
  {
   // crate a new node
   temp->childern[text[i]] = createNode();
  }
  temp = temp->childern[text[i]];
 }

 if (temp->terminal)
 {
  return false;
 }
 else
 {
  printf(" Already! \n");
  temp->terminal = true;
  return true;
 }
}
//>>>>>>>>>>>>>>>>>>>>>>>>
void printTrieRec(node *node, unsigned char *prefix, int lenght)
{
 unsigned char newprefix[lenght + 2];
 memcpy(newprefix, prefix, lenght);
 newprefix[lenght + 1] = 0;
 if (node->terminal)
 {
  printf(" Word: %s \n", prefix);
 }
 for (int i = 0; i < NUM_CHAR; i++)
 {
  if (node->childern[i] != NULL)
  {
   newprefix[lenght] = i;
   printTrieRec(node->childern[i], newprefix, lenght + 1);
  }
 }
}
//>>>>>>>>>>>>>>>>>>>>>>>>
void printTrie(node *root)
{
 if (root == NULL)
 {
  printf(" Trie is empty \n");
  return;
 }
 printTrieRec(root,NULL,0);
}

int main()
{

 node *root = NULL;
 insertNode(&root,"ZEE");
 insertNode(&root,"MANGO");
 insertNode(&root,"LION");
 insertNode(&root,"AMERICA");
 printTrie(root);


 return 0;
}
