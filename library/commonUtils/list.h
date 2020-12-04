#ifndef SPBU_2020_C_HOMEWORKS_LIBRARY_commonUtils_LIST_H_
#define SPBU_2020_C_HOMEWORKS_LIBRARY_commonUtils_LIST_H_
#include <stdbool.h>

typedef struct ListElement ListElement;
typedef struct List List;

List* createList();
ListElement* createListElement(int value);
ListElement* tail(List* list);
ListElement* head(List* list);
ListElement* retrieve(int position, List* list);
ListElement* getNextInCycle(List* list, ListElement* previousElement);
ListElement* getNextElement(ListElement* element);
ListElement* getPreviousElement(ListElement* element);

bool insert(ListElement* element, int position, List* list);
bool deleteElementOnPosition(int position, List* list);
bool isEmpty(List* list);

void removeList(List* list);
void removeElement(ListElement* list);
void printList(List* list);

int getSize(List* list);
int locate(ListElement* element, List* list);
int getElementValue(ListElement* element);

#endif // SPBU_2020_C_HOMEWORKS_LIBRARY_commonUtils_LIST_H_
