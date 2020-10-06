#ifndef SPBU_2020_C_HOMEWORKS_LIBRARY_COMMONUTILS_CYCLELIST_H_
#define SPBU_2020_C_HOMEWORKS_LIBRARY_COMMONUTILS_CYCLELIST_H_
typedef struct CycleListElement CycleListElement;
typedef struct CycleList CycleList;
CycleList* createCycleList();
CycleListElement* createCycleListElement();
void addCycleListElement(int number, CycleList* cycleList);
void printCycleList(CycleList* cycleList, int lastNumber);
void deleteCycleListElement(CycleList* cycleList);
void nextCycleListElement(CycleList* cycleList);
int getLastNumber(CycleList* cycleList);
void removeCycleList(CycleList* cycleList);
#endif //SPBU_2020_C_HOMEWORKS_LIBRARY_COMMONUTILS_CYCLELIST_H_