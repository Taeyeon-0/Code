#include<stdio.h>
/*
1个盘子  A->C    1次
2个盘子  A->B  A->C  B->C   3次
3个盘子  A->C A->B  C->B  A->C  B->A  B->C   A->C   7次
64个盘子    2^64-1次
*/

void move(char A, char C, int n)
{
	printf("把第%d个圆盘从%c->%c ", n, A, C);
}

/*
N代表盘子的个数
pos1起始位置
pos2中转位置
pos3目的位置
*/
void Hanoi(int n, char A, char B, char C)
{
	if (n == 1)
	{
		move(A, C, n);
	}
	else
	{
		Hanoi(n - 1, A, C, B); //将n-1个圆盘从A柱借助于C柱移动到B柱上
		move(A, C, n);    //将A柱子最后一个圆盘移动到C柱上
		Hanoi(n - 1, B, A, C);   //将n-1个盘子从B柱借助于A柱移动到C柱上
	}
}


int main()
{
	/*Hanoi(1, 'A', 'B', 'C');
	printf("\n");*/
	Hanoi(2, 'A', 'B', 'C');
	printf("\n");
	/*Hanoi(3, 'A', 'B', 'C');
	printf("\n");*/
	//Hanoi(64, 'A', 'B', 'C');
	return 0;
}