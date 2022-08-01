#include<stdio.h>
int main(){
    int n;
    printf("\nEnter the number of processes :");
    scanf("%d",&n);
    int mat[n][5];
    int starttime[n];
    int endtime[n];


    for(int i = 0; i<n;i++){
        mat[i][0] = i;
        printf("\nEnter the arrival, burst time and priority of process p%d :",i);
        scanf("%d %d %d", &mat[i][1],&mat[i][2], &mat[i][3]);
        mat[i][4] = mat[i][2];
    }
    
    int temp1,temp2,temp3,temp4,temp5;
    for(int i = 0; i<n; i++){
        for(int j = i+1;j<n;j++){
            if(mat[i][1] > mat[j][1]){
                temp1 = mat[i][0];
                temp2 = mat[i][1];
                temp3 = mat[i][2];
                temp4 = mat[i][3];
                temp5 = mat[i][4];
                mat[i][0] = mat[j][0];
                mat[i][1] = mat[j][1];
                mat[i][2] = mat[j][2];
                mat[i][3] = mat[j][3];
                mat[i][4] = mat[j][4];
                mat[j][0] = temp1;
                mat[j][1] = temp2;
                mat[j][2] = temp3;
                mat[j][3] = temp4;
                mat[j][4] = temp5;
                
            }
            if(mat[i][1] == mat[j][1]){
                if(mat[i][3]>mat[j][3]){
                    temp1 = mat[i][0];
                    temp2 = mat[i][1];
                    temp3 = mat[i][2];
                    temp4 = mat[i][3];
                    temp5 = mat[i][4];
                    mat[i][0] = mat[j][0];
                    mat[i][1] = mat[j][1];
                    mat[i][2] = mat[j][2];
                    mat[i][3] = mat[j][3];
                    mat[i][4] = mat[j][4];
                    mat[j][0] = temp1;
                    mat[j][1] = temp2;
                    mat[j][2] = temp3;
                    mat[j][3] = temp4;
                    mat[j][4] = temp5;
                }
            }
        }    
    }

    for(int i = 0; i<n; i++){
        printf("\nP%d\t%d\t%d\t%d\t%d",mat[i][0],mat[i][1],mat[i][2],mat[i][3],mat[i][4]);
    }


    int tempn = n;
    int start = mat[0][1];
    while(tempn != 0){
        if(mat[0][1]> start){
            start = mat[0][1];
        }
        if(mat[0][2] == mat[0][4]){
           starttime[mat[0][0]] = start;  
        }
        start += 1;   
        mat[0][4] -= 1;
        if(mat[0][4] == 0){
            endtime[mat[0][0]] = start;
            temp1 = mat[0][0];
            temp2 = mat[0][1];
            temp3 = mat[0][2];
            temp4 = mat[0][3];
            temp5 = mat[0][4];
            mat[0][0] = mat[tempn-1][0];
            mat[0][1] = mat[tempn-1][1];
            mat[0][2] = mat[tempn-1][2];
            mat[0][3] = mat[tempn-1][3];
            mat[0][4] = mat[tempn-1][4];
            mat[tempn-1][0] = temp1;
            mat[tempn-1][1] = temp2;
            mat[tempn-1][2] = temp3;
            mat[tempn-1][3] = temp4;
            mat[tempn-1][4] = temp5;
            tempn -= 1;
        }
        for(int i = 0;i<tempn;i++){
            if(mat[i][1]<= start){
                if(mat[0][3]>mat[i][3]){
                    temp1 = mat[i][0];
                    temp2 = mat[i][1];
                    temp3 = mat[i][2];
                    temp4 = mat[i][3];
                    temp5 = mat[i][4];
                    mat[i][0] = mat[0][0];
                    mat[i][1] = mat[0][1];
                    mat[i][2] = mat[0][2];
                    mat[i][3] = mat[0][3];
                    mat[i][4] = mat[0][4];
                    mat[0][0] = temp1;
                    mat[0][1] = temp2;
                    mat[0][2] = temp3;
                    mat[0][3] = temp4;
                    mat[0][4] = temp5;
                }
            }
            
        }

    }
    int waittime = 0;
    int turn_around_time = 0;

    for(int i = 0; i<n; i++){
        printf("\nP%d\t%d\t%d\t%d\t%d",mat[i][0],mat[i][1],mat[i][2],mat[i][3],mat[i][4]);
    }


    for(int i=0;i<n;i++){
        printf("\n Start time of p%d is %d",mat[i][0],starttime[mat[i][0]]);
        waittime += (endtime[mat[i][0]] - mat[i][2] - mat[i][1]);
        turn_around_time += (endtime[mat[i][0]] - mat[i][1]);
    }
    printf("\nAverage waitting time is %f",(float)waittime/n);
    printf("\nAverage turn around  time is %f",(float)turn_around_time/n);
    printf("\n start :%d",start);
    
}