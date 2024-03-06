/*
思路：
两个循环进行控制
外层循环控制打印多少行
内部循环控制每行打印多少个表达式以及表达式内容，
比较简单，具体参考代码
*/
#include <stdio.h>
int main()
{
	int i = 0;
	//控制行数
	for (i = 1; i <= 9; i++)
	{
		//打印每一行内容，每行有i个表达式
		int j = 0;
		for (j = 1; j <= i; j++)
		{
			printf("%d*%d=%2d ", i, j, i * j);
		}
		printf("\n");
	}
	return 0;
}