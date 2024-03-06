#include"game.h"
//初始化棋盘
void init_board(char board[ROWS][COLS], int rows, int cols, char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}

//打印棋盘
void display_board(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	//列号
	for (j = 0; j <= col; j++)
	{
		printf("%d ", j);
	}
	printf("\n");

	for (i = 1; i <= row; i++)
	{
		//打印行号
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}


//布置雷
void set_mine(char mine[ROWS][COLS], int row, int col)
{
	//布置10个雷
	int count = EAZY_COUNT;
	while (count)
	{
		int x = rand() % row + 1; //1-9
		int y = rand() % col + 1; //1-9
		if (mine[x][y] == '0')
		{
			mine[x][y] = '1';
			count--;
		}
	}
}


//统计周围雷函数  下面的
int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	return (mine[x - 1][y - 1] +
		mine[x - 1][y] +
		mine[x - 1][y + 1] +
		mine[x][y - 1] +
		mine[x][y + 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] - 8 * '0');
}

//排雷
void findMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0;
	int y = 0;
	int win = 0;
	while (win<row*col- EAZY_COUNT)   //只要win<  没有排完雷
	{
		printf("请输入要排查雷的坐标：\n");
		scanf_s("%d %d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y < +col)  //合法范围
		{
			//坐标被排查过
			if (show[x][y] == '*')
			{
				if (mine[x][y] == '1')   //踩雷了
				{
					printf("很遗憾,你被炸死了\n");
					display_board(show, ROW, COL);
					break;
				}
				else
				{
					int count = get_mine_count(mine, x, y);  //统计雷
					show[x][y] = count + '0';  //字符3  数字+字符0  可以得到字符数字
					display_board(show, ROW, COL);  //排雷一次 ，打印一次show
					win++;
				}
			}
			else
			{
				printf("坐标已经被排查过\n");
			}
		}
		else
		{
			printf("坐标非法，请重新输入\n");
		}
	}
	if (win == row * col - EAZY_COUNT)
	{
		printf("恭喜你，排雷成功\n");
		display_board(show, ROW, COL);
	}
}

/*
9*9
*/