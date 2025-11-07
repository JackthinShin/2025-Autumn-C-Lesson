//6.1
//1s内
//100000000(含)以内的素数有5761455个
//1(含)以内的素数有0个
#include <stdio.h>
#include <time.h>
#define N 1

int a[N+1];

int main(){
    clock_t start,end;
    start=clock();
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
    end=clock();
    printf("Time:%f\n",(double)(end-start)/CLOCKS_PER_SEC);
    return 0;
}