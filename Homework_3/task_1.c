#include "../library/commonUtils/list.h"
#include <stdio.h>
int main()
{
    List* numbers = createList();
    ListElement* number1 = createListElement(1);
    ListElement* number2 = createListElement(2);
    ListElement* number3 = createListElement(3);
    ListElement* number10 = createListElement(10);
    insert(number1, 0, numbers);
    insert(number2, 1, numbers);
    insert(number3, 2, numbers);
    printList(numbers);
    insert(number10, 1, numbers);
    printList(numbers);
    printf("Locate: %d \n", locate(number10, numbers));
    printList(numbers);
    deleteElementOnPosition(1, numbers);
    deleteElementOnPosition(getSize(numbers), numbers);
    printList(numbers);
    removeList(numbers);
    return 0;
}
