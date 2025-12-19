/*
指针数组排序，升序降序现场定，使用快速排序
输出为：排序后二维数组的样子，排序后指针数组的内容
要求用指针数组改变，不改变二维数组内容
*/

#include <stdio.h>
#include <string.h>
#define N 7

void quicksort(char *a[], int left, int right) {
    if (left >= right) return;
    int i = left, j = right;
    char *x = a[(left + right) / 2];
    while (i <= j) {
        while (strcmp(a[i], x) < 0) i++;
        while (strcmp(a[j], x) > 0) j--;
        if (i <= j) {
            char *t = a[i];
            a[i] = a[j];
            a[j] = t;
            i++;
            j--;
        }
    }
    if (left < j) quicksort(a, left, j);
    if (i < right) quicksort(a, i, right);
}

int main()
{
    int i;
    char nation[N][4]={"CHN", "CAN", "USA", "RUS", "AUS", "KOR","JPN"};
    char *p[N];
    for(i=0;i<N;i++)
        p[i]=nation[i];
    quicksort(p, 0, N-1);
    printf("After sorted, the sequences in two dimension array are: \n");
    for(i=0;i<N;i++)
        printf("%s ",nation[i]);
    putchar('\n');
    printf("After sorted, the sequences indicated by pointer array are: \n");
    for(i=0;i<N;i++)
        printf("%s ",p[i]);
    putchar('\n');
    return(0);
}