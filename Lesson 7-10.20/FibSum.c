/*
1+1/2+3/5+8/13+21/34+……
*/
#include <stdio.h>
#define N 20

int main(){
    double sum=1.0;
    int n=1,a=1,b=1;
    while(n<20){
        printf("%d/%d\n",a,b);
        int c=a+b;
        sum+=1.0*b/c;
        n++;
        a+=b;
        b+=a;
    }
    printf("%lf\n",sum);
    return 0;
}