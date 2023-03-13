#include <stdio.h>
#include <stdlib.h>

int size = 0;

void swap(int *a, int *b)
{
   int temp = *a;
   *a = *b;
   *b = temp;
}

void heapify(int array[], int size, int index)
{
   if (size == 1)
   printf(" Single element in the heap!\n");
   else
   {
      int largest = index;
      int left = 2 * index + 1;
      int right = 2 * index + 2;

      if (left < size && array[left] > array[largest])
         largest = left;
      if (right < size && array[right] > array[largest])
         largest = right;
      if (largest != index)
      {
         swap(&array[index], &array[largest]);
         heapify(array, size, largest);
      }
   }
}

void insert(int array[], int newNumber)
{
   if (size == 0)
   {
      array[0] = newNumber;
      size += 1;
   }
   else
   {
      array[size] = newNumber;
      size += 1;
      for (int i = size / 2 - 1; i >= 0; i--)
      {
         heapify(array, size, i);
      }
   }
}

void deleteRoot(int array[], int number)
{
   int i;
   for (i = 0; i < size; i++)
      if (number == array[i])
         break;
   swap(&array[i], &array[size - 1]);
   size -= 1;
   for (int i = size / 2 - 1; i >= 0; i--)
   {
      heapify(array, size, i);
   }
}

void print(int array[], int size)
{
   for (int i = 0; i < size; i++)
   {
      printf(" %d \n", array[i]);
   }
   printf("\n");
}

int main()
{
   int array[10];
   insert(array, 3);
   insert(array, 4);
   insert(array, 9);
   insert(array, 5);
   insert(array, 2);

   printf("Max-Heap array: ");
   print(array, size);

   deleteRoot(array, 4);

   printf("After deleting an element: ");

   print(array, size);
   return 0;
}