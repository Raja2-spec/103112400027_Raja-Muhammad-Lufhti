#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    Queue* Q = createQueue(5);

    enQueue(Q, 10);
    enQueue(Q, 20);
    enQueue(Q, 30);
    enQueue(Q, 40);

    cout << "Setelah enQueue 4 elemen:\n";
    printQueue(Q);

    int X;
    deQueue(Q, X);
    cout << "deQueue: " << X << endl;

    cout << "Isi queue sekarang:\n";
    printQueue(Q);

    enQueue(Q, 50);
    enQueue(Q, 60);

    cout << "Setelah head dan tail berputar:\n";
    printQueue(Q);

    return 0;
}
