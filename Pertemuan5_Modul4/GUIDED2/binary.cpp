#include <iostream>
using namespace std;

// Definisi node untuk linked list
struct Node {
    int data;
    Node* next;
};

// Fungsi untuk menambahkan node di akhir list
void append(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) head = newNode;
    else {
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
    }
}

// Fungsi untuk mendapatkan panjang linked list
int getLength(Node* head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

// Fungsi untuk mengambil node di posisi ke-n (0-based)
Node* getNodeAt(Node* head, int index) {
    int count = 0;
    while (head && count < index) {
        head = head->next;
        count++;
    }
    return head;
}

// Fungsi binary search untuk linked list
Node* binarySearch(Node* head, int key) {
    int left = 0;
    int right = getLength(head) - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        Node* midNode = getNodeAt(head, mid); // ambil node tengah

        if (!midNode) return nullptr;

        if (midNode->data == key)
            return midNode;
        else if (midNode->data < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return nullptr; // tidak ditemukan
}

int main() {
    Node* head = nullptr;

    // Data HARUS terurut agar binary search bisa digunakan
    append(head, 10);
    append(head, 20);
    append(head, 30);
    append(head, 40);
    append(head, 50);

    int key = 30;
    Node* result = binarySearch(head, key);

    if (result)
        cout << "Found: " << result->data << endl;
    else
        cout << "Not Found" << endl;

    return 0;
}
