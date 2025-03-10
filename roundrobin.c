#include <stdio.h>
int main() {
    int n, i, ts, total = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int bt[n], wt[n], tat[n], temp[n], remaining = n,executed[n];
    float awt = 0, avgtat = 0;
    printf("Enter time quantum: ");
    scanf("%d", &ts);
    for (i = 0; i < n; i++) {
        printf("Enter burst time for process %d: ", i + 1);
        scanf("%d", &bt[i]);
        temp[i] = bt[i];
        wt[i] = 0;
        executed[i]=0;
    }
    int t = 0;
    int ganttProcess[1000],ganttTime[1000],ganttIndex=0;
    while (remaining > 0) {
        for (i = 0; i < n; i++) {
            if (temp[i] > 0) {
            ganttProcess[ganttIndex]=i+1;
            ganttTime[ganttIndex++]=t;
                if (temp[i] > ts) {
                    t += ts;
                    temp[i] -= ts;
                } else {
                    t += temp[i];
                    wt[i] = t - bt[i];
                    tat[i] = t;
                    temp[i] = 0;
                    remaining--;
                }
            }
        }
    }
    ganttTime[ganttIndex]=t;
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
        awt += wt[i];
        avgtat += tat[i];
    }
    printf("\nAverage Waiting Time: %.2f", awt / n);
    printf("\nAverage Turnaround Time: %.2f\n", avgtat / n);
    printf("\nGantt Chart:\n|");
    for (i = 0; i <ganttIndex ; i++) {
        printf(" P%d\t|", ganttProcess[i]);
    }
    printf("\n");
    for (i = 0; i <=ganttIndex; i++) {
        printf("%d\t", ganttTime[i]);
    }
    printf("\n");
    return 0;
}

