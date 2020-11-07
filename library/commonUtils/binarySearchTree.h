#ifndef SPBU_2020_C_HOMEWORKS_LIBRARY_COMMONUTILS_BINARYSEARCHTREE_H_
#define SPBU_2020_C_HOMEWORKS_LIBRARY_COMMONUTILS_BINARYSEARCHTREE_H_
#include <stdbool.h>

typedef struct BinarySearchTree BinarySearchTree;

BinarySearchTree* createTree();
void removeTree(BinarySearchTree* tree);

bool exists(BinarySearchTree* tree, int value);
bool addValueToAVL(BinarySearchTree* tree, int value);
bool removeValueFromAVL(BinarySearchTree* tree, int value);
bool addValueToBST(BinarySearchTree* tree, int value);
bool removeValueFromBST(BinarySearchTree* tree, int value);

void printAscending(BinarySearchTree* tree);
void printDescending(BinarySearchTree* tree);
void printInSpecialForm(BinarySearchTree* tree);

#endif // SPBU_2020_C_HOMEWORKS_LIBRARY_COMMONUTILS_BINARYSEARCHTREE_H_
