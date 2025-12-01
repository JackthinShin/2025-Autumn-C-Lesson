/*
4个角分别放最小的4个数，中心放最大的数，其余的数依次放置，形成一个矩阵
4个角上的数按从左往右、从上往下的顺序依次放置
用指针实现
*/

#include <stdio.h>
#define N 5

void swap(int *a, int i, int j) {
    int temp = *(a + i);
    *(a + i) = *(a + j);
    *(a + j) = temp;
}

void sort(int *arr, int n) {
    int i,j;
    for (i = 0; i < 4; i++) {
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[i]) {
                swap(arr, i, j);
            }
        }
    }
    for (j=4,i=5; i < n; i++) {
        if (arr[i] > arr[j]) {
            j=i;
        }
    }
    swap(arr, j, n/2);
    swap(arr, 3, n-1);
    swap(arr, 2, n-N);
    swap(arr, 1, N-1);
}

int main() {
    int a[N][N];
    int i,j,k=N*N;
    for(i=0;i<N;i++) {
        for(j=0;j<N;j++) {
            a[i][j]=k--;
        }
    }
    sort(a[0],N*N);
    for(i=0;i<N;i++) {
        for(j=0;j<N;j++) {
            if((i==0&&j==0)||(i==0&&j==N-1)||(i==N-1&&j==0)||(i==N-1&&j==N-1)||(i==N/2&&j==N/2)) {
                printf("%4d",a[i][j]);
            } else {
                printf("%4s"," ");
            } 
        }
        printf("\n");
    }
    return 0;
}