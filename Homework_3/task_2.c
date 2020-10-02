#include "../library/commonUtils/soldiers.h"
#include <stdio.h>
int main()
{
    Brigade* soldiers = createBrigade();
    int numberOfSoldiers = 0, killRatio = 0;
    printf("Enter number of soldiers: ");
    scanf("%d", &numberOfSoldiers);
    for (int i = 1; i <= numberOfSoldiers; ++i) {
        addSoldier(i, soldiers);
    }
    printf("Enter the number, every M you want to kill: ");
    scanf("%d", &killRatio);
    for (int i = 1; i < numberOfSoldiers; ++i) {
        for (int j = 1; j < killRatio; ++j) {
            nextSoldier(soldiers);
        }
        deleteSoldier(soldiers);
    }
    printf("The last survivor number is: %d", getLastNumber(soldiers));
    return 0;
}