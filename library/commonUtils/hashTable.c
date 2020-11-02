#include "hashTable.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum CellType { empty,
    used };

typedef struct HashElement {
    char* key;
    int amount;
    int insertionAttempts;
} HashElement;

struct HashTable {
    HashElement** hashTable;
    enum CellType* types;
    int bucketCount;
    int elementCount;
    int polynomFactor;
};

const float maxLoadFactor = 0.7;

float getLoadFactor(HashTable* table)
{
    return (float)table->elementCount / (float)table->bucketCount;
}

float getAverageNumberOfAttempts(HashTable* table)
{
    int sumOfInsertAttempts = 0;
    for (int i = 0; i < table->bucketCount; ++i) {
        if (table->types[i] == used) {
            sumOfInsertAttempts += table->hashTable[i]->insertionAttempts;
        }
    }
    return (float)sumOfInsertAttempts / (float)table->elementCount;
}

void getMaximumInsertAttempts(HashTable* table)
{
    int maximumInsertAttempts = 0;
    for (int i = 0; i < table->bucketCount; ++i) {
        if (table->types[i] == used && table->hashTable[i]->insertionAttempts > maximumInsertAttempts) {
            maximumInsertAttempts = table->hashTable[i]->insertionAttempts;
        }
    }
    for (int i = 0; i < table->bucketCount; ++i) {
        if (table->types[i] == used && table->hashTable[i]->insertionAttempts == maximumInsertAttempts)
            printf("The word w/ most attempts <%s> - %d\n", table->hashTable[i]->key, table->hashTable[i]->insertionAttempts);
    }
}

int getElementCount(HashTable* table)
{
    return table->elementCount;
}

int getBucketCount(HashTable* table)
{
    return table->bucketCount;
}

int getWordAmount(HashTable* table)
{
    int wordAmount = 0;
    for (int i = 0; i < table->bucketCount; ++i) {
        if (table->types[i] == used) {
            wordAmount += table->hashTable[i]->amount;
        }
    }
    return wordAmount;
}

HashElement* createHashElement(char* key)
{
    HashElement* newElement = (HashElement*)malloc(sizeof(HashElement));
    int keySize = strlen(key);
    newElement->key = (char*)malloc(sizeof(char) * keySize);
    strcpy(newElement->key, key);

    newElement->insertionAttempts = 0;
    newElement->amount = 0;

    return newElement;
}

HashTable* createHashTableWithSize(int polynomFactor, int size)
{
    HashTable* newTable = (HashTable*)malloc(sizeof(HashTable));
    newTable->hashTable = (HashElement**)malloc(sizeof(HashElement*) * size);
    newTable->types = (enum CellType*)malloc(sizeof(enum CellType) * size);
    newTable->bucketCount = size;
    newTable->elementCount = 0;
    newTable->polynomFactor = polynomFactor;
    memset(newTable->types, (int)empty, size * sizeof(enum CellType));
    memset(newTable->hashTable, 0, size * sizeof(HashElement*));

    return newTable;
}

HashTable* createHashTable(int polynomFactor)
{
    return createHashTableWithSize(polynomFactor, 1);
}

int getHash(char* key, int polynomFactor, int module)
{
    int size = strlen(key);
    int currentHash = 0;
    for (int i = 0; i < size; ++i) {
        currentHash = ((currentHash * polynomFactor) + (key[i] - 'a')) % module;
    }
    return currentHash;
}

void destroyHashTable(HashTable* table)
{
    for (int i = 0; i < table->bucketCount; ++i) {
        free(table->hashTable[i]);
    }
    free(table->hashTable);
    free(table->types);
    free(table);
}

void expandTable(HashTable* table)
{
    HashElement** oldElements = table->hashTable;
    enum CellType* oldTypes = table->types;

    int oldSize = table->bucketCount;
    int size = table->bucketCount * 2;

    table->hashTable = (HashElement**)malloc(sizeof(HashElement*) * size);
    table->types = (enum CellType*)malloc(sizeof(enum CellType) * size);
    memset(table->hashTable, 0, size * sizeof(HashElement*));
    memset(table->types, (int)empty, size * sizeof(enum CellType));
    table->bucketCount = size;
    table->elementCount = 0;

    for (int i = 0; i < oldSize; ++i) {
        if (oldTypes[i] == used) {
            HashElement* element = oldElements[i];
            pushElement(table, element->key, element->amount, element->insertionAttempts);
        }
    }

    free(oldElements);
    free(oldTypes);
}

int getIndex(HashTable* table, int hash, int attempt)
{
    return (hash + (attempt + attempt * attempt) / 2) % table->bucketCount;
}

bool pushElement(HashTable* table, char* key, int amount, int insertionAttempts)
{
    int attempt = 1;
    int hash = getHash(key, table->polynomFactor, table->bucketCount);
    int index = getIndex(table, hash, attempt);
    while (table->types[index] == used) {
        if (strcmp(table->hashTable[index]->key, key) == 0) {
            if (table->hashTable[index]->insertionAttempts < attempt) {
                table->hashTable[index]->insertionAttempts = attempt;
            }
            table->hashTable[index]->amount++;
            return true;
        }
        ++attempt;
        index = getIndex(table, hash, attempt);
    }
    HashElement* newElement = createHashElement(key);
    table->hashTable[index] = newElement;
    table->types[index] = used;
    table->elementCount++;
    newElement->insertionAttempts = insertionAttempts;
    newElement->amount = amount;
    if (getLoadFactor(table) > maxLoadFactor) {
        expandTable(table);
    }
    return true;
}

bool getWordInformation(HashTable* table, char* key)
{
    int attempt = 1;
    int hash = getHash(key, table->polynomFactor, table->bucketCount);
    int index = getIndex(table, hash, attempt);
    while (table->types[index] == used) {
        if (strcmp(table->hashTable[index]->key, key) == 0) {
            printf("number of repetitions of a word %d\n", table->hashTable[index]->amount);
            printf("number of attempts to insert %d\n", table->hashTable[index]->insertionAttempts);
            return true;
        }
        ++attempt;
        index = getIndex(table, hash, attempt);
    }
    return false;
}

void printListOfMostCommonWords(HashTable* table)
{
    HashElement** elements = (HashElement**)malloc(10 * sizeof(HashElement*));
    memset(elements, (int)NULL, 10 * sizeof(HashElement*));
    for (int i = 0; i < table->bucketCount; ++i) {
        if (table->types[i] == used) {
            if (elements[0] == NULL) {
                elements[0] = table->hashTable[i];
            } else {
                for (int j = 0; j < 10; ++j) {
                    if (elements[j] != NULL && elements[j]->amount < table->hashTable[i]->amount) {
                        for (int k = 9; k > j; --k) {
                            elements[k] = elements[k - 1];
                        }
                        elements[j] = table->hashTable[i];
                        break;
                    } else if (elements[j] == NULL) {
                        elements[j] = table->hashTable[i];
                        break;
                    }
                }
            }
        }
    }
    for (int i = 0; i < 10; ++i) {
        if (elements[i] != NULL) {
            printf("\n %d. %s - repeated %d times", i + 1, elements[i]->key, elements[i]->amount);
        }
    }
    free(elements);
}
