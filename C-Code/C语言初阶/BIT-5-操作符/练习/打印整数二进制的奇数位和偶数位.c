#include<stdio.h>
//获取一个整数二进制序列中所有的偶数位和奇数位，分别打印出二进制序列
int main()
{
	int n = 0;
	scanf_s("%d", &n);
	int i = 0;
	//奇数为
	for (i = 30; i >= 0; i -= 2) //第31位到第1位
	{
		printf("%d", (n >> i) & 1);   //任何数&上1  等于其本身的二进制数
	}

	printf("\n");

	//偶数位
	for (i = 31; i >= 1; i -= 2) //第32位到第2位
	{
		printf("(n >> i) & 1");
	}

	printf("\n");

	return 0;

}