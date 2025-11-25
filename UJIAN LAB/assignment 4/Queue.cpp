#include "Queue.h"
#include <iostream>
using namespace std;

bool isEmpty(QueueEkspedisi &Q) {
    return Q.head == -1;
}

bool isFull(QueueEkspedisi &Q) {
    return Q.tail == MAX - 1;
}

void createQueue(QueueEkspedisi &Q) {
    Q.head = -1;
    Q.tail = -1;
}

void enQueue(QueueEkspedisi &Q) {
    if (isFull(Q)) {
        cout << "Queue penuh.\n";
        return;
    }

    Paket P;
    cout << "Kode Resi: ";      cin >> P.KodeResi;
    cout << "Nama Pengirim: ";  cin >> P.NamaPengirim;
    cout << "Berat Barang: ";   cin >> P.BeratBarang;
    cout << "Tujuan: ";         cin >> P.Tujuan;

    if (isEmpty(Q)) {
        Q.head = Q.tail = 0;
    } else {
        Q.tail++;
    }

    Q.dataPaket[Q.tail] = P;
}

void deQueue(QueueEkspedisi &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong.\n";
        return;
    }

    for (int i = Q.head; i < Q.tail; i++) {
        Q.dataPaket[i] = Q.dataPaket[i + 1];
    }

    Q.tail--;

    if (Q.tail < 0) {
        Q.head = Q.tail = -1;
    }
}

void viewQueue(QueueEkspedisi &Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong.\n";
        return;
    }

    cout << "\n=== Isi Queue ===\n";
    for (int i = Q.head; i <= Q.tail; i++) {
        cout << i + 1 << ". "
             << Q.dataPaket[i].KodeResi << " | "
             << Q.dataPaket[i].NamaPengirim << " | "
             << Q.dataPaket[i].BeratBarang << "kg | "
             << Q.dataPaket[i].Tujuan << "\n";
    }
}
