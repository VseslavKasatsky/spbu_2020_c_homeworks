#include "binarySearchAndAvlTree.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct BinaryTreeNode {
    int value;
    int height;
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
    node->height = 0;
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

bool changeParent(BinarySearchTree* tree, BinaryTreeNode* parent, BinaryTreeNode* newNode, enum Direction direction)
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

int getHeight(BinaryTreeNode* node)
{
    return node == NULL ? 0 : node->height;
}

int getBalanceFactor(BinaryTreeNode* node)
{
    return getHeight(node->rightChild) - getHeight(node->leftChild);
}

void updateHeight(BinaryTreeNode* node)
{
    int heightLeft = getHeight(node->leftChild);
    int heightRight = getHeight(node->rightChild);
    node->height = (heightLeft > heightRight ? heightLeft : heightRight) + 1;
}

BinaryTreeNode* rotateLeft(BinaryTreeNode* root)
{
    BinaryTreeNode* pivot = root->rightChild;
    root->rightChild = pivot->leftChild;
    pivot->leftChild = root;
    updateHeight(root);
    updateHeight(pivot);
    return pivot;
}

BinaryTreeNode* rotateRight(BinaryTreeNode* root)
{
    BinaryTreeNode* pivot = root->leftChild;
    root->leftChild = pivot->rightChild;
    pivot->rightChild = root;
    updateHeight(root);
    updateHeight(pivot);
    return pivot;
}

BinaryTreeNode* balanceBranch(BinaryTreeNode* root)
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

BinaryTreeNode* balanceTree(BinaryTreeNode* node)
{
    if (isLeaf(node)) {
        node->height = 1;
        return node;
    }
    if (node->leftChild != NULL) {
        node->leftChild = balanceTree(node->leftChild);
    }
    if (node->rightChild != NULL) {
        node->rightChild = balanceTree(node->rightChild);
    }
    updateHeight(node);
    return balanceBranch(node);
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

bool addValueToAVL(BinarySearchTree* tree, int value)
{
    if (isEmpty(tree)) {
        tree->root = createNode(value);
        updateHeight(tree->root);
        return true;
    }
    if (addValueRecursive(tree->root, value)) {
        tree->root = balanceTree(tree->root);
        return true;
    }
    return false;
}

bool addValueToBST(BinarySearchTree* tree, int value)
{
    if (isEmpty(tree)) {
        tree->root = createNode(value);
        return true;
    }
    if (addValueRecursive(tree->root, value)) {
        return true;
    }
    return false;
}

bool removeRecursive(BinarySearchTree* tree, BinaryTreeNode* node, BinaryTreeNode* parent, int value, enum Direction direction)
{
    if (node->value == value) {
        if (isLeaf(node)) {
            changeParent(tree, parent, NULL, direction);
        } else if (node->leftChild == NULL && node->rightChild != NULL) {
            changeParent(tree, parent, node->rightChild, direction);
        } else if (node->leftChild != NULL && node->rightChild == NULL) {
            changeParent(tree, parent, node->leftChild, direction);
        } else if (node->leftChild != NULL && node->rightChild != NULL) {
            if (node->rightChild->leftChild == NULL) {
                changeParent(tree, parent, node->rightChild, direction);
                node->rightChild->leftChild = node->leftChild;
            } else {
                BinaryTreeNode* minimumRightChild = node->rightChild;
                BinaryTreeNode* minimumRightChildParent = node;
                while (minimumRightChild->leftChild != NULL) {
                    minimumRightChildParent = minimumRightChild;
                    minimumRightChild = minimumRightChild->leftChild;
                }
                changeParent(tree, parent, minimumRightChild, direction);
                changeParent(tree, minimumRightChildParent, minimumRightChild->rightChild, left);
                minimumRightChild->leftChild = node->leftChild;
                minimumRightChild->rightChild = node->rightChild;
            }
        }
        free(node);
        return true;
    }
    if (node->value > value && node->leftChild != NULL) {
        return removeRecursive(tree, node->leftChild, node, value, left);
    }
    if (node->value < value && node->rightChild != NULL) {
        return removeRecursive(tree, node->rightChild, node, value, right);
    }
    return false;
}

bool removeValueFromAVL(BinarySearchTree* tree, int value)
{
    if (isEmpty(tree)) {
        return false;
    }
    if (removeRecursive(tree, tree->root, NULL, value, none)) {
        tree->root = balanceTree(tree->root);
        return true;
    }
    return false;
}

bool removeValueFromBST(BinarySearchTree* tree, int value)
{
    if (isEmpty(tree)) {
        return false;
    }
    if (removeRecursive(tree, tree->root, NULL, value, none)) {
        return true;
    }
    return false;
}

void removeTreeRecursive(BinarySearchTree* tree, BinaryTreeNode* node, BinaryTreeNode* parent, enum Direction direction)
{
    if (node == NULL) {
        return;
    }
    if (isLeaf(node)) {
        changeParent(tree, parent, NULL, direction);
        free(node);
        return;
    }
    removeTreeRecursive(tree, node->leftChild, node, left);
    removeTreeRecursive(tree, node->rightChild, node, right);
    changeParent(tree, parent, NULL, direction);
    free(node);
}

void removeTree(BinarySearchTree* tree)
{
    if (tree != NULL) {
        removeTreeRecursive(tree, tree->root->leftChild, tree->root, left);
        removeTreeRecursive(tree, tree->root->rightChild, tree->root, right);
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

void printDescending(BinarySearchTree* tree)
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
