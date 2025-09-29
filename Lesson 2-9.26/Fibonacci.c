#include <stdio.h>

void fib(int n, int a, int b) {
	printf("%d ",a+b);
	if(--n>0) fib(n,b,a+b);
}

int main() {
	int N;
	printf("请输入斐波那契数列项数");
	scanf("%d",&N);
	printf("1 1 ");
	fib(N,1,1);
	return 0;
}
