#include <stdbool.h>
#include <stdio.h>
#define max_size 11

typedef struct{
    int item[max_size];
    int front;
    int rear;
} queue;


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
        printf("queue is full cant insert");
        return;
    }
    q->item[q->rear] = value;
    q->rear = (q->rear+1)%max_size;
    if(q->front == -1) q->front = 0;
}

void dqueue(queue *q){
    if(qisempty(q) == true){
        printf("Already empty Underflow!");
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

/*
bool check_for_completion(){
    bool result = false;
    return (bool)result;
}

Will use this later for blocked state
*/
struct process{
    int priority;
    int id;
    int progress;
    bool complete;
    int progress_end;
    bool blocked;
};

int highest_priority(queue *q, struct process p[]){
    int highest = 0;
    int i = q->front+1;
    while(i < q->rear){
        int temp = q->item[i];
        if(p[temp - 1].priority > highest) highest = q->item[i];
        i++;
    }
    return highest;
}

int main(){
    queue contain;
    contain.front = -1;
    contain.rear = 0;

    struct process p[10] = {
        {2, 0, 0, false, 15, false},
        {1, 1, 0, false, 10, false},
        {3, 2, 0, false, 20, false},
        {3, 3, 0, false, 30, false},
        {1, 4, 0, false, 13, false},
        {2, 5, 0, false, 27, false},
        {2, 6, 0, false, 28, false},
        {1, 7, 0, false, 29, false},
        {2, 8, 0, false, 40, false},
        {3, 9, 0, false, 38, false},
    };

    int n = sizeof(p) / sizeof(p[0]);

    for(int i = 0; i < n; i++){
        enqueue(&contain, i);
    }

    while(qisempty(&contain) == false){
        int idx = front_value(&contain);
        p[idx].progress++;
        printf("Process no %d is executing: progress %d is out of %d is done\n", idx, p[idx].progress, p[idx].progress_end);
        if(p[idx].progress >= p[idx].progress_end){
            p[idx].complete = true;
            dqueue(&contain);
            printf("Process no %d is done and now terminated\n", idx);

        }
        else{
            dqueue(&contain);
            enqueue(&contain, idx);
        }
    }
    return 0;
}
