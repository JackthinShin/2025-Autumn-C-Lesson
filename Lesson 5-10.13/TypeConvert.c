//Type Convert
//类型转换
//1 强制(显式)
//2 隐式
//   2.1  算术表达式
//   2.2  赋值(以左值为准)
//由低向高(简略)
//char,short->int->long->float->double

#include <stdio.h>

int main(){
    float a=3.7f;
    int b;
    b=(int)a+4;
    // (int)为向零取整
    printf("%d\n",b);

    printf("%f\n",3/2*4.0+('A'-'B')%2);

    return 0;
}