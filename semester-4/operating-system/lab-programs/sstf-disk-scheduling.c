/*
Algorithm: SSTF Disk Scheduling

1. Start.
2. Read the number of disk requests.
3. Read the request queue.
4. Read the initial head position.
5. Mark all requests as unvisited.
6. Find the request closest to the current head position.
7. Move the disk head to that request.
8. Calculate seek time:
      Seek Time = |Current Position - Requested Track|
9. Mark the request as visited.
10. Repeat until all requests are serviced.
11. Display the seek sequence.
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
    int visited[n];

    printf("Enter request queue:\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &req[i]);
        visited[i] = 0;
    }

    printf("Enter initial head position: ");
    scanf("%d", &head);

    int totalSeek = 0;
    int current = head;

    printf("\nSeek Sequence: %d", current);

    for(int count = 0; count < n; count++)
    {
        int minDist = 999999;
        int index = -1;

        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
            {
                int dist = abs(current - req[i]);

                if(dist < minDist)
                {
                    minDist = dist;
                    index = i;
                }
            }
        }

        visited[index] = 1;
        totalSeek += abs(current - req[index]);
        current = req[index];

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

Seek Sequence: 53 -> 65 -> 67 -> 37 -> 14 -> 98 -> 122 -> 124 -> 183

Total Seek Time = 236
*/
