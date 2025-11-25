#include <iostream>
#include <string>
using namespace std;

struct Node {
    string nama;
    Node* next;
};

Node* head = nullptr;

void insertAkhir(const string& n) {
    Node* baru = new Node{n, nullptr};

    if (!head) {
        head = baru;
        return;
    }

    Node* p = head;
    while (p->next) p = p->next;
    p->next = baru;
}

void deleteNama(const string& n) {
    if (!head) return;

    if (head->nama == n) {
        Node* h = head;
        head = head->next;
        delete h;
        return;
    }

    Node* p = head;
    Node* q = nullptr;

    while (p && p->nama != n) {
        q = p;
        p = p->next;
    }

    if (!p) return;

    q->next = p->next;
    delete p;
}

void viewList() {
    Node* p = head;
    while (p) {
        cout << p->nama << " ";
        p = p->next;
    }
    cout << endl;
}

int hitungGenap() {
    int c = 0;
    Node* p = head;
    while (p) {
        if (p->nama.size() % 2 == 0) c++;
        p = p->next;
    }
    return c;
}

int main() {
    int menu;
    string nama;

    do {
        cout << "Menu: 1 insert, 2 delete, 3 view, 4 hitung genap, 0 exit" << endl;
        cin >> menu;

        if (menu == 1) {
            cout << "Masukkan nama: ";
            cin >> nama;
            insertAkhir(nama);
        } else if (menu == 2) {
            cout << "Masukkan nama untuk delete: ";
            cin >> nama;
            deleteNama(nama);
        } else if (menu == 3) {
            viewList();
        } else if (menu == 4) {
            cout << "Jumlah nama dengan huruf genap: " << hitungGenap() << endl;
        }

    } while (menu != 0);

    return 0;
}
