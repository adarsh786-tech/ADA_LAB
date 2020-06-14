#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int a[30],count=0;

void print_sol(int n)
{
    int i,j;
    count++;
    printf("Solution #%d:",count);
    printf("\n");
    for(i=1;i<=n;i++) // row
    {
        for(j=1;j<=n;j++) //column
        {
        if(a[i]==j)
            printf("Q\t");
        else
            printf("0\t");
        }
        printf("\n");
    }
}

int place(int pos)
{
    int i;
    for(i=1;i<pos;i++)
    {
        if((a[i]==a[pos])||((abs(a[i]-a[pos])==abs(i-pos))))
            return 0;
    }
    return 1;
}

void queen(int n)
{
    int k=1; //column
    a[k]=0; // Q position
    while(k!=0)
    {
        a[k]=a[k]+1;
        while((a[k]<=n)&&!place(k))
            a[k]++;
        if(a[k]<=n)
        {
            if(k==n)
                print_sol(n);
            else
            {
                k++;
                a[k]=0;
            }
        }
        else
            k--;
    }
}
void main()
{
    int i,n;

    printf("Enter the number of Queens n");
    scanf("%d",&n);

    queen(n);

    printf("Total no of solutions=%d",count);
}
