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

    // Scheduler loop - uses priority queues efficiently
    // Time Complexity: O(n) where n is total number of processes
    // Each process is dequeued and processed exactly once (or re-enqueued after time slice)
    // Finding highest priority queue is O(Max_priority) which is constant
    bool all_done = false;
    while(!all_done){
        // Find highest priority non-empty queue - O(Max_priority) = O(1) since Max_priority is constant
        int selected_priority = -1;
        for(int prio = 0; prio < Max_priority; prio++){
            if(!qisempty(&ready[prio])){
                selected_priority = prio;
                break;
            }
        }
        
        // If no queue has processes, all are done
        if(selected_priority == -1){
            all_done = true;
            break;
        }
        
        // Get process from highest priority queue - O(1)
        int idx = front_value(&ready[selected_priority]);
        dqueue(&ready[selected_priority]);
        
        // Execute process for one time slice
        p[idx].progress++;
        printf("Process no %d (priority %d) is executing: progress %d out of %d is done\n", 
               idx, p[idx].priority, p[idx].progress, p[idx].progress_end);
        
        // Check if process is complete
        if(p[idx].progress >= p[idx].progress_end){
            p[idx].complete = true;
            printf("Process no %d is done and now terminated\n", idx);
        }
        else{
            // Re-enqueue to its priority queue - O(1)
            enqueue(&ready[p[idx].priority - 1], idx);
        }
    }

    return 0;
}
