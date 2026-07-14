/*
Algorithm: Two Level Directory

1. Start.
2. Read the number of users.
3. For each user:
      a) Read user name.
      b) Read the number of files.
      c) Read file names.
4. Create a separate directory for each user.
5. Store files under their respective user directory.
6. Display all users and their files.
7. Stop.
*/

#include <stdio.h>

int main()
{
    int users;

    printf("Enter number of users: ");
    scanf("%d", &users);

    for(int i = 0; i < users; i++)
    {
        char user[20];
        int files;

        printf("\nEnter user name: ");
        scanf("%s", user);

        printf("Enter number of files: ");
        scanf("%d", &files);

        char fname[files][20];

        printf("Enter file names:\n");

        for(int j = 0; j < files; j++)
        {
            scanf("%s", fname[j]);
        }

        printf("\nUser: %s\n", user);
        printf("Files:\n");

        for(int j = 0; j < files; j++)
        {
            printf("%s\n", fname[j]);
        }
    }

    return 0;
}

/*
OUTPUT
Enter number of users: 2

Enter user name: User1
Enter number of files: 3
Enter file names:
file1
file2
file3

User: User1
Files:
file1
file2
file3

Enter user name: User2
Enter number of files: 2
Enter file names:
file4
file5

User: User2
Files:
file4
file5
*/
