//Greatest Common Divisor 最大公约数
//Least Common Multiple 最小公倍数
/*
请输入两个非负整数：0,5
最大公约数为5
最小公倍数为0
*/
#include <stdio.h>

int gcd(int u,int v){
    int r;
    while(v!=0){
        r=u%v;
        u=v;
        v=r;
    }
    return u;
}

int lcm(int u,int v){
    return u*v/gcd(u,v);
}

int main(){
    int u,v;
    scanf("%d%d",&u,&v);
    printf("gcd=%d\n",gcd(u,v));
    printf("lcm=%d\n",lcm(u,v));
    return 0;
}