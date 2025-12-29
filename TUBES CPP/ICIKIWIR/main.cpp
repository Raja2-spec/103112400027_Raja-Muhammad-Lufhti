#include "tubes.h"
#include <iostream>
using namespace std;

void menu() {
    cout << "\n=== SuperFood Inventory Manager ===\n";
    cout << "1. Tambah Produk\n";
    cout << "2. Update Produk\n";
    cout << "3. Hapus Produk\n";
    cout << "4. Hapus Expiry Produk\n";
    cout << "5. Cari Produk\n";
    cout << "6. Tampilkan Produk Expiry Terdekat\n";
    cout << "7. Hitung Total Stok\n";
    cout << "0. Keluar\n";
    cout << "Pilihan: ";
} 

int main() {
    BST T;
    createBST(T);
    seedDummy(T); // masukkan data dummy untuk pengujian


    int pilihan;
    do {
        menu();
        cin >> pilihan;

        if (pilihan == 1) {
            insertFood(T);

        } else if (pilihan == 2) {
            updateFood(T);

        } else if (pilihan == 3) {
            string nama;
            cout << "Nama produk yang ingin dihapus: ";
            cin >> nama;
            deleteFood(T, nama);

        } else if (pilihan == 4) {
            string nama, exp;
            cout << "Nama produk: ";
            cin >> nama;
            address p = searchNode(T, nama);
            if (p == Nil) {
                cout << "Produk tidak ditemukan!\n";
            } else {
                cout << "Masukkan expiry yang ingin dihapus: ";
                cin >> exp;
                deleteExpiry(p, exp);
                cout << "Expiry dihapus.\n";
            }

        } else if (pilihan == 5) {
            string nama;
            cout << "Masukkan nama produk: ";
            cin >> nama;
            address p = searchNode(T, nama);
            if (p == Nil) {
                cout << "Produk tidak ditemukan!\n";
            } else {
                cout << "\n=== Detail Produk ===\n";
                cout << "Nama: " << p->info.nama << endl;
                cout << "Kategori: " << p->info.kategori << endl;
                cout << "Stok: " << p->info.stok << endl;
                cout << "Harga: " << p->info.harga << endl;
                cout << "Expiry: ";
                for (int i = 0; i < p->info.jumExpiry; i++) {
                    cout << p->info.expiry[i];
                    if (i != p->info.jumExpiry - 1) cout << ", ";
                }
                cout << endl;
            }

        } else if (pilihan == 6) {
            cout << "\nProduk dengan expiry terdekat:\n";
            showExpiredSoon(T);

        } else if (pilihan == 7) {
            cout << "Total stok semua produk: " << countTotalStock(T) << endl;
        }

        cout << endl;

    } while (pilihan != 0);

    cout << "Program selesai.\n";
    return 0;
}