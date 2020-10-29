#include "binarySearchTree.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct BinaryTreeNode {
    int value;
    struct BinaryTreeNode* leftChild;
    struct BinaryTreeNode* rightChild;
} BinaryTreeNode;

struct BinarySearchTree {
    struct BinaryTreeNode* root;
};

enum Direction { left,
    right,
    none };

BinarySearchTree* createTree()
{
    BinarySearchTree* newTree = (BinarySearchTree*)malloc(sizeof(BinarySearchTree));
    newTree->root = NULL;
    return newTree;
}

BinaryTreeNode* createNode(int value)
{
    BinaryTreeNode* node = (BinaryTreeNode*)malloc(sizeof(BinaryTreeNode));
    node->rightChild = NULL;
    node->leftChild = NULL;
    node->value = value;
    return node;
}

bool isLeaf(BinaryTreeNode* node)
{
    return node->leftChild == NULL && node->rightChild == NULL;
}

bool isEmpty(BinarySearchTree* tree)
{
    return (tree->root == NULL);
}

bool changeParent(enum Direction direction, BinaryTreeNode* parent, BinarySearchTree* tree, BinaryTreeNode* newNode)
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

bool existsRecursive(BinaryTreeNode* node, int value)
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

bool exists(BinarySearchTree* tree, int value)
{
    if (isEmpty(tree)) {
        return false;
    }
    return existsRecursive(tree->root, value);
}

bool addValueRecursive(BinaryTreeNode* node, int value)
{
    if (node->value == value) {
        return false;
    }
    if (node->value > value) {
        if (node->leftChild == NULL) {
            node->leftChild = createNode(value);
            return true;
        } else
            return addValueRecursive(node->leftChild, value);
    }
    if (node->value < value) {
        if (node->rightChild == NULL) {
            node->rightChild = createNode(value);
            return true;
        } else
            return addValueRecursive(node->rightChild, value);
    }
}

bool addValue(BinarySearchTree* tree, int value)
{
    if (isEmpty(tree)) {
        tree->root = createNode(value);
    }
    return addValueRecursive(tree->root, value);
}

bool removeRecursive(BinarySearchTree* tree, BinaryTreeNode* node, int value, BinaryTreeNode* parent, enum Direction direction)
{
    if (node->value == value) {
        if (isLeaf(node)) {
            free(node);
            changeParent(direction, parent, tree, NULL);
            return true;
        }
        if (node->leftChild == NULL && node->rightChild != NULL) {
            changeParent(direction, parent, tree, node->rightChild);
            free(node);
            return true;
        }
        if (node->leftChild != NULL && node->rightChild == NULL) {
            changeParent(direction, parent, tree, node->leftChild);
            free(node);
            return true;
        }
        if (node->leftChild != NULL && node->rightChild != NULL) {
            BinaryTreeNode* minimumRightChild = node->rightChild;
            BinaryTreeNode* minimumRightChildParent = node;
            while (minimumRightChild->leftChild != NULL) {
                minimumRightChildParent = minimumRightChild;
                minimumRightChild = minimumRightChild->leftChild;
            }
            minimumRightChild->leftChild = node->leftChild;
            minimumRightChildParent->leftChild = NULL;
            if (parent == NULL) {
                tree->root = minimumRightChild;
            } else {
                changeParent(direction, parent, tree, minimumRightChild);
            }
            free(node);
            return true;
        }
    }
    if (node->value > value && node->leftChild != NULL) {
        return removeRecursive(tree, node->leftChild, value, node, left);
    }
    if (node->value < value && node->rightChild != NULL) {
        return removeRecursive(tree, node->rightChild, value, node, right);
    }
    return false;
}

bool removeValue(BinarySearchTree* tree, int value)
{
    if (isEmpty(tree)) {
        return false;
    }
    return removeRecursive(tree, tree->root, value, NULL, none);
}

void removeTreeRecursive(BinaryTreeNode* node, BinaryTreeNode* parent, enum Direction d, BinarySearchTree* tree)
{
    if (node == NULL) {
        return;
    }
    if (isLeaf(node)) {
        changeParent(d, parent, tree, NULL);
        free(node);
        return;
    }
    removeTreeRecursive(node->leftChild, node, left, tree);
    removeTreeRecursive(node->rightChild, node, right, tree);
    changeParent(d, parent, tree, NULL);
    free(node);
}

void removeTree(BinarySearchTree* tree)
{
    if (tree != NULL) {
        removeTreeRecursive(tree->root->leftChild, tree->root, left, tree);
        removeTreeRecursive(tree->root->rightChild, tree->root, right, tree);
        free(tree->root);
        tree->root = NULL;
        free(tree);
    }
}

void printAscendingRecursive(BinaryTreeNode* node)
{
    if (node == NULL)
        return;

    printAscendingRecursive(node->leftChild);
    printf("%d, ", node->value);
    printAscendingRecursive(node->rightChild);
}

void printAscending(BinarySearchTree* tree)
{
    printf("\n Here's your tree: ");
    if (tree != NULL) {
        printAscendingRecursive(tree->root);
    }
}

void printInDescendingRecursive(BinaryTreeNode* node)
{
    if (node == NULL) {
        return;
    }
    printInDescendingRecursive(node->rightChild);
    printf("%d, ", node->value);
    printInDescendingRecursive(node->leftChild);
}

void printInDescending(BinarySearchTree* tree)
{
    printf("\n Here's your tree: ");
    if (tree != NULL) {
        printInDescendingRecursive(tree->root);
    }
}

void printInSpecialFormRecursive(BinarySearchTree* tree, BinaryTreeNode* node)
{
    if (node != NULL) {
        printf("(");
        if (node->leftChild == NULL && node->rightChild == NULL) {
            printf(" %d null null ", node->value);
        } else if (node->leftChild == NULL) {
            printf(" %d null ", node->value);
            printInSpecialFormRecursive(tree, node->rightChild);
        } else if (node->rightChild == NULL) {
            printf(" %d ", node->value);
            printInSpecialFormRecursive(tree, node->leftChild);
            printf(" null ");
        } else {
            printf(" %d ", node->value);
            printInSpecialFormRecursive(tree, node->leftChild);
            printInSpecialFormRecursive(tree, node->rightChild);
        }
        printf(")");
    }
}

void printInSpecialForm(BinarySearchTree* tree)
{
    printf("\n Here's your tree: ");
    printInSpecialFormRecursive(tree, tree->root);
}
