#ifndef SPBU_2020_C_HOMEWORKS_LIBRARY_COMMONUTILS_HASHTABLE_H_
#define SPBU_2020_C_HOMEWORKS_LIBRARY_COMMONUTILS_HASHTABLE_H_
#include <stdbool.h>

typedef struct HashTable HashTable;

HashTable* createHashTable(int polynomFactor);

int getHash(char* key, int polynomFactor, int module);

void getMaximumInsertAttempts(HashTable* table);
int getElementCount(HashTable* table);
int getBucketCount(HashTable* table);
int getWordAmount(HashTable* table);
float getLoadFactor(HashTable* table);
float getAverageNumberOfAttempts(HashTable* table);

bool pushElement(HashTable* table, char* key, int amount, int insertionAttempts);
bool getWordCount(HashTable* table, char* key);

void destroyHashTable(HashTable* table);
void printListOfMostCommonWords(HashTable* table);

#endif // SPBU_2020_C_HOMEWORKS_LIBRARY_COMMONUTILS_HASHTABLE_H_
