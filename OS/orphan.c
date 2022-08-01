#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main(){
    int pid = fork();
    if (pid > 0){
        printf("Parent Process");
        exit(0);
    }
    else if (pid == 0){
        printf("In child process");
        sleep(50);
    }
}