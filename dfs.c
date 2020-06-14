#include <stdio.h>
#include <stdlib.h>

int g[20][20],n,visited[20];
void fnDepthFirstSearch(int);

int main(void)
{
    int i,j,k;
    int v;
    printf("Enter the number of vertices : ");
    scanf("%d",&n);
    for (i=1; i<=n; i++)
        visited[i] = 0;
    printf("Enter the adjacency matrix :\n");
    for (i=1; i<=n; i++)
        for (j=1; j<=n; j++)
            scanf("%d",&g[i][j]);
    printf("Enter the source vertex : ");
    scanf("%d",&v);
    fnDepthFirstSearch(v);
    for (k=1; k<=n; k++)
    {
        if(visited[k])
        {
            printf("\nVertex %d reachable",k);
        }
        else
        {
            printf("\nVertex %d not reachable",k);
        }
    }
}
void fnDepthFirstSearch(int currentVertex)
{
    int i;
    visited[currentVertex] = 1;
    for (i=1; i<=n; i++)
        if (g[currentVertex][i] && !visited[i])
            fnDepthFirstSearch(i);
}

