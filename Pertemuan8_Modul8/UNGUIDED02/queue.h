#ifndef QUEUE_H
#define QUEUE_H

const int maxEl = 8;

typedef int infotype;

struct Queue {
    infotype info[maxEl];
    int head;
    int tail;
};

void createQueue(Queue &Q);
bool isEmpty(Queue Q);
bool isFull(Queue Q);
void enqueue(Queue &Q, infotype x);
infotype dequeue(Queue &Q);
void printInfo(Queue Q);

#endif
