#include "../library/commonUtils/list.h"
#include <stdio.h>
int main()
{
    List* numbers = createList();
    ListElement* number1 = createListElement(1);
    ListElement* number2 = createListElement(2);
    ListElement* number3 = createListElement(3);
    addListElement(numbers, number1);
    addListElement(numbers, number2);
    addListElement(numbers, number3);
    printList( numbers);
    return 0;
}
