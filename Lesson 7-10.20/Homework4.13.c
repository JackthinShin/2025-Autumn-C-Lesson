/*
2000-2100年之间的闰年有：
2000 2004 2008 ……       每行10个数据
……
共**个闰年
要求：输出无空行
int sy=2000,ty=2100;
*/

#include <stdio.h>

int isLeap(int i){
    return (i%4==0&&i%100!=0||i%400==0);
}

int main(){
    int sy=1900,ty=1981;
    int n=0;  //已输出的闰年的个数
    for(int i=sy;i<=ty;i++){
        if(isLeap(i)){
            printf("%d ",i);
            n++;
            if(n%10==0) putchar('\n');
        }
    }
    if(n%10!=0) putchar('\n');
    printf("共%d个闰年\n",n);
    return 0;
}