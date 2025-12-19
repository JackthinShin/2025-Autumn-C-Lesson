/*
辛普森积分公式(Simpson's Rule)
通过将积分区间分成若干个小区间，利用抛物线来逼近曲线，从而求得定积分的近似值。
*/

#include <stdio.h>
#define N 1e7

double integral(double a, double b, double (*p)(double)) {
    double h = (b - a) / N; // 每个小区间的宽度
    double sum = p(a) + p(b); // 计算首尾两点的函数值之和

    for (int i = 1; i < N; i++) {
        double x = a + i * h;
        if (i % 2 == 0) {
            sum += 2 * p(x); // 偶数项乘以2
        } else {
            sum += 4 * p(x); // 奇数项乘以4
        }
    }

    sum *= h / 3; // 最终乘以h/3
    return sum;
}

double f1(double x) {
    return x + 1;
}

double f2(double x) {
    return x * x;
}

int main() {
    double (*fun)(double);
    fun = f1;
    printf("f1在[0,2]区间的积分近似值为：%.4f\n", integral(0, 2, fun));
    fun = f2;
    printf("f2在[0,2]区间的积分近似值为：%.4f\n", integral(0, 2, fun));
    return 0;
}