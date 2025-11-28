/*
变量的存储属性
(auto) int a
操作属性 变量名
register 寄存器
auto 动态(默认)
static 静态
for(int i=0;i<10;i++) 中的i只有在for循环中有效
有时为了速度会把变量放在寄存器中:
for(register int i=0;i<10;i++)  不建议使用
static int b; 存放在内存的静态存储区，初始化为0，在编译时创建，只能在本文件中使用
extern 作用域扩展到整个项目，可以在其他文件中引用
*/
#include <stdio.h>

int f(int a) {
    int b=2;
    static int c=3; // 静态变量只初始化一次，因此在第二次调用时c的值不会变回3
    b++;
    c++;
    return a+b+c;
}

int main() {
    int i,z;
    for(i=1;i<4;i++) {
        z=f(i);
        printf("%d\t", z);
    }
    printf("\n");
    return 0;
}