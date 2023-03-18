#include <stdio.h>
#include <stdlib.h>

void print(int array[], int length)
{
 for (int i = 0; i < length; i++)
 {
  printf(" %d ", array[i]);
 }
 printf("\n");
}

void merge(int array[], int start, int mid, int end)
{
 // Find left and right portion length
 int left_length = mid - start + 1;
 int right_length = end - mid;
 // Create temp array for both portion
 int leftArray[left_length];
 int rightArray[right_length];
 // Copy values in to temp array
 for (int i = 0; i < left_length; i++)
 {
  leftArray[i] = array[start + i];
 }
 for(int i = 0; i < right_length; i++)
 {
  rightArray[i] = array[mid + 1 + i];
 }
 // Compare & Merge
 int a,b,main;
 a = 0;
 b = 0;
 main = start;

 while (a < left_length && b < right_length)
 {
  if(leftArray[a] <= rightArray[b])
  {
   array[main] = leftArray[a];
   a++;
  }
  else
  {
   array[main] = rightArray[b];
   b++;
  }
  main++;
 }

 while (a < left_length)
 {
  array[main] = leftArray[a];
  a++;
  main++;
 }
 while (b < right_length)
 {
  array[main] = rightArray[b];
  b++;
  main++;
 }

}

void devide(int array[], int start, int end)
{
 if(start < end)
 {
 int mid = start + (end - start) / 2;
 // Left Part
 devide(array, start, mid);
 // Right Part
 devide(array, mid + 1, end);
 // Now call merge haere
 merge(array, start, mid, end);
 }

}

void mergeSort(int array[], int length)
{
 devide(array, 0, length-1);
}

int main()
{
 printf(" <<< Merge Sort >>> \n");
 int number[] = {45, 12, 2, 11, 0, 3, 5, 2, 1};
 int length = sizeof(number) / sizeof(number[0]);
 printf(" Unsorted Array: ");
 print(number, length);

mergeSort(number,length);

 printf("   Sorted Array: ");
 print(number, length);
 return 0;
}