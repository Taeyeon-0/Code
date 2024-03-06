#include<stdio.h>
int main()
{
	int n = 0;
	int i = 0;
	int j = 0;
	while (scanf_s("%d", &n) != EOF)
	{
		//输入第一行
		for (i = 0; i < n; i++)
		{
			printf("* ");
		}
		printf("\n");

		for (i = 0; i < n - 2; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (j == 0 || j == n - 1)
					printf("* ");
				else
					printf("  ");
			}
			printf("\n");
		}
		//输入最后一行
		for (i = 0; i < n; i++)
		{
			printf("* ");
		}
		printf("\n");
	}
	return 0;
}