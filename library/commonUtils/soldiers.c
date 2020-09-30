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
};

Troop* createTroop()
{
    Troop* troop = malloc(sizeof(Troop));
    troop->current = NULL;
    return troop;
}