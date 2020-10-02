#ifndef SPBU_2020_C_HOMEWORKS_LIBRARY_COMMONUTILS_SOLDIERS_H_
#define SPBU_2020_C_HOMEWORKS_LIBRARY_COMMONUTILS_SOLDIERS_H_
typedef struct Soldier Soldier;
typedef struct Brigade Brigade;
Brigade* createBrigade();
Soldier* createSoldier();
void addSoldier(int number, Brigade* brigade);
void printBrigade(Brigade* brigade, int lastNumber);
void deleteSoldier(Brigade* brigade);
void nextSoldier(Brigade* brigade);
int getLastNumber(Brigade* brigade);
#endif //SPBU_2020_C_HOMEWORKS_LIBRARY_COMMONUTILS_SOLDIERS_H_