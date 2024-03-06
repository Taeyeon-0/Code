#include<stdio.h>
//行列自行输入，计算其中大于零的元素之和
int main()
{
    int m = 0;
    int n = 0;
    scanf("%d %d", &m, &n);
    int i = 0;
    int j = 0;
    int tmp = 0;
    int sum = 0;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            scanf("%d", &tmp);
            if (tmp > 0)
                sum += tmp;
        }
    }
    printf("%d", sum);
    return 0;
}