/*
指针Pointer
*/
#include <stdio.h>

int main() {
    int *p;                 // p是一个指向int类型数据的指针变量,p是int *类型
    int a=3,b;
    b=a+2;
    p=&a;                   // &取变量a的地址赋值给指针变量p
    b=*p+10;                // 通过指针变量p取a的值加10赋值给b,此时b=13
    p=&b;                   // 现在p指向变量b
    (*p)++;                 // 通过指针变量p取b的值加1赋值给b,此时b=14
    int *p1=p;              // p1也是一个指向int类型数据的指针变量,并且指向b
    *p1=a+*p;               // 通过指针变量p1取b的值与a相加赋值给b,此时b=17
    printf("%d\n", *p1);    // 输出b的值17
    scanf("%d", p1);        // 输入一个整数赋值给b
    // 一维数组
    int arr[5] = {1, 2, 3, 4, 5};
    // int *p = &arr[0];    // p指向数组arr的首元素
    int *p2 = arr;          // p2指向数组arr的首元素
    for (int i = 0; i < 5; i++) {
        printf("%d ", *(p2 + i)); // 通过指针访问数组元素
    }
    return 0;
}