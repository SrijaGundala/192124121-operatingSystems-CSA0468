#include <stdio.h>
struct Process {
    int id;
    int burst_time;
};

int main() {
    struct Process processes[] = {
        {6, 16},
        {7, 5},
        {5, 8},
        {3, 7},
    };
    int num_processes = sizeof(processes) / sizeof(processes[0]);

    printf("First-Come, First-Served (FCFS) Process execution order:\n");

    int current_time = 0;
    int i;
    for (i = 0; i < num_processes; i++) {
        printf("Process %d (Time %d to %d)\n", processes[i].id, current_time, current_time + processes[i].burst_time);
        current_time += processes[i].burst_time;
    }

    return 0;
}
