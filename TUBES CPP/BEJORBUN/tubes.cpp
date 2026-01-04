#include "tubes.h"
#include <queue>

// Inisialisasi BST
void createBST(BST &T) {
    T = Nil;
}

bool isEmpty(BST T) {
    return (T == Nil);
}


// Alokasi node produk
address alokasi(string nama, string kategori, int stok, float harga) {
    address p = new node;
    p->info.nama = nama;
    p->info.kategori = kategori;
    p->info.stok = stok;
    p->info.harga = harga;
    p->info.jumExpiry = 0;
    p->left = p->right = Nil;
    return p;
}


// Insert node ke BST (berdasarkan nama produk)
void insertNode(BST &T, address newNode) {
    if (T == Nil) {
        T = newNode;
    } else if (newNode->info.nama < T->info.nama) {
        insertNode(T->left, newNode);
    } else if (newNode->info.nama > T->info.nama) {
        insertNode(T->right, newNode);
    } else {
        cout << "Produk dengan nama tersebut sudah ada!" << endl;
    }
}


// Traversal
void printInorder(BST T) {
    if (T != Nil) {
        printInorder(T->left);
        cout << T->info.nama << " | Stok: " << T->info.stok 
             << " | Harga: " << T->info.harga;
        if (T->info.jumExpiry > 0) {
            cout << " | Expiry: " << T->info.expiry[0];
        } else {
            cout << " | Expiry: -";
        }
        cout << endl;
        printInorder(T->right);
    }
}

void printPreorder(BST T) {
    if (T != Nil) {
        cout << T->info.nama << " | Stok: " << T->info.stok 
             << " | Harga: " << T->info.harga << endl;
        printPreorder(T->left);
        printPreorder(T->right);
    }
}

void printPostorder(BST T) {
    if (T != Nil) {
        printPostorder(T->left);
        printPostorder(T->right);
        cout << T->info.nama << " | Stok: " << T->info.stok 
             << " | Harga: " << T->info.harga << endl;
    }
}

void printLevelOrder(BST T) {
    if (T == Nil) return;

    queue<address> q;
    q.push(T);

    while (!q.empty()) {
        address p = q.front();
        q.pop();
        cout << p->info.nama << " | Stok: " << p->info.stok 
             << " | Harga: " << p->info.harga << endl;

        if (p->left != Nil) q.push(p->left);
        if (p->right != Nil) q.push(p->right);
    }
}


// Search
address searchNode(BST T, string nama) {
    if (T == Nil) return Nil;

    if (nama < T->info.nama) return searchNode(T->left, nama);
    else if (nama > T->info.nama) return searchNode(T->right, nama);
    else return T;
}


// CRUD
void insertFood(BST &T) {
    string nama, kategori;
    int stok;
    float harga;

    cout << "Nama Produk: "; 
    cin >> nama;

    // cek duplikasi
    if (searchNode(T, nama) != Nil) {
        cout << "Produk dengan nama tersebut sudah ada!" << endl;
        return;
    }

    cout << "Kategori: "; 
    cin >> kategori;

    cout << "Stok: ";
    cin >> stok;

    cout << "Harga: ";
    cin >> harga;

    string exp;
    cout << "Expiry (DD-MM-YYYY) atau - jika tidak ada: ";
    cin >> exp;

    address p = alokasi(nama, kategori, stok, harga);
    if (exp != "-") {
        p->info.expiry[0] = exp;
        p->info.jumExpiry = 1;
    }

    insertNode(T, p);
}

void updateFood(BST &T) {
    string nama;
    cout << "Masukkan nama produk yang ingin diupdate: ";
    cin >> nama;

    address p = searchNode(T, nama);
    if (p == Nil) {
        cout << "Produk tidak ditemukan!" << endl;
        return;
    }

    int stok;
    float harga;

    cout << "Stok baru: ";
    cin >> stok;

    cout << "Harga baru: ";
    cin >> harga;

    p->info.stok = stok;
    p->info.harga = harga;
}


// Delete node BST
address findMin(BST T) {
    while (T->left != Nil)
        T = T->left;
    return T;
}

address findMax(BST T) {
    while (T->right != Nil)
        T = T->right;
    return T;
}

address deleteNode(BST &T, string nama) {
    if (T == Nil) return T;

    if (nama < T->info.nama) {
        T->left = deleteNode(T->left, nama);

    } else if (nama > T->info.nama) {
        T->right = deleteNode(T->right, nama);

    } else {
        if (T->left == Nil) {
            address temp = T->right;
            delete T;
            return temp;
        } else if (T->right == Nil) {
            address temp = T->left;
            delete T;
            return temp;
        } else {
            address temp = findMin(T->right);
            T->info = temp->info;
            T->right = deleteNode(T->right, temp->info.nama);
        }
    }
    return T;
}

void deleteFood(BST &T, string nama) {
    T = deleteNode(T, nama);
    cout << "Produk berhasil dihapus" << endl;
    
}


// Counting
int countNode(BST T) {
    if (T == Nil) return 0;
    return 1 + countNode(T->left) + countNode(T->right);
}

int countTotalStock(BST T) {
    if (T == Nil) return 0;
    return T->info.stok + countTotalStock(T->left) + countTotalStock(T->right);
}


// Fungsi tambahan (custom)
void showByCategory(BST T, string kategori) {
    if (T != Nil) {
        showByCategory(T->left, kategori);

        if (T->info.kategori == kategori) {
            cout << T->info.nama << " | Stok: " << T->info.stok 
                 << " | Harga: " << T->info.harga << endl;
        }

        showByCategory(T->right, kategori);
    }
}



// menambahkan beberapa data dummy untuk pengujian
void seedDummy(BST &T) {
    address p;

    p = alokasi("Milk", "Dairy", 10, 2.5f);
    p->info.expiry[0] = "15-01-2026";
    p->info.jumExpiry = 1;
    insertNode(T, p);

    p = alokasi("Bread", "Fresh", 20, 1.5f);
    p->info.expiry[0] = "25-02-2026";
    p->info.jumExpiry = 1;
    insertNode(T, p);

    p = alokasi("IceCream", "Frozen", 5, 3.0f);
    p->info.expiry[0] = "10-03-2026";
    p->info.jumExpiry = 1;
    insertNode(T, p);

    p = alokasi("Chips", "Snack", 15, 1.0f);
    p->info.expiry[0] = "05-04-2026";
    p->info.jumExpiry = 1;
    insertNode(T, p);

    p = alokasi("Juice", "Beverage", 8, 2.0f);
    p->info.expiry[0] = "20-05-2026";
    p->info.jumExpiry = 1;
    insertNode(T, p);
}