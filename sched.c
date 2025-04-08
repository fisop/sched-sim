#include "sched.h"
#include "switch.h"
#include <stdlib.h>
#include <limits.h>

extern struct proc proc[];

int current = 0;

struct proc* select_next(){
    struct proc* next = NULL;

    for (int i = 0; i < NUMPROC; i++) {
        int candidate = (current + i) % NUMPROC;

        if (proc[candidate].status == RUNNABLE) {
            next = &proc[candidate];
            current = candidate;
        }
    }
    
    return next;
}

void scheduler(){
    while (!done()){
        struct proc *candidate = select_next();

        if (candidate != NULL) {
            candidate->status = RUNNING;
            candidate->runtime += swtch(candidate);
        } else {
            idle();
        }
    }
}