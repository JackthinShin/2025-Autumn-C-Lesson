//Fibonacci 
//1 1 2 3 5 8 13 21 ……
//输出Fibonacci数列的第N项

#include <stdio.h>
#define N 40

int main(){
    int fib,fib1,fib2,n=2;  //fib 当前月兔子数 fib1 前一个月兔子数 fib2 前两个月兔子数
    fib1=fib2=1;
    if(N<3){
        printf("1\n");
    }
    while(n<N){
        fib=fib1+fib2;
        n++;
        fib2=fib1;
        fib1=fib;
    }
    printf("%d\n",fib);
    return 0;
}