#include <stdbool.h>
#include <stdio.h>
#define max_size 100

typedef struct{
    int item[max_size];
    int front;
    int rear;
} queue;


bool qisfull(queue *q){
    if(q->rear == max_size) return true;
    else return false;
}

bool qisempty(queue *q){
    if(q->front == q->rear-1 ) return true;
    else return false;
}

void enqueue(queue *q, int value){
    if(qisfull(q) == true){
        printf("queue is full cant insert");
        return;
    }
    else {
        q->item[q->rear] = value;
        q->rear++;
    }
}

void dqueue(queue *q){
    if(qisempty(q) == true){
        printf("Already empty Underflow!");
        return;
    }
    else {
        q->front++;
    }
}

int front_value(queue *q){
    int temp = q->item[q->front + 1];
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
    int id;
    int progress;
    bool complete;
    int progress_end;
    bool blocked;
};

int main(){
    queue contain;
    contain.front = -1;
    contain.rear = 0;

    struct process p[3] = {

        {1, 0, false, 15, false},
        {2, 0, false, 10, false},
        {3, 0, false, 20, false},
    };

    int n = sizeof(p) / sizeof(p[0]);

    for(int i = 0; i < n; i++){
        enqueue(&contain, p[i].id);
    }

    while(qisempty(&contain) == false){
        int temp = front_value(&contain);
        p[temp-1].progress++;
        printf("Process no %d is executing: progress %d is out of %d is done\n", temp, p[temp-1].progress, p[temp-1].progress_end);
        if(p[temp-1].progress >= p[temp-1].progress_end){
            p[temp-1].complete = true;
            dqueue(&contain);
            printf("Process no %d is done and now terminated\n", temp);

        }
        else{
            dqueue(&contain);
            enqueue(&contain, temp);
        }
    }
    return 0;
}
