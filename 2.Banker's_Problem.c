#include<stdio.h>

struct da
{
    int max[10],a1[10],need[10],before[10],after[10];
}p[10];

int main()
{
    int i,j,k,l,resources,processes,tot[10],av[10],cn=0,cz=0,temp=0,c=0;
    printf("\nEnter the number of processes : ");
    scanf("%d",&processes);
    
    printf("\nEnter the number of resources : ");
    scanf("%d",&resources);

    printf ("\nEnter maximum values of %d resources for %d processes : \n", resources, processes);
    for(i=0;i<processes;i++)
    {
        printf("P%d\t",i+1);
        for(j=0;j<resources;j++)
        {
            scanf("%d",&p[i].max[j]);
        }
    }

    printf ("\nEnter allocated values of %d resources for %d processes : \n", resources, processes);
    for (i=0;i<processes;i++)
    {
        printf("P%d\t",i+1);
        for(j=0;j<resources;j++)
        {
            scanf("%d",&p[i].a1[j]);
            p[i].need[j]=p[i].max[j]-p[i].a1[j];
        }
    }

    printf("\nEnter total values of %d resources :\n", resources);
    for(i=0;i<resources;i++)
    {
        scanf("%d",&tot[i]);
    }
    for(i=0;i<resources;i++)
    {
        for(j=0;j<processes;j++)
        temp=temp+p[j].a1[i];
        av[i]=tot[i]-temp;
        temp=0;
    }
    printf("\n\tResources\t Allocated\t   Needed\t Total\t Available");
    for(i=0;i<processes;i++)
    {
        printf("\nP%d \t",i+1);
        for(j=0;j<resources;j++)
            printf("%d   ",p[i].max[j]);
        printf("\t ");

        for(j=0;j<resources;j++)
            printf("%d   ",p[i].a1[j]);
        printf("\t  ");

        for(j=0;j<resources;j++)
            printf("%d   ",p[i].need[j]);
        printf("\t ");

        for(j=0;j<resources;j++)
        {
            if(i==0)
                printf("%d",tot[j]);
        }
        printf("   ");
        for(j=0;j<resources;j++)
        {
            if(i==0)
                printf("%d",av[j]);
        }
    }
    printf("\n\n\tAvailable Before\t Availabe After");
    for(l=0;l<processes;l++)
    {
        for(i=0;i<processes;i++)
        {
            for(j=0;j<resources;j++)
            {
                if(p[i].need[j] >av[j])
                    cn++;
                if(p[i].max[j]==0)
                    cz++;
            }
            if(cn==0 && cz!=resources)
            {
                for(j=0;j<resources;j++)
                {
                    p[i].before[j]=av[j]-p[i].need[j];
                    p[i].after[j]=p[i].before[j]+p[i].max[j];
                    av[j]=p[i].after[j];
                    p[i].max[j]=0;
                }
                printf("\nP%d \t",i+1);
                for(j=0;j<resources;j++)
                    printf(" %d  ",p[i].before[j]);

                printf("\t \t ");
                for(j=0;j<resources;j++)
                    printf("%d  ",p[i].after[j]);
                cn=0;
                cz=0;
                c++;
                break;
            }
            else
            {
                cn=0;cz=0;
            }
        }
    }
    if(c==processes)
        printf("\n\nTHE ABOVE SEQUENCE IS A SAFE SEQUENCE");
    else
        printf("\n\nDEADLOCK OCCURED");
    
    return 0;
}