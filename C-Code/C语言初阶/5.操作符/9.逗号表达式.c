#include<stdio.h>
//exp1, exp2, exp3, …expN
//逗号表达式，就是用逗号隔开的多个表达式。
//逗号表达式，从左向右依次执行。整个表达式的结果是最后一个表达式的结果。

//代码1
/*
int main()
{
	int a = 1;
	int b = 2;
	int c = (a > b, a = b + 10, a, b = a + 1);//逗号表达式
	printf("%d", c);  //13
	//c是多少？
	return 0;
}
*/



//代码2
//if (a = b + 1, c = a / 2, d > 0)


//代码3
/*
int main()
{
	int a = 0;
	a = get_val();
	count_val(a);
	while (a > 0)
	{
		//业务处理
		a = get_val();
		count_val(a);
	}
	//如果使用逗号表达式，改写：
	while (a = get_val(), count_val(a), a > 0)
	{
		//业务处理
	}

	return 0;
}

*/