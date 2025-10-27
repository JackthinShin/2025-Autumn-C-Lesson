/*
Input a and n:2,3
2+22+222=246
1<=a,n<=9
*/
#include <stdio.h>

int main(){
    printf("Input a and n:");
    int a,n;
    scanf("%d,%d",&a,&n);
    int sum=a,x=a;
    printf("%d",a);
    for(int i=1;i<n;i++){
        x=x*10+a;
        printf("+%d",x);
        sum+=x;
    }
    printf("=%d\n",sum);
    return 0;
}