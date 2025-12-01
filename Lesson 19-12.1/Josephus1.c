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
    int out=0,count=0,now=0,prev=people-1;
    while(out<people) {
        count++;
        if(count==spacing) {
            printf("%2d出局 ",now+1);
            a[prev]=a[now];
            out++;
            if(out%10==0) printf("\n");
            count=0;
        }
        prev=now;
        now=a[now];
    }
}

int main() {
    // a[i]表示下一个活着的人的编号
    int a[i]={0};
    for(int j=0;j<i;j++) {
        a[j]=(j+1)%i;
    }
    ring(a,i,3);
    return 0;
}