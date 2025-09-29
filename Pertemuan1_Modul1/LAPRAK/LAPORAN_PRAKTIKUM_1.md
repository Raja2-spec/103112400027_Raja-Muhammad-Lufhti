# <h1 align="center">Laporan Praktikum Modul 1 - Codeblocks IDE & Pengenalan Bahas C++ (Bagian Pertama)</h1>
<p align="center">Raja Muhammad Lufhti - 103112400027</p>

## Dasar Teori
Pemrograman adalah proses menuliskan instruksi logis agar komputer dapat menjalankan tugas tertentu. Bahasa C++ termasuk bahasa pemrograman tingkat tinggi yang banyak digunakan karena mendukung paradigma prosedural dan berorientasi objek. Dalam praktiknya, IDE seperti Code::Blocks mempermudah penulisan, kompilasi, dan eksekusi program.

Konsep dasar pemrograman meliputi variabel dan tipe data, operator, percabangan (if, switch), perulangan (for, while, do–while), serta struktur data sederhana seperti array dan struct. Penguasaan konsep ini menjadi fondasi untuk menyusun logika program dan memecahkan masalah komputasi [1].

## Guided 

### 1. GUIDED 1

```C++
#include<iostream>
using namespace std;

int main() {
    int angka;
    cout << "Masukkan angka pertama: ";
    cin >> angka;
    cout << "Masukkan yang dimaskukan adalah " << angka << endl;
    return 0;
}
```
Program Cpp sederhana yang meminta pengguna untuk memasukkan sebuah angka. Setelah angka dimasukkan, program akan menampilkan angka tersebut ke tampilan layar

### 2. GUIDED 2

```C++
#include<iostream>
using namespace std;

int main() {
    int angka1, angka2;
    cout << "Masukkan angka pertama: ";
    cin >> angka1;
    cout << "Masukkan angka kedua: ";
    cin >> angka2;

    cout << "penjumlahan: " << angka1 + angka2 << endl;
    cout << "pengurangan: " << angka1 - angka2 << endl;
    cout << "perkalian: " << angka1 * angka2 << endl;
    cout << "pembagian: " << angka1 / angka2 << endl;
    cout << "modulus: " << angka1 % angka2 << endl;

    return 0;
}
```
Program ini menerima dua input bilangan bulat dari pengguna, lalu menampilkan hasil penjumlahan, pengurangan, perkalian, pembagian, dan modulus dari kedua bilangan tersebut.

### 3. GUIDED3

```C++
#include<iostream>
using namespace std;

int main() {
    int angka1, angka2;
    cout << "Masukkan angka pertama: ";
    cin >> angka1;
    cout << "Masukkan angka kedua: ";
    cin >> angka2;

    if (angka1 > angka2 ) {
        cout << angka1 << " kurang dari " << angka2 << endl;
    } else {
        cout << angka1 << " lebih dari " << angka2 << endl;
    }

    if (angka1 == angka2) {
        cout << angka1 << " sama dengan " << angka2 << endl;
    } else if (angka1 != angka2) {
        cout << " angka berbeda " << endl;
    }

     int pilihan;
    cout << "MENU" << endl;
    cout << "1. Penjumlahan" << endl;
    cout << "2. Pengurangan" << endl;
    cout << "masukan pilihan: ";
    cin >> pilihan;

    switch (pilihan){
        case 1:
        cout << "Penjumlahan :" << angka1 + angka2 << endl;
        cout << endl;
        break; 
        case 2:
        cout << "Pengurangan :" << angka1 - angka2 << endl;
        cout << endl;
        break;
        default:
        cout << "Pilihan Salah" << endl;

    }
    return 0;
}

```
Program ini meminta dua angka dari pengguna, kemudian:
-Membandingkan kedua angka (lebih besar/kecil, sama atau berbeda).
-Menyediakan menu untuk menghitung penjumlahan atau pengurangan berdasarkan pilihan pengguna.

### 4. GUIDED4

```C++
#include <iostream>
using namespace std;

 int main(){
    int angka1;
    cout << "masukan angka1 : ";
    cin >> angka1;

    for (int i = 0; i  < angka1; i++){
      cout << i << " - ";
    }
    cout << endl;

    int j = 10;
    while (j > angka1){
      cout << j << " - ";
      j--;
    }

    cout << endl;
    int k = 10;
    do {
      cout << k << " - ";
    }while (k < angka1);

     return  0;
    
 }

```
Program ini meminta input satu angka, lalu menggunakan tiga jenis perulangan: for untuk mencetak angka mulai dari 0 hingga sebelum angka yang dimasukkan, while untuk mencetak angka dari 10 turun hingga lebih besar dari angka yang dimasukkan, dan do–while yang selalu mencetak angka 10 sekali meskipun kondisi salah, sehingga program ini menunjukkan perbedaan cara kerja ketiga loop tersebut.

### 5. GUIDED5

```C++
#include<iostream>
using namespace std;

int main(){
    const int MAX = 5;
    struct rapot{
        string nama;
        float nilai;
    };
    rapot siswa[MAX];

    for(int i = 0; i < MAX; i++){
        cout << "masukkan nama siswa : ";
        cin >> siswa[i].nama;
        cout << endl;
        cout << "masukkan nilai siswa : ";
        cin >> siswa[i].nilai;
    }

    int j = 0;
    while(j < MAX){
        cout << "nama siswa : " << siswa[j].nama << ", nilai : " << siswa[j].nilai << endl;
    }
    return 0;
}

```
Program ini membuat array berisi 5 data siswa dengan struct (nama dan nilai), meminta input melalui loop for, lalu menampilkan datanya dengan while; namun loop while akan jadi infinite loop karena variabel j tidak pernah ditambah.


## Unguided 

### 1. Soal Unguided1

```C++
#include <iostream>
using namespace std;
int main() {
    float r, j;
    cout << "masukkan angka ke1 :";
    cin >> r;
    cout << "masukkan angka ke2 :";
    cin >> j;

    cout << "penjumlahan :" << r + j << endl;
    cout << "pengurangan :" << r - j << endl;
    cout << "perkalian :" << r * j << endl;
    cout << "pembagian :" << r/ j << endl;
    return 0;
}   
```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Raja2-spec/103112400027_Raja-Muhammad-Lufhti/blob/main/Pertemuan1_Modul1/LAPRAK/Raja_Muhammad_Lufhti-Output-Unguided1.png)

penjelasan unguided 1:
Program C++ di atas meminta dua angka dari pengguna lalu menampilkan hasil penjumlahan, pengurangan, perkalian, dan pembagiannya.


### 2. Soal Unguided2

```C++
#include <iostream>
using namespace std;
int main() {
    string satuan[] = {"", "satu", "dua", "tiga", "empat", "lima", 
                       "enam", "tujuh", "delapan", "sembilan"};
    string belasan[] = {"sepuluh", "sebelas", "dua belas", "tiga belas", 
                        "empat belas", "lima belas", "enam belas", 
                        "tujuh belas", "delapan belas", "sembilan belas"};
    string puluhan[] = {"", "", "dua puluh", "tiga puluh", "empat puluh", 
                        "lima puluh", "enam puluh", "tujuh puluh", 
                        "delapan puluh", "sembilan puluh"};

    int n;
    cout << "Masukkan angka (0 - 100): ";
    cin >> n;

    cout << n << " : ";

    if (n == 0) {
        cout << "nol";
    } 
    else if (n == 100) {
        cout << "seratus";
    }
    else if (n < 10) {
        cout << satuan[n];
    }
    else if (n < 20) {
        cout << belasan[n - 10];
    }
    else {
        int puluh = n / 10;
        int sisa = n % 10;
        cout << puluhan[puluh];
        if (sisa != 0) {
            cout << " " << satuan[sisa];
        }
    }

    cout << endl;
    return 0;
}
```
### Output Unguided 2 :

##### Output 2
![Screenshot Output Unguided 2_2](https://github.com/Raja2-spec/103112400027_Raja-Muhammad-Lufhti/blob/main/Pertemuan1_Modul1/LAPRAK/Raja_Muhammad_Lufhti-Output-Unguided2.png)

penjelasan unguided 2:
Program C++ ini mengubah angka 0–100 menjadi teks bahasa Indonesia dengan menentukan apakah angka termasuk nol, seratus, satuan, belasan, atau puluhan lalu mencetak hasilnya.

### 3. Soal Unguided3

```C++
#include<iostream>
using namespace std;
int main(){
    int n; //3
    int x = 1;
    cin >> n;

    for (int i = n; i >= 1; i--)
    {
        for (int j = i; j >= 1; j--)
        {
            cout << j;
        }
        cout << "*" ;
        
        for (int k = 1; k <= i; k++)
        {
            cout << k;
        }
        cout << endl;
        
        for (int l = 1; l <= x; l++)
        {
            cout << " ";
        }
        x++;
    }
    cout << "*";
}
```
### Output Unguided 3 :

##### Output 3
![Screenshot Output Unguided 3_3](https://github.com/Raja2-spec/103112400027_Raja-Muhammad-Lufhti/blob/main/Pertemuan1_Modul1/LAPRAK/Raja_Muhammad_Lufhti-Output-Unguided3.png)

penjelasan unguided 3:
Program ini mencetak pola angka menurun dan naik dengan simbol * di tengah, bergeser ke kanan tiap baris sesuai input n.

## Kesimpulan
Berdasarkan praktikum yang dilakukan, dapat disimpulkan bahwa pengenalan bahasa pemrograman C++ melalui IDE Code::Blocks sangat membantu dalam memahami konsep dasar pemrograman. Mahasiswa dapat mempelajari penggunaan variabel, operator, percabangan, perulangan, serta struktur data sederhana melalui contoh program yang terstruktur. Selain itu, latihan yang diberikan menunjukkan bagaimana logika pemrograman dapat diterapkan untuk memecahkan berbagai permasalahan, mulai dari operasi aritmatika hingga pembuatan pola angka. Dengan memahami dasar-dasar ini, mahasiswa memperoleh fondasi penting untuk mempelajari konsep pemrograman lanjutan di kemudian hari [1].

## Referensi
[1] Jurusan Teknik Elektro, Fakultas Teknik, Universitas Negeri Malang. (2017/2018). Modul Praktikum Dasar Pemrograman Komputer: Modul 1 – Pengenalan Pemrograman [PDF]. Universitas Negeri Malang. https://elektro.um.ac.id/wp-content/uploads/2016/04/Dasar-Pemrograman-Modul-1-Pengenalan-Pemrograman.pdf
<br>...
