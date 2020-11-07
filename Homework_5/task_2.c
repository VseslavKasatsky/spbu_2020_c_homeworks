#include "../library/commonUtils/binarySearchTree.h"
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

bool executeRequest(BinarySearchTree* tree)
{
    int command = -1;
    scanf("%d", &command);
    switch (command) {
    case 0: {
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
        printf(exists(tree, number) ? "true" : "false");
        break;
    }
    case 4: {
        printAscending(tree);
        break;
    }
    case 5: {
        printDescending(tree);
        break;
    }
    case 6: {
        printInSpecialForm(tree);
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
    BinarySearchTree* tree = createTree();
    bool request = true;
    while (request) {
        printSelectionMenu();
        request = executeRequest(tree);
    }
    removeTree(tree);
    printf("\n All done!");
    return 0;
}
