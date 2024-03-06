#include <stdio.h>
int main()
{
    int i = 0;
    int sum = 0;
    int input = 0;
    for (i = 0; i < 5; i++)
    {
        scanf("%d", &input);
        sum += input;
    }
    printf("%.1f\n", sum / 5.0);
    return 0;
}