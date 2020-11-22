#include "../library/commonUtils/tree/avlTree.h"
#include "../library/commonUtils/tree/binarySearchTree.h"
#include <stdbool.h>
#include <stdio.h>

void printSelectionMenu()
{
    printf("\n Enter what you want to do\n");
    printf("0 - EXIT\n");
    printf("1 - add element to tree\n");
    printf("2 - remove element from tree\n");
    printf("3 - check if a value exists in the tree\n");
    printf("4 - print ascending\n");
    printf("5 - print descending\n");
    printf("6 - print in special form\n");
}

bool executeRequestBst(BinarySearchTree* tree)
{
    int command = -1;
    scanf("%d", &command);
    switch (command) {
    case 0: {
        removeBinarySearchTree(tree);
        return false;
    }
    case 1: {
        printf("Enter number: ");
        int number = 0;
        scanf("%d", &number);
        addValueToBst(tree, number);
        break;
    }
    case 2: {
        printf("Enter number: ");
        int number = 0;
        scanf("%d", &number);
        removeValueFromBst(tree, number);
        break;
    }
    case 3: {
        printf("Enter number: ");
        int number = 0;
        scanf("%d", &number);
        printf("Is there a number %d - ", number);
        printf(existsBst(tree, number) ? "true" : "false");
        break;
    }
    case 4: {
        printAscendingBst(tree);
        break;
    }
    case 5: {
        printDescendingBst(tree);
        break;
    }
    case 6: {
        printBstInSpecialForm(tree);
        break;
    }
    default: {
        printf("It's not a command \n Try again!");
        break;
    }
    }
    return true;
}

bool executeRequestAvl(AvlTree* tree)
{
    int command = -1;
    scanf("%d", &command);
    switch (command) {
    case 0: {
        removeAvl(tree);
        return false;
    }
    case 1: {
        printf("Enter number: ");
        int number = 0;
        scanf("%d", &number);
        addValueToAVL(tree, number);
        break;
    }
    case 2: {
        printf("Enter number: ");
        int number = 0;
        scanf("%d", &number);
        removeValueFromAVL(tree, number);
        break;
    }
    case 3: {
        printf("Enter number: ");
        int number = 0;
        scanf("%d", &number);
        printf("Is there a number %d - ", number);
        printf(existsAvl(tree, number) ? "true" : "false");
        break;
    }
    case 4: {
        printAscendingAvl(tree);
        break;
    }
    case 5: {
        printDescendingAvl(tree);
        break;
    }
    case 6: {
        printAvlInSpecialForm(tree);
        break;
    }
    default: {
        printf("It's not a command \n Try again!");
        break;
    }
    }
    return true;
}

int main()
{
    bool request = true;
    printf("What type of tree do you want to create \n 1 - Bst, 2 - Avl \n Enter "
           "value: ");
    int treeType = 0;
    scanf("%d", &treeType);
    while (treeType < 1 || treeType > 2) {
        printf("Invalid type.\n Enter 1 - to create Bst, 2 - to create Avl \n "
               "Enter value: ");
        scanf("%d", &treeType);
    }
    if (treeType == 1) {
        BinarySearchTree* binarySearchTree = createBinarySearchTree();
        while (request) {
            printSelectionMenu();
            request = executeRequestBst(binarySearchTree);
        }
    } else {
        AvlTree* avlTree = createAvlTree();
        while (request) {
            printSelectionMenu();
            request = executeRequestAvl(avlTree);
        }
    }
    printf("\n All done!");
    return 0;
}
