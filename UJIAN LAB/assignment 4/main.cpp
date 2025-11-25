#include <iostream>
#include "Queue.h"
using namespace std;

int main() {
    QueueEkspedisi Q;
    createQueue(Q);

    int pilihan;
    do {
        cout << "\n--- Komaniya Ekspress ---\n";
        cout << "1. Input Data Paket\n";
        cout << "2. Hapus Data Paket\n";
        cout << "3. Tampilkan Queue\n";
        cout << "0. Keluar\n";
        cout << "Pilihan anda: ";
        cin >> pilihan;

        switch (pilihan) {
        case 1:
            enQueue(Q);
            break;
        case 2:
            deQueue(Q);
            break;
        case 3:
            viewQueue(Q);
            break;
        }
    } while (pilihan != 0);

    return 0;
}
