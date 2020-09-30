#include "../library/commonUtils/list.h"
#include <stdio.h>
int main()
{
    List* numbers = createList();
    ListElement* number1 = createListElement(1);
    ListElement* number2 = createListElement(2);
    ListElement* number3 = createListElement(3);
    ListElement* number10 = createListElement(10);
    insert(number1, 1, numbers);
    insert(number2, 2, numbers);
    insert(number3, 3, numbers);
    printList(numbers);
    insert(number10, 2, numbers);
    printList(numbers);
    printf("Locate: %d \n", locate(number10, numbers));
    printf("Retrieve: %d \n", retrieve(2, numbers));
    printList(numbers);
    delete (3, numbers);
    printList(numbers);
    removeList(numbers);
    return 0;
}
