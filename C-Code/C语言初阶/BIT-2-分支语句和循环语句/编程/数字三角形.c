#include <stdio.h>
// /KiKi学习了循环，BoBo老师给他出了一系列打印图案的练习，该任务是打印用数字组成的数字三角形图案。
int main()
{
    int n = 0;
    while (scanf("%d", &n) != EOF)
    {
        int i = 0;
        //打印行
        for (i = 0; i < n; i++)
        {
            //打印一行
            for (int j = 0; j < i + 1; j++)
            {
                printf("%d ", j + 1);
            }
            printf("\n");
        }
    }
    return 0;
}