#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
    int pid = fork();
    if (pid > 0){
        printf("In parent process");
        sleep(50);
    }
    else{
        printf("In child process");
        exit(0);
    }
    
}