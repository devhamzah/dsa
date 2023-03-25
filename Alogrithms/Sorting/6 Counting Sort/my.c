#include<stdio.h>
#include<stdlib.h>

void print(int array[],int length)
{
 for(int i = 0; i < length; i++)
 {
  printf(" %d ",array[i]);
 }
}

void countSort(int array[],int size)
{
 // First find the biggest number in given array
 int max = array[0];
 for(int i = 1; i < size; i++)
 {
  if(array[i] > max)
  {
   max = array[i];
  }
 }
 // max = 45 create temp element wiht max + 1 (46)
 // set all values to 0
 int output[size];
 int box[46]={0};
 for(int i = 0; i < size; i++)
 {
  box[array[i]]++;
 }
 // Now store the cumulative cout of each index
 for(int i = 1; i <= max; i++)
 {
  box[i] += box[i-1];
 }
 
 for(int i = size -1; i >= 0; i--)
 {
  output[box[array[i]] - 1] = array[i];
  box[array[i]]--;
 }

 // Copy the sorted elements into orignal array
 for(int i = 0; i < size;i++)
{
 array[i] = output[i];
}
}

int main()
{
 int number[]={45,11,4,1,4,23,2,9,1};
 int size = sizeof(number) / sizeof(number[0]);
 printf(" Unsorted : ");
 print(number,size);

 countSort(number,size);
 
 printf("\n  Sorted  : ");
 print(number,size);



 return 0;
}