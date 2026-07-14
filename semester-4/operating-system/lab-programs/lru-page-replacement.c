/*
Algorithm: Least Recently Used (LRU) Page Replacement

1. Start.
2. Read the number of pages.
3. Read the page reference string.
4. Read the number of frames.
5. Initialize all frames as empty.
6. For each page reference:
      a) Check if the page is present in memory.
      b) If present, update its recent usage time.
      c) If not present, it is a Page Fault.
      d) If a free frame exists, place the page there.
      e) Otherwise, replace the least recently used page.
7. Display frame contents after each reference.
8. Count total Page Faults.
9. Display total Page Faults.
10. Stop.
*/

#include <stdio.h>

int main()
{
    int n, frames;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    int pages[n];

    printf("Enter page reference string:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    int frame[frames];
    int recent[frames];

    for(int i = 0; i < frames; i++)
    {
        frame[i] = -1;
        recent[i] = 0;
    }

    int faults = 0;

    for(int i = 0; i < n; i++)
    {
        int found = 0;

        for(int j = 0; j < frames; j++)
        {
            if(frame[j] == pages[i])
            {
                found = 1;
                recent[j] = i + 1;
                break;
            }
        }

        if(!found)
        {
            int pos = -1;

            for(int j = 0; j < frames; j++)
            {
                if(frame[j] == -1)
                {
                    pos = j;
                    break;
                }
            }

            if(pos == -1)
            {
                pos = 0;

                for(int j = 1; j < frames; j++)
                {
                    if(recent[j] < recent[pos])
                        pos = j;
                }
            }

            frame[pos] = pages[i];
            recent[pos] = i + 1;
            faults++;
        }

        printf("\nPage %d -> ", pages[i]);

        for(int j = 0; j < frames; j++)
        {
            if(frame[j] != -1)
                printf("%d ", frame[j]);
            else
                printf("- ");
        }
    }

    printf("\n\nTotal Page Faults = %d\n", faults);

    return 0;
}

/*
OUTPUT
Enter number of pages: 12

Enter page reference string:
1 2 3 4 1 2 5 1 2 3 4 5

Enter number of frames: 3

Page 1 -> 1 - -
Page 2 -> 1 2 -
Page 3 -> 1 2 3
Page 4 -> 4 2 3
Page 1 -> 4 1 3
Page 2 -> 4 1 2
Page 5 -> 5 1 2
Page 1 -> 5 1 2
Page 2 -> 5 1 2
Page 3 -> 3 1 2
Page 4 -> 3 4 2
Page 5 -> 3 4 5

Total Page Faults = 10
*/
