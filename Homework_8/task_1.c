#include "../library/commonUtils/dfa.h"
#include <stdbool.h>
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

void initializeStatesAndPushTransitions(DFAState** states)
{
    DFAState* initialState = createDFAState(false);
    states[0] = initialState;
    DFAState* integerPartSign = createDFAState(false);
    states[1] = integerPartSign;
    DFAState* integerDigit = createDFAState(true);
    states[2] = integerDigit;
    DFAState* dot = createDFAState(false);
    states[3] = dot;
    DFAState* fractionalDigit = createDFAState(true);
    states[4] = fractionalDigit;
    DFAState* exponent = createDFAState(false);
    states[5] = exponent;
    DFAState* exponentSign = createDFAState(false);
    states[6] = exponentSign;
    DFAState* exponentDigit = createDFAState(true);
    states[7] = exponentDigit;

    addTransition(initialState, '+', integerPartSign);
    addTransition(initialState, '-', integerPartSign);
    addTransition(integerDigit, '.', dot);
    addTransition(integerDigit, 'E', exponent);
    addTransition(fractionalDigit, 'E', exponent);
    addTransition(exponent, '+', exponentSign);
    addTransition(exponent, '-', exponentSign);

    for (char digitSymbol = '0'; (int)digitSymbol <= (int)'9'; ++digitSymbol) {
        addTransition(integerPartSign, digitSymbol, integerDigit);
        addTransition(initialState, digitSymbol, integerDigit);
        addTransition(integerDigit, digitSymbol, integerDigit);
        addTransition(dot, digitSymbol, fractionalDigit);
        addTransition(fractionalDigit, digitSymbol, fractionalDigit);
        addTransition(exponentSign, digitSymbol, exponentDigit);
        addTransition(exponent, digitSymbol, exponentDigit);
        addTransition(exponentDigit, digitSymbol, exponentDigit);
    }
}

bool isNumber(char* expression, int statesAmount)
{
    DFAState** states = (DFAState**)malloc(statesAmount * sizeof(DFAState*));
    initializeStatesAndPushTransitions(states);
    DFA* dfa = createDFA(states[0]);
    bool isExpressionIsNumber = isStringCorrect(expression, dfa);

    for (int i = 0; i < statesAmount; ++i) {
        removeDFAState(states[i]);
    }
    removeDFA(dfa);
    free(states);

    return isExpressionIsNumber;
}

int main()
{
    int statesAmount = 8;
    char* expression = getString();
    printf("This expression is%s a number", isNumber(expression, statesAmount) ? "" : " not");

    free(expression);
    return 0;
}
