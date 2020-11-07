#ifndef SPBU_2020_C_HOMEWORKS_LIBRARY_COMMONUTILS_TEST1_2_H_
#define SPBU_2020_C_HOMEWORKS_LIBRARY_COMMONUTILS_TEST1_2_H_
typedef struct ListComplexElement ListComplexElement;
typedef struct ListComplex ListComplex;

ListComplexElement* createListElement(int imaginary, int real);

ListComplexElement* subtract(ListComplexElement* firstElement, ListComplexElement* secondElement);
ListComplexElement* sum(ListComplexElement* firstElement, ListComplexElement* secondElement);
ListComplexElement* multiplication(ListComplexElement* firstElement, ListComplexElement* secondElement);
ListComplexElement* division(ListComplexElement* firstElement, ListComplexElement* secondElement);

#endif //SPBU_2020_C_HOMEWORKS_LIBRARY_COMMONUTILS_TEST1_2_H_
