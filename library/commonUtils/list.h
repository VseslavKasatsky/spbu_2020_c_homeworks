#ifndef SPBU_2020_C_HOMEWORKS_LIBRARY_commonUtils_LIST_H_
#define SPBU_2020_C_HOMEWORKS_LIBRARY_commonUtils_LIST_H_
typedef struct ListElement ListElement;
typedef struct List List;
#include <stdbool.h>
List* createList();
ListElement* createListElement(int value);
void printList(List* list);

void printListHead(List* list);

void printListTail(List* list);

ListElement* tail(List* list);
ListElement* head(List* list);
void addListElement(List* list, ListElement* elem);

void removeList(List* list);

ListElement* retrieve(int position, List* list);

bool removeByValue(List* list, int value);
#endif // SPBU_2020_C_HOMEWORKS_LIBRARY_commonUtils_LIST_H_
