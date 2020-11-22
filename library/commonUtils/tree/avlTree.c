#include "avlTree.h"
#include "binarySearchInterior.h"
#include <stdio.h>
#include <stdlib.h>

struct AvlTree {
    struct TreeNode* root;
};

AvlTree* createAvlTree()
{
    AvlTree* newTree = (AvlTree*)malloc(sizeof(AvlTree));
    newTree->root = NULL;
    return newTree;
}

bool isEmptyAvl(AvlTree* tree)
{
    return (tree->root == NULL);
}

bool changeParentAvl(AvlTree* tree, TreeNode* parent, TreeNode* newNode, enum Direction direction)
{
    if (direction == left) {
        parent->leftChild = newNode;
    }
    if (direction == right) {
        parent->rightChild = newNode;
    }
    if (direction == none) {
        tree->root = newNode;
    }
    return true;
}

bool existsAvl(AvlTree* tree, int value)
{
    if (isEmptyAvl(tree)) {
        return false;
    }
    return existsRecursive(tree->root, value);
}

bool addValueToAVL(AvlTree* tree, int value)
{
    if (isEmptyAvl(tree)) {
        tree->root = createNode(value);
        tree->root->height = 1;
        return true;
    }
    if (addValueRecursive(tree->root, value)) {
        tree->root = balanceTree(tree->root);
        return true;
    }
    return false;
}

bool removeRecursiveAvl(AvlTree* tree, TreeNode* node, TreeNode* parent, int value, enum Direction direction)
{
    if (node->value == value) {
        if (isLeaf(node)) {
            if (parent != NULL) {
                changeParentAvl(tree, parent, NULL, direction);
            } else {
                tree->root = NULL;
            }
        } else if (node->leftChild == NULL && node->rightChild != NULL) {
            changeParentAvl(tree, parent, node->rightChild, direction);
        } else if (node->leftChild != NULL && node->rightChild == NULL) {
            changeParentAvl(tree, parent, node->leftChild, direction);
        } else if (node->leftChild != NULL && node->rightChild != NULL) {
            if (node->rightChild->leftChild == NULL) {
                changeParentAvl(tree, parent, node->rightChild, direction);
                node->rightChild->leftChild = node->leftChild;
            } else {
                TreeNode* minimumRightChild = node->rightChild;
                TreeNode* minimumRightChildParent = node;
                while (minimumRightChild->leftChild != NULL) {
                    minimumRightChildParent = minimumRightChild;
                    minimumRightChild = minimumRightChild->leftChild;
                }
                changeParentAvl(tree, parent, minimumRightChild, direction);
                changeParentAvl(tree, minimumRightChildParent, minimumRightChild->rightChild, left);
                minimumRightChild->leftChild = node->leftChild;
                minimumRightChild->rightChild = node->rightChild;
            }
        }
        free(node);
        return true;
    }
    if (node->value > value && node->leftChild != NULL) {
        return removeRecursiveAvl(tree, node->leftChild, node, value, left);
    }
    if (node->value < value && node->rightChild != NULL) {
        return removeRecursiveAvl(tree, node->rightChild, node, value, right);
    }
    return false;
}

bool removeValueFromAVL(AvlTree* tree, int value)
{
    if (isEmptyAvl(tree)) {
        return false;
    }
    if (removeRecursiveAvl(tree, tree->root, NULL, value, none)) {
        if (tree->root != NULL) {
            tree->root = balanceTree(tree->root);
        }
        return true;
    }
    return false;
}

void removeAvlRecursive(AvlTree* tree, TreeNode* node, TreeNode* parent, enum Direction direction)
{
    if (node == NULL) {
        return;
    }
    if (isLeaf(node)) {
        changeParentAvl(tree, parent, NULL, direction);
        free(node);
        return;
    }
    removeAvlRecursive(tree, node->leftChild, node, left);
    removeAvlRecursive(tree, node->rightChild, node, right);
    changeParentAvl(tree, parent, NULL, direction);
    free(node);
}

void removeAvl(AvlTree* tree)
{
    if (tree != NULL) {
        if (tree->root != NULL) {
            removeAvlRecursive(tree, tree->root->leftChild, tree->root, left);
            removeAvlRecursive(tree, tree->root->rightChild, tree->root, right);
            free(tree->root);
        }
        tree->root = NULL;
        free(tree);
    }
}

void printAscendingAvl(AvlTree* tree)
{
    printf("\n Here's your tree: ");
    if (tree != NULL) {
        printAscendingRecursive(tree->root);
    }
}

void printDescendingAvl(AvlTree* tree)
{
    printf("\n Here's your tree: ");
    if (tree != NULL) {
        printInDescendingRecursive(tree->root);
    }
}

void printAvlInSpecialFormRecursive(AvlTree* tree, TreeNode* node)
{
    if (node != NULL) {
        printf("(");
        if (node->leftChild == NULL && node->rightChild == NULL) {
            printf(" %d null null ", node->value);
        } else if (node->leftChild == NULL) {
            printf(" %d null ", node->value);
            printAvlInSpecialFormRecursive(tree, node->rightChild);
        } else if (node->rightChild == NULL) {
            printf(" %d ", node->value);
            printAvlInSpecialFormRecursive(tree, node->leftChild);
            printf(" null ");
        } else {
            printf(" %d ", node->value);
            printAvlInSpecialFormRecursive(tree, node->leftChild);
            printAvlInSpecialFormRecursive(tree, node->rightChild);
        }
        printf(")");
    }
}

void printAvlInSpecialForm(AvlTree* tree)
{
    printf("\n Here's your tree: ");
    printAvlInSpecialFormRecursive(tree, tree->root);
}
