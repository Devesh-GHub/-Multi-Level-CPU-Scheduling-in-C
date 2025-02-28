#include <stdio.h>
#include <stdlib.h>

#define MAX_PROCESSES 10

typedef struct {
    int id, arrival, burst, priority, remaining, waiting, turnaround;
} Process;

void print_table(Process processes[], int n) {
    printf("\n------------------------------------------------------------\n");
    printf(" ID   Arrival   Burst   Priority   Waiting   Turnaround\n");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < n; i++) {
        printf(" %2d   %7d   %5d   %8d   %7d   %9d\n", 
            processes[i].id, processes[i].arrival, processes[i].burst, 
            processes[i].priority, processes[i].waiting, processes[i].turnaround);
    }
    printf("------------------------------------------------------------\n");
}

void fcfs(Process processes[], int n) {
    int current_time = 0;
    for (int i = 0; i < n; i++) {
        if (current_time < processes[i].arrival)
            current_time = processes[i].arrival;
        processes[i].waiting = current_time - processes[i].arrival;
        processes[i].turnaround = processes[i].waiting + processes[i].burst;
        current_time += processes[i].burst;
    }
}

void round_robin(Process processes[], int n, int quantum) {
    int time = 0, remaining = n, i;
    for (i = 0; i < n; i++) processes[i].remaining = processes[i].burst;
    while (remaining > 0) {
        for (i = 0; i < n; i++) {
            if (processes[i].remaining > 0) {
                int exec_time = (processes[i].remaining > quantum) ? quantum : processes[i].remaining;
                time += exec_time;
                processes[i].remaining -= exec_time;
                if (processes[i].remaining == 0) {
                    processes[i].turnaround = time - processes[i].arrival;
                    processes[i].waiting = processes[i].turnaround - processes[i].burst;
                    remaining--;
                }
            }
        }
    }
}

void priority_scheduling(Process processes[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (processes[i].priority > processes[j].priority) {
                Process temp = processes[i];
                processes[i] = processes[j];
                processes[j] = temp;
            }
        }
    }
    fcfs(processes, n);
}

int main() {
    Process processes[MAX_PROCESSES];
    int n, choice, quantum;
    printf("Enter number of processes (max 10): ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        processes[i].id = i + 1;
        printf("Enter arrival time, burst time, and priority for Process %d: ", i + 1);
        scanf("%d %d %d", &processes[i].arrival, &processes[i].burst, &processes[i].priority);
    }
    
    printf("\nChoose Scheduling Algorithm:\n");
    printf("1. First-Come, First-Serve (FCFS)\n");
    printf("2. Round Robin\n");
    printf("3. Priority Scheduling\n");
    printf("Enter choice: ");
    scanf("%d", &choice);
    
    switch (choice) {
        case 1:
            printf("\nScheduling using FCFS...\n");
            fcfs(processes, n);
            break;
        case 2:
            printf("Enter time quantum: ");
            scanf("%d", &quantum);
            printf("\nScheduling using Round Robin...\n");
            round_robin(processes, n, quantum);
            break;
        case 3:
            printf("\nScheduling using Priority Scheduling...\n");
            priority_scheduling(processes, n);
            break;
        default:
            printf("Invalid choice! Exiting...\n");
            return 1;
    }
    print_table(processes, n);
    return 0;
}
