/*
原数组为：1 2 3 4 5 6 7
请输入m：9
结果为：6 7 1 2 3 4 5
*/
#include <stdio.h>

void r_s1(int *a, int n) {
    int last = *(a + n - 1);
    for (int i = n - 1; i > 0; i--) {
        *(a + i) = *(a + i - 1);
    }
    *a = last;
}

int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    int m,n=7;
    printf("原数组为:");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n请输入m:");
    scanf("%d", &m);
    m = m % n;
    for (int i = 0; i < m; i++) {
        r_s1(a, n);
    }
    printf("结果为:");
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
    return 0;
}