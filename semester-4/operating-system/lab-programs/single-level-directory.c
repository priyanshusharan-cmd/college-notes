/*
Algorithm: Single Level Directory

1. Start.
2. Read the number of files.
3. Read the file names.
4. Store all files in a single directory.
5. Display the list of files.
6. Stop.
*/

#include <stdio.h>

int main()
{
    int n;

    printf("Enter number of files: ");
    scanf("%d", &n);

    char files[n][20];

    printf("Enter file names:\n");

    for(int i = 0; i < n; i++)
    {
        scanf("%s", files[i]);
    }

    printf("\nFiles in Single Level Directory:\n");

    for(int i = 0; i < n; i++)
    {
        printf("%s\n", files[i]);
    }

    return 0;
}

/*
OUTPUT
Enter number of files: 5

Enter file names:
file1
file2
file3
file4
file5

Files in Single Level Directory:
file1
file2
file3
file4
file5
*/
