#include<stdio.h>
#include<math.h>

int board[20],coun;

void PrintSolution(int n)
{
    printf("\n\nSolution %d:\n\n",++count);
    
    for(int i=1;i<=n;++i)
        printf("\t%d",i);
    
    for(int i=1;i<=n;++i)
    {
        printf("\n\n%d",i);
        for(int j=1;j<=n;++j)
        {
            if(board[i]==j)
                printf("\tQ"); //Queen at position (i,j)
            else
                printf("\t-"); //Empty place
        }
    }
}

// Function to check conflicts
// If no conflict for desired postion returns 1 otherwise returns 0
int place(int row,int column)
{
    int i;
    for(i=1;i<=row-1;++i)
    {
        //Checking column and digonal conflicts
        if(board[i]==column)
            return 0;
        else
            if(abs(board[i]-column)==abs(i-row))
                return 0;
    }
    return 1; //No conflicts
}

void queen (int row,int n)
{
    int column;
    for(column=1;column<=n;++column)
    {
        if(place(row,column))
        {
            board[row]=column; //No conflicts So place queen
            if(row==n) //Dead end
                PrintSolution(n); //Printing the Board Configuration
            else //Try queen with next position
                queen(row+1,n);
        }
    }
}

int main()
{
    int n,i,j;
    void queen(int row,int n);
    printf("\n*** N Queens Problem ***\n");
    printf("\nEnter number of Queens : ");
    scanf("%d",&n);
    queen(1,n);
    printf ("\n");
    return 0;
}