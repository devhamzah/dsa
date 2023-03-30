#include<stdio.h>
#include<stdlib.h>



int binarySearch(int array[],int length,int target)
{
 int left = 0;
 int right = length;
 while (left <= right)
 {
  int mid = (left + right) / 2;
  if(target == array[mid])
  {
   return 1;
  }
  else if (target > array[mid])
  {
   left = mid + 1;
  }
  else if (target < array[mid])
  {
   right = mid - 1;
  }
 }
 return 0;
}

int main()
{
 int numbers[]={0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
 int length = sizeof(numbers) / sizeof(numbers[0]);


 if(binarySearch(numbers,length,0))
 {
  printf(" Found \n");
 }
 else
 {
  printf(" Nod found \n");
 }
 


 return 0;
}