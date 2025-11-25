#include <iostream>
using namespace std;

struct Node {
    int nilai;
    Node* next;
    Node* prev;
};

Node* head = nullptr;
Node* tail = nullptr;

void insertAkhir(int x) {
    Node* baru = new Node{x, nullptr, nullptr};

    if (!head) {
        head = tail = baru;
        return;
    }

    tail->next = baru;
    baru->prev = tail;
    tail = baru;
}

void deleteLast() {
    if (!head) return;

    if (head == tail) {
        delete head;
        head = tail = nullptr;
        return;
    }

    Node* hapus = tail;
    tail = tail->prev;
    tail->next = nullptr;
    delete hapus;
}

void viewDepan() {
    Node* p = head;
    if (!p) {
        cout << "List kosong" << endl;
        return;
    }
    while (p) {
        cout << p->nilai << " ";
        p = p->next;
    }
    cout << endl;
}

void reverseList() {
    Node* p = head;
    while (p) {
        Node* tmp = p->next;
        p->next = p->prev;
        p->prev = tmp;
        p = tmp;
    }
    Node* tmp = head;
    head = tail;
    tail = tmp;
}

int main() {
    int menu, x;

    do {
        cout << "Menu: 1 insert (end), 2 delete (last), 3 view (depan), 4 reverse & view (depan), 0 exit" << endl;
        cin >> menu;

        if (menu == 1) {
            cout << "Masukkan nilai: ";
            cin >> x;
            insertAkhir(x);
        }
        else if (menu == 2) {
            deleteLast();
        }
        else if (menu == 3) {
            viewDepan();
        }
        else if (menu == 4) {
            reverseList();
            cout << "List setelah di-reverse: ";
            viewDepan();
        }

    } while (menu != 0);

    return 0;
}
