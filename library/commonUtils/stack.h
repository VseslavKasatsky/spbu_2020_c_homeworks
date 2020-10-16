#ifndef SPBU_2020_C_HOMEWORKS_LIBRARY_COMMONUTILS_STACK_H_
#define SPBU_2020_C_HOMEWORKS_LIBRARY_COMMONUTILS_STACK_H_
#include <stdbool.h>

typedef struct StackElement StackElement;
typedef struct Stack Stack;

Stack* createStack(StackElement* element);
StackElement* createStackElement(int value);

int determineSign(char* subString);
int postfixCalculator(char* string);

void deleteStruct(Stack* stack);
void addNewStackElement(Stack* stack, char* inputItem);
void perfomOperation(Stack* stack, int sign);

bool isEnd(Stack* stack);

#endif //SPBU_2020_C_HOMEWORKS_LIBRARY_COMMONUTILS_STACK_H_
