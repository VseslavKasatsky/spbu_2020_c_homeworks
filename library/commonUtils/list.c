#include "list.h"
#include <malloc.h>
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
void addListElement(List* list, ListElement* elem)
{
    if (list->head == NULL) {
        list->head = elem;
        list->tail = elem;
        return;
    }
    ListElement* temp = list->head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = elem;
    list->tail = elem;
}
ListElement* head(List* list)
{
    return list->head;
}
ListElement* tail(List* list)
{
    return list->tail;
}
int getValue(ListElement* listElement)
{
    return listElement->value;
}
bool isEmpty(List* list)
{
    return list->size == 0;
}

int size(List* list)
{
    return list->size;
}
void printList(List* list)
{
    printf("START -> ");
    ListElement* temp = list->head;
    while (temp != NULL) {
        printf("%d -> ", temp->value);
        temp = temp->next;
    }
    printf("END\n");
}
