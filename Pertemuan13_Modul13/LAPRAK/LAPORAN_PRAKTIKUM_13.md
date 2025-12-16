# <h1 align="center"> Laporan Praktikum Modul 13 - Multi Linked List </h1>
<p align="center">Raja Muhammad Lufhti - 103112400027</p>

## Dasar Teori
Linked List merupakan struktur data dinamis yang tersusun dari sekumpulan node, di mana setiap node menyimpan data dan sebuah pointer yang menunjuk ke node lain. Berbeda dengan array, linked list tidak memerlukan alokasi memori secara berurutan sehingga lebih fleksibel dalam proses penambahan maupun penghapusan data. Struktur ini sangat cocok digunakan ketika ukuran data sering berubah selama proses eksekusi program.

Doubly Linked List adalah pengembangan dari linked list yang memungkinkan setiap node memiliki dua pointer, yaitu pointer next yang menunjuk ke node berikutnya dan pointer prev yang menunjuk ke node sebelumnya. Dengan adanya dua arah penelusuran ini, operasi seperti pencarian dan penghapusan node menjadi lebih efisien karena tidak selalu harus dimulai dari node pertama.

Multi Linked List merupakan struktur data yang menggabungkan lebih dari satu linked list yang saling berelasi, umumnya untuk merepresentasikan hubungan satu-ke-banyak (one-to-many). Dalam Multi Linked List terdapat list induk (parent) dan list anak (child), di mana setiap node parent memiliki sebuah list child tersendiri. Struktur ini banyak digunakan untuk memodelkan data bertingkat seperti kategori dan subkategori, dosen dan mahasiswa, atau golongan hewan dan jenis hewan.

Melalui Multi Linked List, proses traversal dapat dilakukan secara hierarkis, yaitu menelusuri data parent terlebih dahulu kemudian data child yang terkait. Selain itu, struktur ini memungkinkan operasi pencarian data child beserta parent-nya, sehingga hubungan antar data dapat dipertahankan dengan baik. Oleh karena itu, Multi Linked List menjadi dasar penting dalam memahami struktur data kompleks dan konsep relasi dalam pemrograman.

## Guided
### 1. Implementasi Stuktur Data Multi Linked List

### multilist.h
```C++
#ifndef MULTILIST_H
#define MULTILIST_H

#include <iostream>
using namespace std;

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct  nodeChild{
    string idMakanan;
    string namaMakanan;
    NodeChild next;
    NodeChild prev;
};

struct listAnak{
    NodeChild first;    
    NodeChild last;
};

struct nodeParent{
 string idKategoriMakanan;
 string namaKategoriMakanan;
 NodeParent next;
 NodeParent prev;
 listAnak L_Anak;
};

struct listInduk{
    NodeParent first;
    NodeParent last;
};

void createListInduk(listInduk &LInduk);
void createListAnak(listAnak &Lanak);

NodeParent alokasiNodeParent(string idkategoriMakanan, string namaKategoriMakanan);
void dealokasiNodeParent(NodeParent &NodeInduk);

NodeChild alokasiNodeChild(string idmakanan, string namamakanan);
void dealokasiNodeChild(NodeChild &NodeAnak);

void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent);
void hapusListAnak(listAnak &LAnak);
void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev);

void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild);
void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev); 
void findChildByID(listInduk &LInduk, string IDCari);

void printStrukturMLL(listInduk &LInduk);

#endif
```

### multilist.cpp
```C++
#include "multilist.h"
#include <iostream>

using namespace std;

void createListInduk(listInduk &LInduk){
    LInduk.first = LInduk.last = NULL;
}

void createListAnak(listAnak &LAnak){
    LAnak.first = LAnak.last = NULL;
}

NodeParent alokasiNodeParent(string idKategoriMakanan, string namaKategoriMakanan){
    NodeParent nodeBaruParent = new nodeParent;
    nodeBaruParent->idKategoriMakanan = idKategoriMakanan;
    nodeBaruParent->namaKategoriMakanan = namaKategoriMakanan;
    nodeBaruParent->next = NULL;
    nodeBaruParent->prev = NULL;
    createListAnak(nodeBaruParent->L_Anak);
    return nodeBaruParent;
}

void dealokasiNodeParent(NodeParent &nodeInduk){
    if(nodeInduk != NULL) {
        nodeInduk->next = nodeInduk->prev = NULL;
        delete nodeInduk;
        nodeInduk = NULL;
    }
}

NodeChild alokasiNodeChild(string idMakanan, string namaMakanan){
    NodeChild nodeBaruChild = new nodeChild;
    nodeBaruChild->idMakanan = idMakanan;
    nodeBaruChild->namaMakanan = namaMakanan;
    nodeBaruChild->next = NULL;
    nodeBaruChild->prev = NULL;
    return nodeBaruChild;
}

void dealokasiNodeChild(NodeChild &nodeAnak){
    if(nodeAnak != NULL) {
        nodeAnak->next = nodeAnak->prev = NULL;
        delete nodeAnak;
        nodeAnak = NULL;
    }
}

void insertLastParent(listInduk &LInduk, NodeParent nodeBaruParent){
    if(LInduk.first == NULL) {
        LInduk.first = LInduk.last = nodeBaruParent;
    } else {
        nodeBaruParent->prev = LInduk.last;
        LInduk.last->next = nodeBaruParent;
        LInduk.last = nodeBaruParent;
    }
    cout << "Node parent "<< nodeBaruParent->namaKategoriMakanan << " berhasil ditambahkan kedalam urutan terakhir di list Induk!" << endl;
}

void hapusListAnak(listAnak &LAnak){
    NodeChild nodeBantu = LAnak.first;
    while(nodeBantu != NULL) {
        NodeChild nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasiNodeChild(nodeHapus);
    }
    LAnak.first = LAnak.last = NULL;
}

void deleteAfterParent(listInduk &LInduk, NodeParent nodePrev){
    if(LInduk.first == NULL){
        cout << "List induk kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeParent nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LInduk.last = nodePrev;
            }
            nodeHapus->next = NULL;
            if(nodeHapus->L_Anak.first != NULL){
                hapusListAnak(nodeHapus->L_Anak);
            }
            dealokasiNodeParent(nodeHapus);
            cout << "Node parent setelah node " << nodePrev->namaKategoriMakanan << " berhasil dihapus beserta anak-anaknya!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

void insertLastChild(listAnak &LAnak, NodeChild nodeBaruChild){
    if(LAnak.first == NULL) {
        LAnak.first = LAnak.last = nodeBaruChild;
    } else {
        nodeBaruChild->prev = LAnak.last;
        LAnak.last->next = nodeBaruChild;
        LAnak.last = nodeBaruChild;
    }
    cout << "Node child "<< nodeBaruChild->namaMakanan << " berhasil ditambahkan kedalam urutan terakhir di list Anak!" << endl;
}

void deleteAfterChild(listAnak &LAnak, NodeChild nodePrev){
    if(LAnak.first == NULL){
        cout << "List anak kosong!" << endl;
    } else {
        if(nodePrev != NULL && nodePrev->next != NULL){
            NodeChild nodeHapus = nodePrev->next;
            nodePrev->next = nodeHapus->next;
            if (nodeHapus->next != NULL){
                (nodeHapus->next)->prev = nodePrev;
            } else {
                LAnak.last = nodePrev;
            }
            nodeHapus->next = NULL;
            dealokasiNodeChild(nodeHapus);
            cout << "Node child setelah node " << nodePrev->namaMakanan << " berhasil dihapus!" << endl;
        } else {
            cout << "Node prev tidak valid!" << endl;
        }
    }
}

void findChildByID(listInduk &LInduk, string IDCari){
    if(LInduk.first == NULL){
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        int ketemu = false;
        while(nodeBantuParent != NULL){
            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            int indexChild = 1;
            while(nodeBantuChild != NULL){
                if(nodeBantuChild->idMakanan == IDCari) {
                    cout << "Data ID child ditemukan pada list anak dari node parent " << nodeBantuParent->namaKategoriMakanan << " pada posisi ke-" << indexChild << "!" << endl;
                    cout << "--- Data Child ---" << endl;
                    cout << "ID Child (ID Makanan) : " << nodeBantuChild->idMakanan << endl;
                    cout << "Posisi dalam list anak : posisi ke-" << indexChild << endl;
                    cout << "Nama Makanan : " << nodeBantuChild->namaMakanan << endl;
                    cout << "---------------------------" << endl;
                    cout << "--- Data Parent ---" << endl;
                    cout << "ID Parent (ID Kategori Makanan): " << nodeBantuParent->idKategoriMakanan << endl;
                    cout << "Posisi dalam list induk : posisi ke-" << indexParent << endl;
                    cout << "Nama Kategori Makanan : " << nodeBantuParent->namaKategoriMakanan << endl;
                    ketemu = true;
                    break;
                } else {
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            if(ketemu){
                break;
            } else {
                nodeBantuParent = nodeBantuParent->next;
                indexParent++;
            }
        }
        if(!ketemu){
            cout << "Data ID child tidak ditemukan didalam list anak!" << endl;
        }
    }
}

void printStrukturMLL(listInduk &LInduk){
    if(LInduk.first == NULL) {
        cout << "List induk kosong!" << endl;
    } else {
        NodeParent nodeBantuParent = LInduk.first;
        int indexParent = 1;
        while(nodeBantuParent != NULL) {
            cout << "=== Parent " << indexParent << " ===" << endl;
            cout << "ID Kategori Makanan : " << nodeBantuParent->idKategoriMakanan << endl;
            cout << "Nama Kategori Makanan : " << nodeBantuParent->namaKategoriMakanan << endl;

            NodeChild nodeBantuChild = nodeBantuParent->L_Anak.first;
            if(nodeBantuChild == NULL) {
                cout << "  (tidak ada child)" << endl;
            } else {
                int indexChild = 1;
                while(nodeBantuChild != NULL) {
                    cout << "  - Child " << indexChild << " :" << endl;
                    cout << "      ID Makanan : " << nodeBantuChild->idMakanan << endl;
                    cout << "      Nama Makanan : " << nodeBantuChild->namaMakanan << endl;
                    nodeBantuChild = nodeBantuChild->next;
                    indexChild++;
                }
            }
            cout << "---------------------------" << endl;
            nodeBantuParent = nodeBantuParent->next;
            indexParent++;
        }
    }
}
```

### main.cpp
```C++
#include "multilist.h"
#include <iostream>
using namespace std;

int main(){
    listInduk LInduk;
    createListInduk(LInduk);

    NodeParent k01 = alokasiNodeParent("K01", "Makanan Berat");
    insertLastParent(LInduk, k01);
    NodeParent k02 = alokasiNodeParent("K02", "Minuman");
    insertLastParent(LInduk, k02);
    NodeParent k03 = alokasiNodeParent("K03", "Dessert");
    insertLastParent(LInduk, k03);
    cout<<endl;

    NodeChild M01 = alokasiNodeChild("M01", "Nasi Goreng");
    insertLastChild(k01->L_Anak, M01);
    NodeChild M02 = alokasiNodeChild("M02", "Ayam Bakar Madu");
    insertLastChild(k01->L_Anak, M02);  
    NodeChild D02 = alokasiNodeChild("D02", "Jus Alpukat");
    insertLastChild(k02->L_Anak, D02);
    NodeChild D03 = alokasiNodeChild("D03", "Jus Alpukat");
    insertLastChild(k02->L_Anak, D03);
    NodeChild S01 = alokasiNodeChild("DS01", "Puding Coklat");
    insertLastChild(k03->L_Anak, S01);
    cout << endl;  

    printStrukturMLL(LInduk);
    cout << endl;

    findChildByID(LInduk, "D01");
    cout << endl;
    deleteAfterChild(k01->L_Anak, M01);
    cout<< endl;
    deleteAfterParent(LInduk, k02);
    cout << endl;
    printStrukturMLL(LInduk);
    cout << endl;
    
    return 0;
}
```
Deskripsi: Program tersebut merupakan implementasi multi linked list dengan struktur parent dan child dengan menggunakan double linked list untuk parent dan child nya tersebut. Terdapat struktur *listInduk* yang berfungsi sebagai penyimpanan utama untuk menyimpan seluruh node parent. Setiap node parent yang ada di dalam *listInduk* merepresentasikan sebuah kategori makanan yang memiliki aribut ID kategori dan nama kategori. Setiap node parent juga memiliki struktur sendiri yaitu *listAnak* yang menampung multiple node child. Node child sendiri merepresentasikan makanan individual dengan atribut ID makanan dan nama makanan. Dengan metode ini, satu kategori makanan dapat memiliki banyak item makanan yang terkait dan menciptakan hubungan one to many antara parent dan child. Lalu implementasi double linked list memberikan fleksibilitas dalam melakukan operasi traversal. Setiap node parent maupun child, memiliki poiner next untuk menunjuk ke node berikutnya dan pointer prev untuk menunjuk ke node sebelumnya yang memungkinkan program untuk melakukan penelusuran maju dan mundur dengan lebih efisien.



## Unguided 

### 1. ADT multi linked list golongan hewan 
### main.cpp
```C++
#include "MultiLL.h"

int main() {
    listParent L;
    createListParent(L);

    NodeParent G1 = alokasiParent("G001", "Aves");
    NodeParent G2 = alokasiParent("G002", "Mamalia");
    NodeParent G3 = alokasiParent("G003", "Pisces");
    NodeParent G4 = alokasiParent("G004", "Amfibi");
    NodeParent G5 = alokasiParent("G005", "Reptil");

    insertLastParent(L, G1);
    insertLastParent(L, G2);
    insertLastParent(L, G3);
    insertLastParent(L, G4);
    insertLastParent(L, G5);

    insertLastChild(G1->child, alokasiChild("AV001", "Cendrawasih", "Hutan", true, 0.3));
    insertLastChild(G1->child, alokasiChild("AV002", "Bebek", "Air", true, 2));

    insertLastChild(G2->child, alokasiChild("M001", "Harimau", "Hutan", true, 200));
    insertLastChild(G2->child, alokasiChild("M003", "Gorila", "Hutan", false, 160));
    insertLastChild(G2->child, alokasiChild("M002", "Kucing", "Darat", true, 4));

    insertLastChild(G4->child, alokasiChild("AM001", "Kodok", "Sawah", false, 0.2));

    printMLL(L);
    return 0;
}

```

### MultiLL.cpp
```C++
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

```

### MultiLL.h
```C++
#ifndef MULTILL_H
#define MULTILL_H

#include <iostream>
using namespace std;

struct golonganHewan {
    string idGolongan;
    string namaGolongan;
};

struct dataHewan {
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor;
    float bobot;
};

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild {
    dataHewan info;
    NodeChild next;
    NodeChild prev;
};

struct listChild {
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    golonganHewan info;
    NodeParent next;
    NodeParent prev;
    listChild child;
};

struct listParent {
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

```

### Output Unguided 1 :

##### Output 1
![op1](https://github.com/Raja2-spec/103112400027_Raja-Muhammad-Lufhti/blob/main/Pertemuan13_Modul13/LAPRAK/Raja_Muhammad_Lufhti_Output_UNGUIDED.png)

Program telah berhasil diimplementasikan Multi Linked List yang terdiri dari list parent (golongan hewan) dan list child (data hewan). Setiap node parent memiliki sebuah list child yang dapat berisi lebih dari satu node anak. Melalui implementasi ini, dapat ditampilkan hubungan hierarkis antara golongan hewan dan data hewan secara terstruktur. Selain itu, sistem mampu menampilkan kondisi ketika suatu parent tidak memiliki child, sehingga memperlihatkan bahwa struktur data dapat menangani keadaan list kosong dengan baik. Hasil output yang diperoleh menunjukkan bahwa konsep dasar Multi Linked List telah diterapkan dengan benar.



### 2. Prosedur pencarian hewan berdasarkan ekor false

### main.cpp
```C++
#include "MultiLL.h"

int main() {
    listParent L;
    createListParent(L);

    NodeParent G1 = alokasiParent("G001", "Aves");
    NodeParent G2 = alokasiParent("G002", "Mamalia");
    NodeParent G3 = alokasiParent("G003", "Pisces");
    NodeParent G4 = alokasiParent("G004", "Amfibi");

    insertLastParent(L, G1);
    insertLastParent(L, G2);
    insertLastParent(L, G3);
    insertLastParent(L, G4);

    insertLastChild(G2->child, alokasiChild("M001","Harimau","Hutan",true,200));
    insertLastChild(G2->child, alokasiChild("M003","Gorila","Hutan",false,160));
    insertLastChild(G2->child, alokasiChild("M002","Kucing","Darat",true,4));

    insertLastChild(G4->child, alokasiChild("AM001","Kodok","Sawah",false,0.2));

    tampilkanChildDanParent(L, "G002", 2);
    tampilkanChildDanParent(L, "G004", 1);

    return 0;
}

```

### MultiLL.cpp
```C++
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

```

### MultiLL.h
```C++
#ifndef MULTILL_H
#define MULTILL_H

#include <iostream>
using namespace std;

struct golonganHewan {
    string idGolongan;
    string namaGolongan;
};

struct dataHewan {
    string idHewan;
    string namaHewan;
    string habitat;
    bool ekor;
    float bobot;
};

typedef struct nodeParent *NodeParent;
typedef struct nodeChild *NodeChild;

struct nodeChild {
    dataHewan info;
    NodeChild next;
    NodeChild prev;
};

struct listChild {
    NodeChild first;
    NodeChild last;
};

struct nodeParent {
    golonganHewan info;
    NodeParent next;
    NodeParent prev;
    listChild child;
};

struct listParent {
    NodeParent first;
    NodeParent last;
};

void createListParent(listParent &L);
void createListChild(listChild &L);

NodeParent alokasiParent(string id, string nama);
NodeChild alokasiChild(string id, string nama, string habitat, bool ekor, float bobot);

void insertLastParent(listParent &L, NodeParent P);
void insertLastChild(listChild &L, NodeChild P);

void tampilkanChildDanParent(listParent L,
    string idParent,
    int posisiChild);

#endif

```

### Output Unguided 2 :

##### Output 1
![op2](https://github.com/Raja2-spec/103112400027_Raja-Muhammad-Lufhti/blob/main/Pertemuan13_Modul13/LAPRAK/Raja_Muhammad_Lufhti_Output_UNGUIDED2.png)

Kode Multi Linked List dikembangkan lebih lanjut dengan menambahkan operasi pencarian (search) pada list child berdasarkan posisi tertentu serta menampilkan kembali informasi parent yang menaunginya. Implementasi ini menunjukkan bahwa traversal dapat dilakukan secara vertikal (dari parent ke child) maupun secara kontekstual (menampilkan data parent dari child yang dipilih). Selain itu, informasi posisi node baik pada list parent maupun list child berhasil ditentukan berdasarkan urutan penyisipan data. Hal ini membuktikan bahwa Multi Linked List sangat efektif digunakan untuk menyimpan dan menelusuri data yang memiliki relasi bertingkat.



### 3. Operasi delete

### main.cpp
```C++
#include "MultiLL.h"

int main(){
    listParent L;
    createListParent(L);

    NodeParent G1 = alokasiParent("G001", "Aves");
    NodeParent G2 = alokasiParent("G002", "Mamalia");
    NodeParent G3 = alokasiParent("G003", "Pisces");
    NodeParent G4 = alokasiParent("G004", "Amfibi");
    NodeParent G5 = alokasiParent("G005", "Reptil");

    insertLastParent(L, G1);
    insertLastParent(L, G2);
    insertLastParent(L, G3);
    insertLastParent(L, G4);
    insertLastParent(L, G5);

    insertLastChild(G1->child, alokasiChild("AV001", "Cendrawasih", "Hutan", true, 0.3));
    insertLastChild(G1->child, alokasiChild("AV002", "Bebek", "Air", true, 2));

    insertLastChild(G2->child, alokasiChild("M001", "Harimau", "Hutan", true, 200));
    insertLastChild(G2->child, alokasiChild("M003", "Gorila", "Hutan", false, 160));
    insertLastChild(G2->child, alokasiChild("M002", "Kucing", "Darat", true, 4));

    insertLastChild(G4->child, alokasiChild("AM001", "Kodok", "Sawah", false, 0.2));

    printMLL(L);
    return 0;
}
```

### MultiLL.cpp
```C++
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
```

### MultiLL.h
```C++
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
```

### Output Unguided 3 :

##### Output 1
![op3](https://github.com/Raja2-spec/103112400027_Raja-Muhammad-Lufhti/blob/main/Pertemuan13_Modul13/LAPRAK/Raja_Muhammad_Lufhti_Output_UNGUIDED03.png)

Fungsi struktur Multi Linked List diimplementasikan secara lengkap dan menyeluruh sesuai dengan data yang diberikan, mencakup seluruh golongan hewan beserta data anaknya. Program mampu menampilkan seluruh isi list secara sistematis, termasuk parent yang memiliki child maupun yang tidak memiliki child. Dengan implementasi ini, dapat disimpulkan bahwa Multi Linked List mampu menangani data kompleks dengan relasi satu-ke-banyak secara efisien dan terorganisir. Hasil output yang dihasilkan sesuai dengan ekspektasi, sehingga menegaskan bahwa struktur dan operasi yang digunakan telah berjalan dengan baik.

## Kesimpulan
Berdasarkan implementasi dan pengujian pada Soal Nomor 1, 2, dan 3, dapat disimpulkan bahwa Multi Linked List merupakan struktur data yang efektif untuk mengelola data yang memiliki hubungan hierarkis dan relasional. Struktur ini memungkinkan penyimpanan data yang kompleks tanpa harus menggunakan struktur data statis seperti array dua dimensi.

Melalui praktikum ini, terbukti bahwa Multi Linked List mampu mendukung operasi insert, traversal, pencarian, dan penghapusan data secara terstruktur dan konsisten. Selain itu, konsep parent–child yang diterapkan pada Multi Linked List memberikan pemahaman yang kuat terhadap representasi data dunia nyata, seperti klasifikasi hewan, sistem akademik, maupun sistem inventori.

Dengan demikian, penguasaan Multi Linked List menjadi penting sebagai dasar untuk memahami konsep struktur data lanjutan, pemrograman berorientasi objek, serta sistem basis data relasional.

## Referensi
<br>[1] Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C.
Introduction to Algorithms (3rd ed.).
MIT Press, 2009.[2]Weiss, M. A.
Data Structures and Algorithm Analysis in C++.
Pearson Education, 2014.[3]Sahni, S.
Data Structures, Algorithms, and Applications in C++.
McGraw-Hill, 2005.
