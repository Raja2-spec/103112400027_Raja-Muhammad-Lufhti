#include "MultiLL.h"

void createListParent(listParent &L){
    L.first = L.last = NULL;
}

void createListChild(listChild &L){
    L.first = L.last = NULL;
}

NodeParent alokasiParent(string id, string nama){
    NodeParent P = new nodeParent;
    P->info.idGolongan = id;
    P->info.namaGolongan = nama;
    P->next = P->prev = NULL;
    createListChild(P->child);
    return P;
}

NodeChild alokasiChild(string id, string nama, string habitat, bool ekor, float bobot){
    NodeChild P = new nodeChild;
    P->info.idHewan = id;
    P->info.namaHewan = nama;
    P->info.habitat = habitat;
    P->info.ekor = ekor;
    P->info.bobot = bobot;
    P->next = P->prev = NULL;
    return P;
}

void insertLastParent(listParent &L, NodeParent P){
    if (L.first == NULL)
    {
        L.first = L.last = P;
    }
    else
    {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

void insertLastChild(listChild &L, NodeChild P){
    if (L.first == NULL)
    {
        L.first = L.last = P;
    }
    else
    {
        L.last->next = P;
        P->prev = L.last;
        L.last = P;
    }
}

void printMLL(listParent L){
    NodeParent P = L.first;
    while (P != NULL)
    {
        cout << "Golongan: " << P->info.idGolongan << " - " << P->info.namaGolongan << endl;
        NodeChild C = P->child.first;
        while (C != NULL)
        {
            cout << " " << C->info.idHewan << " | "
                 << C->info.namaHewan << " | "
                 << C->info.habitat << " | Ekor: "
                 << (C->info.ekor ? "True" : "False")
                 << " | Bobot: " << C->info.bobot << endl;
            C = C->next;
        }
        cout << endl;
        P = P->next;
    }
}