#include "../library/commonUtils/stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* getString()
{
    int size = 1;
    int i = 0;
    char* string = (char*)malloc(sizeof(char));
    char element = getchar();
    while (element != '\n') {
        if (size == i) {
            size *= 2;
            string = (char*)realloc(string, size);
        }
        string[i] = element;
        element = getchar();
        ++i;
    }
    string[i] = '\0';
    return string;
}

int determineSign(char* subString)
{
    if (*subString == '+') {
        return 1;
    } else if (*subString == '-') {
        return 2;
    } else if (*subString == '*') {
        return 3;
    } else if (*subString == '/') {
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
        deleteStruct(stack);
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