#include <stdio.h>
#include <stdlib.h>
// Functions Singnatures
void push();
void pop();
void peak();
void print();
// Structure of Node
struct node
{
 int data;
 struct node *next;
};
struct node *head = NULL;
int size, choice;
// Main Function
int main()
{
 while (1)
 {
  printf("       STACK WITH SINGLY-LINKED LIST        \n");
  printf("     **********************************     \n");
  printf("       1.For Push 2.For Pop 3.For Peak      \n");
  printf("\n");

  printf(" Enter your choice:  ");
  scanf("%d", &choice);

  switch (choice)
  {
  case 1:
   push();
   break;
  case 2:
   pop();
   break;
  case 3:
   peak();
   break;
  case 4:
   print();
   break;
  default:
   printf(" Invalid Choice! \n");
  }
 }
 return 0;
}
// Pushing Item in Stack
void push()
{
 struct node *newNode;
 newNode = (struct node *)malloc(sizeof(struct node));
 printf(" Enter the vlue for node: ");
 scanf("%d", &newNode->data);
 newNode->next = NULL;
 if (head == NULL)
 {
  head = newNode;
  size++;
 }
 else
 {
  newNode->next = head;
  head = newNode;
  size++;
 }
}
// Popping Item from Stack
void pop()
{
 if (head == NULL)
 {
  printf(" List is empty! \n");
  return;
 }
 else if (head->next == NULL)
 {
  printf(" %d popped from list! \n",head->data);
  free(head);
  head = NULL;
 }
 else
 {
  struct node *temp;
  temp = head;
  head = head->next;
  printf(" %d poped from list! \n",temp->data);
  free(temp);
  temp = NULL;
  size--;
 }
}
// Print Data (Not Recomanded in Stack)
void print()
{
 if (head == NULL)
 {
  printf(" List is empty!\n");
 }
 else
 {
  struct node *current;
  current = head;
  while (current != NULL)
  {
   printf(" %d ", current->data);
   current = current->next;
  }
  printf(" \n");
 }
}
// Get the peak element of Stack
void peak()
{
 if (head == NULL)
 {
  printf(" List is empty! \n");
  return;
 }
 else
 {
  printf(" %d is top element! \n", head->data);
  return;
 }
}