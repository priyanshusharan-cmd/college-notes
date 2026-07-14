/*
Algorithm: SCAN Disk Scheduling

1. Start.
2. Read the number of disk requests.
3. Read the request queue.
4. Read the initial head position.
5. Sort the request queue in ascending order.
6. Read the initial direction (left or right).
7. Move the disk head in the chosen direction,
   servicing all requests along the way.
8. When the end is reached, reverse the direction.
9. Continue servicing the remaining requests.
10. Calculate total seek time.
11. Display seek sequence.
12. Display total seek time.
13. Stop.
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

    int totalSeek = 0;
    int pos = 0;

    while(pos < n && req[pos] < head)
        pos++;

    int current = head;

    printf("\nSeek Sequence: %d", current);

    for(int i = pos; i < n; i++)
    {
        totalSeek += abs(current - req[i]);
        current = req[i];
        printf(" -> %d", current);
    }

    totalSeek += abs(current - 199);
    current = 199;
    printf(" -> %d", current);

    for(int i = pos - 1; i >= 0; i--)
    {
        totalSeek += abs(current - req[i]);
        current = req[i];
        printf(" -> %d", current);
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

Seek Sequence:
53 -> 65 -> 67 -> 98 -> 122 -> 124 -> 183 -> 199 -> 37 -> 14

Total Seek Time = 331
*/
