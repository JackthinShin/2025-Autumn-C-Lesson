#include <stdio.h>
#include <stdlib.h>

// 这是另一个版本的斐波那契数列程序
int fib(int n) {
    if (n <= 1) {
        return n;
    }
    return fib(n - 1) + fib(n - 2);
}

int main() {
    int count;
    printf("Please input a number: ");
    scanf("%d", &count);
    
    for (int j = 0; j < count; j++) {
        printf("%d ", fib(j));
    }
    printf("\n");
    
    return 0;
}

