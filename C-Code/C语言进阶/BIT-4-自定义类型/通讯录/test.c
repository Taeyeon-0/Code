#include"contact.h"
//test.c - 测试通讯录
//100个人的信息
//每个人的信息  姓名 性别 电话等等
//1.增加联系人
//2.删除指定联系人
//3.修改指定联系人
//4.查找指定联系人
//5.排序
//6.现实通讯录的信息
void menu()
{
	printf("                         \n");
	printf("    1.`add      2.del     \n");
	printf("    3.search   4.modify  \n");
	printf("    5.show     6.sort    \n");
	printf("    0.exit               \n");
	printf("                         \n");
	printf("                         \n");
}

enum
{
	Exit,
	add,
	del,
	search,
	modify,
	show,
	sort
};

int main()
{
	int input = 0;
	//创建通讯录
	struct Contact con;
	//初始化通讯录
	InitContact(&con);
	do
	{
		menu();
		printf("请选择>:");
		scanf("%d", &input);
		switch (input)
		{
		case add:
			AddContact(&con);
			break;
		case del:
			DelContact(&con);
			break;
		case search:
			SearchContact(&con);
			break;
		case modify:
			ModifyContact(&con);
			break;
		case show:
			ShowContact(&con);
			break;
		case sort:
			SortContact(&con);
			break;
		case Exit:
			SaveContact(&con);
			printf("退出通讯录\n");
			DestroyContact(&con);
			break;
		default:
			printf("选择错误\n");
			break;
		}
	} while (input);
	return 0;
}


//需求：通讯录退出后，之前保存的信息不能丢，当下次重新运行通讯里的时候，还能看到上次保存的信息

//分析：退出的时候，把数据保存到文件中，当下一次运行的时候，早从文件中加载信息就可以了