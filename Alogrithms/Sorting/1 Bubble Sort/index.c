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

void bubbleSort(int array[],int length)
{
 for(int i = 0; i < length; i++)
 {
  for(int j = i+1; j < length; j++)
  {
   if(array[j] <= array[i])
   {
    swap(&array[j],&array[i]);
   }
  }
 }

}



int main()
{
 printf(" <<< Bubble Sort >>> \n");
 int number[] = {45, 12, 2, 11, 0, 3, 5, 2, 1};
 int length = sizeof(number) / sizeof(number[0]);
 printf(" Unsorted Array: ");
 print(number, length);

bubbleSort(number,length);

 printf("   Sorted Array: ");
 print(number, length);
 return 0;
}