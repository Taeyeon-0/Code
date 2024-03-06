#include<stdio.h>
//1.C语言中有哪些数据类型？
// char - 字符数据类型
// short - 短整型
// int - 整形
// long - 长整型
// long long - 更长的整形
// float - 单精度浮点数
// double - 双精度浮点数
// C语言中有没有字符串类型    -  答：没有！！


//2.每种类型的大小是多少？
// VS中的数据类型是以下， 但是不同的编译器 有不同的值
int main()
{
	printf("%zd\n", sizeof(char));   //1
	printf("%zd\n", sizeof(short));  //2
	printf("%zd\n", sizeof(int));    //4
	printf("%zd\n", sizeof(long));   //4
	printf("%zd\n", sizeof(long long));   //8
	printf("%zd\n", sizeof(float));    //4
	printf("%zd\n", sizeof(double));   //8
	printf("%zd\n", sizeof(long double));    //8

	//类型的使用定义
	char ch = 'w';
	int weight = 120;
	int salary = 20000;
	return 0;
}
// sizeof是关键字 它的输出格式是%zd
