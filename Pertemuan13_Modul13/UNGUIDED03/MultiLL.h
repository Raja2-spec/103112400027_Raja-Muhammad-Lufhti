#ifndef MULTILL_H
#define MULTILL_H
#include <iostream>
using namespace std;

struct golonganHewan{
    string idGolongan;
    string namaGolongan;
};

struct dataHewan{
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor;
    float bobot;
};

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild{
    dataHewan info;
    NodeChild next;
    NodeChild prev;
};

struct listChild{
    NodeChild first;
    NodeChild last;
};

struct nodeParent{
    golonganHewan info;
    NodeParent next;
    NodeParent prev;
    listChild child;
};

struct listParent{
    NodeParent first;
    NodeParent last;
};

void createListParent(listParent &L);
void createListChild(listChild &L);
NodeParent alokasiParent(string id, string nama);
NodeChild alokasiChild(string id, string nama, string habitat, bool ekor, float bobot);
void insertLastParent(listParent &L, NodeParent P);
void insertLastChild(listChild &L, NodeChild P);
void printMLL(listParent L);

#endif