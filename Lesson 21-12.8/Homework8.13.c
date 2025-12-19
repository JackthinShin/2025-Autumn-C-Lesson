/*
两种方法求定积分，矩形法，梯形法
sin cos exp
示例：
1.sin(x)  2.cos(x)  3.exp(x)+1  0.exit
Please choose one: 1
Please input the lower and the upper: 0,1
result=0.459698
重复直到exit
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define N 1E7

double f1(double x) {
    return sin(x);
}

double f2(double x) {
    return cos(x);
}

double f3(double x) {
    return exp(x) + 1;
}

double integrate_rectangle(double (*f)(double), double a, double b) {
    double h = (b - a) / N;
    double sum = 0.0;
    for (int i = 0; i < N; i++) {
        sum += f(a + i * h);
    }
    return sum * h;
}

double integrate_trapezoid(double (*f)(double), double a, double b) {
    double h = (b - a) / N;
    double sum = (f(a) + f(b)) / 2.0;
    for (int i = 1; i < N; i++) {
        sum += f(a + i * h);
    }
    return sum * h;
}

int main() {
    int choice;
    double a, b, result;
    double f1(double), f2(double), f3(double);
    double (*p)(double);
    while(1) {
        printf("1.sin(x)  2.cos(x)  3.exp(x)+1  0.exit\nPlease choose one: ");
        scanf("%d", &choice);
        if (choice == 0) {
            break;
        }
        switch (choice) {
            case 1:
                p = f1;
                break;
            case 2:
                p = f2;
                break;
            case 3:
                p = f3;
                break;
            case 0:
                exit(0);
        }
        printf("Please input the lower and the upper: ");
        scanf("%lf,%lf", &a, &b);
        // result = integrate_rectangle(p, a, b);
        result = integrate_trapezoid(p, a, b);
        printf("result=%.6f\n", result);
    }
    return 0;
}