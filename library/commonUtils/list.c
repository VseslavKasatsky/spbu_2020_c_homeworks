#include "list.h"
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
    int size;
};

List* createList()
{
    List* list = malloc(sizeof(List));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

ListElement* createListElement(int value)
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
int locate(ListElement* element, List* list)
{
    ListElement* locateElement = head(list);
    int position = 0;
    while (locateElement != element) {
        locateElement = locateElement->next;
        ++position;
    }
    return position;
}
ListElement* retrieve(int position, List* list)
{
    if (position > getSize(list) || position < 0 || getSize(list) < 0) {
        return false;
    }
    ListElement* retrieveElement = head(list);
    for (int i = 0; i < position; ++i) {
        retrieveElement = retrieveElement->next;
    }
    return retrieveElement->value;
}
bool deleteElementOnPosition(int position, List* list)
{
    if (position > getSize(list) || position < 0) {
        return false;
    }
    if (list->size == 1) {
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
        list->size--;
        return true;
    }

    if (position == 0) {
        list->head->next->previous = NULL;
        ListElement* temp = head(list);
        list->head = head(list)->next;
        free(temp);
        list->size--;
        return true;
    }

    if (position == getSize(list) - 1) {
        list->tail->previous->next = NULL;
        ListElement* temp = tail(list);
        list->tail = tail(list)->previous;
        free(temp);
        list->size--;
        return true;
    }
    ListElement* temp = head(list);
    for (int i = 0; i < position; ++i) {
        temp = temp->next;
    }
    temp->previous->next = temp->next;
    temp->next->previous = temp->previous;
    free(temp);
    list->size--;
    return true;
}
void removeList(List* list)
{
    while (!isEmpty(list)) {
        deleteElementOnPosition(1, list);
    }
    free(list);
}
bool isEmpty(List* list)
{
    return list->size == 0;
}

int getSize(List* list)
{
    return list->size;
}
void printList(List* list)
{
    printf("START -> ");
    ListElement* toPrint = head(list);
    while (toPrint != NULL) {
        printf("%d -> ", toPrint->value);
        toPrint = toPrint->next;
    }
    printf("END\n");
}
