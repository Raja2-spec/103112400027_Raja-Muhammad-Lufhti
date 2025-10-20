# <h1 align="center">Laporan Praktikum Modul 4 - Singly Linked List (Bagian Pertama) </h1>
<p align="center">Raja Muhammad Lufhti - 103112400027</p>

## Dasar Teori
Struktur data singly linked list adalah suatu kumpulan simpul (node) di mana tiap simpul memiliki dua bagian utama: data (informasi) dan pointer yang menunjuk ke simpul berikutnya. List ini hanya bergerak satu arah — dari head (awal) ke tail (akhir). Operasi-dasar yang lazim dilakukan antara lain: insert (menambah simpul di awal, akhir atau setelah simpul tertentu), delete (menghapus simpul pertama, terakhir atau sesudah suatu simpul), isEmpty (menguji apakah list kosong), nbList (menghitung jumlah simpul), dan deleteList (mengosongkan seluruh list). Singly linked list menawarkan fleksibilitas dalam penambahan/hapus simpul tanpa harus menggeser seluruh elemen seperti pada array, namun memiliki kelemahan berupa overhead pointer dan akses acak yang lambat. Referensi “RIP Linked List: Empirical Study to Discourage You from Using Linked Lists Any Further” menyebut bahwa dalam banyak kasus struktur berbasis array lebih efisien, baik dalam penggunaan memori maupun kecepatan eksekusi. [1].   

## Guided
### 1. Insert Operations

### main.cpp
```C++
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "--- ISI LIST SETELAH DILAKUKAN INSERT ---" << endl;
    printList(List);

    return 0;
}
```

### list.cpp
```C++
#include "list.h"
#include <iostream>
using namespace std;

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {
    /* I.S. sembarang
       F.S. terbentuk list kosong */
    List.first = Nil;
}

//pembuatan node baru dengan menerapkan manajemen memori
address alokasi(string nama, string nim, int umur) { 
    /* I.S. sembarang
       F.S. mengembalikan alamat node baru dengan isidata = sesuai parameter dan next = Nil */
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node dengan menerapkan manajemen memori
void dealokasi(address &node) {
    /* I.S. P terdefinisi
       F.S. memori yang digunakan node dikembalikan ke sistem */
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, P sudah dialokasikan
       F.S. menempatkan elemen list (node) pada awal list */
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {
    /* I.S. sembarang, nodeBaru dan Prev alamat salah satu elemen list (node)
       F.S. menempatkan elemen (node) sesudah elemen node Prev */
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {
    /* I.S. sembarang, nodeBaru sudah dialokasikan
       F.S. menempatkan elemen nodeBaru pada akhir list */
    if (isEmpty(List) == true) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {
    if (isEmpty(List) == true) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim 
            << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}
```

### list.h
```C++
//Header guard digunakan untuk mencegah file header yang sama 
//di-include lebih dari sekali dalam satu program.
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include<iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa{
    string nama; 
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //Memberikan nama alias dataMahasiswa untuk struct mahasiswa.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

#endif
```
Program ini dibuat untuk menunjukkan (mendemonstrasikan) bagaimana cara kerja struktur data Singly Linked List digunakan dalam pengelolaan data mahasiswa — seperti menambah, menampilkan, dan menghapus data.

### 2. Linked List Insert and Delete Operations
### main.cpp
```C++
#include "list.h"

#include<iostream>
using namespace std;

int main(){
    linkedlist List;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createList(List);

    dataMahasiswa mhs;

    nodeA = alokasi("Dhimas", "2311102151", 20);
    nodeB = alokasi("Arvin", "2211110014", 21);
    nodeC = alokasi("Rizal", "2311110029", 20);
    nodeD = alokasi("Satrio", "2211102173", 21);
    nodeE = alokasi("Joshua", "2311102133", 21);

    insertFirst(List, nodeA);
    insertLast(List, nodeB);
    insertAfter(List, nodeC, nodeA);
    insertAfter(List, nodeD, nodeC);
    insertLast(List, nodeE);

    cout << "ISI LIST SETELAH DILAKUKAN INSERT" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    delFirst(List);
    delLast(List);
    delAfter(List, nodeD, nodeC);

    cout << "ISI LIST SETELAH DILAKUKAN DELETE" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    deleteList(List);
    cout << "ISI LIST SETELAH DILAKUKAN HAPUS LIST" << endl;
    printList(List);
    cout << "jumlah node : " << nbList(List) << endl;
    cout << endl;

    return 0;
}
```

### list.cpp
```C++
#include "list.h"
#include <iostream>
using namespace std;

//I.S = Initial State / kondisi awal
//F.S = Final State / kondisi akhir

//fungsi untuk cek apakah list kosong atau tidak
bool isEmpty(linkedlist List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

//pembuatan linked list kosong
void createList(linkedlist &List) {

    List.first = Nil;
}

//pembuatan node baru
address alokasi(string nama, string nim, int umur) { 

    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.nim = nim; 
    nodeBaru->isidata.umur = umur;
    nodeBaru->next = Nil;
    return nodeBaru;
}

//penghapusan node
void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

//prosedur-prosedur untuk insert / menambahkan node baru kedalam list
void insertFirst(linkedlist &List, address nodeBaru) {

    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedlist &List, address nodeBaru, address Prev) {

    if (Prev != Nil) { //Previous (sebelumnya) tidak boleh NULL
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedlist &List, address nodeBaru) {

    if (isEmpty(List)) {
        List.first = nodeBaru;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        nodeBantu->next = nodeBaru;
    }
}

//prosedur-prosedur untuk delete / menghapus node yang ada didalam list
void delFirst(linkedlist &List){

    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedlist &List){

    address nodeHapus, nodePrev;
    if(isEmpty(List) == false){
        nodeHapus = List.first;
        if(nodeHapus->next == Nil){
            List.first->next = Nil;
            dealokasi(nodeHapus);
        } else { 
            while(nodeHapus->next != Nil){
                nodePrev = nodeHapus; 
                nodeHapus = nodeHapus->next;
            }
            nodePrev->next = Nil; 
            dealokasi(nodeHapus);
        }
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedlist &List, address nodeHapus, address nodePrev){

    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else { //jika list tidak kosong
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

//prosedur untuk menampilkan isi list
void printList(linkedlist List) {

    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama : " << nodeBantu->isidata.nama << ", NIM : " << nodeBantu->isidata.nim << ", Usia : " << nodeBantu->isidata.umur << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

//function untuk menampilkan jumlah node didalam list
int nbList(linkedlist List) {

    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

//prosedur untuk menghapus list (menghapus semua node didalam list)
void deleteList(linkedlist &List){

    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List sudah terhapus!" << endl;
}


```

### list.h
```C++
// list.h

//Header guard digunakan untuk mencegah file header yang sama
//di-include lebih dari sekali dalam satu program.
#ifndef LIST_H
#define LIST_H
#define Nil NULL

#include <iostream>
using namespace std;

//deklarasi isi data struct mahasiswa
struct mahasiswa{
    string nama; 
    string nim;
    int umur;
};

typedef mahasiswa dataMahasiswa; //Memberikan nama alias dataMahasiswa untuk struct mahasiswa.

typedef struct node *address; //Mendefinisikan alias address sebagai pointer ke struct node

struct node{ // node untuk isi dari linked listnya, isi setiap node adalah data & pointer next
    dataMahasiswa isidata;
    address next;
};

struct linkedlist{ //ini linked list nya
    address first;
};

//semua function & prosedur yang akan dipakai
bool isEmpty(linkedlist List);
void createList(linkedlist &List);
address alokasi(string nama, string nim, int umur);
void dealokasi(address &node);
void printList(linkedlist List);
void insertFirst(linkedlist &List, address nodeBaru);
void insertAfter(linkedlist &List, address nodeBaru, address Prev);
void insertLast(linkedlist &List, address nodeBaru);

void delFirst(linkedlist &List);
void delLast(linkedlist &List);
void delAfter(linkedlist &List, address nodeHapus, address nodePrev);
int nbList(linkedlist List);
void deleteList(linkedlist &List);

#endif

```
Program yang dibuat sudah mencakup seluruh operasi dasar yang biasanya dilakukan pada struktur data Single Linked List, mulai dari menambah data (insert), menghapus data (delete), sampai fungsi tambahan untuk menghitung jumlah node dan menghapus seluruh isi list.



## Unguided 
### 1. ADT Singly Linked List

### main.cpp
```C++
#include "Singlylist.h"

int main() {
    List L;
    ElmList *P1, *P2, *P3, *P4, *P5;

    createList(L);

    P1 = alokasi(2);
    insertFirst(L, P1);

    P2 = alokasi(0);
    insertFirst(L, P2);

    P3 = alokasi(8);
    insertFirst(L, P3);

    P4 = alokasi(12);
    insertFirst(L, P4);

    P5 = alokasi(9);
    insertFirst(L, P5);

    printInfo(L);

    return 0;
}

```

### singlylist.cpp
``` C++
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

```

### singlylist.h
```C++
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

```


### Output Unguided 1 :

##### Output 1
![soal 1](https://github.com/Raja2-spec/103112400027_Raja-Muhammad-Lufhti/blob/main/Pertemuan4_Modul4/LAPRAK/Raja_Muhammad_Lufhti_Output_Unguided1.png)

Program di atas merupakan implementasi sederhana dari Single Linked List dalam bahasa C++. Program ini membuat daftar berantai yang berisi beberapa angka menggunakan node yang saling terhubung satu arah. Struktur ElmList menyimpan data (info) dan pointer ke elemen berikutnya (next), sedangkan List menyimpan pointer ke elemen pertama. Fungsi createList menginisialisasi list kosong, alokasi membuat node baru berisi data, insertFirst menambahkan node ke awal list, dealokasi menghapus node dari memori, dan printInfo menampilkan seluruh isi list. Di fungsi main, program membuat lima node berisi angka (9, 12, 8, 0, 2) lalu mencetaknya sesuai urutan penyisipan dari depan list.


### 2. Penghapusan node

### main.cpp
```C++
#include "Singlylist.h"

int main() {
    List L;
    ElmList *P1, *P2, *P3, *P4, *P5;
    ElmList *del;

    createList(L);

    P1 = alokasi(2); insertFirst(L, P1);
    P2 = alokasi(0); insertFirst(L, P2);
    P3 = alokasi(8); insertFirst(L, P3);
    P4 = alokasi(12); insertFirst(L, P4);
    P5 = alokasi(9); insertFirst(L, P5);

    deleteFirst(L, del);
    dealokasi(del);

    deleteLast(L, del); 
    dealokasi(del);

    ElmList* prec = L.first->next; 
    deleteAfter(L, prec, del);
    dealokasi(del);

    printInfo(L);
    cout << "Jumlah node : " << nbList(L) << endl;

    deleteList(L);
    cout << "\n- List Berhasil Terhapus -" << endl;
    cout << "Jumlah node : " << nbList(L) << endl;

    return 0;
}

```

### singlylist.cpp
```C++
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

```

### singlylist.h
```C++
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

```
### Output Unguided 2 :

##### Output 1
![soal 2](https://github.com/Raja2-spec/103112400027_Raja-Muhammad-Lufhti/blob/main/Pertemuan4_Modul4/LAPRAK/Raja_Muhammad_Lufhti_Output_Unguided2.png)

Program ini merupakan implementasi lengkap dari Single Linked List dalam C++ yang mencakup operasi penambahan, penghapusan, dan penghitungan elemen. Program membuat daftar berantai dengan lima data (9, 12, 8, 0, 2), lalu menghapus elemen pertama, terakhir, dan satu elemen di tengah menggunakan fungsi deleteFirst, deleteLast, dan deleteAfter. Setelah setiap penghapusan, node yang dihapus dikembalikan ke memori dengan dealokasi. Fungsi nbList menghitung jumlah node yang masih ada, sedangkan deleteList menghapus seluruh isi list sampai kosong. Hasil akhir program menampilkan isi list setelah beberapa penghapusan, jumlah node yang tersisa, lalu pesan bahwa list berhasil dihapus seluruhnya.


## Kesimpulan
Dari praktikum dan implementasi yang dilakukan, dapat disimpulkan bahwa struktur singly linked list berhasil diterapkan untuk menyimpan data (dalam hal ini data mahasiswa) serta mendukung operasi dasar seperti penambahan (insertFirst, insertLast, insertAfter), penghapusan (deleteFirst, deleteLast, deleteAfter), penghitungan jumlah node (nbList) dan penghapusan seluruh list (deleteList). Singly linked list terbukti fleksibel dalam menyisipkan atau menghapus simpul tanpa harus memindahkan seluruh elemen seperti pada array. Namun, sesuai hasil studi referensi, perlu disadari bahwa linked list juga memiliki kelemahan: overhead pointer dan akses langsung ke elemen tengah atau akhir menjadi relatif lambat dibanding struktur array/vektor. Dengan demikian, meskipun singly linked list sangat cocok untuk latihan pemahaman struktur data, dalam aplikasi nyata kita harus mempertimbangkan konteks penggunaan dan performa sebelum memilihnya sebagai solusi utama.

## Referensi
<br>[1] RIP Linked List: Empirical Study to Discourage You from Using Linked Lists Any Further — Benoît Sonntag & Dominique Colnet (2023)  https://arxiv.org/pdf/2306.06942.pdf