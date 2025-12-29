#include "tubes.h"
#include <iostream>
using namespace std;

void menu() {
    cout << "\nSuperFood Inventory Manager\n";
    cout << "1. Tambah Produk\n";
    cout << "2. Update Produk\n";
    cout << "3. Hapus Produk\n";
    cout << "4. Tambah Expiry ke Produk\n";
    cout << "5. Hapus Expiry Produk\n";
    cout << "6. Cari Produk\n";
    cout << "7. Tampilkan (Traversal)\n";
    cout << "8. Tampilkan Produk Per Kategori\n";
    cout << "9. Tampilkan Produk Expiry Terdekat\n";
    cout << "10. Hitung Jumlah Node\n";
    cout << "11. Hitung Total Stok\n";
    cout << "12. Tampilkan Produk Min/Max (Nama)\n";
    cout << "0. Keluar\n";
    cout << "Pilihan: ";
}

int main() {
    BST T;
    createBST(T);

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
                cout << "Masukkan expiry (YYYY-MM-DD): ";
                cin >> exp;
                addExpiry(p, exp);
                cout << "Expiry ditambahkan.\n";
            }

        } else if (pilihan == 5) {
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

        } else if (pilihan == 6) {
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

        } else if (pilihan == 7) {
            int t;
            cout << "\n1. Inorder\n2. Preorder\n3. Postorder\n4. Level Order\nPilihan: ";
            cin >> t;

            if (t == 1) printInorder(T);
            else if (t == 2) printPreorder(T);
            else if (t == 3) printPostorder(T);
            else if (t == 4) printLevelOrder(T);

        } else if (pilihan == 8) {
            string kategori;
            cout << "Masukkan kategori: ";
            cin >> kategori;
            showByCategory(T, kategori);

        } else if (pilihan == 9) {
            cout << "\nProduk dengan expiry terdekat:\n";
            showExpiredSoon(T);

        } else if (pilihan == 10) {
            cout << "Jumlah node (produk): " << countNode(T) << endl;

        } else if (pilihan == 11) {
            cout << "Total stok semua produk: " << countTotalStock(T) << endl;

        } else if (pilihan == 12) {
            address pMin = findMin(T);
            address pMax = findMax(T);
            cout << "Produk nama terkecil (min): " << pMin->info.nama << endl;
            cout << "Produk nama terbesar (max): " << pMax->info.nama << endl;
        }

        cout << endl;

    } while (pilihan != 0);

    cout << "Program selesai.\n";
    return 0;
}