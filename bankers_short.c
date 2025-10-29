#include <stdio.h>
int main() {
    int n, m, i, j, k;
    int alloc[10][10], max[10][10], need[10][10], maxres[10], avail[10];
    printf("Enter number of processes and number of resources: ");
    scanf("%d %d", &n, &m);
    printf("Enter the max instances of each resource:\n");
    for (j = 0; j < m; j++) {
        scanf("%d", &maxres[j]);
        avail[j] = maxres[j];
    }
    printf("Enter the Allocation matrix (n x m):\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);
    printf("Enter the Max matrix (n x m):\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
            need[i][j] = max[i][j] - alloc[i][j];
        }
    printf("\nNeed matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++)
            printf("%d ", need[i][j]);
        printf("\n");
    }
    for (j = 0; j < m; j++) {
        int sum = 0;
        for (i = 0; i < n; i++) sum += alloc[i][j];
        avail[j] = maxres[j] - sum;
    }
    int finish[10] = {0}, safeseq[10], ind = 0;
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            if (!finish[i]) {
                int can = 1;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]) { can = 0; break; }
                }
                if (can) {                       
                    safeseq[ind++] = i;
                    for (j = 0; j < m; j++) avail[j] += alloc[i][j];
                    finish[i] = 1;
                }
            }
        }
    }
    for (i = 0; i < n; i++) {
        if (!finish[i]) {
            printf("\nSystem is in UNSAFE state\n");
            return 0;
        }
    }
    printf("\nSAFE SEQUENCE: ");
    for (i = 0; i < n; i++) printf("P%d ", safeseq[i]);
    printf("\n");
    return 0;
}
