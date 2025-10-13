/*
闰年问题
    闰年定义：
    ①、普通年能被4整除；且不能被100整除的为闰年。（如2004年就是闰年，1901年不是闰年）
    ②、世纪年能被400整除的是闰年。(如2000年是闰年，1900年不是闰年)
*/

#include <stdio.h>

int isLeap(int y){
    return (y%4==0&&y%100!=0||y%400==0);
}

int main(){
    int y;
    printf("请输入年份:");
    scanf("%d",&y);
    if (isLeap(y)) printf("是闰年\n");
    else printf("不是闰年\n");
    return 0;
}