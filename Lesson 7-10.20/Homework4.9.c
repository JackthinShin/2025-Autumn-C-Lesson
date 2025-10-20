/*
请输入一个非负整数：1234567890
逆序为：0987654321
它是一个10位数
各个数字为：1 2 3 4 5 6 7 8 9 0
要求：不使用数组，不使用long long，只能使用两个一重循环，可处理0
*/
#include <stdio.h>

int main(){
    int t,a,bit=0,weight=0;
    printf("请输入一个非负整数：");
    scanf("%d",&a);
    t=a;
    printf("逆序为：");
    do{
        printf("%d",t%10);
        bit++;
        if(weight==0) weight=1;
        else weight*=10;
        t/=10;
    } while(t>0);
    putchar('\n');
    printf("它是一个%d位数\n",bit);
    printf("各个数字为：");
    while(weight>0){
        printf("%d ",(a/weight)%10);
        weight/=10;
    }
    putchar('\n');
    return 0;
}