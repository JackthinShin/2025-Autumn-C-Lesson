#include <stdio.h>

int Mul(int a, int b, int c) {
	return a*b*c;
}

int main() {
	int a, b, c;
	printf("请输入三个数：");
	scanf("%d%d%d",&a,&b,&c);
	printf("Mul=%d\n",Mul(a,b,c));
	return 0;
}
