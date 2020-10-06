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
    CycleList* troop = malloc(sizeof(CycleList));
    troop->actual = NULL;
    return troop;
}
CycleListElement* createCycleListElement()
{
    CycleListElement* soldier = malloc(sizeof(CycleListElement));
    soldier->number = 0;
    soldier->left = NULL;
    soldier->right = NULL;

    return soldier;
}
void addCycleListElement(int number, CycleList* cycleList)
{
    CycleListElement* soldier = createCycleListElement();
    soldier->number = number;
    if (cycleList->actual == NULL) {
        cycleList->actual = soldier;
        soldier->left = soldier;
        soldier->right = soldier;
        return;
    }
    CycleListElement* left = cycleList->actual->left;
    soldier->left = left;
    left->right = soldier;
    cycleList->actual->left = soldier;
    soldier->right = cycleList->actual;
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