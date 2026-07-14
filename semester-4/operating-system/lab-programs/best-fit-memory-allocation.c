/*
Algorithm: Best Fit Memory Allocation

1. Start.
2. Read the number of memory blocks.
3. Read the size of each memory block.
4. Read the number of processes.
5. Read the size of each process.
6. For each process:
      a) Search all memory blocks.
      b) Find the smallest block that can accommodate the process.
      c) Allocate the process to that block.
      d) Reduce the remaining size of the block.
7. If no suitable block is found, mark the process as not allocated.
8. Display the allocation result.
9. Stop.
*/

#include <stdio.h>

int main()
{
    int nb, np;

    printf("Enter number of memory blocks: ");
    scanf("%d", &nb);

    int block[nb];

    printf("Enter sizes of memory blocks:\n");
    for(int i = 0; i < nb; i++)
        scanf("%d", &block[i]);

    printf("Enter number of processes: ");
    scanf("%d", &np);

    int process[np];
    int allocation[np];

    printf("Enter sizes of processes:\n");
    for(int i = 0; i < np; i++)
    {
        scanf("%d", &process[i]);
        allocation[i] = -1;
    }

    for(int i = 0; i < np; i++)
    {
        int best = -1;

        for(int j = 0; j < nb; j++)
        {
            if(block[j] >= process[i])
            {
                if(best == -1 || block[j] < block[best])
                    best = j;
            }
        }

        if(best != -1)
        {
            allocation[i] = best;
            block[best] -= process[i];
        }
    }

    printf("\nProcess\tProcess Size\tBlock Number\n");

    for(int i = 0; i < np; i++)
    {
        printf("P%d\t%d\t\t", i + 1, process[i]);

        if(allocation[i] != -1)
            printf("%d\n", allocation[i] + 1);
        else
            printf("Not Allocated\n");
    }

    return 0;
}

/*
OUTPUT

Enter number of memory blocks: 5

Enter sizes of memory blocks:
100
500
200
300
600

Enter number of processes: 4

Enter sizes of processes:
212
417
112
426

Process Process Size Block Number
P1      212          4
P2      417          2
P3      112          3
P4      426          5
*/
