#include "stack.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>

struct StackElement {
    int value;
    struct StackElement* next;
};

struct Stack {
    struct StackElement* head;
    int quantity;
};

Stack* createStack(StackElement* element)
{
    Stack* stack = malloc(sizeof(Stack));
    stack->quantity = 0;
    stack->head = element;
    return stack;
}

StackElement* createStackElement(int value)
{
    StackElement* stackElement = malloc(sizeof(StackElement));
    stackElement->value = value;
    stackElement->next = NULL;
    return stackElement;
}

bool isEnd(Stack* stack)
{
    return stack->head->next == NULL;
}
void addNewStackElement(Stack* stack, char* inputItem)
{
    StackElement* cell = createStackElement(atoi(inputItem));
    cell->next = stack->head;
    stack->head = cell;
    stack->quantity++;
}

void deleteStruct(Stack* stack)
{
    while (!isEnd(stack)) {
        StackElement* oldHead = stack->head;
        stack->head = stack->head->next;
        free(oldHead);
    }

    free(stack->head);
    free(stack);
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

void perfomOperation(Stack* stack, int sign)
{
    int valueOne = stack->head->value;
    int valueTwo = stack->head->next->value;

    if (sign == 1) {
        stack->head->next->value = valueTwo + valueOne;
    } else

        if (sign == 2) {
        stack->head->next->value = valueTwo - valueOne;
    } else

        if (sign == 3) {
        stack->head->next->value = valueTwo * valueOne;
    } else

        if (sign == 4) {
        stack->head->next->value = valueTwo / valueOne;
    }

    StackElement* oldHead = stack->head;
    stack->head = stack->head->next;
    --stack->quantity;
    free(oldHead);
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

    if (stack->quantity != 1) {
        printf("Invalid input");
        exit(0);
    }

    int result = stack->head->value;
    deleteStruct(stack);
    return result;
}
