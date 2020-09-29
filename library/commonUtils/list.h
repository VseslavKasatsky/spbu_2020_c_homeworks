#ifndef SPBU_2020_C_HOMEWORKS_LIBRARY_commonUtils_LIST_H_
#define SPBU_2020_C_HOMEWORKS_LIBRARY_commonUtils_LIST_H_
typedef struct ListElement ListElement;
typedef struct List List;
#include <stdbool.h>
List* createList();
ListElement* createListElement(int value);
void addListElement(List* list, ListElement* elem);
ListElement* tail(List* list);
ListElement* head(List* list);
int size(List* list);
bool isEmpty(List* list);
int getValue(ListElement* listElement);

void printList(List* list);
void removeList(List* list);

ListElement* retrieve(int position, List* list);

bool removeByValue(List* list, int value);
#endif // SPBU_2020_C_HOMEWORKS_LIBRARY_commonUtils_LIST_H_
