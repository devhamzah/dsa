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

void swap(int *a,int *b)
{
 int temp = *a;
 *a = *b;
 *b = temp;
}

int part(int array[],int start ,int end)
{
 int pevit = array[end];
 int pointer = start;

 for(int i = start; i < end; i++)
 {
  if(array[i] <= pevit)
  {
   swap(&array[pointer],&array[i]);
   pointer++;
  }
 }
 swap(&array[pointer],&array[end]);
 return pointer;
}

void process(int array[],int start, int end)
{
 if(start < end)
 {
  int pevit = part(array,start,end);
  process(array,start,pevit -1);
  process(array,pevit+1,end);
 }
}

void quickSort(int array[],int length)
{
 process(array,0,length-1);
}




int main()
{
 printf(" <<< Quick Sort >>> \n");
 int number[] = {45, 12, 2, 11, 0, 3, 5, 2, 1};
 int length = sizeof(number) / sizeof(number[0]);
 printf(" Unsorted Array: ");
 print(number, length);

quickSort(number,length);

 printf("   Sorted Array: ");
 print(number, length);
 return 0;
}