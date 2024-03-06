#include<stdio.h>

int main()
{
    int ch = 0;
    while ((ch = getchar()) != EOF)
    {
       
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z'))
        {
            printf("是字母\n");
        }
        else
        {
            printf("不是字母\n");
        }
        //清理掉\n
        getchar();
    }
    return 0;
}
