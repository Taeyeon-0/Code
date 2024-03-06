#include<stdio.h>
//1.联合类型的定义
//联合也是一种特殊的自定义类型
//这种类型定义的变量也包含一系列的成员，特征是这些成员公用同一块空间
/*
union Un
{
	char c;
	int i;
	double d;
};


int main()
{
	union Un un;
	printf("%p\n", &un);
	printf("%p\n", &(un.c));
	printf("%p\n", &(un.i));
	printf("%p\n", &(un.d));
	//地址相同
	printf("%d\n", sizeof(union Un));  //8个字节
	return 0;
}
*/

//一个数值，存储时需要的内存空间只要超过1个字节，就涉及顺序的问题
//0x 11 22 33 44
/*联合体求大小端
int check_sys()
{
	union
	{
		char c;
		int i;
	}u;

	u.i = 1;  //联合体公用一块空间 i的空间小端存储为 01 00 00 00
	return u.c;  //return返回 c  c为1个字节 就是1  如果是大端返回0
}

int main()
{
	int ret = check_sys;
	if (ret == 1)
		printf("小端\n");
	else
		printf("大端\n");
}
*/

//特点：联合的成员是共用同一块内存空间的，这样一个联合变量的大小，至少是最大成员的大小（因为联合至少得有能力保存最大的那个成员）。

//2.联合体的大小计算
//·联合的大小至少是最大成员的大小。
//·当最大成员大小不是最大对齐数的整数倍的时候，就要对齐到最大对齐数的整数倍。
/*
union Un
{
	char arr[5];  //5 对齐数为1
	int i;  //4
};

union Un1
{
	short s[7]; //14
	int i;  //4
};

int main()
{
	printf("%zu\n", sizeof(union Un));  //4的倍数为8
	printf("%zu\n", sizeof(union Un1));  //16
	return 0;
}
*/
