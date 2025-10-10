#include <stdio.h>
#define N 10

int main() {
	int a,max=0;
	printf("请输入%d个数：",N);
	for(int i=0; i<N; i++) {
		scanf("%d",&a);
		if(a>max) max=a;
	}
	printf("Max=%d\n",max);
	return 0;
}
