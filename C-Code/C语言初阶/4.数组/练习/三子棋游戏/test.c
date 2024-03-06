#include"game.h"
#include<stdlib.h>
#include<time.h>
//test.c 测试三子棋游戏
//game.h  三子棋游戏的函数声明
//game.c  游戏函数的实现
void menu()
{
	printf("                   \n");
	printf("      1.play       \n");
	printf("      0.exit       \n");
	printf("                   \n");
}

void game()
{
	char ret;
	//数据的存储需要一个3*3的二维数组
	char board[ROW][COL] = { 0 };
	//初始化函数
	Initboard(board, ROW, COL);
	//打印棋盘
	display_board(board, ROW, COL);
	
	while (1)
	{
		//玩家下棋
		player_move(board, ROW, COL);
		//判断游戏状态
		ret = is_win(board, ROW, COL);
		if (ret != 'C')  //如果return C 则游戏继续 否则跳出来进行判断
			break;
		//电脑下棋
		computer_move(board, ROW, COL);
		//判断游戏状态
		ret = is_win(board, ROW, COL);
		if (ret != 'C')  //如果return C 则游戏继续 否则跳出来进行判断
			break;
	}
	if (ret == '*')
		printf("玩家赢\n");
	
	else if (ret == '#')
		printf("电脑赢\n");
	
	else if (ret == 'Q')
		printf("平局\n");
}
//4种状态判断
//玩家赢 - *
//电脑赢 - #
//平局了 - 'Q'
//游戏继续 - 'C'
int main()
{
	int input = 0;
	srand((unsigned)time(NULL));
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
			printf("选择错误，重新选择\n");
			break;
		}
	} while (input);
	return 0;
}