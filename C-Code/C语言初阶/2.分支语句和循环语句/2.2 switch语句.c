#include<stdio.h>
//2.2.1 switch语句
//举例
//int main()
//{
//	int day = 0;
//	scanf("%d", &day);
//	switch (day)
//	{
//	case 1:
//		printf("星期一\n");
//		break;
//	case 2:
//		printf("星期二\n");
//		break;
//	case 3:
//		printf("星期三\n");
//		break;
//	case 4:
//		printf("星期四\n");
//		break;
//	case 5:
//		printf("星期五\n");
//		break;
//	case 6:
//		printf("星期六\n");
//		break;
//	case 7:
//		printf("星期七\n");
//		break;
//	}
//	return 0;
//}


//需求输入1-5，输出的是"weekday"   输入6-7，输出"weekend"
//int main()
//{
//	int day = 0;
//	switch (day)
//	{
//	case 1:
//	case 2:
//	case 3:
//	case 4:
//	case 5:
//		printf("weekday\n");
//		break;
//	case 6:
//	case 7:
//		printf("weekend\n");
//		break;
//	}
//	return 0;
//}
//break语句的实际效果是把语句列表划分为不同的分支部分
//编程好习惯☆
//在最后一个case语句的后面加一条break语句(避免忘记添加break)


//2.2.2 default子句
//deafult子句的作用是用来提醒用户的输入信息有错误，警告，可以放在switch语句的任何位置
//当switch表达式的值并不匹配所有case标签的值时，这个default子句后面的语句就会执行。
//所以每个switch语句中只能出现一条default子句。
//编程好习惯☆
//在每个switch语句中都放一条default子句是个好习惯，甚至可以在后面再加一个break


//2.2.3 练习
int main()
{
	int n = 1;    //1 2 3
	int m = 2;    //3 4 5
	switch (n)
	{
	case 1:
		m++;
	case 2:
		n++;
	case 3:
		switch (n)
		{
			//switch允许嵌套使用
		case 1:
			n++;
		case 2:
			m++;
			n++;
			break;
		}
	case 4:
		m++;
		break;
	default:
		break;
	}
	printf("m=%d,n=%d\n", m, n);
	return 0;
}