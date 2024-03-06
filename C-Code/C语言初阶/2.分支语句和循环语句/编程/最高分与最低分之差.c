#include <stdio.h>
/*
#define N 10
int main()
{
    int arr[N];
    int i = 0;
    for (i = 0; i < N; i++)
    {
        scanf("%d ", &arr[i]);
    }

    int max = arr[0];
    for (i = 0; i < N; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }

    int min = arr[0];
    for (i = 0; i < N; i++)
    {
        if (arr[i] < min)
            min = arr[i];
    }

    printf("%d", max - min);
    return 0;
}*/


//优化
#include<stdio.h>
int main()
{
	int n = 0;
	scanf_s("%d", &n);
	int max = 0;  //假设最大值是0
	int min = 100;  //假设最小值是100
	int i = 0;
	int score = 0;
	for (i = 0; i < n; i++)
	{
		scanf_s("%d", &score);
		if (score > max)
			max = score;
		if (score < min)
			min = score;
	}
	printf("%d\n", max - min);
	return 0;
}
