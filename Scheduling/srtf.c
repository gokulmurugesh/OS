#include<stdio.h>

struct process{
    int pid,arrival,burst,wt,tat,burst_remaining,is_completed;
};

int main(){
    int n, TTAT=0,TWT=0;
    printf("Enter number of process: ");
    scanf("%d",&n);
    struct process p[n];
    
    for(int i=0;i<n;i++){
        printf("Enter arrival & burst time for pid %d\n",i+1);
        scanf("%d %d",&p[i].arrival,&p[i].burst);
        p[i].pid=i+1;
        p[i].wt=0;
        p[i].tat=0;
        
        //setting burst time,burst_remaining & completion status
        p[i].burst_remaining = p[i].burst;
        p[i].is_completed = 0;
    }
    
    int current_time = 0, completed = 0;
    while(completed != n){
        int x = -1;
        int min = 999999;
        // selecting the process 'x' in ready queue on low burst_remaining, if burst_remaining is equal then low arrival time
        for(int i = 0; i<n; i++){
            if(p[i].arrival <= current_time && p[i].is_completed == 0){
                if(p[i].burst_remaining < min ||(p[i].burst_remaining == min && p[i].arrival < p[x].arrival)){
                    min = p[i].burst_remaining;
                    x = i;
                }
            }
        }
        
        if(x != -1){
            p[x].burst_remaining--;
            current_time++;
            //process completed, calculating tat,wt
            if(p[x].burst_remaining == 0){
                p[x].tat = current_time - p[x].arrival;
                p[x].wt = p[x].tat - p[x].burst;
                TTAT += p[x].tat;
                TWT += p[x].wt;
                p[x].is_completed = 1;
                completed++;
            }
        }
        else{
            current_time++;
        }
    }
    printf("Process\tArrival\tBurst\tWT\tTAT\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].arrival,p[i].burst,p[i].wt,p[i].tat);
    }
    printf("AWT = %f, ATAT = %f",(double)TWT/n,(double)TTAT/n);
}
