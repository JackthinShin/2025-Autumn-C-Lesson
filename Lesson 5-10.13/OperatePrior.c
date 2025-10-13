#include <stdio.h>

int main(){
    int a=5;
    a+=a*=6;
    printf("%d\n",a);
    //优先级顺序
    //即：
    //a*=6
    //a+=a
    return 0;
}