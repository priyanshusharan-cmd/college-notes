/*
Algorithm: Optimal Page Replacement

1. Start.
2. Read the number of pages.
3. Read the page reference string.
4. Read the number of frames.
5. Initialize all frames as empty.
6. For each page reference:
      a) Check if the page is already present.
      b) If present, it is a Page Hit.
      c) Otherwise, it is a Page Fault.
      d) If a free frame exists, place the page.
      e) Else replace the page that will not be used
         for the longest period in the future.
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

    for(int i = 0; i < frames; i++)
        frame[i] = -1;

    int faults = 0;

    for(int i = 0; i < n; i++)
    {
        int found = 0;

        for(int j = 0; j < frames; j++)
        {
            if(frame[j] == pages[i])
            {
                found = 1;
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
                int farthest = -1;

                for(int j = 0; j < frames; j++)
                {
                    int k;

                    for(k = i + 1; k < n; k++)
                    {
                        if(frame[j] == pages[k])
                            break;
                    }

                    if(k == n)
                    {
                        pos = j;
                        break;
                    }

                    if(k > farthest)
                    {
                        farthest = k;
                        pos = j;
                    }
                }
            }

            frame[pos] = pages[i];
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
Page 4 -> 1 2 4
Page 1 -> 1 2 4
Page 2 -> 1 2 4
Page 5 -> 1 2 5
Page 1 -> 1 2 5
Page 2 -> 1 2 5
Page 3 -> 3 2 5
Page 4 -> 4 2 5
Page 5 -> 4 2 5

Total Page Faults = 7
*/
