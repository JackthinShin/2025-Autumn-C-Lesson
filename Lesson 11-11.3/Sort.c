/*
冒泡排序
选择排序
插入排序(直接排序，二分查找)
*/
#include <stdio.h>

int bi_search(int a[],int n,int x){
    int bot=0,top=n-1,mid;
    do{
        mid=(bot+top)/2;
        if(a[mid]==x) return mid;
        else if(a[mid]<x) bot=mid+1;
        else top=mid-1;
    }while(bot<=top);
    return -1;
}

void bubble_sort(int a[],int n){
    int i,j,temp;
    for(i=0;i<n-1;i++)
        for(j=0;j<n-1-i;j++)
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
}

void select_sort(int a[],int n){
    int i,j,min_index,temp;
    for(i=0;i<n-1;i++){
        min_index=i;
        for(j=i+1;j<n;j++)
            if(a[j]<a[min_index])
                min_index=j;
        if(min_index!=i){
            temp=a[i];
            a[i]=a[min_index];
            a[min_index]=temp;
        }
    }
}

void insert_sort(int a[],int n){
    int i,j,temp;
    for(i=1;i<n;i++){
        temp=a[i];
        j=i-1;
        while(j>=0 && a[j]>temp){
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
}

void insert_sort_bi(int a[],int n){
    int i,j,temp,bot,top,mid;
    for(i=1;i<n;i++){
        temp=a[i];
        bot=0; top=i-1;
        while(bot<=top){
            mid=(bot+top)/2;
            if(a[mid]>temp) top=mid-1;
            else bot=mid+1;
        }
        for(j=i-1;j>=bot;j--)
            a[j+1]=a[j];
        a[bot]=temp;
    }
}

int main(){
    int a[]={34,8,64,51,32,21};
    int n=sizeof(a)/sizeof(a[0]);
    insert_sort_bi(a,n);
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
    int x=51;
    int index=bi_search(a,n,x);
    if(index!=-1)
        printf("%d found at index %d\n",x,index);
    else
        printf("%d not found\n",x);
    return 0;
}