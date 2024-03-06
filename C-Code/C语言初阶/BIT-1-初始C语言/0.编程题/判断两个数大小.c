#include <stdio.h>
int main()
{
    int num1 = 0;
    int num2 = 0;
    while (scanf("%d%d", &num1, &num2) != EOF)
    {
        if (num1 > num2)
            printf("%d>%d\n", num1, num2);
        else if (num1 < num2)
            printf("%d<%d\n", num1, num2);
        else
            printf("%d=%d\n", num1, num2);
    }
    return 0;
}