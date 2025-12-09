#include "bstree.h"

// ==============================
// Fungsi Alokasi Node
// ==============================
address alokasi(infotype x) {
    address P = new Node;
    P->info = x;
    P->left = Nil;
    P->right = Nil;
    return P;
}

// ==============================
// Insert Node BST
// ==============================
void insertNode(address &root, infotype x) {
    if (root == Nil) {
        root = alokasi(x);
    } else {
        if (x < root->info) {
            insertNode(root->left, x);
        } else {
            insertNode(root->right, x);
        }
    }
}

// ==============================
// Pencarian Node BST
// ==============================
address findNode(infotype x, address root) {
    if (root == Nil) {
        return Nil;
    } else if (root->info == x) {
        return root;
    } else if (x < root->info) {
        return findNode(x, root->left);
    } else {
        return findNode(x, root->right);
    }
}

// ==============================
// Traversal InOrder
// ==============================
void printInorder(address root) {
    if (root != Nil) {
        printInorder(root->left);
        cout << root->info << " ";
        printInorder(root->right);
    }
}

// ==============================
// Fungsi Nomor 2
// ==============================

// Hitung jumlah node
int hitungJumlahNode(address root) {
    if (root == Nil) {
        return 0;
    }
    return 1 + hitungJumlahNode(root->left) + hitungJumlahNode(root->right);
}

// Hitung total nilai info seluruh node
int hitungTotalInfo(address root) {
    if (root == Nil) {
        return 0;
    }
    return root->info + hitungTotalInfo(root->left) + hitungTotalInfo(root->right);
}

// Hitung kedalaman maksimal tree
int hitungKedalaman(address root, int start) {
    if (root == Nil) {
        return start;
    }
    int kiri = hitungKedalaman(root->left, start + 1);
    int kanan = hitungKedalaman(root->right, start + 1);
    return (kiri > kanan) ? kiri : kanan;
}

// ==============================
// Fungsi Nomor 3
// ==============================

// Traversal Preorder (root → left → right)
void printPreOrder(address root) {
    if (root != Nil) {
        cout << root->info << " ";
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}

// Traversal Postorder (left → right → root)
void printPostOrder(address root) {
    if (root != Nil) {
        printPostOrder(root->left);
        printPostOrder(root->right);
        cout << root->info << " ";
    }
}
