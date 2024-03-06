#include<stdio.h>
//1.数组指针的定义
/*
//整型指针 - 指向整型的指针 - 存放整型变量的地址
int* p;
//字符指针 - 指向字符的指针 - 存放的是字符变量的地址
char* p;
//数组指针 - 指向数组的指针 - 存放的是数组的地址
*/


/*
int main()
{
	int a = 10;
	int* p1 = &a;

	char ch = 'w';
	char* p2 = &ch;

	int arr[10] = { 1,2,3,4,5 };
	int(*pa)[10] = &arr;   //存放数组地址的数组指针pa，pa是数组指针变量
	//pa的类型是 -> int(*)[10]
	return 0;
}
*/


/*
int main()
{
	char arr[5];
	char(*p1)[5] = &arr;
	return 0;
}
*/


//2.&数组名和数组名的区别
/*
int main()
{
	int arr[10] = { 0 };
	printf("%p\n", arr);   //00AFFA44
	printf("%p\n", arr + 1);   //00AFFA48    加了4个字节
	printf("%p\n", &arr[0]);   //00AFFA44
	printf("%p\n", &arr[0] + 1);   //00AFFA48  加了4个字节
	printf("%p\n", &arr);   //00AFFA44
	printf("%p\n", &arr + 1);   //00AFFA6C   加了40个字节 跳过了整个数组
	return 0;
}
*/


/*数组名是数组首元素的地址
有两个例外：
1.sizeof(数组名)
2.&数组名
这两个都是整个数组
*/


//3.数组指针的使用
/*
void print1(int* arr, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", *(arr+i));
	}
	printf("\n");
}

void print2(int(*arr)[10], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", (*arr)[i]);  //*&arr == arr 这样使用很少
	}
	printf("\n");
}

void print3(int arr[3][5], int r, int c)
{
	int i = 0;
	for (i = 0; i < r; i++)
	{
		int j = 0;
		for (j = 0; j < c; j++)
		{
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
}

//二维数组的首元素就是二维数组的第一行
//arr是二维数组的数组名 数组名是数组首元素的地址
//arr就是第一行的地址
void print4(int(*p)[5], int r, int c)  //二维数组传参[5]代表一行五个元素 p加1直接跳过第一行的五个元素
{
	int i = 0;
	for (i = 0; i < r; i++)
	{
		int j = 0;
		for (j = 0; j < c; j++)
		{
			printf("%d ", *(*(p + i) + j));
			//printf("%d ", (*(p + i))[j]);
		}
		printf("\n");
	}
}

void test1()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	print1(arr, sz);
	print2(&arr, sz);  //很少用于一维数组
}

void test2()
{
	int arr[3][5] = { {1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7} };
	//print3(arr, 3, 5);
	print4(arr, 3, 5);
}
int main()
{
	//test1();
	test2();

	return 0;
}
*/

//学了指针数组和数组指针我们来一起回顾并看看下面代码的意思：
/*
int arr[5];
int* parr1[10];   //指针数组
int(*parr2)[10];   //数组指针
int(*parr3[10])[5];  //parr3是存放数组指针的数组
*/