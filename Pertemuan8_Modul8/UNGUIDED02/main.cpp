#include <iostream>
#include "queue.h"
using namespace std;

int main() {
    cout << "Hello World!" << endl;
    cout << "===================" << endl;

    Queue Q;
    createQueue(Q);

    cout << "== Queue Info ==" << endl;

    enqueue(Q, 5);  printInfo(Q);
    enqueue(Q, 7);  printInfo(Q);
    enqueue(Q, 2);  printInfo(Q);
    enqueue(Q, 9);  printInfo(Q);
    enqueue(Q, 4);  printInfo(Q);

    dequeue(Q);     printInfo(Q);
    enqueue(Q, 8);  printInfo(Q);
    dequeue(Q);     printInfo(Q);

    enqueue(Q, 3);  printInfo(Q);
    enqueue(Q, 6);  printInfo(Q);
    dequeue(Q);     printInfo(Q);

    return 0;
}
