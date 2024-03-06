#include<stdio.h>
int Digitsum(int n)   //1729
{
	if (n < 10)
	{
		return n;
	}
	else
	{
		return n % 10 + Digitsum(n / 10);
	}
}


int main()
{
	int n = 0;
	scanf("%d", &n);
	int sum = Digitsum(n);
	printf("%d", sum);
	return 0;
}