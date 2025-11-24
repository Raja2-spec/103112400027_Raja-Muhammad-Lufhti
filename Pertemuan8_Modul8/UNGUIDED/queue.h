#ifndef QUEUE_H
#define QUEUE_H

typedef int infotype;

const int MAX_SIZE = 5;

struct Queue {
    infotype info[MAX_SIZE]; 
    int head; 
    int tail; 
};


void createQueue(Queue& Q);

bool isEmptyQueue(const Queue& Q);

bool isFullQueue(const Queue& Q);

void enqueue(Queue& Q, infotype x);

infotype dequeue(Queue& Q); 

void printInfo(const Queue& Q);

#endif 