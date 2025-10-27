# <h1 align="center">Laporan Praktikum Modul 5 - singly linked list (Bagian kedua)</h1>
<p align="center"> Raja Muhammad Lufhti - 103112400027 </p>

## Dasar Teori
Linked list merupakan salah satu struktur data dinamis yang terdiri dari sekumpulan elemen yang disebut node, di mana setiap node berisi dua bagian utama, yaitu data dan pointer yang menunjuk ke node berikutnya. Tidak seperti array yang memiliki ukuran tetap dan penyimpanan elemen secara bersebelahan di memori, linked list bersifat fleksibel karena dapat menambah atau menghapus data tanpa perlu menggeser elemen lain. Fleksibilitas ini membuat linked list banyak digunakan dalam kasus di mana ukuran data sering berubah atau tidak diketahui sejak awal. Namun, karena setiap elemen hanya dapat diakses secara berurutan dari node pertama (head), linked list tidak mendukung akses acak langsung seperti array, sehingga beberapa operasi seperti pencarian membutuhkan waktu lebih lama (Kumar Sanu, 2019).

Beberapa penelitian mencoba mengoptimalkan proses pencarian pada linked list dengan menambahkan struktur pendukung seperti pointer ganda atau indeks tambahan agar proses pencarian bisa mendekati efisiensi binary search (Long & Yan, 2024). Namun, secara umum, linear search tetap menjadi metode paling sesuai untuk linked list karena sifat alaminya yang berorientasi traversal satu arah. Meskipun demikian, dalam konteks pembelajaran struktur data, penerapan binary search pada linked list tetap penting untuk memahami keterbatasan dan hubungan antara algoritma pencarian serta jenis struktur data yang digunakan. Hal ini juga mendukung prinsip bahwa pemilihan algoritma harus disesuaikan dengan karakteristik struktur data yang digunakan agar efisien secara waktu dan penggunaan memori (Sonntag & Colnet, 2023).


## Guided 

### 1. 
```C++
listbuah.cpp

#include "listbuah.h"
#include <iostream>
using namespace std;

bool isEmpty(linkedList List) {
    if(List.first == Nil){
        return true; 
    } else {
        return false;
    }
}

void createList(linkedList &List) {
    List.first = Nil;
}

address alokasi(string nama, int jumlah, float harga) { 
    address nodeBaru = new node; 
    nodeBaru->isidata.nama = nama;
    nodeBaru->isidata.jumlah = jumlah; 
    nodeBaru->isidata.harga = harga;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node) {
    node->next = Nil;
    delete node;
}

void insertFirst(linkedList &List, address nodeBaru) {
    nodeBaru->next = List.first; 
    List.first = nodeBaru;
}

void insertAfter(linkedList &List, address nodeBaru, address Prev) {
    if (Prev != Nil) {
        nodeBaru->next = Prev->next;
        Prev->next = nodeBaru;
    } else {
        cout << "Node sebelumnya tidak valid!" << endl;
    }
}

void insertLast(linkedList &List, address nodeBaru) {
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
void delFirst(linkedList &List){
    address nodeHapus;
    if (isEmpty(List) == false) {
        nodeHapus = List.first;
        List.first = List.first->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "Node pertama berhasil terhapus!" << endl;
    } else {
        cout << "List kosong!" << endl;
    }
}

void delLast(linkedList &List){
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
        cout << "Node terakhir berhasil terhapus!" << endl;
    } else {
        cout << "list kosong" << endl;
    }
}

void delAfter(linkedList &List, address nodeHapus, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil) { 
            nodeHapus = nodePrev->next;       
            nodePrev->next = nodeHapus->next;  
            nodeHapus->next = Nil;         
            dealokasi(nodeHapus);
            cout << "Node setelah node " << nodePrev->isidata.nama << " berhasil terhapus!" << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

void printList(linkedList List) {
    if (isEmpty(List)) {
        cout << "List kosong." << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu != Nil) { 
            cout << "Nama Buah : " << nodeBantu->isidata.nama << ", Jumlah : " << nodeBantu->isidata.jumlah << ", Harga : " << nodeBantu->isidata.harga << endl;
            nodeBantu = nodeBantu->next;
        }
    }
}

int nbList(linkedList List) {
    int count = 0;
    address nodeBantu = List.first;
    while (nodeBantu != Nil) {
        count++;
        nodeBantu = nodeBantu->next; 
    }
    return count;
}

void deleteList(linkedList &List){
    address nodeBantu, nodeHapus;
    nodeBantu = List.first;
    while(nodeBantu != Nil){
        nodeHapus = nodeBantu;
        nodeBantu = nodeBantu->next;
        dealokasi(nodeHapus); 
    }
    List.first = Nil; 
    cout << "List berhasil terhapus!" << endl;
}

//Materi Modul 5 - Update Operations
void updateFirst(linkedList List){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        cout << "Masukkan update data node pertama : " << endl;
        cout << "Nama buah : ";
        cin >> List.first->isidata.nama;
        cout << "Jumlah : ";
        cin >> List.first->isidata.jumlah;
        cout << "Harga : ";
        cin >> List.first->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateLast(linkedList List){
    if (isEmpty(List) == true) {
        cout << "List Kosong!" << endl;
    } else {
        address nodeBantu = List.first;
        while (nodeBantu->next != Nil) {
            nodeBantu = nodeBantu->next;
        }
        cout << "masukkan update data node terakhir : " << endl;
        cout << "Nama buah : ";
        cin >> nodeBantu->isidata.nama;
        cout << "Jumlah : ";
        cin >> nodeBantu->isidata.jumlah;
        cout << "Harga : ";
        cin >> nodeBantu->isidata.harga;
        cout << "Data Berhasil Diupdate!" << endl;
        cout << endl;
    }
}

void updateAfter(linkedList List, address nodePrev){
    if(isEmpty(List) == true){
        cout << "List kosong!" << endl;
    } else {
        if (nodePrev != Nil && nodePrev->next != Nil){
            address nodeBantu = nodePrev->next;
            cout << "masukkan update data node setelah node " << nodePrev->isidata.nama << " : " << endl;
            cout << "Nama buah : ";
            cin >> nodeBantu->isidata.nama;
            cout << "Jumlah : ";
            cin >> nodeBantu->isidata.jumlah;
            cout << "Harga : ";
            cin >> nodeBantu->isidata.harga;
            cout << "Data Berhasil Diupdate!" << endl;
            cout << endl;
        } else {
            cout << "Node sebelumnya (prev) tidak valid!" << endl;
        }
    }
}

listbuah.h

#ifndef LISTBUAH_H
#define LISTBUAH_H
#define Nil nullptr

#include <iostream>
using namespace std;

struct buah{
    string nama;
    int jumlah;
    float harga;
};
typedef buah dataBuah;
typedef struct node *address;
struct node{
    dataBuah isidata;
    address next;
};

struct linkedList{
    address first;
};

bool listEmpty(linkedList List);
void createList(linkedList &List);
address alokasi(string nama, int jumlah, float harga);
void dealokasi(address &node);
void printList(linkedList List);
void insertFirst(linkedList &List, address nodebaru);
void insertAfter(linkedList &List, address nodebaru, address Prev);
void insertLast(linkedList &List, address nodebaru);
void deleteFirst(linkedList &List);
void delLast(linkedList &List);
void deleteAfter(address &List, address &nodehapus, address nodeprev);
int nbList(linkedList List);
void deletelist(linkedList &List);

//materi modul 5 (part 1 update)
void updateFirst(linkedList List);
void updateLast(linkedList List);
void updateAfter(linkedList List, address prev);

#endif

main.cpp

#include "listbuah.h"
#include <iostream>
using namespace std;

int main(){
    linkedList List;
    address nodeA, nodeB, nodeC,nodeD,nodeE;   
    createList(List);

    nodeA=alokasi("jeruk",100,3000);
    nodeB=alokasi("apel",75,4000);
    nodeC=alokasi("pir",87,5000);
    nodeD=alokasi("semangka",43,11500); 
    nodeE=alokasi("durian",15,31450);

    insertFirst(List,nodeA);
    insertLast(List,nodeB);
    insertAfter(List,nodeC,nodeA);
    insertAfter(List,nodeD,nodeC);
    insertLast(List,nodeE);

    cout<<" isi list buat dilakukan insert"<<endl;
    printList(List);
    cout<<"jumlah node:"<<nbList(List)<<endl;
    cout<<endl;

    updateFirst(List);
    updateLast(List);
    updateAfter(List,nodeD);

    cout<<" isi list buah setelah dilakukan update"<<endl;
    printList(List);
    cout<<"jumlah node:"<<nbList(List)<<endl;
    cout<<endl;

    return 0;
}
```
Dari program ini bisa disimpulkan bahwa linked list merupakan cara penyimpanan data yang lebih fleksibel dibandingkan array, karena kita bisa menambah, menghapus, atau mengubah data kapan saja tanpa perlu menggeser atau mengatur ulang seluruh elemen seperti pada array. Setiap data pada linked list disimpan dalam sebuah node yang berisi nilai data dan penunjuk (pointer) ke node berikutnya, sehingga membentuk rantai yang saling terhubung. Hal ini membuat proses pengelolaan data menjadi lebih efisien dan dinamis, terutama saat ukuran data sering berubah, karena memori dapat dialokasikan sesuai kebutuhan tanpa batasan ukuran tetap seperti pada array.

### 2. 

```C++
binary.cpp

#include <iostream>
using namespace std;

//Definisi node untuk linked list
struct Node { 
    int data;      // Menyimpan nilai data
    Node* next;    // Pointer ke node selanjutnya
};

// Fungsi untuk menghitung panjang linked list
int getLength(Node* head) {
    int count = 0;
    Node* temp = head;
    while(temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}


Node* binarySearch(Node* head, int key) {
    int length = getLength(head);      // Hitung panjang list
    int left = 0;
    int right = length - 1;
    
    while(left <= right) {
        int mid = left + (right - left) / 2;  // Cari posisi tengah
        
        // Traverse ke posisi mid
        Node* temp = head;
        for(int i = 0; i < mid; i++) {
            temp = temp->next;
        }
        
        if(temp->data == key) {           // Jika ditemukan
            return temp;
        }
        else if(temp->data < key) {       // Cari di bagian kanan
            left = mid + 1;
        }
        else {                            // Cari di bagian kiri
            right = mid - 1;
        }
    }
    return nullptr;                       // Tidak ditemukan
}

// Fungsi untuk menambahkan node baru di akhir list
void append(Node* &head, int value){
    Node *newNode = new Node{value, nullptr};
    if(!head) head = newNode;
    else{
        Node *temp = head;
        while(temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

int main() {
    Node* head = nullptr;  // Inisialisasi linked list kosong

    // Menambahkan elemen terurut ke linked list (penting untuk binary search!)
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);
    
    int key = 30;  // Nilai yang dicari
    Node* result = binarySearch(head, key); // Panggil fungsi binary search

    if(result != nullptr) {
        cout << "Nilai " << key << " ditemukan dalam linked list." << endl;
    } else {
        cout << "Nilai " << key << " tidak ditemukan dalam linked list." << endl;
    }

    return 0;
}

linear.cpp

#include <iostream>
using namespace std;

//Definisi node untuk linked list
struct Node { 
    int data;      // Menyimpan nilai data
    Node* next;    // Pointer ke node selanjutnya
};

Node* linearSearch(Node* head, int key) {
    Node* current = head;              // Mulai dari node pertama
    while (current != nullptr) {       // Traverse seluruh list
        if (current->data == key) {    // Jika data ditemukan
            return current;            // Kembalikan pointer node tersebut
        }
        current = current->next;       // Pindah ke node berikutnya
    }
    return nullptr;                    // Tidak ditemukan, return nullptr
}

// Fungsi untuk menambahkan node baru di akhir list
void append(Node* &head, int value){
    Node *newNode = new Node{value, nullptr};
    if(!head) head = newNode;
    else{
        Node *temp = head;
        while(temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

int main() {
    Node* head = nullptr;  // Inisialisasi linked list kosong

    // Menambahkan beberapa elemen ke linked list
    append(head, 10);
    append(head, 20);
    append(head, 30);
    
    Node* result = linearSearch(head, 20); // Panggil fungsi linear search

  cout << (result ? "Found" : "Not Found") << endl; // Tampilkan hasil pencarian

    return 0;
}
```
Program ini menunjukkan dua cara mencari data di linked list, yaitu linear search dan binary search. Pada linear search, pencarian dilakukan dengan memeriksa setiap elemen dari awal hingga data yang dicari ditemukan atau list berakhir, sehingga prosesnya sederhana namun menjadi lambat jika data banyak karena harus dicek satu per satu. Sementara itu, binary search bekerja dengan cara membagi data menjadi dua bagian dan mencari di bagian yang sesuai berdasarkan nilai yang dicari, sehingga lebih cepat dengan kompleksitas waktu O(log n), tetapi hanya bisa digunakan jika data sudah terurut dan kurang efisien untuk linked list karena tidak memiliki indeks langsung seperti array. Jadi, linear search lebih cocok untuk semua jenis data, sedangkan binary search lebih cepat namun terbatas penggunaannya.

## Unguided 

### 1. 

```C++
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void append(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

Node* getNodeAt(Node* head, int index) {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        if (count == index)
            return temp;
        temp = temp->next;
        count++;
    }
    return NULL;
}

int length(Node* head) {
    int len = 0;
    Node* temp = head;
    while (temp != NULL) {
        len++;
        temp = temp->next;
    }
    return len;
}

Node* binarySearch(Node* head, int target) {
    int low = 0;
    int high = length(head) - 1;
    int iterasi = 1;

    cout << "\nProses Pencarian:\n";
    while (low <= high) {
        int mid = (low + high) / 2;
        Node* midNode = getNodeAt(head, mid);

        cout << "Iterasi " << iterasi++ << ": Mid = " << midNode->data
             << " (indeks tengah)";

        if (midNode->data == target) {
            cout << " - DITEMUKAN!\n";
            return midNode;
        } else if (midNode->data < target) {
            cout << " -> Cari di bagian kanan\n";
            low = mid + 1;
        } else {
            cout << " -> Cari di bagian kiri\n";
            high = mid - 1;
        }
    }

    cout << "Tidak ada elemen tersisa\n";
    return NULL;
}

int main() {
    cout << "BINARY SEARCH PADA LINKED LIST\n";

    Node* head = NULL;

    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);
    append(head, 60);

    cout << "Linked List yang dibuat: ";
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";

    int cari = 40;
    cout << "Mencari nilai: " << cari << endl;
    Node* hasil = binarySearch(head, cari);
    if (hasil != NULL) {
        cout << "\nHasil: Nilai " << cari << " DITEMUKAN pada linked list!\n";
        cout << "Alamat node: " << hasil << endl;
        cout << "Data node: " << hasil->data << endl;
        cout << "Node berikutnya: " << (hasil->next ? hasil->next->data : 0) << endl;
    } else {
        cout << "\nHasil: Nilai " << cari << " TIDAK DITEMUKAN dalam linked list!\n";
    }

    cari = 25;
    cout << "\nMencari nilai: " << cari << endl;
    hasil = binarySearch(head, cari);
    if (hasil != NULL) {
        cout << "\nHasil: Nilai " << cari << " DITEMUKAN pada linked list!\n";
    } else {
        cout << "\nHasil: Nilai " << cari << " TIDAK DITEMUKAN dalam linked list!\n";
    }

    return 0;
}


```
### Output Unguided 1 :

##### Output 1
![output ung1](https://github.com/Raja2-spec/103112400027_Raja-Muhammad-Lufhti/blob/main/Pertemuan5_Modul4/LAPRAK/Raja_Muhammad_Lufhti_Output_Unguided1.png)

Program ini mencari data di linked list pakai metode binary search. Data dimasukkan berurutan dari 10 sampai 60, lalu program menampilkan proses saat mencari angka 40 dan 25, apakah ditemukan atau tidak.

### 2. 

```C++
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void append(Node*& head, int val) {
    Node* n = new Node();
    n->data = val;
    n->next = NULL;

    if (!head) head = n;
    else {
        Node* t = head;
        while (t->next) t = t->next;
        t->next = n;
    }
}

Node* linearSearch(Node* head, int key) {
    cout << "\nProses Pencarian:\n";
    int i = 1;
    while (head) {
        cout << "Memeriksa node " << i << ": " << head->data;
        if (head->data == key) {
            cout << " (SAMA) - DITEMUKAN!\n";
            return head;
        } else cout << " (tidak sama)\n";
        head = head->next;
        i++;
    }
    cout << "Tidak ada node lagi yang tersisa\n";
    return NULL;
}

int main() {
    cout << "LINEAR SEARCH PADA LINKED LIST\n";

    Node* head = NULL;
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);

    cout << "Linked List yang dibuat: ";
    for (Node* t = head; t; t = t->next)
        cout << t->data << " -> ";
    cout << "NULL\n";

    int cari = 30;
    cout << "Mencari nilai: " << cari << endl;
    Node* hasil = linearSearch(head, cari);
    if (hasil) {
        cout << "\nHasil: Nilai " << cari << " DITEMUKAN pada linked list!\n";
        cout << "Alamat node: " << hasil << endl;
        cout << "Data node: " << hasil->data << endl;
        cout << "Node berikutnya: " 
             << (hasil->next ? hasil->next->data : 0) << endl;
    } else
        cout << "\nHasil: Nilai " << cari << " TIDAK DITEMUKAN dalam linked list!\n";

    cari = 25;
    cout << "\nMencari nilai: " << cari << endl;
    hasil = linearSearch(head, cari);
    if (!hasil)
        cout << "\nHasil: Nilai " << cari << " TIDAK DITEMUKAN dalam linked list!\n";

    return 0;
}

Program ini mencari data di dalam linked list dengan cara mengecek satu per satu dari awal sampai ketemu, cara ini akan lebih lama kalau datanya banyak karena harus dicek semuanya.
```
### Output Unguided 2 :

##### Output 1
![output ung2](https://github.com/Raja2-spec/103112400027_Raja-Muhammad-Lufhti/blob/main/Pertemuan5_Modul4/LAPRAK/Raja_Muhammad_Lufhti_Output_Unguided2.png)

Program ini mencari angka di dalam linked list menggunakan metode binary search. Data dimasukkan berurutan dari 10 sampai 60, lalu program membagi list jadi dua untuk mencari nilai yang dicari, misalnya 40 dan 25. Setiap langkah pencarian ditampilkan hingga data ditemukan atau tidak ditemukan.

### Kesimpulan
Berdasarkan hasil praktikum dan teori yang telah dipelajari, dapat disimpulkan bahwa linked list merupakan struktur data yang sangat fleksibel untuk operasi penambahan (insert), penghapusan (delete), maupun pembaruan data (update). Setiap node dapat diubah tanpa harus memindahkan seluruh elemen seperti pada array, sehingga lebih efisien ketika ukuran data sering berubah. Namun, untuk operasi pencarian, efisiensinya bergantung pada algoritma yang digunakan.

Linear search merupakan metode pencarian yang paling cocok diterapkan pada linked list karena strukturnya yang berurutan dan tidak memiliki indeks langsung. Meskipun proses pencariannya relatif lebih lambat pada data besar, metode ini sederhana dan selalu dapat digunakan baik untuk data yang terurut maupun tidak. Di sisi lain, binary search hanya efektif jika struktur data mendukung akses acak seperti array. Dalam linked list, karena untuk mencapai elemen tengah saja perlu traversal berulang, binary search kehilangan keunggulan kecepatannya dan justru menjadi kurang efisien dibanding linear search.

Dengan demikian, dapat disimpulkan bahwa dalam penggunaan linked list, linear search merupakan pilihan yang tepat untuk pencarian data, sementara binary search lebih baik diterapkan pada struktur data yang memiliki indeks langsung seperti array. Praktikum ini juga memperkuat pemahaman bahwa pemilihan algoritma harus disesuaikan dengan karakteristik struktur data yang digunakan agar efisiensi program tetap optimal.

## Referensi
<br> [1]Kumar Sanu. (2019). Binary Search in Linked List. International Journal of Engineering Research & Technology (IJERT), Vol. 8 Issue 03.
https://www.ijert.org/research/binary-search-in-linked-list-IJERTV8IS030239.pdf
[2]International Journal of Computer Science and Information Technologies (IJCSIT). (2014). Analysis of Searching Techniques in Data Structures. Vol. 5 (1), 01–05.
https://ijcsit.com/docs/Volume%205/vol5issue01/ijcsit2014050101.pdf
[3]GeeksforGeeks. (2023). Binary Search in Linked List.
https://www.geeksforgeeks.org/binary-search-in-linked-list/