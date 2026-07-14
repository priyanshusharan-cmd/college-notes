/*
Algorithm: Sequential File Allocation

1. Start.
2. Read the number of files.
3. For each file:
      a) Read file name.
      b) Read starting block.
      c) Read file length.
4. Allocate blocks sequentially from the starting block.
5. Display file name, start block and allocated blocks.
6. Repeat for all files.
7. Stop.
*/

#include <stdio.h>

int main()
{
    int n;

    printf("Enter number of files: ");
    scanf("%d", &n);

    char fname[20];
    int start, length;

    printf("\nFile\tStart Block\tLength\tAllocated Blocks\n");

    for(int i = 0; i < n; i++)
    {
        printf("\nEnter file name: ");
        scanf("%s", fname);

        printf("Enter starting block: ");
        scanf("%d", &start);

        printf("Enter file length: ");
        scanf("%d", &length);

        printf("%s\t%d\t\t%d\t", fname, start, length);

        for(int j = 0; j < length; j++)
        {
            printf("%d ", start + j);
        }

        printf("\n");
    }

    return 0;
}

/*
OUTPUT
Enter number of files: 2

Enter file name: file1
Enter starting block: 10
Enter file length: 4
file1   10      4       10 11 12 13

Enter file name: file2
Enter starting block: 20
Enter file length: 3
file2   20      3       20 21 22
*/
