#ifndef SPBU_2020_C_HOMEWORKS_LIBRARY_COMMONUTILS_BINARYSEARCHANDAVLTREE_H_
#define SPBU_2020_C_HOMEWORKS_LIBRARY_COMMONUTILS_BINARYSEARCHANDAVLTREE_H_
#include <stdbool.h>

typedef struct BinarySearchTree BinarySearchTree;

BinarySearchTree* createTree();
void removeTree(BinarySearchTree* tree);

bool exists(BinarySearchTree* tree, int value);
bool addValue(BinarySearchTree* tree, int value);
bool removeValue(BinarySearchTree* tree, int value);

void printAscending(BinarySearchTree* tree);
void printDescending(BinarySearchTree* tree);
void printInSpecialForm(BinarySearchTree* tree);

#endif // SPBU_2020_C_HOMEWORKS_LIBRARY_COMMONUTILS_BINARYSEARCHANDAVLTREE_H_
