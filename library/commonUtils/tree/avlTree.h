#ifndef SPBU_2020_C_HOMEWORKS_AVLTREE_H
#define SPBU_2020_C_HOMEWORKS_AVLTREE_H
#include <stdbool.h>

typedef struct AvlTree AvlTree;

AvlTree* createAvlTree();
void removeAvl(AvlTree* tree);

bool existsAvl(AvlTree* tree, int value);

bool addValueToAVL(AvlTree* tree, int value);
bool removeValueFromAVL(AvlTree* tree, int value);

void printAscendingAvl(AvlTree* tree);
void printDescendingAvl(AvlTree* tree);
void printAvlInSpecialForm(AvlTree* tree);

#endif //SPBU_2020_C_HOMEWORKS_AVLTREE_H
