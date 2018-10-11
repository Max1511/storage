#include <stdio.h>
int main()
{
	const int n=90;
	long long N[1000];	
	N[0]=1;
	N[1]=1;
	if (n==1)
	{
		printf("1");
		return 0;
	}
	if (n==2)
	{
		printf("1\n1");
		return 0;
	}
	printf("1\n1\n");
	int i;
	for (i=2; i<n; i++)
	{
		N[i]=N[i-1]+N[i-2];
		printf("%I64d\n", N[i]);
	}
	return 0;
}
