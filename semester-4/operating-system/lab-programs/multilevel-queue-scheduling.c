/*
=========================================================
Pseudocode for MULTI QUEUE Scheduling

BEGIN

1. Initialize two queues:
   SystemQueue (SQ) <- empty
   UserQueue (UQ) <- empty

2. Input number of processes n

3. FOR each process i = 1 to n DO
   Read ProcessID, ArrivalTime, BurstTime, Type
   IF Type == "System" THEN
       Insert process into SQ (in order of arrival)
   ELSE
       Insert process into UQ (in order of arrival)
   ENDIF
ENDFOR

4. Set current_time <- 0

5. WHILE (SQ is not empty OR UQ is not empty) DO

   // Step 1: Execute System Queue first (higher priority)
   WHILE (SQ is not empty) DO
       Select first process P from SQ (RR)

       IF current_time < P.ArrivalTime THEN
           current_time <- P.ArrivalTime
       ENDIF

       Execute P for its BurstTime

       current_time <- current_time + P.BurstTime
       CompletionTime[P] <- current_time

       Remove P from SQ
   ENDWHILE

   // Step 2: Execute User Queue (only when SQ is empty)
   WHILE (SQ is empty AND UQ is not empty) DO
       Select first process P from UQ (FCFS)

       IF current_time < P.ArrivalTime THEN
           current_time <- P.ArrivalTime
       ENDIF

       Execute P for its BurstTime

       current_time <- current_time + P.BurstTime
       CompletionTime[P] <- current_time

       Remove P from UQ
   ENDWHILE

ENDWHILE

6. FOR each process i
   TurnaroundTime[i] = CompletionTime[i] - ArrivalTime[i]
   WaitingTime[i] = TurnaroundTime[i] - BurstTime[i]
ENDFOR
=========================================================
*/

#include <stdio.h>
#include <stdbool.h>

#define MAX_PROCESSES 100

struct Process {
    int pid;
    int at;
    int bt;
    int type; // 1 for System, 2 for User
    int ct;
    int tat;
    int wt;
    bool completed;
};

int main() {
    int n;
    struct Process p[MAX_PROCESSES];
    
    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input loop
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("\nProcess P%d\n", p[i].pid);
        printf("Arrival Time: ");
        scanf("%d", &p[i].at);
        printf("Burst Time: ");
        scanf("%d", &p[i].bt);
        
        // Using integers for type to avoid string matching errors in C
        printf("Queue Type (1 for System, 2 for User): ");
        scanf("%d", &p[i].type);
        
        p[i].completed = false;
    }

    int current_time = 0;
    int completed_processes = 0;

    // Execution Loop
    while (completed_processes < n) {
        int idx = -1;
        int highest_priority = 999; // 1 is highest (System)
        int earliest_arrival = 999999;

        // Scan all processes to find the one that should execute next
        for (int i = 0; i < n; i++) {
            // Check if process has arrived and is not yet completed
            if (p[i].at <= current_time && !p[i].completed) {
                // Prioritize System (type 1) over User (type 2)
                if (p[i].type < highest_priority) {
                    highest_priority = p[i].type;
                    earliest_arrival = p[i].at;
                    idx = i;
                } 
                // If same queue type, use FCFS (earliest arrival time)
                else if (p[i].type == highest_priority && p[i].at < earliest_arrival) {
                    earliest_arrival = p[i].at;
                    idx = i;
                }
            }
        }

        // If a valid process was found in the ready queue
        if (idx != -1) {
            // Note: Even though pseudocode says (RR) for System, the logic underneath 
            // says "Execute P for its BurstTime". This implements that full-burst logic.
            current_time += p[idx].bt;
            p[idx].ct = current_time;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;
            p[idx].completed = true;
            completed_processes++;
        } else {
            // If no processes have arrived by current_time, the CPU is idle.
            current_time++;
        }
    }

    // Display Output
    float total_wt = 0, total_tat = 0;
    
    printf("\n--------------------------------------------------------------\n");
    printf("PID\tType\tAT\tBT\tCT\tTAT\tWT\n");
    printf("--------------------------------------------------------------\n");
    
    for (int i = 0; i < n; i++) {
        printf("P%d\t%s\t%d\t%d\t%d\t%d\t%d\n", 
            p[i].pid, 
            (p[i].type == 1) ? "Sys" : "Usr", 
            p[i].at, 
            p[i].bt, 
            p[i].ct, 
            p[i].tat, 
            p[i].wt);
            
        total_tat += p[i].tat;
        total_wt += p[i].wt;
    }

    printf("--------------------------------------------------------------\n");
    printf("Average Turnaround Time = %.2f\n", (total_tat / n));
    printf("Average Waiting Time = %.2f\n", (total_wt / n));

    return 0;
}