#include <stdio.h>
#define N 100000000

int a[N+1];

int main(){
    int i,j,count;
    for(i=3;i*i<N;i+=2){
        if(a[i]) continue;
        for(j=i*i;j<=N;j+=2*i)
            if(!a[j]) a[j]=1;
    }
    count=(N>2)?1:0;
    for(i=3;i<=N;i+=2)
        if(!a[i]) count++;
    printf("%d(含)以内的素数有%d个!\n",N,count);
    return 0;
}