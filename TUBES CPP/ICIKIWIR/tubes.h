#ifndef TUBES_H
#define TUBES_H
#define Nil NULL

#include <iostream>
using namespace std;

// struktur record produk
struct Food {
    string nama;                 // nama produk (key unik)
    string kategori;             // Dairy, Frozen, Beverage, Snack, Fresh
    int stok;                    // jumlah stok
    float harga;                 // harga per item
    int jumExpiry;               // jumlah data expiry saat ini
    string expiry[20];           // array tanggal kadaluwarsa (maks 20 batch)
};

// Node BST
typedef Food dataFood;

struct node {
    dataFood info;
    node *left;
    node *right;
};

typedef node* address;
typedef address BST;

// Fungsi dasar BST

void createBST(BST &T);
bool isEmpty(BST T);

address alokasi(string nama, string kategori, int stok, float harga);
void insertNode(BST &T, address newNode);

void printInorder(BST T);
void printPreorder(BST T);
void printPostorder(BST T);
void printLevelOrder(BST T);

// CRUD

address searchNode(BST T, string nama);

void insertFood(BST &T);
void updateFood(BST &T);
void deleteFood(BST &T, string nama);
address deleteNode(BST &T, string nama);

void addExpiry(address p, string expDate);
void deleteExpiry(address p, string expDate);

// Fitur tambahan BST
address findMin(BST T);
address findMax(BST T);

int countNode(BST T);
int countTotalStock(BST T);

void showExpiredSoon(BST T);      // menampilkan produk dengan expiry terdekat
void showByCategory(BST T, string kategori);
void showByExpiryAsc(BST T);      // sorting berdasarkan expiry terdekat

#endif