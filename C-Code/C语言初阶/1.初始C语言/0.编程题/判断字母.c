#include <stdio.h>
int main()
{
    int ch = 0;
    while ((ch = getchar()) != EOF)
    {
        //判断字母
        if((ch>='A' && ch<='Z') || (ch>='a' && ch<='z'))
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
        //清理掉\n
        int b = getchar();   //需要变量来接受getchar的返回值
    }
    return 0;
}