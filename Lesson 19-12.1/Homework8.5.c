/*
请输入人数<1-100>
请输入报数<1-10>
离开顺序为：
*/

#include <stdio.h>

void ring(int a[],int people,int spacing) {
    int out=0,count=0,now=0,prev=people-1;
    while(out<people) {
        count++;
        if(count==spacing) {
            printf("%2d ",now+1);
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
    int i,spacing,a[100]={0};
    printf("请输入人数<1-100>:");
    scanf("%d",&i);
    printf("请输入报数<1-10>:");
    scanf("%d",&spacing);
    printf("离开顺序为：\n");
    for(int j=0;j<i;j++) {
        a[j]=(j+1)%i;
    }
    ring(a,i,spacing);
    return 0;
}