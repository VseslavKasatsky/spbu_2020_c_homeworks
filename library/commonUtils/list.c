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
    if (isEmpty(list)) {
        element->previous = NULL;
        element->next = NULL;
        list->head = element;
        list->tail = element;
        ++list->size;
        return true;
    }
    if (position == 1) {
        list->head->previous = element;
        element->next = list->head;
        list->head = element;
        if (list->size == 1) {
            list->tail = element->next;
        }
        ++list->size;
        return true;
    }
    if (position - 1 == size(list)) {
        list->tail->next = element;
        element->previous = list->tail;
        list->tail = element;
        ++list->size;
        return true;
    }
    ListElement* temp = list->head;
    for (int i = 0; i < position - 1; ++i) {
        temp = temp->next;
    }
    temp->previous->next = element;
    element->previous = temp->previous;
    temp->previous = element;
    element->next = temp;
    ++list->size;
    return true;
}
int locate(ListElement* element, List* list)
{
    ListElement* temp = list->head;
    int position = 1;
    while (temp != element) {
        temp = temp->next;
        ++position;
    }
    return position;
}
ListElement* retrieve(int position, List* list)
{
    if (position > size(list)) {
        return false;
    }
    ListElement* temp = list->head;
    for (int i = 0; i < position; ++i) {
        temp = temp->next;
    }
    return temp->previous->value;
}
bool delete (int position, List* list)
{
    if (position > size(list)) {
        return false;
    }
    if (list->size == 1) {
        free(list->head);
        list->head = NULL;
        list->tail = NULL;
        --list->size;
        return true;
    }

    if (position == 1) {
        head(list)->next->previous = NULL;
        ListElement* temp = head(list);
        list->head = head(list)->next;
        free(temp);
        --list->size;
        return true;
    }

    if (position == size(list)) {
        list->tail->previous->next = NULL;
        ListElement* temp = list->tail;
        list->tail = list->tail->previous;
        free(temp);
        --list->size;
        return true;
    }
    ListElement* temp = list->head;
    for (int i = 0; i < position - 1; ++i) {
        temp = temp->next;
    }
    temp->previous->next = temp->next;
    temp->next->previous = temp->previous;
    free(temp);
    --list->size;
    return true;
}
void removeList(List* list)
{
    while (!isEmpty(list)) {
        delete (1, list);
    }
    free(list);
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
