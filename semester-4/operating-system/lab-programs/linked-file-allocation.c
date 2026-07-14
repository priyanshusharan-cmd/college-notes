/*
Algorithm: Linked File Allocation

1. Start.
2. Read the number of files.
3. For each file:
      a) Read file name.
      b) Read the starting block.
      c) Read the number of blocks.
      d) Read the block numbers.
4. Link each block to the next block.
5. Display file name, starting block and linked blocks.
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
        int blocks;

        printf("\nEnter file name: ");
        scanf("%s", fname);

        printf("Enter number of blocks: ");
        scanf("%d", &blocks);

        int b[blocks];

        printf("Enter block numbers:\n");
        for(int j = 0; j < blocks; j++)
            scanf("%d", &b[j]);

        printf("\nFile Name: %s\n", fname);
        printf("Linked Allocation:\n");

        for(int j = 0; j < blocks - 1; j++)
        {
            printf("%d -> %d\n", b[j], b[j + 1]);
        }

        printf("%d -> NULL\n", b[blocks - 1]);
    }

    return 0;
}

/*
OUTPUT

Enter number of files: 2

Enter file name: file1
Enter number of blocks: 4

Enter block numbers:
10 14 18 22

File Name: file1
Linked Allocation:
10 -> 14
14 -> 18
18 -> 22
22 -> NULL

Enter file name: file2
Enter number of blocks: 3

Enter block numbers:
25 28 31

File Name: file2
Linked Allocation:
25 -> 28
28 -> 31
31 -> NULL
*/
