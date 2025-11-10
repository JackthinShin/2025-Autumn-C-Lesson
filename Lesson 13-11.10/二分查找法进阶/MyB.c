#include<stdio.h>

int finish(int num,int n,int k)
{
	int sum=0,flag=0;
	while(num>0)
	{
		sum+=num;
		num/=k;
	}
	if(sum>=n) flag=1;
	return(flag);
}

int bisearch(int n,int k)
{
	int mid,bot=k,top=n;
	while(top-bot>1)
	{
		mid=(bot+top)/2;
		if(finish(mid,n,k)) 
			top=mid;
		else
			bot=mid;
	}
	return(top);
}

int main()
{
	int n,k,v;
	while(1)
	{
		scanf("%d%d",&n,&k);
		if(n==0) break;
		if(n<=k) v=n;
		else if(n==k+1) v=k;
		else v=bisearch(n,k);
		printf("%d\n",v);
	}
	return(0);
}