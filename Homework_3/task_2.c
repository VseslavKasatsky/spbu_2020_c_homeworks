#include "../library/commonUtils/list.h"
#include <stdio.h>

List* createSoldiers(int numberOfSoldiers)
{
    List* soldiers = createList();
    for (int i = numberOfSoldiers; i > 0; --i) {
        insert(createListElement(i), 0, soldiers);
    }
    return soldiers;
}
int getLastSurvivor(int numberOfSoldiers, int killRatio, List* soldiers)
{
    ListElement* current = head(soldiers);
    for (int i = 1; i < numberOfSoldiers; ++i) {
        for (int j = 1; j < killRatio; ++j) {
            current = nextElement(soldiers, current);
        }
        ListElement* currentCopy = nextElement(soldiers, current);
        deleteElementOnPosition(locate(current, soldiers), soldiers);
        current = currentCopy;
    }
    return getElementValue(current);
}
int main()
{
    int numberOfSoldiers = 0;
    printf("Enter number of soldiers: ");
    scanf("%d", &numberOfSoldiers);
    List* soldiers = createSoldiers(numberOfSoldiers);
    int killRatio = 0;
    printf("Enter the number, every M you want to kill: ");
    scanf("%d", &killRatio);
    printf("The last survivor number is: %d", getLastSurvivor(numberOfSoldiers, killRatio, soldiers));
    removeList(soldiers);
    return 0;
}
