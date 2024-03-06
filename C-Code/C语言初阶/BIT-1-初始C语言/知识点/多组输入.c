#include <stdio.h>
int main()
{
    int n = 0;
    while (scanf("%d", &n) != EOF)   //EOF等于-1  文件结束标志 用于多组输入
    {
        if (n >= 140)
            printf("Genius");
    }
    return 0;
}