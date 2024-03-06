#include<stdio.h>
/*
enum Day
{
	//枚举的可能取值
	Mon,
	Tues,
	Wed,
	Thur,
	Fri,
	Sat,
	Sun
};

struct Stu
{
	char name[20];  //成员变量
	int age;
};
*/


//1.枚举的定义和使用
/*
enum Color
{
	//枚举的可能取值
	//每一个可能的取值是常量
	Red,  //Red = 5 Red不能该，但是可以赋值  后面的值就变成了 6  7
	Green,
	Blue
	//Red = 5
	//Red = 9
	//Red = 10
};

int main()
{
	enum Color color = Blue;
	//enum Color color = 5;   //C语言支持， C++会有警告
	//Red = 2;   //常量不可修改
	int num = Red;
	printf("%d\n", num);    //0
	printf("%d\n", Red);    //0
	printf("%d\n", Green);  //1
	printf("%d\n", Blue);   //2
	int sum = Red + Blue;   //可以相加，但是有些编译器不支持
	printf("%d\n", sum);      //2
	printf("%d\n", sizeof(enum Color));  //VS中为4
	return 0;
}
*/


//2.枚举的优点
/*
#define Red 5
#define Green 7
#define Blue 10
//define预处理后define命令就消失了 替换成了数字 ，不方便调试
int main()
{
	int num = Red;
	return 0;
}
*/

//1.增加代码的可读性和可维护性
//2.和#define定义的标识符比较枚举有类型检查，更加严谨
//3.便于调试
//4.使用方便，一次可以定义多个常量
//5.防止命名污染(封装)

