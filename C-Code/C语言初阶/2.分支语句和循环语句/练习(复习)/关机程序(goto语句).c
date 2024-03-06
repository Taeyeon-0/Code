#include<stdio.h>
//#include<Windows.h>
//goto方式
//int main()
//{
//    char input[10] = { 0 };
//    system("shutdown -s -t 60");
//again:
//    printf("电脑将在1分钟内关机，如果输入：我是猪，就取消关机!\n请输入:>");
//    scanf("%s", input);
//    if (0 == strcmp(input, "我是猪"))
//    {
//        system("shutdown -a");
//    }
//    else
//    {
//        goto again;
//    }
//
//    return 0;
//}


//循环方式
int main()
{
    char input[10] = { 0 };
    system("shutdown -s -t 60");
    printf("电脑将在1分钟内关机，如果输入：我是猪，就取消关机!\n请输入:>");
    while (1)
    {
        scanf("%s", input);
        if (0 == strcmp(input, "我是猪"))
        {
            system("shutdown -a");
            printf("已取消关机\n");
            break;
        }
    }
    return 0;
}