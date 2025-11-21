/*
n阶勒让德多项式P(n,x)
请输入n,x:1,1.5
P(1,1.5):1.500000
*/

#include <stdio.h>

double P(int n,double x) {
    if(n==0)
        return 1;
    else if(n==1)
        return x;
    else
        return ((2*n-1)*x*P(n-1,x)-(n-1)*P(n-2,x))/n;
}

int main() {
    int n;
    double x;
    printf("请输入n,x:");
    scanf("%d,%lf",&n,&x);
    printf("P(%d,%.1f):%.6f\n",n,x,P(n,x));
    return 0;
}