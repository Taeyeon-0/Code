#include<stdio.h>
//int main()
//{
//	int ch = 0;    //getchar的返回值为int
//	while ((ch = getchar()) != EOF)   //EOF的值为-1
//	{
//		putchar(ch);
//	}
//	return 0;
//}
//这里的代码适当的修改是可以用来清理缓冲区的

//
//int main()
//{
//	int ch = 0;
//	while ((ch = getchar()) != EOF)
//	{
//		if (ch < '0' || ch > '9')
//			continue;
//		putchar(ch);
//	}
//	return 0;
//}
//这个代码的作用是：只打印数字字符，跳过其他字符


//int main()
//{
//	char password[20] = { 0 };
//	printf("请输入密码:>");
//	scanf("%s", password);
//	//清理键盘缓冲区\n
//	int a = getchar();    //这样设计还不合理，因为scanf中空格也会直接跳出 比如scanf输入abc def 只有abc
//	printf("请确认密码Y/N：");
//	int ch = getchar();    //getchar会获取scanf后面的\n 放到ch里  就会确认失败
//	if (ch == 'Y')
//	{
//		printf("确认成功\n");
//	}
//	else
//	{
//		printf("确认失败\n");
//	}
//	return 0;
//}


int main()
{
	char password[20] = { 0 };
	printf("请输入密码:>");
	scanf("%s", password);
	while ((getchar()) != '\n')   //清理掉\n之前的缓冲区
	{
		;
	}
	printf("请确认密码Y/N：");
	int ch = getchar();    //getchar会获取scanf后面的\n 放到ch里  就会确认失败
	if (ch == 'Y')
	{
		printf("确认成功\n");
	}
	else
	{
		printf("确认失败\n");
	}
	return 0;
}