/*
约瑟夫环问题(Josephus Problem)是一个著名的数学问题，
描述了一群人围成一圈，
每隔固定人数就淘汰一个人，
直到最后剩下一个人的过程。
用指针模拟链表来解决这个问题。
*/

#include <stdio.h>
#define i 40

void ring(int a[],int people,int spacing) {
    int out=0,count=0,now=0;
    while(out<people) {
        if(a[now]==0) count++;
        if(count==spacing) {
            printf("%2d出局 ",now+1);
            a[now]=-1;
            out++;
            if(out%10==0) printf("\n");
            count=0;
        }
        now=(now+1)%people;
    }
}

int main() {
    // 0表示存活，-1表示死亡
    int a[i]={0};
    ring(a,i,3);
    return 0;
}