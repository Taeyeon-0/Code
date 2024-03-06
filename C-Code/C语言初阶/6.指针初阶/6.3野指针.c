#include<stdio.h>
// 概念： 野指针就是指针指向的位置是不可知的（随机的、不正确的、没有明确限制的）

//1.野指针成因
//·指针未初始化
/*
int main()
{
	int* p;       //局部变量指针未初始化，默认为随机值 p就是野指针
	*p = 20;
	return 0;
}
*/


//·指针越界访问
/*
int main()
{
	int arr[10] = { 0 };
	int i = 0;
	int sz = sizeof(arr) / sizeof(arr[0]);
	int* p = arr;
	for (i = 0; i <= sz; i++)    //指针越界 sz
	{
	    //当指针指向的范围超出数组arr的范围时，p就是野指针
		*p = i;
		p++;
	}
}
*/


//·指针指向的空间释放
/*
int* test()
{
	int num = 100;
	return &num;
}

int main()
{
	int* p = test();
	*p = 200;   //野指针，指向的地址已经释放
	return 0;
}
*/


//2.如何避免野指针
/*
1. 指针初始化
int main()
{
	int a = 10;
	int* pa = &a;   //明确初始化
	int* p = NULL;   //NULL是0  NULL就是为了初始化指针的
	return 0;
}

2. 小心指针越界

3. 指针指向空间释放，及时置NULL     
//动态内存分配  申请空间int *p = malloc(40)
//释放空间  free(p)  p=NULL

4. 避免返回局部变量的地址    -  避免返回栈空间的地址

5. 指针使用之前检查有效性
int main()
{
	int* p = NULL;
	if (p != NULL)   //p等于有效指针的时候才使用
	{
		printf("%d\n", *p);
	}
	return 0;
}
*/


