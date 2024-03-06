#include<stdio.h>
void mul(int a)
{
	int i = 1;
	int j = 1;
	for (i = 1; i <= a; i++)
	{
		for (j = 1; j <= i; j++)
		{
			printf("%-2d*%2d = %-5d", j, i, i * j);
		}
		printf("\n");
	}
}


int main()
{
	int a = 0;
	scanf("%d", &a);
	mul(a);
	return 0;
}