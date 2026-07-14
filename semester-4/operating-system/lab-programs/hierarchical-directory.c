/*
Algorithm: Hierarchical Directory

1. Start.
2. Read the number of directories.
3. For each directory:
      a) Read directory name.
      b) Read the number of files.
      c) Read file names.
4. Create a hierarchical structure where each directory
   contains its own files.
5. Display the directory tree.
6. Stop.
*/

#include <stdio.h>

int main()
{
    int dirs;

    printf("Enter number of directories: ");
    scanf("%d", &dirs);

    for(int i = 0; i < dirs; i++)
    {
        char dirname[20];
        int files;

        printf("\nEnter directory name: ");
        scanf("%s", dirname);

        printf("Enter number of files: ");
        scanf("%d", &files);

        char fname[files][20];

        printf("Enter file names:\n");

        for(int j = 0; j < files; j++)
        {
            scanf("%s", fname[j]);
        }

        printf("\n%s\n", dirname);

        for(int j = 0; j < files; j++)
        {
            printf(" └── %s\n", fname[j]);
        }
    }

    return 0;
}

/*
OUTPUT

Enter number of directories: 2

Enter directory name: Documents
Enter number of files: 3
Enter file names:
resume
report
notes

Documents
 └── resume
 └── report
 └── notes

Enter directory name: Pictures
Enter number of files: 2
Enter file names:
photo1
photo2

Pictures
 └── photo1
 └── photo2
*/
