#include "cycleList.h"
#include <stdio.h>
#include <stdlib.h>

struct ListElement {
    int value;
    struct ListElement* next;
    struct ListElement* previous;
};
struct List {
    struct ListElement* head;
    struct ListElement* tail;
    struct ListElement* current;
    int size;
};
List* createList()
{
    List* list = malloc(sizeof(List));
    list->head = NULL;
    list->tail = NULL;
    list->current = NULL;
    list->size = 0;
    return list;
}
ListElement* createListElement(int value, List* list)
{
    ListElement* element = malloc(sizeof(ListElement));
    element->value = value;
    element->next = NULL;
    element->previous = NULL;
    return element;
}
ListElement* head(List* list)
{
    return list->head;
}
ListElement* tail(List* list)
{
    return list->tail;
}
bool insert(ListElement* element, int position, List* list)
{
    if (position > getSize(list) || position < 0) {
        return false;
    }
    if (isEmpty(list)) {
        list->head = element;
        list->tail = element;
        list->size++;
        list->current = element;
        return true;
    }
    if (position == 0) {
        list->head->previous = element;
        element->next = head(list);
        list->head = element;
        list->size++;
        return true;
    }
    if (position == getSize(list)) {
        list->tail->next = element;
        element->previous = tail(list);
        list->tail = element;
        element->next = head(list);
        list->head->previous = element;
        list->size++;
        return true;
    }
    ListElement* insertElement = head(list);
    for (int i = 0; i < position; ++i) {
        insertElement = insertElement->next;
    }
    insertElement->previous->next = element;
    element->previous = insertElement->previous;
    insertElement->previous = element;
    element->next = insertElement;
    list->size++;
    return true;
}
bool deleteCurrentElement(List* list)
{
    ListElement* deleteElement = list->current;
    deleteElement->previous->next = deleteElement->next;
    deleteElement->next->previous = deleteElement->previous;
    list->current = list->current->next;
    removeElement(deleteElement);
    return true;
}
int getSize(List* list)
{
    return list->size;
}
bool isEmpty(List* list)
{
    return list->size == 0;
}
void removeList(List* list)
{
    deleteCurrentElement(list);
    free(list);
}
void removeElement(ListElement* listElement)
{
    free(listElement);
}
void nextCycleListElement(List* list)
{
    list->current = list->current->next;
}
int getCurrentValue(List* list)
{
    return list->current->value;
}
