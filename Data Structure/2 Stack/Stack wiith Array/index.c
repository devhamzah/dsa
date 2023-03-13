#include <stdio.h>
#include <stdlib.h>
// Main Variables
int Stack[100], size, pointer, value, choice,capacity;
// Functions Signatures
void push();
void pop();
void peak();
// Main Functions
int main()
{
 pointer = -1;
 size = 0;
 printf(" Enter the size of Stack[MAX=100] : ");
 scanf("%d", &capacity);
 if (capacity > sizeof(Stack) / sizeof(Stack[0]))
 {
  printf(" Err: Size of Stact Override! Max Size is 100 \n");
  return 0;
 }

 do
 {
  printf("      STACK OPERATIONS USING ARRAY     \n");
  printf("    ***********************************     \n");
  printf("     1.For Push  2.For Pop 3.For Peak\n");
  printf("                 4.For Exit!                   \n");
  printf(" \n");
  printf(" Enter the choice: ");
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
   printf(" Good Bye See You Later! \n");
   break;
  default:
   printf(" Invalid Choice! \n");
  }
 } while (choice != 4);

 return 0;
}

// Pushing item in Stack
void push()
{
 if (pointer>= capacity -1)
 {
  printf(" Stack is overflow! \n");
  return;
 }
 else
 {
  pointer++;
  size++;
  printf(" Enter the value for push: ");
  scanf("%d", &value);
  Stack[pointer] = value;
 }
}
void pop()
{
 if (pointer <= -1)
 {
  printf(" Stack is underflow! \n");
  return;
 }
 else
 {
  printf(" The popped element is %d .\n", Stack[pointer]);
  Stack[pointer] = 0;
  pointer--;
  size--;
 }
}
void peak()
{
 if (pointer > -1)
 {
  printf(" The peak value in Stack is %d .\n", Stack[pointer]);
 }
 else
 {
  printf(" Stack is empty!\n");
 }
}
// <=============> Key Functions =================> //
