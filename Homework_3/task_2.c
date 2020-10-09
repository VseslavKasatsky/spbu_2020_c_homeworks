#include "../library/commonUtils/cycleList.h"
#include <stdio.h>
int main()
{
    int numberOfSoldiers = 0;
    int killRatio = 0;
    printf("Enter number of soldiers: ");
    scanf("%d", &numberOfSoldiers);

    CycleList* soldiers = createCycleList();
    for (int i = 1; i <= numberOfSoldiers; ++i) {
        addCycleListElement(i, soldiers);
    }

    printf("Enter the number, every M you want to kill: ");
    scanf("%d", &killRatio);

    for (int i = 1; i < numberOfSoldiers; ++i) {
        for (int j = 1; j < killRatio; ++j) {
            nextCycleListElement(soldiers);
        }
        deleteCycleListElement(soldiers);
    }

    printf("The last survivor number is: %d", getLastNumber(soldiers));
    removeCycleList(soldiers);
    return 0;
}