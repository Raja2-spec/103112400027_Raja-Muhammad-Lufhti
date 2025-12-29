#include "tubes.h"
#include <queue>   // Digunakan untuk traversal level-order

// Membuat BST kosong dengan mengatur root menjadi NULL
void createBST(BST &T) {
    T = Nil;
}

// Mengecek apakah BST kosong
bool isEmpty(BST T) {
    return (T == Nil);
}

// Membuat node baru dan mengisi data produk
address alokasi(string nama, string kategori, int stok, float harga) {
    address p = new node;              // Alokasi memori node baru
    p->info.nama = nama;               // Set nama produk
    p->info.kategori = kategori;       // Set kategori produk
    p->info.stok = stok;               // Set jumlah stok
    p->info.harga = harga;             // Set harga produk
    p->info.jumExpiry = 0;             // Inisialisasi jumlah expiry = 0
    p->left = p->right = Nil;          // Node baru belum punya anak
    return p;                           // Kembalikan alamat node
}

// Menyisipkan node ke BST berdasarkan nama (sebagai key)
void insertNode(BST &T, address newNode) {
    if (T == Nil) {
        T = newNode;                   // Jika posisi kosong, pasang node
    } else if (newNode->info.nama < T->info.nama) {
        insertNode(T->left, newNode);  // Jika lebih kecil, ke kiri
    } else if (newNode->info.nama > T->info.nama) {
        insertNode(T->right, newNode); // Jika lebih besar, ke kanan
    } else {
        cout << "Produk dengan nama tersebut sudah ada!" << endl;
    }
}

// Traversal inorder (hasil terurut berdasarkan nama)
void printInorder(BST T) {
    if (T != Nil) {
        printInorder(T->left);         
        cout << T->info.nama << " | Stok: " << T->info.stok
             << " | Harga: " << T->info.harga << endl;
        printInorder(T->right);        
    }
}

// Traversal preorder
void printPreorder(BST T) {
    if (T != Nil) {
        cout << T->info.nama << " | Stok: " << T->info.stok
             << " | Harga: " << T->info.harga << endl;
        printPreorder(T->left);        
        printPreorder(T->right);       
    }
}

// Traversal postorder
void printPostorder(BST T) {
    if (T != Nil) {
        printPostorder(T->left);       
        printPostorder(T->right);      
        cout << T->info.nama << " | Stok: " << T->info.stok
             << " | Harga: " << T->info.harga << endl;
    }
}

// Traversal level-order menggunakan queue
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

// Mencari node berdasarkan nama produk
address searchNode(BST T, string nama) {
    if (T == Nil) return Nil;

    if (nama < T->info.nama)
        return searchNode(T->left, nama);
    else if (nama > T->info.nama)
        return searchNode(T->right, nama);
    else
        return T;
}

// Input produk dari user dan masukkan ke BST
void insertFood(BST &T) {
    string nama, kategori;
    int stok;
    float harga;

    cout << "Nama Produk: ";
    cin >> nama;

    cout << "Kategori: ";
    cin >> kategori;

    cout << "Stok: ";
    cin >> stok;

    cout << "Harga: ";
    cin >> harga;

    address p = alokasi(nama, kategori, stok, harga);
    insertNode(T, p);
}

// Mengupdate stok dan harga produk
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

// Mencari node terkecil (paling kiri)
address findMin(BST T) {
    while (T->left != Nil)
        T = T->left;
    return T;
}

// Mencari node terbesar (paling kanan)
address findMax(BST T) {
    while (T->right != Nil)
        T = T->right;
    return T;
}

// Menghapus node dari BST berdasarkan nama
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

// Wrapper untuk deleteNode
void deleteFood(BST &T, string nama) {
    T = deleteNode(T, nama);
}

// Menambahkan tanggal expiry ke produk
void addExpiry(address p, string expDate) {
    if (p == Nil) return;

    if (p->info.jumExpiry < 20) {
        p->info.expiry[p->info.jumExpiry] = expDate;
        p->info.jumExpiry++;
    } else {
        cout << "Kapasitas expiry penuh!" << endl;
    }
}

// Menghapus tanggal expiry tertentu
void deleteExpiry(address p, string expDate) {
    if (p == Nil) return;

    int idx = -1;
    for (int i = 0; i < p->info.jumExpiry; i++) {
        if (p->info.expiry[i] == expDate) {
            idx = i;
            break;
        }
    }

    if (idx == -1) return;

    for (int i = idx; i < p->info.jumExpiry - 1; i++) {
        p->info.expiry[i] = p->info.expiry[i + 1];
    }
    p->info.jumExpiry--;
}

// Menghitung jumlah node dalam BST
int countNode(BST T) {
    if (T == Nil) return 0;
    return 1 + countNode(T->left) + countNode(T->right);
}

// Menghitung total stok semua produk
int countTotalStock(BST T) {
    if (T == Nil) return 0;
    return T->info.stok + countTotalStock(T->left) + countTotalStock(T->right);
}

// Menampilkan produk berdasarkan kategori
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

// Menampilkan expiry terdekat (index 0)
void showExpiredSoon(BST T) {
    if (T == Nil) return;

    showExpiredSoon(T->left);

    if (T->info.jumExpiry > 0) {
        cout << T->info.nama << " | Expiry terdekat: "
             << T->info.expiry[0] << endl;
    }

    showExpiredSoon(T->right);
}

// Wrapper tampilan expiry
void showByExpiryAsc(BST T) {
    showExpiredSoon(T);
}
