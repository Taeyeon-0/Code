/*
思路：
1. 采用循环的方式输入一个数组
2. 使用max标记数组中的最大值，采用循环的方式依次获取数组中的每个元素，与max进行比较，如果arr[i]大于    max，更新max标记的最大值，数组遍历结束后，max中保存的即为数组中的最大值。
*/
int main()
{
	int arr[10] = { 0 };
	int i = 0;
	int max = 0;

	for (i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
	}
	//
	max = arr[0];
	for (i = 1; i < 10; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	printf("max = %d\n", max);
	return 0;
}