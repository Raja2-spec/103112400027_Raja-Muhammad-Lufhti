#ifndef SINGLYLIST_H
#define SINGLYLIST_H

#include <iostream>
using namespace std;

typedef int infotype;

struct ElmList {
    infotype info;
    ElmList* next;
};

struct List {
    ElmList* first;
};

// Deklarasi fungsi dan prosedur
void createList(List &L);
ElmList* alokasi(infotype x);
void dealokasi(ElmList* P);
void insertFirst(List &L, ElmList* P);
void printInfo(List L);

// Tambahan untuk nomor 2
void deleteFirst(List &L, ElmList* &P);
void deleteLast(List &L, ElmList* &P);
void deleteAfter(List &L, ElmList* Prec, ElmList* &P);
int nbList(List L);
void deleteList(List &L);

#endif
