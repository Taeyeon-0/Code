#include"game.h"
//初始化棋盘函数
void Initboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

//棋盘函数实现(动态实现)
void display_board(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf(" %c ", board[i][j]);
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		//---|---|---
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				printf("---");
				if (j < col - 1)
				{
					printf("|");
				}
			}
		}
		printf("\n");
	}
}

//玩家下棋
void player_move(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("玩家下棋：>\n");
	while (1)
	{
		printf("请输入要下棋的坐标：>");
		scanf_s(" %d %d", &x, &y);
		//坐标的合法性
		//坐标是否被占用
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x-1][y-1] != ' ')  //玩家坐标从1开始，数组从0开始
			{
				printf("坐标被占用，请重新输入\n");
			}
			else
			{
				board[x - 1][y - 1] = '*';
				display_board(board, ROW, COL);   //每次下完棋盘，打印一次棋盘
				break;
			}
		}
		else
		{
			printf("坐标非法，重新输入\n");
		}
	}
}

//电脑下棋(随机下棋)
void computer_move(char board[ROW][COL], int row, int col)
{
	while(1)
	{ 
		int x = rand() % row;   //0-2
		int y = rand() % col;   //0-2
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			printf("电脑下棋：>\n");
			display_board(board, ROW, COL);   //每次下完棋盘，打印一次棋盘
			break;
		}
	}
}

//判断平局函数-如果棋盘满了返回1，否则返回0
int is_full(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}

//判断游戏状态
char is_win(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	int count = 0;
	//判断横向
	for (i = 0; i < row; i++)
	{
		count = 0;    //每循环一行 初始化count为0
		for (j = 0; j < col; j++)
		{
			if (board[i][0] == board[i][j] && board[i][0] != ' ')
				count++;
			if (count >= row)
				return board[i][0];
		}
	}
	//判断纵向
	for (j = 0; j < col; j++)
	{
		count = 0;    //每循环一列 初始化count为0
		for (i = 0; i < row; i++)
		{
			if (board[i][j] == board[0][j] && board[0][j] != ' ')
			{
				count++;
				if (count >= row)
					return board[0][j];
			}
		}
	}
	

	//判断对角线1
	count = 0;    //对角线的判断是从全局开始 所以要放在外面
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (i == j)
			{
				if (board[1][1] == board[i][j] && board[1][1] != ' ')
				{
					count++;
					if (count >= row)
						return board[1][1];
				}
			}
		}
	}
	
	//判断对角线2
	count = 0;   //对角线的判断是从全局开始 所以要放在外面
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if ((i + j + 1) == row)
			{
				if (board[1][1] == board[i][j] && board[1][1] != ' ')
				{
					count++;
					if (count >= row)
						return board[1][1];
				}
			}
		}
	}
	
	//判断平局
	if (is_full(board, ROW, COL) == 1)
	{
		return 'Q';
	}

	return 'C';
}