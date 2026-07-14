/*
=========================================================
a) Rate monotonic scheduling (RMS) Algorithm

Input:
   n = number of tasks
   For each task i:
       Ci = computation time (execution time)
       Pi = period (deadline = Pi)

Output:
   Schedule of tasks over a given time frame (e.g., hyperperiod)

Algorithm:
1. Sort tasks by ascending period (shorter period -> higher priority).
2. Set current_time = 0
3. Define hyperperiod = LCM(P1, P2, ..., Pn) // total schedule length
4. While current_time < hyperperiod:
      For each task i in sorted order:
         If (current_time % Pi == 0):
             Release task i (ready to execute)
      If there are ready tasks:
         Select the task with highest priority (smallest Pi)
         Execute task for 1 time unit
         Decrease its remaining execution time
         If remaining execution time == 0:
             Mark task as completed until next release
      Else:
         Idle for 1 time unit
      current_time = current_time + 1
5. End loop
6. Print schedule timeline (which task ran at each time unit)
=========================================================
*/

#include <stdio.h>
#include <stdbool.h>

#define MAX_TASKS 10
#define MAX_TIME 10000

struct Task {
    int id;
    int c;    // Computation time (Burst time)
    int p;    // Period
    int rem_c; // Remaining computation time
};

// Function to calculate Greatest Common Divisor (GCD)
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// Function to calculate Least Common Multiple (LCM)
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {
    int n;
    struct Task tasks[MAX_TASKS];
    
    printf("Enter number of tasks: ");
    scanf("%d", &n);

    // Input loop
    for (int i = 0; i < n; i++) {
        tasks[i].id = i + 1;
        printf("\nTask P%d\n", tasks[i].id);
        printf("Computation Time (Ci): ");
        scanf("%d", &tasks[i].c);
        printf("Period (Pi): ");
        scanf("%d", &tasks[i].p);
        tasks[i].rem_c = 0; // Initialize with 0, will be replenished at time 0
    }

    // Step 1: Sort tasks by ascending period (shorter period -> higher priority)
    // Using a simple Bubble Sort
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (tasks[j].p > tasks[j+1].p) {
                struct Task temp = tasks[j];
                tasks[j] = tasks[j+1];
                tasks[j+1] = temp;
            }
        }
    }

    // Step 3: Define hyperperiod = LCM(P1, P2, ..., Pn)
    int hyperperiod = tasks[0].p;
    for (int i = 1; i < n; i++) {
        hyperperiod = lcm(hyperperiod, tasks[i].p);
    }
    
    printf("\n--- Calculated Hyperperiod: %d ---\n", hyperperiod);

    // Array to keep track of which task ran at each time unit for printing later
    int schedule[MAX_TIME] = {0}; 

    // Step 2 & 4: Simulation Loop
    for (int current_time = 0; current_time < hyperperiod; current_time++) {
        
        // Release tasks: Replenish execution time if current time is a multiple of Period
        for (int i = 0; i < n; i++) {
            if (current_time % tasks[i].p == 0) {
                tasks[i].rem_c = tasks[i].c;
            }
        }

        // Find highest priority ready task (since array is sorted by period, the first one we find is highest priority)
        int selected_task = -1;
        for (int i = 0; i < n; i++) {
            if (tasks[i].rem_c > 0) {
                selected_task = i;
                break;
            }
        }

        // Execute task or Idle
        if (selected_task != -1) {
            tasks[selected_task].rem_c -= 1;
            schedule[current_time] = tasks[selected_task].id; // Record ID for timeline
        } else {
            schedule[current_time] = 0; // 0 represents Idle
        }
    }

    // Step 6: Print schedule timeline clearly (Grouped by chunks)
    printf("\n--- Schedule Timeline ---\n");
    int current_running = schedule[0];
    int start_time = 0;

    for (int i = 1; i <= hyperperiod; i++) {
        // If the task changes or we reach the end of the hyperperiod, print the block
        if (i == hyperperiod || schedule[i] != current_running) {
            if (current_running == 0) {
                printf("Time [%3d - %3d] : IDLE\n", start_time, i);
            } else {
                printf("Time [%3d - %3d] : Task P%d executed\n", start_time, i, current_running);
            }
            
            // Setup for the next block
            if (i < hyperperiod) {
                current_running = schedule[i];
                start_time = i;
            }
        }
    }
    printf("-------------------------\n");

    return 0;
}