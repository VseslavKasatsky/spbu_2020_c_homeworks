#ifndef SPBU_2020_C_HOMEWORKS_LIBRARY_COMMONUTILS_BINARYSEARCHTREE_H_
#define SPBU_2020_C_HOMEWORKS_LIBRARY_COMMONUTILS_BINARYSEARCHTREE_H_
#include <stdbool.h>

typedef struct BinarySearchTree BinarySearchTree;

BinarySearchTree* createBinarySearchTree();
void removeBinarySearchTree(BinarySearchTree* tree);

bool existsBst(BinarySearchTree* tree, int value);

bool addValueToBst(BinarySearchTree* tree, int value);
bool removeValueFromBst(BinarySearchTree* tree, int value);

void printAscendingBst(BinarySearchTree* tree);
void printDescendingBst(BinarySearchTree* tree);
void printBstInSpecialForm(BinarySearchTree* tree);

#endif // SPBU_2020_C_HOMEWORKS_LIBRARY_COMMONUTILS_BINARYSEARCHTREE_H_
