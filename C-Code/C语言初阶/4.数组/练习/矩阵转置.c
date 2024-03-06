#include<stdio.h>
#define N 2
#define M 3

int main()
{
    int a[N][M];
    int i = 0;
    int j = 0;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    //×ªÖÃ
    for (i = 0; i < M; i++)//3
    {
        for (j = 0; j < N; j++)//2
        {
            printf("%d ", a[j][i]);
        }
        printf("\n");
    }
    return 0;
}