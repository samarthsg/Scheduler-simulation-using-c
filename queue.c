#include <stdbool.h>
#include <stdio.h>
#include "queue.h"

bool qisfull(queue *q){
    if((q->rear+1) % max_size == q->front) return true;
    else return false;
}

bool qisempty(queue *q){
    if(q->front == -1) return true;
    else return false;
}

void enqueue(queue *q, int value){
    if(qisfull(q) == true){
        printf("queue is full cant insert\n");
        return;
    }
    q->item[q->rear] = value;
    q->rear = (q->rear+1)%max_size;
    if(q->front == -1) q->front = 0;
}

void dqueue(queue *q){
    if(qisempty(q) == true){
        printf("Already empty Underflow!\n");
        return;
    }
    q->front = (q->front+1)%max_size;
    if(q->front == q->rear){
        q->front = -1;
        q->rear = 0;
    }
}

int front_value(queue *q){
    int temp = q->item[q->front];
    return temp;
}
