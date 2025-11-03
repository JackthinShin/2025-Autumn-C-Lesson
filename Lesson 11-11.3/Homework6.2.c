/*
请输入5个数:1 3 2 7 9
排序结果为:9 7 3 2 1
1<=N<=10
1)冒泡
2)选择
可以现场改升序降序
*/
#include <stdio.h>

void bubble_sort(int a[],int n){
    int i,j,temp;
    for(i=0;i<n-1;i++)
        for(j=0;j<n-1-i;j++)
            if(a[j]<a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
}

void select_sort(int a[],int n){
    int i,j,index,temp;
    for(i=0;i<n-1;i++){
        index=i;
        for(j=i+1;j<n;j++)
            if(a[j]>a[index])
                index=j;
        if(index!=i){
            temp=a[i];
            a[i]=a[index];
            a[index]=temp;
        }
    }
}

int main(){
    int a[5];
    int n=5;
    printf("请输入5个数:");
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    bubble_sort(a,n);
    // select_sort(a,n);
    printf("排序结果为:");
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}