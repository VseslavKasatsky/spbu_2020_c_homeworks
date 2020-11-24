#include "../library/commonUtils/list.h"
#include <stdio.h>
#include <stdlib.h>

void readFromFileAndPushInList(FILE* file, List* numbers)
{
    bool isEndOfFile = false;
    int index = 0;
    while (!isEndOfFile) {
        char word = '0';
        char buffer = fgetc(file);
        if (buffer == EOF) {
            isEndOfFile = true;
        } else {
            ListElement* newElement = createListElement(buffer - '0');
            insert(newElement, index, numbers);
            ++index;
        }
    }
}

bool isSymmetrical(List* numbers, int amount)
{
    int counter = 0;
    ListElement* startElement = retrieve(0, numbers);
    ListElement* endElement = retrieve(amount - 1, numbers);
    while ((startElement != endElement) && (getNextElement(endElement) != startElement)) {
        if (getElementValue(startElement) == getElementValue(endElement)) {
            ++counter;
        }
        startElement = getNextElement(startElement);
        endElement = getPreviousElement(endElement);
    }
    if (counter == (amount / 2)) {
        return true;
    } else {
        return false;
    }
}

int main()
{
    FILE* file = fopen("text.txt", "r");
    if (file == NULL) {
        printf("ERROR! The program could not open the file!");
        return -1;
    }

    List* numbers = createList();
    readFromFileAndPushInList(file, numbers);
    int size = getSize(numbers);

    if (isSymmetrical(numbers, size)) {
        printf("The set of numbers in the file is symmetrical");
    } else {
        printf("The set of numbers in the file is NOT symmetrical");
    }

    removeList(numbers);
    return 0;
}