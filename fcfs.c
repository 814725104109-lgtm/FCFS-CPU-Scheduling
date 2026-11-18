
#include <stdio.h>

int main()
{
    int n, i, j, t;
    int p[10], at[10], bt[10];
    int ct[10], wt[10], tat[10];
    int time = 0;
    float awt = 0, atat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i=0; i<n; i++)
    {
        printf("Enter PID, AT, BT: ");
        scanf("%d%d%d", &p[i], &at[i], &bt[i]);
    }

    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(at[i] > at[j])
            {
                t=at[i]; at[i]=at[j]; at[j]=t;
                t=bt[i]; bt[i]=bt[j]; bt[j]=t;
                t=p[i]; p[i]=p[j]; p[j]=t;
            }
        }
    }

    printf("\nGantt Chart:\n");

    for(i=0; i<n; i++)
    {
        if(time < at[i])
            time = at[i];

        printf("| P%d ", p[i]);

        time += bt[i];
        ct[i] = time;
        tat[i] = ct[i] - at[i];
        wt[i] = tat[i] - bt[i];

        awt += wt[i];
        atat += tat[i];
    }

    printf("|\n");

    printf("\nPID\tAT\tBT\tCT\tWT\tTAT\n");

    for(i=0; i<n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
        p[i],at[i],bt[i],ct[i],wt[i],tat[i]);
    }

    printf("\nAverage WT = %.2f", awt/n);
    printf("\nAverage TAT = %.2f", atat/n);

    return 0;
}
