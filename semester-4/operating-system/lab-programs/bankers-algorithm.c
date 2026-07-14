/*
Algorithm: Banker's Algorithm (Safety Algorithm)

Step 1 : Start

Step 2 : Read number of processes (n)

Step 3 : Read number of resources (m)

Step 4 : Read Allocation Matrix

Step 5 : Read Maximum Matrix

Step 6 : Read Available Vector

Step 7 : Calculate Need Matrix

            Need = Max - Allocation

Step 8 : Initialize

            Work = Available

            Finish[i] = False

Step 9 : Find a process Pi such that

            Finish[i] = False

            Need[i] <= Work

Step 10 : If such a process exists

             Work =
             Work + Allocation[i]

             Finish[i] = True

             Add Pi to Safe Sequence

Step 11 : Repeat Step 9 and Step 10
          until all processes finish
          or no process can be allocated

Step 12 : If all processes finish

             System is Safe

          Else

             System is Unsafe

Step 13 : Display Safe Sequence

Step 14 : Stop
*/

#include <stdio.h>

void calculateNeed(int n, int m,
                   int max[][20],
                   int allocation[][20],
                   int need[][20])
{
    int i, j;

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            need[i][j] =
            max[i][j] - allocation[i][j];
        }
    }
}

int checkSafeState(int n, int m,
                   int allocation[][20],
                   int need[][20],
                   int available[],
                   int safeSequence[])
{
    int work[20];
    int finish[20];

    int i, j;

    for(i = 0; i < m; i++)
        work[i] = available[i];

    for(i = 0; i < n; i++)
        finish[i] = 0;

    int count = 0;

    while(count < n)
    {
        int found = 0;

        for(i = 0; i < n; i++)
        {
            if(finish[i] == 0)
            {
                int possible = 1;

                for(j = 0; j < m; j++)
                {
                    if(need[i][j] > work[j])
                    {
                        possible = 0;
                        break;
                    }
                }

                if(possible)
                {
                    for(j = 0; j < m; j++)
                    {
                        work[j] =
                        work[j] +
                        allocation[i][j];
                    }

                    safeSequence[count] = i;

                    count++;

                    finish[i] = 1;

                    found = 1;
                }
            }
        }

        if(found == 0)
            break;
    }

    if(count == n)
        return 1;
    else
        return 0;
}

int main()
{
    int n, m;
    int i, j;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &m);

    int allocation[20][20];
    int max[20][20];
    int need[20][20];

    int available[20];
    int safeSequence[20];

    printf("\nEnter Allocation Matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            scanf("%d",
                  &allocation[i][j]);
        }
    }

    printf("\nEnter Maximum Matrix:\n");

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            scanf("%d",
                  &max[i][j]);
        }
    }

    printf("\nEnter Available Vector:\n");

    for(i = 0; i < m; i++)
    {
        scanf("%d",
              &available[i]);
    }

    calculateNeed(n, m,
                  max,
                  allocation,
                  need);

    if(checkSafeState(n, m,
                      allocation,
                      need,
                      available,
                      safeSequence))
    {
        printf("\nSystem is in Safe State\n");

        printf("Safe Sequence : ");

        for(i = 0; i < n; i++)
        {
            printf("P%d",
                   safeSequence[i]);

            if(i != n - 1)
                printf(" -> ");
        }
    }
    else
    {
        printf("\nSystem is NOT in Safe State");
    }

    return 0;
}