#include <stdio.h>

int main()
{
  int at[10], bt[10], pr[10];
  int n, i, j, temp, time = 0;
  int count, over = 0;
  int sum_wait = 0, sum_turnaround = 0, start;
  float avgwait, avgturn;

  printf("Enter the number of processes\n");
  scanf("%d", &n);

  /* Input arrival time and burst time */
  for (i = 0; i < n; i++)
  {
    printf("Enter the AT and BT for P%d :", i + 1);
    scanf("%d%d", &at[i], &bt[i]);

    pr[i] = i + 1;
  }

  /* Sort processes according to arrival time */
  for (i = 0; i < n - 1; i++)
  {
    for (j = i + 1; j < n; j++)
    {
      if (at[i] > at[j])
      {
        temp = at[i];
        at[i] = at[j];
        at[j] = temp;

        temp = bt[i];
        bt[i] = bt[j];
        bt[j] = temp;

        temp = pr[i];
        pr[i] = pr[j];
        pr[j] = temp;
      }
    }
  }

  printf("\n\nProcess\t| Arrival time\t| Burst time\t| Start time\t| Finish time\t| Waiting time\t| Turnaround time\n\n");

  /* SJF Scheduling */
  while (over < n)
  {
    count = 0;

    /* Find processes that have arrived */
    for (i = over; i < n; i++)
    {
      if (at[i] <= time)
        count++;
      else
        break;
    }

    /* Sort available processes according to burst time */
    if (count > 1)
    {
      for (i = over; i < over + count - 1; i++)
      {
        for (j = i + 1; j < over + count; j++)
        {
          if (bt[i] > bt[j])
          {
            temp = at[i];
            at[i] = at[j];
            at[j] = temp;

            temp = bt[i];
            bt[i] = bt[j];
            bt[j] = temp;

            temp = pr[i];
            pr[i] = pr[j];
            pr[j] = temp;
          }
        }
      }
    }

    start = time;
    time += bt[over];

    printf(
        "P[%d]\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\t|\t%d\n",pr[over],at[over],bt[over],start,time,time - at[over] - bt[over],time - at[over]);

    sum_wait += time - at[over] - bt[over];
    sum_turnaround += time - at[over];

    over++;
  }

  /* Calculate averages */
  avgwait = (float)sum_wait / n;
  avgturn = (float)sum_turnaround / n;

  printf("\nAverage waiting time is %f\n", avgwait);
  printf("Average turnaround time is %f\n", avgturn);

  return 0;
}