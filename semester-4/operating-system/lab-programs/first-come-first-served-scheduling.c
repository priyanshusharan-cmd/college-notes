/*
Algorithm: First Come First Serve (FCFS) Scheduling

Input :
    Arrival Time (AT)
    Burst Time (BT)

Output :
    Completion Time (CT)
    Turnaround Time (TAT)
    Waiting Time (WT)
    Average TAT
    Average WT

Step 1 : Start

Step 2 : Read number of processes (n)

Step 3 : Read Arrival Time and
         Burst Time for each process

Step 4 : Initialize current_time = 0

Step 5 : For each process

         a) If current_time < AT[i]
                current_time = AT[i]

         b) Calculate Completion Time
                CT[i] = current_time + BT[i]

         c) Update current_time
                current_time = CT[i]

Step 6 : Calculate Turnaround Time
                TAT[i] = CT[i] - AT[i]

Step 7 : Calculate Waiting Time
                WT[i] = TAT[i] - BT[i]

Step 8 : Calculate Average TAT
         and Average WT

Step 9 : Display AT, BT, CT,
         TAT and WT

Step 10 : Stop
*/

#include <stdio.h>

// Function to calculate Completion Time
void calculateCT(int n, int at[], int bt[], int ct[])
{
    int i;
    int current_time = 0;

    for(i = 0; i < n; i++)
    {
        // If CPU is idle, move time
        // to process arrival time
        if(current_time < at[i])
            current_time = at[i];

        // Calculate Completion Time
        ct[i] = current_time + bt[i];

        // Update current time
        current_time = ct[i];
    }
}

// Function to calculate Turnaround Time
void calculateTAT(int n, int at[],
                  int ct[], int tat[])
{
    int i;

    for(i = 0; i < n; i++)
    {
        // TAT = CT - AT
        tat[i] = ct[i] - at[i];
    }
}

// Function to calculate Waiting Time
void calculateWT(int n, int bt[],
                 int tat[], int wt[])
{
    int i;

    for(i = 0; i < n; i++)
    {
        // WT = TAT - BT
        wt[i] = tat[i] - bt[i];
    }
}

// Function to display output
void display(int n,
             int at[],
             int bt[],
             int ct[],
             int tat[],
             int wt[])
{
    int i;

    float avgwt = 0;
    float avgtat = 0;

    printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1,
               at[i],
               bt[i],
               ct[i],
               tat[i],
               wt[i]);

        avgwt += wt[i];
        avgtat += tat[i];
    }

    printf("\nAverage Turnaround Time = %.2f",
           avgtat / n);

    printf("\nAverage Waiting Time = %.2f\n",
           avgwt / n);
}

int main()
{
    int n, i;

    int at[20];
    int bt[20];
    int ct[20];
    int tat[20];
    int wt[20];

    // Read number of processes
    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Read Arrival Time and Burst Time
    for(i = 0; i < n; i++)
    {
        printf("\nProcess P%d\n", i + 1);

        printf("Arrival Time: ");
        scanf("%d", &at[i]);

        printf("Burst Time: ");
        scanf("%d", &bt[i]);
    }

    // Calculate Completion Time
    calculateCT(n, at, bt, ct);

    // Calculate Turnaround Time
    calculateTAT(n, at, ct, tat);

    // Calculate Waiting Time
    calculateWT(n, bt, tat, wt);

    // Display result
    display(n, at, bt, ct, tat, wt);

    return 0;
}