#include <stdio.h>
int main() {
    int n, ts, i, t = 0, remaining;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int bt[n], temp[n], wt[n], tat[n];
    float avgWT = 0, avgTAT = 0;
    printf("Enter time quantum: ");
    scanf("%d", &ts);
    for(i = 0; i < n; i++) {
        printf("Enter burst time of P%d: ", i + 1);
        scanf("%d", &bt[i]);
        temp[i] = bt[i];
        wt[i] = 0;
    }
    int gp[100], gt[100], g = 0;
    remaining = n;
    while(remaining) {
        for(i = 0; i < n; i++) {
            if(temp[i] > 0) {
                gp[g] = i + 1;
                gt[g++] = t;
                if(temp[i] > ts) {
                    t += ts;
                    temp[i] -= ts;
                } else {
                    t += temp[i];
                    wt[i] = t - bt[i];
                    temp[i] = 0;
                    tat[i] = t;
                    remaining--;
                }
            }
        }
    }
    gt[g] = t;
    printf("\nProcess\tBT\tWT\tTAT\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t\t%d\t%d\t%d\n", i + 1, bt[i], wt[i], tat[i]);
        avgWT += wt[i];
        avgTAT += tat[i];
    }
    printf("\nAverage WT = %.2f", avgWT / n);
    printf("\nAverage TAT = %.2f\n", avgTAT / n);
    printf("\nGantt Chart:\n|");
    for(i = 0; i < g; i++) printf("\tP%d\t|", gp[i]);
    printf("\n");
    for(i = 0; i <= g; i++) printf("%d\t\t", gt[i]);
    return 0;
}
