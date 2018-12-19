#include <stdio.h>
#include <math.h>
double power(double a, int b)
{
	if (b<0)
	{
		a=1.0/a;
		b=-b;
	}
	double res=1;
	while (b>0)
	{
    	if (b%2==1) res*=a;
    	a*=a;
    	b/=2;
	}
	return res;
}
double power_rec (double a, int b)
{
	if (b==0) return 1;
	if (b>0)
	{
		if (b%2==0)  return power_rec(a,b/2)*power_rec(a,b/2);
		else return power_rec(a,b-1)*a;
	}
	else return 1/power_rec(a,-b);
}
int main()
{
	double a;
	int b;
	scanf("%lf%d", &a, &b);
	printf("%lf\n", power(a,b));
	printf("%lf\n", power_rec(a,b));
	printf("%lf", pow(a,b));
	return 0;
}
