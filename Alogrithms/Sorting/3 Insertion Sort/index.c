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

void insertSort(int array[],int length)
{
 for(int i = 1; i < length; i++)
 {
  int hold = array[i];
  int j = i -1;
  while ( j >= 0 && hold <= array[j])
  {
   array[j+1] = array[j];
   j--;
  }
  array[j+1] =hold;
 }
}




int main()
{
 printf(" <<< Insertion Sort >>> \n");
 int number[] = {45, 12, 2, 11, 0, 3, 5, 2, 1};
 int length = sizeof(number) / sizeof(number[0]);
 printf(" Unsorted Array: ");
 print(number, length);

insertSort(number,length);

 printf("   Sorted Array: ");
 print(number, length);
 return 0;
}