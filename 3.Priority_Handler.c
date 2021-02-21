#include<stdio.h>

int main()
{
    int processes,total=0,pos,temp;
    float avg_wait,avg_turn;
    int burst[20],p[20],waiting[20],turnaround[20],priority[20];
    printf("Enter Total Number of Process : ");
    scanf("%d",&processes);
    
    printf("\nEnter Burst Time and Priority\n");
    for(int i=0;i<processes;i++)
    {
        printf("\nP[%d]\n",i+1);
        printf("Burst Time : ");
        scanf("%d",&burst[i]);
        printf("Priority : ");
        scanf("%d",&priority[i]);
        p[i]=i+1;   //contains process number
    }
    
    //sorting burst time, priority and process number in ascending order using selection sort
    for(int i=0;i<processes;i++)
    {
        pos=i;
        for(int j=i+1;j<processes;j++)
        {
            if(priority[j]<priority[pos])
                pos=j;
        }
        
        temp=priority[i];
        priority[i]=priority[pos];
        priority[pos]=temp;
        
        temp=burst[i];
        burst[i]=burst[pos];
        burst[pos]=temp;
        
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
    
    waiting[0]=0;    //waiting time for first process is zero

    //calculate waiting time
    for(int i=1;i<processes;i++)
    {
        waiting[i]=0;
        for(int j=0;j<i;j++)
            waiting[i]+=burst[j];
            
        total+=waiting[i];
    }
    
    avg_wait=(1.0)*total/processes;     //average waiting time
    total=0;
    
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(int i=0;i<processes;i++)
    {
        turnaround[i]=burst[i]+waiting[i];     //calculate turnaround time
        total+=turnaround[i];
        printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",p[i],burst[i],waiting[i],turnaround[i]);
    }
    
    avg_turn=(1.0)*total/processes;        //average turnaround time
    printf("\n\nAverage Waiting Time=%f",avg_wait);
    printf("\nAverage Turnaround Time=%f\n",avg_turn);
    return 0;
}