#include <stdio.h>

int max(int a, int b) {
	if(a>b)
		return a;
	else
		return b;
}

int main() {
	int a,b;
	printf("请输入两个数：");
	scanf("%d%d",&a,&b);
	printf("Max=%d\n",max(a,b));
	return 0;
}
