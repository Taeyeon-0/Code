#include <stdio.h>
/*
&&     逻辑与
||     逻辑或

*/

/*
int main()
{
	int a = 3;
	int b = 0;
	if (a && b)   //同时为真，则为真
	{
		printf("hehe\n");
	}

	if (a || b)
	{
		printf("hehe\n");
	}
	return 0;
}
*/


/*
int main()
{
	int age = 0;
	//18-36青年
	if (age >= 18 && age <= 36)
	{
		printf("青年\n");
	}


	int year = 2000;
	if (((year % 4 == 0) && (year % 4 != 0)) || (year % 400 == 0))
	{
		printf("是闰年\n");
	}
	return 0;
}
*/


//短路运算
/*
int main()
{
	int i = 0, a = 0, b = 2, c = 3, d = 4;
	i = a++ && ++b && d++;  //a++为假 后面就短路，  a=0+1=1
	//i = a++||++b||d++;
	printf("a = %d\n b = %d\n c = %d\nd = %d\n", a, b, c, d);  //1，2，3，4
	return 0;
}
*/
//程序输出的结果是什么？