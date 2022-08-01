#include <stdio.h>
//non pre-emptive
int main(){
    int n;
    printf("Enter the number of processes :");
    scanf("%d", &n);
    int mat[n][3];
    int starttime[n];
    int endtime[n];
    int waitingtime[n];
    int turnaroundtime[n];
    for(int i=0;i<n;i++){
        mat[i][0] = i+1;
        printf("Enter the arrival time and burst time of %d :",i+1);
        scanf("%d %d",&mat[i][1],&mat[i][2]);
    }




    // printing the matrix 
    // for(int i=0;i<n;i++){
    //     printf("\n%d %d %d",mat[i][0],mat[i][1],mat[i][2]);
    
    // }
//sorting based on arrival time
    int temp1,temp2,temp3;
    for(int i=0; i<n;i++){
        for(int j=i+i;j<n;j++){
            if(mat[i][1]>mat[j][1]){
                temp1 = mat[i][0];
                temp2 = mat[i][1];
                temp3 = mat[i][2];
                mat[i][0] = mat[j][0];
                mat[i][1] = mat[j][1];
                mat[i][2] = mat[j][2];
                mat[j][0] = temp1;
                mat[j][1] = temp2;
                mat[j][2] = temp3;
            }
            else if(mat[i][1] == mat[j][1]){
                if(mat[i][2] > mat[j][2]){
                temp1 = mat[i][0];
                temp2 = mat[i][1];
                temp3 = mat[i][2];
                mat[i][0] = mat[j][0];
                mat[i][1] = mat[j][1];
                mat[i][2] = mat[j][2];
                mat[j][0] = temp1;
                mat[j][1] = temp2;
                mat[j][2] = temp3;
                }
            }
        }
    }
    // for(int i=0;i<n;i++){
    //     printf("\n%d %d %d",mat[i][0],mat[i][1],mat[i][2]);
    
    // }

    int start = mat[0][1];
    for(int i=0;i<n;i++){
        starttime[i] = start;
        endtime[i] = start+mat[i][2];
        start = endtime[i];
        for(int j=i+1;j<n-1;j++){
            for(int k=j+1;k<n;k++){
                if(mat[k][1]>endtime[i]){
                    continue;
                }
                if(mat[k][2]<mat[j][2]){
                    temp1 = mat[k][0];
                    temp2 = mat[k][1];
                    temp3 = mat[k][2];
                    mat[k][0] = mat[j][0];
                    mat[k][1] = mat[j][1];
                    mat[k][2] = mat[j][2];
                    mat[j][0] = temp1;
                    mat[j][1] = temp2;
                    mat[j][2] = temp3;
                }
            }
        }
    }
    // for(int i=0;i<n;i++){
    //     printf("\n%d %d %d",mat[i][0],mat[i][1],mat[i][2]);
    // }
    // for(int i=0; i<n; i++){
    //     printf("\n%d %d",starttime[i],endtime[i]);
    // }

    int sum1 = 0,sum2 = 0;
    for(int i=0;i<n;i++){
        turnaroundtime[i] = endtime[i]-mat[i][1];
        waitingtime[i] = starttime[i]-mat[i][1];
        sum1 += turnaroundtime[i];
        sum2 += waitingtime[i];
    }

    printf("\nAverage turnaround time :%f",(float)sum1/n);
    printf("\nAverage waiting time :%f",(float)sum2/n);
}


