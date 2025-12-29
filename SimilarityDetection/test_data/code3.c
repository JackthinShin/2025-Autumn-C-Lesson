#include <stdio.h>

// 完全不同的代码：计算阶乘
int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * factorial(n - 1);
}

int main() {
    int value;
    printf("Enter a number: ");
    scanf("%d", &value);
    
    int result = factorial(value);
    printf("Factorial is: %d\n", result);
    
    return 0;
}

