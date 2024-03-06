#include <stdio.h>
#include <stdlib.h>
//期中考试开始了，大家都想取得好成绩，争夺前五名。
//从键盘输入 n 个学生成绩，输出每组排在前五高的成绩。
int cmp_int(const void *e1, const void *e2)
{
	return *(int *)e1 - *(int *)e2;   //升序
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	int arr[n];
	int i = 0;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	//排序
	qsort(arr, n, sizeof(int), cmp_int);

	//打印
	for(i=n-1;i>=n-5;i--)
	{
		printf("%d",arr[i]);
	}
	return 0;
}