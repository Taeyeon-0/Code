#include<stdio.h>
int bin_search(int arr[], int left, int right, int key)
{
	int mid = 0;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (arr[mid] > key)
		{
			right = mid - 1;
		}
		else if (arr[mid] < key)
		{
			left = mid + 1;
		}
		else
			return mid;//找到了，返回下标
	}
	return -1;//找不到
}


int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int left = 0;
	int right = sizeof(arr) / sizeof(arr[0]) - 1;
	int key = 0;
	scanf("%d", &key);
	int x = bin_search(arr, left, right, key);
	if (x != -1)
	{
		printf("找到了，下标是：%d", x);
	}
	else
	{
		printf("找不到\n");
	}
	return 0;
}
