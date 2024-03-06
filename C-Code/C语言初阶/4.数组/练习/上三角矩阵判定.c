#include<stdio.h>
#define N 3
//KiKi想知道一个n阶方矩是否为上三角矩阵，请帮他编程判定。
//上三角矩阵即主对角线以下的元素都为0的矩阵，主对角线为从矩阵的左上角至右下角的连线。
int main()
{
	int arr[N][N];
	int i = 0;
	int j = 0;
	//输入
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			scanf_s("%d", &arr[i][j]);
		}
	}
	//判断
	int flag = 1;  //假设是上三角矩阵
	for (i = 0; i < N; i++)
	{
		for (j = 0; j<i; j++)   //下三角的判断是j<i的
		{
			if (arr[i][j] != 0)
			{
				flag = 0;
				// break;   //break无法完全跳出多层循环
				goto end;
			}
		}
	}
end:
	if (flag == 0)
		printf("NO\n");
	else
		printf("YES\n");
	return 0;
}