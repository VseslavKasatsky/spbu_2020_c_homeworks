#include "../library/commonUtils/soldiers.h"
#include <stdio.h>
int main()
{
    List* soldiers = createList();
    int numberOfSoldiers=0;
    printf("Enter number of soldiers: ");
    scanf("%d",&numberOfSoldiers);
    for(int i=1;i<=numberOfSoldiers;++i)
    {
        ListElement* number=createListElement(0,i);
        insert(number,i,soldiers);
    }
    printList(soldiers);
    return 0;
}