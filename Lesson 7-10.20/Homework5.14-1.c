//root=2.000000
//小数点后六位
//二分迭代
#include <stdio.h>
#define E 1e-7

double f(double x){
    return 2*x*x*x-4*x*x+3*x-6;
}

double f1(double x){
    return 6*x*x-8*x+3;
}