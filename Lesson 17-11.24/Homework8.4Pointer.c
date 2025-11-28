/*
原数组为：1 2 3 4 5 6 7
请输入m：9
结果为：6 7 1 2 3 4 5
*/
#include <stdio.h>

void rev(int *a, int l, int r) {
    int *p1 = a + l;
    int *p2 = a + r;
    while (p1 < p2) {
        int temp = *p1;
        *p1 = *p2;
        *p2 = temp;
        p1++;
        p2--;
    }
}

int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    int m,n=7;
    printf("原数组为：");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n请输入m：");
    scanf("%d", &m);
    m = m % n;
    rev(a, 0, n-m-1);
    rev(a, n-m, n-1);
    rev(a, 0, n-1);
    printf("结果为：");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}