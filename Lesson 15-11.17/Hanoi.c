/*
汉诺塔问题
算法描述:
将n层汉诺塔从柱子x借助柱子y移动到柱子z
1.当n=1时,直接将x上的盘子移动到z上
2.当n>1时,将n-1层从x借助z移动到y上,将第n层从x移动到z上,再将n-1层从y借助x移动到z上
输入格式:
请输入汉诺塔的层数: 3
输出格式:
A-->C
A-->B
C-->B
A-->C
B-->A
B-->C
A-->C
*/

#include <stdio.h> 

void move(char x,char y) {
    printf("%c-->%c\n",x,y);
}

void hanoi(int n,char x,char y,char z) {
    if(n==1)
        move(x,z);
    else {
        hanoi(n-1,x,z,y);
        move(x,z);
        hanoi(n-1,y,x,z);
    }
}

int main() {
    int n;
    printf("请输入汉诺塔的层数: ");
    scanf("%d",&n);
    hanoi(n,'A','B','C');
    return 0;
}