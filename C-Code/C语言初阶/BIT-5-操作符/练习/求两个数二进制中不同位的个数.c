#include<stdio.h>
/*
编程实现：两个int（32位）整数m和n的二进制表达中，有多少个位(bit)不同？
输入例子:
1999 2299
输出例子:7
*/


/*方法1  效率低
int main()
{
	int m = 0;
	int n = 0;
	int count = 0;
	scanf_s("%d %d", &m, &n);
	int i = 0;
	for (i = 0; i < 32; i++)
	{
		if(((m>>i)&1)!=((n>>i)&1))
			count++;
	}
	printf("%d", count);
	return 0;
}
*/


//异或  不同为1
/*
int count_diff_bit(int m, int n)
{
	int ret = m ^ n;  //异或 有多少1就是有多少不同的位  在求二进制1的个数
	int count = 0;
	while (ret)
	{
		ret = ret & (ret - 1);
		count++;
	}
	return count;
}

int main()
{
	int m = 0;
	int n = 0;
	int count = 0;
	scanf_s("%d %d", &m, &n);
	count = count_diff_bit(m, n);
	printf("%d", count);
	return 0;
}
*/
