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
void reverse();
// Structure of Node
struct node
{
 int data;
 struct node *next;
};
struct node *tail = NULL;
// Main function
int main()
{
 while (1)
 {
  printf("       mmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmmm\n");
  printf("       |                       ( Singly-Linked Circular List )                    |\n");
  printf("       |   1.Create Linked List        4.Append Node          7.Remove from End   |\n");
  printf("       |   2.Print Data                5.Insert at Index      8.Remove by Index   |\n");
  printf("       |   3.Prepend Node              6.Remove from Start    9.Search            |\n");
  printf("       |                                0.For Exit!                               |\n");
  printf("       |                           101.Reverse List Data                          |\n");
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
  case 101:
   reverse();
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
  printf(" Memory Overflow! \n");
  exit(0);
 }
 printf(" Enter the Value for Node: ");
 scanf("%d", &newNode->data);
 if (tail == NULL)
 {
  newNode->next = newNode;
  tail = newNode;
 }
 else
 {
  newNode->next = tail->next;
  tail->next = newNode;
  tail = newNode;
 }
}
// Print List Data
void print()
{
 if (tail == NULL)
 {
  printf(" List is empty or you didn't create Yewt! \n");
  return;
 }
 struct node *current;
 current = tail->next;
 printf(" >>>>>>>>>>>>>>>>>> \n");
 printf(" |                 | \n");
 while (current)
 {
  printf(" |                %d \n", current->data);
  printf(" |                 | \n");
  if (current == tail)
  {
   break;
  }
  current = current->next;
 }
 printf(" <<<<<<<<<<<<<<<<<<<\n");
}
// Prepend Node
void prepend()
{
 struct node *newNode;
 newNode = (struct node *)malloc(sizeof(struct node));
 printf(" Enter the value for Node: ");
 scanf("%d", &newNode->data);
 if (tail == NULL)
 {
  newNode->next = newNode;
  tail = newNode;
 }
 else
 {
  newNode->next = tail->next;
  tail->next = newNode;
 }
}
// Append Node
void append()
{
 struct node *newNode;
 newNode = (struct node *)malloc(sizeof(struct node));
 printf(" Enter the value for Node: ");
 scanf("%d", &newNode->data);
 if (tail == NULL)
 {
  newNode->next = newNode;
  tail = newNode;
 }
 else
 {
  newNode->next = tail->next;
  tail->next = newNode;
  tail = newNode;
 }
}
// Insert at Specific Index
void insertAt()
{
 int index, i;
 struct node *start;
 start = tail->next;
 // Getting Index from User
 printf(" Enter the index Number: ");
 scanf("%d", &index);
 // Validating Index and Looping
 if (index <= 0)
 {
  printf(" Index should not be 0 or Negative! \n");
  return;
 }
 if (index == 1)
 {
  prepend();
  return;
 }
 for (i = 0; i < index - 2; i++)
 {
  start = start->next;
  if (start == tail)
  {
   printf(" Invalid Index! \n");
   return;
  }
 }

 struct node *newNode;
 newNode = (struct node *)malloc(sizeof(struct node));
 if (newNode == NULL)
 {
  printf(" Memory Overflow!\n");
  exit(0);
 }
 printf(" Enter the value for Node: ");
 scanf("%d", &newNode->data);

 newNode->next = start->next;
 start->next = newNode;
}
// Shifting Node Remove from start
void shift()
{
 if (tail == NULL)
 {
  printf(" List is empty or you didn't create Yet! \n");
  return;
 }
 if (tail->next == tail)
 {
  tail = NULL;
  return;
 }
 tail->next = tail->next->next;
 return;
}
// Poping Node Remov from end
void pop()
{
 struct node *current;
 current = tail->next;
 if (current == tail)
 {
  tail = NULL;
  return;
 }
 while (current->next != tail)
 {
  current = current->next;
 }
 current->next = current->next->next;
 tail = current;
}
// Remove Nod from Specific Index
void removeAt()
{
 int index, i;
 struct node *current, *temp;
 current = tail;

 printf(" Enter index number: ");
 scanf("%d", &index);

 for (i = 0; i < index - 1; i++)
 {
  current = current->next;
  if (current == tail)
  {
   printf(" Invalid index! \n");
   return;
  }
 }
 if(current->next == tail && current->next == current)
 {
  free(current);
  tail = NULL;
  return;
 }
 if (current->next == tail)
 {
  temp = current->next;
  current->next = temp->next;
  free(temp);
  temp = NULL;
  tail = current;
  return;
 }
 temp = current->next;
 current->next = temp->next;
 free(temp);
 temp = NULL;
}
// Searching on List
void search()
{
 int target,index;
 index = 0;
 printf(" Enter target value: ");
 scanf("%d",&target);
 struct node *current;
 current = tail->next;
 while (current != tail)
 {
  index++;
  if(current->data == target)
  {
   printf(" Your value %d found at index %d \n",target,index);
   return;
  }
  current = current->next;
 }
 printf(" Value not found! \n");
}
// Reverse List Data
void reverse()
{
 if(tail == NULL)
 {
  printf(" List is empty cannot reverse! \n");
  return;
 }
 struct node *head,*current,*next,*last,*previous;
 head = tail->next;
 last = tail;
 tail->next = NULL;
 current = head;
 previous = NULL;

 while (current != NULL)
 {
  next = current->next;
  current->next = previous;
  previous = current;
  current = next;
 }
 
head->next = last;
tail= head;

}



