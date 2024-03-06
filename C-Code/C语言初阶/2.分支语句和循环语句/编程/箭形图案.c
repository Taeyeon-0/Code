#include<stdio.h>
int main()
{
	int n = 0;
	int i = 0;
	int j = 0;
	while (scanf_s("%d", &n) != EOF)
	{
		//打印上半部分
		for (i = 0; i <= n; i++)
		{
			for (j = 0; j < 2 * n - (i * 2); j++)
			{
				printf(" ");
			}

			for (j = 0; j < i + 1; j++)
			{
				printf("*");
			}
			printf("\n");
		}
		//打印下半部分
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < 2 * (i + 1); j++)
			{
				printf(" ");
			}
			for (j = 0; j < n - i; j++)
			{
				printf("*");
			}
			printf("\n");
				
		}
	}
	return 0;
}