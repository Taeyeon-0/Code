#include <stdio.h>
int main()
{
    int a = 2;
    int b = 3;
    int c = 1;
    scanf("%d%d%d", &a, &b, &c);
    if (a < b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }
    if (a < c)
    {
        int tmp = a;
        a = c;
        c = tmp;
    }
    if (b < c)
    {
        int tmp = b;
        b = c;
        c = tmp;
    }
    printf("a=%d b=%d c=%d\n", a, b, c);
    return 0;
}