#include<stdio.h>
int main()
{
	int a = 0, b = 0, c = 0;
	while (scanf_s("%d %d %d", &a, &b, &c) != EOF)
	{
		//判断是否为三角形
		if (((a + b) > c) && ((a + c) > b) && ((b + c) > a))
		{
			if (a == b && a == c)
			{
				printf("Equilateral triangle!\n");
			}
			else if ((a == b && a != c) || (a == c && a != b) || (b == c && b != a))
			{
				printf("Isosceles triangle!\n");
			}
			else
			{
				printf("Ordinary triangle!\n");
			}
		}
		else
		{
			printf("Not a triangle!\n");
		}
	}
	
	return 0;
}