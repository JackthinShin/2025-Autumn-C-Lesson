//3.7 设圆半径……
//要求:
//  printf*5
//  #define PI 3.1415927
//  double r=1.5,h=3.0;
//  小数点后3位

#include <stdio.h>
#define PI 3.1415927

int main() {
    double r=1.5, h=3.0;
    printf("请输入圆的半径r、高h: ");
    scanf("%lf%lf", &r, &h);
    printf("圆周长：%.3f\n", 2*PI*r);
    printf("圆面积：%.3f\n", PI*r*r);
    printf("圆球表面积：%.3f\n", 4*PI*r*r);
    printf("圆球体积：%.3f\n", 4*PI*r*r*r/3.0);
    printf("圆柱体积：%.3f\n", PI*r*r*h);
    return 0;
}