/*
Algorithm: Page Replacement Algorithms

Step 1 : Start

Step 2 : Read number of pages (n)

Step 3 : Read page reference string

Step 4 : Read number of frames

Step 5 : Read choice

            1. FIFO
            2. LRU
            3. Optimal

Step 6 : Initialize all frames as empty

Step 7 : For each page

            Check whether page
            is already present

            If present

                Page Hit

            Else

                Page Fault

                Replace page
                according to
                selected algorithm

Step 8 : Display frame contents

Step 9 : Display total page faults

Step 10 : Stop
*/

#include <stdio.h>

void FIFO(int pages[], int n, int frames)
{
    int frame[20];
    int i, j;

    for(i = 0; i < frames; i++)
        frame[i] = -1;

    int index = 0;
    int faults = 0;

    for(i = 0; i < n; i++)
    {
        int found = 0;

        for(j = 0; j < frames; j++)
        {
            if(frame[j] == pages[i])
            {
                found = 1;
                break;
            }
        }

        if(!found)
        {
            frame[index] = pages[i];

            index = (index + 1) % frames;

            faults++;
        }

        printf("\n%d -> ", pages[i]);

        for(j = 0; j < frames; j++)
            printf("%d ", frame[j]);
    }

    printf("\n\nPage Faults = %d\n",
           faults);
}

void LRU(int pages[], int n, int frames)
{
    int frame[20];
    int recent[20];

    int i, j;

    for(i = 0; i < frames; i++)
    {
        frame[i] = -1;
        recent[i] = 0;
    }

    int faults = 0;

    for(i = 0; i < n; i++)
    {
        int found = 0;

        for(j = 0; j < frames; j++)
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

            for(j = 0; j < frames; j++)
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

                for(j = 1; j < frames; j++)
                {
                    if(recent[j] <
                       recent[pos])
                        pos = j;
                }
            }

            frame[pos] = pages[i];

            recent[pos] = i + 1;

            faults++;
        }

        printf("\n%d -> ", pages[i]);

        for(j = 0; j < frames; j++)
            printf("%d ", frame[j]);
    }

    printf("\n\nPage Faults = %d\n",
           faults);
}

void OPTIMAL(int pages[],
             int n,
             int frames)
{
    int frame[20];

    int i, j;

    for(i = 0; i < frames; i++)
        frame[i] = -1;

    int faults = 0;

    for(i = 0; i < n; i++)
    {
        int found = 0;

        for(j = 0; j < frames; j++)
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

            for(j = 0; j < frames; j++)
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

                for(j = 0; j < frames; j++)
                {
                    int k;

                    for(k = i + 1;
                        k < n;
                        k++)
                    {
                        if(frame[j]
                           == pages[k])
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

        printf("\n%d -> ", pages[i]);

        for(j = 0; j < frames; j++)
            printf("%d ", frame[j]);
    }

    printf("\n\nPage Faults = %d\n",
           faults);
}

int main()
{
    int n, frames, choice;
    int pages[50];
    int i;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string:\n");

    for(i = 0; i < n; i++)
        scanf("%d", &pages[i]);

    printf("Enter number of frames: ");
    scanf("%d", &frames);

    printf("\n1. FIFO");
    printf("\n2. LRU");
    printf("\n3. Optimal");

    printf("\nEnter choice: ");
    scanf("%d", &choice);

    if(choice == 1)
        FIFO(pages, n, frames);

    else if(choice == 2)
        LRU(pages, n, frames);

    else if(choice == 3)
        OPTIMAL(pages, n, frames);

    else
        printf("Invalid Choice");

    return 0;
}
