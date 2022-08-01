#include <stdio.h>
int main(){
    int n;
    printf("Enter the number of processes :");
    scanf("%d",&n);
    int mat[n][3];
    int turnaroundtime[n];
    int starttime[n];
    int endtime[n];
    int waitingtime[n];

    for(int i = 0; i<n; i++){
        printf("Enter the arrival time and burst time of p%d :",i+1);
        mat[i][0] = i;
        scanf("%d %d",&mat[i][1],&mat[i][2]);
    }


    int temp1,temp2,temp3;
    for(int i = 0; i<n; i++){
        for(int j = i+1; j<n; j++){
            if (mat[i][1]>mat[j][1]){
                temp3 = mat[i][0];
                temp1 = mat[i][1];
                temp2 = mat[i][2];
                mat[i][0] = mat[j][0];
                mat[i][1] = mat[j][1];
                mat[i][2] = mat[j][2];
                mat[j][0] = temp3;
                mat[j][1] = temp1;
                mat[j][2] = temp2;
            }
        }
    }
    int prev = 0;
    for(int i = 0; i<n; i++){
        if(prev>=mat[i][1]){
            starttime[i] = prev;
            endtime[i] = prev+mat[i][2];
            prev = endtime[i];
        }
        else{
            prev = mat[i][1];
            starttime[i] = prev;
            endtime[i] = prev+mat[i][2];
            prev = endtime[i];
        }
    }

    int sum1 = 0;
    int sum2 = 0;

    printf("Watingtime,Turnaroundtime");
    for(int i =0; i<n;i++){
        waitingtime[i] = starttime[i]-mat[i][1];
        turnaroundtime[i] = endtime[i]-mat[i][1];
        sum1 += waitingtime[i];
        sum2 += turnaroundtime[i];
        printf("\n%d %d",waitingtime[i],turnaroundtime[i]);
    }

    printf("\nAvg Turnaround-Time = %f",(float)sum2/n );
    printf("\nAvg Waiting-Time = %f",(float)sum1/n );

}

