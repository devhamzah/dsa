#include <stdio.h>
#include <stdlib.h>

// Find max element in array
int maxValue(int array[], int length)
{
 int max = array[0];
 for (int i = 1; i < length; i++)
 {
  if (array[i] > max)
  {
   max = array[i];
  }
 }
 return max;
}

void countSort(int array[], int size, int place)
{
 int output[size + 1];
 int max = (array[0] / place) % 10;

 for (int i = 1; i < size; i++)
 {
  if (((array[i] / place) % 10) > max)
  {
   max = array[i];
  }
 }

 int count[max + 1];
 for (int i = 0; i < max; i++)
 {
  count[i] = 0;
 }

 // Calculate count of element
 for (int i = 0; i < size; i++)
 {
  count[(array[i] / place) & 10]++;
 }

 // Calculate cumulative count
 for(int i = 1; i < 10; i++)
 {
  count[i] += count[i-1];
 }
 // Place the element in sorted order
 for(int i = size -1; i >=0; i--)
 {
  
 }

}

void radixSort(int array[], int size)
{
 int max = maxValue(array, size);
 for (int place = 1; max / place > 0; place *= 10)
 {
  countSort(array, size, place);
 }
}

void print(int array[], int length)
{
 for (int i = 0; i < length; i++)
 {
  printf(" %d ", array[i]);
 }
 printf("\n");
}

int main()
{
 int numbers[] = {11, 5, 0, 355, 44, 185, 295};
 int length = sizeof(numbers) / sizeof(numbers[0]);
 printf(" Unsorted: ");
 print(numbers, length);

 return 0;
}