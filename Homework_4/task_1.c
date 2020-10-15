#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Cell {
    int item;
    struct Cell* next;
} Cell;

typedef struct Pointer {
    struct Cell* head;
    int quantity;
} Pointer;

Pointer* createNewStruct(void)
{
    Cell* cell = malloc(sizeof(Cell));
    Pointer* pointer = malloc(sizeof(Pointer));
    cell->item = 0;
    cell->next = NULL;
    pointer->quantity = 0;
    pointer->head = cell;
    return pointer;
}

char* getLine()
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

bool isEnd(Pointer* pointer)
{
    return pointer->head->next == NULL;
}

void deleteStruct(Pointer* pointer)
{
    while (!isEnd(pointer)) {
        Cell* oldHead = pointer->head;
        pointer->head = pointer->head->next;
        free(oldHead);
    }

    free(pointer->head);
    free(pointer);
}

void addNewItem(Pointer* pointer, char* inputItem)
{
    Cell* cell = malloc(sizeof(Cell));
    cell->item = atoi(inputItem);
    cell->next = pointer->head;
    pointer->head = cell;
    ++pointer->quantity;
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

void perfomOperation(Pointer* pointer, int sign)
{
    int valueOne = pointer->head->item;
    int valueTwo = pointer->head->next->item;

    if (sign == 1) {
        pointer->head->next->item = valueTwo + valueOne;
    } else

        if (sign == 2) {
        pointer->head->next->item = valueTwo - valueOne;
    } else

        if (sign == 3) {
        pointer->head->next->item = valueTwo * valueOne;
    } else

        if (sign == 4) {
        pointer->head->next->item = valueTwo / valueOne;
    }

    Cell* oldHead = pointer->head;
    pointer->head = pointer->head->next;
    --pointer->quantity;
    free(oldHead);
}

int postfixCalculator(char* string)
{
    Pointer* pointer = createNewStruct();
    char* subString = strtok(string, " ");
    while (subString != NULL) {
        int sign = determineSign(subString);
        if (sign == 0) {
            addNewItem(pointer, subString);
        } else {
            perfomOperation(pointer, sign);
        }

        subString = strtok(NULL, " ");
    }

    if (pointer->quantity != 1) {
        printf("Invalid input");
        exit(0);
    }

    int result = pointer->head->item;
    deleteStruct(pointer);
    return result;
}

int main()
{
    printf("Enter a postfix expression:\nExample: (5 5 + 10 * 10 /):\n");
    char* string = getLine();
    int value = postfixCalculator(string);
    printf("Result = %i\n", value);
    free(string);
    return 0;
}