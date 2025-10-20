#include "Singlylist.h"

void createList(List &L) {
    L.first = nullptr;
}

ElmList* alokasi(infotype x) {
    ElmList* P = new ElmList;
    P->info = x;
    P->next = nullptr;
    return P;
}

void dealokasi(ElmList* P) {
    delete P;
}

void insertFirst(List &L, ElmList* P) {
    P->next = L.first;
    L.first = P;
}

void printInfo(List L) {
    ElmList* P = L.first;
    while (P != nullptr) {
        cout << P->info << " ";
        P = P->next;
    }
    cout << endl;
}

void deleteFirst(List &L, ElmList* &P) {
    if (L.first != nullptr) {
        P = L.first;
        L.first = P->next;
        P->next = nullptr;
    }
}

void deleteLast(List &L, ElmList* &P) {
    if (L.first == nullptr) {
        P = nullptr;
    } else if (L.first->next == nullptr) {
        P = L.first;
        L.first = nullptr;
    } else {
        ElmList* Q = L.first;
        while (Q->next->next != nullptr) {
            Q = Q->next;
        }
        P = Q->next;
        Q->next = nullptr;
    }
}

void deleteAfter(List &L, ElmList* Prec, ElmList* &P) {
    if (Prec != nullptr && Prec->next != nullptr) {
        P = Prec->next;
        Prec->next = P->next;
        P->next = nullptr;
    }
}

int nbList(List L) {
    int count = 0;
    ElmList* P = L.first;
    while (P != nullptr) {
        count++;
        P = P->next;
    }
    return count;
}

void deleteList(List &L) {
    ElmList* P;
    while (L.first != nullptr) {
        deleteFirst(L, P);
        dealokasi(P);
    }
}
