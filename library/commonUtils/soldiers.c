#include "soldiers.h"
#include <stdio.h>
#include <stdlib.h>
struct Soldier {
    struct Soldier* left;
    struct Soldier* right;
    int number;
};

struct Brigade {
    Soldier* actual;
};

Brigade* createBrigade()
{
    Brigade* brigade = malloc(sizeof(Brigade));
    brigade->actual = NULL;
    return brigade;
}
Soldier* createSoldier()
{
    Soldier* soldier = malloc(sizeof(Soldier));
    soldier->number = 0;
    soldier->left = NULL;
    soldier->right = NULL;

    return soldier;
}
void addSoldier(int number, Brigade* brigade)
{
    Soldier* soldier = createSoldier();
    soldier->number = number;
    if (brigade->actual == NULL) {
        brigade->actual = soldier;
        soldier->left = soldier;
        soldier->right = soldier;
        return;
    }
    Soldier* left = brigade->actual->left;
    soldier->left = left;
    left->right = soldier;
    brigade->actual->left = soldier;
    soldier->right = brigade->actual;
}
void printBrigade(Brigade* brigade, int lastNumber)
{
    printf("Start-> ");
    Soldier* temp = brigade->actual;
    printf("%d->", brigade->actual->number);
    while (temp->number != lastNumber) {
        temp = temp->right;
        printf("%d", temp->number);
        printf("->");
    }
    printf(" END \n");
    free(temp);
}
void nextSoldier(Brigade* brigade)
{
    brigade->actual = brigade->actual->right;
}
void deleteSoldier(Brigade* brigade)
{
    Soldier* temp = brigade->actual;
    temp->left->right = temp->right;
    temp->right->left = temp->left;
    brigade->actual = brigade->actual->right;
    free(temp);
}
int getLastNumber(Brigade* brigade)
{
    return brigade->actual->number;
}
void removeBrigade(Brigade* brigade)
{
    free(brigade->actual);
    free(brigade);
}