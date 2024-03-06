#include<stdio.h>
int main()
{
	int num = 0;
	scanf("%d", &num);
	while (num)
	{
		printf("%d", num % 10);
		num /= 10;
	}
	return 0;
}