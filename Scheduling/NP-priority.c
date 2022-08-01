 #include<stdio.h>

struct p{
    int pid,arrival,burst,wt,tat,priority;
};

int main(){
    int n, end=0;
    printf("Enter number of process: ");
    scanf("%d",&n);
    struct p arr[n], temp;
    
    for(int i=0;i<n;i++){
        printf("Enter arrival, burst time & priority for pid %d\n",i+1);
        scanf("%d %d %d",&arr[i].arrival,&arr[i].burst,&arr[i].priority);
        arr[i].pid=i+1;
        arr[i].wt=0;
        arr[i].tat=0;
    }
    
    //sorting by arrival, priority
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i].arrival > arr[j].arrival || (arr[i].arrival == arr[j].arrival && arr[i].priority > arr[j].priority)){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    
    //sorting others except 1st one.
    printf("Process\tArrival\tBurst\tWT\tTAT\tPriority\n");
    int AWT=0, ATAT=0;
    for(int i=0;i<n;i++){
        while(end<arr[i].arrival){end++;}
        end += arr[i].burst;
        arr[i].tat = end - arr[i].arrival;
        arr[i].wt = arr[i].tat - arr[i].burst;
        AWT += arr[i].wt;
        ATAT += arr[i].tat;
        
        //i+1 = pid, arrival < end, highest priority
        if(i!=n-1){
            int j,min=9999,x=i+1;
            for(j=i+1;j<n;j++){
                if(arr[j].arrival < end){
                    if(arr[j].priority < min){
                        min = arr[j].priority;
                        x = j;
                    }
                }
            }
            temp = arr[i+1];
            arr[i+1] = arr[x];
            arr[x] = temp;
        }
        
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",arr[i].pid,arr[i].arrival,arr[i].burst,arr[i].wt,arr[i].tat,arr[i].priority);
    }
    
    printf("AWT = %f, ATAT = %f",(double)AWT/n,(double)ATAT/n);
}
 
