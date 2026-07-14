/*
Algorithm: Priority Non-Preemptive Scheduling

Step 1 : Start

Step 2 : Read number of processes

Step 3 : Read Arrival Time,
         Burst Time and Priority

Step 4 : Mark all processes as unfinished

Step 5 : Select arrived process
         having highest priority

Step 6 : Calculate Completion Time

Step 7 : Calculate Turnaround Time
         TAT = CT - AT

Step 8 : Calculate Waiting Time
         WT = TAT - BT

Step 9 : Calculate Average TAT
         and Average WT

Step 10 : Display results

Step 11 : Stop
*/

#include <stdio.h>

void calculateCT(int n, int at[],
                 int bt[], int pr[],
                 int ct[])
{
    int finished[20] = {0};

    int completed = 0;
    int current_time = 0;
    int i;

    while(completed < n)
    {
        int highest_priority = 9999;
        int index = -1;

        // Find highest priority process
        for(i = 0; i < n; i++)
        {
            if(at[i] <= current_time &&
               finished[i] == 0)
            {
                if(pr[i] < highest_priority)
                {
                    highest_priority = pr[i];
                    index = i;
                }
            }
        }

        // CPU Idle
        if(index == -1)
        {
            current_time++;
        }
        else
        {
            // Calculate CT
            ct[index] =
            current_time + bt[index];

            current_time =
            ct[index];

            finished[index] = 1;

            completed++;
        }
    }
}

void calculateTAT(int n, int at[],
                  int ct[], int tat[])
{
    int i;

    for(i = 0; i < n; i++)
        tat[i] = ct[i] - at[i];
}

void calculateWT(int n, int bt[],
                 int tat[], int wt[])
{
    int i;

    for(i = 0; i < n; i++)
        wt[i] = tat[i] - bt[i];
}

void display(int n,
             int at[],
             int bt[],
             int pr[],
             int ct[],
             int tat[],
             int wt[])
{
    int i;
    float avgwt = 0;
    float avgtat = 0;

    printf("\nProcess\tAT\tBT\tPR\tCT\tTAT\tWT\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1,
               at[i],
               bt[i],
               pr[i],
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
    int pr[20];

    int ct[20];
    int tat[20];
    int wt[20];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("\nProcess P%d\n",
               i + 1);

        printf("Arrival Time: ");
        scanf("%d", &at[i]);

        printf("Burst Time: ");
        scanf("%d", &bt[i]);

        printf("Priority: ");
        scanf("%d", &pr[i]);
    }

    calculateCT(n, at, bt, pr, ct);

    calculateTAT(n, at, ct, tat);

    calculateWT(n, bt, tat, wt);

    display(n, at, bt, pr,
            ct, tat, wt);

    return 0;
}