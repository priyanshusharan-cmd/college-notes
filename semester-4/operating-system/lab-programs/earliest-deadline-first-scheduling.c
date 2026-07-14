/*
=========================================================
b) Earliest Deadline first (EDF) pseudocode

    * n -> Number of processes
    * For each process i:
        * arrival[i] -> Arrival time
        * burst[i] -> Burst time
        * deadline[i] -> Deadline

Pseudocode
BEGIN

INPUT n
FOR i = 1 to n DO
    INPUT arrival[i], burst[i], deadline[i]
    remaining[i] = burst[i]
END FOR
time = 0
completed = 0

WHILE completed < n DO
    min_deadline = INFINITY
    selected = -1
    // Find process with earliest deadline among arrived processes
    FOR i = 1 to n DO
        IF arrival[i] <= time AND remaining[i] > 0 THEN
            IF deadline[i] < min_deadline THEN
                min_deadline = deadline[i]
                selected = i
            END IF
        END IF
    END FOR

    IF selected == -1 THEN
        time = time + 1  // CPU idle
    ELSE
        // Execute selected process for 1 unit (preemptive EDF)
        remaining[selected] = remaining[selected] - 1
        time = time + 1
    END IF
END WHILE
END
=========================================================
*/

#include <stdio.h>
#include <stdbool.h>

#define MAX_PROCESSES 100
#define MAX_TIME 10000
#define INFINITY 999999

int main() {
    int n;
    
    int pid[MAX_PROCESSES];
    int at[MAX_PROCESSES]; // Arrival Time
    int bt[MAX_PROCESSES]; // Burst Time
    int dt[MAX_PROCESSES]; // Deadline
    int rt[MAX_PROCESSES]; // Remaining Time
    int ct[MAX_PROCESSES]; // Completion Time
    int tat[MAX_PROCESSES]; // Turnaround Time
    int wt[MAX_PROCESSES]; // Waiting Time
    
    int schedule[MAX_TIME] = {0}; // Array to store the timeline

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input loop
    for (int i = 0; i < n; i++) {
        pid[i] = i + 1;
        printf("\nProcess P%d\n", pid[i]);
        printf("Arrival Time: ");
        scanf("%d", &at[i]);
        printf("Burst Time: ");
        scanf("%d", &bt[i]);
        printf("Deadline: ");
        scanf("%d", &dt[i]);
        
        rt[i] = bt[i]; // Initialize remaining time
    }

    int time = 0;
    int completed = 0;
    float total_wt = 0, total_tat = 0;

    // Preemptive EDF Execution Loop
    while (completed < n && time < MAX_TIME) {
        int min_deadline = INFINITY;
        int selected = -1;

        // Find process with earliest deadline among arrived processes that are not finished
        for (int i = 0; i < n; i++) {
            if (at[i] <= time && rt[i] > 0) {
                if (dt[i] < min_deadline) {
                    min_deadline = dt[i];
                    selected = i;
                }
            }
        }

        if (selected == -1) {
            schedule[time] = 0; // 0 represents IDLE
            time++;
        } else {
            schedule[time] = pid[selected]; // Record which process ran
            rt[selected]--;
            time++;

            // Check if the process just finished executing
            if (rt[selected] == 0) {
                completed++; 
                
                ct[selected] = time;
                tat[selected] = ct[selected] - at[selected];
                wt[selected] = tat[selected] - bt[selected];
                
                total_tat += tat[selected];
                total_wt += wt[selected];
            }
        }
    }

    int total_time = time;

    // Print grouped schedule timeline
    printf("\n--- Schedule Timeline ---\n");
    int current_running = schedule[0];
    int start_time = 0;

    for (int i = 1; i <= total_time; i++) {
        // If the task changes or we reach the end, print the block
        if (i == total_time || schedule[i] != current_running) {
            if (current_running == 0) {
                printf("Time [%3d - %3d] : IDLE\n", start_time, i);
            } else {
                printf("Time [%3d - %3d] : Task P%d executed\n", start_time, i, current_running);
            }
            
            // Setup for the next block
            if (i < total_time) {
                current_running = schedule[i];
                start_time = i;
            }
        }
    }
    printf("-------------------------\n");

    // Print Results cleanly
    printf("\nPID\tAT\tBT\tDead\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n", 
               pid[i], at[i], bt[i], dt[i], ct[i], tat[i], wt[i]);
    }
    
    printf("\nAverage Turnaround Time = %.2f\n", (total_tat / n));
    printf("Average Waiting Time = %.2f\n", (total_wt / n));

    return 0;
}