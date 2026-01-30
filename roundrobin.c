#include <iso646.h>
#include <stdbool.h>
#include <stdio.h>
#include "queue.h"
#define Max_priority 3

struct process{
    int priority;
    int id;
    int progress;
    bool complete;
    int progress_end;
    bool blocked;
};

void enqueue_priority(struct process *p, queue ready[], int n){
    for(int i=0; i<n; i++){
        int prio = p[i].priority;
        enqueue(&ready[prio-1], p[i].id);
    }

}

int main(){

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

    queue ready[Max_priority];

    for(int i=0; i<Max_priority; i++){
        init_queue(&ready[i]);
    }
    enqueue_priority(p, ready, 10);

    int k = 0;
    while(k < Max_priority){
        if(qisempty(&ready[k]) == false){
            int idx = front_value(&ready[k]);
            p[idx].progress++;
            printf("Process no %d is executing: progress %d is out of %d is done\n", idx, p[idx].progress, p[idx].progress_end);
            if(p[idx].progress >= p[idx].progress_end){
                p[idx].complete = true;
                dqueue(&ready[k]);
                printf("Progress no %d is done and now terminated\n", idx);

            }
            else{
                dqueue(&ready[k]);
                enqueue(&ready[k], idx);
            }
        }
        else{
            k++;
        }
    }

    return 0;
}
