#include <stdio.h>
#define MAX 100

typedef struct {
    int id, arrival, burst, wait, turnaround;
} Process;

int main() {
    Process queue[MAX];
    int n, time = 0, total_wait = 0, total_turnaround = 0;
    
    printf("Enter number of processes: ");
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        queue[i].id = i + 1;
        printf("Enter arrival and burst time for P%d: ", i + 1);
        scanf("%d %d", &queue[i].arrival, &queue[i].burst);
    }
    
    for (int i = 0; i < n; i++) {
        if (time < queue[i].arrival) time = queue[i].arrival;
        queue[i].wait = time - queue[i].arrival;
        queue[i].turnaround = queue[i].wait + queue[i].burst;
        time += queue[i].burst;
        total_wait += queue[i].wait;
        total_turnaround += queue[i].turnaround;
    }
    
    printf("Avg waiting time: %.2f\n", (float)total_wait / n);
    printf("Avg turnaround time: %.2f\n", (float)total_turnaround / n);
    
    return 0;
}