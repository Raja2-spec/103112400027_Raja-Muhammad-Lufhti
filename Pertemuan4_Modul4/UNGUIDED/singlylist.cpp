#include "singlylist.h"

void createList(List &L) {
    L.first = nullptr;
}

ElmList* alokasi(Infotype x) {
    ElmList* P = new ElmList;
    P->info = x;
    P->next = nullptr;
    return P;
}

void dealokasi(ElmList* P) {
    delete P;
}

void insertFirst(List &L, ElmList* P) {
    if (L.first == nullptr) {
        L.first = P;
    } else {
        P->next = L.first;
        L.first = P;
    }
}

void printInfo(List L) {
    ElmList* P = L.first;
    while (P != nullptr) {
        std::cout << P->info << " ";
        P = P->next;
    }
    std::cout << std::endl;
}
