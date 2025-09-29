#include <stdio.h>

int main() {
	int N,a,max=0;
	printf("请输入数的个数：");
	scanf("%d",&N);
	printf("请输入%d个数",N);
	int i=0;
	while(i<N) {
		scanf("%d",&a);
		if (a>max) {
			max=a;
		}
		i++;
	}
	printf("Max=%d",max);
	return 0;
}
