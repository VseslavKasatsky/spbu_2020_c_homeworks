#include "../library/commonUtils/dfa.h"
#include "../library/commonUtils/stringOperations.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

void initializeStatesAndPushTransitions(DFAState** states)
{
    DFAState* initialState = createDFAState(false);
    states[0] = initialState;
    DFAState* leftSymbols = createDFAState(false);
    states[1] = leftSymbols;
    DFAState* atSymbol = createDFAState(false);
    states[2] = atSymbol;
    DFAState* rightSymbols = createDFAState(false);
    states[3] = rightSymbols;
    DFAState* dot = createDFAState(false);
    states[4] = dot;
    DFAState* endSymbols = createDFAState(true);
    states[5] = endSymbols;

    for (char symbol = 'A'; (int)symbol <= (int)'Z'; ++symbol) {
        addTransition(initialState, symbol, leftSymbols);
        addTransition(leftSymbols, symbol, leftSymbols);
    }
    for (char digitSymbol = '0'; (int)digitSymbol <= (int)'9'; ++digitSymbol) {
        addTransition(initialState, digitSymbol, leftSymbols);
        addTransition(leftSymbols, digitSymbol, leftSymbols);
    }
    addTransition(initialState, '%', leftSymbols);
    addTransition(initialState, '+', leftSymbols);
    addTransition(initialState, '-', leftSymbols);
    addTransition(initialState, '.', leftSymbols);
    addTransition(leftSymbols, '%', leftSymbols);
    addTransition(leftSymbols, '+', leftSymbols);
    addTransition(leftSymbols, '-', leftSymbols);
    addTransition(leftSymbols, '.', leftSymbols);
    addTransition(leftSymbols, '@', atSymbol);

    for (char symbol = 'A'; (int)symbol <= (int)'Z'; ++symbol) {
        addTransition(atSymbol, symbol, rightSymbols);
        addTransition(rightSymbols, symbol, rightSymbols);
    }
    for (char digitSymbol = '0'; (int)digitSymbol <= (int)'9'; ++digitSymbol) {
        addTransition(atSymbol, digitSymbol, rightSymbols);
        addTransition(rightSymbols, digitSymbol, rightSymbols);
    }
    addTransition(atSymbol, '-', rightSymbols);
    addTransition(rightSymbols, '-', rightSymbols);
    addTransition(rightSymbols, '.', dot);

    for (char symbol = 'A'; (int)symbol <= (int)'Z'; ++symbol) {
        addTransition(dot, symbol, endSymbols);
        addTransition(endSymbols, symbol, endSymbols);
    }
}

void destroyStates(DFAState** states, int statesAmount)
{
    for (int i = 0; i < statesAmount; ++i) {
        removeDFAState(states[i]);
    }
}

int main()
{
    int statesAmount = 6;
    char* expression = getString();

    DFAState** states = (DFAState**)malloc(statesAmount * sizeof(DFAState*));
    initializeStatesAndPushTransitions(states);
    DFA* dfa = createDFA(states[0]);

    printf("This expression is%s correct", isStringCorrect(expression, dfa) ? "" : " not");

    destroyStates(states, statesAmount);
    removeDFA(dfa);
    free(states);
    free(expression);
    return 0;
}