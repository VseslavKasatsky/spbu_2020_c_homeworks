#include "list.h"
#include <malloc.h>
#include <stdlib.h>
struct ListElement {
    int value;
    struct ListElement* next;
};

struct List {
    struct ListElement* head;
};

List* createList()
{
    List* list = malloc(sizeof(List));
    list->head = NULL;
    return list;
}

ListElement* createListElement(int value)
{
    ListElement* elem = malloc(sizeof(ListElement));
    elem->value = value;
    elem->next = NULL;
    return elem;
}