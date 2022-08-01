#include <stdio.h>
#include <sys/types.h>
int main()
{
    printf("%d\n",getpid());
    fork();
    fork();
    printf("Parent :%d\n",getppid());
    printf("%d\n",getpid());
    return 0;
}
