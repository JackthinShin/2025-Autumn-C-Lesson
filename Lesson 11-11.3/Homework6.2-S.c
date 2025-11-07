/*
请输入5个数:1 3 2 7 9
排序结果为:9 7 3 2 1
1<=N<=10
1)冒泡
2)选择
可以现场改升序降序
*/
#include <stdio.h>

void select_sort(int a[],int n){
    int i,j,index,temp;
    for(i=0;i<n-1;i++){
        index=i;
        for(j=i+1;j<n;j++)
            if(a[j]>a[index])   // > 降序  < 升序
                index=j;
        temp=a[i];
        a[i]=a[index];
        a[index]=temp;
    }
}

int main(){
    int n=6;
    int a[n];
    printf("请输入%d个数:",n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    select_sort(a,n);
    printf("排序结果为:");
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
    return 0;
}