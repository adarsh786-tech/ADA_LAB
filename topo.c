#include <stdio.h>
#include <stdlib.h>

const int MAX=10;

void Topological (int a[MAX][MAX], int n);

int main()
{
    int a[MAX][MAX],n;
    int i,j;
    printf("Topological sorting algorithm\n");
    printf("Enter number of vertices's:");
    scanf("%d",&n);
    printf("Enter the adjacency matrix \n");
    for(i=0;i<n;i++)
        for(j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    Topological(a,n);
    printf("\n");
    return 0;
}
void Topological(int a[MAX][MAX], int n){
    int in[MAX],out[MAX],stack[MAX],top=-1;
    int i,j,k=0;
    for(i=0;i<n;i++){
        in[i]=0;
        for(j=0;j<n;j++){
            if(a[j][i]==1)
                in[i]++;
        }
    }
    for(i=0;i<n;i++)
        printf("%d\t",in[i]);
    while(1){
        for(i=0;i<n;i++){
            if(in[i]==0){
                stack[++top]=i;
                in[i]=-1;
            }
        }
        if(top==-1)
            break;
        out[k]=stack[top--];
        for(i=0;i<n;i++){
            if(a[out[k]][i]==1)
                in[i]--;
        }
        k++;
    }
    printf("Topological sorting is:");
    for(i=0;i<k;i++)
        printf("%d\t",out[i]+1);
}
