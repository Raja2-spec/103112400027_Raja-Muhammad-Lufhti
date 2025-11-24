#include <iostream>
#include "queue.h"

using namespace std;

void createQueue(Queue& Q) {
    Q.head = 0; 
    Q.tail = 0; 
    for (int i = 0; i < MAX_SIZE; ++i) {
        Q.info[i] = -1;
    }
}

bool isEmptyQueue(const Queue& Q) {
    return Q.tail == Q.head;
}

bool isFullQueue(const Queue& Q) {
    return Q.tail == MAX_SIZE;
}

void enqueue(Queue& Q, infotype x) {
    if (isFullQueue(Q)) {
        cout << "Antrian Penuh! Enqueue Gagal." << endl;
    } else {
        Q.info[Q.tail] = x;
        Q.tail++;
    }
}

infotype dequeue(Queue& Q) {
    infotype temp_val = -1; 
    if (isEmptyQueue(Q)) {
        cout << "Antrian Kosong! Dequeue Gagal." << endl;
    } else {
        temp_val = Q.info[Q.head];

        for (int i = Q.head; i < Q.tail - 1; ++i) {
            Q.info[i] = Q.info[i + 1];
        }

        Q.info[Q.tail - 1] = -1;

        Q.tail--;
    }
    return temp_val;
}

void printInfo(const Queue& Q) {
    cout << Q.head << "\t" << Q.tail << "\t|";
    for (int i = 0; i < MAX_SIZE; ++i) {
        if (Q.info[i] == -1) {
            cout << " -1 ";
        } else {
            cout << " " << Q.info[i] << " ";
        }
    }

    if (isEmptyQueue(Q)) {
        cout << "\t: empty queue";
    } else if (isFullQueue(Q)) {
        cout << "\t: full queue";
    }

    cout << endl;
}