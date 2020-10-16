#include "stack.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

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

int getHeadValue(Stack* stack)
{
    return stack->head->value;
}

int getHeadNextValue(Stack* stack)
{
    return stack->head->next->value;
}

int getQuantity(Stack* stack)
{
    return stack->quantity;
}

void perfomOperation(Stack* stack, int sign)
{
    int valueOne = getHeadValue(stack);
    int valueTwo = getHeadNextValue(stack);

    if (sign == 1) {
        stack->head->next->value = valueTwo + valueOne;
    } else if (sign == 2) {
        stack->head->next->value = valueTwo - valueOne;
    } else if (sign == 3) {
        stack->head->next->value = valueTwo * valueOne;
    } else if (sign == 4) {
        stack->head->next->value = valueTwo / valueOne;
    }

    StackElement* oldHead = stack->head;
    stack->head = stack->head->next;
    stack->quantity--;
    free(oldHead);
}