#include <stdio.h>

int main() {
	int a,max=0;
	printf("请输入十个数：");
	for(int i=0; i<10; i++) {
		scanf("%d",&a);
		if(a>max) max=a;
	}
	printf("Max=%d\n",max);
	return 0;
}
