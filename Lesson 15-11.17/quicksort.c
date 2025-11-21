#include <stdio.h>

int partition(int a[],int left,int right) {
    int i=left,j=right,key=a[left];
    while(i<j) {
        while(i<j&&a[j]>=key)
            j--;
        a[i]=a[j];
        while(i<j&&a[i]<=key)
            i++;
        a[j]=a[i];
    }
    a[i]=key;
    return i;
}

void quick(int a[],int left,int right) {
    if (left<right) {
        int k=partition(a,left,right);
        quick(a,left,k-1);
        quick(a,k+1,right);
    }
}

int main() {
    int a[10]={49,38,65,97,76,13,27,49,55,4};
    quick(a,0,9);
    for(int i=0;i<10;i++)
        printf("%d ",a[i]);
    putchar('\n');
    return 0;
}