/*
原数组为:1 3 4 5 7 8 9 10 11 12
输入x:2
新的数组为:1 2 3 4 5 7 8 9 10 11 12
*/
#include <stdio.h>

int bi_search(int a[],int n,int x){
    int bot=0,top=n-1,mid;
    do{
        mid=(bot+top)/2;
        if(a[mid]==x) return mid+1;
        else if(a[mid]<x) bot=mid+1;
        else top=mid-1;
    }while(bot<=top);
    return bot;
}

int main(){
    int a[11]={1,3,4,5,7,8,9,10,11,12};
    int n=10;
    int x;
    printf("原数组为:");
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n输入x:");
    scanf("%d",&x);
    int pos=bi_search(a,n,x);
    for(int i=n;i>pos;i--)
        a[i]=a[i-1];
    a[pos]=x;
    n++;
    printf("新的数组为:");
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}