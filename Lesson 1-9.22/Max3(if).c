#include <stdio.h>

int max(int a, int b, int c) {
	if (a>b) {
		if (a>c) return a;
	} else if (b>c) return b;
	return c;
}

int main() {
	int a,b,c;
	printf("请输入三个数：");
	scanf("%d%d%d",&a,&b,&c);
	printf("Max=%d\n",max(a,b,c));
	return 0;
}
