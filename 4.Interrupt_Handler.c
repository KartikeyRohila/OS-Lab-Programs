#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void i_o_service_routine()
{
    printf("Enter a number : ");
    int x;
    scanf("%d",&x);
    printf("%d\n",x);
}

void err_service_routine()
{
    srand(time(NULL));
    int x=rand()%5+1;
    for(int i=1;i<=x;i++)
    {
        int delay = 1000;   //in milliseconds
        clock_t start_time = clock();
        while(clock()<start_time+delay)
            ;
        printf("Error %d removed\n",i);
    }
}

void interrupt_handler(int n)
{
    srand(time(NULL));
    int pos=rand()%4+2;
    int pos2 = pos+rand()%3+1;
    for(int i=1;i<=n;)
    {
        if(i==pos-1)
        {
            printf("\nProcess %d executed",i);
            printf("\n\nInput/Output interrupt occured - processes paused\n");
            i_o_service_routine();
            printf("\nInterrupt handled by interrupt service routine, ");
            printf("process execution continued\n");
            i++;
        }
        else if(i==pos2-1)
        {
            printf("\nProcess %d executed",i);
            printf("\n\nError interrupt occured - ");
            printf("processes paused-please wait\n");
            err_service_routine();
            printf("\nInterrupt handled by interrupt service routine, ");
            printf("process execution continued\n");
            i++;
        }
        else
        {
            printf("\nProcess %d executed",i);
            i++;
        }
    }
}

int main()
{
    srand(time(NULL));
    int n = rand()%6+10;
    interrupt_handler(n);
}