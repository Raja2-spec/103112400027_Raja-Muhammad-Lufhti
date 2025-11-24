#include "queue.h"
#include <iostream>
using namespace std;

struct Queue {
    int HEAD;
    int TAIL;
    int maxEl;
    int *T;
};

Queue* createQueue(int maxEl) {
    Queue* Q = new Queue;
    Q->HEAD = -1;
    Q->TAIL = -1;
    Q->maxEl = maxEl;
    Q->T = new int[maxEl];
    return Q;
}

bool isEmpty(Queue* Q) {
    return (Q->HEAD == -1);
}

bool isFull(Queue* Q) {
    if (isEmpty(Q)) return false;
    return ((Q->TAIL + 1) % Q->maxEl == Q->HEAD);
}

void enQueue(Queue* Q, infotype X) {
    if (isFull(Q)) {
        cout << "Queue penuh!\n";
        return;
    }
    if (isEmpty(Q)) {
        Q->HEAD = Q->TAIL = 0;
    } else {
        Q->TAIL = (Q->TAIL + 1) % Q->maxEl;
    }
    Q->T[Q->TAIL] = X;
}

bool deQueue(Queue* Q, infotype &X) {
    if (isEmpty(Q)) {
        cout << "Queue kosong!\n";
        return false;
    }
    X = Q->T[Q->HEAD];

    if (Q->HEAD == Q->TAIL) {
        Q->HEAD = Q->TAIL = -1;
    } else {
        Q->HEAD = (Q->HEAD + 1) % Q->maxEl;
    }
    return true;
}

int length(Queue* Q) {
    if (isEmpty(Q)) return 0;

    if (Q->TAIL >= Q->HEAD)
        return Q->TAIL - Q->HEAD + 1;

    return (Q->maxEl - Q->HEAD) + (Q->TAIL + 1);
}

void printQueue(Queue* Q) {
    if (isEmpty(Q)) {
        cout << "Queue kosong\n";
        return;
    }

    cout << "Queue: ";
    int i = Q->HEAD;

    while (true) {
        cout << Q->T[i];
        if (i == Q->TAIL) break;
        cout << " ";
        i = (i + 1) % Q->maxEl;
    }
    cout << endl;
}
