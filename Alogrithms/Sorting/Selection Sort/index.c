#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b)
{
 int temp = *b;
 *b = *a;
 *a = temp;
}

int main()
{
 printf(" <<<<<< Selection Sort. >>>>>>>\n");
 int numbers[] ={7,15,24,2,11,22,99,54,3,1,0};
 printf(" Unsorted Array.\n");
 for(int i = 0; numbers[i] != '\0'; i++)
 {
  printf(" %d ",numbers[i]);
 }
 printf(" \n");
 printf(" Sorting..... \n");

 for(int i = 0; numbers[i] != '\0'; i++)
 {
  int smallest = i;
  for(int j = i+1; numbers[j] != '\0'; j++)
  {
   if(numbers[smallest] > numbers[j])
   {
    smallest = j;
   }
  }
  swap(&numbers[i],&numbers[smallest]);
 }

 printf(" Sorted arrya.\n");
  for(int i = 0; numbers[i] != '\0'; i++)
 {
  printf(" %d ",numbers[i]);
 }
 printf("\n");
 
 return 0;
}