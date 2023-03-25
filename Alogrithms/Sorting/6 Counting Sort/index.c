#include<stdio.h>
#include<stdlib.h>

void print(int array[], int length)
{
 for (int i = 0; i < length; i++)
 {
  printf(" %d ", array[i]);
 }
 printf("\n");
}



void countSort(int array[],int length)
{
 int temp[50]={0};
 for(int i = 0; i < length; i++)
 {
  temp[array[i]]++;
 }

 int pointer = 0;
 for(int i = 0; i <= 46;i++)
 {
  int times = temp[i];
  if(times > 0)
  {
   for(int j = 0; j < times; j++)
   {
    // printf(" %d ",i);
    array[pointer] = i;
    pointer++;
   }
  }
 }
}


int main()
{
 printf(" <<< Count Sort >>> \n");
 int number[] = {45, 12,45,11,0,5,3,2, 11, 0, 3, 5, 2, 1};
 int max = 45;
 int length = sizeof(number) / sizeof(number[0]);
 printf(" Unsorted Array: ");
 print(number, length);


countSort(number,length);


 printf("   Sorted Array: ");
 print(number, length);
 return 0;
}