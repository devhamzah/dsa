#include <stdlib.h>
#include <stdio.h>

void swap(int *a, int *b)
{
 int temp = *a;
 *a = *b;
 *b = temp;
}

int main()
{
 // Create and print unsorted array
 int number[] = {45, 12, 8, 2, 85, 86, 17, 11, 0, 1, 22};
 int length = sizeof(number) / sizeof(number[0]);
 printf(" Unsorted array: ");
 for (int i = 0; i < length; i++)
 {
  printf(" %d ",number[i]);
 }
 printf("\n");
 // Implement Bubble sort Alogrithm
 for (int i = 0; i < length; i++)
 {
  for (int j = i + 1; j < length; j++)
  {
   if (number[i] > number[j])
    swap(&number[i], &number[j]);
  }
 }
 printf(" After running bubble sort: ");
 for(int i = 0; i < length; i++)
 {
  printf(" %d ",number[i]);
 }
 printf("\n");

 return 0;
}