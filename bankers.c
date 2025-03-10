#include<stdio.h>
int main(){
    int avail[10], alloc[10][10], max[10][10], need[10][10], maxres[10], m, n, i, j, k, sum;
    printf("\nEnter the number of processes and number of resources:\n");
    scanf("%d %d", &n, &m);

    printf("\nEnter the max instances of resources:\n");
    for (j = 0; j < m; j++) {
        scanf("%d", &maxres[j]);
        avail[j] = maxres[j];
    }

    printf("\nEnter the allocated resources:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("\nEnter the maximum required resources:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    printf("\nNeed matrix:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    for (j = 0; j < m; j++) {
        sum = 0;
        for (i = 0; i < n; i++) {
            sum += alloc[i][j];
        }
        avail[j] = maxres[j] - sum;
    }

    int finish[10] = {0}, safeseq[10], ind = 0;
    int y = 0;
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            if (finish[i] == 0) {
                int flag = 0;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]) {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) {
                    safeseq[ind++] = i;
                    for (y = 0; y < m; y++) {
                        avail[y] += alloc[i][y];
                    }
                    finish[i] = 1;
                }
            }
        }
    }

    int unsafe = 0;
    for (i = 0; i < n; i++) {
        if (finish[i] == 0) {
            unsafe = 1;
            break;
        }
    }

    if (unsafe) {
        printf("System unsafe\n");
    } else {
        printf("SAFE SEQUENCE: ");
        for (i = 0; i < n; i++) {
            printf("P%d ", safeseq[i]);
        }
        printf("\n");
    }

    return 0;
}

