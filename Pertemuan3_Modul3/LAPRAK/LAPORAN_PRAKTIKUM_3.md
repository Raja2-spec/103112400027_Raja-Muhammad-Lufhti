# <h1 align="center">Laporan Praktikum Modul 3 - Abstract Data Type (ADT)</h1>
<p align="center">Raja Muhammad Lufhti - 103112400027</p>

## Dasar Teori

Abstract Data Type (ADT) adalah konsep dalam pemrograman yang mendefinisikan tipe data beserta operasi-operasi yang dapat dilakukan terhadapnya, tanpa memperhatikan bagaimana data tersebut diimplementasikan. ADT memisahkan antara interface (apa yang bisa dilakukan) dan implementation (bagaimana dilakukan). Dalam C++, ADT dapat direpresentasikan menggunakan struct atau class untuk mengelompokkan data dan fungsi yang terkait menjadi satu kesatuan.

Pada kode di atas, struct pelajaran dan struct Mahasiswa adalah contoh ADT karena keduanya memiliki atribut (seperti nama, kode, nilai) serta fungsi terkait (seperti buat_pelajaran(), tampil_pelajaran(), atau hitungNilaiAkhir()) yang beroperasi atas data tersebut. Prinsip ini membantu menciptakan program yang modular, mudah dipahami, dan dapat digunakan kembali (reusable).

Selain itu, konsep fungsi dan pointer yang digunakan dalam program array juga termasuk penerapan dari abstraksi data dan pengelolaan memori dalam ADT, karena fungsi dan pointer memberikan cara terstruktur untuk memanipulasi data tanpa harus mengaksesnya secara langsung. [1].

## Guided

### 1. Program Data Mahasiswa dengan Struct
#### Mahasiswa.h
```C++
#include<iostream>
using namespace std;
int main(){
    int arr [5];
    for (int i = 0; i < 5; i++){
        cout<<"Masukkan nilai indeks ke-"<<i<<": ";
        cin>>arr[i];
    }
    int j = 0;
    while (j < 5){
        cout<< "Isi indeks ke-"<< j <<" i "<< arr[j]<< endl;
        j++;
    }
    return 0;
}
```

#### Mahasiswa.cpp
```C++
#include <iostream>
#include "Mahasiswa.h"

using namespace std;

// Realisasi fungsi InputMhs
void inputMhs(mahasiswa &m) {
    cout << "Input NIM: "; 
    cin >> m.nim;
    cout << "Input Nilai 1: "; 
    cin >> m.nilai1;
    cout << "Input Nilai 2: "; 
    cin >> m.nilai2;
}

// Realisasi fungsi rata2
float rata2(mahasiswa m) {
    return (float)(m.nilai1 + m.nilai2) / 2;
}
```

#### Main.cpp
```C++
#include<iostream>
#include "Mahasiswa.h"
#include<cstdlib>

using namespace std;

int main () {
    mahasiswa mhs;

    inputMhs(mhs);

    cout << "Rata-rata: " << rata2(mhs) << endl;
    system("pause");
    
    return 0;
}
```

Program ini terdiri dari dua bagian. Bagian pertama meminta pengguna mengisi lima nilai ke dalam array dan menampilkannya kembali. Bagian kedua menggunakan ADT mahasiswa dengan fungsi inputMhs() untuk mengisi data NIM dan nilai, serta rata2() untuk menghitung rata-rata. Di fungsi utama, data mahasiswa dimasukkan lalu hasil rata-ratanya ditampilkan ke layar.

## Unguided 

### 1. Program Menghitung Nilai Akhir Mahasiswa
```C++
#include <iostream>
using namespace std;

struct Mahasiswa {
    string nama;
    string nim;
    float uts, uas, tugas, nilaiAkhir;
};

float hitungNilaiAkhir(float uts, float uas, float tugas) {
    return (0.3 * uts) + (0.4 * uas) + (0.3 * tugas);
}

int main() {
    Mahasiswa mhs[10];
    int n;

    cout << "Masukkan jumlah mahasiswa (1 - 10): ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\nData mahasiswa ke-" << i + 1 << endl;
        cout << "NAMA   : ";
        cin.ignore();
        getline(cin, mhs[i].nama);
        cout << "NIM    : ";
        cin >> mhs[i].nim;
        cout << "UTS    : ";
        cin >> mhs[i].uts;
        cout << "UAS    : ";
        cin >> mhs[i].uas;
        cout << "TUGAS  : ";
        cin >> mhs[i].tugas;

        mhs[i].nilaiAkhir = hitungNilaiAkhir(mhs[i].uts, mhs[i].uas, mhs[i].tugas);
    }

    cout << "\n=== DATA MAHASISWA ===\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ". " << mhs[i].nama
             << " (" << mhs[i].nim << ")"
             << " | Nilai Akhir: " << mhs[i].nilaiAkhir << endl;
    }

    return 0;
}

```
### Output Unguided 1 :

##### Output 1
![Output Program 1](https://github.com/Raja2-spec/103112400027_Raja-Muhammad-Lufhti/blob/main/Pertemuan3_Modul3/LAPRAK/Raja_Muhammad_Lufhti-Output-Unguided01.png)

Program di atas digunakan untuk menyimpan dan menampilkan data maksimal sepuluh mahasiswa yang mencakup nama, NIM, nilai UTS, UAS, dan tugas. Program meminta pengguna memasukkan jumlah mahasiswa, lalu menginput data masing-masing mahasiswa melalui perulangan. Nilai akhir setiap mahasiswa dihitung menggunakan rumus (0.3 * UTS) + (0.4 * UAS) + (0.3 * Tugas) melalui fungsi hitungNilaiAkhir. Setelah semua data dimasukkan, program menampilkan daftar nama, NIM, dan nilai akhir setiap mahasiswa di layar.

### 2. Program Struct untuk Data Mata Pelajaran
```C++
#include <iostream>
using namespace std;

struct pelajaran {
    string namaMapel;
    string kodeMapel;
};

pelajaran buat_pelajaran(string namapel, string kodepel) {
    pelajaran p;
    p.namaMapel = namapel;
    p.kodeMapel = kodepel;
    return p;
}

void tampil_pelajaran(pelajaran pel) {
    cout << "nama pelajaran : " << pel.namaMapel << endl;
    cout << "nilai          : " << pel.kodeMapel << endl;
}

int main() {
    string namapel = "Struktur Data";
    string kodepel = "STD";

    pelajaran pel = buat_pelajaran(namapel, kodepel);
    tampil_pelajaran(pel);

    return 0;
}

```
### Output Unguided 2 :

##### Output 2
![Output Program 2](https://github.com/Raja2-spec/103112400027_Raja-Muhammad-Lufhti/blob/main/Pertemuan3_Modul3/LAPRAK/Raja_Muhammad_Lufhti-Output-Unguided02.png)

Program di atas membuat tipe data struct bernama pelajaran yang menyimpan nama dan kode mata pelajaran. Fungsi buat_pelajaran() digunakan untuk membuat dan mengisi data pelajaran berdasarkan input parameter, sedangkan fungsi tampil_pelajaran() menampilkan isi data tersebut ke layar. Dalam fungsi main(), program membuat data pelajaran dengan nama “Struktur Data” dan kode “STD”, lalu memanggil fungsi tampil_pelajaran() untuk menampilkan hasilnya.

### 3. Program Penukaran Elemen Matriks
```C++
#include <iostream>
using namespace std;

void tampilArray(int arr[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void tukarElemen(int arr1[3][3], int arr2[3][3], int x, int y) {
    int temp = arr1[x][y];
    arr1[x][y] = arr2[x][y];
    arr2[x][y] = temp;
}

void tukarPointer(int *p1, int *p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int main() {
    int A[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int B[3][3] = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };

    cout << "Array A sebelum ditukar:\n";
    tampilArray(A);
    cout << "Array B sebelum ditukar:\n";
    tampilArray(B);

    tukarElemen(A, B, 1, 1);

    cout << "\nArray A sesudah ditukar:\n";
    tampilArray(A);
    cout << "Array B sesudah ditukar:\n";
    tampilArray(B);
    int x = 10, y = 20;
    int *p1 = &x;
    int *p2 = &y;

    cout << "\nSebelum tukar pointer: x = " << x << ", y = " << y << endl;
    tukarPointer(p1, p2);
    cout << "Sesudah tukar pointer: x = " << x << ", y = " << y << endl;

    return 0;
}
        
```
### Output Unguided 3 :

##### Output 1
![Output Program 3](https://github.com/Raja2-spec/103112400027_Raja-Muhammad-Lufhti/blob/main/Pertemuan3_Modul3/LAPRAK/Raja_Muhammad_Lufhti-Output-Unguided03.png)

Program ini menampilkan dua array 3x3, menukar salah satu elemennya dengan fungsi tukarElemen(), dan menampilkan hasilnya kembali. Selain itu, program juga menukar nilai dua variabel x dan y menggunakan pointer melalui fungsi tukarPointer().

## Kesimpulan
Dari keseluruhan materi dan program yang telah dibuat pada Modul 3 tentang Abstract Data Type (ADT), dapat disimpulkan bahwa ADT berperan penting dalam membangun program yang terstruktur, efisien, dan mudah dikelola. Melalui penerapan struct dan fungsi di C++, kita dapat memisahkan antara data dan operasi yang bekerja atas data tersebut, sehingga kode menjadi lebih modular dan mudah dikembangkan. Program-program seperti pengolahan data mahasiswa, data mata pelajaran, dan penukaran elemen matriks menunjukkan penerapan konsep ADT, fungsi, serta pointer dalam mengelola data secara terorganisir. Dengan memahami ADT, mahasiswa dapat membuat program yang tidak hanya berfungsi dengan baik tetapi juga memiliki struktur logis yang rapi, mudah dibaca, serta dapat digunakan kembali untuk kebutuhan lain (reusable).

## Referensi 

[1]. Sahdan, N., & Isnaini, M. (2021). Implementasi Abstract Data Type pada Pemrograman C++ untuk Pembelajaran Struktur Data. Jurnal Teknologi dan Sistem Informasi, 9(2), 115–123.
→ Membahas penerapan ADT menggunakan struct dan class pada bahasa C++ sebagai dasar pemahaman struktur data.
[2]Susanto, H., & Arifin, M. (2020). Penerapan Konsep Abstraksi Data dalam Pengembangan Program Modular. Jurnal Informatika dan Komputer, 6(1), 45–53.
→ Menjelaskan bagaimana ADT membantu membangun program yang terstruktur dan mudah dipelihara.
