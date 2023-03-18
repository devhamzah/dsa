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
 printf(" Swap \n");
 int temp = *a;
 *a = *b;
 *b = temp;
}

void selectSort(int array[],int length)
{

 for(int i = 0; i < length; i++)
 {
  int select = i;
  for(int j = i + 1; j < length; j++)
  {
   if(array[j] < array[select])
   {
    select = j;
   }
  }
  // Optemised call of swap funtion 
  if(select > i)
  {
  swap(&array[i],&array[select]);
  }
 }

}


int main()
{
 printf(" <<< Selection Sort >>> \n");
 int number[] = {45, 12, 2, 11, 0, 3, 5, 2, 1};
 int length = sizeof(number) / sizeof(number[0]);
 printf(" Unsorted Array: ");
 print(number, length);

selectSort(number,length);

 printf("   Sorted Array: ");
 print(number, length);
 return 0;
}