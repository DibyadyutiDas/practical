#include <stdio.h>

int main() {
    int n, bt[10], wt[10], tat[10], rt[10], time = 0, smallest, remaining, i;
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter burst times:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    remaining = n;
    while (remaining > 0) {
        smallest = -1;
        for (i = 0; i < n; i++) {
            if (rt[i] > 0 && (smallest == -1 || rt[i] < rt[smallest])) {
                smallest = i;
            }
        }

        time++;
        rt[smallest]--;

        if (rt[smallest] == 0) {
            remaining--;
            tat[smallest] = time;
            wt[smallest] = tat[smallest] - bt[smallest];
            avg_wt += wt[smallest];
            avg_tat += tat[smallest];
        }
    }

    printf("Process\tBT\tWT\tTAT\n");
    for (i = 0; i < n; i++) printf("%d\t%d\t%d\t%d\n", i + 1, bt[i], wt[i], tat[i]);

    printf("Average Waiting Time: %.2f\n", avg_wt / n);
    printf("Average Turnaround Time: %.2f\n", avg_tat / n);
    return 0;
}