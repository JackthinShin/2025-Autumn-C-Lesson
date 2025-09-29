//2.8 请输入5个整数：1 2 3 4 5
//    最小值为：1
//    使用define延伸至N个数
#define N 5
#include <stdio.h>

int main(){
    int a,min;
    printf("请输入%d个数：",N);
    for(int i=0;i<N;i++){
        scanf("%d",&a);
        if (i==0) min=a;
        else if (min>a) min=a;
    }
    printf("Min=%d\n",min);
    return 0;
}