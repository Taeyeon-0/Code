#include <stdio.h>
#include <math.h> //abs的库函数
//给一个数N 求到fib数的最小值
int main()
{
    int n = 0;
    scanf("%d", &n);
    int f1 = 0;
    int f2 = 1;
    int f3 = f1 + f2;
    while (1)
    {
        if (n == f2)
        {
            printf("0\n");
            break;
        }
        else if (n < f2)
        {
            if (abs(f1 - n) < abs(f2 - n)) //求绝对值
            {
                printf("%d\n", abs(f1 - n));
            }
            else
            {
                printf("%d\n", abs(f2 - n));
            }
            break;
        }

        f1 = f2;
        f2 = f3;
        f3 = f1 + f2;
    }
    return 0;
}