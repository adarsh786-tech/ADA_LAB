#include<stdio.h>
#define INFINITY 999
#define MAX 10
void dijkstra(int cost[MAX][MAX],int n,int startnode)
{
    int distance[MAX],pred[MAX];
    int visited[MAX],count,mindistance,nextnode,i,j;
//pred[] stores the predecessor of each node
//count gives the number of nodes seen so far

//initialize pred[],distance[] and visited[]
    for(i=0;i<n;i++)
    {
        distance[i]=cost[startnode][i];
        pred[i]=startnode;
        visited[i]=0;
    }
    distance[startnode]=0;
    visited[startnode]=1;
    count=1;
    while(count<n-1)
    {
        mindistance=INFINITY;
//nextnode gives the node at minimum distance
        for(i=0;i<n;i++)
            if(!visited[i]&&distance[i]<mindistance){
                mindistance=distance[i];
                nextnode=i;
            }
//check if a better path exists through nextnode
        visited[nextnode]=1;
        for(i=0;i<n;i++)
            if(!visited[i]&&mindistance+cost[nextnode][i]<distance[i])
                distance[i]=mindistance+cost[nextnode][i],pred[i]=nextnode;
        count++;
    }
//print the path and distance of each node
    printf("Dest.\tDis.\tPath");
    for(i=0;i<n;i++)
        if(i!=startnode)
        {
            printf("\n%d\t%d\t%d",i,distance[i],i);
            j=i;
            do{
                j=pred[j];
                printf("<-%d",j);
            }while(j!=startnode);
        }
        printf('\n');
}
int main()
{
    int G[MAX][MAX],i,j,n,u;
    printf("Enter no. of vertices:");
        scanf("%d",&n);
    printf("\nEnter the cost matrix:\n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&G[i][j]);
    printf("\nEnter the starting node:");
        scanf("%d",&u);
    dijkstra(G,n,u);
}
