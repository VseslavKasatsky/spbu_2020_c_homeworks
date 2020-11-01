#include "../library/commonUtils/hashTable.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int const LONGESTWORDLENGTH = 27;

bool getWord(char* word, FILE* file)
{
    memset(word, 0, LONGESTWORDLENGTH * sizeof(char));
    char buffer = 0;
    int i = 0;
    while (buffer != ' ') {
        buffer = fgetc(file);
        if (buffer == EOF) {
            return false;
        }
        if ((buffer >= 'a') && (buffer <= 'z')) {
            word[i] = buffer;
            ++i;
        } else if ((buffer >= 'A') && (buffer <= 'Z'))

        {
            buffer = tolower(buffer);
            word[i] = buffer;
            ++i;
        }
    }
    return true;
}

int main()
{
    char* word = (char*)malloc(LONGESTWORDLENGTH * sizeof(char));
    FILE* file = fopen("text.txt", "r");
    if (file == NULL) {
        printf("ERROR! The program could not open the file!");
        return -1;
    }
    bool flag = getWord(word, file);
    HashTable* table = createHashTable(2);
    while (flag) {
        pushElement(table, word, 1, 1);
        flag = getWord(word, file);
    }
    printf("Average number of attends: %f\n", getAverageNumberOfAttempts(table));
    getMaximumInsertAttempts(table);
    printf("Load factor: %f\n", getLoadFactor(table));
    printf("Total added words: %d\n", getWordAmount(table));
    printf("Number of unique words: %d\n", getElementCount(table));
    printf("Number of empty table cells: %d\n", getBucketCount(table) - getElementCount(table));
    printListOfMostCommonWords(table);
    fclose(file);
    free(word);
    destroyHashTable(table);
    return 0;
}
