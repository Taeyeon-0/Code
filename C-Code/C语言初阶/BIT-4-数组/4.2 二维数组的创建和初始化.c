#include<stdio.h>
//1.二维数组的创建
//数组创建
int arr[3][4];
char arr[3][5];
double arr[2][4];


//2.二维数组的初始化
int arr[3][4] = { 1,2,3,4 };
int arr[3][4] = { {1,2},{4,5} };
int arr[][4] = { {2,3},{4,5} };//二维数组如果有初始化，行可以省略，列不能省略


//3.二维数组的使用
#include <stdio.h>
int main()
{
	int arr[3][4] = { 0 };
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		int j = 0;
		for (j = 0; j < 4; j++)
		{
			arr[i][j] = i * 4 + j;
		}
	}

	for (i = 0; i < 3; i++)
	{
		int j = 0;
		for (j = 0; j < 4; j++)
		{
			printf("%d ", arr[i][j]);
		}
	}
	return 0;
}


//4.二维数组在内存中的存储
int main()
{
	int arr[3][4];
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		int j = 0;
		for (j = 0; j < 4; j++)
		{
			printf("&arr[%d][%d] = %p\n", i, j, &arr[i][j]);
		}
	}
	return 0;
}
//二维数组在内存中也是连续存储的。
