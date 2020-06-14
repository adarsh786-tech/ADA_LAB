#include<stdio.h>
#define MAX 10
#define INF 99
typedef struct
{
	int u,v,weight;
}EDGE;
int findParent(int v,int parent[])
{
	while(parent[v]!=v)v=parent[v];
	return v;
}
void union_ij(int i,int j,int parent[])
{
	if(i<j)parent[j]=i;
	else parent[i]=j;
}
void readGraph(int m,EDGE e[])
{
	int i;
	for(i=0;i<m;i++)
	{
		printf("Enter the edge %d (u,v) and weight : ",i+1);
		scanf("%d%d%d",&e[i].u,&e[i].v,&e[i].weight);
	}
}
int getMinEdge(int n,EDGE e[])
{
	int i,small,pos;
	small=INF;
	pos=-1;
	for(i=0;i<n;i++)
	{
		if(e[i].weight<small)
		{
			small=e[i].weight;
			pos=i;
		}
	}
	return pos;
}
void kruskal(int n,int m,EDGE e[])
{
	int i,j,k,count,sum,u,v,pos,t[MAX][2],parent[MAX];
	count=k=sum=0;
	for(i=0;i<n;i++)
        parent[i]=i;
	while(count<n-1)
	{
		pos=getMinEdge(m,e);
		if(pos==-1)
            break;
		u=e[pos].u;
		v=e[pos].v;
		i=findParent(u,parent);
		j=findParent(v,parent);
		if(i!=j)
		{
			t[k][0]=u;
			t[k][1]=v;
			k++;
            count++;
			sum+=e[pos].weight;
			union_ij(i,j,parent);
		}
		e[pos].weight=INF;
	}
	if(count==n-1)
	{
		printf("Minimum Spannig Tree : \n");
		for(i=0;i<n-1;i++)
		printf("Edge %d (%d,%d)\n",i+1,t[i][0],t[i][1]);
		printf("Sum of Weight = %d\n",sum);
	}
	else printf("Spannig tree not found.\n");
}
int main()
{
	int n,m;
	EDGE e[2*MAX];
	printf("Enter the no. of vertices : ");
	scanf("%d",&n);
	printf("Enter the no. of edges : ");
	scanf("%d",&m);
	readGraph(m,e);
	kruskal(n,m,e);
}
