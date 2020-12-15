#include "../library/commonUtils/list.h"
#include <stdio.h>

int main()
{
    int numberFromUser = 1;
    List* numbers = createList();
    printf("Enter numbers (to finish enter 0): ");
    scanf("%d", &numberFromUser);
    while (numberFromUser) {
        if (isValueInList(numbers, numberFromUser)) {
            updateQuantity(retrieve(getValuePosition(numbers, numberFromUser), numbers));
        } else {
            ListElement* number = createListElement(numberFromUser);
            pushToListInIncrease(numbers, number);
        }
        scanf("%d", &numberFromUser);
    }
    printListElementQuantity(numbers);
    removeList(numbers);
    return 0;
}