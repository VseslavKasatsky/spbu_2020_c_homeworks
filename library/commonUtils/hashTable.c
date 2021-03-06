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
    int (*getHash)(char*, int, int);
    int (*getIndex)(int, int, int);
};

const float maxLoadFactor = 0.7;

float getLoadFactor(HashTable* table)
{
    return (float)table->elementCount / (float)table->bucketCount;
}

void printMaximumInsertAttempts(HashTable* table)
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

void printAverageNumberOfAttempts(HashTable* table)
{
    if (table->elementCount == 0) {
        printf("Average number of attends: 0\n");
        return;
    }
    int sumOfInsertAttempts = 0;
    for (int i = 0; i < table->bucketCount; ++i) {
        if (table->types[i] == used) {
            sumOfInsertAttempts += table->hashTable[i]->insertionAttempts;
        }
    }
    printf("Average number of attends: %f\n", (float)sumOfInsertAttempts / (float)table->elementCount);
}

void printElementCount(HashTable* table)
{
    printf("Number of unique words: %d\n", table->elementCount);
}

void printNumberOfEmptyCells(HashTable* table)
{
    printf("Number of empty table cells: %d\n", table->bucketCount - table->elementCount);
}

void printWordAmount(HashTable* table)
{
    int wordAmount = 0;
    for (int i = 0; i < table->bucketCount; ++i) {
        if (table->types[i] == used) {
            wordAmount += table->hashTable[i]->amount;
        }
    }
    printf("Total added words: %d\n", wordAmount);
}

void printLoadFactor(HashTable* table)
{
    printf("Load factor: %f\n", getLoadFactor(table));
}

void printTableStatistic(HashTable* table)
{
    printAverageNumberOfAttempts(table);
    printLoadFactor(table);
    printMaximumInsertAttempts(table);
    printElementCount(table);
    printWordAmount(table);
    printNumberOfEmptyCells(table);
}

HashElement* createHashElement(char* key)
{
    HashElement* newElement = (HashElement*)malloc(sizeof(HashElement));
    int keySize = (int)strlen(key);
    newElement->key = (char*)malloc((keySize + 1) * sizeof(char));
    strcpy(newElement->key, key);

    newElement->insertionAttempts = 0;
    newElement->amount = 0;

    return newElement;
}

void initializeTable(HashTable* table, int size)
{
    table->hashTable = (HashElement**)malloc(sizeof(HashElement*) * size);
    table->types = (enum CellType*)malloc(sizeof(enum CellType) * size);
    memset(table->hashTable, 0, size * sizeof(HashElement*));
    memset(table->types, (int)empty, size * sizeof(enum CellType));
    table->bucketCount = size;
    table->elementCount = 0;
}

HashTable* createHashTableWithSize(int polynomFactor, int size, int (*getHash)(char*, int, int), int (*getIndex)(int, int, int))
{
    HashTable* newTable = (HashTable*)malloc(sizeof(HashTable));
    newTable->polynomFactor = polynomFactor;
    newTable->getHash = getHash;
    newTable->getIndex = getIndex;
    initializeTable(newTable, size);

    return newTable;
}

HashTable* createHashTable(int polynomFactor, int (*getHash)(char*, int, int), int (*getIndex)(int, int, int))
{
    return createHashTableWithSize(polynomFactor, 1, getHash, getIndex);
}

void deleteHashElement(HashElement* element)
{
    if (element->key != NULL) {
        free(element->key);
    }
    free(element);
}

void destroyHashTable(HashTable* table)
{
    for (int i = 0; i < table->bucketCount; ++i) {
        if (table->types[i] == used) {
            deleteHashElement(table->hashTable[i]);
        }
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

    initializeTable(table, size);
    for (int i = 0; i < oldSize; ++i) {
        if (oldTypes[i] == used) {
            HashElement* element = oldElements[i];
            pushElement(table, element->key, element->amount);
            deleteHashElement(element);
        }
    }

    free(oldElements);
    free(oldTypes);
}

void pushElement(HashTable* table, char* key, int amount)
{
    int attempt = 1;
    int hash = table->getHash(key, table->polynomFactor, table->bucketCount);
    int index = table->getIndex(hash, attempt, table->bucketCount);
    while (table->types[index] == used) {
        if (strcmp(table->hashTable[index]->key, key) == 0) {
            if (table->hashTable[index]->insertionAttempts < attempt) {
                table->hashTable[index]->insertionAttempts = attempt;
            }
            table->hashTable[index]->amount++;
            return;
        }
        ++attempt;
        index = table->getIndex(hash, attempt, table->bucketCount);
    }

    HashElement* newElement = createHashElement(key);
    table->hashTable[index] = newElement;
    table->types[index] = used;
    table->elementCount++;
    newElement->insertionAttempts = attempt;
    newElement->amount = amount;

    if (getLoadFactor(table) > maxLoadFactor) {
        expandTable(table);
    }
}

bool removeElement(HashTable* table, char* key)
{
    int attempt = 1;
    int hash = table->getHash(key, table->polynomFactor, table->bucketCount);
    int index = table->getIndex(hash, attempt, table->bucketCount);
    int startIndex = index;
    while (table->types[index] == used) {
        if (table->hashTable[index]->key != NULL && strcmp(table->hashTable[index]->key, key) == 0) {
            table->types[index] = empty;
            table->elementCount--;
            deleteHashElement(table->hashTable[index]);
            return true;
        }
        ++attempt;
        index = table->getIndex(hash, attempt, table->bucketCount);
        if (startIndex == index) {
            return false;
        }
    }
    return false;
}

void tryToAddWordToListOfMostCommonWords(HashTable* table, int* elementsIndex, int indexInHashTable, int numberOfRepetitiveWords)
{
    if (table->types[indexInHashTable] == used) {
        int index = 0;
        while (elementsIndex[index] > -1 && table->hashTable[indexInHashTable]->amount < table->hashTable[elementsIndex[index]]->amount && index < numberOfRepetitiveWords) {
            ++index;
        }
        if (index < numberOfRepetitiveWords) {
            for (int j = numberOfRepetitiveWords - 1; j > index; --j) {
                elementsIndex[j] = elementsIndex[j - 1];
            }
            elementsIndex[index] = indexInHashTable;
        }
    }
}

void printListOfMostCommonWords(HashTable* table, int numberOfRepetitiveWords)
{
    if (table->elementCount == 0) {
        printf("There are no items in the table\n");
        return;
    }
    int* elementsIndex = (int*)malloc(numberOfRepetitiveWords * sizeof(int));
    memset(elementsIndex, -1, numberOfRepetitiveWords * sizeof(int));
    for (int i = 0; i < table->bucketCount; ++i) {
        tryToAddWordToListOfMostCommonWords(table, elementsIndex, i, numberOfRepetitiveWords);
    }
    int i = 0;
    while (i < numberOfRepetitiveWords && elementsIndex[i] != -1) {
        printf("\n %d. %s - repeated %d times", i + 1, table->hashTable[elementsIndex[i]]->key, table->hashTable[elementsIndex[i]]->amount);
        ++i;
    }
    printf("\n");
    free(elementsIndex);
}
