#include<stdio.h>
#define ROW 5
#define COL 5
//初始化棋盘函数声明
void Initboard(char board[ROW][COL], int row, int col);

//打印棋盘函数声明
void display_board(char board[ROW][COL], int row, int col);

//玩家下棋函数声明
void player_move(char board[ROW][COL], int row, int col);

//电脑下棋函数声明
void computer_move(char board[ROW][COL], int row, int col);

//判断游戏状态
char is_win(char board[ROW][COL], int row, int col);