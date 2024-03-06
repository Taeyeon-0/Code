#include <stdio.h>
int main()
{
    int ret = printf("Hello world!");   //返回值为字符串的个数
    printf("\n");
    printf("%d\n", ret);
    return 0;
}