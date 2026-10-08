#include <stdio.h>
#include <stdlib.h>

int main()
{
    int request[50], n;
    int blocks, head;
    int i, j, temp;
    int total = 0;

    printf("Enter total number of disk blocks: ");
    scanf("%d", &blocks);

    printf("Enter number of disk requests: ");
    scanf("%d", &n);

    printf("Enter disk request string:\n");

    for (i = 0; i < n; i++)
        scanf("%d", &request[i]);

    printf("Enter current head position: ");
    scanf("%d", &head);

    /* Sort requests */
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (request[i] > request[j])
            {
                temp = request[i];
                request[i] = request[j];
                request[j] = temp;
            }
        }
    }

    printf("\nOrder of requests served:\n");
    printf("%d", head);

    /* LEFT direction */
    for (i = n - 1; i >= 0; i--)
    {
        if (request[i] < head)
        {
            total = total + abs(head - request[i]);
            head = request[i];

            printf(" -> %d", head);
        }
    }

    /* RIGHT direction */
    for (i = 0; i < n; i++)
    {
        if (request[i] > head)
        {
            total = total + abs(head - request[i]);
            head = request[i];

            printf(" -> %d", head);
        }
    }

    printf("\n\nTotal head movement = %d\n", total);

    return 0;
}