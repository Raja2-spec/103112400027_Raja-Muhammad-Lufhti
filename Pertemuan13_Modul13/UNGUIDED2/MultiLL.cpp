#include "MultiLL.h"

void createListParent(listParent &L) {
    L.first = L.last = NULL;
}

void createListChild(listChild &L) {
    L.first = L.last = NULL;
}

NodeParent alokasiParent(string id, string nama) {
    NodeParent P = new nodeParent;
    P->info.idGolongan = id;
    P->info.namaGolongan = nama;
    P->next = P->prev = NULL;
    createListChild(P->child);
    return P;
}

NodeChild alokasiChild(string id, string nama, string habitat, bool ekor, float bobot) {
    NodeChild P = new nodeChild;
    P->info.idHewan = id;
    P->info.namaHewan = nama;
    P->info.habitat = habitat;
    P->info.ekor = ekor;
    P->info.bobot = bobot;
    P->next = P->prev = NULL;
    return P;
}

void insertLastParent(listParent &L, NodeParent P) {
    if (L.first == NULL) {
        L.first = L.last = P;
    } else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

void insertLastChild(listChild &L, NodeChild P) {
    if (L.first == NULL) {
        L.first = L.last = P;
    } else {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

void tampilkanChildDanParent(listParent L,
    string idParent,
    int posisiChild) {
    NodeParent P = L.first;
    int posParent = 1;

    while (P != NULL && P->info.idGolongan != idParent) {
        P = P->next;
        posParent++;
    }

    if (P == NULL) return;

    NodeChild C = P->child.first;
    int posChild = 1;

    while (C != NULL && posChild != posisiChild) {
        C = C->next;
        posChild++;
    }

    if (C == NULL) return;

    cout << "Data ditampilkan pada list anak dari node parent "
         << P->info.namaGolongan
         << " pada posisi ke-" << posParent << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "ID Child : " << C->info.idHewan << endl;
    cout << "Posisi dalam list anak : posisi ke-" << posChild << endl;
    cout << "Nama Hewan : " << C->info.namaHewan << endl;
    cout << "Habitat : " << C->info.habitat << endl;
    cout << "Ekor : " << (C->info.ekor ? 1 : 0) << endl;
    cout << "Bobot : " << C->info.bobot << endl;
    cout << "--------------------------------------------------" << endl << endl;

    cout << "Data Parent" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "ID Parent : " << P->info.idGolongan << endl;
    cout << "Posisi dalam list induk : posisi ke-" << posParent << endl;
    cout << "Nama Golongan : " << P->info.namaGolongan << endl;
    cout << "--------------------------------------------------" << endl << endl;
}
