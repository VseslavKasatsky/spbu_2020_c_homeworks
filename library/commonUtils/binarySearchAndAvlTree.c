#include "binarySearchAndAvlTree.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode {
    int value;
    int height;
    struct TreeNode* leftChild;
    struct TreeNode* rightChild;
} TreeNode;

struct BinarySearchTree {
    struct TreeNode* root;
};

struct AvlTree {
    struct TreeNode* root;
};

enum Direction { left,
    right,
    none };

AvlTree* createAvlTree()
{
    AvlTree* newTree = (AvlTree*)malloc(sizeof(AvlTree));
    newTree->root = NULL;
    return newTree;
}

BinarySearchTree* createBinarySearchTree()
{
    BinarySearchTree* newTree = (BinarySearchTree*)malloc(sizeof(BinarySearchTree));
    newTree->root = NULL;
    return newTree;
}

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

bool isEmptyBst(BinarySearchTree* tree)
{
    return (tree->root == NULL);
}

bool isEmptyAvl(AvlTree* tree)
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

bool existsBst(BinarySearchTree* tree, int value)
{
    if (isEmptyBst(tree)) {
        return false;
    }
    return existsRecursive(tree->root, value);
}

bool existsAvl(AvlTree* tree, int value)
{
    if (isEmptyAvl(tree)) {
        return false;
    }
    return existsRecursive(tree->root, value);
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

bool addValueToBST(BinarySearchTree* tree, int value)
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

bool removeRecursiveBst(BinarySearchTree* tree, TreeNode* node, TreeNode* parent, int value, enum Direction direction)
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
                changeParent(tree, minimumRightChildParent, minimumRightChild->rightChild, left);
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

bool removeValueFromBST(BinarySearchTree* tree, int value)
{
    if (isEmptyBst(tree)) {
        return false;
    }
    if (removeRecursiveBst(tree, tree->root, NULL, value, none)) {
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

void removeBinarySearchTreeRecursive(BinarySearchTree* tree, TreeNode* node, TreeNode* parent, enum Direction direction)
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
            removeBinarySearchTreeRecursive(tree, tree->root->leftChild, tree->root, left);
            removeBinarySearchTreeRecursive(tree, tree->root->rightChild, tree->root, right);
            free(tree->root);
        }
        tree->root = NULL;
        free(tree);
    }
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

void printAscendingRecursive(TreeNode* node)
{
    if (node == NULL)
        return;

    printAscendingRecursive(node->leftChild);
    printf("%d, ", node->value);
    printAscendingRecursive(node->rightChild);
}

void printAscendingBst(BinarySearchTree* tree)
{
    printf("\n Here's your tree: ");
    if (tree != NULL) {
        printAscendingRecursive(tree->root);
    }
}

void printAscendingAvl(AvlTree* tree)
{
    printf("\n Here's your tree: ");
    if (tree != NULL) {
        printAscendingRecursive(tree->root);
    }
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

void printDescendingBst(BinarySearchTree* tree)
{
    printf("\n Here's your tree: ");
    if (tree != NULL) {
        printInDescendingRecursive(tree->root);
    }
}

void printDescendingAvl(AvlTree* tree)
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
