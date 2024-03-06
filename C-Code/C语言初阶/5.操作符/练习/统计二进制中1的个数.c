#include<stdio.h>
/* 方法1  正数负数都可以，但是效率不高
int count_bit(int n)
{
	int i = 0;
	int count = 0;
	for (i = 0; i < 32; i++)
	{
		if ((n >> i) & 1)
			count++;
		//if ((n & 1) == 1)
		//count++;
		//n >>= 1;
	}
	return count;
}


int main()
{
	int n = 0;
	scanf_s("%d", &n);  //15
	int num = count_bit(n);
	printf("%d\n", num);  //4
	return 0;
}
*/



/*方法2  逆序取余法  这种方法负数要当成无符号整数
int count_bit(unsigned int n)
{
	int i = 0;
	int count = 0;
	while (n)
	{
		if (n % 2)
			count++;
		n /= 2;
	}
	return count;
}


int main()
{
	int n = 0;
	scanf_s("%d", &n);  //-1
	int num = count_bit(n);
	printf("%d\n", num);    //32
	return 0;
}
*/


//  优化  效率最高
/*
n=11
n = n&(n-1)
1011 == n
1010 == n-1
1011&1010==1010

1010 == n
1001 == n-1
1010&1001==1000

1000 == n
0111 == n-1
1000&0111==0000

0000
*/

/* 优化代码
int count_bit(int n)
{
	int count = 0;
	while (n)
	{
		n = n & (n - 1);
		count++;
	}
	return count;
}


int main()
{
	int n = 0;
	scanf_s("%d", &n);  //15
	int num = count_bit(n);
	printf("%d\n", num);  //4
	return 0;
}
*/
