#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i;
    int request[50];
    int head;
    int total = 0;

    printf("Enter total number of disk blocks: ");
    scanf("%d", &n);

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

    for (i = 0; i < n; i++)
    {
        total = total + abs(head - request[i]);
        head = request[i];

        printf(" -> %d", request[i]);
    }

    printf("\n\nTotal head movement = %d\n", total);

    return 0;
}