#include <stdio.h>
int main()
{
    int sec = 0;
    scanf("%d", &sec);
    int h = sec / 60 / 60;
    int m = sec / 60 % 60;
    int s = sec % 60;
    printf("%d %d %d\n", h, m, s);
    return 0;
}