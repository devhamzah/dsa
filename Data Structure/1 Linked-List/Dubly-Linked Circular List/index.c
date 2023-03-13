#include <stdio.h>
#include <stdlib.h>

// Functions Signatures
void create();
void print();
void prepend();
void append();
void insertAt();
void shift();
void pop();
void removeAt();
void search();
// Structure of Node
struct node
{
  struct node *previous;
  int data;
  struct node *next;
};
struct node *head = NULL;
struct node *tail = NULL;
// Main function
int main()
{
  while (1)
  {
    printf("       mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm\n");
    printf("       |                       ( Dubly-Linked Circular List )                     |\n");
    printf("       |   1.Create Linked List        4.Append Node          7.Remove from End   |\n");
    printf("       |   2.Print Data                5.Insert at Index      8.Remove by Index   |\n");
    printf("       |   3.Prepend Node              6.Remove from Start    9.Search            |\n");
    printf("       |                                0.For Exit!                               |\n");
    printf("       |__________________________________________________________________________|\n");
    printf("\n");
    // Getting Choice
    int choice;
    printf(" Enter you choice: ");
    scanf("%d", &choice);

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
    case 0:
      exit(0);
      break;
    default:
      printf(" Invalid Choice! \n");
      break;
    }
  }
}
// Creating Circular Linked List
void create()
{
  struct node *newNode;
  newNode = (struct node *)malloc(sizeof(struct node));
  if (newNode == NULL)
  {
    printf(" Memory overflow!\n");
    exit(0);
  }
  printf(" Enter the value for Node: ");
  scanf("%d", &newNode->data);
  if (tail == NULL && tail == NULL)
  {
    newNode->next = newNode;
    newNode->previous = newNode;
    head = newNode;
    tail = newNode;
  }
  else
  {
    newNode->next = head;
    head->previous = newNode;
    head = newNode;
    head->previous = tail;
    tail->next = head;
  }
}
// Print List Data
void print()
{
  if (head == NULL && tail == NULL)
  {
    printf(" List is empty or you didn't create yet! \n");
    return;
  }
  int choice;
  printf(" Enter 1 for pirnt in forword order and 11 for reverse order: ");
  scanf("%d", &choice);
  if (choice == 1)
  {
    struct node *current = tail->next;
    while (current)
    {
      printf(" %d ", current->data);
      if (current == tail)
      {
        break;
      }
      current = current->next;
    }
    printf(" \n");
  }
  else if (choice == 11)
  {
    struct node *current = head->previous;
    while (current)
    {
      printf(" %d ", current->data);
      if (current == head)
      {
        break;
      }
      current = current->previous;
    }
    printf("\n");
  }
  else
  {
    printf(" Wrong Choice! \n");
  }
}
// Prepend Node
void prepend()
{
  struct node *newNode;
  newNode = (struct node *)malloc(sizeof(struct node));
  if (newNode == NULL)
  {
    printf(" Memory overflow!\n");
    exit(0);
  }
  printf(" Enter the value for Node: ");
  scanf("%d", &newNode->data);
  if (tail == NULL && tail == NULL)
  {
    newNode->next = newNode;
    newNode->previous = newNode;
    head = newNode;
    tail = newNode;
  }
  else
  {
    newNode->next = head;
    head->previous = newNode;
    head = newNode;
    head->previous = tail;
    tail->next = head;
  }
}
// Append Node
void append()
{
  struct node *newNode;
  newNode = (struct node *)malloc(sizeof(struct node));
  if (newNode == NULL)
  {
    printf(" Memory overflow!\n");
    exit(0);
  }
  printf(" Enter the value for Node: ");
  scanf("%d", &newNode->data);
  if (tail == NULL && tail == NULL)
  {
    newNode->next = newNode;
    newNode->previous = newNode;
    head = newNode;
    tail = newNode;
  }
  else
  {
    newNode->previous = tail;
    tail->next = newNode;
    tail = newNode;
    tail->next = head;
    head->previous = tail;
  }
}
// Insert at Specific Index
void insertAt()
{
  if (head == NULL)
  {
    printf(" List is empty or you didn't create yet! \n");
    return;
  }
  int index, i;
  printf(" Enter the index number: ");
  scanf("%d", &index);
  if (index <= 0)
  {
    printf(" Index should not be 0 or negative! \n");
    return;
  }
  if (index == 1)
  {
    prepend();
    return;
  }
  struct node *current;
  current = tail->next;
  for (i = 0; i < index - 2; i++)
  {
    if (current->next == head)
    {
      printf(" Invalid Index! \n");
      return;
    }
    current = current->next;
  }
  if (current->next == head)
  {
    printf(" Invalid \n");
    return;
  }
  struct node *newNode;
  newNode = (struct node *)malloc(sizeof(struct node));
  printf(" Enter the value for Node: ");
  scanf("%d", &newNode->data);

  newNode->next = current->next;
  current->next->previous = newNode;
  current->next = newNode;
  newNode->previous = current;
}
// Shifting Node Remove from start
void shift()
{
  if (head != NULL && head != tail)
  {
    struct node *temp;
    temp = head;
    head = head->next;
    head->previous = tail;
    tail->next = head;
    free(temp);
    temp = NULL;
  }
  else if (head == tail)
  {
    free(head);
    head = NULL;
    tail = NULL;
  }
  else if (head == NULL && tail == NULL)
  {
    printf(" List is empty! \n");
    return;
  }
}
// Poping Node Remov from end
void pop()
{
  if (tail != NULL && tail != head)
  {
    struct node *temp;
    temp = tail;
    tail = tail->previous;
    tail->next = head;
    head->previous = tail;
  }
  else if (tail == head)
  {
    tail = NULL;
    head = NULL;
  }
  else if (tail == NULL && head == NULL)
  {
    printf(" List is empty! \n");
    return;
  }
}
// Remove Nod from Specific Index
void removeAt()
{
if( head == NULL && tail == NULL)
{
  printf(" List is empty or you didn't create yet! \n");
  return;
}
int index,i;
printf(" Enter index number:  ");
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
current = tail->next;
for(i = 0; i<index -2;i++)
{
if(current->next == tail)
{
  printf(" Invalid index this time \n");
  return;
}
current = current->next;
}
if(current->next == tail)
{
  current->next = head;
  head->previous = current;
  tail = current;
}
else
{
  current->next = current->next->next;
  current->next->next->previous = current;
}
}
// Searching on List
void search()
{
  int target,index;
  index = 0;
  printf(" Enter target Value: ");
  scanf("%d",&target);
  struct node *current;
  current = tail->next;

  do
  {
    index++;
    if(current->data == target)
    {
      printf(" Your value %d found at index %d \n",target,index);
      return;
    }
    current = current->next;
  } while (current != head);
  
  printf(" Value not Found! \n");
}

