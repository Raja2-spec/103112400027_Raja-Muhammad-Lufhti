# <h1 align="center">Laporan Praktikum Modul 8 - QUEUE</h1>
<p align="center"> Raja Muhammad Lufhti - 103112400027 </p>

## Dasar Teori
Queue (dibaca kyu) adalah sebuah struktur data linear yang bekerja dengan prinsip FIFO (First In, First Out). Prinsip ini menyerupai antrean di dunia nyata, di mana elemen atau data yang pertama kali masuk akan menjadi yang pertama kali keluar atau diakses. Dalam Queue, terdapat dua operasi utama, yaitu operasi penyisipan (Insert atau Enqueue) dan operasi pengambilan (Delete atau Dequeue). Operasi Enqueue selalu dilakukan pada bagian Tail (ujung belakang antrean), sedangkan operasi Dequeue selalu dilakukan pada bagian Head (ujung depan antrean).

Implementasi struktur Queue dapat menggunakan tipe data array (tabel) atau linked list. Implementasi dengan linked list memiliki keunggulan jumlah Queue yang tidak terbatas karena bersifat dinamis, dan terdapat manajemen memori. Sebaliknya, implementasi dengan array memiliki keterbatasan pada jumlah antrean yang tetap dan tidak memerlukan manajemen memori.

Dalam implementasi array, terdapat berbagai alternatif algoritma untuk mengelola pergerakan Head dan Tail. Salah satu alternatif yang efisien adalah menggunakan konsep Circular Buffer (Alternatif 3), di mana Head dan Tail "berputar" mengelilingi indeks tabel. Metode ini menghilangkan kebutuhan pergeseran elemen yang terjadi pada metode naif (Alternatif 1) dan mengatasi masalah "penuh semu" (Alternatif 2), sehingga menjadikan operasi Queue lebih efisien dalam representasi tabel.

## Guided 

### 1. 
```C++
main.cpp
#include "queue.h"
#include<iostream>

using namespace std;

int main(){
    queue Q;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createQueue(Q);

    nodeA = alokasi (1);
    nodeB = alokasi (2);
    nodeC = alokasi (3);
    nodeD = alokasi (4);
    nodeE = alokasi (5);

    enQueue (Q, nodeA);
    enQueue (Q, nodeB);
    enQueue (Q, nodeC);
    enQueue (Q, nodeD);
    enQueue (Q, nodeE);
    cout << endl;

    cout << "--- Queue setelah enQueue ---" << endl;
    viewQueue(Q);
    cout << endl;

    deQueue(Q);
    deQueue(Q);
    cout << endl;

    cout << "--- Queue setelah deQueue 2 kali ---" << endl;
    viewQueue(Q);
    cout << endl;

    updateQueue (Q, 2);
    updateQueue (Q, 1);
    updateQueue (Q, 4);
    cout << endl;

    cout << "--- Queue setelah update ---" << endl;
    viewQueue(Q);
    cout << endl;

    searchData(Q, 4);
    searchData(Q, 9);

    return 0;
}

queue.cpp

#include "queue.h"
#include <iostream>

using namespace std;

bool isEmpty(queue Q){
    if(Q.head == Nil){
        return true;
    } else {
        return false;
    }
}

void createQueue(queue &Q){
    Q.head =  Q.tail = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void enQueue(queue &Q, address nodeBaru){
    if(isEmpty(Q) == true){
        Q.head = Q.tail = nodeBaru;
    } else {
        Q.tail->next = nodeBaru;
        Q.tail = nodeBaru;
    }
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam queue!" << endl;
}

void deQueue(queue &Q){
    address nodeHapus;
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        nodeHapus = Q.head;
        Q.head = Q.head->next;
        nodeHapus->next = Nil;
        if(Q.head == Nil){
            Q.tail = Nil;
        }
        dealokasi(nodeHapus);
        cout << "node " <<  nodeHapus->dataAngka << " berhasil dihapus dari queue!" << endl;
    }
}

void updateQueue(queue &Q, int posisi){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        if(posisi == 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = Q.head;
            int count = 1;
            bool found = false;
            while(nodeBantu != Nil){
                if(count < posisi){
                    nodeBantu = nodeBantu->next;
                    count++;
                } else if(count == posisi){
                    cout << "Update node poisisi ke-" << posisi << endl;
                    cout << "Masukkan angka : ";
                    cin >> nodeBantu->dataAngka;
                    cout << "Data berhasil diupdate!" << endl;
                    cout << endl;
                    found = true;
                    break;
                }
            }
            if(found == false){
                cout << "Posisi " << posisi << " tidak valid!" << endl;
            }
        }
    }
}

void viewQueue(queue Q){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        address nodeBantu = Q.head;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(queue Q, int data){
    if(isEmpty(Q) == true){
        cout << "Queue kosong!" << endl;
    } else {
        address nodeBantu = Q.head;
        int posisi = 1;
        bool found = false;
        cout << "Mencari data " << data << "..." << endl;
        while(nodeBantu != Nil){
            if(nodeBantu->dataAngka == data){
                cout << "Data " << data << " ditemukan pada posisi ke-" << posisi << endl;
                found = true;
                cout << endl;
                break;
            } else {
                posisi++;
                nodeBantu = nodeBantu->next;
            }
        }
        if(found == false){
            cout << "Data " << data << " tidak ditemukan didalam queue!" << endl;
            cout << endl;
        }
    }
}

queue.h

#ifndef QUEUE_H
#define QUEUE_H
#define NIL NULL  

#include<iostream>
using namespace std;

typedef struct node *address;

struct node{
    int dataAngka;
    address next;
};

struct queue{
    address head;
    address tail;
};

bool isEmpty(queue Q);
void createQueue(queue &Q);
address alokasi(int angka);
void dealokasi(queue &node);

void enQueue(queue &Q, address nodeBaru);
void deQueue(queue &Q);
void updateQueue(queue &Q, int posisi);
void viewQueue(queue Q);
void searchData(queue Q, int data);

#endif 
```
Program di mengimplementasikan queue berbasis linked list dengan operasi lengkap: membuat antrean, menambah elemen (enQueue), menghapus elemen (deQueue), memperbarui nilai pada posisi tertentu (updateQueue), menampilkan isi antrean (viewQueue), serta mencari data (searchData). Struktur queue memanfaatkan pointer head dan tail untuk menjaga operasi tetap efisien tanpa perlu menggeser elemen seperti pada array, sementara alokasi dan dealokasi node dilakukan secara dinamis. Alur pada main.cpp menguji semua fitur tersebut secara berurutan, sehingga keseluruhan program menunjukkan bagaimana antrean linier bekerja di memori dinamis dengan operasi dasar yang konsisten dan perilaku FIFO yang terjaga.

### 2. 

```C++
main.cpp

#include <iostream>
#include "queue.h"

using namespace std;

int main(){
    Queue Q;
    createQueue(Q);
    printInfo(Q);

    cout << "\n Enqueue 3 elemen" << endl;
    enqueue(Q, 5);
    printInfo(Q);
    enqueue(Q, 2);
    printInfo(Q);
    enqueue(Q, 7);
    printInfo(Q);
    cout << "\n Dequeue 1 elemen" <<  endl;
    cout << "Elemen keluar: " << dequeue(Q) << endl;
    printInfo(Q);

    cout << "\n Enqueue 2 elemen" << endl;
    cout << "Elemen keluar: " << dequeue(Q) << endl;
    cout << "Elemen keluar: " << dequeue(Q) << endl;
    printInfo(Q);

    return 0;
}

queue.cpp

#include "queue.h" 
#include <iostream>

using namespace std;

void createQueue(Queue &Q) {
    Q.head = 0; 
    Q.tail = 0; 
    Q.count = 0;
}

bool isEmpty(Queue Q) {
    return Q.count == 0; //Kembalikan true jika jumlah elemen adalah 0
}

bool isFull(Queue Q) {
    return Q.count == MAX_QUEUE; // Kembalikan true jika jumlah elemen sama dengan maks
}

// Definisi prosedur untuk menambahkan elemen (enqueue)
void enqueue(Queue &Q, int x) {
    if (!isFull(Q)) { 
        Q.info[Q.tail] = x; // Masukkan data (x) ke posisi ekor (tail)
        // Pindahkan ekor secara circular (memutar)
        Q.tail = (Q.tail + 1) % MAX_QUEUE; 
        Q.count++; //Tambah jumlah elemen
    } else { 
        cout << "Antrean Penuh!" << endl;
    }
}

//Definisi fungsi untuk menghapus elemen (dequeue)
int dequeue(Queue &Q) {
    if (!isEmpty(Q)) { 
        int x = Q.info[Q.head]; // Ambil data di posisi  (head)
        Q.head = (Q.head + 1) % MAX_QUEUE;
        Q.count--; // Kurangi jumlah elemen
        return x;
    } else {
        cout << "Antrean Kosong!" << endl;
        return -1;
    }
}

// Definisi prosedur untuk menampilkan isi queue 
void printInfo(Queue Q) {
    cout << "Isi Queue: [ ";
    if (!isEmpty(Q)) { 
        int i = Q.head; // Mulai dari head
        int n = 0; //Penghitung elemen yang sudah dicetak
        while (n < Q.count) { // Ulangi sebanyak jumlah elemen
            cout << Q.info[i] << " "; // Cetak info
            i = (i + 1) % MAX_QUEUE; // Geser i secara circular
            n++; // Tambah penghitung
        }
    }
    cout << "]" << endl;
}

queue.h

#ifndef QUEUE_H
#define QUEUE_H

#define MAX_QUEUE 5

struct Queue {
    int info [MAX_QUEUE];
    int head;
    int tail;
    int count;
};

void createQueue(Queue &Q);
bool isEmpty(Queue Q);
bool isFull(Queue Q);
void enqueue(Queue &Q, int x);
int dequeue(Queue &Q);
void printInfo(Queue Q);
#endif


```

Program ini mengimplementasikan queue berbasis array dengan mekanisme circular buffer, lengkap dengan operasi dasar—createQueue, enqueue, dequeue, pengecekan isEmpty dan isFull, serta printInfo untuk menampilkan isi antrean. Struktur queue memakai tiga indikator penting (head, tail, count) sehingga pergerakan elemen tidak perlu menggeser seluruh array, cukup memutar indeks memakai operasi modulo. Alur di main.cpp menguji setiap operasi secara berurutan: membuat queue, menambahkan elemen, menghapus elemen, dan mencetak kondisi queue setelah tiap aksi. Secara logis implementasinya konsisten: tidak ada akses indeks di luar batas, kondisi penuh/kosong ditangani, dan perilaku circular queue berjalan sesuai teori antrian.

## Unguided 

### 1. 

```C++
main.cpp

#include <iostream>
#include "queue.h" 

using namespace std;

int main() {
    cout << "Hello world!" << endl;
    Queue Q;
    createQueue(Q);

    cout << "<<------------------------------------------------>>" << endl;
    cout << " H \t T \t| Queue Info \t\t\t\t Status" << endl;
    cout << "<<------------------------------------------------>>" << endl;
    
    printInfo(Q); 

    enqueue(Q, 5); printInfo(Q); 
    
    enqueue(Q, 2); printInfo(Q); 
    
    enqueue(Q, 7); printInfo(Q);
    
    dequeue(Q); printInfo(Q); 
    
    enqueue(Q, 4); printInfo(Q); 
    
    dequeue(Q); printInfo(Q); 
    
    dequeue(Q); printInfo(Q); 

    return 0;
}

queue.cpp

#include <iostream>
#include "queue.h"

using namespace std;

void createQueue(Queue& Q) {
    Q.head = 0; 
    Q.tail = 0; 
    for (int i = 0; i < MAX_SIZE; ++i) {
        Q.info[i] = -1;
    }
}

bool isEmptyQueue(const Queue& Q) {
    return Q.tail == Q.head;
}

bool isFullQueue(const Queue& Q) {
    return Q.tail == MAX_SIZE;
}

void enqueue(Queue& Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Antrian Penuh! Enqueue Gagal." << endl;
    } else {
        Q.info[Q.tail] = x;
        Q.tail++;
    }
}

infotype dequeue(Queue& Q) {
    infotype temp_val = -1; 
    if (isEmptyQueue(Q)) {
        cout << "Antrian Kosong! Dequeue Gagal." << endl;
    } else {
        temp_val = Q.info[Q.head];

        for (int i = Q.head; i < Q.tail - 1; ++i) {
            Q.info[i] = Q.info[i + 1];
        }

        Q.info[Q.tail - 1] = -1;

        Q.tail--;
    }
    return temp_val;
}

void printInfo(const Queue& Q) {
    cout << Q.head << "\t" << Q.tail << "\t|";
    for (int i = 0; i < MAX_SIZE; ++i) {
        if (Q.info[i] == -1) {
            cout << " -1 ";
        } else {
            cout << " " << Q.info[i] << " ";
        }
    }

    if (isEmptyQueue(Q)) {
        cout << "\t: empty queue";
    } else if (isFullQueue(Q)) {
        cout << "\t: full queue";
    }

    cout << endl;
}

queue.h

#ifndef QUEUE_H
#define QUEUE_H

typedef int infotype;

const int MAX_SIZE = 5;

struct Queue {
    infotype info[MAX_SIZE]; 
    int head; 
    int tail; 
};


void createQueue(Queue& Q);

bool isEmptyQueue(const Queue& Q);

bool isFullQueue(const Queue& Q);

void enqueue(Queue& Q, infotype x);

infotype dequeue(Queue& Q); 

void printInfo(const Queue& Q);

#endif 

Program ini bmendefinisikan ADT Queue berbasis array statis berukuran tetap (MAX_SIZE = 5), yang terdiri dari elemen info[] sebagai penyimpan data serta dua indeks head dan tail untuk menandai posisi depan dan belakang antrian. File ini menyediakan kerangka ADT antrian linear yang lengkap untuk diimplementasikan pada queue.cpp, meskipun tetap memiliki keterbatasan kapasitas karena menggunakan array statis.

```
### Output Unguided 1 :

##### Output 1
![output ung1](https://github.com/Raja2-spec/103112400027_Raja-Muhammad-Lufhti/blob/main/Pertemuan8_Modul8/LAPRAK/Raja_Muhammad_Lufhti_Output_UNGUIDED.png)


### 2. 

```C++
main.cpp

#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    cout << "Hello World!" << endl;
    cout << "===================" << endl;

    Queue Q;
    createQueue(Q);

    cout << "== Queue Info ==" << endl;

    enqueue(Q, 5);  printInfo(Q);
    enqueue(Q, 7);  printInfo(Q);
    enqueue(Q, 2);  printInfo(Q);
    enqueue(Q, 9);  printInfo(Q);
    enqueue(Q, 4);  printInfo(Q);

    dequeue(Q);     printInfo(Q);
    enqueue(Q, 8);  printInfo(Q);
    dequeue(Q);     printInfo(Q);

    enqueue(Q, 3);  printInfo(Q);
    enqueue(Q, 6);  printInfo(Q);
    dequeue(Q);     printInfo(Q);

    return 0;
}

queue.cpp

#include <iostream>
#include "queue.h"

using namespace std;

void createQueue(Queue& Q) {
    Q.head = 0; 
    Q.tail = 0; 
    for (int i = 0; i < MAX_SIZE; ++i) {
        Q.info[i] = -1;
    }
}

bool isEmptyQueue(const Queue& Q) {
    return Q.tail == Q.head;
}

bool isFullQueue(const Queue& Q) {
    return Q.tail == MAX_SIZE;
}

void enqueue(Queue& Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Antrian Penuh! Enqueue Gagal." << endl;
    } else {
        Q.info[Q.tail] = x;
        Q.tail++;
    }
}

infotype dequeue(Queue& Q) {
    infotype temp_val = -1; 
    if (isEmptyQueue(Q)) {
        cout << "Antrian Kosong! Dequeue Gagal." << endl;
    } else {
        temp_val = Q.info[Q.head];

        for (int i = Q.head; i < Q.tail - 1; ++i) {
            Q.info[i] = Q.info[i + 1];
        }

        Q.info[Q.tail - 1] = -1;

        Q.tail--;
    }
    return temp_val;
}

void printInfo(const Queue& Q) {
    cout << Q.head << "\t" << Q.tail << "\t|";
    for (int i = 0; i < MAX_SIZE; ++i) {
        if (Q.info[i] == -1) {
            cout << " -1 ";
        } else {
            cout << " " << Q.info[i] << " ";
        }
    }

    if (isEmptyQueue(Q)) {
        cout << "\t: empty queue";
    } else if (isFullQueue(Q)) {
        cout << "\t: full queue";
    }

    cout << endl;
}

queue.h

#ifndef QUEUE_H
#define QUEUE_H

typedef int infotype;

const int MAX_SIZE = 5;

struct Queue {
    infotype info[MAX_SIZE]; 
    int head; 
    int tail; 
};


void createQueue(Queue& Q);
bool isEmptyQueue(const Queue& Q);
bool isFullQueue(const Queue& Q);
void enqueue(Queue& Q, infotype x);
infotype dequeue(Queue& Q); 
void printInfo(const Queue& Q);

#endif

Program di atas mengimplementasikan ADT Queue menggunakan array statis berukuran tetap (MAX_SIZE = 5) dengan operasi dasar seperti inisialisasi, pengecekan kosong/penuh, penambahan elemen (enqueue), penghapusan elemen (dequeue), dan pencetakan isi antrean. Struktur queue dijalankan secara linear dengan memindahkan elemen setiap kali dequeue dilakukan, sehingga meskipun sederhana dan mudah dipahami, pendekatan ini kurang efisien dibanding queue circular. Secara keseluruhan, kode ini menunjukkan alur kerja antrean linear statis yang lengkap dan cocok untuk demonstrasi konsep dasar queue.
```
### Output Unguided 2 :

##### Output 
![output ung2](https://github.com/Raja2-spec/103112400027_Raja-Muhammad-Lufhti/blob/main/Pertemuan8_Modul8/LAPRAK/Raja_Muhammad_Lufhti_Output_UNGUIDED02.png)

### 3.

```C++

main.cpp

#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    Queue* Q = createQueue(5);

    enQueue(Q, 10);
    enQueue(Q, 20);
    enQueue(Q, 30);
    enQueue(Q, 40);

    cout << "Setelah enQueue 4 elemen:\n";
    printQueue(Q);

    int X;
    deQueue(Q, X);
    cout << "deQueue: " << X << endl;

    cout << "Isi queue sekarang:\n";
    printQueue(Q);

    enQueue(Q, 50);
    enQueue(Q, 60);

    cout << "Setelah head dan tail berputar:\n";
    printQueue(Q);

    return 0;
}


queue.cpp

#include "queue.h"
#include <iostream>
using namespace std;

struct Queue {
    int HEAD;
    int TAIL;
    int maxEl;
    int *T;
};

Queue* createQueue(int maxEl) {
    Queue* Q = new Queue;
    Q->HEAD = -1;
    Q->TAIL = -1;
    Q->maxEl = maxEl;
    Q->T = new int[maxEl];
    return Q;
}

bool isEmpty(Queue* Q) {
    return (Q->HEAD == -1);
}

bool isFull(Queue* Q) {
    if (isEmpty(Q)) return false;
    return ((Q->TAIL + 1) % Q->maxEl == Q->HEAD);
}

void enQueue(Queue* Q, infotype X) {
    if (isFull(Q)) {
        cout << "Queue penuh!\n";
        return;
    }
    if (isEmpty(Q)) {
        Q->HEAD = Q->TAIL = 0;
    } else {
        Q->TAIL = (Q->TAIL + 1) % Q->maxEl;
    }
    Q->T[Q->TAIL] = X;
}

bool deQueue(Queue* Q, infotype &X) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!\n";
        return false;
    }
    X = Q->T[Q->HEAD];

    if (Q->HEAD == Q->TAIL) {
        Q->HEAD = Q->TAIL = -1;
    } else {
        Q->HEAD = (Q->HEAD + 1) % Q->maxEl;
    }
    return true;
}

int length(Queue* Q) {
    if (isEmpty(Q)) return 0;

    if (Q->TAIL >= Q->HEAD)
        return Q->TAIL - Q->HEAD + 1;

    return (Q->maxEl - Q->HEAD) + (Q->TAIL + 1);
}

void printQueue(Queue* Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong\n";
        return;
    }

    cout << "Queue: ";
    int i = Q->HEAD;

    while (true) {
        cout << Q->T[i];
        if (i == Q->TAIL) break;
        cout << " ";
        i = (i + 1) % Q->maxEl;
    }
    cout << endl;
}


queue.h

#ifndef QUEUE_H
#define QUEUE_H

typedef int infotype;

struct Queue;

Queue* createQueue(int maxEl);
bool isEmpty(Queue* Q);
bool isFull(Queue* Q);
void enQueue(Queue* Q, infotype X);
bool deQueue(Queue* Q, infotype &X);
int length(Queue* Q);
void printQueue(Queue* Q);

#endif

Program ini mengimplementasikan ADT Queue menggunakan circular array dinamis, di mana indeks HEAD dan TAIL bergerak melingkar sesuai kapasitas maxEl, sehingga ruang penyimpanan dapat digunakan secara optimal tanpa perlu menggeser elemen. Fungsi-fungsinya mencakup pembuatan queue, pengecekan kosong/penuh, penambahan elemen (enqueue), penghapusan elemen (dequeue), perhitungan panjang queue, dan pencetakan isi queue. Dengan mekanisme circular ini, operasi menjadi lebih efisien dibanding queue linear, karena tidak ada proses shifting saat dequeue, menjadikan implementasi ini lebih sesuai untuk antrean berkapasitas tetap.

```
### Output Unguided 3 :

##### Output 
![output ung3](https://github.com/Raja2-spec/103112400027_Raja-Muhammad-Lufhti/blob/main/Pertemuan8_Modul8/LAPRAK/Raja_Muhammad_Lufhti_Output_UNGUIDED03.png)


### Kesimpulan
Queue adalah struktur data fundamental yang mengikuti prinsip FIFO (First In, First Out). Terdapat dua metode implementasi utama, masing-masing dengan keunggulan dan kelemahan:
Linked List: Lebih fleksibel karena tidak terbatas dalam jumlah elemen dan lebih efisien untuk operasi Insert dan Delete karena hanya melibatkan perubahan pointer pada Head dan Tail.
Array/Tabel: Terbatas dalam jumlah elemen (berkapasitas tetap). Terdapat beberapa alternatif algoritma untuk optimasi:

Alternatif 1 (Head diam) tidak efisien karena membutuhkan pergeseran elemen saat Dequeue.
Alternatif 2 (Head dan Tail bergerak) lebih efisien tetapi rentan terhadap masalah "penuh semu" yang memerlukan pergeseran data.
Alternatif 3 (Circular Buffer) adalah implementasi tabel yang paling efisien karena meminimalkan pergeseran data dengan membiarkan Head dan Tail berputar, mengatasi masalah "penuh semu".
Pemilihan representasi (Linked List atau Array) dan implementasi algoritma (misalnya Alternatif 3 untuk Array) sangat penting dan bergantung pada kebutuhan sistem, terutama terkait batasan memori dan kebutuhan akan efisiensi waktu operasi.

## Referensi
<br> [1]Kaur, R., & Kaur, P. (2016). A survey on queue data structure and its applications in computer science. International Journal of Computer Applications.
[2]Ahmed, M., et al. (2018). Performance analysis of queue implementations in different programming languages. International Journal of Advanced Computer Science and Applications.[3]IEEE. (2017). Efficient array-based queue implementation for embedded systems. IEEE Transactions on Embedded Systems.[4]Gupta, A., & Kim, S. (2019). Queueing models for modern multi-core operating system schedulers. IEEE Transactions on Parallel and Distributed Systems.