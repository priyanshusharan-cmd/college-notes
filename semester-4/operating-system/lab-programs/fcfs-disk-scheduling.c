/*
Algorithm: FCFS Disk Scheduling

1. Start.
2. Read the number of disk requests.
3. Read the request queue.
4. Read the initial head position.
5. Move the disk head to each request in the order received.
6. Calculate seek time for each movement:
      Seek Time = |Current Position - Requested Track|
7. Add all seek times to get Total Seek Time.
8. Display the seek sequence.
9. Display Total Seek Time.
10. Stop.
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, head;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    int queue[n];

    printf("Enter request queue:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &queue[i]);

    printf("Enter initial head position: ");
    scanf("%d", &head);

    int totalSeek = 0;
    int current = head;

    printf("\nSeek Sequence: %d", current);

    for(int i = 0; i < n; i++)
    {
        totalSeek += abs(current - queue[i]);
        current = queue[i];

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

Seek Sequence: 53 -> 98 -> 183 -> 37 -> 122 -> 14 -> 124 -> 65 -> 67

Total Seek Time = 640
*/
