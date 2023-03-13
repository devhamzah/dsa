#include <stdio.h>
#include <stdlib.h>
// Define singnatures of functions here:
void create();
void print();
void prepend();
void append();
void insert();
void shift();
void pop();
void removeAt();
void search();
void reverse();

// Define structure of Node:
struct node
{
  struct node *previous;
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
    printf("       |                            ( Dubly-Linked List )                         |\n");
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
      insert();
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
      reverse();
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
// Crate Dubly Linked List <--->
void create()
{
  struct node *newNode;
  newNode = (struct node *)malloc(sizeof(struct node));
  if (newNode == NULL)
  {
    printf(" Memory Overflow! \n");
    exit(0);
  }
  printf(" Enter the value for Node: ");
  scanf("%d", &newNode->data);
  if (head == NULL)
  {
    newNode->next = NULL;
    newNode->previous = NULL;
    head = newNode;
  }
  else
  {
    newNode->next = head;
    newNode->previous = NULL;
    head->previous = newNode;
    head = newNode;
  }
  return;
}
// Print List Data <--->
void print()
{
  if (head == NULL)
  {
    printf(" List is empty of you didn't create Yet! \n");
    return;
  }
  printf(" NULL <---> ");
  struct node *pointer;
  pointer = head;
  while (pointer != NULL)
  {
    printf("%d <---> ", pointer->data);
    pointer = pointer->next;
  }
  printf("NULL \n");
}
// Prepend Node <---> Put Node at Start
void prepend()
{
  struct node *newNode;
  newNode = (struct node *)malloc(sizeof(struct node));
  if (newNode == NULL)
  {
    printf(" Memory Overflow! \n");
    exit(0);
  }
  printf(" Enter the value for Node: ");
  scanf("%d", &newNode->data);
  if (head == NULL)
  {
    newNode->next = NULL;
    newNode->previous = NULL;
    head = newNode;
  }
  else
  {
    newNode->next = head;
    newNode->previous = NULL;
    head->previous = newNode;
    head = newNode;
  }
}
// Append Node <---> Put Node at the End of List
void append()
{
  struct node *current, *newNode;
  newNode = (struct node *)malloc(sizeof(struct node));
  if (newNode == NULL)
  {
    printf(" Memory Overflow! \n");
    exit(0);
  }
  printf(" Enter the value for Node: ");
  scanf("%d", &newNode->data);

  if (head == NULL)
  {
    newNode->next = NULL;
    newNode->previous = NULL;
    head = newNode;
  }
  else
  {
    current = head;
    while (current->next != NULL)
    {
      current = current->next;
    }
    current->next = newNode;
    newNode->previous = current;
    newNode->next = NULL;
  }
}
// Insert at Index <--->
void insert()
{
  int index, i;
  struct node *current;
  current = head;
  printf(" Enter Index: ");
  scanf("%d", &index);
  if (index <= 0)
  {
    printf(" Index could not be 0 or Negative! \n");
    return;
  }
  if (head == NULL)
  {
    printf(" Create List first! \n");
  }
  if (index == 1)
  {
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));
    printf(" Enter the value for Node: ");
    scanf("%d", &newNode->data);
    if (head == NULL)
    {
      newNode->next = NULL;
      newNode->previous = NULL;
      head = newNode;
    }
    else
    {
      newNode->next = head;
      head->previous = newNode;
      newNode->previous = NULL;
      head = newNode;
      return;
    }
  }
  for (i = 0; i < index - 2; i++)
  {
    current = current->next;
    if (current == NULL)
    {
      printf(" Invalid Index! \n");
      return;
    }
  }
  struct node *newNode;
  newNode = (struct node *)malloc(sizeof(struct node));
  if (newNode == NULL)
  {
    printf(" Memory Overflow! \n");
    exit(0);
  }
  printf(" Enter the value for give index: ");
  scanf("%d", &newNode->data);
  if (current->next == NULL)
  {
    current->next = newNode;
    newNode->previous = current;
    newNode->next = NULL;
  }
  else
  {
    newNode->next = current->next;
    current->next->previous = newNode;
    newNode->previous = current;
    current->next = newNode;
  }
};
// Shift Node <---> Remove from start
void shift()
{
  if (head == NULL)
  {
    printf(" List is empty or you didn't create Yet! \n");
    return;
  }
  if (head->next == NULL)
  {
    head = NULL;
    return;
  }
  head = head->next;
  head->previous = NULL;
}
// Pop Node <---> Remove from End
void pop()
{
  if(head == NULL)
  {
    printf(" List is empty of you didn't create Yet: \n");
    return;
  }
  struct node *current;
  current = head;
  if(current->next == NULL)
  {
    head = NULL;
    return;
  }
  while (current->next->next != NULL)
  {
    current = current-> next;
  }
  current->next = NULL; 
}
// Remove at <---> Remove from specific index
void removeAt()
{
int index,i;
printf(" Enter the Index Number: ");
scanf("%d",&index);
if(index <= 0)
{
  printf(" Index should not be 0 or negative! \n");
  return;
}
if(index == 1)
{
  shift();
  return;
}
struct node *current;
current = head;
for( i = 0; i < index -2; i++)
{
    current = current->next;
    if(current == NULL)
    {
      printf(" Invalid Index! \n");
      return;
    }
}
if(current->next == NULL){
  printf(" Invalid Index! \n");
  return;
}
if(current->next->next == NULL)
{
  pop();
  return;
}
current->next = current->next->next;
current->next->previous = current;
}
// Search Node <---> Search node value in list
void search()
{
int target,index;
index = 0;
printf(" Enter target value: ");
scanf("%d",&target);
struct node *current;
current = head;
while (current != NULL)
{
  index++;
  if(current->data == target)
  {
    printf(" Your value %d found at index %d . \n",target,index);
    return;
  }
  current= current->next;
}
  printf(" Value not found! \n");
}
// Reverse all Nodes <---> 
void reverse()
{
  int ans;
  if(head == NULL)
  {
    printf(" List is empty or you didn't create Yet! \n");
    return;
  }
  printf(" Are you sure to reverse list data :) Enter 0 for Cancele or any other's for Continue!. :  ");
  scanf("%d",&ans);

if(ans)
{
  struct node *previous,*current,*next;
  current = head;
  previous = NULL;
  while (current != NULL)
  {
    next = current->next;
    current->next = previous;
    current->previous = next;
    previous = current;
    current = next;
  }
  head = previous;
}
else
{
  printf(" You cancele reversal operation! \n");
}
}














