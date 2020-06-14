#include <stdio.h>
#include <stdlib.h>

void minmax(int arr[], int low, int high, int *min, int *max){
    if(low == high){
        *min=arr[low];
        *max=arr[high];
    }
    else if(low == high-1){
        if(arr[low]<arr[high]){
            *min=arr[low];
            *max=arr[high];
        }
        else{
            *max=arr[low];
            *min=arr[high];
        }
    }
    else{
        int min1,min2,max1,max2,mid;
        mid=(low+high)/2;
        minmax(arr,low,mid,&min1,&max1);
        minmax(arr,mid+1,high,&min2,&max2);
        if(min1<min2){
            *min=min1;
        }
        else
            *min=min2;
        if(max1>max2){
            *max=max1;
        }
        else
            *max=max2;
    }
}
int main(){
    int n,i;
    printf("Enter number of array");
    scanf("%d",&n);
    int arr[n];
    printf("Enter number in array");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    int min,max;
    minmax(arr,0,n-1,&min,&max);
    printf("%d %d",min,max);
}
