#include <stdio.h>
#include <stdlib.h>
// Define singnatures of functions here:
void create();
void print();
void prepend();
void append();
void insertAt();
void shift();
void pop();
void removeAt();
void search();
void reverse();
void bubbleSort();

// Define structure of Node:
struct node
{
 int data;
 struct node *next;
};
struct node *head = NULL;
// Main Function --->
int main()
{
 int choice;
 while (1)
 {
  printf("       mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm\n");
  printf("       |                            ( Singly-Linked List )                        |\n");
  printf("       |   1.Create Linked List        4.Append Node          7.Remove from End   |\n");
  printf("       |   2.Print Data                5.Insert at Index      8.Remove by Index   |\n");
  printf("       |   3.Prepend Node              6.Remove from Start    9.Search            |\n");
  printf("       |                                0.For Exit!                               |\n");
  printf("       |                           101.Reverse List Data                          |\n");
  printf("       |__________________________________________________________________________|\n");
  printf("\n");
  // Getting Choice
  printf(" Enter you Choice: ");
  scanf("%d", &choice);
  // Checking Choice
  switch (choice)
  {
  case 1:
   create();
   break;
  case 2:
   print();
   break;
  case 3:
   prepend();
   break;
  case 4:
   append();
   break;
  case 5:
   insertAt();
   break;
  case 6:
   shift();
   break;
  case 7:
   pop();
   break;
  case 8:
   removeAt();
   break;
  case 9:
   search();
   break;
  case 101:
   reverse(); // I will change it after
   break;
  case 0:
   exit(0);
   break;
  default:
   printf(" Invalid Selection! \n");
   break;
  }
 }
}
// Create Linked List ---->
void create()
{
 if (head != NULL)
 {
  printf(" Warning: Linked List is already decleard :) \n");
  return;
 }
 struct node *temp, *ptr;
 temp = (struct node *)malloc(sizeof(struct node));
 if (temp == NULL)
 {
  printf(" Out of Memory! ");
  exit(0);
 }
 printf(" Enter the value for first Node: ");
 temp->next = NULL;
 scanf("%d", &temp->data);
 head = temp;
}
// Print Data --->
void print()
{
 if (head == NULL)
 {
  printf(" List is Empty or you didn't create Yet:  \n");
  return;
 }
 struct node *ptr;
 ptr = head;
 while (ptr != NULL)
 {
  printf(" %d --> ", ptr->data);
  ptr = ptr->next;
 }
 printf("NULL\n");
}
// Prepend Node ---> Add node at head
void prepend()
{
 struct node *temp;
 temp = (struct node *)malloc(sizeof(struct node));
 if (temp == NULL)
 {
  printf(" Out of Memory! ");
  exit(0);
 }
 temp->next = NULL;
 printf(" Enter value for Node: ");
 scanf("%d", &temp->data);
 if (head == NULL)
 {
  head = temp;
 }
 else
 {
  temp->next = head;
  head = temp;
 }
}
// Append Node ---> Add node at tail
void append()
{
 struct node *temp, *ptr;
 temp = (struct node *)malloc(sizeof(struct node));
 if (temp == NULL)
 {
  printf(" Out of Memory! ");
  exit(0);
 }
 printf(" Enter data for Node: ");
 scanf("%d", &temp->data);
 temp->next = NULL;
 if (head == NULL)
 {
  head = temp;
 }
 else
 {
  ptr = head;
  while (ptr->next != NULL)
  {
   ptr = ptr->next;
  }
  ptr->next = temp;
 }
}
// Insert Node at Specific Index
void insertAt()
{
 int index, i;
 struct node *temp, *ptr;
 printf(" Enter Index Number: ");
 scanf("%d", &index);
 if (index == 1)
 {
  temp = (struct node *)malloc(sizeof(struct node));
  printf(" Enter the value for the given Index: ");
  scanf("%d", &temp->data);
  temp->next = head;
  head = temp;
  return;
 }
 ptr = head;
 for (i = 0; i < index - 2; i++)
 {
  ptr = ptr->next;
  if (ptr == NULL)
  {
   printf(" Invalid Index! \n");
   return;
  }
 }
 temp = (struct node *)malloc(sizeof(struct node));
 if (temp == NULL)
 {
  printf(" Out of Memoery!");
  exit(0);
 }
 printf(" Enter the value for given Index: ");
 scanf("%d", &temp->data);
 temp->next = ptr->next;
 ptr->next = temp;
}
// Shifting Node ---> Remove from head
void shift()
{
 head = head->next;
 printf(" Node removed from head succesfully. \n");
}
// Poping Node ---> Remove from tail
void pop()
{
 if (head == NULL)
 {
  printf(" List is Empty or you didn't create Yet! \n");
  return;
 }
 struct node *ptr;
 if (head->next == NULL)
 {
  head = NULL;
  printf(" Node removed form tail succesfully. \n");
  return;
 }
 ptr = head;
 while (ptr->next->next != NULL)
 {
  ptr = ptr->next;
 }
 ptr->next = NULL;
 printf(" Node removed form tail succesfully. \n");
}
// RemoveAt  ---> Remove from specific Index
void removeAt()
{
 int index, i;
 printf(" Enter Index Number: ");
 scanf("%d", &index);
 if (index <= 0)
 {
  printf(" Index value should not be 0 or Negative! \n");
  return;
 }
 if (head == NULL)
 {
  printf(" List is Empty or you didn't create Yet! \n");
  return;
 }
 if (index == 1 && head->next != NULL)
 {
  head = head->next;
  return;
 }
 if (index == 1 && head->next == NULL)
 {
  head = NULL;
  return;
 }
 struct node *ptr;
 ptr = head;
 for (i = 0; i < index - 2; i++)
 {
  ptr = ptr->next;
  if (ptr == NULL || ptr->next == NULL)
  {
   printf(" Invalid Index! \n");
   return;
  }
 }
 ptr->next = ptr->next->next;
}
// Search value --> Search for specific value
void search()
{
 int target;
 int index = 0;
 struct node *ptr;
 printf(" Enter the target value: ");
 scanf("%d", &target);
 ptr = head;
 while (ptr != NULL)
 {
  index++;
  if (ptr->data == target)
  {
   printf(" Your target value %d found at index %d \n", ptr->data, index);
   return;
  }
  ptr = ptr->next;
 }
 printf(" List not contained %d \n", target);
 return;
}
// Reverse List <---- NULL
void reverse()
{
 int ans;
 printf(" Arey you sure to reverse List data!\n Enter 1 for Yes and 0 for No: ");
 scanf("%d",&ans);
 if(ans == 1)
 {
   struct node *current, *previous, *next;
 previous = NULL;
 current = head;
 while (current != NULL)
 {
  next = current->next;
  current->next = previous;
  previous = current;
  current = next;
 }
 head = previous;
 printf(" List reversed sucessfully! \n");
 }
 else
 {
  printf(" You cancelled reversal operation! \n");
  return;
 }
}
// Bubble Sort ---> Sorting Linked List 
void bubbleSort()
{
  
}
