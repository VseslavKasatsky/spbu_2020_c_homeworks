#include "binarySearchInterior.h"
#include <stdio.h>
#include <stdlib.h>

TreeNode* createNode(int value)
{
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->rightChild = NULL;
    node->leftChild = NULL;
    node->value = value;
    node->height = 0;
    return node;
}

bool isLeaf(TreeNode* node)
{
    return node->leftChild == NULL && node->rightChild == NULL;
}

bool existsRecursive(TreeNode* node, int value)
{
    if (node->value == value) {
        return true;
    }
    if (node->value > value && node->leftChild != NULL) {
        return existsRecursive(node->leftChild, value);
    }
    if (node->value < value && node->rightChild != NULL) {
        return existsRecursive(node->rightChild, value);
    }
    return false;
}

int getHeight(TreeNode* node)
{
    return node == NULL ? 0 : node->height;
}

int getBalanceFactor(TreeNode* node)
{
    return getHeight(node->rightChild) - getHeight(node->leftChild);
}

void updateHeight(TreeNode* node)
{
    int heightLeft = getHeight(node->leftChild);
    int heightRight = getHeight(node->rightChild);
    node->height = (heightLeft > heightRight ? heightLeft : heightRight) + 1;
}

TreeNode* rotateLeft(TreeNode* root)
{
    TreeNode* pivot = root->rightChild;
    root->rightChild = pivot->leftChild;
    pivot->leftChild = root;
    updateHeight(root);
    updateHeight(pivot);
    return pivot;
}

TreeNode* rotateRight(TreeNode* root)
{
    TreeNode* pivot = root->leftChild;
    root->leftChild = pivot->rightChild;
    pivot->rightChild = root;
    updateHeight(root);
    updateHeight(pivot);
    return pivot;
}

TreeNode* balanceBranch(TreeNode* root)
{
    if (getBalanceFactor(root) == 2) {
        if (getBalanceFactor(root->rightChild) < 0) {
            root->rightChild = rotateRight(root->rightChild);
        }
        return rotateLeft(root);
    }
    if (getBalanceFactor(root) == -2) {
        if (getBalanceFactor(root->leftChild) > 0) {
            root->leftChild = rotateLeft(root->leftChild);
        }
        return rotateRight(root);
    }
    return root;
}

TreeNode* balanceTree(TreeNode* node)
{
    if (isLeaf(node)) {
        node->height = 1;
        return node;
    }
    if (node->rightChild != NULL) {
        node->rightChild = balanceTree(node->rightChild);
    }
    if (node->leftChild != NULL) {
        node->leftChild = balanceTree(node->leftChild);
    }
    updateHeight(node);
    return balanceBranch(node);
}

bool addValueRecursive(TreeNode* node, int value)
{
    if (node->value == value) {
        return false;
    }
    if (node->value > value) {
        if (node->leftChild == NULL) {
            node->leftChild = createNode(value);
            return true;
        }
        return addValueRecursive(node->leftChild, value);
    } else {
        if (node->rightChild == NULL) {
            node->rightChild = createNode(value);
            return true;
        }
        return addValueRecursive(node->rightChild, value);
    }
}

void printAscendingRecursive(TreeNode* node)
{
    if (node == NULL)
        return;

    printAscendingRecursive(node->leftChild);
    printf("%d, ", node->value);
    printAscendingRecursive(node->rightChild);
}

void printInDescendingRecursive(TreeNode* node)
{
    if (node == NULL) {
        return;
    }
    printInDescendingRecursive(node->rightChild);
    printf("%d, ", node->value);
    printInDescendingRecursive(node->leftChild);
}
