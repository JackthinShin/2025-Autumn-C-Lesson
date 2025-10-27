#include <stdio.h>
#include <math.h>
#include <time.h>

// int isPrime(int n){
//     if(n<2) return 0;
//     for(int i=2;i<n;i++)
//         if(n%i==0) return 0;
//     return 1;
// }

// int isPrime(int n){
//     if(n<2) return 0;
//     for(int i=2;i*i<=n;i++)
//         if(n%i==0) return 0;
//     return 1;
// }

int isPrime(int n){
    if(n==2) return 1;
    else if(n<2||n%2==0) return 0;
    else{
        int up=(int)sqrt(n)+1;
        for(int i=3;i<=up;i+=2)
            if(n%i==0) return 0;
    }
    return 1;
}

int main(){
    clock_t start,end; 
    start=clock();
    int isPrime(int n);
    int n=10000000,i,m;
    m=(n>=2)?1:0;
    for(i=3;i<=n;i+=2)
        if(isPrime(i)) m++;
    printf("The total number of prime numbers no more than %d is %d\n",n,m);
    end=clock();
    printf("Time:%f\n",(double)(end-start)/CLOCKS_PER_SEC);
    return 0;
}