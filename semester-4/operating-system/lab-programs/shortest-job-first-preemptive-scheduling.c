/*
Algorithm: Shortest Job First (SJF) Preemptive

Step 1 : Start

Step 2 : Read number of processes

Step 3 : Read Arrival Time and
         Burst Time

Step 4 : Initialize Remaining Time

Step 5 : Select process with
         minimum Remaining Time

Step 6 : Execute for 1 time unit

Step 7 : Calculate Completion Time

Step 8 : Calculate Turnaround Time
         TAT = CT - AT

Step 9 : Calculate Waiting Time
         WT = TAT - BT

Step 10 : Calculate Average TAT
          and Average WT

Step 11 : Display results

Step 12 : Stop
*/

#include <stdio.h>

void calculateCT(int n, int at[],
                 int bt[], int ct[])
{
    int rt[20];
    int completed = 0;
    int current_time = 0;
    int i;

    for(i = 0; i < n; i++)
        rt[i] = bt[i];

    while(completed < n)
    {
        int min_rt = 9999;
        int index = -1;

        for(i = 0; i < n; i++)
        {
            if(at[i] <= current_time &&
               rt[i] > 0)
            {
                if(rt[i] < min_rt)
                {
                    min_rt = rt[i];
                    index = i;
                }
            }
        }

        if(index == -1)
        {
            current_time++;
        }
        else
        {
            rt[index]--;

            current_time++;

            if(rt[index] == 0)
            {
                ct[index] =
                current_time;

                completed++;
            }
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
    }

    calculateCT(n, at, bt, ct);

    calculateTAT(n, at, ct, tat);

    calculateWT(n, bt, tat, wt);

    display(n, at, bt, ct, tat, wt);

    return 0;
}