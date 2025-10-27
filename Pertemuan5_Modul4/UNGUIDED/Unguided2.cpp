#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void append(Node*& head, int val) {
    Node* n = new Node();
    n->data = val;
    n->next = NULL;

    if (!head) head = n;
    else {
        Node* t = head;
        while (t->next) t = t->next;
        t->next = n;
    }
}

Node* linearSearch(Node* head, int key) {
    cout << "\nProses Pencarian:\n";
    int i = 1;
    while (head) {
        cout << "Memeriksa node " << i << ": " << head->data;
        if (head->data == key) {
            cout << " (SAMA) - DITEMUKAN!\n";
            return head;
        } else cout << " (tidak sama)\n";
        head = head->next;
        i++;
    }
    cout << "Tidak ada node lagi yang tersisa\n";
    return NULL;
}

int main() {
    cout << "LINEAR SEARCH PADA LINKED LIST\n";

    Node* head = NULL;
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);

    cout << "Linked List yang dibuat: ";
    for (Node* t = head; t; t = t->next)
        cout << t->data << " -> ";
    cout << "NULL\n";

    int cari = 30;
    cout << "Mencari nilai: " << cari << endl;
    Node* hasil = linearSearch(head, cari);
    if (hasil) {
        cout << "\nHasil: Nilai " << cari << " DITEMUKAN pada linked list!\n";
        cout << "Alamat node: " << hasil << endl;
        cout << "Data node: " << hasil->data << endl;
        cout << "Node berikutnya: " 
             << (hasil->next ? hasil->next->data : 0) << endl;
    } else
        cout << "\nHasil: Nilai " << cari << " TIDAK DITEMUKAN dalam linked list!\n";

    cari = 25;
    cout << "\nMencari nilai: " << cari << endl;
    hasil = linearSearch(head, cari);
    if (!hasil)
        cout << "\nHasil: Nilai " << cari << " TIDAK DITEMUKAN dalam linked list!\n";

    return 0;
}
