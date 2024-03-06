#include"game.h"
/*
test.c  扫雷游戏的测试逻辑
game.h  游戏函数的声明
game.c  游戏函数的实现
*/


/*  游戏逻辑
 9*9的棋盘  需要 11*11的数组  防止数组越界
2个棋盘，一个放布置好的雷 ，一个放排查的地方
1.有两个数组，一个数组mine用来存放布置好的雷的信息，
另外一个数组show存放排查出来的雷的信息
2.mine数组初始化为'0'，布置雷的时候，改成'1'
show数组初始化为‘*’，排查雷后，具体位置改为数字字符，如‘3’
*/

void menu()
{
	printf("            1.play           \n");
	printf("            0.exit           \n");
}

void game()
{
	//设计两个数组存放信息
	char mine[ROWS][COLS] = { 0 };  //ROWS 防止数组越界
	char show[ROWS][COLS] = { 0 };
	//初始化棋盘
	//mine初始化为全‘0’
	//show初始化为全‘*’
	init_board(mine, ROWS, COLS, '0');
	init_board(show, ROWS, COLS, '*');
	//打印棋盘
	//display_board(mine, ROW, COL);  //打印只需要打印ROW COL  不需要ROWS 
	//display_board(show, ROW, COL); 
	//布置雷
	set_mine(mine, ROW, COL);
	//display_board(mine, ROW, COL);   //测试雷的位置
	display_board(show, ROW, COL);
	//排雷
    find_mine(mine, show, ROW, COL);   //mine数组放到show数组里
}

int main()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请选择：>");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择\n");
			break;
		}
	} while (input);
	return 0;
}