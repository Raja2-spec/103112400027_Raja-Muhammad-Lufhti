# <h1 align="center">Laporan Praktikum Modul 7 - STACK</h1>
<p align="center"> Raja Muhammad Lufhti - 103112400027 </p>

## Dasar Teori
Stack adalah struktur data yang bekerja seperti tumpukan barang: apa yang terakhir ditaruh akan menjadi yang pertama diambil (LIFO – Last In, First Out). Stack hanya punya satu titik akses, yaitu TOP, tempat semua proses masuk dan keluar dilakukan.

Ada dua cara mewakili stack:
1. Menggunakan pointer (linked list) → ukuran fleksibel, elemen baru selalu ditambahkan di depan.
2. Menggunakan array (tabel) → ukuran tetap, TOP bergerak naik-turun sesuai jumlah elemen.

Operasi utama stack hanya dua:
- Push → menambah data ke bagian atas.
- Pop → mengambil data paling atas.
Karena hanya TOP yang boleh disentuh, stack lebih sederhana, cepat, dan mudah diprediksi. Fungsi lain seperti isEmpty, printInfo, atau balikStack hanyalah pendukung dari dua operasi inti tadi.
## Guided 

### 1. 
```C++
main.cpp
#include "stack.h"
#include <iostream>

using namespace std;

int main(){
    stack listStack;
    address nodeA, nodeB, nodeC, nodeD, nodeE = Nil;
    createStack(listStack);

    nodeA = alokasi(1);
    nodeB = alokasi(2);
    nodeC = alokasi(3);
    nodeD = alokasi(4);
    nodeE = alokasi(5);

    push(listStack, nodeA);
    push(listStack, nodeB);
    push(listStack, nodeC);
    push(listStack, nodeD);
    push(listStack, nodeE);
    cout << endl;

    cout << "--- Stack setelah push ---" << endl;
    view(listStack);
    cout << endl;

    pop(listStack);
    pop(listStack);
    cout << endl;

    cout << "--- Stack setelah pop 2 kali ---" << endl;
    view(listStack);
    cout << endl;

    update(listStack, 2);
    update(listStack, 1);
    update(listStack, 4);
    cout << endl;

    cout << "--- Stack setelah update ---" << endl;
    view(listStack);
    cout << endl;

    searchData(listStack, 4);
    searchData(listStack, 9);

    return 0;
}

stack.cpp

#include "stack.h"
#include <iostream>

using namespace std;

bool isEmpty(stack listStack){
    if(listStack.top == Nil){
        return true;
    } else {
        return false;
    }
}

void createStack(stack &listStack){
    listStack.top = Nil;
}

address alokasi(int angka){
    address nodeBaru = new node;
    nodeBaru->dataAngka = angka;
    nodeBaru->next = Nil;
    return nodeBaru;
}

void dealokasi(address &node){
    node->next = Nil;
    delete node;
}

void push(stack &listStack, address nodeBaru){
    nodeBaru->next = listStack.top;
    listStack.top = nodeBaru;
    cout << "Node " << nodeBaru->dataAngka << " berhasil ditambahkan kedalam stack!" << endl;
}

void pop(stack &listStack){
    address nodeHapus;
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        nodeHapus = listStack.top;
        int data = nodeHapus->dataAngka;
        listStack.top = listStack.top->next;
        nodeHapus->next = Nil;
        dealokasi(nodeHapus);
        cout << "node " <<  data << " berhasil dihapus dari stack!" << endl;
    }
}

void update(stack &listStack, int posisi){
    if(isEmpty(listStack) == true){
        cout << "Stack kosong!" << endl;
    } else {
        if(posisi <= 0){
            cout << "Posisi tidak valid!" << endl;
        } else {
            address nodeBantu = listStack.top;
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

void view(stack listStack){ //mencetak dari tumpukan paling atas ke tumpukan paling bawah
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
        while(nodeBantu != Nil){
            cout << nodeBantu->dataAngka << " ";
            nodeBantu = nodeBantu->next;
        }
    }
    cout << endl;
}

void searchData(stack listStack, int data){
    if(isEmpty(listStack) == true){
        cout << "List kosong!" << endl;
    } else {
        address nodeBantu = listStack.top;
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
            cout << "Data " << data << " tidak ditemukan didalam stack!" << endl;
            cout << endl;
        }
    }
}

stack.h

#ifndef STACK_H
#define STACK_H
#define Nil NULL    

#include<iostream>
using namespace std;

typedef struct node *address;

struct node{
    int dataAngka;
    address next;
};

struct stack{
    address top;
};

bool isEmpty(stack listStack);
void createStack(stack &listStack);
address alokasi(int angka);
void dealokasi(address &node);
void push(stack &listStack, address nodeBaru);
void pop(stack &listStack);
void update(stack &listStack, int posisi);
void view(stack listStack);
void searchData(stack listStack, int data);

#endif 
```
Program di atas berisi implementasi lengkap dari struktur data Stack menggunakan linked list dalam C++. Program ini mendemonstrasikan operasi-operasi dasar stack seperti push dan pop, serta fungsi tambahan seperti update dan search. Kode diorganisir dengan baik ke dalam file header (.h), implementasi (.cpp), dan program utama (main.cpp) untuk menunjukkan penggunaan praktis dari struktur data tersebut.

### 2. 

```C++
main.cpp

#include "stack.h"
#include <iostream>

using namespace std;

int main() {
    stack S;
    createStack(S);

    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);

    cout << "Stack Awal:" << endl;
    printinfo(S);

    cout << "balik stack" << endl;
    balikStack(S);

    cout << "Stack Setelah dibalik:" << endl;
    printinfo(S);

    system("pause");
    return 0;
}


stack.cpp

#include <iostream>
#include "stack.h"

using namespace std;

// Fungsi untuk membuat stack baru dengan menginisialisasi top = Nil
void createStack(stack &S) {
    S.top = Nil;  // Inisialisasi top dengan nilai Nil mendakan stack kosong
}

// Fungsi untuk mengecek apakah stack kosong
bool isEmpty(stack S) {
    return S.top == Nil;  // Mengembalikan true jika top bernilai Nil, false jika tidak
}

// Fungsi untuk mengecek apakah stack penuh
bool isFull(stack S) {
    return S.top == MaxEl - 1;  // Mengembalikan true jika top mencapai batas maksimum (MaxEl-1)
}

// Fungsi untuk menambah elemen ke dalam stack (push)
void push(stack &S, infotype x) {
    if (!isFull(S)) {  // Cek apakah stack belum penuh
        S.top++;  // Increment nilai top
        S.info[S.top] = x;  // Masukkan nilai x ke array info pada indeks top
    } else {
        cout << "Stack Penuh!" << endl;  // Tampilkan pesan jika stack penuh
    }
}

// Fungsi untuk mengambil elemen teratas dari stack (pop)
infotype pop(stack &S) {
    infotype x = -999;  // Inisialisasi nilai default jika stack kosong
    if (!isEmpty(S)) {  // Cek apakah stack tidak kosong
        x = S.info[S.top];  // Ambil nilai teratas
        S.top--;  // Decrement nilai top
    } else {
        cout << "Stack Kosong!" << endl;  // Tampilkan pesan jika stack kosong
    }
    return x;  // Kembalikan nilai yang diambil
}

// Fungsi untuk menampilkan isi stack
void printinfo(stack S) {
    if (isEmpty(S)) {  // Cek apakah stack kosong
        cout << "Stack Kosong" << endl;  // Tampilkan pesan jika kosong
    } else {
        cout << "[TOP] ";  // Tampilkan penanda posisi top
        for (int i = S.top; i >= 0; i--) {  // Loop dari top sampai dasar stack
            cout << S.info[i] << " ";  // Tampilkan setiap elemen
        }
        cout << endl;  // Pindah baris setelah selesai
    }
}

// Fungsi untuk membalik urutan elemen dalam stack
void balikStack(stack &S) {
    if (!isEmpty(S)) {  // Cek apakah stack tidak kosong
        stack temp1, temp2;  // Deklarasi dua stack temporary
        createStack(temp1); createStack(temp2);  // Inisialisasi kedua stack temporary

        while (!isEmpty(S)) { push(temp1, pop(S)); }  // Pindahkan semua elemen ke temp1 (urutan terbalik)

        while (!isEmpty(temp1)) { push(temp2, pop(temp1)); }  // Pindahkan ke temp2 (urutan terbalik lagi)

        while (!isEmpty(temp2)) { push(S, pop(temp2)); }  // Kembalikan ke stack asal (urutan sudah benar)
    }
}

stack.h

#ifndef STACK_H
#define STACK_H
#define MaxEl 20
#define Nil -1

typedef int infotype;

struct stack {
    infotype info[MaxEl];//Array unutk menyimpan elemen stack
    int top;
};

void createStack(stack &S);
bool isEmpty(stack S);
bool isFull(stack S);
void push(stack &S, infotype X); //Menambahkan elemen ke dalam stack
infotype pop(stack &S); //Mengambil elemn teratas dari stack
void printinfo(stack S); //Menampilkan isi stack
void balikStack(stack &S); //Membalik urutan elemen dalam stack
#endif


```

Program ini berisi implementasi struktur data Stack menggunakan array statis di C++. Berbeda dengan GUIDED pertama yang menggunakan linked list, pendekatan ini memiliki kapasitas maksimum yang telah ditentukan. Program ini mendemonstrasikan operasi dasar stack (push, pop) dan secara khusus menyoroti fungsi untuk membalik urutan elemen di dalam stack (balikStack).

## Unguided 

### 1. 

```C++
main.cpp

#include <iostream>
#include "stack.h"

using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Stack S;
    createStack(S);

    push(S, 3);
    push(S, 4);
    push(S, 8);
    pop(S);
    push(S, 2);
    push(S, 3);
    pop(S);
    push(S, 9);

    printInfo(S);
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);

    return 0;
}


stack.cpp

#include "stack.h"
#include <iostream>
using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

void push(Stack &S, infotype x) {
    if (S.top < 19) { 
        S.top++;
        S.info[S.top] = x;
    }
}

infotype pop(Stack &S) {
    if (S.top >= 0) {
        infotype x = S.info[S.top];
        S.top--;
        return x;
    }
    return -1;
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);

    while (S.top >= 0) {
        push(temp, pop(S));
    }

    S = temp;
}

stack.h

#ifndef STACK_H
#define STACK_H

typedef int infotype;

struct Stack {
    infotype info[20];
    int top;
};

void createStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);

#endif

Program ini berisi implementasi struktur data Stack menggunakan array statis. Program ini berfungsi sebagai latihan praktis, dengan fokus utama pada demonstrasi fungsi untuk membalik urutan elemen dalam stack (balikStack). Implementasi balikStack di sini sedikit lebih efisien, hanya menggunakan satu stack sementara.

```
### Output Unguided 1 :

##### Output 1
![output ung1](https://github.com/Raja2-spec/103112400027_Raja-Muhammad-Lufhti/blob/main/Pertemuan7_Modul7/LAPRAK/Raja_Muhammad_Lufhti_Output_UNGUIDED01.png)


### 2. 

```C++
main.cpp

#include <iostream>
#include "stack.h"

using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Stack S;
    createStack(S);

    pushAscending(S, 3);
    pushAscending(S, 4);
    pushAscending(S, 8);
    pushAscending(S, 2);
    pushAscending(S, 3);
    pushAscending(S, 9);

    printInfo(S);           
    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);

    return 0;
}

stack.cpp

#include "stack.h"
#include <iostream>
using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

void push(Stack &S, infotype x) {
    if (S.top < 19) {
        S.top++;
        S.info[S.top] = x;
    }
}

infotype pop(Stack &S) {
    if (S.top >= 0) {
        infotype x = S.info[S.top];
        S.top--;
        return x;
    }
    return -1; 
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);
    while (S.top >= 0) {
        push(temp, pop(S));
    }
    S = temp;
}

void pushAscending(Stack &S, infotype x) {
    Stack temp;
    createStack(temp);

    while (S.top >= 0 && S.info[S.top] > x) {
        push(temp, pop(S));
    }

    push(S, x);

    while (temp.top >= 0) {
        push(S, pop(temp));
    }
}

stack.h

#ifndef STACK_H
#define STACK_H

typedef int infotype;

struct Stack {
    infotype info[20];
    int top;
};

void createStack(Stack &S);
void push(Stack &S, infotype x);
infotype pop(Stack &S);
void printInfo(Stack S);
void balikStack(Stack &S);
void pushAscending(Stack &S, infotype x);

#endif

Program ini berisi implementasi Stack berbasis array statis yang memperkenalkan fungsionalitas khusus: pushAscending. Fungsi ini memungkinkan elemen baru dimasukkan ke dalam stack sambil tetap menjaga urutan elemen secara menaik (dari dasar ke puncak). Program utama mendemonstrasikan bagaimana penggunaan pushAscending menghasilkan stack yang terurut secara otomatis. Ini adalah contoh latihan algoritma yang menunjukkan bagaimana struktur data dasar dapat dimodifikasi untuk kebutuhan yang lebih spesifik.
```
### Output Unguided 2 :

##### Output 
![output ung2](https://github.com/Raja2-spec/103112400027_Raja-Muhammad-Lufhti/blob/main/Pertemuan7_Modul7/LAPRAK/Raja_Muhammad_Lufhti_Output_UNGUIDED02.png)

### 3.

```C++

main.cpp

#include <iostream>
#include "stack.h"

using namespace std;

int main() {
    cout << "Hello world!" << endl;

    Stack S;
    createStack(S);

    getInputStream(S);
    printInfo(S);

    cout << "balik stack" << endl;
    balikStack(S);
    printInfo(S);

    return 0;
}

stack.cpp

#include "stack.h"
#include <iostream>
using namespace std;

void createStack(Stack &S) {
    S.top = -1;
}

void push(Stack &S, infotype x) {
    if (S.top < 19) {
        S.top++;
        S.info[S.top] = x;
    }
}

infotype pop(Stack &S) {
    if (S.top >= 0) {
        infotype x = S.info[S.top];
        S.top--;
        return x;
    }
    return -1;
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    for (int i = S.top; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    Stack temp;
    createStack(temp);
    while (S.top >= 0) {
        push(temp, pop(S));
    }
    S = temp;
}

void getInputStream(Stack &S) {
    cout << " ";

    char c = cin.get();   
    while (c != '\n') {   
        if (c >= '0' && c <= '9') {  
            int x = c - '0';  
            push(S, x);
        }
        c = cin.get();   
    }
}

stack.h

#ifndef STACK_H
#define STACK_H

typedef int infotype;

struct Stack {
    infotype info[20];
    int top;
};

void createStack(Stack &S);

void push(Stack &S, infotype x);

infotype pop(Stack &S);

void printInfo(Stack S);

void balikStack(Stack &S);

void pushAscending(Stack &S, infotype x);

void getInputStream(Stack &S);

#endif

```
### Output Unguided 3 :

##### Output 
![output ung3](https://github.com/Raja2-spec/103112400027_Raja-Muhammad-Lufhti/blob/main/Pertemuan7_Modul7/LAPRAK/Raja_Muhammad_Lufhti_Output_UNGUIDED03.png)


### Kesimpulan
Stack adalah struktur data sederhana yang bekerja dengan prinsip LIFO. Semua operasi hanya dilakukan pada bagian atas sehingga penggunaannya cepat dan mudah dikontrol. Baik memakai pointer maupun array, yang penting adalah menjaga agar TOP selalu sesuai dengan keadaan stack. Konsep stack ini menjadi dasar banyak mekanisme penting seperti pemanggilan fungsi, undo-redo, dan proses parsing.

## Referensi
<br> [1]Srivastava, S., & Gupta, G. (2019). Efficient Stack Implementations and Applications in Expression Parsing. IJACSA.[2]Patel, H. (2019). Comparative Analysis of Stack Implementations Using Array and Linked List. IJERT.[3]Liu, P., & Zhao, X. (2021). Stack-Based Memory Management in Modern Programming Languages. JCEA.[4]García, F. D., et al. (2022). Stack Data Structures in Algorithm Optimization. ACM Computing Surveys.