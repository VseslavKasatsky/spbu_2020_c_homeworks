#include "binarySearchTree.h"
#include "binarySearchInterior.h"
#include <stdio.h>
#include <stdlib.h>

struct BinarySearchTree {
    struct TreeNode* root;
};

BinarySearchTree* createBinarySearchTree()
{
    BinarySearchTree* newTree = (BinarySearchTree*)malloc(sizeof(BinarySearchTree));
    newTree->root = NULL;
    return newTree;
}

bool isEmptyBst(BinarySearchTree* tree)
{
    return (tree->root == NULL);
}

bool changeParent(BinarySearchTree* tree, TreeNode* parent, TreeNode* newNode, enum Direction direction)
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

bool existsBst(BinarySearchTree* tree, int value)
{
    if (isEmptyBst(tree)) {
        return false;
    }
    return existsRecursive(tree->root, value);
}

bool addValueToBst(BinarySearchTree* tree, int value)
{
    if (isEmptyBst(tree)) {
        tree->root = createNode(value);
        return true;
    }
    if (addValueRecursive(tree->root, value)) {
        return true;
    }
    return false;
}

bool removeRecursiveBst(BinarySearchTree* tree, TreeNode* node,
    TreeNode* parent, int value, enum Direction direction)
{
    if (node->value == value) {
        if (isLeaf(node)) {
            if (parent != NULL) {
                changeParent(tree, parent, NULL, direction);
            } else {
                tree->root = NULL;
            }
        } else if (node->leftChild == NULL && node->rightChild != NULL) {
            changeParent(tree, parent, node->rightChild, direction);
        } else if (node->leftChild != NULL && node->rightChild == NULL) {
            changeParent(tree, parent, node->leftChild, direction);
        } else if (node->leftChild != NULL && node->rightChild != NULL) {
            if (node->rightChild->leftChild == NULL) {
                changeParent(tree, parent, node->rightChild, direction);
                node->rightChild->leftChild = node->leftChild;
            } else {
                TreeNode* minimumRightChild = node->rightChild;
                TreeNode* minimumRightChildParent = node;
                while (minimumRightChild->leftChild != NULL) {
                    minimumRightChildParent = minimumRightChild;
                    minimumRightChild = minimumRightChild->leftChild;
                }
                changeParent(tree, parent, minimumRightChild, direction);
                changeParent(tree, minimumRightChildParent,
                    minimumRightChild->rightChild, left);
                minimumRightChild->leftChild = node->leftChild;
                minimumRightChild->rightChild = node->rightChild;
            }
        }
        free(node);
        return true;
    }
    if (node->value > value && node->leftChild != NULL) {
        return removeRecursiveBst(tree, node->leftChild, node, value, left);
    }
    if (node->value < value && node->rightChild != NULL) {
        return removeRecursiveBst(tree, node->rightChild, node, value, right);
    }
    return false;
}

bool removeValueFromBst(BinarySearchTree* tree, int value)
{
    if (isEmptyBst(tree)) {
        return false;
    }
    if (removeRecursiveBst(tree, tree->root, NULL, value, none)) {
        return true;
    }
    return false;
}

void removeBinarySearchTreeRecursive(BinarySearchTree* tree, TreeNode* node,
    TreeNode* parent,
    enum Direction direction)
{
    if (node == NULL) {
        return;
    }
    if (isLeaf(node)) {
        changeParent(tree, parent, NULL, direction);
        free(node);
        return;
    }
    removeBinarySearchTreeRecursive(tree, node->leftChild, node, left);
    removeBinarySearchTreeRecursive(tree, node->rightChild, node, right);
    changeParent(tree, parent, NULL, direction);
    free(node);
}

void removeBinarySearchTree(BinarySearchTree* tree)
{
    if (tree != NULL) {
        if (tree->root != NULL) {
            removeBinarySearchTreeRecursive(tree, tree->root->leftChild, tree->root,
                left);
            removeBinarySearchTreeRecursive(tree, tree->root->rightChild, tree->root,
                right);
            free(tree->root);
        }
        tree->root = NULL;
        free(tree);
    }
}

void printAscendingBst(BinarySearchTree* tree)
{
    printf("\n Here's your tree: ");
    if (tree != NULL) {
        printAscendingRecursive(tree->root);
    }
}

void printDescendingBst(BinarySearchTree* tree)
{
    printf("\n Here's your tree: ");
    if (tree != NULL) {
        printInDescendingRecursive(tree->root);
    }
}

void printBstInSpecialFormRecursive(BinarySearchTree* tree, TreeNode* node)
{
    if (node != NULL) {
        printf("(");
        if (node->leftChild == NULL && node->rightChild == NULL) {
            printf(" %d null null ", node->value);
        } else if (node->leftChild == NULL) {
            printf(" %d null ", node->value);
            printBstInSpecialFormRecursive(tree, node->rightChild);
        } else if (node->rightChild == NULL) {
            printf(" %d ", node->value);
            printBstInSpecialFormRecursive(tree, node->leftChild);
            printf(" null ");
        } else {
            printf(" %d ", node->value);
            printBstInSpecialFormRecursive(tree, node->leftChild);
            printBstInSpecialFormRecursive(tree, node->rightChild);
        }
        printf(")");
    }
}

void printBstInSpecialForm(BinarySearchTree* tree)
{
    printf("\n Here's your tree: ");
    printBstInSpecialFormRecursive(tree, tree->root);
}
