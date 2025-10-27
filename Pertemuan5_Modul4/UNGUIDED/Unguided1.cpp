#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void append(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

Node* getNodeAt(Node* head, int index) {
    int count = 0;
    Node* temp = head;
    while (temp != NULL) {
        if (count == index)
            return temp;
        temp = temp->next;
        count++;
    }
    return NULL;
}

int length(Node* head) {
    int len = 0;
    Node* temp = head;
    while (temp != NULL) {
        len++;
        temp = temp->next;
    }
    return len;
}

Node* binarySearch(Node* head, int target) {
    int low = 0;
    int high = length(head) - 1;
    int iterasi = 1;

    cout << "\nProses Pencarian:\n";
    while (low <= high) {
        int mid = (low + high) / 2;
        Node* midNode = getNodeAt(head, mid);

        cout << "Iterasi " << iterasi++ << ": Mid = " << midNode->data
             << " (indeks tengah)";

        if (midNode->data == target) {
            cout << " - DITEMUKAN!\n";
            return midNode;
        } else if (midNode->data < target) {
            cout << " -> Cari di bagian kanan\n";
            low = mid + 1;
        } else {
            cout << " -> Cari di bagian kiri\n";
            high = mid - 1;
        }
    }

    cout << "Tidak ada elemen tersisa\n";
    return NULL;
}

int main() {
    cout << "BINARY SEARCH PADA LINKED LIST\n";

    Node* head = NULL;

    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);
    append(head, 60);

    cout << "Linked List yang dibuat: ";
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";

    int cari = 40;
    cout << "Mencari nilai: " << cari << endl;
    Node* hasil = binarySearch(head, cari);
    if (hasil != NULL) {
        cout << "\nHasil: Nilai " << cari << " DITEMUKAN pada linked list!\n";
        cout << "Alamat node: " << hasil << endl;
        cout << "Data node: " << hasil->data << endl;
        cout << "Node berikutnya: " << (hasil->next ? hasil->next->data : 0) << endl;
    } else {
        cout << "\nHasil: Nilai " << cari << " TIDAK DITEMUKAN dalam linked list!\n";
    }

    cari = 25;
    cout << "\nMencari nilai: " << cari << endl;
    hasil = binarySearch(head, cari);
    if (hasil != NULL) {
        cout << "\nHasil: Nilai " << cari << " DITEMUKAN pada linked list!\n";
    } else {
        cout << "\nHasil: Nilai " << cari << " TIDAK DITEMUKAN dalam linked list!\n";
    }

    return 0;
}
