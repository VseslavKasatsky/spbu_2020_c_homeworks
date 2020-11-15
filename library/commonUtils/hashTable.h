#ifndef SPBU_2020_C_HOMEWORKS_LIBRARY_COMMONUTILS_HASHTABLE_H_
#define SPBU_2020_C_HOMEWORKS_LIBRARY_COMMONUTILS_HASHTABLE_H_
#include <stdbool.h>

typedef struct HashTable HashTable;

HashTable* createHashTable(int polynomFactor);

int getHash(char* key, int polynomFactor, int module);

void printMaximumInsertAttempts(HashTable* table);
void printElementCount(HashTable* table);
void printNumberOfEmptyCells(HashTable* table);
void printWordAmount(HashTable* table);
void printLoadFactor(HashTable* table);
void printAverageNumberOfAttempts(HashTable* table);
void printTableStatistic(HashTable* table);

float getLoadFactor(HashTable* table);

void pushElement(HashTable* table, char* key, int amount);
bool removeElement(HashTable* table, char* key);

void destroyHashTable(HashTable* table);
void printListOfMostCommonWords(HashTable* table, int numberOfRepetitiveWords);

extern int getHashOutside(char* key, int polynomFactor, int module);
extern int getIndexOutside(int hash, int attempt, int module);
#endif // SPBU_2020_C_HOMEWORKS_LIBRARY_COMMONUTILS_HASHTABLE_H_
