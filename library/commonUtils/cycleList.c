#include "cycleList.h"
#include <stdio.h>
#include <stdlib.h>
struct CycleListElement {
    struct CycleListElement* left;
    struct CycleListElement* right;
    int number;
};

struct CycleList {
    CycleListElement* actual;
};

CycleList* createCycleList()
{
    CycleList* cycleList = malloc(sizeof(CycleList));
    cycleList->actual = NULL;
    return cycleList;
}
CycleListElement* createCycleListElement()
{
    CycleListElement* element = malloc(sizeof(CycleListElement));
    element->number = 0;
    element->left = NULL;
    element->right = NULL;

    return element;
}
void addCycleListElement(int number, CycleList* cycleList)
{
    CycleListElement* element = createCycleListElement();
    element->number = number;
    if (cycleList->actual == NULL) {
        cycleList->actual = element;
        element->left = element;
        element->right = element;
        return;
    }
    CycleListElement* left = cycleList->actual->left;
    element->left = left;
    left->right = element;
    cycleList->actual->left = element;
    element->right = cycleList->actual;
}
void printCycleList(CycleList* cycleList, int lastNumber)
{
    printf("Start-> ");
    CycleListElement* temporary = cycleList->actual;
    printf("%d->", cycleList->actual->number);
    while (temporary->number != lastNumber) {
        temporary = temporary->right;
        printf("%d", temporary->number);
        printf("->");
    }
    printf(" END \n");
    free(temporary);
}
void nextCycleListElement(CycleList* cycleList)
{
    cycleList->actual = cycleList->actual->right;
}
void deleteCycleListElement(CycleList* cycleList)
{
    CycleListElement* temporary = cycleList->actual;
    temporary->left->right = temporary->right;
    temporary->right->left = temporary->left;
    cycleList->actual = cycleList->actual->right;
    free(temporary);
}
int getLastNumber(CycleList* cycleList)
{
    return cycleList->actual->number;
}
void removeCycleList(CycleList* cycleList)
{
    free(cycleList->actual);
    free(cycleList);
}