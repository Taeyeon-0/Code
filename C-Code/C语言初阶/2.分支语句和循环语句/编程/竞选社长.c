#include<stdio.h>
//假设你们社团要竞选社长，有两名候选人分别是A和B，社团每名同学必须并且只能投一票，最终得票多的人为社长.
int main()
{
	int s = 0;
	int countA = 0;
	int countB = 0;
	while ((s = getchar()) != '0')
	{
		if (s == 'A')
			countA++;
		if (s == 'B')
			countB++;
	}
	if (countA > countB)
		printf("A");
	else if (countB > countA)
		printf("B");
	else
		printf("E");
	return 0;
}