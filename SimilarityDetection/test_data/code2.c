#include <stdio.h>
#include <math.h>

/* 计算斐波那契数列的函数 */
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int number;
    printf("请输入一个数字: ");
    scanf("%d", &number);
    
    for (int i = 0; i < number; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
    
    return 0;
}

