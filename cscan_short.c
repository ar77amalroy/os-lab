#include <stdio.h>
int main() {
    int head, n, size, seek = 0, pos = 0;
    printf("Enter head position: ");
    scanf("%d", &head);
    printf("Enter number of disk requests: ");
    scanf("%d", &n);
    int a[n + 1];
    printf("Enter disk size: ");
    scanf("%d", &size);
    printf("Enter disk requests: ");
    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    a[n++] = head;
    for(int i = 0; i < n - 1; i++)
        for(int j = 0; j < n - i - 1; j++)
            if(a[j] > a[j + 1]) {
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
    for(int i = 0; i < n; i++)
        if(a[i] == head) { pos = i; break; }
    printf("\nC-SCAN Disk Scheduling:\n");
    for(int i = pos; i < n - 1; i++) {
        int d = a[i + 1] - a[i];
        seek += d;
        printf("Head moves from %d to %d  Distance: %d\n", a[i], a[i + 1], d);
    }
    if(a[n - 1] != size - 1) {
        int d = (size - 1) - a[n - 1];
        seek += d;
        printf("Head moves from %d to %d  Distance: %d\n", a[n - 1], size - 1, d);
    }
    int d = size - 1;
    seek += d;
    printf("Head moves from %d to 0  Distance: %d\n", size - 1, d);
    for(int i = 0; i < pos; i++) {
        if(i == 0) {
            d = a[i]; 
            printf("Head moves from 0 to %d  Distance: %d\n", a[i], d);
        } else {
            d = a[i] - a[i - 1];
            printf("Head moves from %d to %d  Distance: %d\n", a[i - 1], a[i], d);
        }
        seek += d;
    }
    printf("\nTotal Seek Time = %d\n", seek);
    return 0;
}
