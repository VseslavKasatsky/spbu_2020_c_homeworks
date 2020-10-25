#ifndef SPBU_2020_C_HOMEWORKS_LIBRARY_COMMONUTILS_BINARYSEARCHTREE_H_
#define SPBU_2020_C_HOMEWORKS_LIBRARY_COMMONUTILS_BINARYSEARCHTREE_H_
#include <stdbool.h>

typedef struct BinaryTreeNode BinaryTreeNode;
typedef struct BinarySearchTree BinarySearchTree;

BinarySearchTree* createTree();
void removeTree(BinarySearchTree* tree);

bool exists(BinarySearchTree* tree, int value);
bool addValue(BinarySearchTree* tree, int value);
bool removeValue(BinarySearchTree* tree, int value);

void printSymmetrical(BinarySearchTree* tree);
void printInDescending(BinarySearchTree* tree);
void printInSpecialForm(BinarySearchTree* tree);

#endif // SPBU_2020_C_HOMEWORKS_LIBRARY_COMMONUTILS_BINARYSEARCHTREE_H_
