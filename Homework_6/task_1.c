#include "../library/commonUtils/hashTable.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int getHashOutside(char* key, int polynomFactor, int module)
{
    int size = (int)strlen(key);
    int currentHash = 0;
    for (int i = 0; i < size; ++i) {
        currentHash = ((currentHash * polynomFactor) + (key[i] - 'a')) % module;
    }
    return currentHash;
}

int getIndexOutside(int hash, int attempt, int module)
{
    return (hash + (attempt + attempt * attempt) / 2) % module;
}

bool isLetter(char buffer)
{
    return (buffer >= 'a' && buffer <= 'z') || (buffer >= 'A' && buffer <= 'Z');
}

void readWordAndPush(FILE* file, HashTable* table)
{
    bool isEndOfFile = false;
    while (!isEndOfFile) {
        int size = 1;
        char* word = (char*)malloc(size * sizeof(char));
        word[0] = '0';
        int index = 0;
        char buffer = fgetc(file);
        while (isLetter(buffer)) {
            if (buffer >= 'A' && buffer <= 'Z') {
                buffer = tolower(buffer);
            }
            word[index] = buffer;
            ++index;
            if (size == index) {
                size = size * 2;
                word = (char*)realloc(word, size * sizeof(char));
            }
            buffer = fgetc(file);
        }
        if (buffer == EOF) {
            isEndOfFile = true;
        }
        if (isLetter(word[0])) {
            word[index] = '\0';
            pushElement(table, word, 1);
        }
        free(word);
    }
}

int main()
{
    FILE* file = fopen("text.txt", "r");
    if (file == NULL) {
        printf("ERROR! The program could not open the file!");
        return -1;
    }
    int (*getHash)(char*, int, int) = &getHashOutside;
    int (*getIndex)(int, int, int) = &getIndexOutside;
    HashTable* table = createHashTable(2, getHash, getIndex);

    readWordAndPush(file, table);

    printf("Enter the number of the most repetitive words to display: ");
    int numberOfRepetitiveWords = 0;
    scanf("%d", &numberOfRepetitiveWords);

    printListOfMostCommonWords(table, numberOfRepetitiveWords);
    printTableStatistic(table);

    fclose(file);
    destroyHashTable(table);
    return 0;
}
