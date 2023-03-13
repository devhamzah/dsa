#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
// User Defined
#define TABLE_LENGTH 10 // Max lenght of set Array
#define MAX_CHAR 20     // Max name size of person
// Structure of Node
typedef struct Person
{
 char name[MAX_CHAR];
 struct Person *next;
} Person;
Person *table[TABLE_LENGTH];
// Functions Signatures
void init();
unsigned int hash(char *name);
bool insert(Person *p);
void print();
void look(char *name);
void delete(char *name);
// Main Function
int main()
{
 // Initializing Table > Setting all pointers to NULL
 init();
 Person faisal = {.name = "faisal"};
 Person atif = {.name = "atif"};
 Person hamza = {.name = "hamza"};
 Person sayam = {.name = "sayam"};
 Person maryam = {.name = "maryam"};
 Person louis = {.name = "louis"};
 Person khan = {.name = "khan"};
 Person hafeez = {.name = "hafeez"};
 Person naseem = {.name = "naseem"};
 Person nabeel = {.name = "nabeel"};
 insert(&faisal);
 insert(&atif);
 insert(&sayam);
 insert(&hamza);
 insert(&maryam);
 insert(&louis);
 insert(&khan);
 insert(&hafeez);
 insert(&naseem);
 insert(&nabeel);
 look("sayam");
 look("louis");
 look("not");
 delete("atif");
 delete("khan");
 print();

 return 0;
}
// <<<<<<<<<<<<<<<<<<<<< FUNCTIONS DEFINATIONS >>>>>>>>>>>>>>>>>>>>>>>>>>>>>//
void init()
{
 for (int i = 0; i < TABLE_LENGTH; i++)
 {
  table[i] = NULL;
 }
 printf(" Table initialized sucessfully! \n");
}
unsigned int hash(char *name)
{
 int length = strlen(name);
 unsigned int hashValue = 0;
 for (int i = 0; i < length; i++)
 {
  hashValue += name[i];
  hashValue = (hashValue * name[i] % TABLE_LENGTH);
 }
 return hashValue;
}
bool insert(Person *p)
{
 if (p == NULL)
  return false;
 int index = hash(p->name);
 p->next = table[index];
 table[index] = p;
}
void print()
{
 for (int i = 0; i < TABLE_LENGTH; i++)
 {
  if (table[i] == NULL)
  {
   printf(" Index %d is NULL \n", i);
  }
  else
  {
   struct Person *temp;
   temp = table[i];
   printf(" Index %d is ", i);
   while (temp != NULL)
   {
    printf("%s --> ", temp->name);
    temp = temp->next;
   }
   printf(" NULL \n");
  }
 }
}
void look(char *name)
{
 int index = hash(name);
 if (table[index] == NULL)
 {
  printf(" No match found for %s. \n", name);
 }
 else
 {
  struct Person *temp;
  int position = 0;
  temp = table[index];
  while (temp != NULL)
  {
   position++;
   if (strncmp(temp->name, name, MAX_CHAR) == 0)
   {
    printf(" %s found at index %d on position %d \n", temp->name, index, position);
    return;
   }
   temp = temp->next;
  }
  printf(" No match found for %s. \n", name);
 }
}
void delete(char *name)
{
 int index = hash(name);
 if(table[index] == NULL)
 {
  printf(" No match found for deletion! \n");
 }
 else
 {
  struct Person *temp;
  temp = table[index];
  if(strncmp(temp->name,name,MAX_CHAR)== 0)
  {
   table[index] = temp->next;
   return;
  }
  while (temp != NULL)
  {
   if(strncmp(temp->next->name,name,MAX_CHAR) == 0)
   {
    temp->next = temp->next->next;
    break;
   }
   temp = temp->next;
  }
  table[index] = temp;
 }
}




















