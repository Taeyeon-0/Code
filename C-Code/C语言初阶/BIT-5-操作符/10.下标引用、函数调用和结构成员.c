#include<stdio.h>
//1. 下标引用[]
/*
int main()
{
	int arr[10];//创建数组
	arr[9] = 10;//实用下标引用操作符。
	//[] 的两个操作数是arr和9。
	return 0;
}
*/


//2. () 函数调用操作符
/*
void test(int x, int y)
{

}

void test2()
{

}

int main()
{
	test(3, 4);   //() 函数调用操作符
	//操作数：test 3 4
	test2();
	//操作数就是函数名test2
	return 0;
}
*/


//3.访问一个结构的成员
/*
. 结构体.成员名
-> 结构体指针->成员名
*/

//书：书名 +定价
/*
struct Book
{
	char name[20];
	int price;
};

int main()
{
	struct Book sb = { "鹏哥C语言",55 };
	printf("%s %d\n", sb.name, sb.price);  //结构体变量.结构体成员名
	struct Book* ps = &sb;
	printf("%s %d\n", (*ps).name, (*ps).price);
	printf("%s %d\n", ps->name, ps->price);  //结构体指针->结构体成员名
	return 0;
}
*/