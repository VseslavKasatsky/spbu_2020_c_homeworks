#ifndef SPBU_2020_C_HOMEWORKS_BINARYSEARCHINTERIOR_H
#define SPBU_2020_C_HOMEWORKS_BINARYSEARCHINTERIOR_H
#include <stdbool.h>

typedef struct TreeNode {
    int value;
    int height;
    struct TreeNode* leftChild;
    struct TreeNode* rightChild;
} TreeNode;

enum Direction { left,
    right,
    none };

TreeNode* createNode(int value);

TreeNode* rotateLeft(TreeNode* root);
TreeNode* rotateRight(TreeNode* root);
TreeNode* balanceBranch(TreeNode* root);
TreeNode* balanceTree(TreeNode* node);

bool isLeaf(TreeNode* node);
bool existsRecursive(TreeNode* node, int value);
bool addValueRecursive(TreeNode* node, int value);

int getHeight(TreeNode* node);
int getBalanceFactor(TreeNode* node);

void updateHeight(TreeNode* node);
void printAscendingRecursive(TreeNode* node);
void printInDescendingRecursive(TreeNode* node);

#endif // SPBU_2020_C_HOMEWORKS_BINARYSEARCHINTERIOR_H
