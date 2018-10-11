#include <stdio.h>
int main()
{
	char c='A';
	while (c<='Z')
	{
		printf("%c  %d\n", c, c);
		c++;
	}
	c='a';
	while (c<='z')
	{
		printf("%c  %d\n", c, c);
		c++;
	}
	c=' ';
	printf("' '  %d\n", c);
	c='\n';
	printf("\\n  %d\n", c);
	return 0;
}
