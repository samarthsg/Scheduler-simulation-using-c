#ifndef QUEUE_H
#define QUEUE_H

#include<stdbool.h>

#define max_size 11
typedef struct {
    int item[max_size];
    int front;
    int rear;
} queue;

// queue operations
bool qisfull(queue *q);
bool qisempty(queue *q);
void enqueue(queue *q, int value);
void dqueue(queue *q);
int front_value(queue *q);

#endif
