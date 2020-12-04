#ifndef __DFA_H__
#define __DFA_H__
#include <stdbool.h>

typedef struct DFAState DFAState;
typedef struct DFA DFA;

DFA* createDFA(DFAState* initialState);
void removeDFA(DFA* dfa);

DFAState* createDFAState(bool isFinal);
void removeDFAState(DFAState* dfaState);

void addTransition(DFAState* firstState, char value, DFAState* secondState);

bool isStringCorrect(char* string, DFA* dfa);

#endif
