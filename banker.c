#include <stdio.h>

int main()
{
    int allocation[5][3] = {
        {2, 3, 2},
        {4, 0, 0},
        {5, 0, 4},
        {4, 3, 3},
        {2, 2, 4}
    };

    int max[5][3] = {
        {9, 7, 5},
        {5, 2, 2},
        {1, 0, 4},
        {4, 4, 4},
        {6, 5, 5}
    };

    int need[5][3];
    int available[3];

    int i, j, ch;

    /* Calculate Need Matrix */
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 3; j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    while (1)
    {
        printf("\n\n----- MENU -----");
        printf("\n1. Accept Available");
        printf("\n2. Display Allocation and Max");
        printf("\n3. Display Need Matrix");
        printf("\n4. Display Available");
        printf("\n5. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch)
        {
            case 1:
                printf("\nEnter Available resources (A B C): ");
                scanf("%d %d %d",
                      &available[0],
                      &available[1],
                      &available[2]);

                printf("\nAvailable resources accepted.");
                break;

            case 2:
                printf("\nProcess\tAllocation\tMax\n");

                printf("\tA B C\t\tA B C\n");

                for (i = 0; i < 5; i++)
                {
                    printf("P%d\t", i);

                    for (j = 0; j < 3; j++)
                    {
                        printf("%d ", allocation[i][j]);
                    }

                    printf("\t\t");

                    for (j = 0; j < 3; j++)
                    {
                        printf("%d ", max[i][j]);
                    }

                    printf("\n");
                }
                break;

            case 3:
                printf("\nNeed Matrix:\n");
                printf("Process\tA B C\n");

                for (i = 0; i < 5; i++)
                {
                    printf("P%d\t", i);

                    for (j = 0; j < 3; j++)
                    {
                        printf("%d ", need[i][j]);
                    }

                    printf("\n");
                }
                break;

            case 4:
                printf("\nAvailable Resources:\n");
                printf("A\tB\tC\n");
                printf("%d\t%d\t%d\n",
                       available[0],
                       available[1],
                       available[2]);
                break;

            case 5:
                printf("\nProgram terminated.\n");
                return 0;

            default:
                printf("\nInvalid choice!");
        }
    }

    return 0;
}