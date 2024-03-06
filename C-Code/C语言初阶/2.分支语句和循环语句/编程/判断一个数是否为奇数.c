#include<stdio.h>
int main()
{
	int num = 0;
	scanf("%d", &num);
	if (num % 2 == 1)
	{
		printf("是奇数\n");
	}
	else
	{
		printf("不是奇数\n");
	}
	return 0;
}