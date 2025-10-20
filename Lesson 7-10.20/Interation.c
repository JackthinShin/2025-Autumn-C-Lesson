/*
迭代(Interation)程序设计 (初值，迭代公式，终止条件)
1)数列求和
2)Fibonacci数列
3)辗转相除(余)法 求最大公约数
4)二分迭代
5)牛顿迭代
*/

//数列求和 e.g. 1-1/2+3/4-5/8+7/16……
#include <stdio.h>
#define N 20

int main(){
    int sign=-1,nume=1,deno=2,n=1; //numerator分子 denominator分母
    double term,sum=1;
    while(n<=N){
        term=1.0*sign*nume/deno;
        sum+=term;
        n++;
        sign=-sign;
        nume+=2;
        deno*=2;
    }
    printf("%lf\n",sum);
    return 0;
}