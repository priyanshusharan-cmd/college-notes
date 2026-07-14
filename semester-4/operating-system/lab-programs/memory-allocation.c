/*
Algorithm: Memory Allocation Strategies

Step 1 : Start

Step 2 : Read number of memory blocks

Step 3 : Read sizes of memory blocks

Step 4 : Read number of processes

Step 5 : Read sizes of processes

Step 6 : Read choice

            1. First Fit
            2. Best Fit
            3. Worst Fit

Step 7 : Allocate memory according
         to selected strategy

Step 8 : Display allocation table

Step 9 : Stop
*/

#include <stdio.h>

void firstFit(int nb, int block[],
              int np, int process[],
              int allocation[])
{
    int i, j;

    for(i = 0; i < np; i++)
    {
        allocation[i] = -1;

        for(j = 0; j < nb; j++)
        {
            if(block[j] >= process[i])
            {
                allocation[i] = j;
                block[j] -= process[i];
                break;
            }
        }
    }
}

void bestFit(int nb, int block[],
             int np, int process[],
             int allocation[])
{
    int i, j;

    for(i = 0; i < np; i++)
    {
        int best = -1;

        allocation[i] = -1;

        for(j = 0; j < nb; j++)
        {
            if(block[j] >= process[i])
            {
                if(best == -1 ||
                   block[j] < block[best])
                {
                    best = j;
                }
            }
        }

        if(best != -1)
        {
            allocation[i] = best;
            block[best] -= process[i];
        }
    }
}

void worstFit(int nb, int block[],
              int np, int process[],
              int allocation[])
{
    int i, j;

    for(i = 0; i < np; i++)
    {
        int worst = -1;

        allocation[i] = -1;

        for(j = 0; j < nb; j++)
        {
            if(block[j] >= process[i])
            {
                if(worst == -1 ||
                   block[j] > block[worst])
                {
                    worst = j;
                }
            }
        }

        if(worst != -1)
        {
            allocation[i] = worst;
            block[worst] -= process[i];
        }
    }
}

void display(int np,
             int process[],
             int allocation[])
{
    int i;

    printf("\nProcess\tSize\tBlock\n");

    for(i = 0; i < np; i++)
    {
        printf("P%d\t%d\t",
               i + 1,
               process[i]);

        if(allocation[i] != -1)
            printf("%d\n",
                   allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }
}

int main()
{
    int nb, np, i, choice;

    int block[20];
    int temp[20];

    int process[20];
    int allocation[20];

    printf("Enter number of blocks: ");
    scanf("%d", &nb);

    printf("Enter block sizes:\n");

    for(i = 0; i < nb; i++)
    {
        scanf("%d", &block[i]);
        temp[i] = block[i];
    }

    printf("Enter number of processes: ");
    scanf("%d", &np);

    printf("Enter process sizes:\n");

    for(i = 0; i < np; i++)
        scanf("%d", &process[i]);

    printf("\n1. First Fit");
    printf("\n2. Best Fit");
    printf("\n3. Worst Fit");

    printf("\nEnter choice: ");
    scanf("%d", &choice);

    if(choice == 1)
        firstFit(nb, temp,
                 np, process,
                 allocation);

    else if(choice == 2)
        bestFit(nb, temp,
                np, process,
                allocation);

    else if(choice == 3)
        worstFit(nb, temp,
                 np, process,
                 allocation);

    else
    {
        printf("Invalid Choice");
        return 0;
    }

    display(np,
            process,
            allocation);

    return 0;
}