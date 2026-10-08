#include <stdio.h>

int main()
{
    int allocation[5][4] = {
        {0, 0, 1, 2},
        {1, 0, 0, 0},
        {1, 3, 5, 4},
        {0, 6, 3, 2},
        {0, 0, 1, 4}};

    int max[5][4] = {
        {0, 0, 1, 2},
        {1, 7, 5, 0},
        {2, 3, 5, 6},
        {0, 6, 5, 2},
        {0, 6, 5, 6}};

    int available[4] = {1, 5, 2, 0};

    int need[5][4];
    int finish[5] = {0};
    int safe[5];

    int i, j, k;
    int count = 0;
    int found;

    /* Calculate Need Matrix */
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 4; j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    /* Display Need Matrix */
    printf("\nNeed Matrix:\n");
    printf("Process\tA\tB\tC\tD\n");

    for (i = 0; i < 5; i++)
    {
        printf("P%d\t", i);

        for (j = 0; j < 4; j++)
        {
            printf("%d\t", need[i][j]);
        }

        printf("\n");
    }

    /* Banker's Safety Algorithm */

    while (count < 5)
    {
        found = 0;

        for (i = 0; i < 5; i++)
        {
            if (finish[i] == 0)
            {
                /* Check if Need <= Available */
                for (j = 0; j < 4; j++)
                {
                    if (need[i][j] > available[j])
                        break;
                }

                /* Process can execute */
                if (j == 4)
                {
                    for (k = 0; k < 4; k++)
                    {
                        available[k] =
                            available[k] + allocation[i][k];
                    }

                    safe[count] = i;
                    count++;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if (found == 0)
            break;
    }

    /* Check Safe State */
    if (count == 5)
    {
        printf("\nSystem is in SAFE STATE.\n");

        printf("Safe Sequence: ");

        for (i = 0; i < 5; i++)
        {
            printf("P%d", safe[i]);

            if (i != 4)
                printf(" -> ");
        }

        printf("\n");
    }
    else
    {
        printf("\nSystem is NOT in SAFE STATE.\n");
    }

    return 0;
}