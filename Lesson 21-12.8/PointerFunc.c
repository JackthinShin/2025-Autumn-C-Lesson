/*
指针指向函数
*/

#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int main() {
    int (*p)(int, int); // 定义一个指向函数的指针
    p = max; // 将函数地址赋给指针
    printf("最大值是：%d\n", p(10, 20)); // 通过指针调用函数
    p = min;
    printf("最小值是：%d\n", p(10, 20));
    return 0;
}