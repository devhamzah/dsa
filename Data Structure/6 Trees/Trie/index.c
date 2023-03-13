#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define N 26
// Define Trie Node Structure
typedef struct trieNode
{
 struct trieNode *childrens[N];
 bool terminal;
} trieNode;
// <<<<<<<<<<<<<<<<<<<< Functions >>>>>>>>>>>>>>>>>>>>>>>>>>>
trieNode *createNode()
{
 // Creating New Trie Node and Allocating Memory
 trieNode *newNode = malloc(sizeof(struct trieNode));
 // Setting all childerns to NULL
 for (int i = 0; i < N; i++)
 {
  newNode->childrens[i] = NULL;
 }
 // Setting terminal value to false --> 0
 newNode->terminal = false;
 return newNode;
}

void freeNode(trieNode *node)
{
 for (int i = 0; i < N; i++)
 {
  if (node->childrens[i] != NULL)
  {
   freeNode(node->childrens[i]);
  }
  else
  {
   continue;
  }
 }
 free(node);
}

bool isLeafNode(trieNode *root, char *word)
{
 trieNode *temp = root;
 for (int i = 0; i < word[i] != '\0'; i++)
 {
  int position = (int)word[i] - 'a';
  if (temp->childrens[position])
  {
   temp = temp->childrens[position];
  }
 }
 return temp->terminal;
}

char *findLognestPrefix(trieNode *root, char *word)
{
 int len = strlen(word);
 char *longestPrefix = (char *)calloc(len + 1, sizeof(char));
 for (int i = 0; i < word[i] != '\0'; i++)
 {
  longestPrefix[i] = word[i];
 }
 longestPrefix[len] = '\0';

 
}

bool insertNode(trieNode **root, char *word)
{
 if (*root == NULL)
 {
  *root = createNode();
 }
 // unsigned char *text = (unsigned char *)word;
 trieNode *temp = *root;

 for (int i = 0; word[i] != '\0'; i++)
 {
  int index = word[i] - 'a';
  // printf("%d  ",index);
  if (temp->childrens[index] == NULL)
  {
   // creating new node with letter
   temp->childrens[index] = createNode();
  }
  temp = temp->childrens[index];
 }
 if (temp->terminal)
 {
  printf(" %s is already exist in Trie! \n", word);
  return false;
 }
 else
 {
  printf(" %s is inserted successfully.\n", word);
  temp->terminal = true;
  return true;
 }
}

int search(trieNode *root, char *word)
{
 trieNode *temp = root;
 for (int i = 0; word[i] != '\0'; i++)
 {
  int position = word[i] - 'a';
  if (temp->childrens[position] == NULL)
  {
   printf(" %s not present in Trie! \n", word);
   return 0;
  }
  temp = temp->childrens[position];
 }
 if (temp->terminal)
 {
  printf(" %s found in Trie!\n", word);
 }
}

void printTrie(trieNode *node, char *prefix, int length)
{
 if (!node)
  return;
 unsigned char newprefix[length];
 memcpy(newprefix, prefix, length);
 newprefix[length + 1] = '\0';
 if (node->terminal)
 {
  printf(" %s \n", prefix);
 }
 for (int i = 0; i < N; i++)
 {
  if (node->childrens[i] != NULL)
  {
   newprefix[length] = i + 'a';
   printTrie(node->childrens[i], newprefix, length + 1);
  }
 }
};

bool deletePrefix(trieNode **root, char *word)
{
 trieNode *temp = *root;
 for (int i = 0; word[i] != '\0'; i++)
 {
  int position = word[i] - 'a';
  if (temp->childrens[position] == NULL)
  {
   printf(" %s not present in Trie for deletion! \n", word);
   return false;
  }
  temp = temp->childrens[position];
 }
 if (temp->terminal)
 {
  temp->terminal = false;
  // printf(" %s deleted!\n", word);
  return true;
 }
 else
 {
  printf(" %s not present in Trie for deletion! \n", word);
  return false;
 }
}

//****************************************************************
int main()
{

 trieNode *root = NULL;
 printf("<<<<<<< Insert Prefixes :>>>>\n");
 insertNode(&root, "hamza");
 insertNode(&root, "sayam");
 insertNode(&root, "atif");
 insertNode(&root, "ali");
 insertNode(&root, "aammiirr");
 printf("<<<<<<< Searching for Prefixes :>>>>\n");
 search(root, "sayams");
 search(root, "hamza");
 printf("<<<<<<<<<< Printing Trie before deleting :>>>>\n");
 printTrie(root, NULL, 0);
 deletePrefix(&root, "atif");
 deletePrefix(&root, "sayam");
 printf("<<<<<<<<<<< Printing Trie After deleting Some Prefixes :>>>>\n");
 printTrie(root, NULL, 0);
 return 0;
}
