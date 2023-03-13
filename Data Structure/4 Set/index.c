#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
// Define Set Data Structure
typedef struct
{
 int *members;
 int length;
} Set;
// Functions Signatures or declearation
Set *init();
bool isEmpty(Set *set);
void insert(Set *set, int member);
void printSet(Set *set);
Set *setUnion(Set *setA, Set *setB);
Set *setIntersect(Set *setA, Set *setB);
Set *setDifference(Set *setA,Set *setB);
bool isMember(Set *set,int member);
bool isSubset(Set *setA,Set *setB);
bool isEqual(Set *setA,Set *setB);
// Main functions
int main()
{
 // Initializing Set A
 Set *setA = init();
 // Adding members to Set A
 insert(setA, 5);
 insert(setA, 6);
 insert(setA, 7);
 insert(setA, 8);
 // Printing Data of Set A
 printf(" SET A: ");
 printSet(setA);
 // Initializing Set B
 Set *setB = init();
 // Adding members to Set B
 insert(setB, 5);
 insert(setB, 11);
 insert(setB, 7);
 insert(setB, 8);


 // Printing Data of Set B
 printf(" SET B: ");
 printSet(setB);

 Set *setC = setUnion(setA, setB);
 printf("\n");
 printf(" A Uunion B : ");
 printSet(setC);
 printf("\n");

 Set *setD = setIntersect(setA, setB);
 printf(" A Intersection B :");
 printSet(setD);
 printf("\n");

 Set *setE = setDifference(setA, setB);
 printf(" A Difference B :");
 printSet(setE);
 printf("\n");

 Set *setF = setDifference(setB, setA);
 printf(" B Difference A :");
 printSet(setF);
 printf("\n");

 if(isSubset(setA,setB))
 {
  printf(" A is a Subset of B\n");
 }
 else
 {
  printf(" A is not a Subset of B\n");
 }

if(isEqual(setA,setB))
{
 printf(" A and B Sets are Equal! \n");
}
else
{
 printf(" A and B Sets are not Equal!\n");
}

 return 0;
}
// <<<<<<<<<<<<<<<<<<< Functions Definations >>>>>>>>>>>>>>>>>>>>>> //
Set *init()
{
 Set *newSet = malloc(sizeof(Set));
 newSet->length = 0;
 newSet->members = malloc(sizeof(int));
 return newSet;
}
bool isEmpty(Set *set)
{
 return (set->length == 0);
}
void insert(Set *set, int member)
{
 bool check = true;
 for (int i = 0; i < set->length; i++)
 {
  if (set->members[i] == member)
  {
   check = false;
  }
 }
 if (check)
 {
  set->members = realloc(set->members, sizeof(int) * (set->length + 1));
  set->members[set->length] = member;
  set->length = set->length + 1;
 }
}
void printSet(Set *set)
{
 printf("{");
 for (int i = 0; i < set->length; i++)
 {
  printf(" %d ", set->members[i]);
 }
 printf("}");
}
Set *setUnion(Set *setA, Set *setB)
{
 Set *new = init();
 for (int i = 0; i < setA->length; i++)
 {
  insert(new, setA->members[i]);
 }
 for (int i = 0; i < setB->length; i++)
 {
  insert(new, setB->members[i]);
 }
 return new;
}
Set *setIntersect(Set *setA, Set *setB)
{
 Set *temp = init();
 for (int i = 0; i < setA->length; i++)
 {
  for (int j = 0; j < setB->length; j++)
  {
   if (setA->members[i] == setB->members[j])
   {
    insert(temp, setA->members[i]);
   }
  }
 }
 return temp;
}
Set *setDifference(Set *setA,Set *setB)
{
  Set *temp = init();
 for (int i = 0; i < setA->length; i++)
 {
  bool check = true;
  for (int j = 0; j < setB->length; j++)
  {
   if (setA->members[i] == setB->members[j])
   {
    check = false;
    break;
   }
  }
  if(check)
  {
   insert(temp,setA->members[i]);
  }

 }
 return temp;
}
bool isMember(Set *set,int member)
{
 int i = 0;
 while (i < set->length)
 {
  if(set->members[i] == member){
   return true;
   break;
  }
  i++;
 }
 return false;
}
bool isSubset(Set *setA,Set *setB)
{
 for(int i = 0; i < setA->length;i++)
 {
  bool check = true;
  for(int j = 0; j < setB->length; j++)
  {
   if(setA->members[i] == setB->members[j])
   {
    check = false;
   }
  }
  if(check) return false;
 }
 return true;
}
bool isEqual(Set *setA,Set *setB)
{
 if(setA->length != setA->length) return false;
 return isSubset(setA,setB);
}


















