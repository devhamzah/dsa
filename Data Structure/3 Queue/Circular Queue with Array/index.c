#include <stdio.h>
#include <stdlib.h>
// Define Array of Queue and impotant Variables
int Queue[50];
// int size = sizeof(Queue) / sizeof(Queue[0]);
int size;
int front = -1;
int rear = -1;
int choice;
int ans;
// Signature of functions
void enqueue();
void dequeue();
void peak();
// isFull();
// Main functions
int main()
{
 do
 {
 printf("\n");
 printf(" Enter Queue Size. Value Must Be Bigger Than 0 And Less From  Max Size [MAX:50]: ");
 scanf("%d",&size);
 if(size > 50 || size <= 0)
 {
  printf(" You put invalid value for Queue size \n");
  printf(" Value must be between 1 -- MAX and MAX is 50.\n");
  printf(" Enter 1 for Retry and 0 for exti: ");
  scanf("%d",&ans);
  if (ans == 1)
  {
   continue;
  }
  else
  {
   return 0;
  }
 }
 else
 {
  break;
 }
 } while (1);
 
 printf("  Circular Queue's Selected Max Size is %d \n",size);
 while (1)
 {
  printf("    Circular Queue with Array    \n");
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
// <<<<<<<<<<<<<<<<<<<<< Functions >>>>>>>>>>>>>>>>>>>>>>>>>> //
// Enqueue item in Queue
void enqueue()
{
 int temp;
 if (front == -1 && rear == -1)
 {
  front++;
  rear++;
  printf(" Enter the value: ");
  scanf("%d", &temp);
  Queue[rear] = temp;
 }
 else
 {
  
  if (front == (rear + 1) % size)
  {
   printf(" Queue is Full! \n");
   return;
  }
  else
  {
   rear = (rear + 1) % size;
   printf(" Enter the value: ");
   scanf("%d", &temp);
   Queue[rear] = temp;
  }
 }
}
// Dequeue item from Queue
void dequeue()
{
if(front == -1 && rear == -1)
{
 printf(" Queue is Empty! \n");
 return;
}
else if (front == rear)
{
 printf("%d is Dequeued from Queue! \n",Queue[front]);
 front = -1;
 rear = -1;
 return;
}
else
{
 printf("%d is Dequeued from Queue!\n",Queue[front]);
 front = (front+1)%size;
}
}
// Peak first most element in Queue
void peak()
{
 if(rear != -1 && front != -1)
 {
 printf(" %d is at first in Queue! \n",Queue[front]);
 }
 else
 {
  printf(" Queue is empty Peat not Avalible! \n");
 }
}






