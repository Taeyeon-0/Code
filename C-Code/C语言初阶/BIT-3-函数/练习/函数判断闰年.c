#include<stdio.h>
int Judge(int year)
{
	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}
int main()
{
	int year = 0;
	scanf("%d", &year);
	int x = Judge(year);
	if (x == 1)
	{
		printf("是闰年\n");
	}
	else
	{
		printf("不是闰年\n");
	}
	return 0;
}