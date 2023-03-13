#include <stdio.h>
#include <stdlib.h>

int main()
{
 printf(" <<<<<<<<< Insertion sort. >>>>>>>>\n");
 int number[] = {15, 58, 1, 45, 5, 1, 22, 82, 11};
 printf(" Unsorted Array.\n");
 int size = sizeof(number) / sizeof(number[0]);
 for (int i = 0; i < size; i++)
 {
  printf(" %d ", number[i]);
 }

 printf(" \n");
 printf(" Sorting....\n");

 // for (int i = 1; i < size; i++)
 // {
 //  int current = number[i];
 //  int j = i -1;
 //  while (j>=0 && number[j] > current)
 //  {
 //   number[j+1] = number[j];
 //      printf(" %d ",j);
 //   j--;
 //  }
 //  number[j+1] = current;
 // }


 // 2nd Alog with for loop


 for (int i = 1; i < size; i++)
 {
  int current = number[i];
  int key;
  for (int j = i - 1; j >= 0; j--)
  {
   if (number[j] > current)
   {
    number[j + 1] = number[j];
   }else
   {
    break;
   }
   number[j] = current;
  }
 }

 printf(" Sorted Array.\n");
 for (int i = 0; i < size; i++)
 {
  printf(" %d ", number[i]);
 }

 printf(" \n");

 return 0;
};