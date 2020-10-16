#include "../library/commonUtils/stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* getString()
{
    int size = 1;
    char* string = (char*)malloc(sizeof(char));
    char element = getchar();
    while (element != '\n') {
        string[size - 1] = element;
        ++size;
        string = (char*)realloc(string, size);
        element = getchar();
    }
    string[size - 1] = '\0';
    return string;
}

int determineSign(char* subString)
{
    if (strcmp(subString, "+") == 0) {
        return 1;
    } else if (strcmp(subString, "-") == 0) {
        return 2;
    } else if (strcmp(subString, "*") == 0) {
        return 3;
    } else if (strcmp(subString, "/") == 0) {
        return 4;
    }
    return 0;
}

int postfixCalculator(char* string)
{
    Stack* stack = createStack(NULL);
    char* subString = strtok(string, " ");
    while (subString != NULL) {
        int sign = determineSign(subString);
        if (sign == 0) {
            addNewStackElement(stack, subString);
        } else {
            perfomOperation(stack, sign);
        }

        subString = strtok(NULL, " ");
    }

    if (getQuantity(stack) != 1) {
        printf("Invalid input");
        exit(0);
    }

    int result = getHeadValue(stack);
    deleteStruct(stack);
    return result;
}

int main()
{
    printf("Enter a postfix expression:\nExample: (5 5 + 10 * 10 /):\n");
    char* string = getString();
    int value = postfixCalculator(string);
    printf("Result = %i\n", value);
    free(string);
    return 0;
}