#include<stdio.h>

struct process{
    int pid,arrival,burst,wt,tat,burst_remaining,is_completed;
};

int main(){
    int n, TTAT=0,TWT=0, t;
    printf("Enter number of process & time slice: ");
    scanf("%d %d",&n,&t);
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
        // selecting the process 'x' in ready queue on low arrival, if arrival is equal then low pid
        for(int i = 0; i<n; i++){
            if(p[i].arrival <= current_time && p[i].is_completed == 0){
                if(p[i].arrival < min ||(p[i].arrival == min && p[i].pid > p[x].pid)){
                    min = p[i].arrival;
                    x = i;
                }
            }
        }
        
        if(x != -1){
            printf("%d",x+1);
            p[x].burst_remaining-=t;
            current_time+=t;
            while(p[x].burst_remaining < 0){++p[x].burst_remaining;--current_time;}
            p[x].tat += current_time - p[x].arrival;
            p[x].arrival = current_time;
            
            //process completed, calculating wt
            if(p[x].burst_remaining == 0){
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
