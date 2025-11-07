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
            if(a[j]<a[j+1]){    // < 降序  > 升序
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
}

int main(){
    int n=7;
    int a[n];
    printf("请输入%d个数:",n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    bubble_sort(a,n);
    printf("排序结果为:");
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}