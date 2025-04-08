#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sched.h"
#include "switch.h"

#define STEPS 100000

struct proc proc[NUMPROC];
struct proc_type proc_type[NUMPROC] = {CPU1, CPU1, CPU2, IO1, IO2};
// struct proc_type proc_type[NUMPROC] = {CPU2, CPU2, CPU2, CPU2, CPU2};
//struct proc_type proc_type[NUMPROC] = {IO2, IO2, IO2, IO2, IO2};

void init(){
    srand(time(0));

    for (int i=0; i<NUMPROC; i++){
        proc[i].pid = i;
        proc[i].status = RUNNABLE;
        proc[i].runtime = 0;
    }
}

int main() {
    init();
    init_simulation(STEPS);

    scheduler();

    print_stats();
    return 0;
}