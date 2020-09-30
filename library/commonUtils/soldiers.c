#include "soldiers.h"
#include <stdio.h>
#include <stdlib.h>
struct Soldier {
    struct ListElement* left;
    struct ListElement* right;
    int number;
};

struct Troop {
    Soldier* current;
    Soldier* top;
};

Troop* createTroop()
{
    Troop* troop = malloc(sizeof(Troop));
    troop->top=NULL;
    return troop;
}
Soldier* createSoldier()
{
    Soldier* soldier = malloc(sizeof(Soldier));
    soldier->number = 0;
    soldier->left = NULL;
    soldier->right = NULL;

    return soldier;
}
void addSoldier(int number, Troop* troop)
{
    Soldier* soldier= createSoldier();
    soldier->number=number;
    if(troop->top=NULL)
    {
        troop->top=soldier;
        soldier->left=soldier;
        soldier->right=soldier;
        return;
    }
    soldier->left=troop->current;
    troop->current->left=soldier;
    soldier->right=troop->current;
    //nothing, цикл в прогрессе
}