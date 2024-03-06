#include<stdio.h>
//求Sn = a + aa + aaa + aaaa + aaaaa的前n项之和，其中a是一个数字，
int main()
{
	int a = 0;
	int n = 0;
	int i = 0;
	int sum = 0;
	int ret = 0;
	scanf_s("%d %d", &a, &n);
	for (i = 0; i < n; i++)
	{
		if (i == 0)
		{
			ret = a;
		}
		else
		{
			ret = ret * 10 + a;
		}
		sum += ret;
	}
	printf("%d", sum);
	return 0;
}