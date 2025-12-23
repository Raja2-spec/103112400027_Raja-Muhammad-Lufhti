#include "bst.h"

bool isEmpty(Node* root) {
    return root == NULL;
}

void createTree(Node* &root) {
    root = NULL;
}

Node* newNode(string nama, float berat, string tier) {
    Node* p = new Node;
    p->namaMember = nama;
    p->beratBadan = berat;
    p->tierMember = tier;
    p->left = NULL;
    p->right = NULL;
    return p;
}

void insertNode(Node* &root, Node* p) {
    if (root == NULL) {
        root = p;
    } else if (p->beratBadan < root->beratBadan) {
        insertNode(root->left, p);
    } else if (p->beratBadan > root->beratBadan) {
        insertNode(root->right, p);
    }
}

void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        cout << root->beratBadan << " - ";
        inOrder(root->right);
    }
}

Node* mostLeft(Node* root) {
    if (root == NULL) return NULL;
    while (root->left != NULL)
        root = root->left;
    return root;
}

Node* mostRight(Node* root) {
    if (root == NULL) return NULL;
    while (root->right != NULL)
        root = root->right;
    return root;
}

void searchByBeratBadan(Node* root, float key, Node* parent) {
    if (root == NULL) {
        cout << "Data tidak ditemukan\n";
        return;
    }

    if (root->beratBadan == key) {
        cout << "=== Data Ditemukan dalam BST ===\n";
        cout << "Nama Member : " << root->namaMember << endl;
        cout << "Berat Badan : " << root->beratBadan << endl;
        cout << "Tier Member : " << root->tierMember << endl;

        cout << "\n--- Data Parent ---\n";
        if (parent != NULL) {
            cout << parent->namaMember << " | "
                 << parent->beratBadan << " | "
                 << parent->tierMember << endl;
        } else {
            cout << "Tidak memiliki parent\n";
        }

        cout << "\n--- Data Child Kiri ---\n";
        if (root->left != NULL) {
            cout << root->left->namaMember << " | "
                 << root->left->beratBadan << " | "
                 << root->left->tierMember << endl;
        } else cout << "Tidak ada\n";

        cout << "\n--- Data Child Kanan ---\n";
        if (root->right != NULL) {
            cout << root->right->namaMember << " | "
                 << root->right->beratBadan << " | "
                 << root->right->tierMember << endl;
        } else cout << "Tidak ada\n";

        return;
    }

    if (key < root->beratBadan)
        searchByBeratBadan(root->left, key, root);
    else
        searchByBeratBadan(root->right, key, root);
}
