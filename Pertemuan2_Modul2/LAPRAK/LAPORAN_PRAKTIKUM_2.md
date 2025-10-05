# <h1 align="center">Laporan Praktikum Modul 2 - Pengenalan Bahasa C++ (Bagian Kedua)</h1>
<p align="center">Raja Muhammad Lufhti - 103112400027</p>

## Dasar Teori
Struktur data merupakan salah satu bahan dasar pembuatan program. Pemakaian struktur data yang tepat di dalam proses pemrograman, akan menghasilkan algoritma yang jelas dan tepat sehingga menjadikan program secara keseluruhan lebih sederhana. Array merupakan bagian dari struktur data yaitu termasuk kedalam struktur data sederhana yang dapat di definisikan sebagai pemesanan alokasi memory sementara pada komputer.

Struktur data : Struktur Data memberikan penjelasan tentang suatu koleksi atau kelompok data yang dapat dikarakteristikan oleh organisasi serta operasi yang didefinisikan terhadapnya. Pemakaian struktur data yang tepat didalam proses pemrograman,akan menghasilkan algoritma yang kebih jelas dan tepat sehingga menjadikan program secara keseluruhan lebih sederhana.

Array :Array adalah suatu struktur yang terdiri dari sejumlah elemen yang memiliki tipe data yang sama. Elemen-elemen array tersusun secara sekuensial dalam memori komputer. Semua elemem array bertipe sama. Array cocok untuk organisasi kumpulan data homogen yang ukuran atau jumlah elemen maksimumnya telah diketahui dari awal. Homogen adalah bahwa setiap elemen dari sebuah array tertentu haruslah mempunyai tipe data yang sama[1].

## Guided 

### 1. ARRAY 1

```C++
#include<iostream>
using namespace std;

int main(){
    int arr[5];

    for (int i = 0; i < 5; i++){
        cout << "masukkan value indeks ke-" << i << " : ";
        cin >> arr[i];
    }
    int j = 0;
    while(j < 5){
        cout << "isi indeks ke-" << j << " i " << arr[j] << endl;
        j++;
    }
    return 0;

}
```
Program C++ di atas berfungsi untuk menyimpan dan menampilkan isi array berukuran 5. Pertama, program meminta pengguna memasukkan 5 nilai secara berurutan melalui perulangan for, di mana setiap nilai disimpan ke dalam elemen array arr sesuai indeksnya. Setelah semua nilai dimasukkan, program menggunakan perulangan while untuk menampilkan kembali setiap isi array dengan menuliskan indeks dan nilai yang tersimpan. Dengan demikian, program ini menunjukkan proses input dan output data dalam sebuah array sederhana.

### 2. ARRAY 2

```C++
#include <iostream>
using namespace std;

void tampilkanHasil(int arr[2][2]){
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    int arrA[2][2] = {
        {1, 2},
        {3, 4}
    };
    int arrB[2][2] = {
        {2, 3},
        {4, 5}
    };
    int arrC[2][2] = {0};
    int arrD[2][2] = {0};

    //penjumlahan matriks 2x2
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            arrC[i][j] = arrA[i][j] + arrB[i][j];
        }
    }

    cout << "hasil penjumlahan : " << endl;
    tampilkanHasil(arrC);

    cout << endl;

    //perkalian matriks 2x2
    for (int i = 0; i < 2; i++){                        //perulangan baris
        for(int j = 0; j < 2; j++){                     //perulangan kolom
            for(int k = 0; k < 2; k++){         //perulangan perkalian
                arrD[i][j] += arrA[i][k] * arrB[k][j];
            }
        }
    }

    cout << "hasil perkalian : " << endl;
    tampilkanHasil(arrD);
    return 0;
    
}

```
Program ini menjumlahkan dan mengalikan dua matriks 2x2 (arrA dan arrB). Hasil penjumlahan disimpan di arrC, sedangkan hasil perkalian dihitung dengan menjumlahkan hasil kali baris arrA dan kolom arrB lalu disimpan di arrD. Kedua hasil kemudian ditampilkan dengan fungsi tampilkanHasil().

### 3. ARRNPOINTER

```C++
#include <iostream>
using namespace std;

int main(){
    int arr[]={10,20,30,40,50};
    int*ptr=arr; //pointer yang menunjuk ke elemen pertama array

    //mengakses elemen array menggunakan pointer
    for (int i = 0; i < 5; i++){
        cout<<"elemen array ke-"<< i+1<<" menggunakan pointer: "<<*(ptr+i)<<endl;
    }

    //mengakses elemen array menggunakan indeks
    for (int i = 0; i < 5; i++){
        cout<<"Elemen array ke-"<< i+1 <<" menggunakan indeks: "<<arr[i]<<endl;
    }
    return 0;
}
```
program di atas menunjukkan bahwa elemen array dapat diakses dengan dua cara, yaitu menggunakan indeks (arr[i]) maupun pointer (*(ptr+i)), dan keduanya memberikan hasil yang sama. Hal ini karena nama array sebenarnya merepresentasikan alamat elemen pertamanya, sehingga pointer dapat digunakan untuk menelusuri elemen-elemen array melalui aritmatika alamat memori.

### 4. Fungsi Prosedur

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
Program di atas meminta input berupa sebuah angka dari pengguna, lalu menampilkan deretan angka dengan tiga jenis perulangan berbeda. Pertama, perulangan for akan mencetak angka dari 0 hingga kurang dari nilai input. Kedua, perulangan while dimulai dari 10 dan terus menurun mencetak angka selama nilainya lebih besar dari input. Terakhir, perulangan do-while juga dimulai dari 10, namun karena kondisi dicek setelah eksekusi, angka 10 akan selalu dicetak minimal sekali meskipun syarat perulangan tidak terpenuhi.

## Unguided 

### 1. Soal Unguided1

```C++
#include <iostream>

using namespace std;

void tampilMatriks(int arrC[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << arrC[i][j] << " ";
        }
        cout << endl;
    }
}

void jumlahMatriks(int arrA[3][3], int arrB[3][3], int arrC[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            arrC[i][j] = arrA[i][j] + arrB[i][j];
        }
    }
    cout << "Hasil Penjumlahan Matriks:" << endl;
    tampilMatriks(arrC);
}

void kurangMatriks(int arrA[3][3], int arrB[3][3], int arrC[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            arrC[i][j] = arrA[i][j] - arrB[i][j];
        }
    }
    cout << "Hasil Pengurangan Matriks:" << endl;
    tampilMatriks(arrC);
}

void kaliMatriks(int arrA[3][3], int arrB[3][3], int arrC[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            arrC[i][j] = 0;
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                arrC[i][j] += arrA[i][k] * arrB[k][j];
            }
        }
    }
    cout << "Hasil Perkalian Matriks:" << endl;
    tampilMatriks(arrC);
}

int main() {
    int arrA[3][3] = {
        {7, 12, 22},
        {31, 6, 41},
        {15, 19, 36}
    };

    int arrB[3][3] = {
        {11, 34, 7},
        {3, 25, 41},
        {5, 18, 33}
    };

    int arrC[3][3];
    int pilihan;

    do {
        cout << "--- Menu Program Matriks ---" << endl;
        cout << "1. Penjumlahan matriks" << endl;
        cout << "2. Pengurangan matriks" << endl;
        cout << "3. Perkalian matriks" << endl;
        cout << "4. Keluar" << endl;
        cout << "Masukkan pilihan Anda (1-4): ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                jumlahMatriks(arrA, arrB, arrC);
                break;
            case 2:
                kurangMatriks(arrA, arrB, arrC);
                break;
            case 3:
                kaliMatriks(arrA, arrB, arrC);
                break;
            case 4:
                cout << "Keluar dari program." << endl;
                break;
            default:
                cout << "Pilihan tidak valid, coba lagi." << endl;
        }
        cout << endl;
    } while (pilihan != 4);

    return 0;
}

```
### Output Unguided 1 :

##### Output 1
![Screenshot Output Unguided 1_1](https://github.com/Raja2-spec/103112400027_Raja-Muhammad-Lufhti/blob/main/Pertemuan2_Modul2/LAPRAK/Raja_Muhammad_Lufhti-Output-Unguided01.png)

penjelasan unguided 1:
Program ini dibuat untuk menghitung operasi dasar matriks 3x3, yaitu penjumlahan, pengurangan, dan perkalian. Pengguna cukup memilih menu yang tersedia, lalu hasilnya langsung ditampilkan, dan program akan terus berjalan sampai memilih keluar.


### 2. Soal Unguided2

```C++
#include <iostream>
using namespace std;

int main() {
    int panjang = 10;
    int lebar = 5;
    int luas = 0;
    int keliling = 0;

    int *ptrPanjang = &panjang;
    int *ptrLebar = &lebar;

    cout << "--- Nilai Awal ---" << endl;
    cout << "Panjang: " << panjang << endl;
    cout << "Lebar: " << lebar << endl;
    cout << endl;

    luas = (*ptrPanjang) * (*ptrLebar);
    keliling = 2 * ((*ptrPanjang) + (*ptrLebar));

    cout << "--- Hasil Perhitungan ---" << endl;
    cout << "Luas Persegi Panjang: " << luas << endl;
    cout << "Keliling Persegi Panjang: " << keliling << endl;
    cout << endl;

    *ptrPanjang = 12;
    *ptrLebar = 6;

    luas = (*ptrPanjang) * (*ptrLebar);
    keliling = 2 * ((*ptrPanjang) + (*ptrLebar));

    cout << "--- Nilai Setelah Diubah Melalui Pointer ---" << endl;
    cout << "Panjang Baru: " << panjang << endl;
    cout << "Lebar Baru: " << lebar << endl;
    cout << "Luas Baru: " << luas << endl;
    cout << "Keliling Baru: " << keliling << endl;

    return 0;
}

```
### Output Unguided 2 :

##### Output 2
![Screenshot Output Unguided 2_2](https://github.com/Raja2-spec/103112400027_Raja-Muhammad-Lufhti/blob/main/Pertemuan2_Modul2/LAPRAK/Raja_Muhammad_Lufhti-Output-Unguided02.png)

penjelasan unguided 2:
Program ini simpel: awalnya punya panjang 10 dan lebar 5, lalu dihitung luas dan kelilingnya. Setelah itu, panjang dan lebar diubah lewat pointer jadi 12 dan 6, lalu dihitung lagi luas dan keliling yang baru, dan semua hasilnya ditampilkan ke layar.


## Kesimpulan
Dari praktikum Modul 2 tentang Pengenalan Bahasa C++ (Bagian Kedua), dapat disimpulkan bahwa penggunaan array, pointer, serta operasi dasar pada struktur data sangat penting untuk mendukung proses pemrograman. Array memungkinkan penyimpanan data dengan tipe yang sama secara terstruktur dan mudah diakses, baik menggunakan indeks maupun pointer.

Selain itu, percobaan dengan operasi matriks (penjumlahan, pengurangan, dan perkalian) memberikan gambaran bagaimana array dua dimensi dapat dimanfaatkan untuk menyelesaikan perhitungan matematis. Penerapan pointer juga memperlihatkan fleksibilitas dalam mengubah dan mengakses data melalui alamat memori.

Secara keseluruhan, praktikum ini membantu memahami konsep dasar manipulasi data menggunakan array dan pointer di C++, yang nantinya akan sangat berguna dalam menyelesaikan permasalahan yang lebih kompleks pada pemrograman maupun pengembangan sistem.[1].

## Referensi
[1] Pratama, M. A. (2020, March 29). STRUKTUR DATA ARRAY DUA DIMENSI  PADA PEMROGRAMAN C++. https://doi.org/10.31219/osf.io/vyech
<br>...
