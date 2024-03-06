#include<stdio.h>
int main()
{
	int money = 0;
	scanf_s("%d", &money);
	int total = money;   //总瓶数
	int empty = money;   //空瓶数
	while (empty >= 2)    
	{
		total += empty / 2;   //将空瓶数/2 得到新的瓶数
		empty = empty / 2 + empty % 2;   //剩下的空瓶数 = 如5 可以换2瓶可乐  余下1瓶就是3个空瓶  5/2+5%2==3
	}

    //第二种方法
    /*
    if (money != 0)
		total = 0;
	else
		total = 2 * money - 1;
    */
	printf("%d", total);
	return 0;
}