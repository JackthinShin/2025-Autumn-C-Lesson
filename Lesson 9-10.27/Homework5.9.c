//Perfect Number ⼀个数如果恰好等于它的因⼦之和，这个数就称为“完数”
//1000000<含>以内的完数有:
//6     因子为:1,2,3
//28    因子为:1,2,4,7,14
//……

#include <stdio.h>
#include <time.h>
#define M 1000000

int isPerfect(int n){
    int i,sum=1;
    if(n==1) return 0;
    for(i=2;i*i<n;i++){
        if(n%i==0) sum+=i+n/i;
        if(sum>n) return 0;
    }
    if(i*i==n) sum+=i;
    return sum==n;
}

int main(){
    clock_t start,end;
    start=clock();
    int i,j,n=0;
    printf("%d(含)以内的完数有:\n",M);
    for(i=2;i<=M;i+=2){
        if(isPerfect(i)){
            printf("%d\t",i);
            n++;
            printf("因子为:1");
            for(j=2;j<=i/2;j++)
                if(i%j==0) printf(",%d",j);
            putchar('\n');
        }
    }
    printf("共%d个!\n",n);
    end=clock();
    printf("Time:%f\n",(double)(end-start)/CLOCKS_PER_SEC);
    return 0;
}