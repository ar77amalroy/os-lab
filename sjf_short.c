#include <stdio.h>
int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int p[n], bt[n], wt[n], tat[n];
    float avgWT = 0, avgTAT = 0;
    for(int i = 0; i < n; i++) {
        p[i] = i + 1;
        printf("Enter burst time of P%d: ", i + 1);
        scanf("%d", &bt[i]);
    }
    for(int i = 0; i < n - 1; i++)
        for(int j = i + 1; j < n; j++)
            if(bt[i] > bt[j]) {
                int t = bt[i]; bt[i] = bt[j]; bt[j] = t;
                t = p[i]; p[i] = p[j]; p[j] = t;
            }
    wt[0] = 0;
    for(int i = 1; i < n; i++)
        wt[i] = wt[i - 1] + bt[i - 1];
    for(int i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
        avgWT += wt[i];
        avgTAT += tat[i];
    }
    printf("\nProcess\tBT\tWT\tTAT\n");
    for(int i = 0; i < n; i++)
        printf("P%d\t\t%d\t%d\t%d\n", p[i], bt[i], wt[i], tat[i]);
    printf("\nGantt Chart:\n|");
    for(int i = 0; i < n; i++) printf("P%d\t|", p[i]);
    printf("\n0");
    for(int i = 0; i < n; i++) printf("\t%d", tat[i]);
    printf("\n\nAverage WT = %.2f", avgWT / n);
    printf("\nAverage TAT = %.2f\n", avgTAT / n);
    return 0;
}
