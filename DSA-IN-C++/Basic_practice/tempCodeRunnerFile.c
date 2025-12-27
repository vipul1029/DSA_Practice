// 3) Round Robin (RR)
// rr.c
#include <stdio.h>
#include <stdlib.h>
int main(){
    int n, qt;
    printf("Enter number of processes: "); scanf("%d",&n);
    int pid[n], bt[n], at[n], rem[n];
    for (int i=0;i<n;i++){ pid[i]=i+1; 
        printf("AT BT for P%d: ", pid[i]); scanf("%d %d",&at[i], &bt[i]); rem[i]=bt[i]; }
    printf("Enter time quantum: "); scanf("%d", &qt);
    int time=0, done=0;
    int ct[n], tat[n], wt[n];
    // simple ready queue by round-robin scanning; consider arrival times
    while (done < n) {
        int progress = 0;
        for (int i=0;i<n;i++){
            if (rem[i] > 0 && at[i] <= time) {
                progress = 1;
                int exec = rem[i] > qt ? qt : rem[i];
                rem[i] -= exec;
                time += exec;
                if (rem[i]==0){
                    ct[i]=time; tat[i]=ct[i]-at[i]; wt[i]=tat[i]-bt[i]; done++;    } }
        }
        if (!progress) time++; // advance time if no process ready
    }
    double atat=0, awt=0;
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i=0;i<n;i++){ 
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n", pid[i], at[i], bt[i], ct[i], tat[i], wt[i]); atat+=tat[i]; awt+=wt[i]; }
    printf("Avg TAT=%.2f, Avg WT=%.2f\n", atat/n, awt/n);
    return 0;
}
