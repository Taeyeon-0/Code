#include<stdio.h>
//编写代码实现，模拟用户登录情景，并且只能登录三次。（只允许输入三次密码，如果密码正确则
//提示登录成，如果三次均输入错误，则退出程序。
int main()
{
	char arr[10] = " ";
	int i = 0;
	for (i = 0; i < 3; i++)
	{
		printf("请输入密码\n");
		scanf("%s", arr);
		if (strcmp(arr, "bit") == 0)
		{
			printf("密码正确\n");
		}
		else
		{
			if (i == 2)
			{
				printf("密码错误，退出\n");
				break;
			}
		}
	}
	return 0;
}