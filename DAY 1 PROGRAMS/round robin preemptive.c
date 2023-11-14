#include <stdio.h>

// Structure to represent a process
struct Process {
    int id;
    int burst_time;
    int remaining_time;
};

int main() {
    
    struct Process processes[] = {
	    {6, 6, 6},
	    {5, 5, 5},
        {6, 6, 6},
        {5, 5, 5},
    };
    int num_processes = sizeof(processes) / sizeof(processes[0]);
    int time_quantum = 2;

    printf("Process execution order:\n");

    int completed = 0;
    int current_time = 0;
	int i;
    while (completed < num_processes) {
        for (i = 0; i < num_processes; i++) {
            if (processes[i].remaining_time > 0) {
                if (processes[i].remaining_time > time_quantum) {
                    printf("Process %d (Time %d to %d)\n", processes[i].id, current_time, current_time + time_quantum);
                    current_time += time_quantum;
                    processes[i].remaining_time -= time_quantum;
                } else {
                    printf("Process %d (Time %d to %d)\n", processes[i].id, current_time, current_time + processes[i].remaining_time);
                    current_time += processes[i].remaining_time;
                    processes[i].remaining_time = 0;
                    completed++;
                }
            }
        }
    }

    return 0;
}
