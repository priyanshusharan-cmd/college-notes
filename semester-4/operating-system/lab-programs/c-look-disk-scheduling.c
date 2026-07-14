/*
Algorithm: C-LOOK Disk Scheduling

1. Start.
2. Read the number of disk requests.
3. Read the request queue.
4. Read the initial head position.
5. Sort all requests in ascending order.
6. Service all requests greater than or equal to the head position.
7. After reaching the last request, jump to the smallest request.
8. Continue servicing the remaining requests.
9. Calculate total seek time.
10. Display seek sequence.
11. Display total seek time.
12. Stop.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, head;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    int req[n];

    printf("Enter request queue:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    for(int i = 0; i < n - 1; i++)
    {
        for(int j = 0; j < n - i - 1; j++)
        {
            if(req[j] > req[j + 1])
            {
                int temp = req[j];
                req[j] = req[j + 1];
                req[j + 1] = temp;
            }
        }
    }

    int pos = 0;

    while(pos < n && req[pos] < head)
        pos++;

    int totalSeek = 0;
    int current = head;

    printf("\nSeek Sequence: %d", current);

    for(int i = pos; i < n; i++)
    {
        totalSeek += abs(current - req[i]);
        current = req[i];
        printf(" -> %d", current);
    }

    if(pos > 0)
    {
        totalSeek += abs(current - req[0]);
        current = req[0];
        printf(" -> %d", current);

        for(int i = 1; i < pos; i++)
        {
            totalSeek += abs(current - req[i]);
            current = req[i];
            printf(" -> %d", current);
        }
    }

    printf("\nTotal Seek Time = %d\n", totalSeek);

    return 0;
}

/*
OUTPUT
Enter number of requests: 8

Enter request queue:
98 183 37 122 14 124 65 67

Enter initial head position: 53

Seek Sequence: 53 -> 65 -> 67 -> 98 -> 122 -> 124 -> 183 -> 14 -> 37

Total Seek Time = 322
*/
