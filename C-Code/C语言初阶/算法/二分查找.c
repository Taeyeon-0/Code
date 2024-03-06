#include<stdio.h>
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int left = 0;
	int right = sizeof(arr) / sizeof(arr[0]) - 1;
	int key = 0;
	int mid = 0;
	printf("请输入要找的数\n");
	scanf("%d", &key);

	//二分查找
	while (left <= right)
	{
		mid = left + (right - left) / 2;   //不会越界  left+right可能超过数组总长度  会溢出
		if (key < arr[mid])
		{
			right = mid - 1;
		}
		else if (key > arr[mid])
		{
			left = mid + 1;
		}
		else
		{
			break;
		}
	}

	if (left <= right)
	{
		printf("找到了，下标为%d\n", mid);
	}
	else
	{
		printf("找不到\n");
	}
	return 0;
}
