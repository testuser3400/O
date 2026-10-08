#include <stdio.h>

int main()
{
    int i, n, k, no, avail;
    int pages[50], frames[5], counter[5];
    int count = 0;
    int time = 0;
    int pos, min;

    printf("\nHow many pages :\n");
    scanf("%d", &n);

    printf("\nEnter Reference String :\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &pages[i]);
    }

    printf("\nHow many frames :\n");
    scanf("%d", &no);

    for (i = 0; i < no; i++)
    {
        frames[i] = -1;
        counter[i] = 0;
    }

    printf("\nRef_String\tFrames\n");

    for (i = 0; i < n; i++)
    {
        avail = 0;
        time++;

        /* Check if page is already present */
        for (k = 0; k < no; k++)
        {
            if (frames[k] == pages[i])
            {
                avail = 1;
                counter[k] = time;
                break;
            }
        }

        /* Page fault */
        if (avail == 0)
        {
            count++;
            pos = -1;

            /* Find empty frame */
            for (k = 0; k < no; k++)
            {
                if (frames[k] == -1)
                {
                    pos = k;
                    break;
                }
            }

            /* If no empty frame, find LRU page */
            if (pos == -1)
            {
                min = counter[0];
                pos = 0;

                for (k = 1; k < no; k++)
                {
                    if (counter[k] < min)
                    {
                        min = counter[k];
                        pos = k;
                    }
                }
            }

            frames[pos] = pages[i];
            counter[pos] = time;
        }

        /* Display reference string and frames */
        printf("%d\t\t", pages[i]);

        for (k = 0; k < no; k++)
        {
            if (frames[k] == -1)
                printf("- ");
            else
                printf("%d ", frames[k]);
        }

        printf("\n");
    }

    printf("\nPage Fault : %d\n", count);

    return 0;
}