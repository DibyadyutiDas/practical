#include <stdio.h>

int main() {
    int n, i, time = 0, remain, shortest, finish_time;
    printf("Enter number of processes: ");
    scanf("%d", &n);

    int bt[n], priority[n], rt[n];
    for (i = 0; i < n; i++) {
        printf("P[%d] Burst Time and Priority: ", i+1);
        scanf("%d%d", &bt[i], &priority[i]);
        rt[i] = bt[i];
    }

    remain = n;
    int min_priority = 9999;

    printf("\nProcess\tCompletion Time\tWaiting Time\n");
    while (remain != 0) {
        int highest_priority = 9999;
        int pos = -1;

        for (i = 0; i < n; i++) {
            if (rt[i] > 0 && priority[i] < highest_priority) {
                highest_priority = priority[i];
                pos = i;
            }
        }

        if (pos == -1) {
            time++;
            continue;
        }

        rt[pos]--;
        time++;

        if (rt[pos] == 0) {
            remain--;
            finish_time = time;
            printf("P[%d]\t%d\t\t%d\n", pos+1, finish_time, finish_time - bt[pos]);
        }
    }

    return 0;
}
