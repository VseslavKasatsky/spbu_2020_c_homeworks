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
    ListElement* elem = malloc(sizeof(ListElement));
    elem->value = value;
    elem->next = NULL;
    return elem;
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
void printListHead(List* list)
{
    printf("HEAD -> ");
    ListElement* temp = list->head;
    printf("%d", temp->value);
    printf("\n");
}
void printListTail(List* list)
{
    printf("TAIL -> ");
    ListElement* temp = list->head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    printf("%d \n", temp->value);
}
ListElement* tail(List* list)
{
    return list->tail;
}
ListElement* head (List* list)
{
 return list->head;
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