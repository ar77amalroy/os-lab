#include <stdio.h>
int main() {
    int head, n, i, size, pos = 0, seek = 0;
    printf("Enter head position: ");
    scanf("%d", &head);
    printf("Enter number of disk requests: ");
    scanf("%d", &n);
    int a[n + 1];
    printf("Enter disk size: ");
    scanf("%d", &size);
    printf("Enter disk requests: ");
    for(i = 0; i < n; i++) scanf("%d", &a[i]);
    a[n++] = head;
    for(int x = 0; x < n - 1; x++)
        for(int y = 0; y < n - x - 1; y++)
            if(a[y] > a[y + 1]) {
                int t = a[y];
                a[y] = a[y + 1];
                a[y + 1] = t;
            }
    for(i = 0; i < n; i++)
        if(a[i] == head) { pos = i; break; }
    printf("\nSCAN Disk Scheduling:\n");
    for(i = pos; i < n - 1; i++) {
        int dist = a[i + 1] - a[i];
        seek += dist;
        printf("Head moves from %d to %d \tDistance: %d\n", a[i], a[i + 1], dist);
    }
    if(a[n - 1] != size - 1) {
        int dist = (size - 1) - a[n - 1];
        seek += dist;
        printf("Head moves from %d to %d \tDistance: %d\n", a[n - 1], size - 1, dist);
    }
    if(pos > 0) {
        int dist = (size - 1) - a[pos - 1];
        seek += dist;
        printf("Head moves from %d to %d \tDistance: %d\n", size - 1, a[pos - 1], dist);
        for(i = pos - 1; i > 0; i--) {
            dist = a[i] - a[i - 1];
            seek += dist;
            printf("Head moves from %d to %d \tDistance: %d\n", a[i], a[i - 1], dist);
        }
    }
    printf("\nTotal Seek Time = %d\n", seek);
    return 0;
}
