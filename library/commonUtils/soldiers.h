#ifndef SPBU_2020_C_HOMEWORKS_LIBRARY_COMMONUTILS_SOLDIERS_H_
#define SPBU_2020_C_HOMEWORKS_LIBRARY_COMMONUTILS_SOLDIERS_H_
typedef struct Soldier Soldier;
typedef struct Troop Troop;
#include <stdbool.h>
Troop* createTroop();
Soldier* createSoldier();
void addSoldier(int number, Troop* troop);
#endif //SPBU_2020_C_HOMEWORKS_LIBRARY_COMMONUTILS_SOLDIERS_H_