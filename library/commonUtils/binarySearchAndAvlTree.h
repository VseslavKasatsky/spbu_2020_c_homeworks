#ifndef SPBU_2020_C_HOMEWORKS_LIBRARY_COMMONUTILS_BINARYSEARCHANDAVLTREE_H_
#define SPBU_2020_C_HOMEWORKS_LIBRARY_COMMONUTILS_BINARYSEARCHANDAVLTREE_H_
#include <stdbool.h>

typedef struct BinarySearchTree BinarySearchTree;

BinarySearchTree* createBinarySearchTree();
void removeBinarySearchTree(BinarySearchTree* tree);

bool existsBst(BinarySearchTree* tree, int value);

bool addValueToBST(BinarySearchTree* tree, int value);
bool removeValueFromBST(BinarySearchTree* tree, int value);

void printAscendingBst(BinarySearchTree* tree);
void printDescendingBst(BinarySearchTree* tree);
void printBstInSpecialForm(BinarySearchTree* tree);

typedef struct AvlTree AvlTree;

AvlTree* createAvlTree();
void removeAvl(AvlTree* tree);

bool existsAvl(AvlTree* tree, int value);

bool addValueToAVL(AvlTree* tree, int value);
bool removeValueFromAVL(AvlTree* tree, int value);

void printAscendingAvl(AvlTree* tree);
void printDescendingAvl(AvlTree* tree);
void printAvlInSpecialForm(AvlTree* tree);

#endif // SPBU_2020_C_HOMEWORKS_LIBRARY_COMMONUTILS_BINARYSEARCHANDAVLTREE_H_
