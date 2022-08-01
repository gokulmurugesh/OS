//first fit
#include<stdio.h>
int main(){
    int nb,np;
    printf("\nEnter the number of Blocks :");
    scanf("%d",&nb);
    printf("\nEnter the number of Processes (<Blocks) :");
    scanf("%d",&np);
    int block[nb][2];//0 -- size 1 -- fragment
    printf("\nEnter the size of each blocks");
    for(int i=0; i<nb;i++){
        printf("\nBlock b%d :",i);
        scanf("%d",&block[i][0]);
        block[i][1] = block[i][0];
    }
    int process[np][2];
    printf("\nEnter the size of each process");
    for(int i=0;i<np;i++){
        printf("\nProcess p%d :",i);
        scanf("%d",&process[i][0]);
        process[i][1] = -1;
    }
    for(int i=0;i<np;i++){
        int min = -1;
        for(int j=0;j<nb;j++){
            if(block[j][0] == block[j][1]){
                if(block[j][0] >= process[i][0]){
                    if(min == -1 || block[j][1]<block[min][1]){
                        min = j;
                    }
                }
            }    
        }
        process[i][1] = min;
        block[min][1] -= process[i][0];
    }

    for(int i = 0; i<np;i++){
        printf("\nProcess %d in block %d with size %d and fragment %d",i,process[i][1],
        (process[i][1] == -1)?process[i][1]:block[process[i][1]][0],(process[i][1] == -1)?process[i][1]:block[process[i][1]][1]);
    }
}