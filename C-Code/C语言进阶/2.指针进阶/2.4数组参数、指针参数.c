#include<stdio.h>
//1.一维数组传参
/*
void test(int arr[])//ok?  √
{}
void test(int arr[10])//ok?  √
{}
void test(int* arr)//ok?  √
{}
void test2(int* arr[20])//ok?  √ 20也可以省略
{}
void test2(int** arr)//ok?   √
{}
int main()
{
	int arr[10] = { 0 };
	int* arr2[20] = { 0 };   //指针数组
	test(arr);
	test2(arr2);
}
*/


//2.二维数组传参
/*
void test(int arr[3][5])//ok？ √
{}
void test(int arr[][])//ok？ ×
{}
void test(int arr[][5])//ok？ √
{}
//总结：二维数组传参，函数形参的设计只能省略第一个[]的数字。
//因为对一个二维数组，可以不知道有多少行，但是必须知道一行多少元素。
//这样才方便运算。
void test(int* arr)//ok？  ×
{}
void test(int* arr[5])//ok？ ×
{}
void test(int(*arr)[5])//ok？ √
{}
void test(int** arr)//ok？ ×
{}
int main()
{
	int arr[3][5] = { 0 };
	test(arr);
}
*/


//3.一级指针传参
/*
void print(int* p, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d\n", *(p + i));
	}
}
int main()
{
	int arr[10] = { 1,2,3,4,5,6,7,8,9 };
	int* p = arr;
	int sz = sizeof(arr) / sizeof(arr[0]);
	//一级指针p，传给函数
	print(p, sz);
	return 0;
}

*/


//4.二级指针传参
/*
void test(int** ptr)
{
	printf("num = %d\n", **ptr);
}
int main()
{
	int n = 10;
	int* p = &n;
	int** pp = &p;
	test(pp);
	test(&p);
	return 0;
}
当函数的参数为二级指针的时候，可以接收什么参数？
void test(int **p)
{}

int** ptr = ;
test(ptr);   //ok;

int* p2 = ;
test(&p2);  //ok

int* arr[10];   //数组指针的数组名
test(arr);  //ok
*/
