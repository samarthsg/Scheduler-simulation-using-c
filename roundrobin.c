#include <iso646.h>
#include <stdbool.h>
#include <stdio.h>
#include "queue.h"

struct process{
    int priority;
    int id;
    int progress;
    bool complete;
    int progress_end;
    bool blocked;
};

int highest_priority(struct process p[], int n){
    int highest = 0;
    for(int i=0; i<n; i++){
        if (p[i].priority > p[highest].priority && p[i].complete == false){
            highest = p[i].priority;
        }
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

    queue ready;
    ready.front = -1;
    ready.rear = 0;

    int n = sizeof(p) / sizeof(p[0]);


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
