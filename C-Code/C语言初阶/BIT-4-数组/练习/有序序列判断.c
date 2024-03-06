#include<stdio.h>
/*
#define N 5
int main()
{
	int arr[5] = { 0 };
	int i = 0;
	for(i = 0; i < N; i++)
	{
		scanf_s("%d", &arr[i]);
	}
	int flag1 = 1;
	for (i = 0; i < N; i++)
	{
		if ((i + 1) < N)
		{
			if (arr[i] >= arr[i + 1])
			{
				flag1 = 1;
			}
			else
			{
				flag1 = 0;
				break;
			}
		}
	}

	int flag2 = 1;
	for (i = 0; i < N; i++)
	{
		if ((i + 1) < N)
		{
			if (arr[i] <= arr[i + 1])
			{
				flag2 = 1;
			}
			else
			{
				flag2 = 0;
				break;
			}
		}
	}

	if (flag1 == 1 || flag2 == 1)
		printf("sorted");
	else
		printf("unsorted");
	return 0;
}*/


//优化
int main()
{
	int n = 0;
	int arr[50] = { 0 };
	scanf_s("%d", &n);
	int i = 0;
	int flag1 = 0;//升序
	int flag2 = 0;//降序
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &arr[i]);
		if (i > 0)
		{
			if (arr[i] > arr[i - 1])
				flag1 = 1;
			else if(arr[i]<arr[i-1])
				flag2 = 1;
			//如果相等则不操作
		}
	}
	if (flag1 + flag2 <= 1)  //flag1+flag2如果等于0  则五个数字都是一样的
		printf("sorted\n");
	else
		printf("unsorted\n");
	return 0;
}