#include <stdio.h>
#include <stdlib.h>

// Swap values between index
void swap(int *a, int *b)
{
 int temp = *a;
 *a = *b;
 *b = temp;
}

// Function to find the partition position
int partition(int array[], int start, int end)
{
 // select right most element as a pivet
 int pivot = array[end];
 // make hold pointer for greater element
 int hold = start;
 // traverse each element of array
 // compare then wiht the pivet
 for (int j = start; j < end; j++)
 {
  if (array[j] <= pivot)
  {
   swap(&array[hold], &array[j]);
   hold++;
  }
 }
 swap(&array[hold], &array[end]);
 // Return the partition point
 return hold;
}

// this
void quickSort(int array[],int start,int end)
{
 if(start < end)
 {
  // find the pivet element such that 
  // elements smaller than the pivet goes on left side
  // elements bigger than the pivet goes on right side
  int pivet = partition(array,start,end);
  // recursive call on the left side of pivet
  quickSort(array,start,pivet-1);

  // recursive call on the right side of the pivet
  quickSort(array,pivet+1,end);

 }
}

int main()
{
 printf(" <<<< Quicksort >>>> \n");
 // Creating unsorted Array
 int number[] = {45,12,2,0,85,15,85,96,78,11,7,3};
 int size = sizeof(number) / sizeof(number[0]);
 // Print unsorted Array
 printf(" Unsorted Array: ");
 for(int i = 0; i < size ; i++)
 {
  printf(" %d ",number[i]);
 }
 printf("\n");

 // Sorting Array with Quicksort
 quickSort(number,0,size-1);

 // Print after sorting Array
 printf(" Sorted Array: ");
 for(int i = 0; i < size ; i++)
 {
  printf(" %d ",number[i]);
 }
 printf("\n");

 return 0;
}