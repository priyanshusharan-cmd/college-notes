/*
Algorithm: Round Robin Scheduling
Input : 
Arrival Time (AT)
Burst Time (BT)
Time Quantum (TQ)

Output : 
Completion Time (CT)
Turnaround Time (TAT)
Waiting Time (WT)

Start
    Input number of processes, n
    Input time_quantum

    For i = 1 to n
        Input process_id[i], arrival_time[i], burst_time[i]
        remaining_time[i] = burst_time[i]
    End For

    Initialize current_time = 0
    Initialize a ready_queue = empty
    Initialize waiting_time[i] = 0, turnaround_time[i] = 0

    While there are unfinished processes
        Add all processes that have arrived (arrival_time <= current_time) 
        and not yet completed into ready_queue

        If ready_queue is empty
            current_time = current_time + 1  // CPU idle
            Continue
        End If

        Select process p from front of ready_queue
        
        If remaining_time[p] > time_quantum
            Execute process p for time_quantum
            remaining_time[p] = remaining_time[p] - time_quantum
            current_time = current_time + time_quantum
            Add newly arrived processes to ready_queue
            Put process p back at end of ready_queue
        Else
            Execute process p for remaining_time[p]
            current_time = current_time + remaining_time[p]
            turnaround_time[p] = current_time - arrival_time[p]
            waiting_time[p] = turnaround_time[p] - burst_time[p]
            remaining_time[p] = 0  // process completed
        End If
    End While

    Print process_id, arrival_time, burst_time, waiting_time, turnaround_time
    Calculate average_waiting_time = sum(waiting_time) / n
    Calculate average_turnaround_time = sum(turnaround_time) / n
    Print average_waiting_time, average_turnaround_time
End
*/

#include <stdio.h>
#include <stdbool.h>

int main() {
    int n, tq;
    int current_time = 0;
    int completed_processes = 0;
    
    printf("Enter number of processes: ");
    scanf("%d", &n);
    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    int pid[100], at[100], bt[100], rt[100], ct[100], tat[100], wt[100];
    bool completed[100] = {false};
    bool in_queue[100] = {false};

    // Input loop
    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("\nProcess P%d\n", pid[i]);
        printf("Arrival Time: ");
        scanf("%d", &at[i]);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
        rt[i] = bt[i]; // Initialize remaining time
    }

    // Queue implementation variables
    int queue[1000]; 
    int front = 0, rear = 0;

    while (completed_processes < n) {
        // Add all processes that have arrived by 'current_time' into the queue
        for (int i = 0; i < n; i++) {
            if (at[i] <= current_time && !completed[i] && !in_queue[i]) {
                queue[rear++] = i;
                in_queue[i] = true;
            }
        }

        // If no processes have arrived yet, CPU is idle
        if (front == rear) {
            current_time++;
            continue;
        }

        // Select process 'p' from front of ready_queue
        int p = queue[front++];
        in_queue[p] = false; // It is currently in the CPU, not the queue

        if (rt[p] > tq) {
            // Execute for time quantum
            rt[p] -= tq;
            current_time += tq;

            // CRITICAL: Add newly arrived processes to queue BEFORE pushing 'p' back
            for (int i = 0; i < n; i++) {
                if (at[i] <= current_time && !completed[i] && !in_queue[i] && i != p) {
                    queue[rear++] = i;
                    in_queue[i] = true;
                }
            }
            
            // Put process 'p' back at end of ready_queue
            queue[rear++] = p;
            in_queue[p] = true;

        } else {
            // Execute for the remaining time
            current_time += rt[p];
            rt[p] = 0; // Process completed
            
            ct[p] = current_time;
            tat[p] = ct[p] - at[p];
            wt[p] = tat[p] - bt[p];
            
            completed[p] = true;
            completed_processes++;

            // Check for any new arrivals at the exact time this process finished
            for (int i = 0; i < n; i++) {
                if (at[i] <= current_time && !completed[i] && !in_queue[i]) {
                    queue[rear++] = i;
                    in_queue[i] = true;
                }
            }
        }
    }

    // Display Output
    float total_wt = 0, total_tat = 0;
    
    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);
        total_tat += tat[i];
        total_wt += wt[i];
    }

    printf("\nAverage Turnaround Time = %.2f", (total_tat / n));
    printf("\nAverage Waiting Time = %.2f\n", (total_wt / n));

    return 0;
}