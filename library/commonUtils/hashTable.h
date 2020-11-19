#ifndef SPBU_2020_C_HOMEWORKS_LIBRARY_COMMONUTILS_HASHTABLE_H_
#define SPBU_2020_C_HOMEWORKS_LIBRARY_COMMONUTILS_HASHTABLE_H_
#include <stdbool.h>

typedef struct HashTable HashTable;

HashTable* createHashTable(int polynomFactor, int (*getHash)(char*, int, int), int (*getIndex)(int, int, int));

void printMaximumInsertAttempts(HashTable* table);
void printElementCount(HashTable* table);
void printNumberOfEmptyCells(HashTable* table);
void printWordAmount(HashTable* table);
void printLoadFactor(HashTable* table);
void printAverageNumberOfAttempts(HashTable* table);

void printTableStatistic(HashTable* table);
void printListOfMostCommonWords(HashTable* table, int numberOfRepetitiveWords);

float getLoadFactor(HashTable* table);

void pushElement(HashTable* table, char* key, int amount);
bool removeElement(HashTable* table, char* key);

void destroyHashTable(HashTable* table);

#endif // SPBU_2020_C_HOMEWORKS_LIBRARY_COMMONUTILS_HASHTABLE_H_
