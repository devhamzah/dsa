#include <stdio.h>
#include <stdlib.h>
// Structure of List
struct node
{
 int data;
 struct node *next;
};
struct node *front = NULL;
struct node *rear = NULL;
// Functions Signatures
void enqueue();
void dequeue();
void peak();
// Main Functions
int main()
{
 printf(" Size of a queue with Linked-List depend's on System Memory  \n");
 printf(" this is also possible to limit Queue size with linke-list but  \n");
 printf(" as I already crated an Array Queue with limited size So, I decided  \n");
 printf(" to create this one without limits. (This progran exit imidiately \n");
 printf(" after your system run's out of memory) Thank You :)");
 printf("\n");

 int choice;
 while (1)
 {
  printf("     Queue with Linked-List    \n");
  printf("  ***************************** \n");
  printf("   1.For Enqueue 2.For Dequeue \n");
  printf("   3.For Peak    4.For Space  \n");
  printf("            0.For Exit  \n");
  printf("  *****************************\n");
  printf("\n");
  printf(" Enter you choice: ");
  scanf("%d", &choice);
  switch (choice)
  {
  case 1:
   enqueue();
   break;
  case 2:
   dequeue();
   break;
  case 3:
   peak();
   break;
  case 0:
   exit(0);
   break;
  default:
   printf(" Invalid Choice! \n");
   break;
  }
 }

 return 0;
}
// <<<<<<<<<<<<<<<<<  Functions >>>>>>>>>>>>>>>>>>>>>>> //
void enqueue()
{
 struct node *temp;
 temp = (struct node *)malloc(sizeof(struct node));
 printf(" Enter the value: ");
 scanf("%d", &temp->data);
 if (front == NULL && rear == NULL)
 {
  temp->next = NULL;
  front = temp;
  rear = temp;
 }
 else
 {
  rear->next = temp;
  rear = temp;
 }
}
void dequeue()
{
 if (front == NULL && rear == NULL)
 {
  printf(" Queue in empty! \n");
  return;
 }
 else if (front == rear)
 {
  printf(" %d is dequeued from Queue \n", front->data);
  free(front);
  front = NULL;
  rear = NULL;
  return;
 }
 else
 {
  struct node *extract;
  extract = front;
  front = front->next;
  printf(" %d is dequeued for Queue \n", extract->data);
  free(extract);
 }
}
void peak()
{
 if (front == NULL & rear == NULL)
 {
  printf(" Queue is empty!\n");
 }
 else
 {
  printf("%d is first at Queue! \n", front->data);
 }
}