#include<stdio.h>
//有一个整数序列（可能有重复的整数），现删除指定的某一个整数，
//输出删除指定数字之后的序列，序列中未被删除数字的前后位置没有发生改变。
int main()
{
	int n = 0;
	scanf_s("%d", &n);
	int i = 0;
	int arr[50] = { 0 };
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &arr[i]);
	}
	//输入删除的数字
	int del = 0;
	scanf_s("%d", &del);

	//删除数组中的del数字
	//1 2 3 4 5 9   删除4   变成1 2 3 5 9
	int j = 0;
	for (i = 0; i < n; i++)
	{
		if (arr[i] != del)
		{
			arr[j++] = arr[i];
		}
	}

	for (i = 0; i < n - 1; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}