#include<stdio.h>
/*
//函数指针
int(*pf)(int, int);
//函数指针数组
int(*pfArr[4])(int, int);  
//整型指针
int* p;
//整型指针数组
int* arr[5];
*/


/*
int Add(int x, int y)
{
	return x + y;
}

int Sub(int x, int y)
{
	return x - y;
}

int main()
{
	//函数指针数组
	//可以存放多个参数相同返回类型相同的函数的地址
	int (*pfArr[2])(int, int) = { Add,Sub };
	int ret = pfArr[0](2, 3);
	printf("%d\n", ret);
	ret = pfArr[1](2, 3);
	printf("%d\n", ret);
	return 0;
}
*/


//写一个计算器
//加、减、乘、除
/*

*/
int Add(int x, int y)
{
	return x + y;
}

int Sub(int x, int y)
{
	return x - y;
}

int Mul(int x, int y)
{
	return x * y;
}

int Div(int x, int y)
{
	return x / y;
}

void menu()
{
	printf("                          \n");
	printf("       1.add  2.sub       \n");
	printf("       3.mul  4.div       \n");
	printf("       0.exit             \n");
	printf("                          \n");
}

int main()
{
	int input = 0;
	int x = 0;
	int y = 0;
	int ret = 0;
	//函数指针数组 - 转移表
	int (*pfArr[])(int, int) = { 0,Add,Sub,Mul,Div };  //下面选择1对应加法 所以第0个不能是Add 用0代替
	do
	{
		menu();
		printf("请选择:>");
		scanf_s("%d", &input);
		printf("请输入两个操作数;>");
		scanf_s("%d %d", &x, &y);
		if (input == 0)
		{
			printf("推出计算器\n");
			break;
		}

		if (input >= 1 && input <= 4)
		{
			ret = pfArr[input](x, y);
			printf("%d", ret);
		}
	
	} while (input);
	return 0;
}