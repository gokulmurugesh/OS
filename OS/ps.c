#include<stdio.h>
int main(){
    int n;
    printf("\nEnter the number of processes :");
    scanf("%d",&n);
    int mat[n][4];
    int starttime[n];
    int endtime[n];


    for(int i = 0; i<n;i++){
        mat[i][0] = i;
        printf("\nEnter the arrival, burst time and priority of process p%d :",i);
        scanf("%d %d %d", &mat[i][1],&mat[i][2], &mat[i][3]);
    }
    
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
            if(mat[i][1] == mat[j][1]){
                if(mat[i][3]>mat[j][3]){
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

    for(int i = 0; i<n; i++){
        printf("\nP%d\t%d\t%d\t%d\t",mat[i][0],mat[i][1],mat[i][2],mat[i][3]);
    }


    int tempn = 0;
    int start = mat[0][1];
    while(tempn != n){
        if(mat[tempn][1]> start){
            start = mat[tempn][1];
        }   
        starttime[mat[tempn][0]] = start;
        start+= mat[tempn][2];
        endtime[mat[tempn][0]] = start;
        tempn += 1;
        for(int i = tempn;i<n;i++){
            if(mat[i][1]<start && mat[i][3]<mat[tempn][3]){
                temp1 = mat[tempn][0];
                temp2 = mat[tempn][1];
                temp3 = mat[tempn][2];
                temp4 = mat[tempn][3];
                mat[tempn][0] = mat[i][0];
                mat[tempn][1] = mat[i][1];
                mat[tempn][2] = mat[i][2];
                mat[tempn][3] = mat[i][3];
                mat[i][0] = temp1;
                mat[i][1] = temp2;
                mat[i][2] = temp3;
                mat[i][3] = temp4;
            }
        }

    }
    int waittime = 0;
    int turn_around_time = 0;
    for(int i=0;i<n;i++){
        waittime += (endtime[mat[i][0]] - mat[i][2] - mat[i][1]);
        turn_around_time += (endtime[mat[i][0]] - mat[i][1]);
    }
    printf("\nAverage waitting time is %f",(float)waittime/n);
    printf("\nAverage turn around  time is %f",(float)turn_around_time/n);
    printf("\n start :%d",start);
    
}