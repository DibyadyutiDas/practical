#include <stdio.h>

int main() {
    int n, bt[10], wt[10], tat[10];
    float avg_wt = 0, avg_tat = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter burst times:\n");
    for (int i = 0; i < n; i++) scanf("%d", &bt[i]);

    wt[0] = 0;
    for (int i = 1; i < n; i++) wt[i] = wt[i - 1] + bt[i - 1];

    for (int i = 0; i < n; i++) {
        tat[i] = wt[i] + bt[i];
        avg_wt += wt[i];
        avg_tat += tat[i];
    }

    printf("Process\tBT\tWT\tTAT\n");
    for (int i = 0; i < n; i++) printf("%d\t%d\t%d\t%d\n", i + 1, bt[i], wt[i], tat[i]);

    printf("Average Waiting Time: %.2f\n", avg_wt / n);
    printf("Average Turnaround Time: %.2f\n", avg_tat / n);
    return 0;
}