#include <stdio.h>
#include <time.h>
int irand (int t)
{
	int hash, prime=101, i;
	for (i=0; i<4; i++)
	{
		int byte=(t & 0xFF<<8*i);
		hash=(hash*256+byte)%prime;
	}
	return hash;
}
double frand (int t)
{
	long long hash;
	int i;
	for (i=0; i<4; i++)
	{
		long long byte=(t & 0xFF<<8*i);
		hash=(hash*256+byte)%100000000000ll;
	}
	return 1.0*hash/100000000000;
}
int main()
{
	int r;
	double R;
	r=irand(time(NULL)+clock());
	R=frand(time(NULL)+clock());
	printf("%d\n%.12f", r, R);
	return 0;
}
