#include "MultiLL.h"

void createListParent(listParent &L) {
    L.first = NULL;
    L.last = NULL;
}

void createListChild(listChild &L) {
    L.first = NULL;
    L.last = NULL;
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

void printMLL(listParent L) {
    NodeParent P = L.first;
    int parentNo = 1;

    while (P != NULL) {
        cout << "=== Parent " << parentNo++ << " ===" << endl;
        cout << "ID Golongan : " << P->info.idGolongan << endl;
        cout << "Nama Golongan : " << P->info.namaGolongan << endl;

        if (P->child.first == NULL) {
            cout << "  (tidak ada child)" << endl;
        } else {
            NodeChild C = P->child.first;
            int childNo = 1;
            while (C != NULL) {
                cout << "  Child " << childNo++ << " :" << endl;
                cout << "    ID Hewan : " << C->info.idHewan << endl;
                cout << "    Nama Hewan : " << C->info.namaHewan << endl;
                cout << "    Habitat : " << C->info.habitat << endl;
                cout << "    Ekor : " << (C->info.ekor ? 1 : 0) << endl;
                cout << "    Bobot : " << C->info.bobot << endl;
                C = C->next;
            }
        }
        cout << "----------------------" << endl << endl;
        P = P->next;
    }
}
