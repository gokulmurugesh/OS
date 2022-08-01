#include<stdio.h>

struct p{
    int pid,arrival,burst,wt,tat;
};

int main(){
    int n, end=0;
    printf("Enter number of process: ");
    scanf("%d",&n);
    struct p arr[n];
    
    for(int i=0;i<n;i++){
        printf("Enter arrival & burst time for pid %d\n",i+1);
        scanf("%d %d",&arr[i].arrival,&arr[i].burst);
        arr[i].pid=i+1;
        arr[i].wt=0;
        arr[i].tat=0;
    }
    
    //sorting by arrival
    struct p temp;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i].arrival > arr[j].arrival || (arr[i].arrival == arr[j].arrival && arr[i].pid > arr[j].pid)){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }            
        }
    }
    
    printf("Process\tArrival\tBurst\tWT\tTAT\n");
    int TWT=0, TTAT=0;
    for(int i=0;i<n;i++){
        while(end<arr[i].arrival){end++;}
        end += arr[i].burst;
        arr[i].tat = end - arr[i].arrival;
        arr[i].wt = arr[i].tat - arr[i].burst;
        TWT += arr[i].wt;
        TTAT += arr[i].tat;
        printf("%d\t%d\t%d\t%d\t%d\n",arr[i].pid,arr[i].arrival,arr[i].burst,arr[i].wt,arr[i].tat);
    }
    
    printf("AWT = %f, ATAT = %f",(double)TWT/n,(double)TTAT/n);
}
