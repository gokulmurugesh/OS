#include<stdio.h>
int main(){
    int n;
    printf("\nEnter the number of processes :");
    scanf("%d",&n);
    int mat[n][4];
    int starttime[n];
    int endtime[n];
    int waitingtime[n];


    // initializing waiting time of every process as 0
    for(int i = 0; i<n;i++){
        waitingtime[i] = 0;
        printf("%d", waitingtime[i]);
    }

    //getting input
    //mat[i][0] -- process id starts from 0
    //mat[i][1] -- process arrival time
    //mat[i][2] -- process burst time
    //mat[i][3] -- process remaining time
    for(int i = 0; i<n;i++){
        mat[i][0] = i;
        printf("\nEnter the arrival and burst time of process p%d :",i);
        scanf("%d %d", &mat[i][1],&mat[i][2] );
        mat[i][3] = mat[i][2];
    }
    

    //sorting based on the arrival and bursttime
    int temp1,temp2,temp3,temp4;
    for(int i = 0; i<n; i++){
        for(int j = i+1;j<n;j++){
            if(mat[i][1] > mat[j][1]){
                temp1 = mat[i][0];
                temp2 = mat[i][1];
                temp3 = mat[i][2];
                temp4 = mat[i][3];
                mat[i][0] = mat[j][0];
                mat[i][1] = mat[j][1];
                mat[i][2] = mat[j][2];
                mat[i][3] = mat[j][3];
                mat[j][0] = temp1;
                mat[j][1] = temp2;
                mat[j][2] = temp3;
                mat[j][3] = temp4;
                
            }
            else if (mat[i][1] == mat[j][1]){
                if(mat[i][3] > mat[j][3]){
                    temp1 = mat[i][0];
                    temp2 = mat[i][1];
                    temp3 = mat[i][2];
                    temp4 = mat[i][3];
                    mat[i][0] = mat[j][0];
                    mat[i][1] = mat[j][1];
                    mat[i][2] = mat[j][2];
                    mat[i][3] = mat[j][3];
                    mat[j][0] = temp1;
                    mat[j][1] = temp2;
                    mat[j][2] = temp3;
                    mat[j][3] = temp4;
                }
            }
        }    
    }



    int tempn = 0;
    int start = mat[0][1];
    while(tempn != n){
        //to check ideal time
        if(start < mat[tempn][1]){
            start = mat[tempn][1];
        }
        //to check if the process starts now and assign start time
        if(mat[tempn][2] == mat[tempn][3]){
            starttime[mat[tempn][0]] = start;
        }
        mat[tempn][3] -= 1;
        start += 1;
        for(int j = tempn+1;j<n;j++){
            if(mat[j][3] != 0 && mat[j][1] <start){
                waitingtime[mat[j][0]] += 1;
            }
        }
        if(mat[tempn][3] == 0){
            endtime[mat[tempn][0]] = start;
            tempn += 1;
        }
        //sorting based on the remaining time for the arrived processes
        for(int i = tempn; i<n; i++){
            for(int j = i+1;j<n;j++){
                if (mat[j][1]<=start){
                    if(mat[i][3] > mat[j][3]){
                        temp1 = mat[i][0];
                        temp2 = mat[i][1];
                        temp3 = mat[i][2];
                        temp4 = mat[i][3];
                        mat[i][0] = mat[j][0];
                        mat[i][1] = mat[j][1];
                        mat[i][2] = mat[j][2];
                        mat[i][3] = mat[j][3];
                        mat[j][0] = temp1;
                        mat[j][1] = temp2;
                        mat[j][2] = temp3;
                        mat[j][3] = temp4;
                    }
                }
                
            }
        }

    }


    int sum1 = 0;
    int sum2 = 0;
    for(int i = 0; i<n; i++){
        sum1 += waitingtime[i];
        sum2 += endtime[mat[i][0]] - mat[i][1]; 
    }
    printf("\nAvg waiting time :%f",(float)sum1/n);
    printf("\nAvg turn around time :%f",(float)sum2/n);
}