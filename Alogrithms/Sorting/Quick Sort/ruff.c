#include <stdio.h>
#include <stdlib.h>
// Swap Fucntion
void swap(int *a, int *b)
{
 int temp = *a;
 *a = *b;
 *b = temp;
}

// Partition of Array deviding by pivet
int partition(int array[],int low,int high)
{
 int pivetValue = array[high];
 int i = low;

 for(int j = low; j<high; j++)
 {
   if(array[j] <= pivetValue)
   {
    swap(&array[i],&array[j]);
    i++;
   }
 }

 swap(&array[i],&array[high]);
 return i;
}

// Quick Sort Recursive Function
void quickRec(int array[], int low, int high)
{
 if (low < high)
 {
  int pivetIndex = partition(array, low, high);
  quickRec(array, low, pivetIndex - 1);
  quickRec(array, pivetIndex + 1, high);
 }
}

// Quick Sort Wrapper
void quickSort(int array[], int length)
{
 quickRec(array, 0, length - 1);
}

int main()
{
 printf(" <<<<<<<< Quick Sort >>>>>>>\n");

 return 0;
}