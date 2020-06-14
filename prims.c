#include<stdio.h>
#define INF 9999
#define MAX 10
int main()
{
    int a,b,u,v,n,i,j,count=0,sum=0;
    int visited[MAX]={0},cost[MAX][MAX],min,mincost=0;
    printf("\nEnter the number of nodes:");
    scanf("%d",&n);
    printf("\nEnter the cost matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&cost[i][j]);
    for(i=0;i<n;i++)
    {
        for(j=sum=0;j<n;j++)
        {
            if(cost[i][j]!=INF)
                sum+=cost[i][j];
        }
        if(!sum)
        {
            printf("Disconnected graph not allowed.\n");
            return 0;
        }
    }
    visited[0]=1;
    printf("\n");
    while(count<n-1)
    {
        min=INF;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++){
                if(cost[i][j]<min&&visited[i])
                {
                    min=cost[i][j];
                    a=u=i;
                    b=v=j;
                }
            }
        if(!visited[v])
        {
            printf("\nEdge %d:(%d %d) cost:%d",count++,a,b,min);
            mincost+=min;
            visited[b]=1;
        }
        cost[a][b]=cost[b][a]=INF;//no cycle
    }
    printf("\nMinimun cost=%d\n",mincost);
}
