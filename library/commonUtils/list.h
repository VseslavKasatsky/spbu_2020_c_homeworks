#ifndef SPBU_2020_C_HOMEWORKS_LIBRARY_commonUtils_LIST_H_
#define SPBU_2020_C_HOMEWORKS_LIBRARY_commonUtils_LIST_H_
#include <stdbool.h>
typedef struct ListElement ListElement;
typedef struct List List;
List* createList();
ListElement* createListElement(int value);
ListElement* tail(List* list);
ListElement* head(List* list);
bool insert(ListElement* element, int position, List* list);
int locate(ListElement* element, List* list);
ListElement* retrieve(int position, List* list);
bool deleteElementOnPosition(int position, List* list);
void removeList(List* list);
int getSize(List* list);
bool isEmpty(List* list);
void printList(List* list);

#endif // SPBU_2020_C_HOMEWORKS_LIBRARY_commonUtils_LIST_H_
