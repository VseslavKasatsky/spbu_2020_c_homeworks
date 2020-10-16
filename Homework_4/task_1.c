#include "../library/commonUtils/stack.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int main()
{
    printf("Enter a postfix expression:\nExample: (5 5 + 10 * 10 /):\n");
    char* string = getLine();
   // int value = postfixCalculator(string);
 //   printf("Result = %i\n", value);
    free(string);
    return 0;
}