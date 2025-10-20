#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>
using namespace std;

typedef int Infotype;

struct ElmList {
    Infotype info;
    ElmList *next;
};

struct List {
    ElmList *first;
};

void createList(List &L);
ElmList* alokasi(Infotype x);
void dealokasi(ElmList* P);
void insertFirst(List &L, ElmList* P);
void printInfo(List L);

#endif
