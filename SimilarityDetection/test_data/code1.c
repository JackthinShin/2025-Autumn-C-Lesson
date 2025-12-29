#include <stdio.h>
#include <stdlib.h>

// 这是一个计算斐波那契数列的程序
int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int num;
    printf("请输入一个数字: ");
    scanf("%d", &num);
    
    for (int i = 0; i < num; i++) {
        printf("%d ", fibonacci(i));
    }
    printf("\n");
    
    return 0;
}

