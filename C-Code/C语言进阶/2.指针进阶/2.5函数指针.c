#include<stdio.h>
/*
int Add(int x, int y)
{
	return x + y;
}

int main()
{
	int (*pf)(int x, int y) = Add;  //函数指针的定义
	//int sum = (*pf)(3, 5);  (*)可以省略   Add == pf
	int sum = pf(3, 5);
	printf("%d\n", sum);   //8
	int arr[10] = { 0 };
	printf("%p\n", &arr);  //取出数组的地址 - 010FF8A8
	printf("%p\n", Add);   //004913B6
	printf("%p\n", &Add);   //004913B6
	//对于函数来说Add和&Add是相同的 没有区别 都是函数的地址
	return 0;
}
*/


//练习
/*
int test(const char* str, double d)
{

}

int main()
{
	//int (*pt)(const char*, double) = &test;
	int (*pt)(const char* str, double d) = &test;
	return 0;
}
*/


//分析两个代码
/*
typedef unsigned int uint;
int main()
{
	//代码1
	//0 - int
	//(void (*p)())0 - 把0当做一个函数的地址
	(*(void (*)())0)();
	//把0直接转换成一个  void(*)()的函数指针，然后去调用0地址的函数
	//代码2
	typedef void(*pf_t)(int);   //pf_t是一个类型 放到*后面
	//void (*signal(int, void(*)(int)))(int);  //不易阅读的代码
	pf_t signal(int, pf_t);  //改写
	//上述代码是一次函数声明
	//声明的函数叫signal
	//函数的第一个参数是int类型的
	//函数的第二个参数是函数指针类型，该函数指针指向的函数参数是int 返回类型是void
	//signal函数的返回类型也是一个函数指针类型，该函数指针指向的函数参数是int 返回类型是void
	return 0;
}
*/

