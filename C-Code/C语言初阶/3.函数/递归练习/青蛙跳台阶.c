#include<stdio.h>
//一只青蛙一次跳上1级台阶，也可以跳上2级。求该青蛙跳上一个n级的台阶总共有多少种跳法
/*
可以采用逆向思维，跳上第7层台阶前一跳可以有两种跳法。
可以是从6层台阶跳一阶，还可以从5层台阶跳两阶。
同理，跳上第N层台阶前一跳也有两种跳法。
可以是从N - 1层台阶跳一阶，还可以从N - 2层台阶跳两阶
反推到第一跳，也是同理，要么跳一阶，要么跳两阶。
跳一阶，只有一种跳法。而跳两阶，有两种跳法。
*/
int Frog_jump(int x)
{
	if (x == 1)
		return 1;   //跳一阶，只有一种跳法
	if (x == 2)
		return 2;    //跳二阶，有两种跳法
	else
		return Frog_jump(x - 1) + Frog_jump(x - 2);
	//跳上第N级台阶有2种跳法，可以是N-1级台阶跳一阶
	//还可以从N-2级台阶跳两阶
}


int main()
{
	int num = 0;
	printf("请输入青蛙要跳到几层数：\n");
	scanf("%d", &num);
	int count = Frog_jump(num);
	printf("跳到%d层有%d种跳法！\n", num, count);
	return 0;
}