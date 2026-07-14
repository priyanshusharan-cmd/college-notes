/*
Algorithm: Indexed File Allocation

1. Start.
2. Read the number of files.
3. For each file:
      a) Read file name.
      b) Read index block number.
      c) Read number of blocks allocated.
      d) Read the block numbers.
4. Store all block numbers in the index block.
5. Display file name, index block and allocated blocks.
6. Repeat for all files.
7. Stop.
*/

#include <stdio.h>

int main()
{
    int n;

    printf("Enter number of files: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        char fname[20];
        int indexBlock, blocks;

        printf("\nEnter file name: ");
        scanf("%s", fname);

        printf("Enter index block: ");
        scanf("%d", &indexBlock);

        printf("Enter number of blocks allocated: ");
        scanf("%d", &blocks);

        int b[blocks];

        printf("Enter block numbers:\n");
        for(int j = 0; j < blocks; j++)
            scanf("%d", &b[j]);

        printf("\nFile Name: %s\n", fname);
        printf("Index Block: %d\n", indexBlock);
        printf("Allocated Blocks: ");

        for(int j = 0; j < blocks; j++)
            printf("%d ", b[j]);

        printf("\n");
    }

    return 0;
}

/*
OUTPUT

Enter number of files: 2

Enter file name: file1
Enter index block: 5
Enter number of blocks allocated: 4
Enter block numbers:
10 14 18 22

File Name: file1
Index Block: 5
Allocated Blocks: 10 14 18 22

Enter file name: file2
Enter index block: 8
Enter number of blocks allocated: 3
Enter block numbers:
25 28 31

File Name: file2
Index Block: 8
Allocated Blocks: 25 28 31
*/
