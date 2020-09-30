#ifndef SPBU_2020_C_HOMEWORKS_LIBRARY_COMMONUTILS_SOLDIERS_H_
#define SPBU_2020_C_HOMEWORKS_LIBRARY_COMMONUTILS_SOLDIERS_H_
typedef struct Soldier Soldier;
typedef struct Troop Troop;
#include <stdbool.h>
Troop* createTroop();
Soldier* createSoldier(int value, int number);
Soldier* tail(Troop* list);
Soldier* head(Troop* list);
bool insert(ListElement* element, int position, List* list);
int locate(ListElement* element, List* list);
ListElement* retrieve(int position, List* list);
bool delete (int position, List* list);
void removeList(List* list);
int getSize(List* list);
bool isEmpty(List* list);
void printList(List* list);

#endif //SPBU_2020_C_HOMEWORKS_LIBRARY_COMMONUTILS_SOLDIERS_H_
