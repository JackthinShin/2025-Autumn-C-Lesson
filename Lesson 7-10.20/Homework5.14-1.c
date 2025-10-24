//root=2.000000
//小数点后六位
//牛顿迭代
#include <stdio.h>
#define E 1e-7

double f(double x){
    return 2*x*x*x-4*x*x+3*x-2;
}

double f1(double x){
    return 6*x*x-8*x+3;
}

double mabs(double m){
    if(m<0) return -m;
    return m;
}

int main(){
    double a=1.5,b;
    b=a-f(a)/f1(a);
    while(mabs(a-b)>E){
        a=b;
        b=a-f(a)/f1(a);
    }
    printf("root=%lf\n",b);
    return 0;
}