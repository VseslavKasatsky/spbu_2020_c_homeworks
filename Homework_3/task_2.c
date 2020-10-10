#include "../library/commonUtils/cycleList.h"
#include <stdio.h>
int main()
{
    int numberOfSoldiers = 0;
    int killRatio = 0;
    printf("Enter number of soldiers: ");
    scanf("%d", &numberOfSoldiers);

    List* soldiers = createList();
    for (int i = 0; i < numberOfSoldiers; ++i) {
        insert(createListElement(i + 1, soldiers), i, soldiers);
    }

    printf("Enter the number, every M you want to kill: ");
    scanf("%d", &killRatio);

    for (int i = 1; i < numberOfSoldiers; ++i) {
        for (int j = 1; j < killRatio; ++j) {
            nextCycleListElement(soldiers);
        }
        deleteCurrentElement(soldiers);
    }

    printf("The last survivor number is: %d", getCurrentValue(soldiers));
    removeList(soldiers);
    return 0;
}
