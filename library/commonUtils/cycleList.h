#ifndef SPBU_2020_C_HOMEWORKS_LIBRARY_commonUtils_CYCLELIST_H_
#define SPBU_2020_C_HOMEWORKS_LIBRARY_commonUtils_CYCLELIST_H_
#include <stdbool.h>

typedef struct ListElement ListElement;
typedef struct List List;

List* createList();
ListElement* createListElement(int value, List* list);
ListElement* tail(List* list);
ListElement* head(List* list);

bool insert(ListElement* element, int position, List* list);
bool deleteCurrentElement(List* list);
bool isEmpty(List* list);

void removeList(List* list);
void removeElement(ListElement* list);
void nextCycleListElement(List* list);

int getSize(List* list);
int locate(ListElement* element, List* list);
int getCurrentValue(List* list);

#endif // SPBU_2020_C_HOMEWORKS_LIBRARY_commonUtils_CYCLELIST_H_
