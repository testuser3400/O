#include <stdio.h>
#include <stdlib.h>

int main()
{
    int blocks, n, i;
    int request[50], visited[50] = {0};
    int head, total = 0;
    int min, pos, distance;

    printf("Enter total number of disk blocks: ");
    scanf("%d", &blocks);

    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    printf("Enter disk request string:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &request[i]);
    }

    printf("Enter current head position: ");
    scanf("%d", &head);

    printf("\nOrder of requests served:\n");
    printf("%d", head);

    /* SSTF Algorithm */
    for (i = 0; i < n; i++)
    {
        min = 9999;
        pos = -1;

        /* Find nearest request */
        for (int j = 0; j < n; j++)
        {
            if (visited[j] == 0)
            {
                distance = abs(head - request[j]);

                if (distance < min)
                {
                    min = distance;
                    pos = j;
                }
            }
        }

        /* Serve the nearest request */
        visited[pos] = 1;
        total = total + min;
        head = request[pos];

        printf(" -> %d", head);
    }

    printf("\n\nTotal head movement = %d\n", total);

    return 0;
}