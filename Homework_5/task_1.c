#include "../library/commonUtils/binarySearchTree.h"
#include <stdio.h>

int main()
{
    BinarySearchTree* tree = createTree();
    printf("Is there a number 4 - %d \n", exists(tree, 4));
    addValue(tree, 4);
    printf("Is there a number 4 - %d \n", exists(tree, 4));
    addValue(tree, 2);
    printf("Is there a number 2 - %d \n", exists(tree, 2));
    addValue(tree, 1);
    printf("Is there a number 1 - %d \n", exists(tree, 1));
    addValue(tree, 3);
    printf("Is there a number 3 - %d \n", exists(tree, 3));
    addValue(tree, 5);
    printf("Is there a number 5 - %d \n", exists(tree, 5));
    addValue(tree, 10);
    printf("Is there a number 10 - %d \n", exists(tree, 10));
    printf("Is there a number 15 - %d \n", exists(tree, 15));
    printf("Is there a number 7 - %d \n", exists(tree, 7));

    printAscending(tree);

    removeValue(tree, 4);

    printAscending(tree);
    printInDescending(tree);
    printInSpecialForm(tree);
    removeTree(tree);
    printf("\n All done!");
    return 0;
}
