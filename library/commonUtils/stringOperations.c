#include "stringOperations.h"
#include <stdio.h>
#include <stdlib.h>

char* getString()
{
    int size = 1;
    char* word = (char*)malloc(size * sizeof(char));
    char buffer = '0';
    printf("Enter the expression: ");
    scanf("%c", &buffer);
    int index = 0;
    while (buffer != '\n' && buffer != '\0') {
        word[index] = buffer;
        scanf("%c", &buffer);
        ++index;
        if (size == index) {
            size = size * 2;
            word = (char*)realloc(word, size * sizeof(char));
        }
    }
    word[index] = '\0';
    return word;
}
