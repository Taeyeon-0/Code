#include<stdio.h>
//指针的地址占用字节都一样 32位4字节  64位8字节
/*
int main()
{
	int* pa;
	int* pc;
	float* pf;
	printf("%zu\n", sizeof(pa));  //8
	printf("%zu\n", sizeof(pc));  //8
	printf("%zu\n", sizeof(pf));  //8
	return 0;
}
*/


//1.指针的解引用
//·指针类型决定了指针进行解引用操作时候的权限
//char*的指针解引用访问1个字节  int*的指针解引用访问4个字节   double*的指针解引用访问8个字节

/*
int main()
{
	int a = 0x11223344;
	//int* pa = &a;
	//*pa = 0;   //改变4个字节的值
	char* pc = &a;
	*pc = 0;    //只会改变第1个字节
	return 0;
}
*/



//2.指针+-整数
/*
·指针类型决定了指针的步长(向前/向后 走一步多大字节)
 int* 指针+1，意思是跳过一个整型，也就是向后走4个字节
 char*指针+1，意思是跳过一个字符，也就是向后走1个字节
 double*指针+1，意思是跳过一个double，也就是向后走8个字节

 int main()
{
	int a = 0x11223344;
	int* pa = &a;
	char* pc = &a;
	printf("pa=%p\n", pa);   //pa=0000005CE4DBFB54
	printf("pc=%p\n", pc);   //pc=0000005CE4DBFB54

	printf("pa+1=%p\n", pa + 1);   //pa+1=0000005CE4DBFB58 加了4个字节
	printf("pc+1=%p\n", pc + 1);   //pc+1=0000005CE4DBFB55 加了1个字节

	return 0;
}
*/


/*指针方法赋值给数组
//写法1
int main()
{
	int arr[10] = { 0 };
	//1~10
	int* p = arr;
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		*p = i + 1;
		p++;
	}
	return 0;
}
*/

/*
//写法2
int main()
{
	int arr[10] = { 0 };
	//1~10
	int* p = arr;
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		*(p + i) = i + 1；
	}
	return 0;
}
*/
