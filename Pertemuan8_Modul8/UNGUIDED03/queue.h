#ifndef QUEUE_H
#define QUEUE_H

typedef int infotype;

struct Queue;

Queue* createQueue(int maxEl);
bool isEmpty(Queue* Q);
bool isFull(Queue* Q);
void enQueue(Queue* Q, infotype X);
bool deQueue(Queue* Q, infotype &X);
int length(Queue* Q);
void printQueue(Queue* Q);

#endif
