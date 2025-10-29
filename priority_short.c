#include <stdio.h>
int main() {
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    int bt[n], wt[n], tat[n], pr[n], pid[n];
    float avgw = 0, avgt = 0;
    for(int i = 0; i < n; i++) {
        printf("Enter BT and Priority of P%d: ", i + 1);
        scanf("%d %d", &bt[i], &pr[i]);
        pid[i] = i + 1;
    }
    for(int i = 0; i < n - 1; i++)
        for(int j = i + 1; j < n; j++)
            if(pr[i] > pr[j]) {
                int t = pr[i]; pr[i] = pr[j]; pr[j] = t;
                t = bt[i]; bt[i] = bt[j]; bt[j] = t;
                t = pid[i]; pid[i] = pid[j]; pid[j] = t;
            }
    wt[0] = 0;
    for(int i = 1; i < n; i++)
        wt[i] = wt[i - 1] + bt[i - 1];
    for(int i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
        avgw += wt[i];
        avgt += tat[i];
    }
    printf("\nPID\tBT\tPR\tWT\tTAT\n");
    for(int i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\n", pid[i], bt[i], pr[i], wt[i], tat[i]);
    printf("\nGantt Chart:\n|");
    for(int i = 0; i < n; i++)
        printf("P%d\t|", pid[i]);
    printf("\n0");
    for(int i = 0; i < n; i++)
        printf("\t%d", tat[i]);
    printf("\n\nAverage WT = %.2f", avgw / n);
    printf("\nAverage TAT = %.2f\n", avgt / n);
    return 0;
}
