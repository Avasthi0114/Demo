#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void)
{
int a[6] = {10,20,30,40,50,60};
printf("\n Given array:\t");
for(int i=0;i<6;++i)
{
printf("%d\t",a[i]);
}
printf("\n");

printf("\nChild process created.\n");
 printf("\nChild => PPID:%d PID: %d\n", getppid(), getpid());
 for(int i = 0; i<6 ;i++)
 {
 a[i] = a[i] * a[i];
 }
printf("\nSquare of numbers in array:\t");
for(int i=0;i<6;++i)
{
printf("%d\t",a[i]);
}
printf("\n");
 exit(EXIT_SUCCESS);
 }

s